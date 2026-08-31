from pathlib import Path
import re
import json
import urllib.request
from collections import Counter


# ============================================================
# PATHS
# ============================================================

ROOT = Path(__file__).resolve().parent.parent

README_FILE = ROOT / "README.md"
CACHE_FILE = ROOT / "scripts" / "codeforces_problems.json"
METADATA_FILE = ROOT / "scripts" / "metadata.json"

START_MARKER = "<!-- AUTO-GENERATED:START -->"
END_MARKER = "<!-- AUTO-GENERATED:END -->"


# ============================================================
# LANGUAGE DETECTION
# ============================================================

LANGUAGES = {
    ".cpp": "C++",
    ".cc": "C++",
    ".cxx": "C++",
    ".py": "Python",
    ".java": "Java",
    ".js": "JavaScript",
    ".ts": "TypeScript",
    ".go": "Go",
    ".rs": "Rust",
}


def detect_language(filename):
    extension = Path(filename).suffix.lower()

    return LANGUAGES.get(
        extension,
        extension[1:].upper() if extension else "Unknown"
    )


# ============================================================
# CODEFORCES
# ============================================================

def extract_codeforces_id(filename):

    name = Path(filename).stem

    match = re.match(
        r"^(\d+[A-Z]\d*)",
        name
    )

    if match:
        return match.group(1)

    return None


def download_codeforces_problems():

    url = (
        "https://codeforces.com/api/"
        "problemset.problems"
    )

    print(
        "Downloading Codeforces "
        "problem data..."
    )

    with urllib.request.urlopen(
        url,
        timeout=30
    ) as response:

        data = json.loads(
            response.read().decode("utf-8")
        )

    if data["status"] != "OK":
        raise RuntimeError(
            "Codeforces API returned an error."
        )

    problems = data["result"]["problems"]

    CACHE_FILE.parent.mkdir(
        parents=True,
        exist_ok=True
    )

    with open(
        CACHE_FILE,
        "w",
        encoding="utf-8"
    ) as file:

        json.dump(
            problems,
            file,
            indent=2
        )

    return problems


def load_codeforces_problems():

    if CACHE_FILE.exists():

        with open(
            CACHE_FILE,
            "r",
            encoding="utf-8"
        ) as file:

            return json.load(file)

    return download_codeforces_problems()


def create_codeforces_lookup(problems):

    lookup = {}

    for problem in problems:

        if "contestId" not in problem:
            continue

        if "index" not in problem:
            continue

        problem_id = (
            f"{problem['contestId']}"
            f"{problem['index']}"
        )

        lookup[problem_id] = problem

    return lookup


def scan_codeforces_solutions():

    directories = [
        ROOT / "practice_question",
        ROOT / "contest_question" / "codeforces",
    ]

    solutions = []

    for directory in directories:

        if not directory.exists():
            continue

        for file in directory.iterdir():

            if not file.is_file():
                continue

            if file.suffix.lower() not in LANGUAGES:
                continue

            problem_id = extract_codeforces_id(
                file.name
            )

            if not problem_id:
                continue

            solutions.append({
                "id": problem_id,
                "filename": file.name,
                "path": file.relative_to(ROOT).as_posix(),
                "language": detect_language(
                    file.name
                ),
            })

    return solutions


# ============================================================
# CODECHEF
# ============================================================

def extract_codechef_code(filename):

    name = Path(filename).stem

    match = re.match(
        r"^([A-Z0-9]+)\s*-",
        name
    )

    if match:
        return match.group(1)

    return None


def extract_codechef_name(filename):
    """
    Fallback name extraction from filename.

    Example:
        DISTINCTCOL-DistinctColors.cpp
        -> Distinct Colors
    """

    name = Path(filename).stem

    match = re.match(
        r"^[A-Z0-9]+\s*-\s*(.+)$",
        name
    )

    if not match:
        return name

    title = match.group(1).strip()

    # Replace separators.
    title = title.replace("_", " ")
    title = title.replace("-", " ")

    # Split CamelCase.
    #
    # DistinctColors -> Distinct Colors
    # MinimumFlips -> Minimum Flips
    title = re.sub(
        r"(?<=[a-z])(?=[A-Z])",
        " ",
        title
    )

    # ChefandDolls -> Chef and Dolls
    title = re.sub(
        r"(?i)(?<=\w)and(?=[A-Z])",
        " and ",
        title
    )

    # Normalize spaces.
    title = re.sub(
        r"\s+",
        " ",
        title
    ).strip()

    return title


def fetch_codechef_problem(code):

    """
    Fetch CodeChef problem metadata directly from
    CodeChef's public problem endpoint.

    Returns:
        {
            "name": "...",
            "rating": ...,
            "tags": [...]
        }

    Returns None if the request fails.
    """

    url = (
        "https://www.codechef.com/api/"
        f"contests/PRACTICE/problems/{code}"
    )

    try:

        request = urllib.request.Request(
            url,
            headers={
                "User-Agent": (
                    "Mozilla/5.0 "
                    "(compatible; "
                    "README-Generator/1.0)"
                ),
                "Accept": "application/json",
            }
        )

        with urllib.request.urlopen(
            request,
            timeout=20
        ) as response:

            data = json.loads(
                response.read().decode("utf-8")
            )

        if data.get("status") != "success":
            return None

        # ----------------------------------------------------
        # Problem name
        # ----------------------------------------------------

        name = data.get(
            "problem_name"
        )

        # ----------------------------------------------------
        # Difficulty rating
        # ----------------------------------------------------

        rating = data.get(
            "difficulty_rating"
        )

        if rating in (
            None,
            "",
            "-1",
            -1
        ):
            rating = None

        # Convert numeric string to integer.
        if isinstance(
            rating,
            str
        ):

            try:
                rating = int(rating)
            except ValueError:
                pass

        # ----------------------------------------------------
        # Tags
        # ----------------------------------------------------
        #
        # CodeChef exposes:
        #
        # user_tags
        # computed_tags
        #
        # Combine both while removing duplicates.
        #

        user_tags = data.get(
            "user_tags",
            []
        )

        computed_tags = data.get(
            "computed_tags",
            []
        )

        if not isinstance(
            user_tags,
            list
        ):
            user_tags = []

        if not isinstance(
            computed_tags,
            list
        ):
            computed_tags = []

        tags = []

        for tag in (
            user_tags +
            computed_tags
        ):

            if not tag:
                continue

            if tag not in tags:
                tags.append(tag)

        return {
            "name": name,
            "rating": rating,
            "tags": tags,
        }

    except Exception as error:

        print(
            f"WARNING: Could not fetch "
            f"CodeChef metadata for {code}: "
            f"{error}"
        )

        return None


def scan_codechef_solutions():

    directory = (
        ROOT /
        "contest_question" /
        "codechef"
    )

    solutions = []

    if not directory.exists():
        return solutions

    for file in directory.iterdir():

        if not file.is_file():
            continue

        if file.suffix.lower() not in LANGUAGES:
            continue

        code = extract_codechef_code(
            file.name
        )

        if not code:
            continue

        solutions.append({
            "code": code,
            "filename": file.name,
            "path": file.relative_to(ROOT).as_posix(),
            "language": detect_language(
                file.name
            ),
        })

    return solutions


# ============================================================
# METADATA
# ============================================================

def load_metadata():

    if not METADATA_FILE.exists():

        print(
            "WARNING: metadata.json "
            "not found."
        )

        return {}

    with open(
        METADATA_FILE,
        "r",
        encoding="utf-8"
    ) as file:

        return json.load(file)


# ============================================================
# GITHUB LINK
# ============================================================

def github_file_link(path):

    encoded_path = "/".join(
        part.replace(" ", "%20")
        for part in path.split("/")
    )

    return (
        "https://github.com/"
        "N1kh1lKumar/"
        "Competitive-Programming-journey/"
        "blob/main/"
        f"{encoded_path}"
    )


# ============================================================
# CODEFORCES SECTION
# ============================================================

def generate_codeforces_section(
    solutions,
    lookup
):

    rows = []

    rating_count = Counter()

    for solution in solutions:

        problem = lookup.get(
            solution["id"]
        )

        if not problem:
            continue

        rating = problem.get(
            "rating"
        )

        if rating:
            rating_count[rating] += 1

        tags = ", ".join(
            problem.get(
                "tags",
                []
            )
        )

        solution_link = github_file_link(
            solution["path"]
        )

        rows.append({
            "id": solution["id"],
            "name": problem["name"],
            "rating": rating or "-",
            "tags": tags or "-",
            "language": solution["language"],
            "link": solution_link,
        })

    rows.sort(
        key=lambda x: (
            int(
                re.match(
                    r"\d+",
                    x["id"]
                ).group()
            ),
            x["id"]
        )
    )

    rating_table = []

    for rating in sorted(
        rating_count
    ):

        rating_table.append(
            f"| {rating} | "
            f"{rating_count[rating]} |"
        )

    problem_table = []

    for row in rows:

        problem_table.append(
            f"| {row['id']} | "
            f"{row['name']} | "
            f"{row['rating']} | "
            f"{row['tags']} | "
            f"{row['language']} | "
            f"[View]({row['link']}) |"
        )

    return f"""## 🟦 Codeforces

**Total Problems Solved:** {len(rows)}

### ⭐ Rating Distribution

| Rating | Problems |
|---:|---:|
{chr(10).join(rating_table)}

### 🧩 Problems

| ID | Problem | Rating | Tags | Language | Solution |
|---|---|---:|---|---|---|
{chr(10).join(problem_table)}
"""


# ============================================================
# CODECHEF SECTION
# ============================================================

def generate_codechef_section(
    solutions,
    metadata
):

    codechef_metadata = metadata.get(
        "codechef",
        {}
    )

    rows = []

    for solution in solutions:

        code = solution["code"]

        # ----------------------------------------------------
        # Existing metadata.json entry
        # ----------------------------------------------------

        local_metadata = (
            codechef_metadata.get(
                code,
                {}
            )
        )

        # ----------------------------------------------------
        # Fetch live CodeChef metadata
        # ----------------------------------------------------

        print(
            f"Fetching CodeChef metadata: {code}"
        )

        online_metadata = (
            fetch_codechef_problem(
                code
            )
        )

        # ----------------------------------------------------
        # Filename fallback
        # ----------------------------------------------------

        filename_name = (
            extract_codechef_name(
                solution["filename"]
            )
        )

        # ----------------------------------------------------
        # Determine name
        #
        # Priority:
        #
        # 1. Live CodeChef API
        # 2. metadata.json
        # 3. Filename
        # ----------------------------------------------------

        if online_metadata:
            name = (
                online_metadata.get(
                    "name"
                )
                or local_metadata.get(
                    "name"
                )
                or filename_name
            )
        else:
            name = (
                local_metadata.get(
                    "name"
                )
                or filename_name
            )

        # ----------------------------------------------------
        # Determine rating
        #
        # Priority:
        #
        # 1. Live CodeChef API
        # 2. metadata.json
        # 3. "-"
        # ----------------------------------------------------

        if online_metadata:
            rating = (
                online_metadata.get(
                    "rating"
                )
            )

            if rating is None:
                rating = local_metadata.get(
                    "rating"
                )

        else:
            rating = local_metadata.get(
                "rating"
            )

        # ----------------------------------------------------
        # Determine tags
        #
        # Priority:
        #
        # 1. Live CodeChef API
        # 2. metadata.json
        # 3. "-"
        # ----------------------------------------------------

        if online_metadata:

            tags = online_metadata.get(
                "tags",
                []
            )

            if not tags:
                tags = local_metadata.get(
                    "tags",
                    []
                )

        else:

            tags = local_metadata.get(
                "tags",
                []
            )

        if isinstance(
            tags,
            str
        ):
            tags = [tags]

        solution_link = github_file_link(
            solution["path"]
        )

        rows.append(
            f"| {code} | "
            f"{name} | "
            f"{rating or '-'} | "
            f"{', '.join(tags) or '-'} | "
            f"{solution['language']} | "
            f"[View]({solution_link}) |"
        )

    rows.sort()

    return f"""## 🟧 CodeChef

**Total Problems Solved:** {len(rows)}

| Code | Problem | Rating | Tags | Language | Solution |
|---|---|---:|---|---|---|
{chr(10).join(rows)}
"""


# ============================================================
# PROGRESS
# ============================================================

def generate_progress_section(
    codeforces_solutions,
    codechef_solutions
):

    codeforces_count = len(
        codeforces_solutions
    )

    codechef_count = len(
        codechef_solutions
    )

    total = (
        codeforces_count +
        codechef_count
    )

    return f"""## 📊 Progress

| Platform | Problems Solved |
|---|---:|
| Codeforces | {codeforces_count} |
| CodeChef | {codechef_count} |
| **Total** | **{total}** |
"""


# ============================================================
# LANGUAGE STATISTICS
# ============================================================

def generate_language_section(
    codeforces_solutions,
    codechef_solutions
):

    all_solutions = (
        codeforces_solutions +
        codechef_solutions
    )

    language_count = Counter(
        solution["language"]
        for solution in all_solutions
    )

    rows = []

    for language in sorted(
        language_count
    ):

        rows.append(
            f"| {language} | "
            f"{language_count[language]} |"
        )

    return f"""## 💻 Languages

| Language | Problems |
|---|---:|
{chr(10).join(rows)}
"""


# ============================================================
# README UPDATE
# ============================================================

def update_readme(
    generated_content
):

    generated_block = (
        f"{START_MARKER}\n\n"
        f"{generated_content}\n"
        f"{END_MARKER}"
    )

    if not README_FILE.exists():

        README_FILE.write_text(
            generated_block,
            encoding="utf-8"
        )

        return

    readme = README_FILE.read_text(
        encoding="utf-8"
    )

    pattern = re.compile(
        re.escape(START_MARKER)
        + r".*?"
        + re.escape(END_MARKER),
        re.DOTALL
    )

    if pattern.search(readme):

        readme = pattern.sub(
            generated_block,
            readme
        )

    else:

        readme = (
            readme.rstrip()
            + "\n\n"
            + generated_block
            + "\n"
        )

    README_FILE.write_text(
        readme,
        encoding="utf-8"
    )


# ============================================================
# MAIN
# ============================================================

def main():

    print()
    print(
        "Starting README generator..."
    )
    print()

    # --------------------------------------------------------
    # Codeforces
    # --------------------------------------------------------

    codeforces_problems = (
        load_codeforces_problems()
    )

    codeforces_lookup = (
        create_codeforces_lookup(
            codeforces_problems
        )
    )

    codeforces_solutions = (
        scan_codeforces_solutions()
    )

    # --------------------------------------------------------
    # CodeChef
    # --------------------------------------------------------

    metadata = load_metadata()

    codechef_solutions = (
        scan_codechef_solutions()
    )

    # --------------------------------------------------------
    # Generate sections
    # --------------------------------------------------------

    progress_section = (
        generate_progress_section(
            codeforces_solutions,
            codechef_solutions
        )
    )

    language_section = (
        generate_language_section(
            codeforces_solutions,
            codechef_solutions
        )
    )

    codeforces_section = (
        generate_codeforces_section(
            codeforces_solutions,
            codeforces_lookup
        )
    )

    codechef_section = (
        generate_codechef_section(
            codechef_solutions,
            metadata
        )
    )

    generated_content = (
        progress_section
        + "\n"
        + language_section
        + "\n"
        + codeforces_section
        + "\n"
        + codechef_section
    )

    # --------------------------------------------------------
    # Update README
    # --------------------------------------------------------

    update_readme(
        generated_content
    )

    print(
        f"Codeforces solutions : "
        f"{len(codeforces_solutions)}"
    )

    print(
        f"CodeChef solutions   : "
        f"{len(codechef_solutions)}"
    )

    print()

    print(
        "README successfully updated."
    )


if __name__ == "__main__":
    main()
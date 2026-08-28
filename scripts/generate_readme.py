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

        problem = codechef_metadata.get(
            code,
            {}
        )

        name = problem.get(
            "name",
            code
        )

        rating = problem.get(
            "rating"
        )

        tags = problem.get(
            "tags",
            []
        )

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

    # Codeforces

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

    # CodeChef

    metadata = load_metadata()

    codechef_solutions = (
        scan_codechef_solutions()
    )

    # Generate sections

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
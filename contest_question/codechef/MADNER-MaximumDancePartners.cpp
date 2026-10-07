#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximumPairs(const string &students) {
        // write your code here 
        int n = students.size();
        int count =0;
        for(int i =0; i<n-1; i++){
            if(students[i] != students[i+1]){
                count++;
                i++;
            }
        }
        return count;
    }
};

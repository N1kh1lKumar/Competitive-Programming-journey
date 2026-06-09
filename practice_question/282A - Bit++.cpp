#include<bits/stdc++.h>
using namespace std;
 
bool checkSt(string Statement){
    if(Statement == "X++" || Statement == "++X"){
        return true;
    }else{
        return false;
    }
}
 
int main(){
    int n;
    cin >> n;
    
    int x =0;
    
    for(int i=0; i<n; i++){
        string Statement;
        cin >> Statement;
        
        if(checkSt(Statement)){
            x++;
        }else{
            x--;
        }
    }
 
    cout << x << endl;
    
    return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int N;
vector<string> str;
string st; 

bool cmp(string &a, string &b){
    int sizeA = a.size();
    int sizeB = b.size();
    int sumA=0; int sumB=0;
    if (sizeA!= sizeB) return a.size() < b.size();
    for(int i=0; i< a.size(); i++){
        if(isdigit(a[i])) sumA += (a[i]-'0'); 
      }
    for(int i=0; i< b.size(); i++){
        if(isdigit(b[i])) sumB += (b[i]-'0'); 
    } 
    if(sumA != sumB)  return sumA < sumB;    
    return a < b;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N; 
  for (int i=0; i< N ;i++){
    //string str[N]; 배열 선언에 N이 들어가면 안됨 !! -> 동적 할당을 위해 vector<string> 사용 할 줄 알기 
    // 동적 할달 사용 
    cin >> st;  
    str.push_back(st); 

  } 
  sort(str.begin(),str.end(),cmp); 
  for (auto i: str){
    cout << i << '\n' ; 
  }
 // 문자열 배열 저장 어떻게 할 지 -> String 클래스 사용하기 
}
#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int tmp[1000001];
void merge(int st, int en){
  int mid = (st+en)/2;
  int lidx = st; 
  int ridx = mid;
  for(int i = st; i < en; i++){
    if(ridx == en) tmp[i] = arr[lidx++];
    else if(lidx == mid) tmp[i] = arr[ridx++];
    else if(arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
    else tmp[i] = arr[ridx++];
  }
  for(int i = st; i < en; i++) arr[i] = tmp[i]; // tmp에 임시저장해둔 값을 a로 다시 옮김
}

void merge_sort(int st, int en){
  if(en-st == 1) return; // 길이 1인 경우
  int mid = (st+en)/2;
  merge_sort(st,mid); // st to mid-1 정렬
  merge_sort(mid,en); // mid to en-1 정렬
  merge(st,en);
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;  
  for(int i = 0; i < n; i++) cin >> arr[i];
  merge_sort(0, n);
  for(int i = 0; i < n; i++) cout << arr[i] << '\n';
}
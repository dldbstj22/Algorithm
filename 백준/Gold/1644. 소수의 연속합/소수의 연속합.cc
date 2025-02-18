#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

const int MXN = 4000002;
//seive 함수는 소수 판정 함수 
vector<bool> seive(MXN, true);
vector<int> primes;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //i가 소수라면 i*i부터 시작해서 i의 배수들을 모두 false로 변경하는 과정 
  for(int i=2; i*i<MXN; i++){

    // i가 합성수이면 continue
    if (!seive[i]) continue;

    //i가 소수라면 i*i보다 큰 배수들 모두 false만들어주기 
    for (int j = i * i; j < MXN; j += i) 
      seive[j] = false;
  }

  //배열에 대해서 i가 소수일떄 모두 primes 벡터에 i 값 넣기 
  for (int i = 2; i < MXN; i++) if (seive[i]) primes.push_back(i);
  //마지막에 0을 추가해서 배열의 끝을 나타냈음 , 이 부분 생각 못했었음 
  primes.push_back(0);
  
  // 투 포인터 정의 
  //target은 입력받은 정수 값 
  // s: st, e; en 역할 
  //tmpSum : 임시적으로 배열의 값들을 더한 값
  int target, s = 0, e = 1, ans = 0, tmpSum = primes[0];
  cin >> target;
  while (1) {
    if (tmpSum == target) ans++;
    //더해진 값이 더 작으면 e를 증가시켜주고 tmp에 더해줌 
    if (tmpSum <= target) tmpSum += primes[e++];
    //더해진 값이 더 커져버리면 그 배열을 멈추고 s값을 넘겨줘서 다시 시작해야함 

    if (target < tmpSum) tmpSum -= primes[s++];
    // e의 값이 끝까지 갔다면 break 
    if (e == int(primes.size())) break;
  }
  cout << ans;
}
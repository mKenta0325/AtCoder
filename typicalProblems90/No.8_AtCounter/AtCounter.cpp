#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;

int str_length ;
string str ;

const string ATCODER = "atcoder" ;

/* 動的計画法

  dp[i][k]: str の i 番目までで，atcoder の k 番目までの部分文字列を何通り作れるのか

  ・dp[0][k] := 0
  ・dp[i][k] は i 番目を用いない場合と i 番目を用いる場合の合計
  　dp[i][k] := dp[i - 1][k] + dp[i - 1][k - 1]

*/

vector< vector<int> > table ;

void memoized_recursion_core(int i, int k) {
  if (i == 0) {
    table[0][k] = 0 ;
    return ;
  }
  int unused_num = table.at(i - 1).at(k) ;
  if (unused_num == -1) {
    memoized_recursion_core(i - 1, k) ;
    unused_num = table.at(i - 1).at(k) ;
  }

  // ここから！
}
void memoized_recursion() {
  table = vector< vector<int> >(vector<int>(str_length + 1), ATCODER.size() + 1) ;
  for (int i = 0 ; i <= str_length ; i++) {
    for (int k = 0 ; k <= ATCODER.size() ; k++)
      table.at(i).at(k) = -1 ;
  }
  memoized_recursion_core(str_length, ATCODER.size()) ;
}

int main() {
  cin >> str_length ;
  cin >> str ;



  return 0 ;
}

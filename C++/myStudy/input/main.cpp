#include <iostream>
#include <vector>
using namespace std ;

int main() {
  int a, b, c ;
  cin >> a >> b >> c ;
  auto matrix = vector< vector<int> >(a, vector<int>(b)) ;
  string line ;
  while ( !cin.eof() ) {
    getline(cin, line) ;
    cout << line << endl ;
  }
  cout << "finised" << endl ;
}

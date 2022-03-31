#include <iostream>
#include <vector>
#include <utility>
#include <stack>
using namespace std ;

const int UNDISCOVERED = 0 ;
const int DISCOVERED = 1 ;
const int PROCESSED = 2 ;

vector<string> split(string str) {
  auto result = vector<string>() ;
  result.push_back("") ;
  int pos = 0 ;
  for (auto c : str) {
    if (c == ' ') {
      result.push_back("") ;
      pos++ ;
      continue ;
    }
    result.at(pos) += c ;
  }
  return result ;
}

bool is_reachable(vector< vector<bool> > matrix, int ra, int ca, int rb, int cb) {
  auto cell_status = vector< vector<int> >(matrix.size(), vector<int>(matrix.at(0).size())) ;
  auto cell_stack = stack< pair<int, int> >() ;
  cell_status.at(ra).at(ca) = DISCOVERED ;
  cell_stack.push(make_pair(ra, ca)) ;
  while (cell_stack.size() != 0) {
    auto cell = cell_stack.top() ;
    cell_stack.pop() ;
    int i = cell.first ;
    int j = cell.second ;
    if (i == rb && j == cb) return true ;
    // cell の上マス (i - 1, j)
    if (i > 0 && matrix.at(i - 1).at(j)) {
      if (cell_status.at(i - 1).at(j) == UNDISCOVERED) {
        cell_status.at(i - 1).at(j) = DISCOVERED ;
        cell_stack.push(make_pair(i - 1, j)) ;
      }
    }
    // cell の下マス (i + 1, j)
    if (i < matrix.size() - 1 && matrix.at(i + 1).at(j)) {
      if (cell_status.at(i + 1).at(j) == UNDISCOVERED) {
        cell_status.at(i + 1).at(j) = DISCOVERED ;
        cell_stack.push(make_pair(i + 1, j)) ;
      }
    }
    // cell の左マス (i, j - 1)
    if (j > 0 && matrix.at(i).at(j - 1)) {
      if (cell_status.at(i).at(j - 1) == UNDISCOVERED) {
        cell_status.at(i).at(j - 1) = DISCOVERED ;
        cell_stack.push(make_pair(i, j - 1)) ;
      }
    }
    // cell の右マス (i, j + 1)
    if (j < matrix.at(0).size() - 1 && matrix.at(i).at(j + 1)) {
      if (cell_status.at(i).at(j + 1) == UNDISCOVERED) {        
        cell_status.at(i).at(j + 1) = DISCOVERED ;
        cell_stack.push(make_pair(i, j + 1)) ;
      }
    }
    cell_status.at(i).at(j) = PROCESSED ;
  }
  return false ;
}

int main() {
  int H, W, Q ;
  cin >> H >> W >> Q ;
  auto matrix = vector< vector<bool> >(H, vector<bool>(W)) ;
  string line ;
  while ( !cin.eof() ) {
    getline(cin, line) ;
    if (line == "") continue ;
    auto data = split(line) ;
    int t = atoi( data.at(0).c_str() ) ;
    if (t == 1) {
      int r, c ;
      r = atoi( data.at(1).c_str() ) - 1 ;
      c = atoi( data.at(2).c_str() ) - 1 ;
      matrix.at(r).at(c) = true ;
      continue ;
    }
    int ra, ca, rb, cb ;
    ra = atoi(data.at(1).c_str()) - 1 ;
    ca = atoi(data.at(2).c_str()) - 1 ;
    rb = atoi(data.at(3).c_str()) - 1 ;
    cb = atoi(data.at(4).c_str()) - 1 ;
    if (! (matrix.at(ra).at(ca) && matrix.at(rb).at(cb)) ) {
      cout << "No" << endl ;
      continue ;
    }
    if (! is_reachable(matrix, ra, ca, rb, cb)) {
      cout << "No" << endl ;
      continue ;
    }
    cout << "Yes" << endl ;
  }
}

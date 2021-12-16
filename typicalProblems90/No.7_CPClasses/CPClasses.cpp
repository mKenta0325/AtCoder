#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int class_num ;
vector<int> ratings_class ;
int student_num ;
vector<int> ratings_student ;

int lower_bound_index(int v, int l) {
  // v < ratings_class[i] となる最小の i を求める．
  if (v < ratings_class.at(l))
    return l ;
  int left = l ;
  int right = class_num - 1 ;
  while (right != left + 1) {
    int middle = (left + right) / 2 ;
    if (v < ratings_class.at(middle)) {
      right = middle ;
      continue ;
    }
    left = middle ;
  }
  return right ;
}

int main() {
  cin >> class_num ;
  ratings_class = vector<int>(class_num) ;
  set<int> ratings_class_set ;
  for (int i = 0 ; i < class_num ; i++) {
    int r ;
    cin >> r ;
    ratings_class_set.insert(r) ;
  }
  class_num = ratings_class_set.size() ;
  vector<int> ratings_class(class_num) ;
  int pos = 0 ;
  for (int r : ratings_class_set) {
    ratings_class.at(pos) = r ;
    pos++ ;
  }
  cin >> student_num ;
  ratings_student = vector<int>(student_num) ;
  for (int j = 0 ; j < student_num ; j++)
    cin >> ratings_student.at(j) ;

  sort(ratings_class.begin(), ratings_class.end()) ;
  sort(ratings_student.begin(), ratings_student.end()) ;

  int right = 0 ;
  for (int rs : ratings_student) {
    right = lower_bound_index(rs, max(0, right - 1)) ;
    cout << "right : " << right << endl ;
    if (right == 0) {
      cout << ratings_class.at(0) - rs << endl ;
      continue ;
    }
    cout << min(rs - ratings_class.at(right - 1), ratings_class.at(right) - rs) << endl ;
  }
}

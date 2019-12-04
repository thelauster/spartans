#include <random>
#include<algorithm>
#include<stdexcept>

#include "table.h"

Table::Table(long width, long height, long val) {
  width_ = width;
  height_ = height;
  vector<long> row(width, val);
  t_.assign(height, row);
}

void Table::fill_random(long lo, long hi, unsigned int seed) {
  std::mt19937 generator(seed);
  std::uniform_int_distribution<int> distribution(lo, hi);
  
  std::transform(t_.begin(), t_.end(), t_.begin(), 
      [&distribution, &generator](vector<long> v){
        std::transform(v.begin(), v.end(), v.begin(),
        [&distribution, &generator](long l){
          l = distribution(generator);
          return l;
        });
        return v;
      });
}

bool Table::set_value(unsigned int row_num, unsigned int col_num, long val) {
  if (static_cast<long>(row_num) < height_ && static_cast<long>(col_num) < width_) {
    vector<long> & row = t_[row_num];
    row[col_num] = val;
    return true;
  } else {
    return false;
  }
}

long Table::get_value (unsigned int row_num, unsigned int col_num) const {
  if (static_cast<long>(row_num) < height_ && static_cast<long>(col_num) < width_) {
    return t_[row_num][col_num];
  } else {
    throw std::out_of_range("");
  }
}

ostream& operator<<(ostream& out, Table t) {
  for (auto row:t.t_) {
    for (auto cell:row) {
      out << cell << ',';
    }
    out << '\n';
  }
  return out;
}


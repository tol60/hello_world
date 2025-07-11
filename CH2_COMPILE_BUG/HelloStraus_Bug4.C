// Just a simple hello world test
// g++ -std=c++11 -g -o HelloStraus_Bug4.exe HelloStraus_Bug4.C  2>&1 | tee tmp.txt

#include "std_lib_facilities.h"
integer main ()
{
  cout << "Hello, Straus!\n";
  //keep_window_open(); // wait for a character to be entered
  return 0;
}

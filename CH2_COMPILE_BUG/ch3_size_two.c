// Just a simple hello world test
// g++ -std=c++11 -g -o HelloStraus.exe HelloStraus.C  2>&1 | tee tmp.txt

#include "std_lib_facilities.h"
int main ()
{
  cout << "Hello, Straus!\n";
  //keep_window_open(); // wait for a character to be entered
  int n = 5;
  cout << "int n = " << n << ", sizeof() = " << sizeof (n) << endl;
  double x = 5.3;
  cout << "double x  = " << x << ", sizeof() = " << sizeof (x) << endl;

  string st_en_short = "a";
  cout << "string st_en_short  = " << st_en_short << ", sizeof() = " << sizeof (st_en_short) << ", st_en_short.size() = " << st_en_short.size() << endl;
  string st_en = "abc";
  cout << "string st_en  = " << st_en << ", sizeof() = " << sizeof (st_en) << ", st_en.size() = " << st_en.size() << endl;
  string st_ru = "жюц";
  cout << "string st_ru  = " << st_ru << ", sizeof() = " << sizeof (st_ru) << ", st_ru.size() = " << st_ru.size() << endl;
  string st_en_long= "1234567890123456789012345678901234567890";
  cout << "string st_en_long  = " << st_en_long << ", sizeof() = " << sizeof (st_en_long) << ", st_en_long.size() = " << st_en_long.size() << endl;

  char ch_en = 'a';
  cout << "char ch_en  = " << ch_en << ", sizeof() = " << sizeof (ch_en) << endl;
  char ch_ru = 'Ю';
  cout << "char ch_ru  = " << ch_ru << ", sizeof() = " << sizeof (ch_ru) << endl;

  return 0;
}

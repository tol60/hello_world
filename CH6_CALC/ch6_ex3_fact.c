//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//
 
/*
    This file is known as calculator02buggy.cpp
 
    I have inserted 5 errors that should cause this not to compile
    I have inserted 3 logic errors that should cause the program to give wrong results
 
    First try to find an remove the bugs without looking in the book.
    If that gets tedious, compare the code to that in the book (or posted source code)
 
    Happy hunting!
 
*/
 
#include "std_lib_facilities.h"
 
//------------------------------------------------------------------------------
 
class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};
 
//------------------------------------------------------------------------------
 
class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};
 
//------------------------------------------------------------------------------
 
// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}
 
//------------------------------------------------------------------------------
 
// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}
 
//------------------------------------------------------------------------------
 
Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }
 
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)
 
    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(': case ')':case '{': case '}': case '+': case '-': case '*': case '/':case '!':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7':case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token('8', val);   // let '8' represent "a number"
    }
    default:
        error("Bad token");
    }
}
 
//------------------------------------------------------------------------------
 
Token_stream ts;        // provides get() and putback() 
 
//------------------------------------------------------------------------------
 
double expression();    // declaration so that primary() can call expression()
 
//------------------------------------------------------------------------------
/* если n = 5, то возращаем 5*4*3*2*1
если n = 0, то возвращаем 1
еслит n = -5,  то возвращаем -(5!)*/
// добавили проверку на переполнение
// n! =  n*(n-1)*(n-2)*...*3*2*1 = n*{(n-1)*(n-2)*...*3*2*1}= n * (n-1)!
/*int fact(int n)
{
    //if (n<0) error("отрицательный аргумент для факториала");
    if (n<0) return - fact(-n);
    if (n==0) return 1;
    int val = 1;
    while (n>1){
        val *= n;
        if (val <= 0) error("Переполнение в функции fact");
        --n;
    }
    return val;
}*/
//n!= n*(n-1)!
int fact(int n)
{
    if (n<0) return - fact(-n);
    if (n==0||n==1) return 1;
    int val = n * fact(n-1);//n!= n*(n-1)!
    if (val <= 0) error("Переполнение в функции fact");
    return val;
}
// deal with numbers and parentheses
double primary()
{
    double d = 0;
    Token t = ts.get();// (
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    //{
        // вВОД: (35)
        d = expression();// 35
        t = ts.get();// )
        if (t.kind != ')') 
            error("')' expected");
        //return d;
        break;
    //i}
    case '{':    // handle '(' expression ')'
    {
        d = expression();
        t = ts.get();
        if (t.kind != '}') 
            error("'}' expected");
        //return d;
        break;
    }
    case '-':
    {
        return - primary();
    }
    case '8': 
    {          // we use '8' to represent a number
        d = t.value;
        /*while(1)
        {
            t = ts.get();
            if (t.kind == '!'){
                d = fact(d);
            } else {
                ts.putback(t);
                break;
            }
        }*/
        //return d;  // return the number's value
        break;
    }
    default:
        error("primary expected");
    }
    while(1)
    {
        t = ts.get();
        if (t.kind == '!'){
            d = fact(d);
        } else {
            ts.putback(t);
            break;
        }
    }
    return d;
}
 
//------------------------------------------------------------------------------
 
// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream
 
    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}
 
//------------------------------------------------------------------------------
 
// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream
 
    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}
 
//------------------------------------------------------------------------------
//ТИП имя_функции(параменты) тело_функции
int main()
try
{
    cout<<"Добро пожаловать в программу калькулятор!\nВводите выражения с числами с плавающей тоской.\n";
    cout<<"Можно использовать операторы: - ; + ; * ; / .\nЧто бы вывести результат нажмите после выражения знак = .\n";
    cout<<"Что бы выйти из программы нажмите клавишу x .\n";
    double val = 0;
    while (cin) {
        Token t = ts.get();
        
 
        if (t.kind == 'x') break; // 'x' for quit
        if (t.kind == '=')        // ';' for "print now"
            cout << "=" << val << '\n';
        else{
            ts.putback(t);
            val = expression();
        }
    }
    keep_window_open();
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}
 
//------------------------------------------------------------------------------

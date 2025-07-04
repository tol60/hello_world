# hello_world

Step 1 Install WSL (Windows Subsystem for Linux)
In Windows PowerShell

wsl --install

wsl --status

Extra details
https://learn.microsoft.com/en-us/windows/wsl/install

Step 2 Install Ubuntu.
https://ubuntu.com/desktop/wsl
(username, password. Do not forget it)
(тут устанавливается пароль, который надо обязательно запомнить).

Step 3 Install Visual Studio Code.
https://code.visualstudio.com/download
to start, type:

code .

Sample example from youtube (includes step 2):
https://www.youtube.com/watch?v=av0UQy6g2FA&t=7s

Step 4 Install the compiler:

sudo apt-get update

sudo apt-get install g++

Step 5 Execute:

cd 

pwd

ls

mkdir PROGRAMMING

ls

cd PROGRAMMING

pwd

ls 

git clone https://github.com/tol60/hello_world.git

ls

cd hello_world

pwd

ls

ls *.C

cat HelloStraus.C

grep -i cout HelloStraus.C

Compile (should generate a.out):

g++ HelloStraus.C

Run a program:

./a.out

Compile (should generate HelloStraus.exe)

g++ -std=c++11 -g -o HelloStraus.exe HelloStraus.C  2>&1 | tee tmp.txt

Run a program:

./HelloStraus.exe

Extra commands:

pwd       // show current directory

ls        // list directory

ls -altr  // list files (including hiddent that start with '.'). a = all, l = long info, -t = sort by time, -r = reverse order

cat FILENAME // display file content

cp FILEFROM FILETO  // copy file FROM to a new file FROM to a new file TO

grep PATTERN FILE // search for a regular expression PATTERN in a FILE 

df -h     // show mount points (in case you need to access windows folder)

man COMMAND // will print help information on a given command



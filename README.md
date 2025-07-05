# Setting up WSL (Windows sybsystem for Linux)

## Installation
Meeting link https://us05web.zoom.us/j/5834734948?pwd=cfT1zha5k7Rukl719vCbpDbvqd6bKG.1&omn=85238526619
### Step 1 Install WSL (Windows Subsystem for Linux)

To **install** (in **Windows PowerShell**)

`wsl --install`

To check status

`wsl --status`

> [!NOTE]
> Extra details
> https://learn.microsoft.com/en-us/windows/wsl/install
>
> ***Enable Virtualazation in BIOS*** 
> https://yandex.ru/video/preview/2809549896879216036

### Step 2 Install Ubuntu.
https://ubuntu.com/desktop/wsl
> [!NOTE]
> (username, **password**. Do **not forget** it)
> 
> (тут устанавливается **пароль**, который надо **обязательно запомнить**).

### Step 3 Install Visual Studio Code.
https://code.visualstudio.com/download

Once installed, to start, type:

`code .`

> [!NOTE]
> Sample example from youtube (includes step 2):
> https://www.youtube.com/watch?v=av0UQy6g2FA&t=7s
>
> Another example (connecting Visual Studio):
> https://youtu.be/bRW5r7TK6KM?si=dFliCqgJBmK4KzAq&t=372 (Ctrl + L, `\\wsl$`; Extentions->remote wsl)

### Step 4 Install the compiler:

```
sudo apt-get update
sudo apt-get install g++
```

### Step 5 Execute:

```
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
```
Extra commands example:
```
pwd
ls
ls *.C
cat HelloStraus.C
grep -i cout HelloStraus.C
```

#### HelloStraus.C
```C
#include "std_lib_facilities.h"
int main ()
{
  cout << "Hello, Straus!\n";
  cout << "Here we go!\n";
  return 0;
}
```


**Compile** (should generate **a.out**):

`g++ HelloStraus.C`

**Run a program:**

`./a.out`

**Compile** (should generate **HelloStraus.exe**)

`g++ -std=c++11 -g -o HelloStraus.exe HelloStraus.C  2>&1 | tee tmp.txt`

**Run** a program:

`./HelloStraus.exe`

## Command details:

`pwd`       // show current directory

`ls`        // list directory

`ls -altr`  // list files (including hiddent that start with '.'). a = all, l = long info, -t = sort by time, -r = reverse order

`cat FILENAME` // display file content

`cp FILEFROM FILETO`  // copy file FROM to a new file FROM to a new file TO

`grep PATTERN FILE` // search for a regular expression PATTERN in a FILE 

`df -h`     // show mount points (in case you need to access windows folder)

`man COMMAND` // will print help information on a given command

`lsb_release -a` // which ubuntu release do we have

`grep -ir PATTERN *` // search recursively for PATTERN in all the files 

> [!TIP]
> In `~/.bashrc` set
>
> `alias lr='ls -ltr'`
>
> To source the file do `. ~/.bashrc`

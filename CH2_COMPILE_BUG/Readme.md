# Ch2 Compile Bug
Compile HelloStraus_Bug*.C examples

## Where does <iostream> come from?
```
g++ -E -x c++ - -v < /dev/null
```

## What is the difference?


```
g++ HelloStraus_Bug1.C
./a.out
./a.out > tmp.txt
./a.out |tee tmp.txt
./a.out 2>&1 |tee tmp.txt
g++ HelloStraus_Bug1.C > tmp.txt
g++ HelloStraus_Bug1.C |tee tmp.txt
g++ HelloStraus_Bug1.C 2>&1 |tee tmp.txt
```

## Explanation
google translate https://translate.google.com/?sl=en&tl=ru&text=append&op=translate

In Linux, the
`>` symbol is a **redirection** operator used to **redirect** the standard **output** of a command to a **file**. This means that instead of the command's output being displayed on your terminal screen, it will be written to the specified **file**

In Linux,
`>>` is an output **redirection** operator that **appends** the **output** of a command to the end of a specified **file**

In Linux, the vertical bar symbol `|` is called a
pipe. It's a powerful tool used to **connect** the **output** of one command to the **input** of another, creating a chain or "pipeline" of commands

In Linux, the `tee` command reads from **standard input** and writes to **both** standard **output** and one or more **files** simultaneously. It's essentially a "splitter" that allows you to view output while also saving it to a file. 

In Linux shell scripting,
`2>&1` is a powerful **redirection** operator used to **combine** the **error** output (standard error) with the **regular** output (standard output) of a command or program

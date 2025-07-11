# Ch2 Compile Bug
Compile HelloStraus_Bug*.C examples

## What is the difference?


```
g++ HelloStraus_Bug1.C
./a.out
./a.out > tmp.txt
./a.out |tee tmp.txt
g++ HelloStraus_Bug1.C > tmp.txt
```

## Explanation
google translate https://translate.google.com/?sl=en&tl=ru&text=append&op=translate

In Linux, the
`>` symbol is a redirection operator used to redirect the standard output of a command to a file. This means that instead of the command's output being displayed on your terminal screen, it will be written to the specified file

In Linux,
`>>` is an output **redirection** operator that **appends** the **output** of a command to the end of a specified file

In Linux shell scripting,
`2>&1` is a powerful **redirection** operator used to **combine** the **error** output (standard error) with the **regular** output (standard output) of a command or program

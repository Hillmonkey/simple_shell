<p align="center">

<img src="http://media.giphy.com/media/SgJvoYdHHrCjm/giphy.gif">
<br>



<h1><p align="center">Simple Shell</h1></p></font>





# Simple Shell
Simple Shell is a command line interface that accepts commands entered by the user and executes them. This shell is the final project of the first 3 months at Holberton School.

Simple Shell allows the user to run executable files that in folders specified by the `$PATH` environmental variable, in addition to executable files with explicitly specified paths.

How to compile from source: `gcc -Wall -Werror -Wextra -pedantic *.c -o shell`.
This code was compiled using gcc, version 4.8.4.

## Example of how to launch the shell after compiling:
`./shell`

* Output: prompt to terminal: `$ `

## Syntax
The shell works by using commands given by the user input. The shell commands take in the following syntax: `command name {arguments}`. The shell executes a command after it is written by user using the command followed by the arguments.

`ls`
The above example takes in a command by the user and will list all files and directories in current working directory. 
For each operand that names a file of a type other than directory, ls displays its name as well as any requested, associated information.  For each operand that names a file of type directory, ls displays the names of files contained within that directory, as well as any requested, associated information.
If no operands are given, the contents of the current directory are displayed.  If more than one operand is given, non-directory operands are displayed first; directory and non-directory operands are sorted separately and in lexicographical order.

For more information on ls, you can use the `man` command which will show a manual of the given command or any command you wish to know more information on. It contains system calls, libraries and other important files.

The shell also contains two builtins which are commands that are within the shell itself. The two builtins are `exit` and `env`. You can also use `help` command to know which builtins are provided by the shell. The `help` command works similarly to the manual where it provides further detail or information on given builtin.

### Unpredictable Results
The following variables take a buffersize of 1024:
* `PATH_TOKENS`
* `CMD_TOKENS`
* `FULL_PATH`

Disclosure this program takes no more than 1024, using more than alloted 1024 will cause segmentation fault or unpredictable behavior.

### Compilation
All files will be compiled with the following: `$ gcc -Wall -Werror -Wextra -pedantic *.c`



### List of useful commands
* `mv` - helps to move one file into another file
* `cat` - prints and concatenates files to the standard output
* `pwd` - given you the current working directory
* `less` - will let you go backward and forward in the files
* `cp` -copies a file into another file
* `grep` - helps to search for a file in a specific pattern
* `ls` - will list all files and directories in current working directory



### Builtins
There are two builtins programmed into the shell. Below is a description and use for each builtin.

* `env` - The env command is a command that tells the shell program to display all of the environment variables with their values. It is a    way to access those values through the shell.

* `exit` - If you wish to exit out of the shell the user can use the builtin `exit`.


### Exiting commands and the shell
To exit out of a command or process the user can use `ctrl c`. `Control c` stops a process and causes it to abort.
The user can also utilize the command `ctrl D` which will just exit. When the command `ctrl D` is used an exit status of 0 is given. Using exit, you can input its exit status or it is defaulted to the status of the last command executed.

## Files
* `README.md` : Current file, contains information about this project
* `Authors`: File with list of contributing authors
* `man_1_simple_shell`: File for executing man page on the turtle shell
* `holberton.h` : Header file, contains all prototypes for funcitons used, as well as libriaries
* `_getline.c`: Gets line from prompt
* `built_ins.c`: Commands built in 
* `error_switch.c`: Switch cases for errors
* `exec_cmd.c`: Execute commands
* `execute_built.c`: Execute built ins being called
* `helper1.c`: 
* `helper2.c`:
* `hsh.c`: The file where all functions are being called
* `init_free.c`:
* `math_helper.c`: 
* `prompt.c`: Prompt creator deals with interactive non-interactive



### Comments

### Authors
* Wendy Segura - https://github.com/wendysegura
* Larry Madeo - https://github.com/Hillmonkey

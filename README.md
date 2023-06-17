0x16. C - Simple Shell

Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

General
Who designed and implemented the original Unix operating system
Who wrote the first version of the UNIX shell
Who invented the B programming language (the direct predecessor to the C programming language)
Who is Ken Thompson
How does a shell work
What is a pid and a ppid
How to manipulate the environment of the current process
What is the difference between a function and a system call
How to create processes
What are the three prototypes of main
How does the shell use the PATH to find the programs
How to execute another program with the execve system call
How to suspend the execution of a process until one of its children terminates
What is EOF / “end-of-file”?

The shell is a command that reads lines from either a file or the termi‐
     nal, interprets them, and generally executes other commands.  It is the
     program that is running when a user logs into the system (although a user
     can select a different shell with the chsh(1) command).  The shell imple‐
     ments a language that has flow control constructs, a macro facility that
     provides a variety of features in addition to data storage, along with
     built in history and line editing capabilities.  It incorporates many
     features to aid interactive use and has the advantage that the interpre‐
     tative language is common to both interactive and non-interactive use
     (shell scripts).  That is, commands can be typed directly to the running
     shell or can be put into a file and the file can be executed directly by
     the shell.

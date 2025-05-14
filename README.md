# Spring 2025 System Programming — Final Project

* **Do not start this project until you have read these instructions carefully and you understand them. If something is not clear, ask.**

---

## ❖・Before You Begin・❖

1. Log in to GitHub.
2. Fork this repository. See [this video](http://code-warrior.github.io/tutorials/git/github/forking-and-cloning-at-the-github-web-site/) on how to carry out this step and step `3`.
3. Clone your fork, using either the web site or the GitHub Desktop client.
4. Checkout your personalized branch, the one with your name.

---

## ❖・Instructions・❖

This final project is divided into two sections: written and programming. For the written portion, write your answers directly in the `WRITTEN.md` file. The answers may be found in your notes and/or the readings from The Linux Programming Interface book.

Directions for each of the four programming projects appears below. Write your code in the included `.c` files.

**Note**: *Do not edit the Makefile*

### Extra Credit

Extra credit is built into this assignment’s grading. See the **Grading** section below.

### Program 1

As discussed in chapters 2 and 4, every process has an ID and a parent who also has an ID. Write a C program — no shell scripts — that reports the PID of the parent of the `top` program. You will need to run the `top` program in a Terminal window before writing the output of your C program in a separate window.

### Program 2

Write a C program that uses `main`'s third argument to render the current user's `SHELL`, `PATH`, and `USERNAME` variables. What else can you view through the third argument to `main`?

### Program 3

Recall that the `lseek()` system call allows for the read-write offset, or pointer, to be placed anywhere in a file. Using this `README.md` file as your file descriptor, replace `Program 3` in the heading of this section with its uppercase equivalent: `PROGRAM 3`.

### Program 4

Write a C program that dynamically allocates 1024 bytes of memory to a string. Don’t print the results. In the same program, render the end of the program text, the end of the initialized data segment, and the end of the uninitialized data segment.

---

## ❖・Grading・❖

| Item                             | Points |
|----------------------------------|:------:|
| `program-1.c` works              |  `20`  |
| `program-2.c` works              |  `20`  |
| `program-3.c` works              |  `20`  |
| `program-4.c` works              |  `20`  |
| Question 1 is correct (written)  |  `5`   |
| Question 2 is correct (written)  |  `5`   |
| Question 3 is correct (written)  |  `5`   |
| Question 4 is correct (written)  |  `5`   |
| Question 5 is correct (written)  |  `5`   |
| Question 6 is correct (written)  |  `5`   |
| Question 7 is correct (written)  |  `5`   |
| Question 8 is correct (written)  |  `5`   |
| Question 9 is correct (written)  |  `5`   |
| Question 10 is correct (written) |  `5`   |

---

## ❖・Due・❖

Wednesday, 14 May 2025, at 10:00 PM. **`NO` late assignments will be accepted, unless you can provide documentation of an emergency.**

---

## ❖・Submission・❖

You will need to issue a pull request back into the original repo, the one from which your fork was created for this project. See the **Issuing Pull Requests** section of [this site](http://code-warrior.github.io/tutorials/git/github/index.html) for help on how to submit your assignment.

**Note**: This assignment may *only* be submitted via GitHub. **`NO` other form of submission will be accepted**.

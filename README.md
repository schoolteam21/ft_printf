# ft_printf

Regardless of the programming language considered, the printf function, (or its equivalents) is always highly useful. The main reason is the ease of its formatting, and the support of diverse types in variable numbers. Some variations even propose to be able to write the resulting string of characters either in a file descriptor or in a particular stream.
Some also propose to recall this string without printing it. In short, undeniably, printf is a vital function. In this project, we ask you to recode it and add it to your libft so that you can use it in all your future projects, such as ft_ls...

## Goals
This project's aim is to recode the libc's printf function.

### This version supports the following conversions:
<ul>
<li>csp</li>
<li>diouxX with flags:</li>
<ul>
<li>hh</li>
<li>h</li>
<li>ll</li>
<li>l</li>
</ul>
<li>f with flags:</li>
<ul>
<li>l</li>
<li>L</li>
</ul>
</ul>

### It also supports:
<ul>
<li>%% management</li>
<li>#, 0, -, +, " " flags</li>
<li>width</li>
<li>precision</li>
</ul>


Some cases of undefined behaviour are managed to work properly.

## Installation

Use Makefile to compile.
```bash
make
```

# 42sh

# About
With the Minishell projects, we discovered the “behind the scenes” of a shell. More specifically, your explored the process’ synchronisation creation with functions such asfork and wait. We also discovered inter-process communication, using pipes, as well asredirections and line edition, using termcaps.
With the 42sh project, we will go even further by adding functionailities such as globbing management, subshells and inhibitor.
![](42sh_screen.gif)
## Installation
1. Download/Clone this repo
```
git clone https://github.com/pankratdodo/42sh.git
```
2. Run
```
cd 42sh && make && ./42sh
```

## Main project instructions
#### General Instructions

- Project must be written in C in accordance with [the Norm](https://github.com/R4meau/minishell/blob/master/norme.en.pdf).
- Program cannot have memory leaks.
- No Segmentation fault, bus error, double free, etc.
- Within the mandatory part, you are allowed to use only the following libc functions:
    - The whole man 2 section
    - All the functions allowed in [other minishells](https://github.com/pankratdodo/21sh)
    - Every functions of the `termcaps` library
- The “;” command line separator
- Pipes “|”
- Redirection and aggregation operators `<`, `>`, `<<`, `>>`, `>&`, `<&`
- File descriptor aggregation
- Use `UP` and `DOWN` arrows to navigate through the command history
- Cut, and paste all line using the `Ctrl-U` `Crtl-Y` keys
- Go directly to the beginning or the end of a line by pressing `home` and `end`
- Write AND edit a command over a few lines. `SHIFT+UP` and `SHIFT+DOWN` allow to go from one line to another in the command while remaining in the same column or otherwise the most appropriate column.
- Following built-ins: `cd`, `echo`, `exit`, `type`
- Monitoring of intern shell variables:
    - Intern variable creation depending on syntax: `name=value`
    - Intern variable exportation to the environment, via built-in `export`
    - Possibility to list shell intern variables via built-in `set`
    - Intern and environement variables revocation, via built-in `unset`
    - Environment variable creation for unique command, for instance: `HOME=/tmp`
    - Simple expansion of parameters depending on syntax `${}`
    - Exit code access of previously command via the expansion `${?}`
- Job control monitoring, with buitl-ins `jobs`, `fg`, `bg` and the `&` operator
- A correct monitoring of all signals
- Each built-in must have the enounced options byy [POSIX](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html) standard, except for explicit case as `set` or `unset`.

#### Modular Part

- Inhibitors `”` (double quote), `’` (simple quote) and `\`
- Arithmetic expansion: `$(())` Only these operators:
    - Incrementality, decrementing `++` `--`
    - Addition, Soustraction `+` `-`
    - Multiplication, division, modulo `*` `/` `%`
    - Comparison `<=` `>=` `<` `>`
    - Equality, differencies `==` `!=`
    - AND/OR logical `&&` `||`
- Complete management of the history:
    - Expansions: `!!`, `!word`, `!number`, `!-number`
    - Saving to a file so that it can be used over several sessions
    - Built-in `fc` (all [POSIX](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html) options)
    - Incremental search in the history with `CTRL-R`
- Contextual dynamic completion of commands, built-ins, files, internal and environment variables. What is meant by contextual? re-we use the `ls /` command and your cursor is on the `/`, then a contextual completion will only propose the content of the root folder and not the commands or built-ins. Same for this case:
`echo ${S`, the completion should only propose variable names that start with S, whether internal or environmental.
- Alias management via built-ins `alias` and `unalias`
- A hash table and built-in `hash` to interact with it.

#### Bonus Part

- Autocompletion for order/built-ins parameters
- A shell compliant with the [POSIX](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html) Standard
- File of history is individual
- File of history is encrypted
- May take as a single argement a set of commands in the form of text. Run:
```
./42sh 42cmd
```
![](42cmd_screen.gif)
- Have a [git history](https://github.com/mbrellaV/42sh) and explicit commit messages
- Threads at Makefile

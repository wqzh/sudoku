[中文](README.md) | English

[Click me, Open Sudoku solver](https://htmlpreview.github.io/?https://raw.githubusercontent.com/wqzh/sudoku/blob/main/browser/index.html)

# Sudoku Solver

A backtracking-based Sudoku solver supporting Web, Android, and C platforms.

## Project Structure

```
sudoku/
├── browser/     # Web version (open directly in browser)
├── android/     # Android version
└── c_solver/    # C language version
```

## browser Version

The browser version requires no installation. Simply open `browser/index.html` in a browser.

### Features

- Sudoku input (manual input / load example)
- Placeholder selection (0, x, *) for unknown cells
- Solver with up to 5 solutions
- Pagination for multiple solutions
- Conflict detection
- Board clear

### Usage

1. Open `index.html` in a browser
2. Click "Manual Input" to enter a puzzle, or "Load Example" for a sample
3. Click "Solve" to get the answer

```shell
# Manual Input Examples
53xx7xxxx
6xx195xxx
x98xxxx6x
8xxx6xxx3
4xx8x3xx1
7xxx2xxx6
x6xxxx28x
xxx419xx5
xxxx8xx79


xx4xxxxx7
xxxx2xx9x
xxx5xx1xx
x7xxx1xxx
xxxx8xxxx
xxx9xxx3x
xx1xx7xxx
x9xx4xxxx
8xxxxx5xx
```
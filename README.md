
中文 | [English](README_en.md)


# 数独求解器

一个基于回溯算法的数独求解器，支持 Web、Android 和 C 三种平台。

## 项目结构

```
sudoku/
├── browser/     # Web 版（浏览器直接打开）
├── android/     # Android 版
└── c_solver/    # C 语言版
```

## browser 版

浏览器版本无需安装，直接用浏览器打开 `browser/index.html` 即可使用。

### 功能

- 数独题目输入（手动输入 / 填入示例）
- 支持选择占位符（0、x、*）表示未知
- 求解并显示最多 5 个解
- 多解翻页浏览
- 冲突检测
- 清空棋盘

### 使用方法

1. 在浏览器中打开 `index.html`
2. 点击「手动输入」输入数独题目，或点击「填入示例」加载示例
3. 点击「求解」获取答案

```shell
# 手动输入杨丽
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
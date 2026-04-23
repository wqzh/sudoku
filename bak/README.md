# 数独求解器 (Sudoku Solver)

一个数独求解应用，包含网页版。纯 JavaScript 实现，零依赖，单文件即可运行。

## 功能特性

- **9x9 标准数独棋盘**，3x3 宫格加粗分隔
- **手动输入**：用户可填入初始数字（1-9）
- **一键求解**：纯 JS 回溯算法，无需编译
- **多解展示**：支持最多 5 个解的切换浏览
- **结果高亮**：绿色标记新填入的数字
- **解数量统计**：显示总解数，无解时给出提示

## 快速开始

### 1. 直接运行

双击 `index.html` 文件即可在浏览器中打开。

### 2. 或使用本地服务器（推荐）

```bash
python -m http.server 8080
```

然后访问 `http://localhost:8080`

## 使用方法

1. **填入初始数字**：在空白格中输入 1-9
2. **点击"求解"**：
   - 无解：显示"无解"
   - 唯一解：直接展示，绿色高亮新数字
   - 多个解：显示总数，使用左/右箭头切换
3. **点击"清空"**：确认后清除所有输入

## 求解器接口

```javascript
const { count, solutions } = Solver.findSolutions(inputArray, maxSolutions);
```

| 参数 | 说明 |
|------|------|
| `inputArray` | 81 个整数（行优先），0 = 空白 |
| `maxSolutions` | 最多返回解的数量（默认 5） |
| `count` | 找到的解数量 |
| `solutions` | Int8Array 数组，每个包含 81 个整数 |

## 技术栈

- **求解引擎**：纯 JavaScript 回溯算法
- **前端**：原生 HTML / CSS / JavaScript
- **构建**：无构建步骤，零依赖

## 项目结构

```
sudoku/
├── index.html              # 网页主文件（含 JS 求解器 + CSS）
├── wasm/                   # 原 WASM 编译输出（已废弃）
├── c_solver/               # 原 C 语言求解器（已废弃）
│   ├── solver.c
│   └── Makefile
├── tutorial/
│   └── wasm_compile.md     # 原 WASM 编译教程（已废弃）
├── .gitignore
└── README.md
```

## License

MIT

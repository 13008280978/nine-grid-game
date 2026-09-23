# 九宫格小游戏（Nine Grid Game）

基于 **EasyX 图形库** 的 C++ Windows 桌面小游戏：在 3×3 网格中点击最底行的黑块得分，黑块连锁下落并随机补位。

## 玩法

- 3×3 网格，每一行随机出现一个黑块（其余为白块）
- 点击**最底行**的黑块：命中 +10 分，全部黑块下移一行，顶部随机生成新黑块
- 点错白块则游戏结束

## 技术要点

| 要点 | 实现 |
| --- | --- |
| 图形渲染 | EasyX `graphics.h`，`initgraph(300, 360)` 创建窗口 |
| 防闪烁 | `BeginBatchDraw()` / `EndBatchDraw()` 双缓冲批量绘图 |
| 交互 | `MOUSEMSG` 捕获鼠标消息，点击坐标 → 网格下标映射判定 |
| 随机逻辑 | `rand()` + 时间种子，随机生成黑块列位置并循环补位 |

## 构建环境

- Visual Studio 2022（PlatformToolset v143，Windows SDK 10.0，x64）
- [EasyX 图形库](https://easyx.cn)（安装后自带 `graphics.h`）

## 运行

```bash
# 方式一：直接运行 Release 中的可执行程序
# Release v1.0.0 附件：JiuGongGe.exe（即九宫格.exe，GitHub 资产名不支持中文故用拼音）
JiuGongGe.exe

# 方式二：源码编译
# 1. 安装 EasyX：https://easyx.cn
# 2. Visual Studio 2022 打开 nine-grid-game.sln
# 3. 选择 x64 配置，F5 编译运行
```

## 目录结构

```
.
├── nine-grid-game.sln
├── nine-grid-game.vcxproj
└── main.cpp          # 全部游戏逻辑（单文件实现）
```

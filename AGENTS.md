# 数据结构学习仓库

## 项目信息
- **用途**：个人学习数据结构的代码笔记
- **作者**：985 大学生，记录自己的学习过程
- **仓库地址**：https://github.com/dahuang546/data-structure-notes
- **GitHub 用户名**：dahuang546

## 目录结构
```
.
├── 顺序表/          # 数组实现的线性表 (linear2.c, test.c)
├── 链表/            # 单链表 (list.c)
├── 栈/              # 栈：数组实现 + 链表实现
├── 队列/            # 链式队列 (queue.c)
├── 串/              # 字符串操作（未完成）
└── 2026-04-23-学习笔记.md   # 学习日记
```

## 常用操作
- 编译：`gcc -o output/xxx xxx.c`（输出到 output/，已被 gitignore）
- 推送：直接 `git push`，Token 已配置在钥匙串
- 日记：按日期命名，如 `2026-04-23-学习笔记.md`

## GitHub 认证方式
本仓库已配置多种 GitHub 认证方式，按需使用：

| 方式 | 命令 | 适用场景 |
|-----|------|---------|
| **Git 钥匙串**（已配置） | `git push` | 日常推送，最常用 |
| **GitHub CLI 设备流** | `gh auth login --web` | 需要 `gh` 命令行工具权限时 |
| **GitHub CLI Token** | `gh auth login --with-token < token.txt` | 脚本化或自动化场景 |

**`gh auth login --web` 使用步骤：**
1. 运行命令，复制输出的 one-time code
2. 浏览器打开 https://github.com/login/device
3. 粘贴 code 并授权

## 注意事项
- 代码风格偏随意，注释尽量写清楚
- 编译环境：macOS + VSCode + Clang
- 串的部分还没写完，持续更新中

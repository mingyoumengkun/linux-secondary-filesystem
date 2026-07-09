# Linux 二级文件系统模拟

用C语言实现的Linux二级文件系统模拟器

## 功能特性

- **login**: 用户登录
- **dir**: 列出目录（显示文件名、物理地址、保护码、文件长度）
- **create**: 创建文件
- **delete**: 删除文件
- **open**: 打开文件
- **close**: 关闭文件
- **read**: 读取文件内容
- **write**: 写入文件内容

## 文件保护

支持读写保护机制：
- 0: 无保护
- 1: 只读保护
- 2: 禁止写
- 3: 完全禁止

## 项目结构

```
├── README.md
├── fs.h              # 文件系统核心头文件
├── fs.c              # 文件系统核心实现
├── main.c            # 主程序和命令行界面
└── Makefile          # 编译文件
```

## 编译和运行

```bash
make
./filesystem
```

## 使用示例

```
login user1
create file1.txt
open file1.txt
write hello world
close
dir
```

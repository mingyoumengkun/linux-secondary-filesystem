# Linux 二级文件系统模拟

用C语言实现的Linux二级文件系统模拟器

## 功能特性

- **login**: 用户登录
- **logout**: 用户登出
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
├── README.md              # 项目说明
├── fs.h                   # 文件系统核心头文件
├── fs.c                   # 文件系统核心实现
├── main.c                 # 主程序和命令行界面
└── Makefile               # 编译配置
```

## 编译和运行

```bash
# 编译
make

# 运行
./filesystem

# 清理编译文件
make clean
```

## 命令说明

| 命令 | 用法 | 说明 |
|------|------|------|
| login | `login <username>` | 登录系统，自动创建新用户 |
| logout | `logout` | 登出系统 |
| dir | `dir` | 列出所有文件及详细信息 |
| create | `create <filename> [protect_code]` | 创建文件（保护码：0-3） |
| delete | `delete <filename>` | 删除文件 |
| open | `open <filename> <mode>` | 打开文件（0=读，1=写） |
| close | `close <fd>` | 关闭文件 |
| read | `read <fd> [size]` | 读取文件内容 |
| write | `write <fd> <data>` | 写入文件内容 |
| help | `help` | 显示帮助信息 |
| exit | `exit` | 退出程序 |

## 使用示例

```bash
# 1. 登录用户
login user1

# 2. 创建文件（无保护）
create file1.txt 0

# 3. 创建只读文件
create secret.txt 1

# 4. 打开文件进行写操作
open file1.txt 1

# 5. 写入数据
write 0 Hello World

# 6. 关闭文件
close 0

# 7. 重新打开文件进行读操作
open file1.txt 0

# 8. 读取数据
read 0 11

# 9. 关闭文件
close 0

# 10. 列出目录
dir

# 11. 删除文件
delete file1.txt

# 12. 登出
logout

# 13. 退出程序
exit
```

## 实现细节

### 数据结构

- **User**: 用户信息结构
- **FileEntry**: 文件条目结构（包含文件名、所有者、保护码、大小、物理地址等）
- **OpenFile**: 打开文件表项（跟踪打开的文件和文件指针）
- **FileSystem**: 文件系统总体结构

### 特性

- ✅ 多用户支持
- ✅ 文件保护机制（读写保护）
- ✅ 块分配和回收
- ✅ 文件指针管理
- ✅ 详细的目录列表
- ✅ 错误检查和提示

## 编译信息

- C标准: C99
- 编译器: gcc
- 编译标志: -Wall -Wextra -std=c99

## 作者

mingyoumengkun

## 许可证

MIT License

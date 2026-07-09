#ifndef FS_H
#define FS_H

#include <time.h>

#define MAX_FILENAME 50
#define MAX_FILES 100
#define MAX_USERS 20
#define MAX_OPEN_FILES 20
#define MAX_FILE_SIZE 10000
#define MAX_BLOCKS 1000

/* 文件保护码定义 */
#define PROTECT_NONE 0      /* 无保护 */
#define PROTECT_READ 1      /* 只读保护 */
#define PROTECT_WRITE 2     /* 禁止写 */
#define PROTECT_ALL 3       /* 完全禁止 */

/* 用户结构 */
typedef struct {
    int user_id;
    char username[MAX_FILENAME];
    int is_logged_in;
} User;

/* 文件结构 */
typedef struct {
    int file_id;
    char filename[MAX_FILENAME];
    int owner_id;
    int protect_code;          /* 保护码 */
    int file_size;             /* 文件长度 */
    int start_block;           /* 物理地址（起始块号） */
    int block_count;           /* 占用的块数 */
    time_t create_time;
    time_t modify_time;
    int is_deleted;
} FileEntry;

/* 打开文件表项 */
typedef struct {
    int file_id;
    int user_id;
    int open_mode;             /* 0: 读模式, 1: 写模式 */
    int file_pointer;          /* 文件指针位置 */
} OpenFile;

/* 文件系统结构 */
typedef struct {
    User users[MAX_USERS];
    int user_count;
    
    FileEntry files[MAX_FILES];
    int file_count;
    
    OpenFile open_files[MAX_OPEN_FILES];
    int open_file_count;
    
    int current_user_id;       /* 当前登录用户ID */
    
    char blocks[MAX_BLOCKS * 100];  /* 数据块（每块100字节） */
    int block_bitmap[MAX_BLOCKS];   /* 块位图：0表示空闲，1表示已使用 */
} FileSystem;

/* 函数声明 */
FileSystem* fs_init(void);
void fs_destroy(FileSystem* fs);

/* 用户管理 */
int fs_login(FileSystem* fs, const char* username);
int fs_logout(FileSystem* fs);
int fs_get_current_user(FileSystem* fs);

/* 文件操作 */
int fs_create_file(FileSystem* fs, const char* filename, int protect_code);
int fs_delete_file(FileSystem* fs, const char* filename);
int fs_open_file(FileSystem* fs, const char* filename, int mode);
int fs_close_file(FileSystem* fs, int fd);
int fs_read_file(FileSystem* fs, int fd, char* buffer, int size);
int fs_write_file(FileSystem* fs, int fd, const char* data, int size);

/* 目录操作 */
void fs_list_directory(FileSystem* fs);

/* 块管理 */
int fs_allocate_block(FileSystem* fs);
void fs_free_block(FileSystem* fs, int block_num);

#endif

# C 语言指针与链表综合示例

> 一个涵盖指针基础、数组、函数参数传递、字符串、二级指针和单链表操作的完整教学程序。

## 功能概览

本程序包含 6 个独立的教学演示模块，循序渐进地展示 C 语言指针的核心概念：

| 模块 | 函数 | 教学主题 | 核心知识点 |
| :--- | :--- | :--- | :--- |
| demo1 | `demo1_basic()` | 指针基础 | 取地址 `&`、解引用 `*`、通过指针修改变量 |
| demo2 | `demo2_array()` | 指针与数组 | 数组名即首元素地址、指针遍历数组、`*(p+i)` 与 `arr[i]` 等价 |
| demo3 | `demo3_swap()` | 指针与函数参数 | 值传递（不改变实参）vs 指针传递（改变实参），`swap` 经典案例 |
| demo4 | `demo4_string()` | 指针与字符串 | 字符指针遍历字符串、`'\0'` 终止符判断 |
| demo5 | `demo5_double_pointer()` | 二级指针 | 指向指针的指针，`int**` 的使用 |
| demo6 | `demo6_linked_list()` | 链表操作（综合） | 头插法、头删法、链表逆置、二级指针传参、内存释放 |

## 代码结构
pointer_demo.c
pointer_demo.c
├── demo1_basic() // 指针基本用法
├── demo2_array() // 指针与数组
├── demo3_swap() // 对比演示值传递与指针传递
│ ├── swap_wrong() // 错误示例：值传递（不交换）
│ └── swap_right() // 正确示例：指针传递（交换）
├── demo4_string() // 指针与字符串
├── demo5_double_pointer() // 二级指针
├── demo6_linked_list() // 链表完整演示
│ ├── typedef struct Node // 链表节点结构体定义
│ ├── printList() // 打印链表
│ ├── insertHead() // 头插法（使用二级指针）
│ ├── deleteHead() // 头删法（使用二级指针）
│ └── reverseList() // 链表逆置（使用二级指针）
└── main() // 依次调用 demo1 ~ demo6


## 🔧 编译与运行

### 环境要求
- 任意 C 编译器（GCC ≥ 4.8、Clang、MSVC）
- 支持 C99 或更高标准

### 编译命令（以 GCC 为例）
```bash
gcc -o pointer_demo pointer_demo.c

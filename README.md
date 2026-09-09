## 代码结构

程序按功能划分为 6 个教学模块，每个模块包含若干辅助函数：

### 模块一：指针基础
| 函数 | 说明 |
| :--- | :--- |
| `demo1_basic()` | 演示指针的取地址、解引用及通过指针修改变量 |

### 模块二：指针与数组
| 函数 | 说明 |
| :--- | :--- |
| `demo2_array()` | 演示数组名即首元素地址，指针遍历数组 |

### 模块三：指针与函数参数
| 函数 | 说明 |
| :--- | :--- |
| `swap_wrong(int a, int b)` | 错误示例：值传递，不改变实参 |
| `swap_right(int *a, int *b)` | 正确示例：指针传递，交换实参 |
| `demo3_swap()` | 对比调用两种 swap 函数的效果 |

### 模块四：指针与字符串
| 函数 | 说明 |
| :--- | :--- |
| `demo4_string()` | 演示用字符指针遍历字符串 |

### 模块五：二级指针
| 函数 | 说明 |
| :--- | :--- |
| `demo5_double_pointer()` | 演示指向指针的指针（`int**`） |

### 模块六：链表操作（综合）
| 函数 | 说明 |
| :--- | :--- |
| `typedef struct Node` | 链表节点结构体定义（data + next） |
| `printList(Node *head)` | 遍历并打印链表 |
| `insertHead(Node **head, int val)` | 头插法（使用二级指针） |
| `deleteHead(Node **head)` | 头删法（使用二级指针） |
| `reverseList(Node **head)` | 链表逆置（使用二级指针） |
| `demo6_linked_list()` | 综合演示头插、逆置、头删及内存释放 |

### 程序入口
| 函数 | 说明 |
| :--- | :--- |
| `main()` | 依次调用 demo1 ~ demo6，输出所有演示内容 |

---

## 编译与运行

### 环境要求
- 任意 C 编译器（GCC ≥ 4.8、Clang、MSVC）
- 支持 C99 或更高标准

### 编译命令（以 GCC 为例）
```bash
gcc -o pointer_demo pointer_demo.c

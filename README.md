## 1 从基础开始——预备知识和复习
### 1.2 关于指针
1. 指针类型
    - `指针类型`不是单独存在的, 它是由其他类型派生而成的. 也就是说, 实际上存在的类型是 `指向int的指针类型`, `指向double的指针类型` etc.
    
2. 指针类型, 指针类型变量, 指针类型的值
    - 因为 `指针类型` 是类型, 所以它和 `int类型`, `double类型` 一样, 也存在 `指针类型变量` 和 `指针类型的值`. 三者经常都统称为 `指针`, 非常容易造成歧义, 需要根据上下文语境进行判断
    - 先有 `指针类型`, 因为有了 `指针类型`, 所以有了 `指针类型的变量` 和 `指针类型的值`
    
3. 变量不一定按照声明的顺序保存在内存中

4. 指针运算
    - 指针运算是针对指针进行整数加减运算，以及指针之间进行减法运算的功能
    - 对指针加 `N`，指针前进 `当前指针指向的数据类型的长度 × N`
    
5. 空指针
    - 空指针是一个特殊的指针值
    - 空指针是指可以确保没有指向任何一个对象的指针, 通常使用宏定义 `NULL` 来表示空指针常量值
    - 空指针确保它和任何非空指针进行比较都不会相等，因此经常作为函数发生异常时的返回值使用
    
### 1.3 关于数组
1. 数组是指将固定个数、相同类型的变量排列起来的对象

2. 给指向数组的某个元素的指针加 N 后，指针会指向 N 个之后的元素

3. 表达式中，数组可以解读成 `指向它的初始元素的指针`; 尽管有三个小例外，但是这和在后面加不加`[]`没有关系

4. p[i] 与 *(p + i)
    - `p[i]` 是 `*(p + i)` 的简便写法, `p[i]` 的写法就是一种语法糖, 下标运算符 `[]` 原本就有这种用法，它和数组无关
    
    - 根据加法交换率 `*(p + i)` 等价于 `*(i + p)`; 相应地, `p[i]` 可以写成 `i[p]`, 但是不要这样写
    
5. 将数组作为函数的参数进行传递 ?
    - 在 C 中是不能将数组作为函数参数进行传递的; 但是，你可以 `通过传递指向初始元素的指针来达到将数组作为参数进行传递的目的`
    - 在 C 中，函数参数传递都是传值，向函数传递的都是参数的副本
    - 无论如何都要将数组进行值传递的时候，建议将数组整体整理成结构体成员

6. 数组作为函数的形参进行声明
    - 只有在声明函数形参时，数组的声明才被编译器解读成指针, 即 `int func(int a[])` 等价于 `int func(int *a)`, 即使定义了元素个数, 编译器也是无视的, `int func(int a[10])` 也与前两者等价

## 2 做个实验见分晓——C 是怎么使用内存的
### 2.1 虚拟地址
1. 当今的操作系统都会给应用程序的每一个进程分配独立的 `虚拟地址空间`. 这和 C 语言本身并没有关系，而是操作系统和 CPU 协同工作的结果.

2. fflush() 是对输出流使用的, 它不能用于输入流

### 2.2 C 的内存的使用方法
1. C 语言的 `三种变量作用域`
    - 全局变量
        - 在函数之外声明的变量，默认地会成为全局变量
        - 全局变量在任何地方都是可见的
        
    - 文件内部的静态变量
        - 通过 `static` 指定的变量（包括函数），对于其他源代码文件是不可见的
        - 就算对于像全局变量那样被定义在函数外面的变量，一旦添加了 `static`，作用域就只限定在当前所在的源代码文件中
        
    - 局部变量
        - 局部变量是指在函数中声明的变量
        - 局部变量只能在包含它的声明的语句块（使用{}括起来的范围）中被引用
        - 局部变量通常在它所在的语句块结束的时候被释放. 如果你不想释放某个局部变量，可以在局部变量上加上 `static` 进行声明
        
2. 在程序中，如果需要保持一些数据，必须在内存中的某个场所取得相应大小的内存区域. 总结一下，在 C 中有 `三种内存区域的寿命`
    - 静态变量
        - 静态变量的寿命从程序运行时开始，到程序关闭时结束
        - 静态变量包括:
            - 全局变量
            - 文件内的 static 变量
            - 指定 static 的局部变量
            
    - 自动变量
        - 自动变量的寿命到声明该变量的语句块执行结束为止
        - 自动变量包括:
            - 没有指定 static 的局部变量
            
    - 通过 `malloc()` 动态分配内存
        - 通过 malloc() 分配的领域的寿命到调用 free() 为止
        

### 2.3 函数和字符串常量
1. 函数自身和字符串常量被分配到内存中的 `只读内存区域`

2. 由于函数本身不可能需要改写，所以它被配置在内存的只读区域

3. 如果执行程序是只读的，在同一份程序被同时启动多次的时候，通过在物理地址上共享程序能够节约物理内存

4. 由于硬盘上已经存放了可执行程序，就算内存不足，也不需要将程序交换到虚拟内存，相反可以将程序直接从内存中销毁

5. 函数可以在表达式中被解读成 `指向函数的指针`

6. `指向函数的指针` 本质上也是指针(地址), 所以可以将它赋给指针型变量:
    ```
    // 比如有下面的函数原型：
    int func(double d);
    // 保存指向此函数的指针的变量的声明如下：
    int (*func_p)(double); 
    // 然后写成下面这样，就可以通过 func_p 调用 func，
    int (*func_p)(double);  // 声明
    func_p = func;          // 将 func 赋给 func_p
    func_p(0.5);            // 此时，func_p 等同于 func 
    ```
    
7. 将 `指向函数的指针` 保存在变量中的技术经常被运用在如下场合：
    - GUI 中的按钮控件记忆 `当自身被按下的时候需要调用的函数`
    - 根据 `指向函数的指针的数组` 对处理进行分配, 以代替 `switch case`
    
### 2.4 静态变量
1. 静态变量是从程序启动到运行结束为止持续存在的变量. 因此，静态变量总是在虚拟地址空间上占有固定的区域

2. 静态变量包括:
    - 全局变量
    - 文件内 static 变量
    - 指定 static 的局部变量
    
3. 关于函数和全局变量，如果它们的名称相同，即使它们跨了多个源代码文件也被作为相同的对象来对待, 进行这项工作的是一个被称为“链接器”的程序
    
4. 为了在链接器中将名称结合起来，各目标代码大多都具备一个符号表（symbol table）

### 2.5 自动变量 (栈)
1. 自动变量重复使用内存区域. 因此, 自动变量的地址是不一定的

2. C 语言中，在现有被分配的内存区域之上以 “堆积” 的方式，为新的函数调用分配内存区域
   在函数返回的时候，会释放这部分内存区域供下一次函数调用使用
   
3. C 语言中，通常将自动变量保存在栈中
    - 通过将自动变量分配在栈中，内存区域可以被重复利用，这样可以节约内存
    - 将自动变量分配在栈中, 有利于 `递归调用` 的实现
    
4. C 语言函数的参数是 `从后往前` 被堆积在栈中的 (后面的参数先进栈), 并且由 `调用方` 将参数从栈中除去
    - 无论需要堆积多少个参数，总能找到第一个参数的地址
    - 第一个参数一定存在于距离固定的场所
    
### 2.6 利用 malloc()来进行动态内存分配（堆）
1. C 语言中可以使用 `malloc()` 进行动态内存分配
    - 作用: `malloc()` 根据参数指定的尺寸来分配内存块，它返回指向内存块初始位置的指针
    - 用法: 
        - `p = malloc(size); free(p);`
        - malloc() 函数的返回值类型为 `void*`，`void*` 类型的指针可以不强制转型地赋给所有的指针类型变量
        - 一旦内存分配失败 (内存不足), malloc() 将返回 `NULL`
        - 利用 malloc() 分配的内存被结束使用时, 需要通过 `free()` 来释放内存
    - 用处
        - 动态分配结构体
        - 分配可变长数组
    
2. 像 malloc() 这样能够动态地（运行时）进行内存分配，并且可以通过任意的顺序释放的记忆区域，称为 `堆（heap）`

3. malloc() 属于标准库函数, 不是系统调用

4. malloc() 管理从操作系统一次性地被分配的内存，然后零售给应用程序，这是它大致的实现方式;
   因此，一般来说调用 free() 之后，对应的内存区域是不会立刻返还给操作系统的
   
### 2.7 内存布局对齐
1. C 标准规定，`sizeof(char)的结果必定为 1`

2. 根据 CPU 的不同，布局对齐填充的方式也不同; 即使手工进行布局对齐，也不能提高可移植性

### 2.8 字节排序
1. 小端字节序和大端字节序

2. 根据环境的不同，内存中的二进制映像的形式也不尽相同，所以那些试图将内存的内容直接输出到硬盘，或者通过网络进行传输以便不同的机器读取等想法都是不可取的

3. 无论是整数还是浮点小数，内存上的表现形式都随环境的不同而不同

## 3. 揭秘 C 的语法 --- 它到底是怎么回事
### 3.1 解读 C 的声明
1. 用 `英语` 来读 C 的声明, eg. `int (*pf)();` 被读成 `pf is pointer to function returning int`

2. 阅读 C 声明的详细步骤
    - 着眼于标识符 (变量名或函数名)
    - 从距离标识符最近的地方开始, 依照优先顺序解释派生类型 (指针, 数组和函数). 优先顺序说明如下:
        - 用于整理声明内容的 `()`
        - 用于表示数组的 `[]`
        - 用于表示函数的 `()`
        - 用于表示指针的 `*`
    - 解释完派生类型, 使用 `of`, `to`, `returning` 将它们连接起来 (array of, pointer to, function returning)
    - 最后, 追加数据类型修饰符 (在左边, int, double 等)
    > (注: 数组元素个数和函数的参数属于类型的一部分; 应该将它们作为附属于类型的属性进行解释)
    
3. C 语言声明解读示例

    C语言声明 | 英语表达 | 中文表达
    : ------ : | : ------ : | : ------:
    int hoge; | hoge is int | hoge 是 int
    int hoge[10]; | hoge is array of int | hoge 是 int 的数组
    int hoge[10][3]; | hoge is array of array of int | hoge 是 int 数组的数组
    int *hoge[10]; | hoge is array of pointer to int | hoge 是指向 int 的指针的数组
    double (*hoge)[3]; | hoge is pointer to array of double | hoge 是指向 double 的数组的指针
    int func(int a); | func is function returning int | func 是返回 int 的函数
    int (*func_p)(int a); | func_p is pointer to function returning int | func_p 是指向返回 int 的函数的指针
    
4. 在 C 中, 遇到以下情况需要定义 `类型`
    - 在强制转型运算符中
    - 类型作为 `sizeof` 运算符的操作数
    
### 3.2 C 的数据类型的模型
1. C 的所有类型可以用 `类型链` 表示, 链的最后面的元素是 `基本类型`, 从倒数第二个元素开始的元素都是 `派生类型` (指从某些类型派生出来的类型)

2. C 中除了结构体, 共用体之外, 还有以下三种派生类型:
    - 指针
    - 数组 ("元素个数" 作为它的属性)
    - 函数 ("参数信息" 作为它的属性)
    
3. 从基本类型开始，递归地（重复地）粘附上派生类型，就可以生成无限类型

4. 指针类型派生
    - `指针类型（pointer type）` 可由函数类型、对象类型或不完全的类型派生，派生指针类型的类型称为引用类型
    - 指针类型描述一个对象，该类对象的值提供对该引用类型实体的引用
    - 由引用类型 `T` 派生的指针类型有时称为 `（指向）T 的指针`
    - 从引用类型构造指针类型的过程称为 `指针类型的派生`, 这些构造派生类型的方法可以递归地应用
    - 对指针进行 `*` 运算符求值以及对指针进行加法运算时, 由不同类型派生出来的指针之间存在差异
    
5. 数组类型派生
    - 数组类型本质就是将一定个数的派生源的类型进行排列而得到的类型 
    
6. 指向数组的指针
    - 派生出`数组`之后，再派生出`指针`，就可以生成`指向数组的指针`
    - `指向int的指针` 和 `指向int数组的指针` 是完全不同的数据类型
    
7. C 中不存在多维数组
    - `int hoge[3][2]` 可以解读成 `hoge is array(元素个数3) of array(元素个数2)`
    - C 语言中不存在多维数组; 其实是 `数组的数组`
    - `数组` 就是将一定个数的类型进行排列而得到的类型; `数组的数组` 也只不过是派生源的类型恰好为数组
    - 将伪多维数组作为函数的参数进行传递, 如下所示, 前两种函数原型的写法是第三种写法的语法糖:
        - void func(int hoge[3][2]);
        - void func(int hoge[][2]);
        - void func(int (*hoge)[2]); (传递指向数组的指针)
        
8. 函数类型派生
    - 函数类型也是一种派生类型，`参数(类型)` 是它的属性
    - 函数类型与其他类型不同, 不能作为变量被定义, 且没有特定的长度 (非对象类型)
    - 从函数类型是不能派生出除了指针类型之外的其他任何类型的, 而且对指向函数类型的指针不能做指针运算
    - 从数组类型是不能派生出函数类型的, 因为在 C 中, 数组是不能作为函数返回值返回的
    
9. 计算类型的大小
    - 有特定长度的类型，在标准中称为对象类型
    - 除了函数类型和不完全类型，其他类型都有大小
    - 通过 `sizeof(类型名)` 编译器可以为我们计算当前类型的大小，无论是多么复杂的类型
    
10. 基本类型
    - 基本类型包括
        - char
        - int
        - float
        - double
        - 枚举
    - char 和 signed char 或者 unsigned char 同义；至于默认情况下，char 究竟是有符号的还是无符号的，C 标准并没有定义，而是取决于处理环境
    - 对于这些类型的大小，sizeof(char)（包含 signed、unsigned） 必定返回 1。其他的类型全部依赖处理环境的定义。即使是 char，在 sizeof 肯定会返回 1 的情况下，也没有规定肯定是 8 位，现实中也存在 char 为 9 的处理环境。
    
11. 结构体和共用体
    - 在语法上，结构体和共用体是作为派生类型使用的
    - 结构体类型可以集合几个其他不同的类型，而数组只能线性地包含同一个类型
    - 共用体的语法和结构体相似，但是，结构体的成员是“排列地”分配在内存中，而共用体的成员则是“重叠地”分配在内存中
    
12. 不完全类型
    - 不完全类型指 `函数之外、类型的大小不能被确定的类型`
    - C 的类型分类
        - 对象类型（char、int、数组、指针、结构体等）
        - 函数类型
        - 不完全类型（eg. 结构体标记的声明）
    - 因为不能确定大小，所以不能将不完全类型变成数组，也不能将其作为结构体的成员，或者声明为变量。但如果仅仅是用于取得指针，是可以使用不完全类型的
    - 在 C 标准中，void 类型也被归类为不完全类型
    
### 3.3 表达式
1. 表达式分为基本表达式和派生表达式
    - 基本表达式包括
        - 标识符
        - 常量
        - 字符串常量
        - 使用 () 括起来的表示式
    - 派生表达式
        - 对表达式使用运算符，或通过运算符将表达式和表达式相互连接，这些表示方法也称为表达式

2. 表达式可以表示为一棵 `二叉树`，这棵树的所有节点和子树也是表达式

3. 表达式的类型
    - 所有的表达式都持有类型
    - 在对表达式使用运算符，或者将表达式作为参数传递给函数的时候，表达式中持有的类型具有特别重要的意义

4. 表达式的值 (左值与右值)
    - 表达式代表某处的内存区域的时候，我们称当前的表达式为左值
    - 表达式只是代表值的时候，我们称当前的表达式为右值
    - 表达式中有时候存在左值，有时候不存在左值，要根据上下文判断
    
5. 将数组解读成指针
    - 规则：`在表达式中，数组被解读成指针，且该指针不能作为左值`
    - 上述规则有以下的例外情况：
        - 数组为 sizeof 运算符的操作数
        - 数组为 & 运算符的操作数 (返回指向整体数组的指针)
        - 初始化数组时的字符串常量
        
6. 数组和指针相关的运算符
    - 解引用 `*`
        - 运算符 * 将指针作为操作数，返回指针所指向的对象或者函数
        - 只要不是返回函数，运算符 * 的结果都是左值
    - 地址运算符 `&`
        - & 将一个左值作为操作数，返回指向该左值的指针
        - 地址运算符不能将非左值的表达式作为操作数
    - 下标运算符 `[]`
        - [] 将指针和整数作为操作数
        - p[i] 是 *(p + i) 的语法糖
    - 箭头运算符 `->`
        - 通过指针访问结构体的成员的时候，会使用 -> 运算符
        - p->hoge 是 (*p).hoge 的语法糖 
        
### 3.4 解读 C 的声明（续）
1. const 修饰符
    - const 是在 ANSI C 中追加的修饰符，它将类型修饰为 `只读`
    - const 修饰的标识符不是常量，它只是 `只读` 而已

2. const 主要被用于修饰函数的参数
    - 在现实中，当指针作为参数时，const 常用于 `将指针指向的对象设定为只读`
    - 若函数的形参是一个指针，且这个形参的目的仅仅是 `向函数传值` 而不是 `返回多个值`，其最佳实践就是在原型声明中加入 `const`
    - 尽管函数接受了作为参数的指针，但是指针指向的对象不会被修改，也就是说 `函数虽然接受了指针，但是并不意味着要向调用方返回值`

3. 解读 const 声明的规则
    - 遵从 3.1 中第 2 条提到的规则，从标识符开始，使用英语由内向外顺序地解释下去
    - 一旦解释完毕的部分的左侧出现了 const，就在当前位置追加 read-only
    - 如果解释完毕的部分的左侧出现了数据类型修饰符，并且其左侧存在 const，姑且先去掉数据类型修饰符，追加 read-only
    - eg. char * const src 可以解释成 `src is read-only pointer to char`; char const *src 可以解释成 `src is pointer to read-only char`
    - char const *src 等价于 const char *src
    
4. typedef
    - typedef 用于给某类型定义别名, eg. `typedef char *String;`, 以后对于 `指向 char 的指针` 可以使用 `String` 这个别名
    - 可以按照普通的变量声明的顺序来解释 `typedef`，eg. `typedef char *String` 可以解释成 `String is pointer to char`
    - typedef 属于 `存储类型修饰符`，因为其指定类型的语法沿用了通常声明标识符的语法规则
    - typedef 使用和通常的标识符声明相同的方式进行解释；可是，被声明的不是变量或者函数，而是类型的别名
    - typedef 也可以一次声明类型的多个别名
    
### 3.5 其他
1. 函数的形参的声明
    - 只有在声明函数形参的情况下，`int a[]` 和 `int *a` 才具有相同的意义, 数组形参会被自动解读成指针
        - `void func(int a[]);` 和 `void func(int *a);` 是完全等价的函数原型
        - `void func(int a[][5]);` 和 `void func(int (*a)[5]);` 是完全等价的函数原型
        
2. 关于空的下标运算符[], 在 C 语言中，遇到以下情况下标运算符 [] 可以将元素个数省略不写
    - 函数形参的声明
        - 对于函数的形参，最外层的数组会被解读成指针，即使定义了元素个数也会被无视
    - 根据初始化表达式可以确定数组大小的情况
        - 编译器可以根据初始化表达式来确定元素的个数，所以可以省略 `最外层数组` 的元素个数
        - eg.
            - double matrix[][2] = {{1,0}, {0,1}};
            - char *color_name[] = {"red", "green", "blue"};
            - char color_name[][6] = {"red", "green", "blue"};
    - 使用 extern 声明全局变量的情况
        - 全局变量在多个编译单元（.c 文件）中的某一个中定义，然后从其他代码文件通过 `extern` 进行声明
        - 在定义的时候还是需要元素个数的，但是在使用 extern 进行声明的时候，在连接的时候编译器可以确定实际的数组大小，所以可以省略最外层数组的元素个数
        
3. 字符串常量
    - 使用 `""` 包围起来的字符串被称为字符串常量
    - 字符串常量的 `类型` 是 `char数组`，因此 `在表达式中，字符串常量可以解读为指向char数组初始元素的指针`
        - eg. char *str; str="abc";
        - 例外：char 数组的初始化是个例外，此时的字符串常量，作为在花括号中分开书写的初始化表达式的省略形式，编译器会进行特殊处理
        - 几个例子
            ```
            // 以下两行等价
            char str[] = "abc";
            char str[] = {'a', 'b', 'c', '\0'};
            
            // ERROR
            char str[4]; // str is a array
            str = "abc"; // array not equal to pointer
            
            // OK
            char *str = "abc";
            
            // OK
            char *color_name[] = {
                "red",
                "green",
                "blue"
            };
            
            // OK
            char color_name[][6] = {
                "red",
                "green",
                "blue"
            };
            ```
            
4. 关于指向函数的指针引起的混乱
    - 对于 C 语言，`表达式中的函数可以被解读成指向函数的指针`
        - 表达式中的函数自动转换成 `指向函数的指针`. 但是，当函数是地址运算符 `&` 或者 `sizeof` 运算符的操作数时，表达式中的函数不能变换成 `指向函数的指针`
        - 函数调用运算符 `() ` 的操作数不是 `函数`，而是 `函数的指针`
    - 如果对 `指向函数的指针` 使用解引用 `*`，它暂时会成为函数，但是因为在表达式中，所以它会被瞬间地变回成 `指向函数的指针`
        - 结论：对 `指向函数的指针` 使用 `*` 运算符，等于对牛弹琴，无任何效果
        
5. 强制类型转换
    - cast 是将某类型强制地转换成其他类型的运算符, 形如 `(类型名称)`
    - 强制类型转换的两种使用方式
        - 基本类型的强制转换
        - 指针类型的强制转换
            - 在运行时，不同类型的指针对处理环境来说都只是地址，所谓的指针的强制类型转换，就是对指针进行强制读取转换
    - 不要使用强制类型转换来掩盖编译器的警告
    
### 3.6 数组和指针是不同的事物
1. C 语言的数组和指针是完全不同的类型
    - 数组是一些对象排列后形成的
    - 指针则表示指向某处
    
2. 表达式上下文中的数组和指针
    - 在表达式中，数组可以被解读成指向其初始元素的指针 (右值)

3. 声明上下文中的数组和指针
    - 声明函数形参
        - 只有在声明函数的形参的时候，数组的声明才能解读成指针的声明
        - 在不是声明函数的形参的时候，数组声明和指针的声明是不可能相等的
    - 使用 extern 声明的全局数组不能用指针替换
    - 声明局部变量或者结构体的成员时，写成 `int hoge[];` 会引起语法错误
    - 存在数组初始化表达式的情况下，可以使用空的`[]`，但这是因为编译器能够计算出数组元素的个数，所以可以省略书写元素个数. 仅此而已，这种特征和数组扯不上任何关系
    
## 4. 数组和指针的常用方法
### 4.1 基本的使用方法
1. 以函数返回值之外的方式来返回值
    - 如果将指针作为参数传递给函数，此后在函数内部对指针指向的对象填充内容，就可以从函数返回多个值
    - 如果需要通过函数返回值以外的方式返回值，将 `指向 T 的指针`（如果想要返回的值的类型为 T）作为参数传递给函数
    
2. 将数组作为函数的参数传递
    - 在 C 语言中，数组是不能作为参数进行传递的；但可以通过传递指向数组初始元素的指针，使得在函数内部操作数组成为可能
    - 在函数内部，可以通过 `array[i]` 的方式引用数组的内容，因为在本质上，array[i] 只不过是 *(array+i) 的语法糖
    - 想要将类型 T 的数组作为参数进行传递，可以考虑传递 `指向 T 的指针`；可是，作为被调用方是不知道数组的元素个数的，所以在必要的情况下，需要 `再传递一个参数表示数组的长度或者人为的使数组最后一个元素为 '\0'`
    
3. 可变长数组
    - 一般情况下，C 语言在 `编译时` 必须知道数组的元素个数
    - 但是也可以使用 `malloc()` 在 `运行时` 再为数组申请必要的内存区域 —— 这种数组，称为 `可变长数组`
    - 在需要获得类型 T 的可变长数组时，可以使用 `malloc()` 来动态地给 `指向 T 的指针` 分配内存区域；但此时需要程序员自己对数组的元素个数进行管理
    
### 4.2 组合使用
1. 可变长数组的数组
    - `类型T的可变长数组` 是通过 `指向T的指针` 来实现的, 但是元素个数需要自己来管理
2. 可变长数组的可变长数组
    - `T的可变长数组的可变长数组` 是通过 `指向T的指针的指针` 来实现的
3. 命令行参数
    - int main(void)
    - int main(int argc, char **argv)
4. 通过参数返回指针
    - 异常处理中使用 goto，反而可以让程序更加整洁
5. 将多维数组作为函数的参数传递
6. 纠结于“可变”之前，不妨考虑使用结构体
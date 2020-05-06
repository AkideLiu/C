# C Notes

[toc]



## I/O缓存

scanf() 是从标准输入设备（键盘）读取数据，带有行缓冲区的，这让 scanf() 具有了一些独特的“性格”，例如可以连续输入、可以输入多余的数据等。反过来，scanf() 也出现了一些奇怪的行为，例如，有时候两份数据之间有空格会读取失败，而有时候两份数据之间又必须有空格。

scanf() 的这些特性都是有章可循的，其根源就是行缓冲区。

当遇到 scanf() 函数时，程序会先检查输入缓冲区中是否有数据：

- 如果没有，就等待用户输入。用户从键盘输入的每个字符都会暂时保存到缓冲区，直到按下回车键，产生换行符`\n`，输入结束，scanf() 再从缓冲区中读取数据，赋值给变量。
- 如果有数据，那就看是否符合控制字符串的规则：
  - 如果能够匹配整个控制字符串，那最好了，直接从缓冲区中读取就可以了，就不用等待用户输入了。
  - 如果缓冲区中剩余的所有数据只能匹配前半部分控制字符串，那就等待用户输入剩下的数据。
  - 如果不符合，scanf() 还会尝试忽略一些空白符，例如空格、制表符、换行符等：
    - 如果这种尝试成功（可以忽略一些空白符），那么再重复以上的匹配过程。
    - 如果这种尝试失败（不能忽略空白符），那么只有一种结果，就是读取失败。


你看，scanf() 并不是直接让用户从键盘输入数据，而是先检查缓冲区，处理缓冲区中的数据。对于初学者来说，scanf() 检查缓冲区的规则也许有点复杂，下面我们通过几个典型的例子来“细嚼慢咽”。

#### 【实例1】scanf() 连续输入：

```C
#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    printf("a=%d, b=%d, c=%d\n", a, b, c);
    return 0;
}
```

运行结果：

```
100 200 300↙
a=100, b=200, c=300
```

程序执行到第一个 scanf()，由于缓冲区中没有数据，所以会等待用户输入。从键盘输入`100 200 300`后按下回车键，输入就结束了，scanf() 开始从缓冲区中读取数据。

第一个 scanf() 的控制字符串是`"%d"`，会匹配到第一个整数，也就是 100，于是将 100 赋值给变量 a，并将内部的位置标记移动到 100 以后，此时缓冲区中剩下` 200 300↙`。注意，换行符也是一个字符，也会进入缓冲区。

> 位置标记是什么？系统内部有一个专门用来记录 scanf() 读取到哪个位置的标记，随着 scanf() 的读取，该标记会向后移动，下一个 scanf() 就从这个新的位置开始读取。

第二个 scanf() 的控制字符串也是"%d"，需要读取一个整数，而此时缓冲区中的内容是`200 300↙`，开头是一个空格，并不是一个有效的数字，不符合控制字符串的规则。空格是一个空白符，此处是可以忽略的，于是 scanf() 忽略空格后再继续匹配，就得到了数字 200，终于匹配成功了。

到了第三个 scanf()，缓冲区中剩下`300↙`，同样会忽略开头的空格，匹配到数字 300。

最终，三个 scanf() 都匹配成功了，缓冲区中只留下了`↙`。嗯，那就留着吧，已经没用了，等程序运行结束了，会释放缓冲区内存，一切数据都灰飞烟灭了。

#### 【实例2】scanf() 读取失败：

```C
#include <stdio.h>
int main()
{
    int a, b=999;
    char str[30];
    printf("b=%d\n", b);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%s", str);
    printf("a=%d, b=%d, str=%s\n", a, b, str);
    return 0;
}
```

运行结果：

```
b=999
100 http://c.biancheng.net↙
a=100, b=999, str=http://c.biancheng.net
```

程序执行到第一个 scanf() 时等待用户输入，从键盘输入`100 http://c.biancheng.net`，按下回车键，scanf() 匹配到 100，赋值给变量a，同时将内部的位置指针移动到 100 后面。

到了第二个 scanf()，缓冲区中有数据，会直接读取。此时缓冲区中的内容为`http://c.biancheng.net↙`，即使忽略开头的空格也不是 scanf() 想要的整数，所以匹配失败了，不会给变量 b 赋值，b 的值保持不变，这就是两次输出变量 b 的值相同的原因。

匹配失败意味着不会移动内部的位置指针，此时缓冲区中的内容仍然是`http://c.biancheng.net↙`。执行到底三个 scanf() 时，它想要一个字符串，这不是正好捡漏吗，把`http://c.biancheng.net`赋值给 str 就好了。

> 注意，scanf()、gets() 在读取字符串时会忽略换行符，不会把换行符作为字符串的内容。

#### 【实例3】不能忽略空白符的情形：

```C
#include <stdio.h>
int main()
{
    int a = 1, b = 2;
    scanf("a=%d", &a);
    scanf("b=%d", &b);
    printf("a=%d, b=%d\n", a, b);
    return 0;
}
```

输入示例：

```
a=99↙
a=99, b=2
```

输入`a=99`，按下回车键，程序竟然运行结束了，只有第一个 scanf() 成功读取了数据，第二个 scanf() 仿佛没有执行一样，根本没有给用户任何机会去输入数据。这是为什么呢？

第一个 scanf() 执行完后，将 99 赋值给了 a，缓冲区中只剩下一个换行符`\n`；到了第二个 scanf()，发现缓冲区中有内容，但是又不符合控制字符串的格式，于是尝试忽略这个空白符。注意，这个时候的空白符是不能忽略的，所以就没有办法了，只能读取失败了。

实测发现，空白符在大部分情况下都可以忽略，前面的两个例子就是这样。但是当控制字符串不是以格式控制符 %d、%c、%f 等开头时，空白符就不能忽略了，它会参与匹配过程，如果匹配失败，就意味着 scanf() 读取失败了。

本例中，第二个 scanf() 的开头并不是格式控制符，而是写死的`b`字符，所以不会忽略换行符，而换行符和`b`又不匹配，怎么办呢？没办法，只能读取失败了。

如果我们换一种输入方式呢？

```
a=99 b=200↙
a=99, b=2
```

你看，第二个 scanf() 也读取失败了。执行到第二个 scanf() 时，缓冲区中剩下` b=200↙`，开头的空格依然不能忽略，然而又和控制字符串不匹配，所以只能读取失败了。

两种输入方式都不行，究竟该如何输入呢？很简单，不要让两份数据之间有空白符，只能像下面一样输入：

```
a=99b=200↙
a=99, b=200
```

这样 a 和 b 都能够正确读取了。注意，a=99b=200中间是没有任何空格的。

最后，我们再修改一下上面的代码，将第二个 scanf() 改成下面的样子：

```C
scanf("%d", &b);
```

运行结果：

```
a=100↙
200↙
a=100, b=200
```

此时，第二个 scanf() 的控制字符串以`%d`开头，就可以忽略换行符了。忽略换行符以后，缓冲区中就没有内容了，所以会等待用户输入。输入 200 以后，第二个 scanf() 就匹配成功了，将 200 赋值给变量 b。

那么，为什么只有当控制字符串以格式控制符开头时，才会忽略换行符呢？我也觉得这个特性很奇怪，目前还未想明白，也没有资料可查，请读者先记住这个结论。

## 刷新I/O

缓冲区的优点很明显，它加快了程序的运行速度，减少了硬件的读写次数，让整个计算机变得流畅起来；但是，缓冲区也带来了一些负面影响，经过前面几节的学习相信读者也见识到了。

那么，该如何消除这些负面影响呢？思路其实也很简单，在输入输出之前清空（刷新）缓冲区即可：

- 对于输出操作，清空缓冲区会使得缓冲区中的所有数据立即显示到屏幕上；很明显，这些数据没有地方存放了，只能输出了。
- 对于输入操作，清空缓冲区就是丢弃残留字符，让程序直接等待用户输入，避免引发奇怪的行为。

> 本节的代码用到了一些暂时没有学到的知识，估计很多初学者会不理解，没关系，那就先记住吧，记不住就复制吧，总之，按照葫芦画瓢就完了。

## 清空输出缓冲区

清空输出缓冲区很简单，使用下面的语句即可：

```c
fflush(stdout);
```

fflush() 是一个专门用来清空缓冲区的函数，stdout 是 standard output 的缩写，表示标准输出设备，也即显示器。整个语句的意思是，清空标准输出缓冲区，或者说清空显示器的缓冲区。

Windows 平台下的 printf()、puts()、putchar() 等输出函数都是不带缓冲区的，所以不用清空，下面的代码演示了如何在 Linux 和 Mac OS 平台下清空缓冲区：

```C
#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("C语言中文网");
    fflush(stdout);  //本次输出结束后立即清空缓冲区
    sleep(5);
    printf("http://c.biancheng.net\n");
   
    return 0;
}
```

程序运行后，第一个 pirntf() 立即输出，等待 5 秒以后，第二个 printf() 才输出，这就符合我们的惯性思维了。如果不加`fflush(stdout)`语句，程序运行后，第一个 printf() 并不会立即输出，而是等待 5 秒以后和第二个 scanf() 一起输出（已在《[C语言数据输出大汇总以及轻量进阶](http://c.biancheng.net/view/1793.html)》中进行了演示），这有点不符合我们的思维习惯。

## 清空输入缓冲区

首先，很遗憾地说，没有一种既简洁明了又适用于所有平台的清空输入缓冲区的方案。只有一种很蹩脚的方案能适用于所有平台，那就是将输入缓冲区中的数据都读取出来，但是却不使用。

大家不要以为我很轻松地就能说出这句话，我翻墙查阅了很多英文资料，又测试了很多平台和编译器才敢说的。

我们先说两种通用的方案，虽然它很蹩脚，但是却行之有效。

#### 1) 使用 getchar() 清空缓冲区

getchar() 是带有缓冲区的，每次从缓冲区中读取一个字符，包括空格、制表符、换行符等空白符，只要我们让 getchar() 不停地读取，直到读完缓冲区中的所有字符，就能达到清空缓冲区的效果。请看下面的代码：

```C
int c;
while((c = getchar()) != '\n' && c != EOF);
```

该代码不停地使用 getchar() 获取缓冲区中的字符，直到遇见换行符`\n`或者到达文件结尾才停止。由于大家所学知识不足，这段代码暂时无法理解，我也就不细说了，在实际开发中，大家按照下面的形式使用即可：

```C
#include <stdio.h>
int main()
{
    int a = 1, b = 2;
    char c;
    scanf("a=%d", &a);
    while((c = getchar()) != '\n' && c != EOF); //在下次读取前清空缓冲区
    scanf("b=%d", &b);
    printf("a=%d, b=%d\n", a, b);
   
    return 0;
}
```

输入示例：

```
a=100↙
b=200↙
a=100, b=200
```

按下第一个回车键后，只有第一个 scanf() 读取成功了，第二个 scanf() 并没有开始读取，等我们再次输入并按下回车键后，第二个 scanf() 才开始读取，这就符合我们的操作习惯了。如果没有清空缓冲区的语句，按下第一个回车键后，两个 scanf() 都读取了，只是第二个 scanf() 读取失败了，让人觉得很怪异，这点已在《[使用scanf从键盘输入数据](http://c.biancheng.net/view/1795.html)》中进行了演示。

改变输入方式，再次尝试一下：

```
a=100b=200↙
b=300↙
a=100, b=300
```

你看，第一次输入的多余内容并没有起作用，就是因为它们在第二个 scanf() 之前被清空了。

这种方案的关键之处在于，getchar() 是带有缓冲区的，并且一切字符通吃，或者说一切字符都会读取，不会忽略。不过这种方案有个缺点，就是要额外定义一个变量 c，对于有强迫症的读者来说可能有点难受。 

#### 2) 使用 scanf() 清空缓冲区

scanf() 还有一种高级用法，就是使用类似于正则表达式的通配符，这样它就可以读取所有的字符了，包括空格、换行符、制表符等空白符，不会再忽略它们了。并且，scanf() 还允许把读取到的数据直接丢弃，不用赋值给变量。

请看下面的语句：

```c
scanf("%*[^\n]"); scanf("%*c");
```

第一个 scanf() 将逐个读取缓冲区中`\n`之前的其它字符，% 后面的 * 表示将读取的这些字符丢弃，遇到`\n`字符时便停止读取。此时，缓冲区中尚有一个`\n`遗留，第二个 scanf() 再将这个`\n`读取并丢弃，这里的星号和第一个 scanf() 的星号作用相同。由于所有从键盘的输入都是以回车结束的，而回车会产生一个`\n`字符，所以将`\n`连同它之前的字符全部读取并丢弃之后，也就相当于清除了输入缓冲区。

相信很多读者都不明白这种写法，没关系，下节我们在讲解 [scanf() 的高级用法](http://c.biancheng.net/view/vip_1800.html)时还会再解释。

我们来演示这种方案的效果：

```C
#include <stdio.h>
int main()
{
    int a = 1, b = 2;
   
    scanf("a=%d", &a);
    scanf("%*[^\n]"); scanf("%*c"); //在下次读取前清空缓冲区
    scanf("b=%d", &b);
    printf("a=%d, b=%d\n", a, b);
   
    return 0;
}
```

输入示例 ①：

```
a=100↙
b=200↙
a=100, b=200
```

输入示例 ②：

```
a=100b=200↙
b=300↙
a=100, b=300
```

相比使用 getchar()，这种方案不用额外定义一个变量，看起来更加整洁。

## 两种不通用、不建议的方案

以上两种清空输入缓冲区的方案是通用的，在任何平台、任何编译器、任何情景下都奏效。除此以外，有些教材和老师可能还讲解过其它的方案，常见的有两种，分别是`fflush(stdin)`和`rewind(stdin)`。

#### 1) fflush(stdin)

fflush(stdin) 常用于 Windows 平台，在 VC 6.0、VS2010 等较老的编译器下确实能够清空缓冲区。

C语言标准规定，当 fflush() 用于 stdout 时，必须要有清空输出缓冲区的作用；但是C语言标准并没有规定 fflush() 用于 stdin 时的作用，编译器的实现者可以自由决定，所以它的行为是未定义的。

较老的微软编译器进行了扩展，赋予了 fflush(stdin) 清空输入缓冲区的功能，例如 VC 6.0、VS2010 等；但是，较新的微软编译器又取消了这种扩展，不再支持 fflush(stdin)，例如 VS2015、VS2017 等，在这些版本的编译器下，fflush() 是无效的。

较老的 GCC 是不支持 fflush(stdin) 的，但是最新的 GCC 又开始支持 fflush(stdin) 了。

LLVM/Clang 编译器始终不支持 fflush(stdin)。

总之，fflush(stdin) 这种不标准的写法只适用于一部分编译器，通用性非常差，所以不建议使用。如果你由于个人习惯坚持使用，请测试你的编译器是否支持。

#### 2) rewind(stdin)

rewind() 函数并没有清空缓冲区的功能，但是 rewind(stdin) 偏偏在某些编译器下会导致清空缓冲区的假象，例如 VS2015、LLVM/Clang。在 GCC 下，rewind(stdin) 是没有任何效果的。

## 总结

最靠谱、最通用、最有效的清空输入缓冲区的方案就是使用 getchar() 或者 scanf() 将缓冲区中的数据逐个读取出来，其它方案都有或多或少的问题。
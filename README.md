[TOC]

# C++面向对象

 面向对象的三大特征：**封装、继承、多态**
 万物皆对象

## 封装：

### 封装的意义1：将属性和行为进行统一

- 将对象的属性和行为作为一个整体，表现一个事物

- 将属性和行为加以权限的控制

    string类型的赋值操作，通过assign来实现，或者直接赋值：

```c++
string s1("hello world"), s2;
//s2 = s1;		这样也是可以的 
s2.assign(s1);
```



### 封装的意义2：设置访问权限

三种访问权限：

- public          类内可以访问，类外可以访问
- protected   类内可以访问，类外不能访问，子类可以访问
- private        类内可以访问，类外不能访问，子类不能访问

### struct和class的区别

C++中，两者的唯一区别：默认的访问权限不同

- struct默认权限为公共权限public
- class默认权限为私有权限 private

> 不论是属性还是方法，只要没有明确声明权限，默认情况下，在class中都是private的，类外无法访问。在struct中都是public的，在类外可以访问。



## 对象的清理和初始化

### 构造函数和析构函数

#### 构造函数的分类及调用

两种分类方式：

- 按参数分为，有参构造函数和无参构造函数
- 按类型分为，普通构造函数和**拷贝构造函数**

三种调用方式：

- 括号法：

    > ```c++
    > Stu stu("张三", 18, "男");   //普通构造函数
    > Stu stu2(stu);				//拷贝构造函数
    > ```

- 显式法：

    > ```c++
    > Person person = Person("张三", 18);	//普通构造函数
    > Person person1 = Person(person);	 //拷贝构造函数
    > ```

    > 像Person("张三", 18); 这种对象是**匿名对象**，系统在当前行结束后会立即回收
    >
    > **不要用拷贝构造初始化一个匿名对象**，这样，Person(p)  <==> Person p; 系统会忽略括号，当做重新定义了一个对象p

- 隐式转换法：**转换构造函数**

    > **将一种数据类型转为另一种数据类型**例如将float转为整形：int a = int(1.23)；而对于用户自定义的数据，系统不知道怎么转换 ，就需要定义专门的函数来告诉编译器。
    >
    > **当构造函数只有一个参数**，并且这个参数不是本类的const引用时，这种构造函数就称为转换构造函数
    >
    > ```c++
    > Person(string name) : Name(name) {}			//拷贝构造函数
    > ....
    > Person per = "张三";						   //转换构造函数
    > ```
    >
    > 



拷贝构造函数（复制构造函数）：

用于对象间的赋值  类名(类名 &p);			将p的所有属性复制到自身

> 话说为什么要用引用呢？只是复制，根本不会改变源对象的属性

另外，为了防止函数内部对源对象对的异常改变，可以给形参加上const关键字

#### 拷贝构造函数的使用

```c++
Stu (const Stu& stu)
{
	Name = stu.getName();
    ...
}
...
    
Stu stu1("张三", 18, "男");

Stu stu2(stu1);
Stu stu3 = stu1;
```

上述两种调用方式虽然形式不同，但是执行的操作完全相同

#### 拷贝构造函数的调用时机

拷贝构造函数在以下三种情况下会被调用：

- 用一个对象初始化另一个对象

    > ```c++
    > Person per1("张三", 18, "男");
    > Person per2(per1);
    > ```
    >
    > per2调用了拷贝构造函数

- 用值传递形式给函数参数传值

    > ```c++
    > bool cmp(Line l1, Line l2)
    > {
    >     return l1.getLen() > l2.getLen();
    > }
    > .....
    > Line line1((1, 2), (2, 3));
    > Line line2((5, 8), (2, 0));
    > if(cmp(line1, line2));
    > ...
    > ```
    >
    > 这里在调用cmp函数的时候，形参l1  l2会调用拷贝构造函数，将line1和line2的数据拷贝过来

- 以值的方式返回局部对象

    > ```c++
    > Point FindIntersection(Line l1, Line l2)//intersection: 交点
    > {
    >     Point intersection;
    > 	.....
    >     return intersection;
    > }
    > ...
    > Point intersection = FindIntersection(line1, line2);
    > ```
    >
    > 因为局部变量在函数FindIntersection结束后就会被系统释放，因此**编译系统会在主函数中创建一个无名的临时变量**，生存期只有函数调用所处的表达式intersection = FindIntersection(line1, line2)中，执行"return intersection"时，会调用**拷贝构造函数**将intersection**拷贝给临时对象**，当函数运行结束时，intersection对象消失，但临时对象会存在于表达式中。
    >
    > > 编译器有时会针对拷贝构造函数的调用做优化，避免不必要的拷贝构造函数调用

#### 深拷贝与浅拷贝

- 浅拷贝：简单的赋值拷贝操作（利用编译器提供的拷贝构造函数，就是浅拷贝）
- 深拷贝：在堆区重新申请内存，进行拷贝操作

浅拷贝带来问题：内存的重复释放

当一个类属性里面有指针，并且在构造函数中为指针申请了内存，在析构函数中释放了这块内存，那个当一个对象拷贝到另一个对象后，**只拷贝了指针**，没有另外申请内存，相当于两个对象的指针指向了同一块内存。当一个对象销毁后，要销毁另一个对象就会出问题，那片内存已经释放了，再次访问就是非法的，程序会崩溃。

> 普通的拷贝构造（或者是默认拷贝构造函数）只会复制所有的属性，一个指针属性也会只把指针复制过去，结果就是两个对象的指针属性都指向了同一块堆内存

**解决办法：**

自己写一个拷贝构造函数，并且另外申请一块堆区内存





### 析构函数

在栈区先进后出，后创建的对象先调用析构

```c++
void fun()
{
    Person p1("张三");
    Person p2(p1);
    ...
}
```

则会先调用p2的析构函数，然后调用p1的析构函数

### 类对象作为类成员

```c++
class A {};
class B
{
    A a;
};

B b;
```

A 和 B 的构造函数、析构函数的调用顺序是？

> A的构造函数
>
> B的构造函数
>
> B的析构函数
>
> A的析构函数

### 静态成员

在成员变量和成员函数前加上关键字static，称为静态成员

- 静态成员变量

    - 所有对象共享同一份数据
    - 在编译阶段分配内存
    - 类内声明，类外初始化

    ```c++
    class A
    {
    public:
        static int value;	//类内声明
        ...
    private:
        static int priva;
    };
    
    int A::value = 1;		//类外初始化
    int A::priva = 3;
    
    A a,  b;
    a.value = 5;
    b.value = 9;
    A::value = 10;
    std::cout << a.value << std::endl;
    //A::priva = 10;	//出错，priva是私有属性
    //a.priva = 10;		//出错，同上
    ```

    先由a修改为5，然后由b修改为9，最后通过类名修改为10

    **也是有权限的**，在private权限下，类外不可直接访问



- 静态成员函数

    - 所有对象共享同一个函数
    - 静态成员函数**只能**访问静态成员

    在函数名前加上static，注意只能访问静态成员变量，调用方式也有两种方式，同静态成员变量；也有访问权限

## 对象模型和this指针

### 成员变量和成员函数分开存储

成员变量和成员函数是分开存储的，所有的对象共用一个函数实例。

- 空类的大小：

    ```c++
    class A {};
    ...
    A a;
    std::cout << sizeof(a) << std::endl;
    ```

    输出结果是1

    本来一个空类型的实例，不包含任何东西，结果应该是0，但是**编译器为了区分空对象在内存的位置，会为每个对象分配一个字节的空间**

    > 在声明空类型的实例的时候，必须占用一定的内存才能使用这些实例。**至少占用对少内存，由编译器决定，在Visual Studio中，每个空类型的实例占用1个字节。**

- 对于非空类

    - 非静态成员变量，属于类的对象
    - 静态成员变量，不属于类的对象
    - 成员函数，包括构造、析构，不属于类的对象

    ```c++
    class Person
    {
    	int m_A;				//非静态成员变量，属于类的对象上
        static int m_B;			//静态成员变量，不属于类的对象上
        void func()	{}			//非静态成员函数，不属于类的对象上
        static void func2() {}	//静态成员函数，不属于类的对象上
    };
    int Person::m_B;
    ```

    即：**只有非静态成员变量属于类的对象**，其他的都不属于，在存储上其他的都不算做对象大小

### this指针

#### 概念

每一个非静态成员函数都只会诞生一份函数实例，那个多个同类型对象就会共用一块代码，这块代码是怎么区分那个对象调用自己的？——this指针

**this指针指向被调用的成员函数所属的对象**

- this指针是隐含每一个**非静态成员函数内**的一种指针
- this指针不需要定义，直接使用即可



#### this指针的用途：

- 当形参与成员变量同名时，可以用this指针来区分

    > 为了避免这种冲突，可以在成员变量前加上前缀 m_    m是member的意思
    >
    > 例如 int m_Age;   这样就可以跟普通形参  age 区分开了

- 在类的非静态成员函数中返回对象本身，可使用return *this

    ```c++
    class Person{
        ...
        Person& AddNum();
    };
    
    Person& Person::AddNum(Person p)
    {
        this->num += p.num;
        return *this;
    }
    ...
        
    Person p(10);
    Person p2(0);
    //链式编程思想
    p2.AddNum(p).AddNum(p).AddNum(p);
    ```

    这里函数类型是Person& 返回对象本身，如果是Person，则是另一个对象了，就不能链式的使用了。

#### 注意事项

空指针也可以调用成员函数，但是这是this指针为空，这个时候访问属性就会出错

```c++
class Person{
    void func() { std::cout << "hello world" << std::endl; }
  	void func2() { std::cout << name << std::endl; }
  	string name;  
};

Person *p = NULL;
p.func();
p.func2();					//错误，this指向空，原理相当于下面这句
cout << p->name << endl;	//当然是错的
```

在成员函数中访问属性name ， cout << name; 相当于 cout << this->name;  而空指针对象的this也是指向NULL的，这样this->name就出错了

> 加上一个判断语句，加强代码健壮性：
>
> ```c++
> if(this == NULL)
>     return;
> ```
>
> 

## const修饰成员

### 饰成员函数 : 常函数

- 成员函数后加上const后称这个函数为**常函数**
- 常函数内不可以修改成员属性
- 成员属性声明时加上关键字**mutable**后，在常函数中依然可以修改

this指针的本质：

```c++
class Person{
    ...
    void func();
};

void Person::func()
{
    cout << this->name << endl;
}
```

在这个类中，this的类型为:Person* const this;  这代表了this的指向不可以改变，但是this指向的值可以改变。那么要想this指向的值也不能改变，就应该定义为const Person* const this;

常函数的原理就是这个：类型  函数名()  const  {}

在大括号之前加上const，就代表这个成员函数中this指向的值不可以修改，即**这个成员函数中不能修改属性**，如果一定要修改，就要在属性定义前加上**mutable**关键字

```c++
class Person{
	void func(int c) const { a = c; }
    void func2(int c) const { b = c; }	//出错，常函数中不能改变普通属性
    
    int b;
    mutable int a;
};
```

### 什么时候用常函数（！！），为什么加上mutable

养成良好的代码吸管，**对于不改变对象状态**的成员函数，**都应该声明为常函数**

#### 什么是对象状态？

语言上讲，成员状态就是各个成员属性

但是，是否改变对象状态应该根据**这一对对象对外接口所反映的信息**来判断

- 不改变对象状态的函数**不一定**就不改变对象值

下面的例子：

```c++
class Line{
public:
    Line(const Point &p1, const Point &p2) : p1(p1), p2(p2), len(-1) {}
    doublt getLen();
private:
    Point p1, p2;
    double len;
};

double Line::getLen()
{
    if(len < 0)
    {
        double x = p1.getX() - p2.getX();
        double y = p1.getY() - p2.getY();
        len = sqrt(x * x + y * y);
    }
    return len;
}
```

一个线段类，里面有两个点对象作为线段的两个端点，还有一个线段长度的属性。注意到构造函数中将len初始化为 -1，而在getLen中计算了线段长度。这是因为有些情况下构造了线段对象后不需要获取线段长度，也就不需要计算（耗时），因此特意加上一个getLen函数来在必要情况下获取长度，并且加上一个len属性来暂存这个值，这样做的好处是下一次获取长度就不需要再次计算了。

这里的getLen函数并**没有改变对象状态**，只是在第一次调用时计算并改变了len的值，在后面的调用中只是返回了len，所以应该设置成常函数，但是常函数不能修改属性的值，所以要在属性len声明的时候加上mutable关键字

### 修饰成员属性

在属性前面加上const就成了常数据成员，**在任何函数中都不能对该成员赋值**，因此需要对其初始化。在构造函数中，只能通过初始化列表获取初始值，进行初始化。

```c++
class Person{
    Person(int m) : a(m) {}
    
    const int a;
    static const int b;
    //或者是
    //static const int b = 10;
};
const int Person::b = 10;
```

### 修饰对象：常对象

- 声明对象前加上const称为常对象
- 常对象只能调用常函数

### 修饰引用：常引用(!!!!!)

在声明引用时加上const，就变成了一个常引用，**常引用所引用的对象不能被更新**

***非const引用只能绑定到普通的对象上，而不能绑定到常对象；但常引用可以绑定到常对象***

> 对于在函数中无需改变其值的参数，不宜使用普通的引用方式传递，那样会使得常对象无法被传入，采用传值的方式或常引用的方式可以避免这一问题。对于大对象来说，传值耗时较多，因此传递常引用为宜。复制构造函数的参数一般也宜采用常引用传递。

**为什么加常引用？**

对于int &a = 5;这句代码，一定会报错，普通的引用时将变量起一个别名，而这句中5会临时储存，这句执行完就会被销毁，所以这样起一个别名a肯定会出错。同样的，**对于一个临时对象，如果作为形参传进一个函数中，要么用值传递，要么就得用常引用传递**



## 友元

友元关系提供了不同类或对象的成员函数之间、类的成员函数与一般函数之间进行数据共享的机制。

简单来说就是通过友元关系，可以在普通函数与类之间建立特殊关系，使得普通函数可以直接访问类的私有属性，同样，这个类与另一个类之间也可以建立友元关系，使得可以访问私有属性：

### 全局函数做友元

```c++
class A{
    friend void setVal(A *a, int m);
public:
    A(int a) : m_a(a) {}
private:
    int m_a;
};

void setVal(A *a, int m)
{
    a->m_a = m;
}
```

通过加上friend关键字，就可以声明一个友元关系，来让函数setVal(...)访问类A的私有属性



### 类做友元

```c++
class A{
public:
    void display() { cout << X << endl; }
    int getX() { return X; }
private:
    int X;
};

class B{
public:
    void setX(int i);
private:
    A a;
}
void B::setX(int i)
{
    a.X = i;
}
```

这里setX肯定是不行的，因为函数中访问了A的私有属性 X ，而要实现这种功能，需要在A中声明类B为A的一个友元类，在A中添加

```c++
friend class B;
```

声明之后，在B类中所有的成员函数都可以访问A的私有属性了 

### 成员函数做友元

如果只是想要某一个成员函数作为友元函数，就不可以将整个类作为另一类的友元，只需要在函数前加上friend关键字，并且加上这个成员函数所属的类名作为限定就可以了

**但是会出现一些问题**

```c++
class A;
class B{
public:
    void func() { a.x = 10; }
    A a;
};

class A{
    friend void B::func();	//声明类B的成员函数func()为类A的一个友元
private:
    int x;
}
```

看起来这么写是没有问题的，然而编译后报错：line 4, 使用了未定义的类型"A"

原因是B中的func()函数中使用了对象 a ，然而此时类A只有一个前行引用声明，对于A的实际大小并不确定，所以就会出错，解决方案是将函数func()的实现放在类A的实现后面



## 运算符重载

将operator(符号作为函数名)，可以有成员函数重载和全局函数重载

**对于双目运算符B**，要重载以实现operd1  B  operd2这种表达式，operd1为A类的对象，则应当将B重载为A的成员函数，该函数只有一个形参，类型是operd2所属的类型，重载后，operd1 B operd2就相当于函数调用operd1.operatorB(operd2)

**对于前置单目运算符U**，如“-”（负号），则要实现U operd，应当将U重载为operd所属类A的成员函数，没有形参，U operd相当于函数调用operd.operatorU()；

**对于后置运算符“++”和"--"**，要实现operd ++或 operd --，运算符应当重载为operd所属类A的成员函数，这时函数应该带有一个整形int形参，重载后，表达式operd++或operd--就相当于函数调用operd.operator++(0)和operd.operator--(0)，**这里int形参不起任何作用，仅仅用于区别前置++、--和后置++、--**

### 加号重载：

```c++
class Complex {
	friend Complex operator+(Complex& c1, int m);

public:
	Complex() : m_Real(0), m_Imag(0) {}
	Complex(int real, int imag) : m_Real(real), m_Imag(imag) {}
	Complex operator+(Complex &comp);
	//显示，这个show函数是成员函数，因此可以访问这个类的私有属性
	void Show() const { dcout << m_Real << " + " << m_Imag << "i" << endl; }
private:
	int m_Real;	//实部
	int m_Imag;	//虚部
};
Complex Complex::operator+(Complex &comp)
{
	Complex temp;
	temp.m_Real = this->m_Real + comp.m_Real;
	temp.m_Imag = this->m_Imag + comp.m_Imag;
	return temp;
}

Complex operator+(Complex& c1, int m)
{
	Complex temp;
	temp.m_Real = c1.m_Real + m;
	temp.m_Imag = c1.m_Imag;
	return temp;
}

int main()
{
	Complex a(2, 4), b(1, 5);
	a.Show();
	(a + b).Show();
	(a + 5).Show();
	//a.operator+(b).Show();
	return 0;
}
```

> 使用引用可以避免拷贝一个新对象，减少内存使用，减少运行时间

上段代码对加号进行了重载，分别使用了成员函数重载和全局函数重载，并且这个加号运算符重载又进行了重载，使得形参有两个版本：(Complex,  Complex)  和  ( Complex,  int  )

### 左移符号(<<)重载

使用普通的cout << "helloworld" ;只能输出基本数据类型

```c++
class Person
{
...
private:
    string name;
    string sex;
    int age;
};
```

如果想要同时输出Person类某个对象的姓名、性别、年龄，需要使用cout << p.name << p.sex << p.age;

这样很麻烦，通过左移符号重载，可以定义重载函数直接 cout << p ，但是这个重载函数有些地方要注意：

**不能是成员函数，只能定义为全局函数**

因为如果是成员函数，就需要由一个对象来调用这个函数，这样，这个对象作为调用者，cout 则会作为参数，最后调用的语法就成了 Person p.operator<<(cout); 或者  p << cout 跟原来的正好反过来了。

```c++
class Person{
    //cout 类型是 std::ostream，而全局只有cout一个变量，所以需要用引用的方式作为形参
    void operator<< (ostream &cout);
};
Person p;
p.operator<<(cout);
p << cout;			
```

需要将<<的重载定义为全局函数：

```c++
void operator<<(ostream &out, Person p)
{
    out << p.name << p.sex << p.age;
}
cout << p;	//这样就是对的了
```

而想要在调用时这样写：
cout << p << "hello world" << endl; 这就是上面写的链式编程思想了，就需要函数operator<<()返回一个cout：

```c++
std::ostream& operator<<(std::ostream &out, Person p)
{
    out << p.name << p.sex << p.age;
    return out;
}
```

相当于 cout << p之后继续返回了一个cout，然后执行cout << "hello world".....

> 这里函数返回类型是std::ostream& 而不是 std::ostream是因为函数形参out本身就是一个std::ostream&类型，返回的out就得是引用类型。而为什么形参是引用？因为cout 在全局只有一个变量，需要用引用的方式传入函数内，否则就会出现另一个std::ostream的对象引发冲突

### 函数调用符号重载

- 函数调用符号（）也可以重载
- 重载后的使用方式很像函数的调用，因此成为仿函数
- 仿函数没有固定的语法，非常灵活

```c++
class MyPrint
{
public:
    void operator()(string str) { cout << str << endl; }
};
```

```C++
class MyAdd
{
public:
    int operator()(int a, int b) { return a + b; }
};

MyAdd add;
std::cout << add(10, 20) << std::endl;
```

或者使用匿名对象调用：

```c++
class MyAdd
{
public:
    int operator()(int a, int b) { return a + b; }
};

std::cout << MyAdd()(10, 20) << std::endl;
```

使用了默认构造函数创建了一个匿名对象，调用函数调用符号的重载函数







## 继承

继承的好处：减少重复代码

语法： class 子类 ： 继承方式  父类

子类也称作**派生类**

父类也称作**基类**

### 继承方式

- 公共继承
- 保护继承
- 私有继承

```c++
class Base {
public:
	int a;
protected:
	int b;
private :
	int c;
};

class Pub : public Base {
public:
	void func4() { a = 10; b = 10; c = 10; }	//c不可访问
};

class Pro : protected Base {
public:
	void func5() { a = 10; b = 10; c = 10; }	//c不可访问
};

class Pri : private Base {
public:
	void func6() { a = 10; b = 10; c = 10; }	//c不可访问
};
```

对于基类Base中的private属性，其子类（派生类）均不可访问（继承了但是不能访问）

公共继承的子类Pub，基类中的public属性，在子类Pub中依旧是public的，基类中的protected属性在子类中也依旧是protected的

保护继承的子类Pro，基类中的public、protected属性在子类中都变成了protected的了

私有继承的之类Pri ，基类中的public、protected属性在子类中都变成了private的了

![bandicam 2021-09-03 14-13-46-265](D:\Users\ZZZ\Desktop\bandicam 2021-09-03 14-13-46-265.jpg)



### 继承中的对象模型

**问题：**从父类继承过来的成员，哪些属于子类对象中？

```c++
class Base {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class A : public Base {
public:
	int m_D;
};

void test01()
{
	A a;
	std::cout << sizeof(a) << std::endl;
}
```

sizeof打印结果是多少？

结果是16，说明了子类继承父类，不仅把public、protected的属性继承过来了，而且把不可访问的private属性也继承过来了

> 利用开始菜单中的Visual Studio的开发人员命令工具可以查看类的内存布局，首先转到.cpp文件所在目录，然后输入下面的命令：
>
> ```
> cl /d1 reportSingleClassLayoutName "Name.cpp"
> ```
>
> 前面cl是英文字母l，后面d1是数字1
>
> 作用是报告单个类的布局，类名为Name，所在文件为Name.cpp





 ### 继承中的构造和析构函数的调用顺序

逻辑上看，先有父类，才有子类，应该是先父类的构造，然后子类的构造；先子类的析构，再父类的析构

![image-20210903151839005](C:\Users\ZZZ\AppData\Roaming\Typora\typora-user-images\image-20210903151839005.png)





### 继承中同名成员处理方式

如果子类中的成员跟父类中的成员同名，则子类对象默认访问的是子类成员

```c++
class Base {
public:
	Base(): m_A(200) {}
	int m_A;
};

class A : public Base {
public:
	A() : m_A(100) {}
	int m_A;
};

void test01()
{
	A a;
	std::cout << a.m_A << std::endl;
	std::cout << a.Base::m_A << std::endl;;
	std::cout << "---------------" << std::endl;
}
```

默认a.m_A访问的是子类A的成员，如果要访问父类的成员，就要加上父类的作用域Base::

对于成员函数，也是同样的，但是如果在父类中有一个重载，子类中没有这个重载，如果直接调用这个重载就会报错

```c++
class Base{
public:
    void func() { std::cout << "func in Base" << std::endl; }
    void func(int a) { std::cout << "func(int a) in Base" << std::endl; }
};

class A : public Base{
public:
    void func() { std::cout << "func in A " << std::endl; }
};
....
A a;
a.func(10);	//	会报错
```

因为子类存在func的情况下使用'.'符号就默认使用了子类中的函数，而子类没有这种重载，就会报错，解决办法需要加上Base的作用于：a.Base::func(10);

> 如果子类中出现了和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有的同名成员函数



### 多继承语法

class 类名 ：继承方式 类1，继承方式 类2，继承方式 类3.....

### 菱形继承（！！！）

菱形继承概念：

​	两个派生类继承同一个类

​	又有某个类同事继承两个派生类

这种继承称为菱形继承

```c++
class Base {
public:
	int m_Age;
};

class Son1 : public Base {
public:
	int m_A;
};

class Son2 : public Base {
public:
	int m_A;
};

class GrandSon : public Son1, public Son2 {
public:
	int m_A;
};

```



![image-20210903164420349](C:\Users\ZZZ\AppData\Roaming\Typora\typora-user-images\image-20210903164420349.png)

就会出现一个问题，这里GrandSon类同时继承了Son1和Son2类，而Son1和Son2类分别够继承了Base类，Base类中有个m_Age属性，不管是Son1、Son2、GrandSon，这个属性只需要一个就好了，但是在GrandSon中，这个属性出现了两次，浪费内存。

解决办法是**虚继承**，在继承前加上vertual关键字，就变成了虚继承

```c++
class Base {
public:
	int m_Age;
};

class Son1 : vertual public Base {
public:
	int m_A;
};

class Son2 : vertual public Base {
public:
	int m_A;
};

class GrandSon : public Son1, public Son2 {
public:
	int m_A;
};
```

#### 虚继承的内存分布（！！！）

使用虚继承后的内存分布如下：

![image-20210903181335333](C:\Users\ZZZ\AppData\Roaming\Typora\typora-user-images\image-20210903181335333.png)

其中原本的Son1的Base类处的m_Age处现在是一个vbprt，这是virtual base pointer，虚基类指针，它指向了vbtable，虚基类表，也就是后面GrandSon::$vbtable@Son1@:这一行，这个表中记录了一个偏移量20（相对于GrandSon  Son1的基地址），也就是地址为20的m_Age。

同样的，Son2的Base处的m_Age也是一个虚基类指针，指向了GrandSon::$vbtable@Son2@这里，里面也是一个偏移量，相对于GrandSon的Son2的基地址，偏移量为12，即地址为12+8=20处的m_Age。因此这个类GrandSon中只有一个m_Age了。

而sizeof(GrandSon)由原来的20变为了24，是因为虽然m_Age由两个变成了一个，但是新增加了两个虚基类指针，又增加了8字节，因此一共就是24字节的空间了。

> 现在在GrandSon中只有一个m_Age了，对于GrandSon g，不管是g.Son1::m_Age还是g.Son2::m_Age，或者是g.m_Age,都是同一个值，相当于多个指针指向了同一变量







## 类型兼容规则

类型兼容规则是指在需要基类对象的任何地方，都可以使用**公有**派生类的对象来替代

如果子类是保护继承或是私有继承，那个原本父类中的公有属性，在子类中就都成了protected的或是private的属性了，在类外原本可以访问的一些属性，在子类中也访问不到了，因此就不能代替父类了。

> 通过公有继承，派生类得到了基类中出构造函数、析构函数之外的所有成员。这样，公有派生类实际就具备了基类的所有功能，凡是基类能解决的问题，公有派生类都可以解决。所替代的对象包括以下情况：
>
> - 派生类的对象可以隐含转换为基类对象
>
>     ```c++
>     class Base{};
>     class Son : public Base{};
>     ...
>     Son son;
>     Base p = son;
>     ```
>
> - 派生类的对象可以初始化基类的引用
>
>     ```c++
>     class Base{};
>     class Son : public Base{};
>     ...
>     Son son;
>     Base& p = son;
>     ```
>
> - 派生类的指针可以隐含转换为基类的指针
>
>     ```c++
>     class Base{};
>     class Son : public Base{};
>     ...
>     Son son;
>     Son* p = &son;
>     Base* p2 = p;
>     ```





## 多态

多态分为两类：

- 静态多态：函数重载   运算符重载属于静态多台，复用函数名
- 动态多态：派生类和虚函数实现**运行时**多态

区别：

- 静态多台的函数地址早绑定 —— 编译阶段确定函数地址
- 动态多态的函数地址晚绑定 —— 运行阶段确定函数地址

```c++
class Animal {
public:
    void Speak() { std::cout << "Animal is speaking " << std::endl; }
};

class Cat : public Animal {
public:
    void Speak() { std::cout << "Cat is speaking " << std::endl; }
};

void doSpeak(Animal& animal)
{
    animal.Speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);
}
```

调用doSpeak(cat)最后打印出来的是 “animal is speaking" 而不是猫在说话，这时因为在doSpeak函数中的调用animal.Speak()，其中Speak()函数的地址早绑定了，在编译阶段就确定了函数的地址，指向了第3行代码出的地址，因此最后会打印出动物在说话。

解决办法就是让Speak()函数晚绑定，在运行阶段再绑定函数地址，方法就是在基类的Speak()函数定义前加上virtual关键字，使其变成一个虚函数。

### 多态的条件

- 首先需要有继承关系
- 子类对父类的虚函数进行了重写
- 满足赋值兼容规则

> 重写：函数返回值类型、函数名、参数列表完全一致



### 多态的使用

**父类的指针或引用，指向子类对象**

如果doSpeak函数是值传递形式，就不能进行晚绑定，这样不管基类中的Speak函数是不是定义为虚函数，都不能进行晚绑定。

```c++
void doSpeak(Animal animal)
{
    animal.Speak();
}
```

如果函数是引用方式，或者是一个基类类型的指针，就可以进行晚绑定，实现多态



### 多态的底层（virtual对sizeof结果的影响）

```c++
class Animal {
public:
    void Speak() { std::cout << "Animal is speaking " << std::endl; }
};

std::cout << sizeof(Animal) << std::endl;
```

```c++
class Animal {
public:
    virtual void Speak() { std::cout << "Animal is speaking " << std::endl; }
};

std::cout << sizeof(Animal) << std::endl;
```

上面的结果分别是1 4第一个相当于一个空类，大小为1，第二个则是因为存在一个**虚函数指针**

> 只会有一个vfptr，多个虚函数将会在vftable中体现，但是vfptr只有一个，因此尽管有多个虚函数，但是在计算大小时只按照一个指针的大小计算
>
> ```c++
> class Animal {
> public:
>     virtual void Speak() { std::cout << "Animal is speaking " << std::endl; }
>     virtual void Speak2() { std::cout << "Animal is speaking " << std::endl; }
>     virtual void Speak3() { std::cout << "Animal is speaking " << std::endl; }
> };
> 
> std::cout << sizeof(Animal) << std::endl;
> ```
>
> 这个例子，尽管定义了三个虚函数，但是最后sizeof结果还是4，因为只存在一个vfptr，在vftable中才会有多一个的函数地址

声明时加上了virtual关键字，就会在类中添加一个vfprt（虚函数指针），指向了一个vftable（虚函数表），这个表中记录了这个函数体的位置，在在基类中，就是&Animal::Speak

如果是派生类：

```c++
class Animal {
public:
    int a;
    virtual void Speak() { std::cout << "Animal is speaking " << std::endl; }
};

class Cat : public Animal {
public:
    void Speak() { std::cout << "Cat is speaking " << std::endl; }
};

void doSpeak(Animal& animal)
{
    animal.Speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);
    std::cout << "类Animal的大小：" << sizeof(Animal) << std::endl;
}
```

![image-20210904111146526](C:\Users\ZZZ\AppData\Roaming\Typora\typora-user-images\image-20210904111146526.png)

![image-20210904111223422](C:\Users\ZZZ\AppData\Roaming\Typora\typora-user-images\image-20210904111223422.png)

Cat类继承了Animal类，也有一个vfptr，但是其指向的vftable却跟基类Animal中的不一样，函数体变了，在基类中函数体地址是&Animal::Speal，在Cat中，函数体地址为&Cat::Speak，这就是

vftable中地址的不同是因为派生类中对函数重写的结果，如果没有进行重写，那个在Cat类的vftable中函数地址将还是&Animal::Speak



### 多态案例 —— 计算器类

分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类

....

写代码时，提倡 开闭原则：对扩展进行开放，对修改进行关闭。这样组织结构清晰，可读性强，便于前期和后期的维护

```c++
class AbstractCalculator    //计算器的抽象类
{
public:
    AbstractCalculator(int a, int b) : m_Num1(a), m_Num2(b) { }
    virtual int getResult() { return 0; }
    int m_Num1;
    int m_Num2;
};

//加法：
class AddCalculator : public AbstractCalculator
{
public:
    AddCalculator(int a, int b) : AbstractCalculator(a, b) { }
    int getResult() { return m_Num1 + m_Num2; }
};

//减法：
class SubCalculator : public AbstractCalculator
{
public:
    SubCalculator(int a, int b) :AbstractCalculator(a, b) {}
    int getResult() { return m_Num1 - m_Num2; }
};


void test01()
{
    AbstractCalculator* ptr = new AddCalculator(10, 20);
    std::cout << ptr->getResult() << std::endl;
    delete ptr;

    ptr = new SubCalculator(12, 20);
    std::cout << ptr->getResult() << std::endl;
    delete ptr;
}
```

将计算器进行抽象，定义一个抽象类，主要的共性是两个操作数，作为抽象类的属性，使用这个抽象类来派生出各种的计算操作：加减乘除等。这样做的好处是便于维护，便于扩展，如果想增加一个计算功能，只需要再写一个派生类，不用对基类进行任何的修改，减少了出错的可能。
















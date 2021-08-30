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



属性、行为统称为成员	

属性：成员属性.....

行为：成员方法.....



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

#### 饰成员函数 : 常函数

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

#### 修饰成员属性

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

#### 修饰对象：常对象

- 声明对象前加上const称为常对象
- 常对象只能调用常函数

## 友元

友元关系提供了不同类或对象的成员函数之间、类的成员函数与一般函数之间进行数据共享的机制。

简单来说就是通过友元关系，可以在普通函数与类之间建立特殊关系，使得普通函数可以直接访问类的私有属性，同样，这个类与另一个类之间也可以建立友元关系，使得可以访问私有属性：

#### 全局函数做友元

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



#### 类做友元

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

#### 成员函数做友元

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





























 

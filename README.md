[TOC]

# C++面向对象

 面向对象的三大特征：**封装、继承、多态**
 万物皆对象

## 封装：

### 封装的意义1：将属性和行为进行统一

- 将对象的属性和行为作为一个整体，表现一个事物

- 将属性和行为加以权限的控制

    string类型的赋值操作，通过assign来实现，或者直接赋值：

```c
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


//#include <iostream>
//
//class Animal {
//public:
//    int a;
//    virtual void Speak() { std::cout << "Animal is speaking " << std::endl; }
//    virtual void Shower() { std::cout << "Animal is Showering " << std::endl; }
//};
//
//class Cat : public Animal {
//public:
//    void Speak() { std::cout << "Cat is speaking " << std::endl; }
//    //void Shower() { std::cout << "Cat is showering " << std::endl; }
//};
//
//void doSpeak(Animal& animal)
//{
//    animal.Speak();
//}
//
//void test01()
//{
//    Cat cat;
//    doSpeak(cat);
//    std::cout << "类Animal的大小：" << sizeof(Animal) << std::endl;
//}
//
//int main()
//{
//    test01();
//    return 0;
//}
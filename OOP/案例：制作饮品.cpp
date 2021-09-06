//#include <iostream>
//
//// boil   煮水
//// crew   冲泡 
//// pour in cup  倒入杯中
//
//class AbstractDrinking
//{
//public:
//    //有四个步骤：煮水 - 冲泡 - 倒入杯中 - 加入辅料
//    void Water() { std::cout << "将水加热至沸腾" << std::endl; }
//    virtual void Crew() = 0;
//    void PourInCup() { std::cout << "将冲泡后的水倒入杯中 " << std::endl; }
//    virtual void AddOther() = 0;
//    void MakeDrink() {
//        Water();
//        Crew();
//        PourInCup();
//        AddOther();
//    }
//};
//
//class Tea : public AbstractDrinking
//{
//public:
//    void Crew() { std::cout << "冲泡茶叶" << std::endl; }
//    void AddOther() { std::cout << "加入准备好的柠檬" << std::endl; }
//};
//
//class Coffee : public AbstractDrinking
//{
//public:
//    void Crew() { std::cout << "冲泡咖啡" << std::endl; }
//    void AddOther() { std::cout << "加入糖和牛奶" << std::endl; }
//};
//
//void DoWork(AbstractDrinking* abs)
//{
//    if (abs != NULL)
//        abs->MakeDrink();
//    delete abs;
//    abs = NULL;
//}
//
//void DoWork(AbstractDrinking& abs)
//{
//    abs.MakeDrink();
//}
//
//void test01()
//{
//    Tea tea;
//    Coffee coffee;
//    DoWork(tea);
//    DoWork(coffee);
//}
//
//int main()
//{
//    test01();
//    return 0;
//}
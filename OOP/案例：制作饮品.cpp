//#include <iostream>
//
//// boil   ��ˮ
//// crew   ���� 
//// pour in cup  ���뱭��
//
//class AbstractDrinking
//{
//public:
//    //���ĸ����裺��ˮ - ���� - ���뱭�� - ���븨��
//    void Water() { std::cout << "��ˮ����������" << std::endl; }
//    virtual void Crew() = 0;
//    void PourInCup() { std::cout << "�����ݺ��ˮ���뱭�� " << std::endl; }
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
//    void Crew() { std::cout << "���ݲ�Ҷ" << std::endl; }
//    void AddOther() { std::cout << "����׼���õ�����" << std::endl; }
//};
//
//class Coffee : public AbstractDrinking
//{
//public:
//    void Crew() { std::cout << "���ݿ���" << std::endl; }
//    void AddOther() { std::cout << "�����Ǻ�ţ��" << std::endl; }
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
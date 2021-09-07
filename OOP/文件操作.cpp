#include <iostream>
#include <fstream>
#include <string>

const char* PATH = "..\\file\\test.txt";
const char* PATH2 = "..\\file\\test2.txt";

class Person {
public:
    Person() 
    {
        memset(m_Name, 0, sizeof(m_Name)); 
        m_Age = 0;
    }
    Person(const char* str, int age) : m_Age(age) 
    { 
        strcpy_s(m_Name, str);
    }
    void Show() 
    {
        std::cout << m_Name << "������Ϊ" << m_Age << std::endl; 
    }
private:
    char m_Name[20];
    int m_Age;
};

void test01()       //����д�ļ�
{
    //std::ifstream ifs;      //�����ļ�������   ��ȡ�ļ�
    std::ofstream ofs;
    ofs.open(PATH, std::ios::out | std::ios::ate);
    if (!ofs.is_open())
    {
        std::cout << "failed to open <" << PATH << ">" << std::endl;
        return;
    }

    const char* buf = "�������";
    ofs.write(buf, strlen(buf));

    ofs.close();
}

void test02()
{
    std::ifstream ifs;  //��ȡ�ļ�
    ifs.open(PATH, std::ios::in);
    
    //��һ�ַ�ʽ
    //std::string text;
    //while(ifs >> text)
    //{
    //    std::cout << text << std::endl;
    //}

    //�ڶ��ַ�ʽ��ʹ�� getline����
    //char text[1024] = { 0 };
    //while (ifs.getline(text, sizeof(text)))
    //{
    //    std::cout << text << std::endl;
    //}
    
    //�����ַ�ʽ��ʹ��ȫ�� getline
    //std::string text;
    //while (std::getline(ifs, text))
    //{
    //    std::cout << text << std::endl;
    //}

    

    //�����ַ�ʽ ʹ�� get������һ���ַ�һ���ַ��Ķ�
    char c;
    while ((c = ifs.get()) != EOF)
    {
        std::cout << c;     //���ַ�ʽ�Ͳ��ܼӻ����ˣ���Ϊ�����ַ�\nҲ���������ˣ����Զ�����
    }


    ifs.close();
}

void test03()   //�������ļ���д
{
    std::fstream file(PATH2, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
    if (!file.is_open())
    {
        std::cout << "failed to open < " << PATH2 << " >" << std::endl;
        return;
    }

    Person p("����", 10);  
    Person p2; 
    p.Show();

    //д
    file.write((const char*)&p, sizeof(Person));

    file.seekg(0, std::ios::beg);
    //��
    file.read((char*)&p2, sizeof(Person));
    p2.Show();
    std::streampos here = file.tellg();
    std::cout << here << std::endl;
    file.close();
}

int main()
{
    //test01();
    //test02();
    test03();
    return 0;
}
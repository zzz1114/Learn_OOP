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
        std::cout << m_Name << "的年龄为" << m_Age << std::endl; 
    }
private:
    char m_Name[20];
    int m_Age;
};

void test01()       //测试写文件
{
    //std::ifstream ifs;      //创建文件流对象   读取文件
    std::ofstream ofs;
    ofs.open(PATH, std::ios::out | std::ios::ate);
    if (!ofs.is_open())
    {
        std::cout << "failed to open <" << PATH << ">" << std::endl;
        return;
    }

    const char* buf = "你好世界";
    ofs.write(buf, strlen(buf));

    ofs.close();
}

void test02()
{
    std::ifstream ifs;  //读取文件
    ifs.open(PATH, std::ios::in);
    
    //第一种方式
    //std::string text;
    //while(ifs >> text)
    //{
    //    std::cout << text << std::endl;
    //}

    //第二种方式，使用 getline函数
    //char text[1024] = { 0 };
    //while (ifs.getline(text, sizeof(text)))
    //{
    //    std::cout << text << std::endl;
    //}
    
    //第三种方式，使用全局 getline
    //std::string text;
    //while (std::getline(ifs, text))
    //{
    //    std::cout << text << std::endl;
    //}

    

    //第四种方式 使用 get函数，一个字符一个字符的读
    char c;
    while ((c = ifs.get()) != EOF)
    {
        std::cout << c;     //这种方式就不能加换行了，因为换行字符\n也被读进来了，会自动换行
    }


    ifs.close();
}

void test03()   //二进制文件读写
{
    std::fstream file(PATH2, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
    if (!file.is_open())
    {
        std::cout << "failed to open < " << PATH2 << " >" << std::endl;
        return;
    }

    Person p("张三", 10);  
    Person p2; 
    p.Show();

    //写
    file.write((const char*)&p, sizeof(Person));

    file.seekg(0, std::ios::beg);
    //读
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
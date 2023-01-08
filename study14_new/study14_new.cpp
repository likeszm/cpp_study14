/*
* 名称: 重载测试
*
* 收获:
* 1、如果没有声明print(char)会自动把参数'6'用ascii转成int类型调用print(int)
* 2、运算符重载要区分在类内部还是外部!参数个数差一个
* 3、运算符重载还要考虑比如a+b+c运算顺序（这个通过友元函数解决）、++（++a）怎么保证不出错（返回值用引用&）等的问题
* 4、运算符重载本质上还是函数的重载，参数的类型并不一定要相同
* 5、运算符太多了还没全部测试完QaQ
* 6、
*/

#include <iostream>

class Line_class
{
private:
    double length;

public:
    double get_length(void) { return length; }
    double set_length(double len) { length = len; }

    Line_class(void) : length(-1) { }
    Line_class(double len) : length(len) { }

    void print(void) { std::cout << "尚未传入参数!" << std::endl; }
    void print(int i) { std::cout << i << " 的类型是：int" << std::endl; }
    void print(char i) { std::cout << i << " 的类型是：char" << std::endl; }
    void print(float i) { std::cout << i << " 的类型是：float" << std::endl; }
    void print(std::string i) { std::cout << i << " 的类型是：string" << std::endl; }

    Line_class operator-() { length = -length; return *this; }      //一元运算符

    Line_class operator-(int i) { return length - i; }
    friend Line_class operator-(int i, Line_class obj);

    bool operator<(Line_class temp);
};
Line_class operator+ (Line_class temp_1, Line_class temp_2)     //二元运算符
{
    return (temp_1.get_length() + temp_2.get_length());
}


void constructor_reload_test(void);
void operator_reload_test(void);



int main()
{
    //constructor_reload_test();
    operator_reload_test();


    std::cout << "\n测试完成\n";
    return 0;
}

Line_class operator-(int i, Line_class obj)
{
    return obj - i;
}

bool Line_class::operator<(Line_class temp)
{
    if (this->get_length() < temp.get_length())
    {
        return true;
    }
    else {
        return false;
    }
}

void constructor_reload_test(void)
{
    std::cout << "尝试创建对象: " << std::endl;

    Line_class line_1(11), line_2;
    //line_2.set_length(12);

    std::cout << "line_1.length = " << line_1.get_length() << std::endl;
    std::cout << "line_2.length = " << line_2.get_length() << std::endl;

    Line_class test;
    test.print();
    test.print(0);
    test.print((float)12.34);
    test.print('6');        //如果没有声明print(char)会自动把'6'用ascii转成int
    test.print("7");
}

void operator_reload_test(void)
{
    Line_class line_1(1112);
    std::cout << "(-line_1).get_length() = " << (-line_1).get_length() << std::endl;

    Line_class line_2(11), line_3(12);
    std::cout << "(line_2 + line_3).get_length() = " << (line_2 + line_3).get_length() << std::endl;

    Line_class line_4(1112);
    std::cout << "(line_4 - 100).get_length() = " << (line_4 - 100).get_length() << std::endl;
    std::cout << "(100 - line_4).get_length() = " << (100 - line_4).get_length() << std::endl;

    Line_class line_5(3.14), line_6(3.1415);
    std::cout << "(line_5 < line_6) = " << (line_5 < line_6) << std::endl;
    std::cout << "(line_6 < line_5) = " << (line_6 < line_5) << std::endl;

}


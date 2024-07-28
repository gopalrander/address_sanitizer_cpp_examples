#include <iostream>
struct Point {

    struct InitParams {
        InitParams(int x, int y) :
            m_x(x),
            m_y(y)
        {};

        const int& m_x;
        const int& m_y;
    };

    Point(InitParams init) :
        m_x(init.m_x),
        m_y(init.m_y)
    {};

    int m_x;
    int m_y;
};

int main()
{
    int x = 100, y = 200;
    Point::InitParams init(x, y);
    Point obj = Point(init);

    std::cout << "Init Params"<<std::endl;
    std::cout << "Expected:" << x << " Actual:" << init.m_x << std::endl;
    std::cout << "Expected:" << y << " Actual:" << init.m_y << std::endl;

    std::cout << "Object"<<std::endl;
    std::cout << "Expected:" << x << " Actual:" << obj.m_x << std::endl;
    std::cout << "Expected:" << y << " Actual:" << obj.m_y << std::endl;

    return 0;
}
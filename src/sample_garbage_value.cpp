#include <iostream>

/* Problem 1
// This example shows why it is important to understand C++ memory model, even with basic types as int.
// Even without using raw pointers, it is possible to have get an undefined behaviour.
// The problem here is that InitParams is trying to bind a reference variable (m_x) to a temporary copy of variable (x).
// Possible solutions at the end.
*/
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
    // Part 1. Compiler temporary assigned to reference.
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

/* Possible solutions and Discussion
// For variable which are cheap to copy, it is better to create copy, rather than maintaining the references and their lifetime.
// In the above example, member variables of Point::InitParams should be declared as:
// const int m_x and const int m_y, respectively.
// One might argue that for large objects, copy is not cheap. And that's true. 
// Let's discuss that in another example.
*/
#include <iostream>

/* Problem 1
// This example shows why it is important to understand C++ memory model, even with Object types.
// This sample shows that if the lifetime of the variable bound by a reference expires, it is invalid to access that variable later.
// We assume that the Object type Point is not cheap to copy.
// The problem here is the similar, that Line::InitParams is trying to bind a reference variable (m_start) to a compiler temporary variable.
// Note: The output of the program might print garbage value based on the compiler used.
// Runtime analyzer option should be used to compiler and run this program to get the error.
// Eg: clang option -fsanitize=address
// Possible solutions at the end.
*/
struct Point {

    Point(int x, int y):
        m_x(x),
        m_y(y)
    {};

    int m_x;
    int m_y;
};

struct Line {

    struct InitParam {
        
        InitParam(const Point& start, const Point& end):
            m_start(start),
            m_end(end)
            {}

        const Point& m_start;
        const Point& m_end;
    };

    Line(InitParam init):
        m_start(init.m_start),
        m_end(init.m_end)
    {}

    void Print()
    {
        std::cout << "start =  x: " << this->m_start.m_x << " y: " << this->m_start.m_y << std::endl;
        std::cout << "end =  x: " << this->m_end.m_x << " y: " << this->m_end.m_y << std::endl;
    }

    Point m_start;
    Point m_end;
};


int main()
{
    int x = 100, y = 200;
    
    Line::InitParam init(Point(x, y), Point(x+x, y+y));
    Line line(init);

    line.Print();
    
    return 0;
}

/* Possible solutions and Discussion
// For variable which are NOT cheap to copy, it is better to store reference, rather than copying.
// And with reference, we also need to understand the lifetime management of the variable.
// In the above example, variables to constructor Line::InitParams are compiler temporary and even if they are declared as const ref type, their lifetime is not extended.
// Only valid place to use them is within the constructor Line::InitParams.
// To solve the problem,One possibility is that the input to the paramters should be declared as lvalues before passing them in constructor.
//    Point start = Point(x, y);
//    Point end = Point(x+x, y+y);
//    Line::InitParam init(start, end);
// Godbolt: https://godbolt.org/z/4dfKEvf11
*/
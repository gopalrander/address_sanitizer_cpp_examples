#include <iostream>
struct SomeClass {

    struct InitParams {
        InitParams(int sv, int pd) :
            m_sv(sv), m_partitionId(pd)
        {};

        const int& m_sv;
        const int& m_partitionId;
    };

    SomeClass(InitParams init) :
        m_sequence_vector(init.m_sv),
        m_partitionId(init.m_partitionId)
    { };

    int m_sequence_vector;
    int m_partitionId;
};

int main()
{
    SomeClass::InitParams init(100, 100);
    SomeClass obj = SomeClass(init);

    std::cout << obj.m_sequence_vector << std::endl;

    return 0;
}
#include "Matrices.h"
#include "Vector3D.h"
#include <ostream>
#include <iostream>

int main()
{
    
    Vector3D row1(1.0f, 2.0f, -3.0f);
    Vector3D row2(4.0f, -5.0f, 6.0f);
    Vector3D row3(-3.0f, -18.0f, -13.0f);

    Matrix3D a(row1, row2, row3);

    Matrix3D b(row2, row3, row1);

    float result = ScalarTriple(row1, row2, row3);

    float result2 = Lagrange(row1, row2);


    std::cout << result << std::endl;
    std::cout << result2 << std::endl;
    return 0;
}

/*
for(int i = 0; i < sizeof(result) /sizeof(int); i++)
{
    std::cout << result[i]<< std::endl;
}
*/
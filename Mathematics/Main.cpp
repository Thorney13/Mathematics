#include "Matrices.h"
#include "Vector3D.h"
#include <ostream>
#include <iostream>

/*
int main()
{
    Vector3D v(1, 4, 7);

    Vector3D normalized = Normalize(v);
    
    for(int i = 0; i < sizeof(v) /sizeof(int); i++)
    {
        std::cout << v[i] - normalized[i] << std::endl;
        //v[i] *= 3.0f;
        //std::cout << v[i] << std::endl;
    }
    return 0;
}
*/

int main()
{
    
    Vector3D row1(1.0f, 2.0f, 3.0f);
    Vector3D row2(4.0f, 5.0f, 6.0f);
    Vector3D row3(7.0f, 8.0f, 9.0f);

    Matrix3D a(row1, row2, row3);

    Matrix3D b(row2, row3, row1);

    Vector3D result = Cross(row1, row2);

    for(int i = 0; i < sizeof(result) /sizeof(int); i++)
    {
        std::cout << result[i]<< std::endl;
    }
    return 0;
}
﻿#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>

struct Vector3D
{
    float x, y, z;

    Vector3D() = default;
    
    Vector3D(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    
    float& operator [](int i)
    {
        return ((&x)[i]);
    }
    
    const float& operator [](int i) const 
    {
        return ((&x)[i]);
    }
    
    Vector3D& operator *=(float s)
    {
        x *= s; y *= s; z*= s;
        return (*this);
    }

    Vector3D& operator /=(float s)
    {
        s = 1.0f / s;
        x *= s; y *= s; z*= s;
        return (*this);
    }

    Vector3D& operator +=(const Vector3D& v)
    {
        x += v.x; y += v.y; z += v.z;
        return(*this);
    }

    Vector3D& operator -=(const Vector3D& v)
    {
        x -= v.x; y -= v.y; z -= v.z;
        return(*this);
    }
    
};

inline Vector3D operator *(const Vector3D& v, float s)
{
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator /(const Vector3D& v, float s)
{
    s = 1.0f / s;
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline float Magnitude(const Vector3D& v)
{
    return(sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline Vector3D Normalize(const Vector3D& v)
{
    return( v / Magnitude(v));
}

inline Vector3D operator +(const Vector3D& a, const Vector3D& b)
{
    return (Vector3D(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline Vector3D operator -(const Vector3D& a, const Vector3D& b)
{
    return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
}

inline float Dot(const Vector3D& a, const Vector3D& b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline float DisDot(const Vector3D& a, const Vector3D& b, const Vector3D& c)
{
    return (a.x * (b.x+ c.x) + a.y * (b.y + c.y) + a.z * (b.z + c.z));
}

inline Vector3D Cross(const Vector3D& a, const Vector3D& b)
{
    return (Vector3D(a.y * b.z - a.z * b.y,
                     a.z * b.x - a.x * b.z,
                     a.x * b.y - a.y * b.x));
}

inline float Lagrange(const Vector3D& a, const Vector3D& b)
{
    Vector3D cross = Cross(a, b);
    float x = pow(cross.x, 2);
    float y = pow(cross.y, 2);
    float z = pow(cross.z, 2);
    
    return (x+y+z);
}

inline float ScalarTriple(const Vector3D& a, const Vector3D& b, const Vector3D& c)
{
    Vector3D cross = Cross(a, b);

    return (Dot(cross, c));
}

#endif // VECTOR3D_H
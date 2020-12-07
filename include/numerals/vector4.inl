//
//  vector4.inl
//  numerals
//
//  Created by Dmitrii Torkhov <dmitriitorkhov@gmail.com> on 28.06.2020.
//  Copyright © 2020 Dmitrii Torkhov. All rights reserved.
//

namespace cc {

    // -- Implicit basic constructors --

    template<class T>
    inline vector4<T>::vector4() : x(), y(), width(), height() {
    }

    template<class T>
    inline vector4<T>::vector4(const vector4 &v) : x(v.x), y(v.y), width(v.width), height(v.height) {
    }

    // -- Explicit basic constructors --

    template<class T>
    inline vector4<T>::vector4(T s) : x(s), y(s), width(s), height(s) {
    }

    template<class T>
    inline vector4<T>::vector4(T x, T y, T width, T height) : x(x), y(y), width(width), height(height) {
    }

    template<class T>
    inline vector4<T>::vector4(const vector2 <T> &o, const vector2 <T> &s) : origin(o), size(s) {
    }

    // -- Destructor --

    template<class T>
    inline vector4<T>::~vector4() {
    }

    // -- Copy assignment --

    template<class T>
    inline vector4 <T> &vector4<T>::operator=(const vector4 &v) {
        x = v.x;
        y = v.y;
        width = v.width;
        height = v.height;

        return *this;
    }

    // -- Component accesses --

    template<class T>
    inline T &vector4<T>::operator[](size_t i) {
        switch (i) {
            case 0:
            default:
                return x;
            case 1:
                return y;
            case 2:
                return width;
            case 3:
                return height;
        }
    }

    template<class T>
    inline const T &vector4<T>::operator[](size_t i) const {
        switch (i) {
            case 0:
            default:
                return x;
            case 1:
                return y;
            case 2:
                return width;
            case 3:
                return height;
        }
    }

    // -- Unary arithmetic operators --

    template<class T>
    inline vector4 <T> &vector4<T>::operator+=(const vector4 <T> &v) {
        return *this = vector4(x + v.x, y + v.y, width + v.width, height + v.height);
    }

    template<class T>
    inline vector4 <T> &vector4<T>::operator+=(T s) {
        return *this = vector4(x + s, y + s, width + s, height + s);
    }

    template<class T>
    inline vector4 <T> &vector4<T>::operator-=(const vector4 <T> &v) {
        return *this = vector4(x - v.x, y - v.y, width - v.width, height - v.height);
    }

    template<class T>
    inline vector4 <T> &vector4<T>::operator-=(T s) {
        return *this = vector4(x - s, y - s, width - s, height - s);
    }

    template<class T>
    inline vector4 <T> &vector4<T>::operator*=(const vector4 <T> &v) {
        return *this = vector4(x * v.x, y * v.y, width * v.width, height * v.height);
    }

    template<class T>
    inline vector4 <T> &vector4<T>::operator*=(T s) {
        return *this = vector4(x * s, y * s, width * s, height * s);
    }

    template<class T>
    inline vector4 <T> &vector4<T>::operator/=(const vector4 <T> &v) {
        return *this = vector4(x / v.x, y / v.y, width / v.width, height / v.height);
    }

    template<class T>
    inline vector4 <T> &vector4<T>::operator/=(T s) {
        return *this = vector4(x / s, y / s, width / s, height / s);
    }

    // -- Binary operators --

    template<class T>
    inline bool operator==(const vector4 <T> &v1, const vector4 <T> &v2) {
        return v1.x == v2.x && v1.y == v2.y && v1.width == v2.width && v1.height == v2.height;
    }

    template<class T>
    inline bool operator!=(const vector4 <T> &v1, const vector4 <T> &v2) {
        return !(v1 == v2);
    }

    template<class T>
    inline vector4 <T> operator+(const vector4 <T> &v1, const vector4 <T> &v2) {
        return vector4<T>(v1) += v2;
    }

    template<class T>
    inline vector4 <T> operator+(const vector4 <T> &v, T s) {
        return vector4<T>(v) += s;
    }

    template<class T>
    inline vector4 <T> operator-(const vector4 <T> &v1, const vector4 <T> &v2) {
        return vector4<T>(v1) -= v2;
    }

    template<class T>
    inline vector4 <T> operator-(const vector4 <T> &v, T s) {
        return vector4<T>(v) -= s;
    }

    template<class T>
    inline vector4 <T> operator*(const vector4 <T> &v1, const vector4 <T> &v2) {
        return vector4<T>(v1) *= v2;
    }

    template<class T>
    inline vector4 <T> operator*(const vector4 <T> &v, T s) {
        return vector4<T>(v) *= s;
    }

    template<class T>
    inline vector4 <T> operator/(T s, const vector4 <T> &v) {
        return {s / v.x, s / v.y, s / v.width, s / v.height};
    }

    template<class T>
    inline vector4 <T> operator/(const vector4 <T> &v, T s) {
        return vector4<T>(v) /= s;
    }

    template<class T>
    inline vector4 <T> operator/(const vector4 <T> &v1, const vector4 <T> &v2) {
        return vector4<T>(v1) /= v2;
    }

}
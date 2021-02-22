//
//  vec4.inl
//  vectors
//
//  Created by Dmitrii Torkhov <dmitriitorkhov@gmail.com> on 28.06.2020.
//  Copyright © 2020-2021 Dmitrii Torkhov. All rights reserved.
//

namespace cc {

    // -- Implicit basic constructors --

    template<class T>
    inline vec4<T>::vec4() : x(), y(), width(), height() {
    }

    template<class T>
    inline vec4<T>::vec4(const vec4 &v) : x(v.x), y(v.y), width(v.width), height(v.height) {
    }

    // -- Explicit basic constructors --

    template<class T>
    inline vec4<T>::vec4(T s) : x(s), y(s), width(s), height(s) {
    }

    template<class T>
    inline vec4<T>::vec4(T x, T y, T width, T height) : x(x), y(y), width(width), height(height) {
    }

    template<class T>
    inline vec4<T>::vec4(const vec2 <T> &o, const vec2 <T> &s) : origin(o), size(s) {
    }

    // -- Destructor --

    template<class T>
    inline vec4<T>::~vec4() {
    }

    // -- Copy assignment --

    template<class T>
    inline vec4 <T> &vec4<T>::operator=(const vec4 &v) {
        x = v.x;
        y = v.y;
        width = v.width;
        height = v.height;

        return *this;
    }

    // -- Comparison --

    template<class T>
    bool vec4<T>::equals(const vec4 &v) const {
        return origin.equals(v.origin) && size.equals(v.size);
    }

    // -- Component accesses --

    template<class T>
    inline T &vec4<T>::operator[](size_t i) {
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
    inline const T &vec4<T>::operator[](size_t i) const {
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
    inline vec4 <T> &vec4<T>::operator+=(const vec4 <T> &v) {
        return *this = vec4(x + v.x, y + v.y, width + v.width, height + v.height);
    }

    template<class T>
    inline vec4 <T> &vec4<T>::operator+=(T s) {
        return *this = vec4(x + s, y + s, width + s, height + s);
    }

    template<class T>
    inline vec4 <T> &vec4<T>::operator-=(const vec4 <T> &v) {
        return *this = vec4(x - v.x, y - v.y, width - v.width, height - v.height);
    }

    template<class T>
    inline vec4 <T> &vec4<T>::operator-=(T s) {
        return *this = vec4(x - s, y - s, width - s, height - s);
    }

    template<class T>
    inline vec4 <T> &vec4<T>::operator*=(const vec4 <T> &v) {
        return *this = vec4(x * v.x, y * v.y, width * v.width, height * v.height);
    }

    template<class T>
    inline vec4 <T> &vec4<T>::operator*=(T s) {
        return *this = vec4(x * s, y * s, width * s, height * s);
    }

    template<class T>
    inline vec4 <T> &vec4<T>::operator/=(const vec4 <T> &v) {
        return *this = vec4(x / v.x, y / v.y, width / v.width, height / v.height);
    }

    template<class T>
    inline vec4 <T> &vec4<T>::operator/=(T s) {
        return *this = vec4(x / s, y / s, width / s, height / s);
    }

    // Rectangle operations

    template<class T>
    T vec4<T>::get_min_x() const {
        return origin.x;
    }

    template<class T>
    T vec4<T>::get_max_x() const {
        return origin.x + size.width;
    }

    template<class T>
    T vec4<T>::get_min_y() const {
        return origin.y;
    }

    template<class T>
    T vec4<T>::get_max_y() const {
        return origin.y + size.height;
    }

    template<class T>
    inline void vec4<T>::merge(const vec4 &v) {
        const T min_x = std::min(get_min_x(), v.get_min_x());
        const T min_y = std::min(get_min_y(), v.get_min_y());
        const T max_x = std::max(get_max_x(), v.get_max_x());
        const T max_y = std::max(get_max_y(), v.get_max_y());
        *this = {min_x, min_y, max_x - min_x, max_y - min_y};
    }

    template<class T>
    inline bool vec4<T>::contains(const vec2 <T> &v) const {
        return v.x >= get_min_x() && v.x <= get_max_x() && v.y >= get_min_y() && v.y <= get_max_y();
    }

    // -- Binary operators --

    template<class T>
    inline bool operator==(const vec4 <T> &v1, const vec4 <T> &v2) {
        return v1.x == v2.x && v1.y == v2.y && v1.width == v2.width && v1.height == v2.height;
    }

    template<class T>
    inline bool operator!=(const vec4 <T> &v1, const vec4 <T> &v2) {
        return !(v1 == v2);
    }

    template<class T>
    inline vec4 <T> operator+(const vec4 <T> &v1, const vec4 <T> &v2) {
        return vec4<T>(v1) += v2;
    }

    template<class T>
    inline vec4 <T> operator+(const vec4 <T> &v, T s) {
        return vec4<T>(v) += s;
    }

    template<class T>
    inline vec4 <T> operator-(const vec4 <T> &v1, const vec4 <T> &v2) {
        return vec4<T>(v1) -= v2;
    }

    template<class T>
    inline vec4 <T> operator-(const vec4 <T> &v, T s) {
        return vec4<T>(v) -= s;
    }

    template<class T>
    inline vec4 <T> operator*(const vec4 <T> &v1, const vec4 <T> &v2) {
        return vec4<T>(v1) *= v2;
    }

    template<class T>
    inline vec4 <T> operator*(const vec4 <T> &v, T s) {
        return vec4<T>(v) *= s;
    }

    template<class T>
    inline vec4 <T> operator/(T s, const vec4 <T> &v) {
        return {s / v.x, s / v.y, s / v.width, s / v.height};
    }

    template<class T>
    inline vec4 <T> operator/(const vec4 <T> &v, T s) {
        return vec4<T>(v) /= s;
    }

    template<class T>
    inline vec4 <T> operator/(const vec4 <T> &v1, const vec4 <T> &v2) {
        return vec4<T>(v1) /= v2;
    }

}
//
//  vector4.h
//  numerals
//
//  Created by Dmitrii Torkhov <dmitriitorkhov@gmail.com> on 28.06.2020.
//  Copyright © 2020 Dmitrii Torkhov. All rights reserved.
//

#pragma once

#include <algorithm>

#include "numerals/vector2.h"

namespace cc {

    template<class T>
    struct vector4 {

        // -- Data --

        union {

            struct {

                T x, y;

                union {

                    struct {

                        T width, height;

                    };

                    struct {

                        T z, w;

                    };

                };

            };

            struct {

                T left, bottom, right, top;

            };

            struct {

                vector2<T> origin, size;

            };

        };

        // -- Implicit basic constructors --

        vector4();

        vector4(const vector4 &v);

        // -- Explicit basic constructors --

        explicit vector4(T s);

        vector4(T x, T y, T width, T height);

        vector4(const vector2<T> &o, const vector2<T> &s);

        // -- Destructor --

        ~vector4();

        // -- Copy assignment --

        vector4 &operator=(const vector4 &v);

        // -- Comparison --

        bool equals(const vector4 &v) const;

        // -- Component accesses --

        T &operator[](size_t i);

        const T &operator[](size_t i) const;

        // -- Unary arithmetic operators --

        vector4 &operator+=(const vector4 &v);

        vector4 &operator+=(T s);

        vector4 &operator-=(const vector4 &v);

        vector4 &operator-=(T s);

        vector4 &operator*=(const vector4 &v);

        vector4 &operator*=(T s);

        vector4 &operator/=(const vector4 &v);

        vector4 &operator/=(T s);

        // Rectangle operations

        T get_min_x() const;

        T get_max_x() const;

        T get_min_y() const;

        T get_max_y() const;

        void merge(const vector4 &v);

        bool contains(const vector2<T> &v) const;

    };

    // -- Types --

    using float4 = vector4<float>;

    using int4 = vector4<int>;

    using size_t4 = vector4<size_t>;

    // -- Binary operators --

    template<class T>
    bool operator==(const cc::vector4<T> &v1, const cc::vector4<T> &v2);

    template<class T>
    bool operator!=(const cc::vector4<T> &v1, const cc::vector4<T> &v2);

    template<class T>
    cc::vector4<T> operator+(const cc::vector4<T> &v1, const cc::vector4<T> &v2);

    template<class T>
    cc::vector4<T> operator+(const cc::vector4<T> &v1, T s);

    template<class T>
    cc::vector4<T> operator-(const cc::vector4<T> &v1, const cc::vector4<T> &v2);

    template<class T>
    cc::vector4<T> operator-(const cc::vector4<T> &v, T s);

    template<class T>
    cc::vector4<T> operator*(const cc::vector4<T> &v1, const cc::vector4<T> &v2);

    template<class T>
    cc::vector4<T> operator*(const cc::vector4<T> &v, T s);

    template<class T>
    cc::vector4<T> operator/(float f, const cc::vector4<T> &v);

    template<class T>
    cc::vector4<T> operator/(const cc::vector4<T> &v, T s);

    template<class T>
    cc::vector4<T> operator/(const cc::vector4<T> &v1, const cc::vector4<T> &v2);

}

#include "vector4.inl"

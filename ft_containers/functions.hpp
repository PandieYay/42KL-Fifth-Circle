#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

namespace ft
{
    template <bool Cond, class T = void>
    struct enable_if
    {
    };
    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    template <bool trueFalse>
    struct is_integral_base
    {
        static const bool value = trueFalse;
    };

    template <class T>
    struct is_integral : is_integral_base<false>
    {
    };

    template <>
    struct is_integral<bool> : is_integral_base<true>
    {
    };

    template <>
    struct is_integral<int> : is_integral_base<true>
    {
    };
    template <> struct is_integral<char> : is_integral_base<true> {};
    template <> struct is_integral<char16_t> : is_integral_base<true> {};
    template <> struct is_integral<char32_t> : is_integral_base<true> {};
    template <> struct is_integral<wchar_t> : is_integral_base<true> {};
    template <> struct is_integral<signed char> : is_integral_base<true> {};
    template <> struct is_integral<short> : is_integral_base<true> {};
    template <> struct is_integral<long> : is_integral_base<true> {};
    template <> struct is_integral<long long int> : is_integral_base<true> {};
    template <> struct is_integral<unsigned char> : is_integral_base<true> {};
    template <> struct is_integral<unsigned short int> : is_integral_base<true> {};
    template <> struct is_integral<unsigned int> : is_integral_base<true> {};
    template <> struct is_integral<unsigned long int> : is_integral_base<true> {};
    template <> struct is_integral<unsigned long long int> : is_integral_base<true> {};

    template <class InputIterator1, class InputIterator2>  bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1!=last1)
        {
            if (!(*first1 == *first2))
            return false;
            ++first1; ++first2;
        }
        return true;
    }
    template <class InputIterator1, class InputIterator2>  bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        while (first1!=last1)
        {
            if (first2==last2 || *first2<*first1) return false;
            else if (*first1<*first2) return true;
            ++first1; ++first2;
        }
        return (first2!=last2);
    }

    template <class T1, class T2> struct pair
    {
        T1 first;
        T2 second;

        // Constructors
        pair() : first(T1()), second(T2()){};
        pair(const T1 &x, const T2 &y) :first(x), second(y) {};
        template<class U, class V>
        pair (const pair<U,V> &pr) : first(pr.first), second(pr.second) {};

        // operator=
        pair &operator=(const pair& pr) {first = pr.first; second = pr.second; return *this; };
    };

    //Relational Operators
    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return rhs < lhs;
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs < rhs);
    }
    
    template <class T1, class T2>  pair<T1,T2> make_pair (T1 x, T2 y)
    {
    return (pair<T1,T2>(x,y));
    }
}
#endif
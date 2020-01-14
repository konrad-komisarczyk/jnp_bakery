#ifndef JNP1ZAD4_PIE_H
#define JNP1ZAD4_PIE_H

#include <cassert>
#include <type_traits>
#include <tgmath.h>

/**
 * @return Approximation of PI
 * Leibnitz`s method -
 * Calculates (@param n)-th partial sum of Maclaurin`s series for function y = arctg(x) and x = 1
 */
constexpr double pi_approx(unsigned int n) {

     //perimeter of polygon INSCRIBED in unit circle. Starting with hexagon.
            double insc = 6;
     //perimeter of polygon CIRCUMSCRIBED on unit circle. Starting with hexagon.
                double cirsc = 6 * 2 / sqrt(3); // TODO - sqrt też musimy samemu przybliżać?

              for (int i = 0; i < n; i++) {
        // we use formula from Achimedes "Measurement of a Circle"
                cirsc = 2 * insc * cirsc / (insc + cirsc);
               insc = sqrt(insc * cirsc);
            }

            return (cirsc + insc) / 4;
}

/**
 * Approximation of PI. Most accurate that it is possible in type double.
 */
constexpr double PI = pi_approx(5000000);

template<typename R, R radius, bool isSellable, typename P = float>
class Pie {
    static_assert(std::is_integral<R>::value, "R type has to be integral");
    static_assert(std::is_floating_point<P>::value, "P type has to be floating point");

private:
    int stock;
    P price;

public:
    static constexpr bool sellable = isSellable;

    typedef R SizeType;

    typedef P PriceType;

    //CherryPie constructor
    template<bool b = isSellable, typename std::enable_if<!b, bool>::type = false>
    Pie(int initialStock) :
            stock(initialStock) {
        assert(initialStock >= 1);
    }

    //ApplePie constructor
    template<bool b = isSellable, typename std::enable_if<b, bool>::type = false>
    Pie(int initialStock, P price) :
            stock(initialStock),
            price(price) {
        assert(initialStock >= 1);
    }

    static constexpr double getArea() {
        return (PI * radius * radius);
    }

    int getStock() {
        return stock;
    }

    template<bool b = isSellable>
    typename std::enable_if<b, P>::type getPrice() {
        return price;
    }

    template<bool b = isSellable>
    typename std::enable_if<b, void>::type sell() {
        if (stock >= 1) {
            stock--;
        }
    }

    template<bool b = isSellable>
    typename std::enable_if<b, void>::type restock(int amount) {
        if (stock + amount >= 0) {
            stock += amount;
        }
    }
};

template<typename R, R radius>
using CherryPie = Pie<R, radius, false>;

template<typename R, R radius, typename P>
using ApplePie = Pie<R, radius, true, P>;

#endif //JNP1ZAD4_PIE_H
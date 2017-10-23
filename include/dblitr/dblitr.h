#pragma once

#include <utility>
#include <stdexcept>

namespace elh {
    // coordinate
    using coord = std::pair<int, int>;

    // forward declaration
    template <int Width, int Height>
    class doubled_iterator;

    // abs to x and y coordinate
    template <int Width, int Height>
    coord cast_to_coord(int abs) {
        if (abs<0 && Width*Height<abs) throw std::out_of_range{"argument exceeds the width and height range"};
        else return coord{abs%Width, abs/Height};
    }

    // coord to abs
    template <int Width, int Height>
    int cast_to_abs(const coord& c) noexcept {
        return c.first + Width*c.second;
    }

    template <int Width, int Height>
	class doubled_iterator {
		int abs_m;  // absolute position through the range

	public:
        // construct with a absolute position
        doubled_iterator(int abs): abs_m{abs} {}
        // construct with a coordinate
        doubled_iterator(const coord& c): abs_m{cast_to_abs<Width, Height>(c)} {}
        // construct with another iterator
        doubled_iterator(const doubled_iterator<Width, Height>& itr): abs_m{itr.abs()} {}

        doubled_iterator<Width, Height>& operator=(int abs) noexcept {
            abs_m = abs;
            return *this;
        }

        doubled_iterator<Width, Height>& operator=(const coord& c) noexcept { 
            abs_m = cast_to_abs<Width, Height>(c);
            return *this;
        }

        doubled_iterator<Width, Height>& operator=(const doubled_iterator<Width, Height>&) = default;

        // get the absolute positon
		int abs() const noexcept { return abs_m; }

        // set the absolute position (should start with 0)
        void set_abs(int abs) noexcept { abs_m = abs; }

        // get the coordinate
        coord crd() const noexcept { return cast_to_coord<Width, Height>(abs_m); }

        void set_crd(const coord& c) noexcept { abs_m = cast_to_abs<Width, Height>(c); }

        doubled_iterator<Width, Height>& operator++() { // prefix
            abs_m++;
            return *this;
        }
        doubled_iterator<Width, Height> operator++(int) {  // postfix
            doubled_iterator<Width, Height> temp = *this;
            abs_m++;
            return temp;
        }

        doubled_iterator<Width, Height>& operator--() {
            --abs_m;
            return *this;
        }
        doubled_iterator<Width, Height> operator--(int) {
            doubled_iterator<Width, Height> temp = *this;
            --abs_m;
            return temp;
        }
	};
    

    template <int Width, int Height>
    bool operator==(const doubled_iterator<Width, Height>& lhs, const doubled_iterator<Width, Height>& rhs) noexcept {
        return lhs.abs() == rhs.abs();
    }

    template <int Width, int Height>
    bool operator!=(const doubled_iterator<Width, Height>& lhs, const doubled_iterator<Width, Height>& rhs) noexcept {
        return !(lhs == rhs);
    }

    template <int Width, int Height>
    bool operator>(const doubled_iterator<Width, Height>& lhs, const doubled_iterator<Width, Height>& rhs) noexcept {
        return lhs.abs() > rhs.abs();
    }

    template <int Width, int Height>
    bool operator<(const doubled_iterator<Width, Height>& lhs, const doubled_iterator<Width, Height>& rhs) noexcept {
        return lhs.abs() < rhs.abs();
    }

    template <int Width, int Height>
    bool operator<=(const doubled_iterator<Width, Height>& lhs, const doubled_iterator<Width, Height>& rhs) noexcept {
        return !operator>(lhs, rhs);
    }
    
    template <int Width, int Height>
    bool operator>=(const doubled_iterator<Width, Height>& lhs, const doubled_iterator<Width, Height>& rhs) noexcept {
        return !operator<(lhs, rhs);
    }
}

#pragma once

#include <utility>

namespace elh {

    template <int Width, int Height>
	class doubled_iterator final {
    public:
        using coord = std::pair<int, int>;

    protected:
        // abs to x and y coordinate
        static coord cast_to_coord(int abs) noexcept {
            return coord{abs%Width, abs/Height};
        }

        // coord to abs
        static int cast_to_abs(const coord& c) noexcept {
            return c.first + Width*c.second;
        }

    private:
		int abs_m;  // absolute position through the range

	public:
        // construct with a absolute position
        doubled_iterator(int abs): abs_m{abs} {}
        // construct with a coordinate
        doubled_iterator(const coord& c): abs_m{cast_to_abs(c)} {}

        // get the absolute positon
		int abs() const noexcept { return abs_m; }

        // set the absolute position (should start with 0)
        void set_abs(int abs) noexcept { abs_m = abs; }

        // get the coordinate
        coord crd() const noexcept { return cast_to_coord(abs_m); }

        void set_crd(const coord& c) noexcept { abs_m = cast_to_abs(c); }
	};

    template <int Width, int Height>
    bool operator==(const doubled_iterator<Width, Height>& lhs, const doubled_iterator<Width, Height>& rhs) noexcept {
        return lhs.abs() == rhs.abs();
    }
}

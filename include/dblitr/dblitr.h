#pragma once

#include <utility>

namespace elh {

    template <int Width, int Height>
	class doubled_iterator final {
    public:
        using coord = std::pair<int, int>;

    protected:
        static coord cast_to_coord(int abs) {
            return coord{abs%Width, abs/Height};
        }

    private:
		int abs_m;  // absolute position through the range

	public:
        // construct with a absolute position
        doubled_iterator(int abs): abs_m{abs} {}

        // get the absolute positon
		int abs() const noexcept { return abs_m; }

        // set the absolute position (should start with 0)
        void set_abs(int abs) noexcept { abs_m = abs; }
	};
}

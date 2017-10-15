#pragma once

namespace elh {
	class doubled_iterator final {
		int abs_m;  // absolute position through the range

	public:
        // construct with a absolute position
        doubled_iterator(int abs);

        // get the absolute positon
		int abs() const noexcept;
	};
}

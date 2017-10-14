#pragma once

namespace elh {
	class doubled_iterator final {
		int abs_m;
	public:
        doubled_iterator(int abs);
		int abs() const noexcept;
	};
}

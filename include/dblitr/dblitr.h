#pragma once

namespace elh {
	class doubled_iterator final {
		int abs_m;
	public:
		int abs() const noexcept;
	};
}

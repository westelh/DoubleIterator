#include "dblitr/dblitr.h"

// ------------------------------------------------------------------
elh::doubled_iterator::doubled_iterator(int abs): abs_m{abs} {  }
// ------------------------------------------------------------------
int elh::doubled_iterator::abs() const noexcept {
    return abs_m;
}
// ------------------------------------------------------------------
void elh::doubled_iterator::set_abs(int abs) noexcept {
    abs_m = abs;
}
// ------------------------------------------------------------------

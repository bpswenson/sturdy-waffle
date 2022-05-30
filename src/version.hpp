//
// Created by bswenson3 on 5/29/22.
//

#include <common.hpp>
#include <version.conf>

namespace xeon {
    String get_xeon_full_version() {
        return String(XEON_VERSION_STRING);
    }
}
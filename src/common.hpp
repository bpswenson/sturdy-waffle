//
// Created by bswenson3 on 5/28/22.
//
#pragma once

#include <cstring>
#include <cstdint>
#include <cstddef>
#include <cassert>
#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace xeon {

    using String = std::string;
    using StringView = std::string_view;

    template<typename KEY, typename VALUE>
    using HashMap = std::unordered_map<KEY, VALUE>;

    using int8 = int8_t;
    using int16 = int16_t;
    using int32 = int32_t;
    using int64 = int64_t;

    using uint16 = uint16_t;
    using uint32 = uint32_t;
    using uint64 = uint64_t;

    template<typename TYPE>
    using Vector = std::vector<TYPE>;



}
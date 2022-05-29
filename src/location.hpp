//
// Created by bswenson3 on 5/28/22.
//

#pragma once

#include <common.hpp>

namespace xeon {

class Location {
public:
    Location(uint32 file_id, uint32 line, uint32 column, uint32 length) :
        m_file_id(file_id), m_line(line), m_column(column), m_length(length) {}

    uint32 get_file_id()  const { return m_file_id; }
    uint32 get_line() const { return m_line; }
    uint32 get_column() const { return m_column; }
    uint32 get_length() const { return m_length; }

private:
    uint32 m_file_id;
    uint32 m_line;
    uint32 m_column;
    uint32 m_length;
};

}

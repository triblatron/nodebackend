//
// Created by tony on 09/03/24.
//

#pragma once

#include "InputStream.h"


#include <limits>

namespace nbe
{
    class ByteBuffer;

    class NODEBACKEND_API MemoryInputStream : public InputStream
    {
    public:
        explicit MemoryInputStream(ByteBuffer* buf);

        InputStream& readBuf(value_type* buf, std::size_t len) override;
    private:
        ByteBuffer* _buf;
    };
}
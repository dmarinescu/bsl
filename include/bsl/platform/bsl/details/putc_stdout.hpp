/// @copyright
/// Copyright (C) 2020 Assured Information Security, Inc.
///
/// @copyright
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// @copyright
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// @copyright
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
/// SOFTWARE.

#ifndef BSL_DETAILS_PUTC_STDOUT_HPP
#define BSL_DETAILS_PUTC_STDOUT_HPP

#include "../../../char_type.hpp"
#include "../../../cstdio.hpp"
#include "../../../discard.hpp"
#include "../../../is_constant_evaluated.hpp"

namespace bsl::details
{
    /// <!-- description -->
    ///   @brief Outputs a character to stdout.
    ///
    /// <!-- inputs/outputs -->
    ///   @param c the character to output to stdout
    ///
    constexpr void
    putc_stdout(char_type const c) noexcept
    {
        if (is_constant_evaluated()) {
            return;
        }

        // This is required by stdio
        // NOLINTNEXTLINE(bsl-implicit-conversions-forbidden)
        bsl::discard(fputc(c, stdout));
    }
}

#endif

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

#include <bsl/extent.hpp>
#include <bsl/ut.hpp>

/// <!-- description -->
///   @brief Main function for this unit test. If a call to ut_check() fails
///     the application will fast fail. If all calls to ut_check() pass, this
///     function will successfully return with bsl::exit_success.
///
/// <!-- inputs/outputs -->
///   @return Always returns bsl::exit_success.
///
bsl::exit_code
main() noexcept
{
    using namespace bsl;

    static_assert(extent<bool>::value == 0);
    static_assert(extent<bool, 0>::value == 0);
    static_assert(extent<bool, 1>::value == 0);
    static_assert(extent<bool, 2>::value == 0);

    static_assert(extent<bool[]>::value == 0);          // NOLINT
    static_assert(extent<bool[], 0>::value == 0);       // NOLINT
    static_assert(extent<bool[][4]>::value == 0);       // NOLINT
    static_assert(extent<bool[][4], 0>::value == 0);    // NOLINT
    static_assert(extent<bool[][4], 1>::value == 4);    // NOLINT
    static_assert(extent<bool[][4], 2>::value == 0);    // NOLINT

    static_assert(extent<bool[2]>::value == 2);          // NOLINT
    static_assert(extent<bool[2], 0>::value == 2);       // NOLINT
    static_assert(extent<bool[2][4]>::value == 2);       // NOLINT
    static_assert(extent<bool[2][4], 0>::value == 2);    // NOLINT
    static_assert(extent<bool[2][4], 1>::value == 4);    // NOLINT
    static_assert(extent<bool[2][4], 2>::value == 0);    // NOLINT

    return bsl::ut_success();
}
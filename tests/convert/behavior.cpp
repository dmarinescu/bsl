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

#include <bsl/convert.hpp>
#include <bsl/ut.hpp>

namespace
{
    /// <!-- description -->
    ///   @brief Used to execute the actual checks. We put the checks in this
    ///     function so that we can validate the tests both at compile-time
    ///     and at run-time. If a bsl::ut_check fails, the tests will either
    ///     fail fast at run-time, or will produce a compile-time error.
    ///
    /// <!-- inputs/outputs -->
    ///   @return Always returns bsl::exit_success.
    ///
    [[nodiscard]] constexpr auto
    tests() noexcept -> bsl::exit_code
    {
        bsl::ut_scenario{"the basics"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_int32 const val{42};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::convert<bsl::int32>(val.get()) == 42);
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_int32 const val{42};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::convert<bsl::int32>(val) == 42);
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_int32 const val{42, true};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::convert<bsl::int32>(val).invalid());
                };
            };
        };

        bsl::ut_scenario{"up bsl::convert signed to signed"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_int8 const val{bsl::safe_int8::max()};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val) == bsl::to_i8(bsl::safe_int8::max()));
                    bsl::ut_check(bsl::to_i16(val) == bsl::to_i16(bsl::safe_int8::max()));
                    bsl::ut_check(bsl::to_i32(val) == bsl::to_i32(bsl::safe_int8::max()));
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_int8::max()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_int8::max()));
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_int8 const val{bsl::safe_int8::min()};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val) == bsl::to_i8(bsl::safe_int8::min()));
                    bsl::ut_check(bsl::to_i16(val) == bsl::to_i16(bsl::safe_int8::min()));
                    bsl::ut_check(bsl::to_i32(val) == bsl::to_i32(bsl::safe_int8::min()));
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_int8::min()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_int8::min()));
                };
            };
        };

        bsl::ut_scenario{"up bsl::convert unsigned to unsigned"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_uint8 const val{bsl::safe_uint8::max()};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val) == bsl::to_u8(bsl::safe_uint8::max()));
                    bsl::ut_check(bsl::to_u16(val) == bsl::to_u16(bsl::safe_uint8::max()));
                    bsl::ut_check(bsl::to_u32(val) == bsl::to_u32(bsl::safe_uint8::max()));
                    bsl::ut_check(bsl::to_u64(val) == bsl::to_u64(bsl::safe_uint8::max()));
                    bsl::ut_check(bsl::to_umax(val) == bsl::to_umax(bsl::safe_uint8::max()));
                };
            };
        };

        bsl::ut_scenario{"up bsl::convert signed to unsigned"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_int8 const val{bsl::safe_int8::max()};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val) == bsl::to_u8(bsl::safe_int8::max()));
                    bsl::ut_check(bsl::to_u16(val) == bsl::to_u16(bsl::safe_int8::max()));
                    bsl::ut_check(bsl::to_u32(val) == bsl::to_u32(bsl::safe_int8::max()));
                    bsl::ut_check(bsl::to_u64(val) == bsl::to_u64(bsl::safe_int8::max()));
                    bsl::ut_check(bsl::to_umax(val) == bsl::to_umax(bsl::safe_int8::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_int8 const val{bsl::safe_int8::min()};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val).invalid());
                    bsl::ut_check(bsl::to_u16(val).invalid());
                    bsl::ut_check(bsl::to_u32(val).invalid());
                    bsl::ut_check(bsl::to_u64(val).invalid());
                    bsl::ut_check(bsl::to_umax(val).invalid());
                };
            };
        };

        bsl::ut_scenario{"up bsl::convert unsigned to signed"} = []() noexcept {
            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_uint8 const val{bsl::safe_uint8::max()};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_uint8 const val{bsl::safe_uint8::max()};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i16(val) == bsl::to_i16(bsl::safe_uint8::max()));
                    bsl::ut_check(bsl::to_i32(val) == bsl::to_i32(bsl::safe_uint8::max()));
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_uint8::max()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_uint8::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_uint16 const val{bsl::safe_uint16::max()};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                    bsl::ut_check(bsl::to_i16(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_uint16 const val{bsl::safe_uint16::max()};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i32(val) == bsl::to_i32(bsl::safe_uint16::max()));
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_uint16::max()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_uint16::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_uint32 const val{bsl::safe_uint32::max()};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                    bsl::ut_check(bsl::to_i16(val).invalid());
                    bsl::ut_check(bsl::to_i32(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_uint32 const val{bsl::safe_uint32::max()};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_uint32::max()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_uint32::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_uint64 const val{bsl::safe_uint64::max()};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                    bsl::ut_check(bsl::to_i16(val).invalid());
                    bsl::ut_check(bsl::to_i32(val).invalid());
                    bsl::ut_check(bsl::to_i64(val).invalid());
                    bsl::ut_check(bsl::to_imax(val).invalid());
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::safe_uintmax::max()};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                    bsl::ut_check(bsl::to_i16(val).invalid());
                    bsl::ut_check(bsl::to_i32(val).invalid());
                    bsl::ut_check(bsl::to_i64(val).invalid());
                    bsl::ut_check(bsl::to_imax(val).invalid());
                };
            };
        };

        bsl::ut_scenario{"down bsl::convert signed to signed"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int8::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val) == bsl::to_i8(bsl::safe_int8::max()));
                    bsl::ut_check(bsl::to_i16(val) == bsl::to_i16(bsl::safe_int8::max()));
                    bsl::ut_check(bsl::to_i32(val) == bsl::to_i32(bsl::safe_int8::max()));
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_int8::max()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_int8::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int16::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int16::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i16(val) == bsl::to_i16(bsl::safe_int16::max()));
                    bsl::ut_check(bsl::to_i32(val) == bsl::to_i32(bsl::safe_int16::max()));
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_int16::max()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_int16::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int32::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                    bsl::ut_check(bsl::to_i16(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int32::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i32(val) == bsl::to_i32(bsl::safe_int32::max()));
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_int32::max()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_int32::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int64::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                    bsl::ut_check(bsl::to_i16(val).invalid());
                    bsl::ut_check(bsl::to_i32(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int64::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_int64::max()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_int64::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_intmax::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                    bsl::ut_check(bsl::to_i16(val).invalid());
                    bsl::ut_check(bsl::to_i32(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_intmax::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_intmax::max()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_intmax::max()));
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int8::min())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val) == bsl::to_i8(bsl::safe_int8::min()));
                    bsl::ut_check(bsl::to_i16(val) == bsl::to_i16(bsl::safe_int8::min()));
                    bsl::ut_check(bsl::to_i32(val) == bsl::to_i32(bsl::safe_int8::min()));
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_int8::min()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_int8::min()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int16::min())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int16::min())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i16(val) == bsl::to_i16(bsl::safe_int16::min()));
                    bsl::ut_check(bsl::to_i32(val) == bsl::to_i32(bsl::safe_int16::min()));
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_int16::min()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_int16::min()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int32::min())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                    bsl::ut_check(bsl::to_i16(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int32::min())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i32(val) == bsl::to_i32(bsl::safe_int32::min()));
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_int32::min()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_int32::min()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int64::min())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                    bsl::ut_check(bsl::to_i16(val).invalid());
                    bsl::ut_check(bsl::to_i32(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int64::min())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_int64::min()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_int64::min()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_intmax::min())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                    bsl::ut_check(bsl::to_i16(val).invalid());
                    bsl::ut_check(bsl::to_i32(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_intmax::min())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_intmax::min()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_intmax::min()));
                };
            };
        };

        bsl::ut_scenario{"down bsl::convert unsigned to unsigned"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uint8::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val) == bsl::to_u8(bsl::safe_uint8::max()));
                    bsl::ut_check(bsl::to_u16(val) == bsl::to_u16(bsl::safe_uint8::max()));
                    bsl::ut_check(bsl::to_u32(val) == bsl::to_u32(bsl::safe_uint8::max()));
                    bsl::ut_check(bsl::to_u64(val) == bsl::to_u64(bsl::safe_uint8::max()));
                    bsl::ut_check(bsl::to_umax(val) == bsl::to_umax(bsl::safe_uint8::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uint16::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uint16::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u16(val) == bsl::to_u16(bsl::safe_uint16::max()));
                    bsl::ut_check(bsl::to_u32(val) == bsl::to_u32(bsl::safe_uint16::max()));
                    bsl::ut_check(bsl::to_u64(val) == bsl::to_u64(bsl::safe_uint16::max()));
                    bsl::ut_check(bsl::to_umax(val) == bsl::to_umax(bsl::safe_uint16::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uint32::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val).invalid());
                    bsl::ut_check(bsl::to_u16(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uint32::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u32(val) == bsl::to_u32(bsl::safe_uint32::max()));
                    bsl::ut_check(bsl::to_u64(val) == bsl::to_u64(bsl::safe_uint32::max()));
                    bsl::ut_check(bsl::to_umax(val) == bsl::to_umax(bsl::safe_uint32::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uint64::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val).invalid());
                    bsl::ut_check(bsl::to_u16(val).invalid());
                    bsl::ut_check(bsl::to_u32(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uint64::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u64(val) == bsl::to_u64(bsl::safe_uint64::max()));
                    bsl::ut_check(bsl::to_umax(val) == bsl::to_umax(bsl::safe_uint64::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uintmax::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val).invalid());
                    bsl::ut_check(bsl::to_u16(val).invalid());
                    bsl::ut_check(bsl::to_u32(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uintmax::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u64(val) == bsl::to_u64(bsl::safe_uintmax::max()));
                    bsl::ut_check(bsl::to_umax(val) == bsl::to_umax(bsl::safe_uintmax::max()));
                };
            };
        };

        bsl::ut_scenario{"down bsl::convert signed to unsigned"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int8::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val) == bsl::to_u8(bsl::safe_int8::max()));
                    bsl::ut_check(bsl::to_u16(val) == bsl::to_u16(bsl::safe_int8::max()));
                    bsl::ut_check(bsl::to_u32(val) == bsl::to_u32(bsl::safe_int8::max()));
                    bsl::ut_check(bsl::to_u64(val) == bsl::to_u64(bsl::safe_int8::max()));
                    bsl::ut_check(bsl::to_umax(val) == bsl::to_umax(bsl::safe_int8::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int16::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int16::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u16(val) == bsl::to_u16(bsl::safe_int16::max()));
                    bsl::ut_check(bsl::to_u32(val) == bsl::to_u32(bsl::safe_int16::max()));
                    bsl::ut_check(bsl::to_u64(val) == bsl::to_u64(bsl::safe_int16::max()));
                    bsl::ut_check(bsl::to_umax(val) == bsl::to_umax(bsl::safe_int16::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int32::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val).invalid());
                    bsl::ut_check(bsl::to_u16(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int32::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u32(val) == bsl::to_u32(bsl::safe_int32::max()));
                    bsl::ut_check(bsl::to_u64(val) == bsl::to_u64(bsl::safe_int32::max()));
                    bsl::ut_check(bsl::to_umax(val) == bsl::to_umax(bsl::safe_int32::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int64::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val).invalid());
                    bsl::ut_check(bsl::to_u16(val).invalid());
                    bsl::ut_check(bsl::to_u32(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int64::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u64(val) == bsl::to_u64(bsl::safe_int64::max()));
                    bsl::ut_check(bsl::to_umax(val) == bsl::to_umax(bsl::safe_int64::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_intmax::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val).invalid());
                    bsl::ut_check(bsl::to_u16(val).invalid());
                    bsl::ut_check(bsl::to_u32(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_intmax::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u64(val) == bsl::to_u64(bsl::safe_intmax::max()));
                    bsl::ut_check(bsl::to_umax(val) == bsl::to_umax(bsl::safe_intmax::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int8::min())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val).invalid());
                    bsl::ut_check(bsl::to_u16(val).invalid());
                    bsl::ut_check(bsl::to_u32(val).invalid());
                    bsl::ut_check(bsl::to_u64(val).invalid());
                    bsl::ut_check(bsl::to_umax(val).invalid());
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int16::min())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val).invalid());
                    bsl::ut_check(bsl::to_u16(val).invalid());
                    bsl::ut_check(bsl::to_u32(val).invalid());
                    bsl::ut_check(bsl::to_u64(val).invalid());
                    bsl::ut_check(bsl::to_umax(val).invalid());
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int32::min())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val).invalid());
                    bsl::ut_check(bsl::to_u16(val).invalid());
                    bsl::ut_check(bsl::to_u32(val).invalid());
                    bsl::ut_check(bsl::to_u64(val).invalid());
                    bsl::ut_check(bsl::to_umax(val).invalid());
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_int64::min())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val).invalid());
                    bsl::ut_check(bsl::to_u16(val).invalid());
                    bsl::ut_check(bsl::to_u32(val).invalid());
                    bsl::ut_check(bsl::to_u64(val).invalid());
                    bsl::ut_check(bsl::to_umax(val).invalid());
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_intmax const val{bsl::to_imax(bsl::safe_intmax::min())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val).invalid());
                    bsl::ut_check(bsl::to_u16(val).invalid());
                    bsl::ut_check(bsl::to_u32(val).invalid());
                    bsl::ut_check(bsl::to_u64(val).invalid());
                    bsl::ut_check(bsl::to_umax(val).invalid());
                };
            };
        };

        bsl::ut_scenario{"down bsl::convert unsigned to signed"} = []() noexcept {
            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uint8::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uint8::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i16(val) == bsl::to_i16(bsl::safe_uint8::max()));
                    bsl::ut_check(bsl::to_i32(val) == bsl::to_i32(bsl::safe_uint8::max()));
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_uint8::max()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_uint8::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uint16::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                    bsl::ut_check(bsl::to_i16(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uint16::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i32(val) == bsl::to_i32(bsl::safe_uint16::max()));
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_uint16::max()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_uint16::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uint32::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                    bsl::ut_check(bsl::to_i16(val).invalid());
                    bsl::ut_check(bsl::to_i32(val).invalid());
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uint32::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(bsl::safe_uint32::max()));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(bsl::safe_uint32::max()));
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uint64::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                    bsl::ut_check(bsl::to_i16(val).invalid());
                    bsl::ut_check(bsl::to_i32(val).invalid());
                    bsl::ut_check(bsl::to_i64(val).invalid());
                    bsl::ut_check(bsl::to_imax(val).invalid());
                };
            };

            bsl::ut_given_at_runtime{} = []() noexcept {
                bsl::safe_uintmax const val{bsl::to_umax(bsl::safe_uintmax::max())};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val).invalid());
                    bsl::ut_check(bsl::to_i16(val).invalid());
                    bsl::ut_check(bsl::to_i32(val).invalid());
                    bsl::ut_check(bsl::to_i64(val).invalid());
                    bsl::ut_check(bsl::to_imax(val).invalid());
                };
            };
        };

        bsl::ut_scenario{"to functions"} = []() noexcept {
            bsl::ut_given{} = []() noexcept {
                bsl::safe_int32 const val{42};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_i8(val) == bsl::to_i8(42));
                    bsl::ut_check(bsl::to_i8(42) == bsl::to_i8(42));
                    bsl::ut_check(bsl::to_i16(val) == bsl::to_i16(42));
                    bsl::ut_check(bsl::to_i16(42) == bsl::to_i16(42));
                    bsl::ut_check(bsl::to_i32(val) == bsl::to_i32(42));
                    bsl::ut_check(bsl::to_i32(42) == bsl::to_i32(42));
                    bsl::ut_check(bsl::to_i64(val) == bsl::to_i64(42));
                    bsl::ut_check(bsl::to_i64(42) == bsl::to_i64(42));
                    bsl::ut_check(bsl::to_imax(val) == bsl::to_imax(42));
                    bsl::ut_check(bsl::to_imax(42) == bsl::to_imax(42));
                };
            };

            bsl::ut_given{} = []() noexcept {
                bsl::safe_uint32 const val{42U};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8(val) == bsl::to_u8(42U));
                    bsl::ut_check(bsl::to_u8(42U) == bsl::to_u8(42U));
                    bsl::ut_check(bsl::to_u16(val) == bsl::to_u16(42U));
                    bsl::ut_check(bsl::to_u16(42U) == bsl::to_u16(42U));
                    bsl::ut_check(bsl::to_u32(val) == bsl::to_u32(42U));
                    bsl::ut_check(bsl::to_u32(42U) == bsl::to_u32(42U));
                    bsl::ut_check(bsl::to_u64(val) == bsl::to_u64(42U));
                    bsl::ut_check(bsl::to_u64(42U) == bsl::to_u64(42U));
                    bsl::ut_check(bsl::to_umax(val) == bsl::to_umax(42U));
                    bsl::ut_check(bsl::to_umax(42U) == bsl::to_umax(42U));
                };
            };

            bsl::ut_given{} = []() noexcept {
                constexpr bsl::safe_uintmax const val{bsl::to_umax(0xFFFFFFFFFFFFFFFFU)};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8_unsafe(val) == bsl::to_u8(0xFFU));
                    bsl::ut_check(bsl::to_u16_unsafe(val) == bsl::to_u16(0xFFFFU));
                    bsl::ut_check(bsl::to_u32_unsafe(val) == bsl::to_u32(0xFFFFFFFFU));
                    bsl::ut_check(bsl::to_u64_unsafe(val) == bsl::to_u64(0xFFFFFFFFFFFFFFFFU));
                    bsl::ut_check(bsl::to_umax_unsafe(val) == bsl::to_umax(0xFFFFFFFFFFFFFFFFU));
                };
            };

            bsl::ut_given{} = []() noexcept {
                constexpr bsl::safe_uintmax const val{0xFFFFFFFFFFFFFFFFU};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(bsl::to_u8_unsafe(val.get()) == bsl::to_u8(0xFFU));
                    bsl::ut_check(bsl::to_u16_unsafe(val.get()) == bsl::to_u16(0xFFFFU));
                    bsl::ut_check(bsl::to_u32_unsafe(val.get()) == bsl::to_u32(0xFFFFFFFFU));
                    bsl::ut_check(
                        bsl::to_u64_unsafe(val.get()) == bsl::to_u64(0xFFFFFFFFFFFFFFFFU));
                    bsl::ut_check(
                        bsl::to_umax_unsafe(val.get()) == bsl::to_umax(0xFFFFFFFFFFFFFFFFU));
                };
            };
        };

        bsl::ut_scenario{"to_umax_upper_lower"} = []() noexcept {
            bsl::ut_given{"uint8"} = []() noexcept {
                constexpr auto upper{0xFFFFFFFFFFFFFFFF_umax};
                constexpr auto lower{0x01_u8};
                constexpr auto expected{0xFFFFFFFFFFFFFF01_umax};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(expected == bsl::to_umax_upper_lower(upper, lower));
                    bsl::ut_check(expected == bsl::to_umax_upper_lower(upper.get(), lower));
                    bsl::ut_check(expected == bsl::to_umax_upper_lower(upper, lower.get()));
                    bsl::ut_check(expected == bsl::to_umax_upper_lower(upper.get(), lower.get()));
                };
            };

            bsl::ut_given{"uint16"} = []() noexcept {
                constexpr auto upper{0xFFFFFFFFFFFFFFFF_umax};
                constexpr auto lower{0x0123_u16};
                constexpr auto expected{0xFFFFFFFFFFFF0123_umax};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(expected == bsl::to_umax_upper_lower(upper, lower));
                    bsl::ut_check(expected == bsl::to_umax_upper_lower(upper.get(), lower));
                    bsl::ut_check(expected == bsl::to_umax_upper_lower(upper, lower.get()));
                    bsl::ut_check(expected == bsl::to_umax_upper_lower(upper.get(), lower.get()));
                };
            };

            bsl::ut_given{"uint32"} = []() noexcept {
                constexpr auto upper{0xFFFFFFFFFFFFFFFF_umax};
                constexpr auto lower{0x01234567_u32};
                constexpr auto expected{0xFFFFFFFF01234567_umax};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(expected == bsl::to_umax_upper_lower(upper, lower));
                    bsl::ut_check(expected == bsl::to_umax_upper_lower(upper.get(), lower));
                    bsl::ut_check(expected == bsl::to_umax_upper_lower(upper, lower.get()));
                    bsl::ut_check(expected == bsl::to_umax_upper_lower(upper.get(), lower.get()));
                };
            };

            bsl::ut_given{"uint64/uintmax"} = []() noexcept {
                constexpr auto upper{0xFFFFFFFFFFFFFFFF_umax};
                constexpr auto lower{0x0123456789ABCDEF_umax};
                constexpr auto expected{0x0123456789ABCDEF_umax};
                bsl::ut_then{} = [&]() noexcept {
                    bsl::ut_check(expected == bsl::to_umax_upper_lower(upper, lower));
                    bsl::ut_check(expected == bsl::to_umax_upper_lower(upper.get(), lower));
                    bsl::ut_check(expected == bsl::to_umax_upper_lower(upper, lower.get()));
                    bsl::ut_check(expected == bsl::to_umax_upper_lower(upper.get(), lower.get()));
                };
            };
        };

        return bsl::ut_success();
    }
}

/// <!-- description -->
///   @brief Main function for this unit test. If a call to bsl::ut_check() fails
///     the application will fast fail. If all calls to bsl::ut_check() pass, this
///     function will successfully return with bsl::exit_success.
///
/// <!-- inputs/outputs -->
///   @return Always returns bsl::exit_success.
///
[[nodiscard]] auto
main() noexcept -> bsl::exit_code
{
    static_assert(tests() == bsl::ut_success());
    return tests();
}

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

#include <bsl/is_unbounded_array.hpp>
#include <bsl/ut.hpp>

namespace
{
    class myclass final
    {};

    struct mystruct final
    {};

    // Needed for testing type traits
    // NOLINTNEXTLINE(bsl-decl-forbidden)
    union myunion final
    {};

    enum class myenum : bsl::int32
    {
    };

    class myclass_abstract
    {
    public:
        constexpr myclass_abstract() noexcept = default;
        virtual constexpr ~myclass_abstract() noexcept = default;

        virtual void foo() noexcept = 0;

    protected:
        constexpr myclass_abstract(myclass_abstract const &) noexcept = default;
        [[maybe_unused]] constexpr auto operator=(myclass_abstract const &) &noexcept
            -> myclass_abstract & = default;
        constexpr myclass_abstract(myclass_abstract &&) noexcept = default;
        [[maybe_unused]] constexpr auto operator=(myclass_abstract &&) &noexcept
            -> myclass_abstract & = default;
    };

    class myclass_base
    {};

    class myclass_subclass : public myclass_base
    {};
}

/// <!-- description -->
///   @brief Main function for this unit test. If a call to ut_check() fails
///     the application will fast fail. If all calls to ut_check() pass, this
///     function will successfully return with bsl::exit_success.
///
/// <!-- inputs/outputs -->
///   @return Always returns bsl::exit_success.
///
[[nodiscard]] auto
main() noexcept -> bsl::exit_code
{
    using namespace bsl;

    // NOLINTNEXTLINE(cppcoreguidelines-avoid-c-arrays, hicpp-avoid-c-arrays, modernize-avoid-c-arrays)
    static_assert(is_unbounded_array<bool[]>::value);
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-c-arrays, hicpp-avoid-c-arrays, modernize-avoid-c-arrays)
    static_assert(is_unbounded_array<bool[][1]>::value);
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-c-arrays, hicpp-avoid-c-arrays, modernize-avoid-c-arrays)
    static_assert(is_unbounded_array<bool const[]>::value);
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-c-arrays, hicpp-avoid-c-arrays, modernize-avoid-c-arrays)
    static_assert(is_unbounded_array<bool const[][1]>::value);
    static_assert(!is_unbounded_array<bool>::value);
    static_assert(!is_unbounded_array<bool const>::value);
    static_assert(!is_unbounded_array<bsl::int8>::value);
    static_assert(!is_unbounded_array<bsl::int8 const>::value);
    static_assert(!is_unbounded_array<bsl::int16>::value);
    static_assert(!is_unbounded_array<bsl::int16 const>::value);
    static_assert(!is_unbounded_array<bsl::int32>::value);
    static_assert(!is_unbounded_array<bsl::int32 const>::value);
    static_assert(!is_unbounded_array<bsl::int64>::value);
    static_assert(!is_unbounded_array<bsl::int64 const>::value);
    static_assert(!is_unbounded_array<bsl::int_least8>::value);
    static_assert(!is_unbounded_array<bsl::int_least8 const>::value);
    static_assert(!is_unbounded_array<bsl::int_least16>::value);
    static_assert(!is_unbounded_array<bsl::int_least16 const>::value);
    static_assert(!is_unbounded_array<bsl::int_least32>::value);
    static_assert(!is_unbounded_array<bsl::int_least32 const>::value);
    static_assert(!is_unbounded_array<bsl::int_least64>::value);
    static_assert(!is_unbounded_array<bsl::int_least64 const>::value);
    static_assert(!is_unbounded_array<bsl::int_fast8>::value);
    static_assert(!is_unbounded_array<bsl::int_fast8 const>::value);
    static_assert(!is_unbounded_array<bsl::int_fast16>::value);
    static_assert(!is_unbounded_array<bsl::int_fast16 const>::value);
    static_assert(!is_unbounded_array<bsl::int_fast32>::value);
    static_assert(!is_unbounded_array<bsl::int_fast32 const>::value);
    static_assert(!is_unbounded_array<bsl::int_fast64>::value);
    static_assert(!is_unbounded_array<bsl::int_fast64 const>::value);
    static_assert(!is_unbounded_array<bsl::intptr>::value);
    static_assert(!is_unbounded_array<bsl::intptr const>::value);
    static_assert(!is_unbounded_array<bsl::intmax>::value);
    static_assert(!is_unbounded_array<bsl::intmax const>::value);
    static_assert(!is_unbounded_array<bsl::uint8>::value);
    static_assert(!is_unbounded_array<bsl::uint8 const>::value);
    static_assert(!is_unbounded_array<bsl::uint16>::value);
    static_assert(!is_unbounded_array<bsl::uint16 const>::value);
    static_assert(!is_unbounded_array<bsl::uint32>::value);
    static_assert(!is_unbounded_array<bsl::uint32 const>::value);
    static_assert(!is_unbounded_array<bsl::uint64>::value);
    static_assert(!is_unbounded_array<bsl::uint64 const>::value);
    static_assert(!is_unbounded_array<bsl::uint_least8>::value);
    static_assert(!is_unbounded_array<bsl::uint_least8 const>::value);
    static_assert(!is_unbounded_array<bsl::uint_least16>::value);
    static_assert(!is_unbounded_array<bsl::uint_least16 const>::value);
    static_assert(!is_unbounded_array<bsl::uint_least32>::value);
    static_assert(!is_unbounded_array<bsl::uint_least32 const>::value);
    static_assert(!is_unbounded_array<bsl::uint_least64>::value);
    static_assert(!is_unbounded_array<bsl::uint_least64 const>::value);
    static_assert(!is_unbounded_array<bsl::uint_fast8>::value);
    static_assert(!is_unbounded_array<bsl::uint_fast8 const>::value);
    static_assert(!is_unbounded_array<bsl::uint_fast16>::value);
    static_assert(!is_unbounded_array<bsl::uint_fast16 const>::value);
    static_assert(!is_unbounded_array<bsl::uint_fast32>::value);
    static_assert(!is_unbounded_array<bsl::uint_fast32 const>::value);
    static_assert(!is_unbounded_array<bsl::uint_fast64>::value);
    static_assert(!is_unbounded_array<bsl::uint_fast64 const>::value);
    static_assert(!is_unbounded_array<bsl::uintptr>::value);
    static_assert(!is_unbounded_array<bsl::uintptr const>::value);
    static_assert(!is_unbounded_array<bsl::uintmax>::value);
    static_assert(!is_unbounded_array<bsl::uintmax const>::value);
    static_assert(!is_unbounded_array<myclass_abstract>::value);
    static_assert(!is_unbounded_array<myclass_abstract const>::value);
    static_assert(!is_unbounded_array<myclass>::value);
    static_assert(!is_unbounded_array<myclass const>::value);
    static_assert(!is_unbounded_array<mystruct>::value);
    static_assert(!is_unbounded_array<mystruct const>::value);
    static_assert(!is_unbounded_array<myunion>::value);
    static_assert(!is_unbounded_array<myunion const>::value);
    static_assert(!is_unbounded_array<myenum>::value);
    static_assert(!is_unbounded_array<myenum const>::value);
    static_assert(!is_unbounded_array<myclass_base>::value);
    static_assert(!is_unbounded_array<myclass_base const>::value);
    static_assert(!is_unbounded_array<myclass_subclass>::value);
    static_assert(!is_unbounded_array<myclass_subclass const>::value);
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-c-arrays, hicpp-avoid-c-arrays, modernize-avoid-c-arrays)
    static_assert(!is_unbounded_array<bool[1]>::value);
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-c-arrays, hicpp-avoid-c-arrays, modernize-avoid-c-arrays)
    static_assert(!is_unbounded_array<bool[1][1]>::value);
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-c-arrays, hicpp-avoid-c-arrays, modernize-avoid-c-arrays)
    static_assert(!is_unbounded_array<bool const[1]>::value);
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-c-arrays, hicpp-avoid-c-arrays, modernize-avoid-c-arrays)
    static_assert(!is_unbounded_array<bool const[1][1]>::value);
    static_assert(!is_unbounded_array<void>::value);
    static_assert(!is_unbounded_array<void const>::value);
    static_assert(!is_unbounded_array<void *>::value);
    static_assert(!is_unbounded_array<void const *>::value);
    static_assert(!is_unbounded_array<void *const>::value);
    static_assert(!is_unbounded_array<void const *const>::value);
    static_assert(!is_unbounded_array<bool &>::value);
    static_assert(!is_unbounded_array<bool &&>::value);
    static_assert(!is_unbounded_array<bool const &>::value);
    static_assert(!is_unbounded_array<bool const &&>::value);
    static_assert(!is_unbounded_array<bool(bool)>::value);
    static_assert(!is_unbounded_array<bool (*)(bool)>::value);

    return bsl::ut_success();
}

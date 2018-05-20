//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <alda/bindings/duration.hpp>
#include <alda/bindings/unsigned.hpp>
#include <alda/raw/element_type.hpp>
#include <alda/raw/static_size.hpp>
#include <alda/raw/stream/error.hpp>
#include <alda/serialization/read.hpp>
#include <alda/serialization/write.hpp>
#include <fcppt/catch/defer.hpp>
#include <fcppt/either/make_success.hpp>
#include <fcppt/endianness/format.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch.hpp>
#include <cstdint>
#include <ratio>
#include <sstream>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"bindings::duration",
	"[alda]"
)
{
	typedef
	alda::bindings::unsigned_<
		std::uint32_t,
		fcppt::endianness::format::little
	>
	int_binding;

	typedef
	alda::bindings::duration<
		int_binding,
		std::milli
	>
	duration_binding;

	static_assert(
		alda::raw::static_size<
			duration_binding
		>::value
		==
		alda::raw::static_size<
			int_binding
		>::value,
		""
	);

	typedef
	alda::raw::element_type<
		duration_binding
	>
	duration;

	std::stringstream stream{};

	alda::serialization::write<
		duration_binding
	>(
		stream,
		duration{
			10u
		}
	);

	CHECK(
		fcppt::catch_::defer(
			alda::serialization::read<
				duration_binding
			>(
				stream
			)
			==
			fcppt::either::make_success<
				alda::raw::stream::error
			>(
				duration{
					10u
				}
			)
		)
	);
}

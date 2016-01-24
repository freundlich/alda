//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <alda/bindings/enum.hpp>
#include <alda/bindings/unsigned.hpp>
#include <alda/serialization/write_record.hpp>
#include <alda/raw/make_generic.hpp>
#include <alda/raw/record_variadic.hpp>
#include <alda/raw/stream/istream.hpp>
#include <majutsu/get.hpp>
#include <majutsu/make_role_tag.hpp>
#include <majutsu/role.hpp>
#include <fcppt/endianness/format.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


namespace
{

enum class test_enum
{
	value0,
	value1,
	fcppt_maximum = value1
};

typedef
alda::bindings::enum_<
	test_enum,
	alda::bindings::unsigned_<
		std::uint8_t,
		fcppt::endianness::format::little
	>
>
enum_binding;

MAJUTSU_MAKE_ROLE_TAG(
	enum_role
);

typedef
alda::raw::record_variadic<
	majutsu::role<
		enum_binding,
		enum_role
	>
>
message;

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	alda_enum
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK(
		majutsu::get<
			enum_role
		>(
			message{
				enum_role{} =
					test_enum::value0
			}
		)
		==
		test_enum::value0
	);

	BOOST_CHECK(
		majutsu::get<
			enum_role
		>(
			message{
				enum_role{} =
					test_enum::value1
			}
		)
		==
		test_enum::value1
	);
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	alda_enum_stream
)
{
FCPPT_PP_POP_WARNING

	std::stringstream stream;

	alda::serialization::write_record(
		stream,
		message{
			enum_role{} =
				test_enum::value1
		}
	);

	typedef
	fcppt::optional::object<
		message
	>
	optional_result;

	optional_result const result(
		alda::raw::make_generic<
			alda::raw::stream::istream,
			message
		>(
			stream
		)
	);

	BOOST_REQUIRE(
		result.has_value()
	);

	BOOST_CHECK(
		majutsu::get<
			enum_role
		>(
			result.get_unsafe()
		)
		==
		test_enum::value1
	);

	stream.str(
		"\x15"
	);

	BOOST_CHECK((
		!alda::raw::make_generic<
			alda::raw::stream::istream,
			message
		>(
			stream
		).has_value()
	));
}

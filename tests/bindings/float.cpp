//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <alda/bindings/float.hpp>
#include <alda/bindings/fundamental.hpp>
#include <alda/raw/element_type.hpp>
#include <alda/raw/make_generic.hpp>
#include <alda/raw/static_size.hpp>
#include <alda/raw/stream/error.hpp>
#include <alda/raw/stream/istream.hpp>
#include <alda/serialization/write.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/catch/either.hpp>
#include <fcppt/either/apply.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fcppt/config/external_end.hpp>


namespace
{

static_assert(
	alda::raw::static_size<
		alda::bindings::float_
	>::value
	==
	alda::raw::static_size<
		alda::bindings::fundamental<
			alda::bindings::float_::fixed_int
		>
	>::value,
	""
);

void
fuzzy_equal(
	alda::raw::element_type<
		alda::bindings::float_
	> const _val1,
	alda::raw::element_type<
		alda::bindings::float_
	> const _val2
)
{
	CHECK(
		(_val1 < 0)
		==
		(_val2 < 0)
	);

	typedef
	alda::raw::element_type<
		alda::bindings::float_
	>
	float_type;

	float_type const abs1(
		std::abs(
			_val1
		)
	);

	float_type const abs2(
		std::abs(
			_val2
		)
	);

	float_type const max(
		std::max(
			abs1,
			abs2
		)
	);

	float_type const epsilon(
		0.0001f
	);

	if(
		max < epsilon
	)
	{
		CHECK(
			abs1
			<
			epsilon
		);

		CHECK(
			abs2
			<
			epsilon
		);
	}
	else
	{
		float_type const abs_diff(
			std::abs(
				_val1
				-
				_val2
			)
		);

		if(
			max > 1.f
		)
			CHECK(
				abs_diff
				/
				max
				<
				epsilon
			);
		else
			CHECK(
				abs_diff
				<
				epsilon
			);
	}
}

typedef
fcppt::either::object<
	alda::raw::stream::error,
	alda::raw::element_type<
		alda::bindings::float_
	>
>
either_result_type;

void
fuzzy_equal_either(
	either_result_type const &_left,
	either_result_type const &_right
)
{
	CHECK(
		fcppt::either::apply(
			[](
				alda::raw::element_type<
					alda::bindings::float_
				> const _inner_left,
				alda::raw::element_type<
					alda::bindings::float_
				> const _inner_right
			)
			{
				fuzzy_equal(
					_inner_left,
					_inner_right
				);

				return
					fcppt::unit{};
			},
			_left,
			_right
		).has_success()
	);
}

void
test_conversion(
	alda::raw::element_type<
		alda::bindings::float_
	> const _value
)
{
	std::stringstream stream;

	alda::serialization::write<
		alda::bindings::float_
	>(
		stream,
		_value
	);

	fuzzy_equal_either(
		alda::raw::make_generic<
			alda::raw::stream::istream,
			alda::bindings::float_
		>(
			stream
		),
		either_result_type{
			_value
		}
	);
}

}

TEST_CASE(
	"bindings::float",
	"[catch]"
)
{
	test_conversion(
		0.f
	);

	test_conversion(
		0.01f
	);

	test_conversion(
		-0.01f
	);

	test_conversion(
		-1.f
	);

	test_conversion(
		1.f
	);

	test_conversion(
		-10000.f
	);

	test_conversion(
		10000.f
	);

	/*
	fuzzy_equal(
		0.1f,
		0.01f
	);

	fuzzy_equal(
		1.f,
		2.f
	);*/
}

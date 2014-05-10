/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2012 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#include <alda/bindings/enum.hpp>
#include <alda/message/make_class.hpp>
#include <majutsu/composite.hpp>
#include <majutsu/make_role_tag.hpp>
#include <majutsu/role.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
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
	std::uint8_t
> enum_binding;

MAJUTSU_MAKE_ROLE_TAG(
	enum_role
);

typedef alda::message::make_class<
	majutsu::composite<
		boost::mpl::vector1<
			majutsu::role<
				enum_binding,
				enum_role
			>
		>
	>
> message;

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	alda_enum
)
{
FCPPT_PP_POP_WARNING

	BOOST_CHECK(
		message(
			enum_role{} =
				test_enum::value0
		).get<
			enum_role
		>()
		== test_enum::value0
	);

	BOOST_CHECK(
		message(
			enum_role{} =
				test_enum::value1
		).get<
			enum_role
		>()
		== test_enum::value1
	);
}

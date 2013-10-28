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


#ifndef ALDA_BINDINGS_STATIC_HPP_INCLUDED
#define ALDA_BINDINGS_STATIC_HPP_INCLUDED

#include <alda/bindings/array.hpp>
#include <alda/bindings/static_decl.hpp>
#include <majutsu/const_raw_pointer.hpp>
#include <majutsu/make.hpp>
#include <majutsu/needed_size.hpp>
#include <majutsu/place.hpp>
#include <majutsu/raw_pointer.hpp>
#include <majutsu/static_size.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace alda
{
namespace bindings
{

template<
	typename Type,
	typename Adapted
>
void
place(
	alda::bindings::static_<
		Type,
		Adapted
	> const *,
	Type const &_value,
	majutsu::raw_pointer const _mem
)
{
	majutsu::place<
		alda::bindings::array<
			typename
			Type::storage_type,
			Adapted
		>
	>(
		_value.storage(),
		_mem
	);
}

template<
	typename Type,
	typename Adapted
>
Type
make(
	alda::bindings::static_<
		Type,
		Adapted
	> const *,
	majutsu::const_raw_pointer const _mem
)
{
	return
		Type(
			majutsu::make<
				alda::bindings::array<
					typename
					Type::storage_type,
					Adapted
				>
			>(
				_mem
			)
		);
}

}
}

namespace majutsu
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type,
	typename Adapted
>
struct static_size<
	alda::bindings::static_<
		Type,
		Adapted
	>
>
:
majutsu::static_size<
	alda::bindings::array<
		typename
		Type::storage_type,
		Adapted
	>
>
{
};

FCPPT_PP_POP_WARNING

}

#endif

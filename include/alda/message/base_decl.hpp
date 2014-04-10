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


#ifndef ALDA_MESSAGE_BASE_DECL_HPP_INCLUDED
#define ALDA_MESSAGE_BASE_DECL_HPP_INCLUDED

#include <alda/detail/external_class_symbol.hpp>
#include <alda/detail/external_symbol.hpp>
#include <alda/message/base_fwd.hpp>
#include <alda/message/base_unique_ptr.hpp>
#include <majutsu/const_raw_pointer.hpp>
#include <majutsu/size_type.hpp>


namespace alda
{
namespace message
{

template<
	typename TypeEnum
>
class ALDA_DETAIL_EXTERNAL_CLASS_SYMBOL base
{
protected:
	ALDA_DETAIL_EXTERNAL_SYMBOL
	base();

	ALDA_DETAIL_EXTERNAL_SYMBOL
	base(
		base const &
	);

	ALDA_DETAIL_EXTERNAL_SYMBOL
	base &
	operator=(
		base const &
	);

	ALDA_DETAIL_EXTERNAL_SYMBOL
	base(
		base &&
	);

	ALDA_DETAIL_EXTERNAL_SYMBOL
	base &
	operator=(
		base &&
	);
public:
	typedef
	typename
	TypeEnum::type
	type_enum;

	typedef
	majutsu::const_raw_pointer
	const_raw_pointer;

	typedef
	majutsu::size_type
	size_type;

	typedef
	typename
	alda::message::base_unique_ptr<
		TypeEnum
	>
	unique_ptr;

	virtual
	~base() = 0;

	virtual
	type_enum
	type() const = 0;

	virtual
	const_raw_pointer
	data() const = 0;

	virtual
	size_type
	size() const = 0;

	virtual
	unique_ptr
	clone() const = 0;
};

}
}

#endif

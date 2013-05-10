#ifndef ALDA_BINDINGS_DETAIL_PUT_LENGTH_HPP_INCLUDED
#define ALDA_BINDINGS_DETAIL_PUT_LENGTH_HPP_INCLUDED

#include <alda//endianness.hpp>
#include <majutsu/const_raw_pointer.hpp>
#include <majutsu/needed_size.hpp>
#include <majutsu/raw_pointer.hpp>
#include <fcppt/truncation_check_cast.hpp>
#include <fcppt/algorithm/copy_n.hpp>
#include <fcppt/endianness/convert.hpp>


namespace alda
{
namespace bindings
{
namespace detail
{

template<
	typename Concept
>
void
put_length(
	Concept const *,
	typename Concept::type const &_value,
	majutsu::raw_pointer &_memory
)
{
	typedef typename
	Concept::length_type length_type;

	length_type const dest_sz(
		fcppt::endianness::convert(
			fcppt::truncation_check_cast<
				length_type
			>(
				majutsu::needed_size<
					Concept
				>(
					_value
				)
			),
			alda::endianness()
		)
	);

	fcppt::algorithm::copy_n(
		reinterpret_cast<
			majutsu::const_raw_pointer
		>(
			&dest_sz
		),
		sizeof(length_type),
		_memory
	);

	_memory += sizeof(length_type);
}

}
}
}

#endif

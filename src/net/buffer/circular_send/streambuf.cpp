//          Copyright Carl Philipp Reh 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <alda/net/buffer/circular_send/streambuf.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iosfwd>
#include <streambuf>
#include <fcppt/config/external_end.hpp>


alda::net::buffer::circular_send::streambuf::streambuf(
	alda::net::buffer::max_send_size const _size
)
:
	std::streambuf(),
	impl_{
		_size.get()
	}
{
}

alda::net::buffer::circular_send::streambuf::~streambuf()
{
}

alda::net::buffer::circular_send::streambuf::size_type
alda::net::buffer::circular_send::streambuf::space_left() const
{
	return
		impl_.capacity()
		-
		impl_.size();
}

alda::net::buffer::circular_send::streambuf::const_array_range
alda::net::buffer::circular_send::streambuf::send_part() const
{
	return
		impl_.array_two().second
		==
		0u
		?
			impl_.array_one()
		:
			impl_.array_two()
		;
}

void
alda::net::buffer::circular_send::streambuf::bytes_sent(
	size_type const _size
)
{
	impl_.erase(
		impl_.begin(),
		impl_.begin()
		+
		fcppt::cast::size<
			impl_type::difference_type
		>(
			fcppt::cast::to_signed(
				_size
			)
		)
	);
}

bool
alda::net::buffer::circular_send::streambuf::empty() const
{
	return
		impl_.empty();
}

alda::net::buffer::circular_send::streambuf::size_type
alda::net::buffer::circular_send::streambuf::capacity() const
{
	return
		impl_.capacity();
}

void
alda::net::buffer::circular_send::streambuf::clear()
{
	impl_.clear();
}

std::streamsize
alda::net::buffer::circular_send::streambuf::xsputn(
	char_type const *const _data,
	std::streamsize const _size
)
{
	std::streamsize const to_write(
		std::min(
			fcppt::cast::size<
				std::streamsize
			>(
				fcppt::cast::to_signed(
					this->space_left()
				)
			),
			_size
		)
	);

	impl_.insert(
		impl_.end(),
		_data,
		_data
		+
		to_write
	);

	return
		to_write;
}

alda::net::buffer::circular_send::streambuf::int_type
alda::net::buffer::circular_send::streambuf::overflow(
	int_type const _c
)
{
	if(
		this->space_left()
		==
		0u
	)
		return
			traits_type::eof();

	if(
		!traits_type::eq_int_type(
			_c,
			traits_type::eof()
		)
	)
		impl_.push_back(
			traits_type::to_char_type(
				_c
			)
		);

	return
		0;
}
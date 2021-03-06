//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef ALDA_RAW_STREAM_BIND_HPP_INCLUDED
#define ALDA_RAW_STREAM_BIND_HPP_INCLUDED

#include <alda/raw/stream/error.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace alda
{
namespace raw
{
namespace stream
{

template<
	typename Stream,
	typename Type,
	typename Function
>
inline
auto
bind(
	Type &&_value,
	Function const &_function
)
->
std::enable_if_t<
	!Stream::can_fail,
	decltype(
		_function(
			std::forward<
				Type
			>(
				_value
			)
		)
	)
>
{
	return
		_function(
			std::forward<
				Type
			>(
				_value
			)
		);
}

template<
	typename Stream,
	typename Type,
	typename Function
>
inline
auto
bind(
	fcppt::either::object<
		alda::raw::stream::error,
		Type
	> &&_value,
	Function const &_function
)
->
std::enable_if_t<
	Stream::can_fail,
	decltype(
		fcppt::either::bind(
			std::move(
				_value
			),
			_function
		)
	)
>
{
	return
		fcppt::either::bind(
			std::move(
				_value
			),
			_function
		);
}

}
}
}

#endif

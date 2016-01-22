//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef ALDA_BINDINGS_BOOL_HPP_INCLUDED
#define ALDA_BINDINGS_BOOL_HPP_INCLUDED

#include <alda/bindings/bool_decl.hpp>
#include <alda/bindings/unsigned.hpp>
#include <alda/raw/dispatch_type.hpp>
#include <alda/raw/element_type.hpp>
#include <alda/raw/make_generic.hpp>
#include <alda/raw/place.hpp>
#include <alda/raw/pointer.hpp>
#include <alda/raw/static_size.hpp>
#include <alda/raw/stream/bind.hpp>
#include <alda/raw/stream/reference.hpp>
#include <alda/raw/stream/result.hpp>
#include <alda/raw/stream/return.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace alda
{
namespace bindings
{

inline
void
place(
	alda::raw::dispatch_type<
		alda::bindings::bool_
	>,
	alda::raw::element_type<
		alda::bindings::bool_
	> const _value,
	alda::raw::pointer const _data
)
{
	alda::raw::place<
		alda::bindings::bool_::wrapped_type
	>(
		_value
		?
			fcppt::literal<
				alda::raw::element_type<
					alda::bindings::bool_::wrapped_type
				>
			>(
				1
			)
		:
			fcppt::literal<
				alda::raw::element_type<
					alda::bindings::bool_::wrapped_type
				>
			>(
				0
			)
		,
		_data
	);
}

template<
	typename Stream
>
alda::raw::stream::result<
	Stream,
	alda::bindings::bool_
>
make_generic(
	alda::raw::dispatch_type<
		alda::bindings::bool_
	>,
	alda::raw::dispatch_type<
		Stream
	>,
	alda::raw::stream::reference<
		Stream
	> _stream
)
{
	return
		alda::raw::stream::bind<
			Stream
		>(
			alda::raw::make_generic<
				Stream,
				alda::bindings::bool_::wrapped_type
			>(
				_stream
			),
			[](
				alda::raw::element_type<
					alda::bindings::bool_::wrapped_type
				> const _element
			)
			{
				return
					alda::raw::stream::return_<
						Stream
					>(
						_element
						!=
						fcppt::literal<
							alda::raw::element_type<
								alda::bindings::bool_::wrapped_type
							>
						>(
							0
						)
					);
			}
		);
}

}
}


namespace alda
{
namespace raw
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<>
struct static_size<
	alda::bindings::bool_
>
:
alda::raw::static_size<
	alda::bindings::bool_::wrapped_type
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif

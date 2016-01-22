//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef ALDA_MESSAGE_IS_RECORD_HPP_INCLUDED
#define ALDA_MESSAGE_IS_RECORD_HPP_INCLUDED

#include <alda/message/record_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace alda
{
namespace message
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Type
>
struct is_record
:
std::false_type
{
};

template<
	typename Id,
	typename Types
>
struct is_record<
	alda::message::record<
		Id,
		Types
	>
>
:
std::true_type
{
};

FCPPT_PP_POP_WARNING

}
}

#endif

//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef ALDA_RAW_DETAIL_INNER_TYPES_HPP_INCLUDED
#define ALDA_RAW_DETAIL_INNER_TYPES_HPP_INCLUDED

#include <alda/raw/element_type_tpl.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/element_to_label_tpl.hpp>
#include <fcppt/record/element_to_type_tpl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform.hpp>
#include <fcppt/config/external_end.hpp>


namespace alda
{
namespace raw
{
namespace detail
{

template<
	typename Types
>
using
inner_types
=
typename
boost::mpl::transform<
	Types,
	fcppt::record::element<
		fcppt::record::element_to_label_tpl<
			boost::mpl::_1
		>,
		alda::raw::element_type_tpl<
			fcppt::record::element_to_type_tpl<
				boost::mpl::_1
			>
		>
	>
>::type;

}
}
}

#endif

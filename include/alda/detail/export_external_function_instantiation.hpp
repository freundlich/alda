#ifndef ALDA_DETAIL_EXPORT_EXTERNAL_FUNCTION_INSTANTIATION_HPP_INCLUDED
#define ALDA_DETAIL_EXPORT_EXTERNAL_FUNCTION_INSTANTIATION_HPP_INCLUDED

#if defined(ALDA_EXTERNAL_INSTANTIATION)
#	if defined(ALDA_EXTERNAL_STATIC_LINK)
#		define ALDA_DETAIL_EXPORT_EXTERNAL_FUNCTION_INSTANTIATION
#	else
#		include <fcppt/export_function_instantiation.hpp>
#		define ALDA_DETAIL_EXPORT_EXTERNAL_FUNCTION_INSTANTIATION FCPPT_EXPORT_FUNCTION_INSTANTIATION
#	endif
#else
#	define ALDA_DETAIL_EXPORT_EXTERNAL_FUNCTION_INSTANTIATION
#endif

#endif
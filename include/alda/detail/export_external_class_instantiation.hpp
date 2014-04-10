#ifndef ALDA_DETAIL_EXPORT_EXTERNAL_CLASS_INSTANTIATION_HPP_INCLUDED
#define ALDA_DETAIL_EXPORT_EXTERNAL_CLASS_INSTANTIATION_HPP_INCLUDED

#if defined(ALDA_EXTERNAL_INSTANTIATION)
#	if defined(ALDA_EXTERNAL_STATIC_LINK)
#		define ALDA_DETAIL_EXPORT_EXTERNAL_CLASS_INSTANTIATION
#	else
#		include <fcppt/export_class_instantiation.hpp>
#		define ALDA_DETAIL_EXPORT_EXTERNAL_CLASS_INSTANTIATION FCPPT_EXPORT_CLASS_INSTANTIATION
#	endif
#else
#	define ALDA_DETAIL_EXPORT_EXTERNAL_CLASS_INSTANTIATION
#endif

#endif

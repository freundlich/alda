//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef ALDA_CALL_OBJECT_DECL_HPP_INCLUDED
#define ALDA_CALL_OBJECT_DECL_HPP_INCLUDED

#include <alda/call/default_callback.hpp>
#include <alda/call/object_fwd.hpp>
#include <alda/call/detail/base_fwd.hpp>
#include <alda/message/base_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/unique_ptr_decl.hpp>
#include <fcppt/enum/array_decl.hpp>
#include <fcppt/optional/object_decl.hpp>


namespace alda
{
namespace call
{

template<
	typename TypeEnum,
	typename Messages,
	typename Callee
>
class object
{
	FCPPT_NONCOPYABLE(
		object
	);

	typedef typename Callee::result_type result_type;

	typedef alda::call::detail::base<
		TypeEnum,
		Callee
	> base;
public:
	typedef alda::call::default_callback<
		TypeEnum,
		result_type
	> default_callback;

	typedef alda::message::base<
		TypeEnum
	> message_base;

	object();

	~object();

	result_type
	operator()(
		message_base const &,
		Callee &,
		default_callback const &
	) const;
private:
	typedef
	fcppt::unique_ptr<
		base
	>
	base_unique_ptr;

	typedef
	fcppt::optional::object<
		base_unique_ptr
	>
	optional_base_unique_ptr;

	typedef
	fcppt::enum_::array<
		typename
		TypeEnum::type,
		optional_base_unique_ptr
	>
	instance_array;

	instance_array const instances_;
};

}
}

#endif

//          Copyright Carl Philipp Reh 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <alda/exception.hpp>
#include <alda/raw/stream/failure.hpp>
#include <fcppt/text.hpp>


alda::raw::stream::failure::failure()
:
	alda::exception{
		FCPPT_TEXT("stream failure")
	}
{
}
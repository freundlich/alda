#include <alda/net/buffer/circular_send/object.hpp>
#include <alda/net/buffer/circular_send/sink.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


alda::net::buffer::circular_send::sink::sink(
	alda::net::buffer::circular_send::object &_container
)
:
	container_(
		_container
	)
{
}

std::streamsize
alda::net::buffer::circular_send::sink::write(
	char const *const _data,
	std::streamsize const _size
)
{
	// write nothing if there is not enough space
	if(
		static_cast<
			std::streamsize
		>(
			container_.space_left()
		)
		< _size
	)
		return -1;

	container_.get().insert(
		container_.get().end(),
		_data,
		_data + _size
	);

	return
		_size;
}
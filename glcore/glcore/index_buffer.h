#pragma once

#include "gl_buffer.h"

namespace glcore
{
	class index_buffer : public gl_buffer
	{
	public:
		index_buffer() = default;
		index_buffer(std::uint32_t* indices, std::uint32_t size);
		~index_buffer();

	public:
		virtual void bind() const override;
		virtual void unbind() const override;
	};
}
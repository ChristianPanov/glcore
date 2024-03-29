#include "vertex_buffer_layout.h"

namespace glcore
{
	vertex_buffer_layout::vertex_buffer_layout(std::initializer_list<vertex_attribute> attributes)
		: m_attributes{ attributes }
	{
		for (auto& [type, name, offset] : m_attributes)
		{
			offset = m_stride;
			m_stride += shader_data_type::size(type);
		}
	}

	std::uint32_t vertex_buffer_layout::stride() const
	{
		return m_stride;
	}

	const std::vector<vertex_attribute>& vertex_buffer_layout::data() const
	{
		return m_attributes;
	}
}

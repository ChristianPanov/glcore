#pragma once

#include <string>
#include <vector>

namespace glcore
{
	enum class shader_type {
		vertex,
		fragment,
		tesselation_control,
		tesselation_evaluation,
		geometry
	};

	struct shader_t
	{
		shader_type type;
		std::string_view path;
	};

	class shader_program
	{
	public:
		shader_program() = default;
		shader_program(std::initializer_list<shader_t> shaders);
		~shader_program();

	public:
		void bind() const;
		void unbind() const;
		std::uint32_t program();

	public:
		shader_t& operator[](std::size_t index);
		const shader_t& operator[](std::size_t index) const;

	private:
		std::uint32_t create_program();
		std::uint32_t compile(shader_type t_shader_type, std::string_view source);
		std::uint32_t to_gl_type(shader_type t_shader_type);
		void link_and_validate(std::uint32_t program);
		bool is_valid(std::uint32_t id);
		std::string parse_code(std::string_view path);

	private:
		std::uint32_t m_id{};
		std::vector<shader_t> m_shaders;
	};
}
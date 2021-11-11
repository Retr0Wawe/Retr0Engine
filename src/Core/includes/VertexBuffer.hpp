#ifndef VERTEX_BUF_H
#define VERTEX_BUF_H

#include <glad/glad.h>
#include "Log.hpp"

namespace Retr0Engine
{
	class VertexBuffer
	{
	private:
		GLuint vbo;
	public:
		enum class DrawMethods
		{
			STATIC,
			DYNAMIC,
			STREAM
		};
	public:
		VertexBuffer(const void* data,const int size, DrawMethods draw_method);

		virtual ~VertexBuffer();

	public:
		GLenum draw_method(DrawMethods method) const;

		void bind() const;

		static void unbind();
	};
}

#endif 
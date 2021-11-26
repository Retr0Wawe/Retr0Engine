#include "VertexBuffer.hpp"

namespace Retr0Engine
{
	VertexBuffer::VertexBuffer(const void* data, const int size, DrawMethods method)
	{
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, size, data, draw_method(method));
	}

	VertexBuffer::VertexBuffer(const VertexBuffer& a)
	{
		this->vbo = a.vbo;
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &vbo);
	}

	VertexBuffer& VertexBuffer::operator=(const VertexBuffer& a)
	{
		this->vbo = a.vbo;
		return *this;
	}

	GLenum VertexBuffer::draw_method(DrawMethods method) const
	{
		switch (method)
		{
			case DrawMethods::STATIC: return GL_STATIC_DRAW;
		
			case DrawMethods::DYNAMIC: return GL_DYNAMIC_DRAW;
		
			case DrawMethods::STREAM: return GL_STREAM_DRAW;
		}

		LOG_CRITICAL("Error! Unknown render parameter!");
		return GL_STREAM_DRAW;
	}

	void VertexBuffer::bind() const 
	{
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
	}

	void VertexBuffer::unbind() 
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}
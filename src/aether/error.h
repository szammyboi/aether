#pragma once

#include <exception>
#include <string>


namespace Aether {
	enum class ErrorType
	{
		CORE = 0,
		ENGINE
	};

	template <ErrorType T>
	class Exception : public std::exception
	{
	public:
		Exception(const char* msg)
			: m_Message(msg) {}

		inline const char* what() const throw()
			{ return m_Message.c_str(); }
	private:
		std::string m_Message;
	};

	typedef Exception<ErrorType::CORE> CoreException;
	typedef Exception<ErrorType::ENGINE> EngineException;
}

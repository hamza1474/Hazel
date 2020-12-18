#include "hzpch.h"
#include "Application.h"

#include "Hazel/Log.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Hazel
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}

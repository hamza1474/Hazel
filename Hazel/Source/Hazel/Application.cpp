#include "Application.h"

#include "Hazel/Log.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Hazel
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		// Testing Log System

		HZ_CORE_INFO("<<<<<<<<<<<<<Testing Log Systems>>>>>>>>>>>>>>>");
		
		HZ_CORE_INFO("Testing Core Log System.......\n.\n.\n.");
		HZ_CORE_TRACE("Test Core Trace.....OK");
		HZ_CORE_INFO("Test Core Info.....OK");
		HZ_CORE_WARN("Test Core Warn.....OK");
		HZ_CORE_ERROR("Test Core Error.....OK");
		HZ_CORE_CRITICAL("Test Core Critical.....OK");
		HZ_CORE_INFO("........");
		HZ_CORE_INFO("Testing Client Log System.......\n.\n.\n.");
		HZ_TRACE("Test Client Trace.....OK");
		HZ_INFO("Test Client Info.....OK");
		HZ_WARN("Test Client Warn.....OK");
		HZ_ERROR("Test Client Error.....OK");
		HZ_CRITICAL("Test Client Critical.....OK");

		HZ_CORE_INFO("....All OK");
		HZ_CORE_INFO("........");
		HZ_CORE_INFO("<<<<<<<<<<<<<Testing Event System>>>>>>>>>>>>>>>");
		HZ_CORE_INFO("Testing Window Resize Event...\n.\n.\n.");
		WindowResizeEvent e(1280, 720);
		HZ_TRACE(e);
		HZ_CORE_INFO("....All OK");
		HZ_CORE_INFO("........");
		while (true)
		{
		}
	}
}

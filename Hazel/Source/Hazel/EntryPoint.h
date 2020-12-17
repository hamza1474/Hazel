#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	Hazel::Log::Init();
	HZ_CORE_INFO("Loading Hazel");
	HZ_CORE_TRACE("Trace Error!!!");
	HZ_CORE_CRITICAL("Critical Core Error");

	int a = 5;

	HZ_ERROR("Client Error at {0}", a);
	
	auto App = Hazel::CreateApplication();
	App->Run();
	delete App;
}

#endif
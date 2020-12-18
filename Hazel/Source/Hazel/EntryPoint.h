#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	Hazel::Log::Init();
	
	auto App = Hazel::CreateApplication();
	App->Run();
	delete App;
}

#endif
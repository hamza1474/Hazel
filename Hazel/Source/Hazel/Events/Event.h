#pragma once

#include "Hazel/Core.h"

#include <string>
#include <functional>

namespace Hazel
{
	// Events in Hazel block the program right now
	
	// TODO: Buffer Events and handle them later in handling
	// stage without interrupting the whole program
	
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication     = BIT(0),
		EventCategoryInput           = BIT(1),
		EventCategoryKeyboard        = BIT(2),
		EventCategoryMouse           = BIT(3),
		EventCategoryMouseButton     = BIT(4)
	};

#define EVENT_CLASS_TYPE(Type) static EventType GetStaticType() { return EventType::##Type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #Type; }

#define EVENT_CLASS_CATEGORY(Category) virtual int GetCategoryFlags() const override { return Category; }
	
	class HAZEL_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory Category)
		{
			return GetCategoryFlags() & Category;
		}
	protected:
		bool m_Handled;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			:m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> Func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = Func(*(*T)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
		
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}

#ifndef SIMPLE_EXAMPLE_INCLUDE_CORE_EVENT_TYPE_HPP
#define SIMPLE_EXAMPLE_INCLUDE_CORE_EVENT_TYPE_HPP

#include <cstdint>

namespace core {

enum class EventType : std::uint8_t { OBJECT_FOUND = 0, OBJECT_LOST = 1 };

class Event {
  public:
    Event(EventType type) : type_{type}, data_{nullptr}
    {
    }

    Event(EventType type, void* data) : type_{type}, data_{data}
    {
    }

    EventType getType() const
    {
        return type_;
    }

    void* getData() const
    {
        return data_;
    }

  private:
    EventType type_;
    void* data_;
};

}  // namespace core

#endif  // SIMPLE_EXAMPLE_INCLUDE_CORE_EVENT_TYPE_HPP

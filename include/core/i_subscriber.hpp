#ifndef SIMPLE_EXAMPLE_INCLUDE_CORE_I_SUBSCRIBER_HPP
#define SIMPLE_EXAMPLE_INCLUDE_CORE_I_SUBSCRIBER_HPP

#include "core/event_type.hpp"

namespace core {

class ISubscriber {
  public:
    virtual void onEvent(Event event) = 0;
    virtual ~ISubscriber() = default;
};

}  // namespace core

#endif  // SIMPLE_EXAMPLE_INCLUDE_CORE_I_SUBSCRIBER_HPP

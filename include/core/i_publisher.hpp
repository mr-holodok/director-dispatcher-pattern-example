#ifndef SIMPLE_EXAMPLE_INCLUDE_CORE_I_PUBLISHER_HPP
#define SIMPLE_EXAMPLE_INCLUDE_CORE_I_PUBLISHER_HPP

#include "core/event_type.hpp"

namespace core {

class IPublisher {
  public:
    virtual void emitEvent(Event event) = 0;
    virtual ~IPublisher() = default;
};

}  // namespace core

#endif  // SIMPLE_EXAMPLE_INCLUDE_CORE_I_PUBLISHER_HPP

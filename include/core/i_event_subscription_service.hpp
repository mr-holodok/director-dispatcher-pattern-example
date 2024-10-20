#ifndef SIMPLE_EXAMPLE_INCLUDE_CORE_I_EVENT_SUBSCRIPTION_SERVICE_HPP
#define SIMPLE_EXAMPLE_INCLUDE_CORE_I_EVENT_SUBSCRIPTION_SERVICE_HPP

#include "core/event_type.hpp"
#include "core/i_subscriber.hpp"

namespace core {

class IEventSubscriptionService {
  public:
    virtual void addSubscription(ISubscriber* subscriber, EventType event) = 0;
    virtual void removeSubscription(ISubscriber* subscriber, EventType event) = 0;
    virtual ~IEventSubscriptionService() = default;
};

}  // namespace core

#endif  // SIMPLE_EXAMPLE_INCLUDE_CORE_I_EVENT_SUBSCRIPTION_SERVICE_HPP

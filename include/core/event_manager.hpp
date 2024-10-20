#ifndef SIMPLE_EXAMPLE_INCLUDE_CORE_EVENT_MANAGER_HPP
#define SIMPLE_EXAMPLE_INCLUDE_CORE_EVENT_MANAGER_HPP

#include <map>
#include <vector>

#include "core/i_event_subscription_service.hpp"
#include "core/i_publisher.hpp"
#include "core/i_subscriber.hpp"

namespace core {

class EventManager : public IPublisher, public IEventSubscriptionService {
  public:
    EventManager() = default;
    ~EventManager() override = default;

    void emitEvent(Event event) override;
    void addSubscription(ISubscriber* subscriber, EventType event) override;
    void removeSubscription(ISubscriber* subscriber, EventType event) override;

  private:
    std::map<EventType, std::vector<ISubscriber*>> subscriptions_;
};

}  // namespace core

#endif  // SIMPLE_EXAMPLE_INCLUDE_CORE_EVENT_MANAGER_HPP

#include "core/event_manager.hpp"

#include <algorithm>

namespace core {

void EventManager::addSubscription(ISubscriber* subscriber, EventType event)
{
    if (subscriptions_.find(event) == subscriptions_.end()) {
        subscriptions_[event] = std::vector<ISubscriber*>();
    }
    if (std::find(subscriptions_[event].begin(), subscriptions_[event].end(), subscriber) ==
        subscriptions_[event].end()) {
        subscriptions_[event].push_back(subscriber);
    }
}

void EventManager::removeSubscription(ISubscriber* subscriber, EventType event)
{
    if (subscriptions_.find(event) != subscriptions_.end()) {
        subscriptions_[event].erase(std::remove(subscriptions_[event].begin(), subscriptions_[event].end(), subscriber),
                                    subscriptions_[event].end());
    }
}

void EventManager::emitEvent(Event event)
{
    if (subscriptions_.find(event.getType()) != subscriptions_.end()) {
        for (auto subscriber : subscriptions_[event.getType()]) {
            subscriber->onEvent(event);
        }
    }
}

}  // namespace core

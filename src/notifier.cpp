#include "app/notifier.hpp"

#include <iostream>

namespace app {

Notifier::Notifier(core::IEventSubscriptionService* event_subscription_service)
{
    event_subscription_service->addSubscription(this, core::EventType::OBJECT_FOUND);
    event_subscription_service->addSubscription(this, core::EventType::OBJECT_LOST);
}

void Notifier::onEvent(core::Event event)
{
    switch (event.getType()) {
        case core::EventType::OBJECT_FOUND:
            std::cout << "Got event with a type: OBJECT_FOUND." << std::endl;
            break;
        case core::EventType::OBJECT_LOST:
            std::cout << "Got event with a type: OBJECT_LOST." << std::endl;
            break;
        default:
            break;
    }
}

}  // namespace app
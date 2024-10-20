#ifndef SIMPLE_EXAMPLE_INCLUDE_APP_NOTIFIER_HPP
#define SIMPLE_EXAMPLE_INCLUDE_APP_NOTIFIER_HPP

#include "core/i_event_subscription_service.hpp"
#include "core/i_subscriber.hpp"

namespace app {

class Notifier final : public core::ISubscriber {
  public:
    Notifier(core::IEventSubscriptionService* event_subscription_service);

    void onEvent(core::Event event) final;
};

}  // namespace app

#endif  // SIMPLE_EXAMPLE_INCLUDE_APP_NOTIFIER_HPP
#ifndef SIMPLE_EXAMPLE_INCLUDE_CORE_AN_EVENT_PRODUCER
#define SIMPLE_EXAMPLE_INCLUDE_CORE_AN_EVENT_PRODUCER

#include "core/i_publisher.hpp"

namespace core {

class AnEventProducer {
  public:
    AnEventProducer(IPublisher* publisher) : publisher_(publisher)
    {
    }

    void setPublisher(IPublisher* publisher)
    {
        publisher_ = publisher;
    }

    IPublisher* getPublisher()
    {
        return publisher_;
    }

    void produceEvent(Event event)
    {
        publisher_->emitEvent(event);
    }

  private:
    IPublisher* publisher_;
};

}  // namespace core

#endif  // SIMPLE_EXAMPLE_INCLUDE_CORE_AN_EVENT_PRODUCER

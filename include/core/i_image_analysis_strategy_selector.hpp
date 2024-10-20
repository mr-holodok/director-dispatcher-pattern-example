#ifndef SIMPLE_EXAMPLE_INCLUDE_CORE_I_IMAGE_ANALYSIS_STRATEGY_SELECTOR_HPP
#define SIMPLE_EXAMPLE_INCLUDE_CORE_I_IMAGE_ANALYSIS_STRATEGY_SELECTOR_HPP

#include "core/event_type.hpp"
#include "core/i_image_analysis_strategy.hpp"

namespace core {

class IImageAnalysisStrategySelector {
  public:
    virtual IImageAnalysisStrategy* selectStrategyForEvent(Event event) = 0;
    virtual IImageAnalysisStrategy* getDefaultStrategy() = 0;
    virtual ~IImageAnalysisStrategySelector() = default;
};

}  // namespace core

#endif  // SIMPLE_EXAMPLE_INCLUDE_CORE_I_IMAGE_ANALYSIS_STRATEGY_SELECTOR_HPP

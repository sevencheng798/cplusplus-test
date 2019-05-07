/**
 * Creator 2019-05-07
 */

#pragma once

#include <memory>

namespace sampleCXX {
namespace common {

template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

} // namespace common
} // namespace sampleCXX

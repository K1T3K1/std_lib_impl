#ifndef FUNCTIONAL_H_
#define FUNCTIONAL_H_

#include <memory>

namespace _std {

template <class T>
class Function;

template <typename Ret, typename... Params>
struct Function<Ret(Params...)> {
  Function(Ret (*f)(Params...)) : callable{std::make_unique<callable_impl<Ret (*)(Params...)>>(f)} {}

  Ret operator()(Params... params) {
    return callable->call(params...);
  }

 private:
  struct callable_interface {
    virtual Ret call(Params...) = 0;
    virtual ~callable_interface() = default;
  };

  template <typename Callable>
  struct callable_impl : callable_interface {
    callable_impl(Callable callable_) : callable{std::move(callable_)} {}

    // std::invoke impl
    Ret call(Params... params) { return callable(params...); }
    Callable callable;
  };

  std::unique_ptr<callable_interface> callable;
};
}  // namespace _std
#endif  // FUNCTIONAL_H_
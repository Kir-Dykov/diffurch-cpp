#pragma once
#include "../solver.hpp"
namespace Equation {
struct Linear1 : Solver<Linear1> {

  double k;

  Linear1(double k_ = -1.) : k(k_) {};

  static constexpr auto t = State::TimeVariable();
  static constexpr auto x = State::Variable<0>();

  static const bool ic_is_true_solution = true;

  auto get_lhs() { return State::Vector(k * x); }
  auto get_ic() { return State::Vector(exp(k * t)); }

  std::string repr(bool latex = true) {
    std::string kk = (k == 1 ? "" : k == -1 ? "-" : std::format("{:.3g}", k));
    if (latex)
      return "$\\dot x = " + kk + " x$";
    else
      return "x' = " + kk + "x";
  }
  /*auto get_events() { return Events(StepEvent(std::make_tuple(t, x))); }*/
};
} // namespace Equation

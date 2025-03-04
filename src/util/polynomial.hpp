#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
namespace diffurch {
template <size_t order, size_t degree>
constexpr std::array<double, degree - order + 1> derivative_coefficients() {
  std::array<double, degree - order + 1> C;
  for (int i = 0; i <= degree - order; i++) {
    C[i] = 1.;
    for (double j = i + 1; j <= i + order; j++) {
      C[i] *= j;
    }
  }
  return C;
}

template <size_t degree> class Polynomial {
private:
  std::array<double, degree + 1> coefs;

public:
  constexpr Polynomial(const std::array<double, degree + 1> &coefs_)
      : coefs(coefs_) {};

  template <typename... Args>
  constexpr Polynomial(Args... args) : coefs({args...}){};
  /*constexpr Polynomial(std::initializer_list<double> list) : coefs(list) {};*/ // doesn't work with constexpr for some reason

  // performance can be improved:
  // derivative coefficeients can be precalculated
  template <size_t order = 0> constexpr double eval(double theta) const {
    if constexpr (order > degree) {
      return 0;
    }
    const static std::array<double, degree - order + 1> d_coefs =
        derivative_coefficients<order, degree>();
    double res = coefs[degree] * d_coefs[degree - order];
    for (int j = degree - 1; j >= static_cast<int>(order); j--) {
      res *= theta;
      res += coefs[j] * d_coefs[j - order];
    }
    // double res = 0r;
    // double power = 1r;
    // for (int j = 0; j <= degree - order; j++) {
    //     res += power * coefs[j+order]*d_coefs[j];
    //     power *= theta;
    // }
    return res;
  }
};

template <size_t order = 0, size_t n, size_t k>
std::array<double, n> eval_array(const std::array<Polynomial<k>, n> &arr,
                                 double theta) {
  std::array<double, n> result;
  std::transform(arr.begin(), arr.end(), result.begin(), [&theta](auto poly) {
    return poly.template eval<order>(theta);
  });
  return result;
}
} // namespace diffurch

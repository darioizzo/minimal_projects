
#ifndef NAIVE_UDXS_HPP
#define NAIVE_UDXS_HPP

#include <boost/numeric/conversion/cast.hpp>
#include <pagmo/population.hpp>
#include <pagmo/s11n.hpp>
#include <pagmo/types.hpp>
#include <pybind11/pybind11.h>  

// UDP
struct naive_udp {
  // Implementation of the objective function.
  pagmo::vector_double fitness(const pagmo::vector_double &dv) const {
    return {dv[0]};
  }
  // Implementation of the box bounds.
  std::pair<pagmo::vector_double, pagmo::vector_double> get_bounds() const {
    return {{0.}, {1.}};
  }
  // Serialization
  template <typename Archive> void serialize(Archive &ar, unsigned) {}
};

// UDA
struct naive_uda {
  // Implementation of the objective function.
  pagmo::population evolve(const pagmo::population &pop) const { return pop; }
  // Serialization
  template <typename Archive> void serialize(Archive &ar, unsigned){};
};

#endif
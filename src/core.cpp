#include <iostream>
#include <pagmo/population.hpp>
#include <pybind11/pybind11.h>

#include "naive_converters.hpp"
#include "naive_udxs.hpp"
#include "pickle_support.hpp"

namespace py = pybind11;

struct extracting_uda {
  // Implementation of the objective function.
  pagmo::population evolve(const pagmo::population &pop) const {
    const auto &prob = pop.get_problem();
    auto upd_ptr = prob.extract<py::object>();
    if (!upd_ptr) {
      std::cout << "Cannot convert to py::object" << std::endl;
      throw 666;
    }
    return pop;
  }
  // Serialization
  template <typename Archive> void serialize(Archive &ar, unsigned){};
};

PYBIND11_MODULE(core, m) {
  // Converters tests
  m.def("test_population_converters", &test_population_converters);
  // UDA to test for the extract from pythonic object
  py::class_<extracting_uda> extracting_uda_(m, "extracting_uda");
  extracting_uda_.def(py::init<>())
      .def("evolve", &extracting_uda::evolve)
      .def(py::pickle(&udx_pickle_getstate<extracting_uda>,
                      &udx_pickle_setstate<extracting_uda>));         
  // Naive UDXs
  py::class_<naive_udp> naive_udp_(m, "naive_udp");
  naive_udp_.def(py::init<>())
      .def("fitness", &naive_udp::fitness)
      .def("get_bounds", &naive_udp::get_bounds)
      .def(py::pickle(&udx_pickle_getstate<naive_udp>,
                      &udx_pickle_setstate<naive_udp>));
  py::class_<naive_uda> naive_uda_(m, "naive_uda");
  naive_uda_.def(py::init<>())
      .def("evolve", &naive_uda::evolve)
      .def(py::pickle(&udx_pickle_getstate<naive_uda>,
                      &udx_pickle_setstate<naive_uda>));
}
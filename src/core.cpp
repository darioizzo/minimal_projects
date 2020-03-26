#include <iostream>
#include <pagmo/population.hpp>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

struct extracting_uda
{
  // Implementation of the objective function.
  pagmo::population evolve(const pagmo::population &pop) const
  {
    const auto &prob = pop.get_problem();
    auto upd_ptr = prob.extract<py::object>();
    if (!upd_ptr)
    {
      std::cout << "Cannot convert to py::object" << std::endl;
      throw 666;
    }
    return pop;
  }
  // Serialization
  template <typename Archive>
  void serialize(Archive &ar, unsigned){};
};

bool inner_is_pyobject(const pagmo::problem &p)
{
  auto retval = p.get_type_index() == std::type_index(typeid(py::object));
  return retval;
}

PYBIND11_MODULE(core, m)
{
  // Miscellanea
  m.def("inner_is_pyobject", &inner_is_pyobject);
}
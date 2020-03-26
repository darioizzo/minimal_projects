#include <iostream>
#include <pagmo/population.hpp>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

bool is_pyobject(const pagmo::problem &p)
{
  auto retval = p.get_type_index() == std::type_index(typeid(py::object));
  return retval;
}

bool can_extract_pyobject(const pagmo::problem &p)
{
  auto upd_ptr = p.extract<py::object>();
  if (!upd_ptr)
  {
    return false;
  }
  else
  {
    return true;
  }
}

PYBIND11_MODULE(core, m)
{
  m.def("is_pyobject", &is_pyobject);
  m.def("can_extract_pyobject", &can_extract_pyobject);
}
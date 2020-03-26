#ifndef PICKLE_SUPPORT_HPP
#define PICKLE_SUPPORT_HPP

#include <boost/numeric/conversion/cast.hpp>
#include <iostream>
#include <pagmo/s11n.hpp>
#include <pybind11/pybind11.h>

namespace py = pybind11;

// Serialization support
template <typename UDX> inline py::tuple udx_pickle_getstate(const UDX &udx) {
  // The idea here is that first we extract a char array
  // into which a has been serialized, then we turn
  // this object into a Python bytes object and return that.
  std::ostringstream oss;
  {
    boost::archive::binary_oarchive oarchive(oss);
    oarchive << udx;
  }
  auto s = oss.str();
  return py::make_tuple(
      py::bytes(s.data(), boost::numeric_cast<py::size_t>(s.size())));
}

template <typename UDX> inline UDX udx_pickle_setstate(py::tuple state) {
  // Similarly, first we extract a bytes object from the Python state,
  // and then we build a C++ string from it. The string is then used
  // to deserialized the object.
  if (py::len(state) != 1) {
    std::cout << "Weird state length in udx_pickle_setstate" << std::endl;
    throw 667;
  }

  auto ptr = PyBytes_AsString(state[0].ptr());
  if (!ptr) {
    std::cout << "Weird state content in udx_pickle_setstate" << std::endl;
    throw 668;
  }

  std::istringstream iss;
  iss.str(std::string(ptr, ptr + py::len(state[0])));
  UDX udx;
  {
    boost::archive::binary_iarchive iarchive(iss);
    iarchive >> udx;
  }

  return udx;
}

#endif
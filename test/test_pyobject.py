import pygmo
import core
class python_prob:
    def fitness(self, dv):
        return [dv[0]]
    def get_bounds(self):
        return ([0],[1])

print("Is inner a py::object: ", core.is_pyobject( pygmo.problem(python_prob())))
print("Can I extract a py::object from pagmo::problem: ", core.can_extract_pyobject( pygmo.problem(python_prob())))


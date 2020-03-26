import pygmo
import core
class python_prob:
    def fitness(self, dv):
        return [dv[0]]
    def get_bounds(self):
        return ([0],[1])

print("Result: ", core.inner_is_pyobject(pygmo.problem(python_prob())))


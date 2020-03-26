import pygmo
import core
class python_prob:
    def fitness(self, dv):
        return [dv[0]]
    def get_bounds(self):
        return ([0],[1])


uda = core.extracting_uda()    
algo = pygmo.algorithm(uda)
pybind11_prob = pygmo.problem(core.naive_udp())
print("Result pybind11 converted udp: ", core.is_pyobject(pybind11_prob))
print("Result python udp: ", core.is_pyobject( pygmo.problem(python_prob())))


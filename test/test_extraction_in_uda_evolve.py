import pygmo
import core
uda = core.extracting_uda()    
algo = pygmo.algorithm(uda)
pop = pygmo.population(core.naive_udp(), 20)

try:
    algo.evolve(pop)
except:
    print("Epic fail: an exception was raised in the algo evolve!!")
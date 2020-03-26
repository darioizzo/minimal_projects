import pygmo
import core
uda = core.extracting_uda()    
algo = pygmo.algorithm(uda)
pop = pygmo.population(pygmo.null_problem(), 20)
algo.evolve(pop)

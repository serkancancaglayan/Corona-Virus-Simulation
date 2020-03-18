#include "person.h"
typedef struct{
    Person * persons;
    size_t population_size;
    size_t number_of_infected;
}Population;

Population * createPopulation(size_t population_size);
void draw_population(Population * p, SDL_Renderer * renderer);
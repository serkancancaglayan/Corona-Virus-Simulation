#include "person.h"
#include <stdlib.h>
#include <SDL2/SDL_ttf.h>
typedef struct{
    Person * persons;
    size_t population_size; 
    size_t number_of_infected;
}Population;

Population * create_population(size_t population_size);
void draw_population(Population * p, SDL_Renderer * renderer);
void update_population(Population *p);
void free_population(Population *p);
float rand_float(float min, float max,float seed);

#include "population.h"
Population * create_population(size_t population_size){
    Population * population = (Population *)malloc(sizeof(Population));
    population->persons = (Person *)malloc(sizeof(Person) * population_size);
    population->population_size = population_size;
    population->number_of_infected = 0;
    for(int i = 0; i < population_size; i++){
        srand(i);
        float x_pos = rand() % (WindowWidth - default_width);
        float y_pos = rand() % (WindowHeight - default_height);
        int age = rand() % 100;
        population->persons[i] = *(create_person(age, x_pos, y_pos));
    }
    return population;
}

void draw_population(Population * p, SDL_Renderer * renderer){
    for(int i = 0; i < p->population_size; i++){
        draw_person(&p->persons[i], renderer);
    }
}

void update_population(Population *p){
    for(int i = 0; i < p->population_size; i++){
        if(p->persons[i].is_infected && !p->persons[i].is_checked){
            p->number_of_infected++;
            check_infected(&p->persons[i]);
        }
    }
}
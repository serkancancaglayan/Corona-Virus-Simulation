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

void check_infections_population(Population *p){
    for(int i = 0; i < p->population_size; i++){
        if(p->persons[i].is_infected){
            int age = p->persons[i].age;
            /* 0 - 9 years old --> no fatalities
               10 - 39 years old --> %0.2
               40 - 49 years old --> %0.4
               50 - 59 years old --> %1.3
               60 - 69 years old --> %3.6
               70 - 79 years old --> %8.0
               80+ years old --> %14.8
            */
            float death_rate = 100 *((float) rand() / (float)RAND_MAX);
            if(age >= 0 && age <= 9){
                continue;
            }
            else if(age >= 10 && age <= 39){
                if(death_rate <= 0.2){
                    p->persons[i].isAlive = 0;
                }
            }
            else if(age >= 40 && age <= 49){
                if(death_rate <= 0.4){
                    p->persons[i].isAlive = 0;
                }
            }
            else if(age >= 50 && age <= 59){
                if(death_rate <= 1.3){
                    p->persons[i].isAlive = 0;
                }
            }
            else if(age >= 60 && age <= 69){
                if(death_rate <= 3.6){
                    p->persons[i].isAlive = 0;
                }
            }
            else if(age >= 70 && age <= 79){
                if(death_rate <= 8.0){
                    p->persons[i].isAlive = 0;
                }
            }
            else{
                if(death_rate <= 14.8){
                    p->persons[i].isAlive = 0;
                }
            }
        }
    }
}
void update_population(Population *p){
    check_infections_population(p);
}
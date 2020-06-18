#include "population.h"
#include <time.h>
Population * create_population(size_t population_size){
    Population * population = (Population *)malloc(sizeof(Population));
    population->persons = (Person *)malloc(sizeof(Person) * population_size);
    population->population_size = population_size;
    population->number_of_infected = 0;
    for(int i = 0; i < population_size; i++){
        srand(i * time(NULL));
        float x_pos = rand() % (WindowWidth - default_width);
        float y_pos = rand() % (WindowHeight - default_height);
        int age = rand() % 100;
        population->persons[i] = *(create_person(age, x_pos, y_pos));
    }
    //starting with 1 infected
    population->persons[0].is_infected = 1;
    return population;
}

void draw_population(Population * p, SDL_Renderer * renderer){
    /* not working
    //rendering infected count text
    char count[100];
    sprintf(count, "%d", (int)p->number_of_infected);
    printf("%s\n",count);

    TTF_Font * font = TTF_OpenFont("Sans.ttf",36);
    SDL_Color Whiteish = {200, 200, 200};
    SDL_Surface * message_surface = TTF_RenderText_Solid(font, count, Whiteish);
    SDL_Texture * message_texture = SDL_CreateTextureFromSurface(renderer, message_surface);

    SDL_Rect message_rect = {0, 0, 200, 100};
    SDL_RenderCopy(renderer, message_texture, NULL, &message_rect);
    */

    //drawing persons
    for(int i = 0; i < p->population_size; i++){
        draw_person(&p->persons[i], renderer);
    }
}

float rand_float(float min, float max,float seed){
    srand(seed);
    float scale = rand() / (float) RAND_MAX;
    return min + scale * ( max - min );
}

void update_population(Population *p){
    for(int i = 0; i < p->population_size; i++){
        // moving persons at random directions
        float rand_direction_x = rand_float(-10, 10, i);
        float rand_direction_y = rand_float(-10, 10, rand_direction_x);
        move_person(&p->persons[i], delta_time, rand_direction_x, rand_direction_y);
    

        //checking infections
        for(int j = 0; j < p->population_size; j++){
            if(i != j){
                if(infection(&p->persons[i], &p->persons[j])){
                    check_infected(&p->persons[i]);
                }
            }
        }
    }
}

void free_population(Population *p){    
    free(p->persons);
    free(p);
}

#include "person.h"
Person * create_person(int age, float x_pos, float y_pos){
    Person * p = malloc(sizeof(Person));
    p->age = age;
    p->x_pos = x_pos;
    p->y_pos = y_pos;
    p->is_infected = 0;
    p->isAlive = 1;
    return p;
}

void move_person(Person * p, float dt,int direction){
     //direction --> -1 or 1
    p->x_pos += default_vel_x * dt * direction;
    p->y_pos += default_vel_y *dt * direction;
}
void draw_person(Person *p, SDL_Renderer * renderer){
    if(p->isAlive){
        SDL_Rect * rect = (SDL_Rect *)malloc(sizeof(SDL_Rect));
        rect->x = (int)p->x_pos;
        rect->y = (int)p->y_pos;
        rect->w = 20;
        rect->h = 20;
        //draw red if person is infected, otherwise white
        if(p->is_infected){
            SDL_SetRenderDrawColor(renderer, 255, 10, 10, SDL_ALPHA_OPAQUE);
        }else{
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        }
        SDL_RenderDrawRect(renderer, rect);
    }else{
        return;
    }
}


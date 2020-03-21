#include "corona_simulation.h"
#define default_vel_x 0.1
#define default_vel_y 0.1
#define default_width 10
#define default_height 10
typedef struct{
    int age;    
    int is_infected;
    int isAlive;
    float x_pos;
    float y_pos;
    int is_checked;
}Person;

Person * create_person(int age, float x_pos, float y_pos);
void move_person(Person * p, float dt, float direction_x, float direction_y);
void draw_person(Person *p, SDL_Renderer * renderer);
void check_infected(Person *p);
int infection(Person *p, Person *other);
float distance(int x1, int y1, int x2, int y2);


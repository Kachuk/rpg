#include "../movement_handler.h"
#include "../physics/physics_internal.h"

void default_movement_handler(Body *self, Physics_State_Internal *state) {
        // default movement without gravity
        if (self->body_existence_duration++ > self->body_existence_timelimit){
            self->is_active = false;
        }


		if (!self->is_kinematic) {
			self->velocity[1] += state->gravity;
			if (state->terminal_velocity > self->velocity[1]) {
				self->velocity[1] = state->terminal_velocity;
			}
		}
        self->velocity[0] += self->acceleration[0];
		self->velocity[1] += self->acceleration[1];

}
void proyectile_movement_handler(Body *self, Physics_State_Internal *state) {


}
void katana_movement_handler(Body *self, Physics_State_Internal *state) {

    if (self->body_existence_duration++ > self->body_existence_timelimit){
        self->is_active = false;
    }
    printf("entity: %zx , duration %d\n", self->entity_id ,self->body_existence_duration);

    //center of the elipse
    //i need to add an offset
    i8 a = 20;
    i8 b = 10;
    f32 h = self->attached_to_body->aabb.position[0] - a*2;
    f32 k = self->attached_to_body->aabb.position[1];
    i8 t = 0;

    f32 x = h + -a * cosf((float)self->body_existence_duration / 2);
    f32 y = k + -b * sinf((float)self->body_existence_duration / 2);


    if (self->attached_to_body != NULL) {
        //katana movement needs to follow the player body movements
        self->aabb.position[0] = fabs(x);
        self->aabb.position[1] = fabs(y);
    } else {
        printf("katana not attached to body");
    }

	//printf("(%f, %f)", self->attached_to_body->aabb.position[0], self->attached_to_body->aabb.position[1]);


}
void kinetic_movement_handler(Body *self, Physics_State_Internal *state) {


}
// do nothing
void static_movement_handler(Body *self, Physics_State_Internal *state) {}

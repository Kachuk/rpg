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

}
void kinetic_movement_handler(Body *self, Physics_State_Internal *state) {


}
// do nothing
void static_movement_handler(Body *self, Physics_State_Internal *state) {}

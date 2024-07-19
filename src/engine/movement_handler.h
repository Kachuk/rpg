#pragma once

#include "physics.h"
#include "physics/physics_internal.h"


void default_movement_handler(Body *self, Physics_State_Internal *state);
void proyectile_movement_handler(Body *self, Physics_State_Internal *state);
void katana_movement_handler(Body *self, Physics_State_Internal *state);
void kinetic_movement_handler(Body *self, Physics_State_Internal *state);
void static_movement_handler(Body *self, Physics_State_Internal *state);


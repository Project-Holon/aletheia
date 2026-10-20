#ifndef GAME_ARM9_PARTICLE_TYPES_H
#define GAME_ARM9_PARTICLE_TYPES_H

#include "../types.h"

/* Projection setup for the system camera. */
struct ParticleCameraParams {
    u32 projType;
    u32 fovSin;
    u32 fovCos;
    u32 aspect;
    u32 orthoExtent;
    u32 nearZ;
    u32 farZ;
    u32 projScale;
};

#endif

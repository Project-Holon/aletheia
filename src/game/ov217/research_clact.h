#ifndef RESEARCH_CLACT_H
#define RESEARCH_CLACT_H

#include "../types.h"

struct ClactUnit;
struct ClactActor;

/* Header passed to CLACT_CreateActor: position plus two small settings. */
struct ActorHeader {
    s16 x;
    s16 y;
    s16 z;
    u8 animNo;
    u8 bgPriority;
};

/* Surface position passed to CLACT_AddActorSurfacePos. */
struct SurfacePos {
    s16 x;
    s16 y;
};

#endif

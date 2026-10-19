#ifndef PMSIV_EDIT_SHARED_TYPES_H
#define PMSIV_EDIT_SHARED_TYPES_H

#include "pms_input_data_shared_types.h"

#include "../types.h"

struct PmsInputView;

struct PmsInputState;

struct PmsInputData;

/* Frame-stepped screen effect used by the category and edit views: either a
 * brightness ramp (fixed point 20.12) or a two-layer alpha blend ramp. */
struct PmsivFade {
    int planeMask;
    int secondPlaneMask;
    int current;
    int target;
    int step;
    int framesLeft;
    int done;
    void *task;
};

/* Frame-stepped background scroll of one layer (fixed point 20.12). */
struct PmsivBgScroll {
    int layer;
    int axis;
    int current;
    int target;
    int step;
    u16 framesLeft;
    u16 state;
    void *task;
};

struct Bmp;

typedef struct { short x,y; } Pair;

#endif

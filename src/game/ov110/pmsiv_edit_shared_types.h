#ifndef PMSIV_EDIT_SHARED_TYPES_H
#define PMSIV_EDIT_SHARED_TYPES_H

#include "pms_input_data_shared_types.h"

typedef signed char s8;

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

struct V3;

struct Obj_021BC160;

struct Obj_021BC1B8;

struct Bmp;

typedef struct { void *root; u8 pad[0x18]; void *items[2][2]; } Obj_021BC160;

typedef struct { short x,y; } Pair;

typedef struct { void *root; u8 *state; int pad; void *desc[2]; u8 gap0[8]; void *items[2][2]; u8 gap[12]; Pair pos[2]; int pad40; int count; } Obj_021BC1B8;

#endif

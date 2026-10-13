#ifndef ALETHEIA_OV037_GIMMICK_SAVE_TYPES_H
#define ALETHEIA_OV037_GIMMICK_SAVE_TYPES_H

/*
 * Views of GimmickWork.work (the 32-word block of the field gimmick save), one
 * per gimmick that keeps state there.  The block is shared: only one gimmick
 * is active at a time, so each gimmick overlay lays its own view over it (the
 * id argument of the accessor is not used).  The script commands of overlay 37
 * and the gimmick overlays themselves use these same definitions.
 *
 * The header uses only built-in types so that any source file can include it
 * ("../ov037/gimmick_save_types.h").
 */

/* Gimmick 38 (overlay 38): eight switches, ten plates, seven doors. */
typedef struct Gimmick38Work {
    int switchFound[8];             /* 0x00 */
    int platePressed[10];           /* 0x20 */
    int doorOpen[7];                /* 0x48 */
} Gimmick38Work;

/*
 * Gimmick 39 (overlay 39): the gimmick save area (work id 2, 0x18 bytes used).
 */
#define FIELD_GIMMICK_CART_LANES_LANE_COUNT        4

typedef struct Gimmick39Save {
    int laneFrame[FIELD_GIMMICK_CART_LANES_LANE_COUNT];            /* 0x00: cart animation frame kept while the map is off */
    unsigned char laneState[FIELD_GIMMICK_CART_LANES_LANE_COUNT];  /* 0x10: lever position of each lane, 0 or 1 */
    unsigned short laneUnlocked[2];                                /* 0x14: set by script for lanes 1 and 2 */
} Gimmick39Save;

/* Gimmick 40 (overlay 40): the gimmick save area (work id 3). */
typedef struct Gimmick40Save {
    int flag;                       /* 0x00: set and read by script commands */
    unsigned char animeDone[1];     /* 0x04: per model, the animation was played */
} Gimmick40Save;

/* Gimmick 42 (overlay 42): the gimmick save area (work id 4). */
#define FIELD_GIMMICK_BUTTON_STATES_ONE_SHOT_COUNT 3

typedef struct Gimmick42Save {
    unsigned char oneShotPlayed[FIELD_GIMMICK_BUTTON_STATES_ONE_SHOT_COUNT];   /* 0x00: the model played its animation */
} Gimmick42Save;

/* Gimmick 46 (overlay 46): three units, each a pose and one lever state per side. */
#define FIELD_GIMMICK_ROTATING_ROOM_UNIT_COUNT 3
#define FIELD_GIMMICK_ROTATING_ROOM_SIDE_COUNT 2

typedef struct Gimmick46Unit {
    int pose;                          /* 0 .. 3, picks the body animation */
    int leverOn[FIELD_GIMMICK_ROTATING_ROOM_SIDE_COUNT]; /* lever state per side */
} Gimmick46Unit;

/* Gimmick block of the field save (block 10). */
typedef struct Gimmick46Save {
    Gimmick46Unit units[FIELD_GIMMICK_ROTATING_ROOM_UNIT_COUNT];
} Gimmick46Save;

#endif

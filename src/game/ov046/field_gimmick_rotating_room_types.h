#ifndef OV046_GIMMICK_TYPES_H
#define OV046_GIMMICK_TYPES_H

/* Types of the ov046 field gimmick: three units, each drawn by five
 * expansion-object models (see GIMMICK46_MODEL_*). A unit has a pose that the
 * player changes with two levers; a button on each side plays a press
 * animation, and the player can hop across (GIMMICK46 hop event). */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;

#define GIMMICK46_SAVE_BLOCK_ID 10
#define GIMMICK46_UNIT_COUNT 3
#define GIMMICK46_MODELS_PER_UNIT 5
#define GIMMICK46_SIDE_COUNT 2

/* Model indices inside a unit (add unit * GIMMICK46_MODELS_PER_UNIT). */
#define GIMMICK46_MODEL_BODY 0
#define GIMMICK46_MODEL_LEVER_BASE 1   /* + side */
#define GIMMICK46_MODEL_BUTTON_BASE 3  /* + side */
/* Model of the extra decoration drawn once for the whole gimmick. */
#define GIMMICK46_MODEL_EXTRA 15

/* Sound effects. */
#define GIMMICK46_SE_HOP_START 0x55e
#define GIMMICK46_SE_BUTTON 0x6d3
#define GIMMICK46_SE_HOP_END 0x6d3
#define GIMMICK46_SE_ROTATE_START 0x6d4
#define GIMMICK46_SE_ROTATE_END 0x6d9
#define GIMMICK46_SE_LEVER_START 0x6fc
#define GIMMICK46_SE_LEVER_END 0x6fd
#define GIMMICK46_SE_NONE (-1)

#define GIMMICK46_HOP_STEPS 8
#define GIMMICK46_HOP_SPEED 0x2000

/* Fixed-point position. */
typedef struct Vec3Fx {
    int x;
    int y;
    int z;
} Vec3Fx;

/* Position, scale and rotation of an expansion-object model. */
typedef struct FldExpModel {
    Vec3Fx pos;
    Vec3Fx scale;
    int rotation[9];  /* 3x3 fixed-point matrix */
} FldExpModel;

/* Save data of one unit (12 bytes). */
typedef struct Gimmick46Unit {
    int pose;                          /* 0 .. 3, picks the body animation */
    int leverOn[GIMMICK46_SIDE_COUNT]; /* lever state per side */
} Gimmick46Unit;

/* Gimmick block of the field save (block 10). */
typedef struct Gimmick46Save {
    Gimmick46Unit units[GIMMICK46_UNIT_COUNT];
} Gimmick46Save;

/* Event data: play one animation on a model and wait until it stops. */
typedef struct Gimmick46AnimEvent {
    u8 modelIndex;
    u8 startCount;   /* number of entries of animId that are started */
    u8 stopCount;    /* animations 0 .. stopCount-1 are stopped first */
    u8 pad;
    int unused[2];
    int animId[1];
    int startSe;
    int endSe;       /* GIMMICK46_SE_NONE: no sound at the end */
} Gimmick46AnimEvent;

/* Event data: the player hops across a unit. */
typedef struct Gimmick46HopEvent {
    u8 pad[3];
    u8 step;         /* 0 .. GIMMICK46_HOP_STEPS */
    int speedX;      /* position change per step */
    int baseY;       /* height at the start */
} Gimmick46HopEvent;

/* Common work of the gimmick (allocated by the setup function). */
typedef struct Gimmick46Work {
    int unitIndex;          /* unit that the running event uses */
    int side;               /* lever or button side of that event */
    Gimmick46Unit *unit;    /* save data of that unit */
    union {
        Gimmick46AnimEvent anim;
        Gimmick46HopEvent hop;
    } event;
    int playerInside;       /* player stands inside the area */
} Gimmick46Work;

#endif

#ifndef OV046_GIMMICK_TYPES_H
#define OV046_GIMMICK_TYPES_H

/* Types of the ov046 field gimmick: three units, each drawn by five
 * expansion-object models (see FIELD_GIMMICK_ROTATING_ROOM_MODEL_*). A unit has a pose that the
 * player changes with two levers; a button on each side plays a press
 * animation, and the player can hop across (GIMMICK46 hop event). */

#include "../types.h"

#define FIELD_GIMMICK_ROTATING_ROOM_SAVE_BLOCK_ID 10
#define FIELD_GIMMICK_ROTATING_ROOM_MODELS_PER_UNIT 5

/* Model indices inside a unit (add unit * FIELD_GIMMICK_ROTATING_ROOM_MODELS_PER_UNIT). */
#define FIELD_GIMMICK_ROTATING_ROOM_MODEL_BODY 0
#define FIELD_GIMMICK_ROTATING_ROOM_MODEL_LEVER_BASE 1   /* + side */
#define FIELD_GIMMICK_ROTATING_ROOM_MODEL_BUTTON_BASE 3  /* + side */
/* Model of the extra decoration drawn once for the whole gimmick. */
#define FIELD_GIMMICK_ROTATING_ROOM_MODEL_EXTRA 15

/* Sound effects. */
#define FIELD_GIMMICK_ROTATING_ROOM_SE_HOP_START 0x55e
#define FIELD_GIMMICK_ROTATING_ROOM_SE_BUTTON 0x6d3
#define FIELD_GIMMICK_ROTATING_ROOM_SE_HOP_END 0x6d3
#define FIELD_GIMMICK_ROTATING_ROOM_SE_ROTATE_START 0x6d4
#define FIELD_GIMMICK_ROTATING_ROOM_SE_ROTATE_END 0x6d9
#define FIELD_GIMMICK_ROTATING_ROOM_SE_LEVER_START 0x6fc
#define FIELD_GIMMICK_ROTATING_ROOM_SE_LEVER_END 0x6fd
#define FIELD_GIMMICK_ROTATING_ROOM_SE_NONE (-1)

#define FIELD_GIMMICK_ROTATING_ROOM_HOP_STEPS 8
#define FIELD_GIMMICK_ROTATING_ROOM_HOP_SPEED 0x2000

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

/* Event data: play one animation on a model and wait until it stops. */
typedef struct FieldGimmickRotatingRoomAnimEvent {
    u8 modelIndex;
    u8 startCount;   /* number of entries of animId that are started */
    u8 stopCount;    /* animations 0 .. stopCount-1 are stopped first */
    u8 pad;
    int unused[2];
    int animId[1];
    int startSe;
    int endSe;       /* FIELD_GIMMICK_ROTATING_ROOM_SE_NONE: no sound at the end */
} FieldGimmickRotatingRoomAnimEvent;

/* Event data: the player hops across a unit. */
typedef struct FieldGimmickRotatingRoomHopEvent {
    u8 pad[3];
    u8 step;         /* 0 .. FIELD_GIMMICK_ROTATING_ROOM_HOP_STEPS */
    int speedX;      /* position change per step */
    int baseY;       /* height at the start */
} FieldGimmickRotatingRoomHopEvent;

/* Common work of the gimmick (allocated by the setup function). */
typedef struct FieldGimmickRotatingRoomWork {
    int unitIndex;          /* unit that the running event uses */
    int side;               /* lever or button side of that event */
    FieldGimmickRotatingRoomUnit *unit;    /* save data of that unit */
    union {
        FieldGimmickRotatingRoomAnimEvent anim;
        FieldGimmickRotatingRoomHopEvent hop;
    } event;
    int playerInside;       /* player stands inside the area */
} FieldGimmickRotatingRoomWork;

#endif

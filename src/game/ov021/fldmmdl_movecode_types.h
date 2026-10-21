#ifndef ALETHEIA_OV021_FLDMMDL_MOVECODE_TYPES_H
#define ALETHEIA_OV021_FLDMMDL_MOVECODE_TYPES_H

struct FieldEffectObj;

#include "../ov010/fldmmdl_types.h"

/*
 * Work areas of the field model move codes in fldmmdl_movecode.c. Each one is the
 * block returned by the model's move proc work (0x10 bytes at Mmdl+0x94); the
 * size passed to the init call is noted on each type. Step handlers of the
 * spin, swing, back-and-forth and route move codes read the step index from
 * the byte noted on the type.
 */

/* Rectangle of grid cells a limited random walk may enter. */
typedef struct MmdlMoveRect {
    int left;
    int top;
    int right;
    int bottom;
} MmdlMoveRect;

/* 8 bytes: turn in place at random inside a set of directions. */
typedef struct MmdlTurnRandomWork {
    unsigned short suspended;   /* 0: turning */
    short waitFrames;
    unsigned int dirSetId;      /* row of the direction set table */
} MmdlTurnRandomWork;

/* 8 bytes: face one fixed direction. */
typedef struct MmdlFixedDirWork {
    unsigned int dir;           /* 0 up, 1 down, 2 left, 3 right */
    int state;
} MmdlFixedDirWork;

/* 16 bytes: walk at random inside a set of directions. */
typedef struct MmdlWalkRandomWork {
    short state;
    short waitFrames;
    int limitMode;              /* 0 none, 1 stay in the move rect, 2 allow bump bit 1 */
    unsigned int acmdSpeed;     /* second argument of the walk acmd lookup */
    unsigned int dirSetId;
} MmdlWalkRandomWork;

/* Turn order of a spin: directions ended by 9. */
typedef struct MmdlDirCycle {
    int dirs[5];
} MmdlDirCycle;

/* 8 bytes: spin or swing in place (turn, wait, turn to the next direction). */
typedef struct MmdlSpinWork {
    signed char rotation;       /* 2 turn left, 3 turn right */
    unsigned char pad1;
    unsigned char step;         /* index of the step handler */
    unsigned char pad3;
    int waitCount;
} MmdlSpinWork;

/* State of a model that mirrors the player's turns (event types 7, 8, 17, 18). */
typedef struct MmdlMirrorState {
    signed char savedDir;
    signed char side;           /* 0: left hand event types 7 and 17, else 1 */
    unsigned char dirWasPaused;
    unsigned char pad3;
} MmdlMirrorState;

/* 8 bytes: walk between the start and the header position and back. */
typedef struct MmdlBackForthWork {
    unsigned char step;
    unsigned char reversed;
    unsigned char triggerCount;
    unsigned char pad3;
    MmdlMirrorState mirror;
} MmdlBackForthWork;

/* 12 bytes: walk a route of four directions. */
typedef struct MmdlRoutePatrolWork {
    unsigned char step;
    unsigned char routeIndex;
    unsigned char axisCheckIndex;
    unsigned char axis;         /* 0 compare x, 1 compare z */
    unsigned char routeId;      /* row of the direction set table */
    unsigned char triggerCount;
    unsigned char pad6;
    unsigned char pad7;
    MmdlMirrorState mirror;
} MmdlRoutePatrolWork;

/* 12 bytes: route patrol that turns into its mirrored move code. */
typedef struct MmdlRoutePatrolSwapWork {
    unsigned char step;
    signed char routeIndex;
    unsigned char axisCheckIndex;
    unsigned char axis;
    unsigned char routeId;
    unsigned char reverseRoute; /* 1: walk the route backwards */
    unsigned char triggerCount;
    unsigned char pad7;
    MmdlMirrorState mirror;
} MmdlRoutePatrolSwapWork;

/* Record of the direction set table: set id and its list ended by 9. */
typedef struct MmdlDirSetEntry {
    unsigned int id;
    unsigned int *dirs;
} MmdlDirSetEntry;

/*
 * Per-move-code work areas of the field model movement routines. Each one
 * is the block returned by the model's move proc work (0x10 bytes at
 * Mmdl+0x94) or move sub proc work (0x10 bytes at Mmdl+0xA4); the size
 * passed to the init call is noted on each type.
 */

/* Sub proc work (9 bytes): walk a number of steps, then wait for the move end. */
typedef struct MmdlStepRepeatWork {
    unsigned char state;
    signed char waitFlag;
    signed char count;
    signed char countMax;       /* param1 of the model */
} MmdlStepRepeatWork;

/* Sub proc work (9 bytes): turn on the spot (look around or spin). */
typedef struct MmdlTurnSubWork {
    unsigned char busy;
    unsigned char state;
    unsigned char pad2;
    signed char repeatParam;    /* param1 of the model, written by the init */
    signed char startDir;
    signed char dirGroup;       /* row of the direction table */
    signed char dirIndex;       /* column of the direction table */
    signed char turnCount;
    signed char frameCount;
} MmdlTurnSubWork;

/*
 * Move proc work (8 bytes for the player look, 12 for the other-model
 * look): remembers where the watched model stood when it was last seen.
 */
typedef struct MmdlLookWork {
    unsigned char step;
    unsigned char tracking;
    short targetX;
    short targetZ;
    unsigned short lastDir;     /* 0xFF: none */
    Mmdl *target;               /* look at other model only */
} MmdlLookWork;

/* Move proc work (8 bytes): hide the model in a field effect. */
typedef struct MmdlHideWork {
    unsigned char step;
    unsigned char kind;
    unsigned char noEffect;
    unsigned char pad3;
    struct FieldEffectObj *effect;
} MmdlHideWork;

/* Move proc work (4 bytes): face a fixed direction or the player's. */
typedef struct MmdlFaceDirWork {
    unsigned char step;
    signed char dir;            /* 9: take the player's direction */
    unsigned char flag;
    unsigned char pad3;
} MmdlFaceDirWork;

/* Move proc work (12 bytes): walk along a wall. */
typedef struct MmdlWallWalkWork {
    unsigned char step;
    unsigned char pad1[3];
    unsigned int mode;
    unsigned int hand;
} MmdlWallWalkWork;

#endif

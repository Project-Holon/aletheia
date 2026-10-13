#ifndef GAME_OV043_FIELD_GIMMICK_LIFT_ELEVATOR_TYPES_H
#define GAME_OV043_FIELD_GIMMICK_LIFT_ELEVATOR_TYPES_H

/* ov043: field gimmick with six switchable lifts (index 0..5) and one
 * elevator (model 7). Each lift model moves between two heights; the walkable
 * height area under it follows the lift state. Characters standing in the lift
 * zone ride along. Lift 5 also breaks an obstacle (model 6) and changes the fog. */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

#define GIMMICK43_LIFT_COUNT   6
#define GIMMICK43_ELEVATOR     7   /* model index of the elevator */
#define GIMMICK43_OBSTACLE     6   /* model index of the breakable obstacle */
#define GIMMICK43_FIXED_AREA_COUNT 8   /* height areas 0..7 are fixed; lift areas follow from 8 */
#define GIMMICK43_RIDER_MAX    5
#define GIMMICK43_BIG_LIFT     5   /* lift that breaks the obstacle and changes the fog */
#define GIMMICK43_SAVE_BLOCK   7   /* field save gimmick block id */

typedef struct VecFx32 {
    int x;
    int y;
    int z;
} VecFx32;

/* Fixed walkable height area registered at field map setup (table entry, 0x14 bytes). */
typedef struct HeightRegion {
    int tileX;
    int tileZ;
    int width;
    int depth;
    int height;
} HeightRegion;

/* Tile rectangle of one lift; the registered height depends on the lift state. */
typedef struct LiftZone {
    int tileX;
    int tileZ;
    int width;
    int depth;
    int height[2];   /* area height for lift state 0 and 1 */
} LiftZone;

/* Model height of one lift for state 0 and 1 (table entry, 0x18 bytes). */
typedef struct LiftHeights {
    int y[2];
    int reserved[4];
} LiftHeights;

/* Gimmick save block (7 words). */
typedef struct Gimmick43Save {
    int liftState[GIMMICK43_LIFT_COUNT];   /* 1 = lift moved to its second position */
    int obstacleBroken;                    /* obstacle (model 6) destroyed by lift 5 */
} Gimmick43Save;

/* Vertical camera jitter while a lift starts or stops (0x1C bytes). */
typedef struct CameraShake {
    u8 phase;               /* 0x00 0: stop camera trace, 1: shaking */
    u8 count;               /* 0x01 shakes done */
    u8 halfCycles;          /* 0x02 shake count is halfCycles * 2 */
    u8 frameParity;         /* 0x03 shake every second frame */
    int amplitude;          /* 0x04 height offset, sign flips every shake */
    u8 *camera;             /* 0x08 */
    int savedCameraTarget;  /* 0x0C camera trace target to restore */
    VecFx32 savedShift;     /* 0x10 camera target shift to restore */
} CameraShake;

/* Field map common work (0x58 bytes), allocated in the setup function. */
typedef struct Gimmick43Work {
    int liftIndex;                      /* 0x00 lift (0..5) that is moving */
    int curY;                           /* 0x04 current height (fx32) */
    int goalY;                          /* 0x08 height the lift moves to */
    int stepY;                          /* 0x0C height change per frame */
    int savedCameraTarget;              /* 0x10 elevator: trace target saved while the camera is detached */
    int isRising;                       /* 0x14 elevator: nonzero when it goes up */
    int isStalled;                      /* 0x18 lift 5 hit the obstacle and waits */
    u16 stallFrames;                    /* 0x1C counts shake ends while stalled */
    u16 stallStage;                     /* 0x1E 0: start shake, 1: wait for shake */
    CameraShake shake;                  /* 0x20 */
    int isFogCheckPending;              /* 0x3C change the fog at the next threshold */
    int obstacleAnimeState;              /* 0x40 1: obstacle break just started, 2: wait for its animation */
    void *riders[GIMMICK43_RIDER_MAX];  /* 0x44 field objects that move with the lift */
} Gimmick43Work;

#endif

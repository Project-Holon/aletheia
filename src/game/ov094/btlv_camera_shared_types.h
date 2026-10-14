#ifndef BTLV_CAMERA_SHARED_TYPES_H
#define BTLV_CAMERA_SHARED_TYPES_H

#include "btlv_effvm_types.h"

typedef int fx32;
typedef signed short s16_021F6560;

struct G3dCamera;

typedef struct BtlvVec3 {
    fx32 x, y, z;
} BtlvVec3;

/*
 * Moves a vector by a fixed step per tick (BTLV_EFFECT_StepMover). Shared by the camera,
 * the sprite manager, the background scroll and the Pokemon sprite tweens.
 * mode 0: jump to end; 1 and 4: step toward end; 2: swing back and forth
 * and stop at start; 3: like 2 but reverse only on odd repeat counts.
 */
typedef struct BtlvMover {
    int mode;           /* 0x00 */
    BtlvVec3 start;     /* 0x04: value when the move began, restored after the last repeat (modes 2 and 3) */
    BtlvVec3 end;       /* 0x10: target of modes 0, 1 and 4 */
    BtlvVec3 step;      /* 0x1c: change per update */
    int count;          /* 0x28: updates left before the step reverses */
    int countReset;     /* 0x2c */
    int wait;           /* 0x30: ticks left before the next update */
    int waitReset;      /* 0x34 */
    int repeat;         /* 0x38: reversals left */
} BtlvMover;

#define BTLV_CAMERA_MOVE_EYE    0x1
#define BTLV_CAMERA_MOVE_TARGET 0x2
#define BTLV_CAMERA_MOVE_SHAKE  0x4

/* The battle camera (0xB8 bytes), made by BTLV_CAMERA_Create. */
typedef struct BtlvCamera {
    void *owner;                /* 0x00: battle effect owner */
    struct G3dCamera *camera;   /* 0x04 */
    int orbitPitch;             /* 0x08: angle of the eye above the target plane */
    int orbitYaw;               /* 0x0C */
    int orbitRadius;            /* 0x10: distance between eye and target */
    u32 moveFlags;              /* 0x14: BTLV_CAMERA_MOVE_* */
    BtlvVec3 eye;               /* 0x18 */
    BtlvVec3 target;            /* 0x24 */
    BtlvVec3 eyeDest;           /* 0x30 */
    BtlvVec3 targetDest;        /* 0x3C */
    BtlvVec3 eyeStep;           /* 0x48 */
    BtlvVec3 targetStep;        /* 0x54 */
    BtlvVec3 shakeOffset;       /* 0x60: added to eye and target */
    int moveWait;               /* 0x6C: ticks left before the next move step */
    int moveWaitReset;          /* 0x70 */
    int easeCount;              /* 0x74: moves left before the steps are halved */
    BtlvMover shake;            /* 0x78 */
    u16 heap;                   /* 0xB4 */
    u16 pad_B6;
} BtlvCamera;

#endif

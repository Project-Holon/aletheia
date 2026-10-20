#ifndef GAME_OV044_FIELD_GIMMICK_LIFT_TYPES_H
#define GAME_OV044_FIELD_GIMMICK_LIFT_TYPES_H

/* ov044: field gimmick with one lift. The lift model moves vertically between
 * two heights and carries the player; the camera is detached while it descends. */

#include "../types.h"

#include "../sdk_fx.h"

/* Field map common work (0x14 bytes), allocated in the setup function. */
typedef struct FieldGimmickLiftWork {
    int curY;               /* 0x00 current lift height (fx32) */
    int goalY;              /* 0x04 height the lift moves to */
    int stepY;              /* 0x08 height change per frame, signed toward goalY */
    const VecFx32 *savedCameraTarget;  /* 0x0C camera trace target saved while the camera is detached */
    int isDescending;       /* 0x10 nonzero: lift goes down and the camera stays behind */
} FieldGimmickLiftWork;

#endif

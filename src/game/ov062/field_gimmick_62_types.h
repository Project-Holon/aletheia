#ifndef GAME_OV062_FIELD_GIMMICK_62_TYPES_H
#define GAME_OV062_FIELD_GIMMICK_62_TYPES_H

/* ov062: field gimmick with one animated model at a fixed position. The model
 * is hidden once the flag in gimmick work slot 0x34 is set. */

#include "../types.h"

#define FIELD_GIMMICK_62_WORK_SLOT    0x34   /* gimmick work slot that holds the hide flag */

#include "../sdk_fx.h"

#endif

#ifndef BTLV_EFFVM_SHARED_TYPES_H
#define BTLV_EFFVM_SHARED_TYPES_H

/*
 * All per-function stand-in views that lived here are gone: the sprite manager,
 * battle sprite and gauge code now use BtlvClact, BtlvMcssWork and BtlvGaugeWork.
 * Only the includes below remain, because btlv_clact.c and
 * btlv_effect_shared_types.h still include this file.
 */

#include "btlv_effvm_types.h"
#include "btlv_camera_shared_types.h"
#include "btlv_effect_shared_types.h"

typedef long long s64;

#endif

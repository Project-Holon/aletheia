#ifndef SCRCMD_MMDL_SHARED_TYPES_H
#define SCRCMD_MMDL_SHARED_TYPES_H

#include "script_work_types.h"
#include "scrcmd_trialhouse_shared_types.h"

struct FieldMap;

struct MmdlSys;

struct Mmdl;

#include "../types.h"

#include "../sdk_fx.h"

typedef int (*GameEventFunc)(struct GameEvent *event, u32 *state, void *work);

#endif

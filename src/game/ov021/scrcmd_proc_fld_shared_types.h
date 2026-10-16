#ifndef SCRCMD_PROC_FLD_SHARED_TYPES_H
#define SCRCMD_PROC_FLD_SHARED_TYPES_H

#include "scrcmd_proc_fld_types.h"

struct Ctx;

struct Obj;

struct BigObj;

struct Desc;

struct ScriptVm;

struct ScrcmdWork;

/* Six enable flags handed to the field region object. */
typedef struct LayerFlags {
    u32 flag[6];
} LayerFlags;

#endif

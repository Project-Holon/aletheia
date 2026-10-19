#ifndef ALETHEIA_OV010_SCRIPT_WORK_TYPES_H
#define ALETHEIA_OV010_SCRIPT_WORK_TYPES_H

/*
 * Script work block (0x14C bytes) allocated by the script work create
 * function (script_work.c, 0x02158E7C). One block exists per running script
 * (child scripts point back to their parent). Field offsets come from the
 * accessors in script_work.c.
 */

#include "../types.h"

#define SCRIPT_WORK_MAGIC 0x3643F
#define SCRIPT_LOCAL_WORK_BASE 0x8000

#include "../arm9/script_vm_types.h"

/* Map handles resolved from the game system (script_work.c, 0x02158E54). */
typedef struct ScriptFieldParam {
    void *mapSystem;   /* 0x00: derived from fieldSystem */
    void *fieldSystem; /* 0x04: field system of the game system */
} ScriptFieldParam;

/* One 0x1C-byte trainer record (two per work). */
typedef struct ScriptTrainerEntry {
    u32 params[7];
} ScriptTrainerEntry;

typedef struct ScriptWork {
    u32 magic;                       /* 0x00: SCRIPT_WORK_MAGIC */
    u16 scriptId;                    /* 0x04 */
    u16 pad06;                       /* 0x06: alignment */
    void *targetObj;                 /* 0x08: object the script talks to */
    u16 heapId;                      /* 0x0C */
    u16 pad0E;                       /* 0x0E: alignment */
    void *gameSystem;                /* 0x10 */
    void *event;                     /* 0x14 */
    ScriptFieldParam fieldParam;     /* 0x18 */
    int targetObjParam;              /* 0x20: creation parameter for the target object */
    int isChild;                     /* 0x24 */
    struct ScriptWork *parentWork;   /* 0x28 */
    void *wordSet;                   /* 0x2C */
    void *msgBuffer;                 /* 0x30: string buffer, 0x500 */
    void *tempBuffer;                /* 0x34: string buffer, 0x500 */
    void *msgData;                   /* 0x38 */
    void *userWork;                  /* 0x3C: heap block owned by the script */
    u32 trainerParam;                /* 0x40 */
    ScriptTrainerEntry trainers[2];  /* 0x44 */
    u16 localWorks[96];              /* 0x7C: work ids 0x8000.. */
    u32 returnScriptId;              /* 0x13C */
    u32 returnParam;                 /* 0x140 */
    u32 returnFlag;                  /* 0x144 */
    void *cmdWork;                   /* 0x148 */
} ScriptWork;

#endif

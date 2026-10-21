#ifndef GAME_OV186_BR_PROC_SYS_TYPES_H
#define GAME_OV186_BR_PROC_SYS_TYPES_H

#include "../types.h"

/* State of the battle recorder process system (BR_PROC_SYS_Create), 0x70 bytes. */
struct BrProcSysContext {
    unsigned object;               /* 0x00 process-system object */
    void *base;                    /* 0x04 record array base */
    unsigned short count;          /* 0x08 record count */
    unsigned short pad0;           /* 0x0A */
    unsigned arg;                  /* 0x0C */
    unsigned short heap;           /* 0x10 heap id */
    unsigned short pad1;           /* 0x12 */
    int done;                      /* 0x14 set when the running slot completes */
    int state;                     /* 0x18 slot state machine */
    u8 slotArea[0x30];             /* 0x1C old/current/next slots and entry scratch */
    unsigned pending[6];           /* 0x4C pending record indices */
    int pendingCount;              /* 0x64 */
    unsigned *list;                /* 0x68 loaded index list */
    int loaded;                    /* 0x6C */
};

#endif

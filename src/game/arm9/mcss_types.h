#ifndef GAME_ARM9_MCSS_TYPES_H
#define GAME_ARM9_MCSS_TYPES_H

#include "../types.h"

/* A loaded palette. */
typedef struct McssPlttData {
    u32   fmt;                          /* 0x00 */
    u32   extended;                     /* 0x04 */
    u32   byteSize;                     /* 0x08 */
    void *data;                         /* 0x0C */
} McssPlttData;

/*
 * What to load for one sprite: the archive and the member ids of its
 * resources.  Built by the MCSS_TOOL_MakeAddWork functions, stored in the
 * work at +0x150 so the resources can be reloaded.  heapMode 1 puts the
 * resources into the 0x8000 heap bank.
 */
typedef struct McssAddWork {
    u32 arcId;                          /* 0x00 */
    u32 textureMember;                  /* 0x04 */
    u32 paletteMember;                  /* 0x08 */
    u32 cellMember;                     /* 0x0C */
    u32 cellAnimMember;                 /* 0x10 */
    u32 multiCellMember;                /* 0x14 */
    u32 multiCellAnimMember;            /* 0x18 */
    u32 cellHeaderMember;               /* 0x1C */
    u32 heapMode;                       /* 0x20 */
} McssAddWork;

#endif

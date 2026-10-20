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

#endif

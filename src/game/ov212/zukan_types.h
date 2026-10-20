#ifndef GAME_OV212_ZUKAN_TYPES_H
#define GAME_OV212_ZUKAN_TYPES_H

#include "../types.h"

/* Descriptor ZUKAN_CreateActor builds one CLACT actor from (0x18 bytes). Built by
 * the ov210 search screen and the other zukan screens. */
struct ZknSearchActorTemplate {
    int kind;      /* 0x00 */
    u16 id;        /* 0x04 */
    u16 flags;     /* 0x06 */
    int charIdx;   /* 0x08 character resource index */
    int palIdx;    /* 0x0C palette resource index */
    int cellIdx;   /* 0x10 cell resource index */
    u16 x;         /* 0x14 */
    u16 y;         /* 0x16 */
};

#endif

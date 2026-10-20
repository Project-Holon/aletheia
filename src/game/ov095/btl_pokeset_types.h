#ifndef BTL_POKESET_TYPES_H
#define BTL_POKESET_TYPES_H

#include "../types.h"

struct BtlPokeParam;

/* A set of up to six pokemon with the damage each one took. */
typedef struct BtlPokeSet {
    struct BtlPokeParam *poke[6]; /* 0x00 */
    u16 damage[6];          /* 0x18: damage added without the extra flag */
    u16 damageExtra[6];     /* 0x24: damage added with the extra flag */
    u8 damageKind[6];       /* 0x30: 0 none, 1 damage, 2 extra damage added last */
    u16 speed[6];           /* 0x36: sort key, filled by the speed sort */
    u8 count;               /* 0x42 */
    u8 countMax;            /* 0x43: highest count reached */
    u8 seekIndex;           /* 0x44: cursor of the SeekNext walk */
    u8 emptyMarked;         /* 0x45: set from outside, makes an empty set count as removed */
    u8 pad46[2];            /* 0x46 */
} BtlPokeSet;

#endif

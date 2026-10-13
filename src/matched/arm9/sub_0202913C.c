/*
 * function: func_0202913C
 * address:  0x0202913C
 * packet:   pkt_02028FD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_SetState  0x02029344  thumb
 */
#include "../include/Obj16755.h"

typedef unsigned int u32;

extern void FIELD_SOUND_SYSTEM_SetState(void *obj, u32 value);

void func_0202913C(void *obj)
{
    switch (((struct Obj16755 *)obj)->f1C) {
    case 0:
    case 5:
        break;
    case 3:
        FIELD_SOUND_SYSTEM_SetState(obj, 11);
        break;
    }
}

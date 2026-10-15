/*
 * function: STA_ACT_SCRIPT_SetPendingFlag
 * address:  0x021FAF54
 * packet:   pkt_021FAF54
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10543.h"

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);

int STA_ACT_SCRIPT_SetPendingFlag(int a, char *b)
{
    VM_GetU32(((struct Obj10543 *)b)->f4);
    if (((struct Obj10543 *)b)->f16 & 2)
        ((struct Obj10543 *)b)->f16 |= 4;
    return 1;
}

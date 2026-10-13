/*
 * function: FLDEFF_SHADOW_DeleteSlot
 * address:  0x021AC2AC
 * packet:   pkt_021AC2AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with two fields and a constant one.
 *
 * symbols:
 *   BILLBOARD_ACT_DeleteSlots  0x02050278  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12095.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BbActSys;
extern void BILLBOARD_ACT_DeleteSlots(struct BbActSys *o, u32 first, u32 count);

void FLDEFF_SHADOW_DeleteSlot(u8 *p)
{
    BILLBOARD_ACT_DeleteSlots((struct BbActSys *)(((struct Obj12095 *)p)->f10), (u16)((struct Obj12095 *)p)->f18, 1);
}

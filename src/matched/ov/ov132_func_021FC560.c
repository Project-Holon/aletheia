/*
 * function: func_021FC560
 * address:  0x021FC560
 * packet:   pkt_021FC560
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STA_ACTING_ClearText  0x021F94B0  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23262.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void STA_ACTING_ClearText(u8 *p);

int func_021FC560(void *a, void **pp)
{
    STA_ACTING_ClearText(((struct Obj23262 *)((u8 *)*pp))->f34);
    return 0;
}

/*
 * function: PERCENTAGE_StoreValue
 * address:  0x021C2888
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter, u8 at +2.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26023.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void PERCENTAGE_StoreValue(void *p, u8 v)
{
    ((struct Obj26023 *)p)->f2 = v;
}

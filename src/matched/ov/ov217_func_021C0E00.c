/*
 * function: ListViewState_SetScrollX
 * address:  0x021C0E00
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter, u32 at +4.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26001.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void ListViewState_SetScrollX(void *p, u32 v)
{
    ((struct Obj26001 *)p)->f4 = v;
}

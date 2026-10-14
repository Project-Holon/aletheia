/*
 * function: ListViewState_GetScrollY
 * address:  0x021C0DF8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +8.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25999.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 ListViewState_GetScrollY(void *p)
{
    return ((struct Obj25999 *)p)->f8;
}

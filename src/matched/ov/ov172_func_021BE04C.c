/*
 * function: COMM_TVT_SYS_GetTaskMenu
 * address:  0x021BE04C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0x1d4.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24120.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 COMM_TVT_SYS_GetTaskMenu(void *p)
{
    return ((struct Obj24120 *)p)->f1D4;
}

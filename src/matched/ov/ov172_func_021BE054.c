/*
 * function: COMM_TVT_SYS_GetMemberCount
 * address:  0x021BE054
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u8 at +0x18.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24121.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u8 COMM_TVT_SYS_GetMemberCount(void *p)
{
    return ((struct Obj24121 *)p)->f18;
}

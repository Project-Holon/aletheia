/*
 * function: COMM_TVT_SYS_GetCameraBusy
 * address:  0x021BE0F8
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0x34.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24139.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 COMM_TVT_SYS_GetCameraBusy(void *p)
{
    return ((struct Obj24139 *)p)->f34;
}

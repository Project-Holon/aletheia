/*
 * function: COMM_TVT_SYS_SetCameraBusy
 * address:  0x021BE0FC
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Set the u32 at +0x34.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24140.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void COMM_TVT_SYS_SetCameraBusy(void *p, u32 v)
{
    ((struct Obj24140 *)p)->f34 = v;
}

/*
 * function: COMM_TVT_SYS_GetInputLocked
 * address:  0x021BE0C8
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0x28.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24132.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 COMM_TVT_SYS_GetInputLocked(void *p)
{
    return ((struct Obj24132 *)p)->f28;
}

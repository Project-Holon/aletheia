/*
 * function: COMM_TVT_SYS_GetMsgData
 * address:  0x021BE03C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, u32 at +0x1cc.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24118.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 COMM_TVT_SYS_GetMsgData(void *p)
{
    return ((struct Obj24118 *)p)->f1CC;
}

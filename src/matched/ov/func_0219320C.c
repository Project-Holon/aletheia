/*
 * function: FIELD_MSGBG_KeyWaitGetAuto
 * address:  0x0219320C
 * packet:   pkt_0219320C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter at +0x0.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17938.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 FIELD_MSGBG_KeyWaitGetAuto(u8 *p)
{
    return ((struct Obj17938 *)p)->f0;
}

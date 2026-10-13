/*
 * function: SCRIPT_WORK_SetReturnParam
 * address:  0x02159104
 * packet:   pkt_ov010_02159104
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Store of a word at +0x140.
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18756.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

void SCRIPT_WORK_SetReturnParam(u8 *p, u32 v)
{
    ((struct Obj18756 *)p)->f140 = v;
}

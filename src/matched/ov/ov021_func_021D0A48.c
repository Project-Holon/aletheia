/*
 * function: TRIAL_HOUSE_DeleteWork
 * address:  0x021D0A48
 * packet:   pkt_ov021_021D0A48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj20290.h"
#include "../include/Obj20291.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020307B0(void *p);

void TRIAL_HOUSE_DeleteWork(void *a, u8 **pp)
{
    if (*pp != 0) {
        func_020307B0(((struct Obj20290 *)(*pp))->f14C);
        func_020307B0(((struct Obj20291 *)(*pp))->f128);
        func_020307B0(*pp);
        *pp = 0;
    }
}

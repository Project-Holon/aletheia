/*
 * function: func_02162458
 * address:  0x02162458
 * packet:   pkt_ov010_02162458
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled thumb leaf (ldr r0,[r0,#0x34]; bx lr), the sole blocker of
 * ov021 func_021892CC (lane S26).
 * symbols:
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18957.h"

typedef unsigned char u8;
typedef unsigned int  u32;

u32 func_02162458(u8 *p)
{
    return ((struct Obj18957 *)p)->f34;
}

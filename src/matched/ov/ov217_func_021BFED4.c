/*
 * function: func_021BFED4
 * address:  0x021BFED4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 720)), 720 to ARROW_Destroy.
 *
 * symbols:
 *   ARROW_Destroy  0x021C209C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25956.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 ARROW_Destroy(void *a0);

void func_021BFED4(u8 *a0)
{
    ARROW_Destroy((void *)(((struct Obj25956 *)a0)->f2D0));
}


/*
 * function: func_021BD3A4
 * address:  0x021BD3A4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 300)), 300 to BMP_OAM_DeleteSys.
 *
 * symbols:
 *   BMP_OAM_DeleteSys  0x02025588  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25886.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void BMP_OAM_DeleteSys(void *p);

void func_021BD3A4(u8 *a0)
{
    BMP_OAM_DeleteSys((void *)((u32)(((struct Obj25886 *)a0)->f12C)));
}


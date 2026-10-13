/*
 * function: MCSS_SetLoadHook
 * address:  0x02014CF0
 * packet:   pkt_0201394C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Two consecutive word stores through the object pointer - a plain field
 * pair setter with no prologue, so no label, attested by the pool word
 * 0x02014CF1.  The stores are in source order.
 *
 
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MCSS_SetLoadHook.c \
 *       --func MCSS_SetLoadHook --addr 0x02014CF0 --cc 1.1p1 --thumb
 */
#include "../include/Obj11718.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


struct Obj02014CF0;

void MCSS_SetLoadHook(struct Obj02014CF0 *o, int v1, int v2)
{
    ((struct Obj11718 *)o)->f38 = v1;
    ((struct Obj11718 *)o)->f3C = v2;
}


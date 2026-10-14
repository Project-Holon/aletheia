/*
 * function: RingQueue_FreeBuffer
 * address:  0x021C0E98
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to func_020307B0.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26003.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 func_020307B0(void *p);

void RingQueue_FreeBuffer(u8 *a0)
{
    func_020307B0((void *)((u32)(((struct Obj26003 *)a0)->f0)));
}


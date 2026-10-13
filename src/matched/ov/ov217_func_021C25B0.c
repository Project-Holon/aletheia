/*
 * function: func_021C25B0
 * address:  0x021C25B0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Store the result of functional call CLACT_CreateUnit(0x1a, 0, p->h0) into p->w4.
 *
 * symbols:
 *   func_021C25B0  0x021C25B0  thumb  ov217
 *   CLACT_CreateUnit  0x0204B100  arm  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03378.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
void func_021C25B0(u8 *p)
{
    ((struct Obj03378 *)p)->f4 = (u32)CLACT_CreateUnit(0x1a, 0, ((struct Obj03378 *)p)->f0);
}


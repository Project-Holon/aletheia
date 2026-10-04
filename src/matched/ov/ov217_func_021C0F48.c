/*
 * function: func_021C0F48
 * address:  0x021C0F48
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two-call wrapper: field +0x18, then the object itself.
 *
 * symbols:
 *   func_021C0F48  0x021C0F48  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26004.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
extern void func_020307B0(void *p);
void func_021C0F48(u8 *p)
{
    func_020452E8((struct Descriptor *)(((struct Obj26004 *)p)->f18));
    func_020307B0(p);
}


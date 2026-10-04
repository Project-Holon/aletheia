/*
 * function: func_021C112C
 * address:  0x021C112C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C124C  0x021C124C  thumb  ov217
 *   func_021C13E8  0x021C13E8  thumb  ov217
 *   func_021C14DC  0x021C14DC  thumb  ov217
 *   func_021C1D24  0x021C1D24  thumb  ov217
 *
 * When func_021C1D24() reports 1 and the +8 field is set, runs the
 * +0x3C update triplet.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26006.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_021C124C(u8 *p);
extern void func_021C13E8(u8 *p);
extern void func_021C14DC(u8 *p);
extern u32 func_021C1D24(void *);
void func_021C112C(u8 *p)
{
    if (func_021C1D24(p) == 1) {
    if (((struct Obj26006 *)p)->f8 != 0) {
    func_021C14DC(p);
    func_021C124C(p);
    func_021C13E8(p);
    }
    }
}

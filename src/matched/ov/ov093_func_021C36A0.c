/*
 * function: func_021C36A0
 * address:  0x021C36A0
 * packet:   pkt_ov093_021C36A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D5FB8  0x021D5FB8  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 */
#include "../include/Obj09970.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern void func_021D5FB8(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);

void func_021C36A0(u8 *p, u8 *a, u16 *b, int c)
{
    int i = func_021D5440(a);
    func_021D5FB8(a);
    func_021CD4B0(((struct Obj09970 *)p)->fC, 3, i);
    func_021CD4B0(((struct Obj09970 *)p)->fC, 0x32, i, (u8)c, *b);
    func_021CD4B0(((struct Obj09970 *)p)->fC, 0x34, i);
}

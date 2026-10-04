/*
 * function: func_021C3720
 * address:  0x021C3720
 * packet:   pkt_ov093_021C3720
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6D90  0x021D6D90  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021C41C0  0x021C41C0  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern int func_021D6D90(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C41C0(u8 *p, u8 *a);

u16 func_021C3720(u8 *p, u8 *a, u16 *b, int c)
{
    int i = func_021D5440(a);
    u16 v = func_021D6D90(a);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x34, i);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x32, i, (u8)c, *b);
    func_021C41C0(p, a);
    return v;
}

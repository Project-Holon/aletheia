/*
 * function: func_021BD3E8
 * address:  0x021BD3E8
 * packet:   pkt_ov093_021BD3E8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9C98  0x021B9C98  thumb  ov093
 *   func_021BD43C  0x021BD43C  thumb  ov093
 *   func_021C5D88  0x021C5D88  thumb  ov093
 *   func_021BD4E4  0x021BD4E4  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern u8 func_021B8DDC(u32 x);
extern char *func_021B9AEC(char *p, int i);
extern int func_021B9C98(char *p, u8 *a);
extern void func_021BD43C(u8 *p, int i, u8 a, u8 b, int c);
extern void func_021C5D88(u8 *p, u8 *a, int b);
extern void func_021BD4E4(u8 *p, int i, u8 a, u8 b);

void func_021BD3E8(u8 *p, u8 *a)
{
    int i;
    int r;
    i = func_021B8DDC(func_021D5440(a));
    r = func_021B9C98(func_021B9AEC(*(char * *)&((struct Obj00003 *)p)->f8, i), a);
    if (r == 0 || r == 2) {
        func_021BD43C(p, i, r, 1, 0);
        func_021C5D88(p, a, 0xe7);
        func_021BD4E4(p, i, r, 1);
    }
}

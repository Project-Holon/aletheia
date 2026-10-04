/*
 * unit:     yes
 * function: func_021E732C, func_021E737C
 * address:  0x021E732C
 * packet:   pkt_ov093_021E732C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E8CF0  0x021E8CF0  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F27F4     0x021F27F4  data   ov093  a4
 */
#include "../include/Obj13541.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern u8 *func_021C88A4(int a, int k, int c);
extern u16 func_021E8CF0(int a);
extern void func_021C88C8(void *a, void *b);
extern int d_021F27F4[];

void func_021E732C(int a, int b, int c)
{
    u32 i;
    u32 n;
    u8 *p;

    if (c == func_021D775C(3)) {
        n = func_021D775C(5);
        for (i = 0; i < n; i++) {
            p = func_021C88A4(b, 0x14, c);
            ((struct Obj13541 *)p)->f4 = func_021E8CF0(10);
            ((struct Obj13541 *)p)->f6 = func_021D775C(i + 6);
            func_021C88C8((void *)b, p);
        }
    }
}

int *func_021E737C(int *p)
{
    *p = 1;
    return d_021F27F4;
}

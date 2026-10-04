/*
 * function: func_021A5408
 * address:  0x021A5408
 * packet:   pkt_ov021_021A5408
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A572C  0x021A572C  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09570.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021A572C(u32);
extern u32 func_0216D5F8(void);
extern void func_0216D4B4(char *p);
extern void func_0216D5E0(int a0, int a1);
extern void func_0216D674(void *p, u16 v);
extern void func_021A3964(u8 *p, u32 v);

int func_021A5408(u32 a)
{
    u32 x;
    u32 y;
    switch (((struct Obj09570 *)a)->f0) {
    case 0:
        break;
    case 1:
        return 0;
    case 2:
    case 3:
        x = func_021A572C(a);
        y = func_0216D5F8();
        func_0216D4B4((char *)x);
        func_0216D5E0(x, y);
        func_0216D674((void *)x, 0);
        func_021A3964((u8 *)(*(u32 *)&((struct Obj09570 *)a)->fC), 0);
        break;
    }
    return 1;
}

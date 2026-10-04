/*
 * function: func_021637E4
 * address:  0x021637E4
 * packet:   pkt_ov010_021637E4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216DC34  0x0216DC34  thumb  ov010
 *   func_02163F40  0x02163F40  thumb  ov010
 *   func_0216DC18  0x0216DC18  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021AB440  0x021AB440  thumb  ov021
 *   func_021AB358  0x021AB358  thumb  ov021
 *   func_021BBFB8  0x021BBFB8  thumb  ov021
 */
#include "../include/Obj00110.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_0216DC34(void *a0);
typedef unsigned int   u32;
extern int func_02163F40(int a, int dir);
extern void func_0216DC18();
extern void *func_0216D67C(void *a0);
extern u16 func_021AB0F0(u32 attr);
extern u16 func_021AB0F8(u32 attr);
extern int func_021AB440();
extern int func_021AB358(int x);
extern void func_021BBFB8(u32 a, u32 b, u32 c, u32 d);

void func_021637E4(int a, int q)
{
    int r4, r7, s;
    u8 *t = *(u8 * *)&((struct Obj00110 *)q)->f10;

    if (t[6] == 0) {
        return;
    }
    if (func_0216DC34((void *)a) != 0) {
        return;
    }
    r4 = -1;
    if (((struct Obj00110 *)q)->fE & 0x40) {
        r4 = *(int *)(q + 4);
    } else {
        r7 = func_02163F40(a, 1);
        if (func_021AB0F8(r7) & 0x40) {
            r4 = r7;
        }
    }
    if (r4 == -1) {
        return;
    }
    r7 = 1;
    r4 = func_021AB0F0(r4);
    s = (int)func_0216D67C((void *)a);
    if (func_021AB440(r4) == 1 || func_021AB358(r4) == 1) {
        r7 = 2;
    }
    func_021BBFB8(s, a, ((struct Obj00110 *)q)->f14, r7);
    func_0216DC18(a, 1);
}

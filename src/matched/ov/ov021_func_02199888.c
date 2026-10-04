/*
 * function: func_02199888
 * address:  0x02199888
 * packet:   pkt_ov021_02199888
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D600  0x0216D600  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DA70  0x0216DA70  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D848  0x0216D848  thumb  ov010
 *   func_0216D860  0x0216D860  thumb  ov010
 *   func_0216D87C  0x0216D87C  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04222.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u8 *func_0216D6BC(u32, u32);
extern void func_0216D5E0(int a0, int a1);
extern u32 func_0216D600(u32, u32);
extern void func_0216D674(void *p, u16 v);
extern u32 func_0216DA70(u32);
extern int func_0216D83C(void *p);
extern u32 func_0216D80C(u32, u32);
extern int func_0216D854(void *p);
extern u32 func_0216D818(u32, u32);
extern int func_0216D86C(void *p);
extern u32 func_0216D824(u32, u32);
extern void func_0216D848(char *p, short v);
extern void func_0216D860(char *p, short v);
extern void func_0216D87C(char *p, short v);
extern u32 func_0216D7CC(u32);

void func_02199888(u32 a, int b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h, u8 i)
{
    u8 *q;
    int dir;

    dir = 1;
    q = func_0216D6BC(a, 16);
    q[0] = e;
    ((struct Obj04222 *)q)->f4 = b;
    q[2] = g;
    q[1] = h;
    q[3] = i;
    ((struct Obj04222 *)q)->fE = 0x1000 / q[0];
    func_0216D5E0(a, (u16)c);
    func_0216D600(a, (u16)d);
    func_0216D674((void *)a, f);
    func_0216DA70(a);
    func_0216D80C(a, func_0216D83C((void *)a));
    func_0216D818(a, func_0216D854((void *)a));
    func_0216D824(a, func_0216D86C((void *)a));
    if (b != 0) {
        switch (g) {
        case 0:
            if (b < 0)
                dir = -1;
            func_0216D848((char *)a, dir);
            break;
        case 1:
            if (b < 0)
                dir = -1;
            func_0216D860((char *)a, dir * 2);
            break;
        case 2:
            if (b < 0)
                dir = -1;
            func_0216D87C((char *)a, dir);
            break;
        }
    }
    func_0216D7CC(a);
}

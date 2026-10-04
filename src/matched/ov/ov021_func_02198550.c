/*
 * function: func_02198550
 * address:  0x02198550
 * packet:   pkt_ov021_02198550
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_02163FC0  0x02163FC0  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_02163E7C  0x02163E7C  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   d_021DDBD4     0x021DDBD4  data   ov021  a4
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01032.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;

extern void *func_0216D6D4(void *p);
extern void func_02163FC0(int a, int dir, int amt);
extern int func_02164010(int a);
extern void func_02163E7C(int a, int b);
extern void func_0216D568(void *p, u32 v);
extern int *d_021DDBD4[];
extern void func_0216D8C0(u32, Vec *);
extern void func_02163F10(u32);
extern void func_0216D674(void *p, u16 v);
extern void func_0216D7CC(u8 *p);
extern void func_020061E4(u32);

int func_02198550(u32 a)
{
    u8 *h;

    h = func_0216D6D4((void *)a);
    if (((struct Obj01032 *)h)->f0 != 0) {
        func_02163FC0(a, ((struct Obj01032 *)h)->fC, ((struct Obj01032 *)h)->f0);
        func_02164010(a);
        if (((struct Obj01032 *)h)->f4 >= 0x10000) {
            ((struct Obj01032 *)h)->f4 = 0;
            func_02163E7C(a, ((struct Obj01032 *)h)->fC);
            func_0216D568((void *)a, 0x20);
        }
        ((struct Obj01032 *)h)->f4 += (((struct Obj01032 *)h)->f0 < 0) ? -((struct Obj01032 *)h)->f0 : ((struct Obj01032 *)h)->f0;
    }
    ((struct Obj01032 *)h)->fA += ((struct Obj01032 *)h)->f8;
    if (((struct Obj01032 *)h)->fA > 0xF00) {
        ((struct Obj01032 *)h)->fA = 0xF00;
    }
    {
        Vec v;
        u16 k;
        int i;
        k = ((struct Obj01032 *)h)->fA / 256;
        i = ((struct Obj01032 *)h)->fF;
        v.x = 0;
        v.y = d_021DDBD4[i][k];
        v.z = 0;
        func_0216D8C0(a, &v);
    }
    ((struct Obj01032 *)h)->fD = ((struct Obj01032 *)h)->fD - 1;
    if (((struct Obj01032 *)h)->fD > 0) {
        return 0;
    }
    {
        Vec v = { 0, 0, 0 };
        func_0216D8C0(a, &v);
    }
    func_0216D568((void *)a, 0x540);
    func_02163F10(a);
    func_0216D674((void *)a, 0);
    func_0216D7CC((u8 *)a);
    func_020061E4(0x67B);
    return 1;
}

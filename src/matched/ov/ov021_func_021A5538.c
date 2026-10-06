/*
 * function: func_021A5538
 * address:  0x021A5538
 * packet:   pkt_ov021_021A5538
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_021A5264  0x021A5264  thumb  ov021
 *   func_021A550C  0x021A550C  thumb  ov021
 *   func_021A5354  0x021A5354  thumb  ov021
 *   func_021A3964  0x021A3964  thumb  ov021
 *   func_021A5328  0x021A5328  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06014.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021A3960(unsigned char *p);
extern u16 func_0216D608(void *p);
extern int func_021A5264(u8 *a, void *b, u32 c, int *d);
extern void func_021A550C(u32 *p);
extern void func_021A5354(u32 a);
extern void func_021A3964(u8 *p, u32 v);
extern void func_021A5328(u32 a);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *a0, int a1);
extern u32 *func_0216D548(u32 *p, u32 v); /* its third parameter is a scratch it never reads */

int func_021A5538(u8 *a)
{
    int v;
    void *x = func_021A3960(*(unsigned char * *)&((struct Obj06014 *)a)->fC);
    u32 y = func_0216D608(x);
    if (func_021A5264(a, x, y, &v) != 0) {
        func_021A550C((u32 *)a);
        func_021A5354((u32)a);
        func_021A3964(*(u8 * *)&((struct Obj06014 *)a)->fC, 0);
        return 0;
    }
    func_021A5328((u32)a);
    func_0216D410(x, func_02197E7C(y, 0x10));
    func_0216D548(x, 0x18);
    ((struct Obj06014 *)a)->f0 = 1;
    func_021A3964(*(u8 * *)&((struct Obj06014 *)a)->fC, 1);
    return 1;
}

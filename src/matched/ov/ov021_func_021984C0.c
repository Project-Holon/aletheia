/*
 * function: func_021984C0
 * address:  0x021984C0
 * packet:   pkt_ov021_021984C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_02163E7C  0x02163E7C  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05004.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *func_0216D6BC(int a0, int a1, int a2);
extern int func_02163F10(int a0);
extern void func_02163E7C(int a, int b);
extern void *func_0216D568(void *p, u32 v);
extern int func_0216D60C(int a0, int a1);
extern void func_0216D674(void *p, u16 v);
extern void func_0216D7CC(u8 *);
extern void func_020061E4(void);

void func_021984C0(u8 *a, u32 b, u32 c, u32 d, u16 e, s16 f, u16 g, u32 h)
{
    u8 *r;

    r = func_0216D6BC((int)a, (u32)16, c);
    r[12] = b;
    ((struct Obj05004 *)r)->f0 = c;
    r[13] = d;
    r[14] = e;
    r[15] = f;
    ((struct Obj05004 *)r)->f8 = g;
    if (c == 0) {
        func_02163F10((int)a);
    } else {
        func_02163E7C((int)a, (u16)b);
    }
    func_0216D568(a, 0xa0);
    func_0216D60C((int)a, (u16)b);
    func_0216D674(a, e);
    func_0216D7CC(a);
    if (h != 0) {
        func_020061E4();
    }
}

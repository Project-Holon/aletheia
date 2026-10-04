/*
 * function: func_021858B8
 * address:  0x021858B8
 * packet:   pkt_ov023_021858B8
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_02185354  0x02185354  thumb  ov023
 *   func_0218654C  0x0218654C  thumb  ov023
 */
#include "../include/Obj20355.h"

struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
extern u32 func_0203D1C0(u32 index);
struct Link;
extern u32 func_02039CB4(struct Link *h, u32 a, u32 b);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_02185354(char *p);
extern int  func_0218654C(char *p);

int func_021858B8(char *p, int a1)
{
    int h;
    int i;
    int mask;

    h = (int)func_020399A8();
    mask = 0;
    for (i = 0; i < 5; i++) {
        if (func_0203D1C0((unsigned char)i) == 1)
            mask |= 1 << i;
    }
    if (func_02039CB4((struct Link *)h, 0xc8, 0x29) != 0 || func_0218654C(p) == 1
        || mask != ((struct Obj20355 *)p)->f1B0) {
        func_0202208C(0, 8, 8, 0, 0x10, 1, 0x28);
        a1 = 3;
    }
    func_02185354(p);
    return a1;
}

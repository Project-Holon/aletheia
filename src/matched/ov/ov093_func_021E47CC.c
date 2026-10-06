/*
 * function: func_021E47CC
 * address:  0x021E47CC
 * packet:   pkt_ov093_021E47CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E89C0  0x021E89C0  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj10090.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern int func_021E89C0(void);
extern void func_021C88C8(void *a, void *b);

void func_021E47CC(int a0, u8 *s, int k)
{
    u8 v;
    u8 *q;
    u8 *e;

    if (k == func_021D775C(3)) {
        v = func_021D775C(6);
        q = func_021C7CF4((int *)s, v);
        if (func_021D62C4((struct Unk021D62A8 *)q, 12) == 0) {
            e = func_021C88A4((char *)s, 12, k);
            ((struct Obj10090 *)e)->f4 = 12;
            ((struct Obj10090 *)e)->f8 = func_021E89C0();
            e[0xf] = v;
            func_021C88C8(s, e);
        }
    }
}

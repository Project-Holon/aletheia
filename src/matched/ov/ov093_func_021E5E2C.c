/*
 * function: func_021E5E2C
 * address:  0x021E5E2C
 * packet:   pkt_ov093_021E5E2C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj21516.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
struct QI;
extern u16 func_021D5B40(struct QI *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021E5E2C(u8 *p, void *a, int b, int *c)
{
    void *r;
    u8 *q;
    if (b != func_021D775C(2))
        return;
    if (*c != 0)
        return;
    r = func_021C7CF4(a, b);
    if ((u16)(u32)func_021D5B40(r) != 0) {
        q = func_021C88A4(a, 0x23, b);
        ((struct Obj21516 *)q)->f4 = 1;
        func_021C88C8(a, q);
    }
}

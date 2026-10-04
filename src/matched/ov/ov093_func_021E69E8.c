/*
 * function: func_021E69E8
 * address:  0x021E69E8
 * packet:   pkt_ov093_021E69E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5C30  0x021D5C30  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */
#include "../include/Obj07834.h"
#include "../include/Obj13538.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5C30(struct UtilWork *p);
extern int func_021C8010(u8 *p, unsigned int v);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);

void func_021E69E8(int x, void *a, int c)
{
    u8 *p;
    u8 *q;

    if (c == func_021D775C(2)) {
        p = func_021C88A4(a, 0x15, c);
        p[8] = c;
        ((struct Obj13538 *)p)->f4 = 5;
        func_021C88C8(a, p);
        if (func_021D5C30(func_021C7CF4(a, c)) == 0) {
            q = func_021C88A4(a, 0x37, c);
            ((struct Obj07834 *)q)->f4 = 0x272;
            q[6] = func_021C8010(a, c);
            q[7] = 6;
            q[0xb] = 1;
            func_021C88C8(a, q);
        }
        p = func_021C88A4(a, 4, c);
        func_021C8838(p + 4, 2, 0x268);
        func_021C8860((struct S *)(p + 4), c);
        func_021C88C8(a, p);
    }
}

/*
 * function: func_021DD7B8
 * address:  0x021DD7B8
 * packet:   pkt_ov093_021DD7B8
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
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D5844  0x021D5844  thumb  ov093
 *   func_020189D0  0x020189D0  thumb
 *   func_021D7DC0  0x021D7DC0  thumb  ov093
 */
#include "../include/Obj07817.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern void *func_021C88A4(void *a, int k, int b);
extern int func_021DCFF8(int a, int b);
struct QQ;
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C8838(void *l, int a, int b);
struct S;
extern void func_021C8860(struct S *l, u32 v);
extern u16 func_021D70A8(struct QQ *p);
extern void func_021C88C8(void *a, void *b);
extern void *func_021D5844(void *m);
extern int func_020189D0(void *m, int b);
extern void func_021D7DC0(int a, void *b, void *out);

void func_021DD7B8(int a, u8 *b, int c, int *d, int e)
{
    void *m;
    u8 *p;
    if (*d == 0 && c == func_021D775C(2)) {
        m = func_021C7CF4(b, c);
        p = func_021C88A4(b, 5, c);
        p[6] = c;
        *(u16 *)&((struct Obj07817 *)p)->f4 = func_021D7B74(m, func_021DCFF8(a, 2));
        func_021C8838(p + 8, 2, 908);
        func_021C8860((struct S *)(p + 8), c);
        func_021C8860((struct S *)(p + 8), func_021D70A8((void *)a));
        func_021C88C8(b, p);
        if (func_020189D0(func_021D5844(m), e) == -1) {
            p = func_021C88A4(b, 0xc, c);
            p[0xf] = c;
            ((struct Obj07817 *)p)->f4 = 6;
            func_021D7DC0(6, m, p + 8);
            func_021C88C8(b, p);
        }
        *d = 1;
    }
}

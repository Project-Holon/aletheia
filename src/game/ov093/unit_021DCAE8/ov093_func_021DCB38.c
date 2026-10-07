/*
 * function: func_021DCB38
 * address:  0x021DCB38
 * packet:   pkt_ov093_021DCB38
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
 *   func_021D6740  0x021D6740  thumb  ov093
 *   func_020213C0  0x020213C0  thumb
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021D85C0  0x021D85C0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../../../matched/include/Obj07816.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
struct QI;
struct QK;
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D6740(struct QK *p);
extern int func_020213C0(u32 a);
extern u16 func_021D5B40(struct QI *p);
extern int func_021C8288(u8 *p);
extern int func_021D85C0(int a, u32 b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021DCB38(int a, void *b, int c)
{
    u8 *m;
    void *mon;
    u32 n;

    if (c == func_021D775C(2)) {
        mon = func_021C7CF4(b, c);
        n = func_021D6740(mon);
        if (n != 0 && func_020213C0(n) != 0 && func_021D5B40(mon) == 0
            && (func_021C8288(b) == 1 || func_021D85C0((int)b, 0x32) != 0)) {
            m = (u8 *)func_021C88A4(b, 0x20, c);
            ((struct Obj07816 *)m)->f0 |= 0x20 << 18;
            ((struct Obj07816 *)m)->f4 = n;
            m[6] = c;
            m[7] = 1;
            func_021C8838(m + 0xc, 2, 0x1db);
            func_021C8860((struct S *)(m + 0xc), c);
            func_021C8860((struct S *)(m + 0xc), n);
            func_021C88C8(b, m);
        }
    }
}

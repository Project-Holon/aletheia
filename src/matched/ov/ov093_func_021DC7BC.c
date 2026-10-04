/*
 * function: func_021DC7BC
 * address:  0x021DC7BC
 * packet:   pkt_ov093_021DC7BC
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
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
struct QF;
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(struct QF *p);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021DC7BC(int a, void *b, int c)
{
    u8 *m;

    if (c == func_021D775C(2)) {
        if (func_021D5444(func_021C7CF4(b, c)) == 0x22b) {
            m = (u8 *)func_021C88A4(b, 0x39, c);
            m[4] = c;
            m[5] = 0;
            func_021C8838(m + 8, 1, 0xba);
            func_021C8860((struct S *)(m + 8), c);
            func_021C88C8(b, m);
        }
    }
}

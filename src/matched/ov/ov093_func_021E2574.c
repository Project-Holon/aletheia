/*
 * function: func_021E2574
 * address:  0x021E2574
 * packet:   pkt_ov093_021E2574
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, unsigned v);
extern void *func_021C88A4(void *p, int a, int b);
extern void func_021C8838(void *p, int a, u16 b);
struct S;
extern void func_021C8860(struct S *p, unsigned int val);
extern void func_021C88C8(void *a, void *b);

void func_021E2574(int a, void *b, int c, int *d)
{
    char *p;
    u8 u;

    if (d[6] != 0 && func_021D775C(0x1D) == 2 && func_021D76BC(0x41, 1) != 0) {
        p = func_021C88A4(b, 4, c);
        u = func_021D775C(4);
        func_021C8838(p + 4, 2, u == c ? 0x2C8 : 0x2C5);
        func_021C8860((struct S *)(p + 4), u);
        func_021C88C8(b, p);
    }
}

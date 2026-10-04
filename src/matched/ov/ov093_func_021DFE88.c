/*
 * function: func_021DFE88
 * address:  0x021DFE88
 * packet:   pkt_ov093_021DFE88
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7F24  0x021C7F24  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8;
extern int func_021D775C(int key);
extern int func_021C7F24(u8 *p, int i);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, unsigned int v);
extern void func_021C88C8(void *a, void *b);

void func_021DFE88(int a, void *b, int c)
{
    char *p;
    char *q;

    if (c == func_021D775C(2) && func_021C7F24(b, c) != 0) {
        p = func_021C88A4(b, 4, c);
        func_021C8838(p + 4, 2, 0x19e);
        func_021C8860((struct S *)(p + 4), c);
        func_021C88C8(b, p);
        q = func_021C88A4(b, 0x29, c);
        *(u8 *)(q + 0x4c) = c;
        func_021C88C8(b, q);
    }
}

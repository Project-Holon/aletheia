/*
 * function: func_021D92CC
 * address:  0x021D92CC
 * packet:   pkt_ov093_021D92CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021D775C(int);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021D92CC(void *a, int b, int *c, int d)
{
    int t;
    u8 *p;

    if (b == func_021D775C(2) && c[0] != 0) {
        t = func_021D775C(0x19);
        if (t == 0 || c[1] != t) {
            func_021C88B4(a, 2, b);
            p = func_021C88A4(a, 4, b);
            func_021C8838(p + 4, 2, d);
            func_021C8860((struct S *)(p + 4), b);
            func_021C88C8(a, p);
            func_021C88B4(a, 3, b);
            c[1] = t;
        }
        c[0] = 0;
    }
}

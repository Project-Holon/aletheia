/*
 * function: func_021E0628
 * address:  0x021E0628
 * packet:   pkt_ov093_021E0628
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 */
typedef unsigned short u16;
extern int func_021D775C(int key);
extern int func_021EF948(int k);
extern void *func_021C88A4(void *a, int k, int b);
extern int func_021E8940(int v);
extern void func_021C88C8(void *a, void *b);
extern void func_021C88B4(void *a, int k, int b);

struct S {
    int f0;
    int f4;
    int f8;
    int fC;
    u16 f10;
    u16 f12;
};

void func_021E0628(int a, void *b, int c)
{
    struct S *p;

    if (c == func_021D775C(3)) {
        if (func_021EF948(2) == 0) {
            p = func_021C88A4(b, 0x1b, c);
            p->f4 = 2;
            p->f8 = func_021E8940(5);
            p->f12 = (p->f12 & ~0xff) | 1;
            p->f10 = 0x75;
            func_021C88C8(b, p);
            func_021C88B4(b, 0x35, c);
        }
    }
}

/*
 * function: func_021E3A78
 * address:  0x021E3A78
 * packet:   pkt_ov093_021E3A78
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021E3C5C  0x021E3C5C  thumb  ov093
 */

extern int func_021D775C(int);
extern char *func_021C88A4(void *a, int k, int c);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(char *p, int a);
extern void func_021C88C8(void *a, void *p);
extern void func_021E3C5C(void *a, int c, int d);

void func_021E3A78(int u, void *a, int c, int *w)
{
    char *p;

    if (c == func_021D775C(3)) {
        p = func_021C88A4(a, 4, c);
        func_021C8838(p + 4, 2, 0x1ff);
        func_021C8860(p + 4, c);
        func_021C88C8(a, p);
        w[6] = 1;
        func_021E3C5C(a, c, 0);
    }
}

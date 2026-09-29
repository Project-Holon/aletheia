/*
 * function: func_021E3D38
 * address:  0x021E3D38
 * packet:   pkt_ov093_021E3D38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

extern int func_021D775C(int);
extern void func_021C8838(int p, int a, int b);
extern void func_021C8860(int p, int a);
extern void func_021D76BC(int a, int b);

void func_021E3D38(int u, int v, int c, int *w)
{
    int p;

    if (c == func_021D775C(2)) {
        p = func_021D775C(0x3f);
        switch (w[0]) {
        case 1:
            func_021C8838(p, 2, 0x2e9);
            func_021C8860(p, c);
            func_021D76BC(0x51, 1);
            break;
        case 2:
            func_021C8838(p, 2, 0x2ec);
            func_021C8860(p, c);
            func_021D76BC(0x51, 1);
            break;
        }
    }
}

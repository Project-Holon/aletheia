/*
 * function: func_021E19C0
 * address:  0x021E19C0
 * packet:   pkt_ov137_021E19C0
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02039338   0x02039338  arm
 *   func_021E1604   0x021E1604  thumb  ov137
 *   func_021DCBC4   0x021DCBC4  thumb  ov137
 */

extern int func_02039338(void);
extern void func_021E1604(char *, int);
extern void func_021DCBC4(int, int, void *, int);

void func_021E19C0(char *r4, int r5)
{
    struct {
        int a;
        int b;
        short h[6];
    } buf;
    int i;

    if (func_02039338() != 0)
        return;
    func_021E1604(r4, r5);
    buf.a = *(int *)(r4 + 0x11C);
    buf.b = *(int *)(r4 + 0x33C);
    for (i = 0; i < *(int *)(r4 + 0x30); i++) {
        int v = *(int *)(r4 + 0x2FC + i * 0xB4);
        buf.h[i] = (short)(v / 4096);
    }
    func_021DCBC4(*(int *)(r4 + 0xDC), 0x2808, &buf, 0x14);
}

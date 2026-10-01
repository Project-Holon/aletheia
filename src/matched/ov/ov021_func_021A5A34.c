/*
 * function: func_021A5A34
 * address:  0x021A5A34
 * packet:   pkt_ov021_021A5A34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 */

typedef unsigned int u32;

int func_0216D5F8(u32 h);
void func_0216D4B4(u32 h);
void func_0216D5E0(u32 h, int v);
void func_0216D674(u32 h, int a);
void func_021A3964(u32 h, int s);

void func_021A5A34(u32 *p)
{
    u32 h;
    int v;

    if (p[0] == 3) {
        h = p[7];
        v = func_0216D5F8(h);
        func_0216D4B4(h);
        func_0216D5E0(h, v);
        func_0216D674(h, 0);
        func_021A3964(p[5], 0);
    }
}

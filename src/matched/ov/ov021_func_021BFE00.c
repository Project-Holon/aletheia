/*
 * function: func_021BFE00
 * address:  0x021BFE00
 * packet:   pkt_ov021_021BFE00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns a 0x7C-byte task (callback func_021C04C0).
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021C04C0  0x021C04C0  thumb  ov021
 */

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void *func_020124E8(void *p);
void func_021C04C0(void);

void *func_021BFE00(int a0, void *p, int a2)
{
    void *t = func_020122C0(p, a0, func_021C04C0, 0x7C);
    int *w = func_020124E8(t);

    w[0] = (int)p;
    w[1] = a2;
    w[3] = 0;
    return t;
}

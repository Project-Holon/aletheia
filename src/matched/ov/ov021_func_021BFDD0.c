/*
 * function: func_021BFDD0
 * address:  0x021BFDD0
 * packet:   pkt_ov021_021BFDD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns a 0x7C-byte task (callback func_021C0398).
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021C0398  0x021C0398  thumb  ov021
 */

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void *func_020124E8(void *p);
void func_021C0398(void);

void *func_021BFDD0(int a0, void *p, int a2, int a3)
{
    void *t = func_020122C0(p, a0, func_021C0398, 0x7C);
    int *w = func_020124E8(t);

    w[0] = (int)p;
    w[1] = a2;
    w[3] = 0;
    w[4] = a3;
    return t;
}

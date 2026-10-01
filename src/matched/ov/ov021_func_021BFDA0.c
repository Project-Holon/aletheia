/*
 * function: func_021BFDA0
 * address:  0x021BFDA0
 * packet:   pkt_ov021_021BFDA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns a 0x7C-byte task (callback func_021C021C).
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021C021C  0x021C021C  thumb  ov021
 */

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void *func_020124E8(void *p);
void func_021C021C(void);

void *func_021BFDA0(int a0, void *p, int a2, int a3)
{
    void *t = func_020122C0(p, a0, func_021C021C, 0x7C);
    int *w = func_020124E8(t);

    w[0] = (int)p;
    w[1] = a2;
    w[3] = 0;
    w[29] = 0;
    w[30] = a3;
    return t;
}

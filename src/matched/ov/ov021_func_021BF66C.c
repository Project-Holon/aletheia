/*
 * function: func_021BF66C
 * address:  0x021BF66C
 * packet:   pkt_ov021_021BF66C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns a 0x68-byte task (callback func_021BFC98) and stores its owner and argument.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BFC98  0x021BFC98  thumb  ov021
 */

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void *func_020124E8(void *p);
void func_021BFC98(void);

void *func_021BF66C(int a0, void *p, int a2)
{
    void *t = func_020122C0(p, a0, func_021BFC98, 0x68);
    int *w = func_020124E8(t);

    w[1] = a2;
    w[0] = (int)p;
    return t;
}

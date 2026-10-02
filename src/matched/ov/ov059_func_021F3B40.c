/*
 * function: func_021F3B40
 * address:  0x021F3B40
 * packet:   pkt_ov059_021F3B40
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F3C6C  0x021F3C6C  thumb  ov059
 */

extern void *func_0201210C(const void *p);
extern int *func_021897BC(char *p, int idx);
extern void *func_020122C0(void *owner, void *a, int (*callback)(void *), unsigned int size);
extern int func_021F3C6C(void *p);

void func_021F3B40(void *p, int v)
{
    int *o;
    o = func_021897BC(func_0201210C(p), 1);
    func_020122C0(p, 0, func_021F3C6C, 0);
    *o = v;
}

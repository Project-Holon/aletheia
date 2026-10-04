/*
 * function: func_021F392C
 * address:  0x021F392C
 * packet:   pkt_ov044_021F392C
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 */

extern void  func_021BE700(void *p, int i, int j, int k, int flag);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(unsigned char *p, int v);

void func_021F392C(void *p)
{
    func_021BE700(p, 0, 0, 1, 1);
    func_021BE700(p, 0, 0, 0, 0);
    func_021BE6CC((int)p, 0, 0, 1, 0);
    p = func_021BE674(p, 0, 0, 1);
    func_021BE6B0(p, 1);
}

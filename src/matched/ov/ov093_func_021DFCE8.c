/*
 * function: func_021DFCE8
 * address:  0x021DFCE8
 * packet:   pkt_ov093_021DFCE8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021E8BD0  0x021E8BD0  thumb  ov093
 */

extern int func_021D775C(int key);
extern int func_021D76BC(int a, int b);
extern void func_021E8BD0(void *p, int a);

void func_021DFCE8(int a, int b, int c)
{
    int v;

    if (c != func_021D775C(3))
        return;
    v = func_021D775C(30);
    func_021E8BD0(&v, 1);
    func_021D76BC(30, v);
}

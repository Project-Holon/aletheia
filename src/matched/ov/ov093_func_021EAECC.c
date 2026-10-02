/*
 * function: func_021EAECC
 * address:  0x021EAECC
 * packet:   pkt_ov093_021EAECC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EAEF0  0x021EAEF0  thumb  ov093
 */
typedef unsigned char u8;
extern void func_021EAEF0(void *, void *);
void func_021EAECC(u8 *p, int v, int w)
{
    *(int *)(p + 0x160) = v;
    *(int *)(p + 0x164) = v;
    *(int *)(p + 0x16c) = w;
    func_021EAEF0(*(void **)(p + 0x180), p + 0x160);
}

/*
 * function: func_021EAEA8
 * address:  0x021EAEA8
 * packet:   pkt_ov093_021EAEA8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0689B780  0x0689B780  thumb  ov095
 */
typedef unsigned char u8;
extern void func_0689B780(void *, void *);
void func_021EAEA8(u8 *p, int v)
{
    *(int *)(p + 0x160) = v;
    *(int *)(p + 0x164) = v;
    *(int *)(p + 0x16c) = 3;
    func_0689B780(*(void **)(p + 0x180), p + 0x160);
}

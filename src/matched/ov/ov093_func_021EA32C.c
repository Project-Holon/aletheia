/*
 * function: func_021EA32C
 * address:  0x021EA32C
 * packet:   pkt_ov093_021EA32C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EAF00  0x021EAF00  thumb  ov093
 */
typedef unsigned char u8;

extern void func_021EAF00(u8 *p, int a);

void func_021EA32C(u8 *p, int k)
{
    int v;

    switch (k) {
    case 2:
        v = 0x563;
        break;
    case 3:
        v = 0x565;
        break;
    default:
        v = 0x564;
        break;
    }
    func_021EAF00(p, v);
}

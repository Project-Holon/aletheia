/*
 * function: func_021CFA04
 * address:  0x021CFA04
 * packet:   pkt_ov021_021CFA04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021CFA1C  0x021CFA1C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021CFA1C(int v, void *l);

int func_021CFA04(int a, int v, void *l)
{
    int r = 0;

    if (a != v) {
        r = func_021CFA1C(v, l);
    }
    return r;
}

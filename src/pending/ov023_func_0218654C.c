/*
 * function: func_0218654C
 * address:  0x0218654C
 * packet:   pkt_0218654C
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * symbols:
 *   func_021841A4  0x021841A4  thumb  ov023
 *
 * blocker: target 0x021841A4 has no witness outside the compared range
 *          (five overlays overlap the address; no func_ label found).
 */

typedef unsigned int u32;

void func_021841A4(u32 x);

void func_0218654C(char *p)
{
    func_021841A4(*(u32 *)*(u32 **)(p + 4));
}

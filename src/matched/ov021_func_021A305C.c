/*
 * function: func_021A305C
 * address:  0x021A305C
 * packet:   pkt_021A305C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021A392C  0x021A392C  thumb  ov021
 *
 * blocker: target 0x021A392C has no witness outside the compared range
 *          (ov009/ov021 overlap; the ov021 hint does not locate a func_ label).
 
 *
 * UNBLOCKED: func_021A392C is now an EXACT entry in layout/matched/ov021;
 * the call site resolves as matched, verdict promoted to EXACT.
*/

typedef unsigned int u32;

void func_021A392C(u32 x);

void func_021A305C(char *p)
{
    func_021A392C(*(u32 *)(p + 4));
}

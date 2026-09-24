/*
 * function: func_021C5078
 * address:  0x021C5078
 * packet:   pkt_021C5078
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   (none)

 * BLOCKED.  MATCH: the call at +0x08 targets 02015EA0, an ARM address with no label and no pool witness outside the compared range, so the site stays wildcarded.
 */


extern void func_02015EA0(int);
extern void func_02015BA4(int, int);

void func_021C5078(int a, int b)
{
    func_02015EA0(b);
    func_02015BA4(a, b);
}


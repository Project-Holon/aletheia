/*
 * function: func_021C5078
 * address:  0x021C5078
 * packet:   pkt_021C5078
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02015EA0  0x02015EA0  thumb

 * BLOCKED.  MATCH: the call at +0x08 targets 02015EA0, an ARM address with no label and no pool witness outside the compared range, so the site stays wildcarded.
 */


extern void func_02015EA0(void *p);
extern void func_02015BA4(void *sys, void *obj);

void func_021C5078(int a, int b)
{
    func_02015EA0((void *)b);
    func_02015BA4((void *)a, (void *)b);
}


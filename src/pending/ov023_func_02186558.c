/*
 * function: func_02186558
 * address:  0x02186558
 * packet:   pkt_02186558
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * symbols:
 *   func_021841A0  0x021841A0  thumb  ov023
 *
 * blocker: target 0x021841A0 has no witness outside the compared range
 *          (five overlays overlap the address; no func_ label found).
 */

typedef unsigned int u32;

void func_021841A0(u32 x);

void func_02186558(char *p)
{
    func_021841A0(*(u32 *)*(u32 **)(p + 4));
}

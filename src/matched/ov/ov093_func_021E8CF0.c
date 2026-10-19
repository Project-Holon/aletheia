/*
 * function: BTL_TYPEPAIR_MakeSingle
 * address:  0x021E8CF0
 * packet:   pkt_ov093_021E8CF0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_TYPEPAIR_Make  0x021E8CE0  thumb  ov093
 */

unsigned short BTL_TYPEPAIR_Make(unsigned int, unsigned int);

int BTL_TYPEPAIR_MakeSingle(int a)
{
    return BTL_TYPEPAIR_Make(a, a);
}

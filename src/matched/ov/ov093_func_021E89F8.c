/*
 * function: BTLV_CORE_MakeSlotKind1
 * address:  0x021E89F8
 * packet:   pkt_ov093_021E89F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, the only blocker of BTL_CALC_MakeSickContFromSpec's MATCH (case 1 of its
 * kind switch).  Sibling of BTLV_CORE_MakeSlotKind3: packs kind 1, a 6-bit field and a
 * 16-bit field into a one-word bitfield.
 */
typedef unsigned int u32;
struct S { unsigned a:3; unsigned b:6; unsigned c:16; unsigned d:7; };
int BTLV_CORE_MakeSlotKind1(u32 a, u32 b)
{
    struct S s = {0};
    s.a = 1;
    s.b = a & 0x3f;
    s.c = b;
    return *(int *)&s;
}

/*
 * function: func_021E89F8
 * address:  0x021E89F8
 * packet:   pkt_ov093_021E89F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, the only blocker of func_021D7C70's MATCH (case 1 of its
 * kind switch).  Sibling of func_021E899C: packs kind 1, a 6-bit field and a
 * 16-bit field into a one-word bitfield.
 */
typedef unsigned int u32;
struct S { unsigned a:3; unsigned b:6; unsigned c:16; unsigned d:7; };
int func_021E89F8(u32 a, u32 b)
{
    struct S s = {0};
    s.a = 1;
    s.b = a & 0x3f;
    s.c = b;
    return *(int *)&s;
}

/*
 * function: func_021E8AC8
 * address:  0x021E8AC8
 * packet:   pkt_ov093_021E8AC8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:

 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

union Slot {
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
};

void func_021E8AC8(union Slot *p, u32 v)
{
    if (p->s.kind == 3)
        p->s.lo = v;
    else if (p->s.kind == 4)
        p->s.hi = v;
}

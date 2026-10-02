/*
 * function: func_021E8A98
 * address:  0x021E8A98
 * packet:   pkt_ov093_021E8A98
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:

 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

union Slot {
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
};

u8 func_021E8A98(union Slot s)
{
    if (s.s.kind == 3)
        return s.s.lo;
    if (s.s.kind == 4)
        return s.s.hi;
    return 0x1f;
}

/*
 * function: BTL_SICKCONT_IsKind1Index15
 * address:  0x021E8A78
 * packet:   pkt_ov093_021E8A78
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

int BTL_SICKCONT_IsKind1Index15(union Slot s)
{
    if (s.s.kind == 1 && s.s.lo == 0xf)
        return 1;
    return 0;
}

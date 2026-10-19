/*
 * function: BTL_SICKCONT_GetLow
 * address:  0x021E8AFC
 * packet:   pkt_ov093_021E8AFC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;
union Slot {
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
    struct { u32 kind : 3; u32 pad : 6; u32 v : 16; u32 rest : 7; } w;
};
u8 BTL_SICKCONT_GetLow(union Slot s)
{
    if (s.s.kind == 2) return s.s.lo;
    if (s.s.kind == 4) return s.s.lo;
    return 0;
}
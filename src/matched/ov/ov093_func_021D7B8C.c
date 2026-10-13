/*
 * function: BTL_CALC_RandRange
 * address:  0x021D7B8C
 * packet:   pkt_ov093_021D7B8C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 BTL_CALC_Random(u32 range);

u32 BTL_CALC_RandRange(u32 lo, u32 hi)
{
    u32 t;
    if (lo > hi) {
        t = lo;
        lo = hi;
        hi = t;
    }
    return lo + BTL_CALC_Random(hi - lo + 1);
}

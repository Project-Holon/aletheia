/*
 * function: BTL_MAIN_PokeIdToClientId
 * address:  0x021B8D08
 * packet:   pkt_ov093_021B8D08
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021EFCF0  0x021EFCF0  data  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern const u8 data_021EFCF0[4];

u8 BTL_MAIN_PokeIdToClientId(u32 x)
{
    u8 i;
    for (i = 0; i < 4; i++) {
        u8 lo = data_021EFCF0[i];
        u8 hi = lo + 5;
        if (x >= lo && x <= hi) return i;
    }
    return 0;
}

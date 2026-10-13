/*
 * function: MAP_ATTR_GetBattleBackground
 * address:  0x021AB580
 * packet:   pkt_ov021_021AB580
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   data_021D8EA0  0x021D8EA0  data
 *   data_021D8EA1  0x021D8EA1  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern const u8 data_021D8EA0[];
extern const u8 data_021D8EA1[];

u8 MAP_ATTR_GetBattleBackground(u16 x)
{
    u32 i;

    for (i = 0; i < 0x25; i++) {
        if (x == data_021D8EA0[i * 2])
            return data_021D8EA1[i * 2];
    }
    return 0;
}

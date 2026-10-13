/*
 * function: ISS_CITY_SYS_GetPlayerZoneId
 * address:  0x0202ACBC
 * packet:   pkt_0202AC60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *
 */

typedef unsigned int u32;

struct Rec44;
extern unsigned short GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);

u32 ISS_CITY_SYS_GetPlayerZoneId(u32 *p)
{
    return GAME_DATA_GetPlayerZoneId((const struct Rec44 *)*p);
}

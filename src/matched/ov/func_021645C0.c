/*
 * function: EVENTDATA_SYSTEM_CheckNormalFieldZoneNotZone34
 * address:  0x021645C0
 * packet:   pkt_021645C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Size the third argument through the arm9 helper, bail when the arm9
 * status is set, otherwise copy it out.
 *
 * symbols:
 *   GAME_DATA_GetPlayerZoneId   0x02012AC8  thumb
 *   ZONEDATA_IsZone34   0x02013D20  thumb
 *   ZONEDATA_IsNormalFieldZone   0x02013E04  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Rec44;
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u32 ZONEDATA_IsZone34(u32 id);
extern u32 ZONEDATA_IsNormalFieldZone(u32 id);

int EVENTDATA_SYSTEM_CheckNormalFieldZoneNotZone34(void *a0, void *a1, void *a2)
{
    int r = GAME_DATA_GetPlayerZoneId(a2);

    if (ZONEDATA_IsZone34(r) != 0)
        return 0;

    return ZONEDATA_IsNormalFieldZone(r);
}


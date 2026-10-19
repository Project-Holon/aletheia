/*
 * function: FIELD_MENU_GetLayoutType
 * address:  0x021A8B18
 * packet:   pkt_ov021_021A8B18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   ZONEDATA_IsUnionRoom  0x02013CC8  thumb
 *   ZONEDATA_IsZone96Pair  0x02013CE0  thumb
 *   ZONEDATA_IsZone34  0x02013D20  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 ZONEDATA_IsUnionRoom(u32 id);
extern u32 ZONEDATA_IsZone96Pair(u16 v);
extern u32 ZONEDATA_IsZone34(u16 v);
struct BigObj;
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);

u32 FIELD_MENU_GetLayoutType(void *a, void *b, u32 c)
{
    u32 r = 0;

    if (ZONEDATA_IsUnionRoom((u16)c) || ZONEDATA_IsZone96Pair(c)) {
        r = 1;
    } else if (ZONEDATA_IsZone34(c)) {
        r = 4;
    } else if (GAME_DATA_GetIntrudeCount(a)) {
        r = 5;
    } else if (!ZONEDATA_CheckEventFlag(b, 0x961)) {
        r = 3;
    } else if (!ZONEDATA_CheckEventFlag(b, 0x962)) {
        r = 2;
    }
    return r;
}

/*
 * function: FIELD_SUBSCREEN_ResolveMode
 * address:  0x021A0EE4
 * packet:   pkt_ov021_021A0EE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02009210  0x02009210  thumb
 *   func_020090E0  0x020090E0  thumb
 *   ZONEDATA_IsZone34  0x02013D20  thumb
 *   ZONEDATA_IsZone4BPair  0x02013D00  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 func_02009210(void);
extern u32 func_020090E0(void);
extern u32 ZONEDATA_IsZone34(void);
extern u32 ZONEDATA_IsZone4BPair(u32);

u32 FIELD_SUBSCREEN_ResolveMode(u32 *p, u32 x)
{
    u32 a, b;
    if (x == 0) {
        a = (u32)GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)p[5]));
        b = FIELDMAP_GetZoneId((u8 *)p[5]);
        if (ZONEDATA_IsZone34() != 0 || ZONEDATA_IsZone4BPair(b) != 0)
            return 5;
        GAME_DATA_GetSaveControl((struct Big *)a);
        func_02009210();
        if (func_020090E0() == 0)
            return 5;
    }
    return x;
}

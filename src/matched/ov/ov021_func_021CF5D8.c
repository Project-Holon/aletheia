/*
 * function: func_021CF5D8
 * address:  0x021CF5D8
 * packet:   pkt_ov021_021CF5D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * ZONEDATA_GetParentZoneId returns u16 (its body ends in ldrh); declaring it u32, or
 * keeping its result in a u32 local, hoists the spilled local's reload
 * above the final *outType store (4 bytes).
 *
 * symbols:
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   ZONEDATA_GetParentZoneId  0x02013E40  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   MAP_ATTR_IsAnyGrass  0x021AB2BC  thumb  ov021
 *   MAP_ATTR_IsSplashWaterB  0x021AB364  thumb  ov021
 *   MAP_ATTR_IsSandVariant  0x021AB37C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern u16 FIELDMAP_GetZoneId(u8 *p);
extern u16 ZONEDATA_GetParentZoneId(u32 a);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u32 FIELD_PLAYER_GetNowAttribute(void **ctx);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern BOOL MAP_ATTR_IsAnyGrass(u16 id);
extern BOOL MAP_ATTR_IsSplashWaterB(u16 id);
extern int MAP_ATTR_IsSandVariant(u32 id);

void func_021CF5D8(int id, int kind, int flag, struct Obj00020 *pos, u32 *outType, u16 *outMsg)
{
    u32 attr;
    u16 m;
    u16 sp;
    u32 type;
    u16 msg;

    sp = ZONEDATA_GetParentZoneId(FIELDMAP_GetZoneId((u8 *)pos));
    switch (id) {
    case 0x23B:
        *outMsg = 0x469;
        *outType = 0x23;
        return;
    case 0x283:
        *outMsg = 0x474;
        *outType = 0x20;
        return;
    case 0x284:
        *outMsg = 0x475;
        *outType = 0x20;
        return;
    case 0x286:
        *outMsg = 0x476;
        *outType = 0x20;
        return;
    case 0x27D:
        *outMsg = 0x468;
        *outType = 0x1f;
        return;
    case 0x1EE:
        *outMsg = 0x478;
        *outType = 0x1f;
        return;
    case 0x27E:
    case 0x27F:
    case 0x280:
    case 0x287:
        *outMsg = 0x478;
        *outType = 0x22;
        return;
    case 0x281:
    case 0x282:
    case 0x285:
        *outMsg = 0x477;
        *outType = 0x21;
        return;
    }
    if (kind == 1) {
        *outMsg = 0x469;
        *outType = 0x1f;
        return;
    }
    if (kind == 4) {
        if (sp == 0xd6) {
            *outMsg = 0x469;
        } else {
            *outMsg = 0x468;
        }
        *outType = 2;
        return;
    }
    attr = FIELD_PLAYER_GetNowAttribute(FIELDMAP_GetFieldPlayer(pos));
    m = MAP_ATTR_GetTerrainId(attr);
    if (MAP_ATTR_GetFlags(attr) & 2) {
        msg = 0x468;
        type = 2;
    } else if (MAP_ATTR_IsAnyGrass(m)) {
        if (flag) {
            msg = 0x469;
            type = 1;
        } else {
            msg = 0x468;
            type = 0;
        }
    } else if (MAP_ATTR_IsSplashWaterB(m)) {
        msg = 0x468;
        type = 0;
    } else {
        if (MAP_ATTR_IsSandVariant(m)) {
            msg = 0x468;
            type = 4;
        } else {
            msg = 0x468;
            type = 3;
        }
    }
    *outType = type;
    if (sp == 0xd6) {
        *outMsg = 0x469;
    } else {
        *outMsg = msg;
    }
}

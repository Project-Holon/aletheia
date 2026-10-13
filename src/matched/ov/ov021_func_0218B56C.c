/*
 * function: FIELD_EVENT_CHECK_GetFrontTileMessage
 * address:  0x0218B56C
 * packet:   pkt_ov021_0218B56C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Picks the message for the tile the player faces: the first of the 13 table
 * entries at 0x021D3CE8 whose direction matches and whose attribute test
 * passes, else the water prompts 0x2712 (when a party member knows Surf) or
 * 0x2716; 0xFFFF for none.
 *
 * symbols:
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb
 *   FIELD_PLAYER_GetFrontAttribute  0x021A3128  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb
 *   func_02013E04  0x02013E04  thumb
 *   FIELD_PLAYER_CheckEncountAttr  0x021A3504  thumb
 *   FIELD_EVENT_CHECK_FindPartyMemberWithMove  0x0218B630  thumb
 *   FIELD_PLAYER_CheckSurfEntryAttr  0x021A3524  thumb
 *   data_021D3CE8  0x021D3CE8  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct FieldCtx {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    u16 f10;
    char pad12[0x06];
    void *f18;
    char pad1C[0x08];
    u16 f24;
};

struct TileMsg {
    int (*test)(u16 attr);
    u16 dir;
    u16 msg;
};

extern const struct TileMsg data_021D3CE8[13];

struct BigObj;
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
extern u32 FIELD_PLAYER_GetNowAttribute(void **ctx);
extern u32 FIELD_PLAYER_GetFrontAttribute(u32 *a, u32 b);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern u32 func_02013E04(u32 id);
extern int FIELD_PLAYER_CheckEncountAttr(u8 *a, int b, int c);
extern int FIELD_EVENT_CHECK_FindPartyMemberWithMove(void *sys, u32 move);
extern int FIELD_PLAYER_CheckSurfEntryAttr(u8 *a, int b, int c);

u16 FIELD_EVENT_CHECK_GetFrontTileMessage(struct FieldCtx *p, u8 *pos)
{
    u32 here;
    u32 ahead;
    u16 attr;
    u32 i;

    if (GAME_DATA_GetIntrudeCount(p->f8) == 1)
        return 0xFFFF;
    here = FIELD_PLAYER_GetNowAttribute(p->f18);
    ahead = FIELD_PLAYER_GetFrontAttribute(p->f18, p->f24);
    attr = MAP_ATTR_GetTerrainId(ahead);
    for (i = 0; i < 13; i++) {
        if ((p->f24 == data_021D3CE8[i].dir || data_021D3CE8[i].dir == 9) && data_021D3CE8[i].test(attr))
            return data_021D3CE8[i].msg;
    }
    if (!func_02013E04(p->f10) || GAME_DATA_GetIntrudeCount(p->f8) == 1)
        return 0xFFFF;
    if (FIELD_PLAYER_CheckEncountAttr((u8 *)p->f18, here, ahead) && FIELD_EVENT_CHECK_FindPartyMemberWithMove(p->f8, 0x39) != 6)
        return 0x2712;
    if (FIELD_PLAYER_CheckSurfEntryAttr((u8 *)p->f18, (u32)here, (u32)ahead))
        return 0x2716;
    return 0xFFFF;
}

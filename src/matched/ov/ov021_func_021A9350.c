/*
 * function: FIELD_ENCOUNT_SetupParam
 * address:  0x021A9350
 * packet:   pkt_ov021_021A9350
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   MOVE_POKEMON_SAVE_GetBlock  0x0200D418  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_GetNature  0x02018598  thumb
 *   FIELD_ENCOUNT_ApplyLeadAbility  0x021A9828  thumb  ov021
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   MOVE_POKEMON_SAVE_IsCooldownDone  0x0200D58C  thumb
 *   POKEPARTY_GetBattleReadyCount  0x0201AA50  thumb
 *   FIELD_ENCOUNT_RandPercent  0x021A9DC8  thumb  ov021
 *   POKEPARTY_FindFirstBattleReady  0x0201AB08  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sel {
    void *f00;
    void *f04;
    int f08;
    int f0C;
    u8 pad10[5];
    u8 f15;
    u16 f16;
    u16 f18;
    u8 f1A;
    u8 f1B;
    u8 f1C;
    u8 f1D;
    u8 f1E;
    u8 pad1F;
    u32 f20;
    void *f24;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 9;
    u32 b15 : 1;
};

typedef signed int     s32;
struct Big;
struct BigObj;
struct Blk38;
struct Sub0200852CObj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void MI_CpuFill8(void *p, int v, int n);
extern void *MOVE_POKEMON_SAVE_GetBlock(void *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern u8 POKE_TOOL_GetNature(void *p);
extern void FIELD_ENCOUNT_ApplyLeadAbility(struct Sel *s, u16 d);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern u32 MOVE_POKEMON_SAVE_IsCooldownDone(struct Blk38 *p);
extern u32 POKEPARTY_GetBattleReadyCount(void *p);
extern u32 FIELD_ENCOUNT_RandPercent(void);
extern u32 POKEPARTY_FindFirstBattleReady(void *p);

void FIELD_ENCOUNT_SetupParam(struct Sel *s, void *a, int b, int c, u16 d)
{
    void *t;
    void *party;
    void *mon;

    t = GAME_DATA_GetSaveControl(a);
    party = GAME_DATA_GetMyParty(a);
    MI_CpuFill8(s, 0, 0x2C);
    s->f08 = b;
    s->f0C = c;
    s->f00 = a;
    s->f04 = MOVE_POKEMON_SAVE_GetBlock(t);
    if (b == 5 || b == 6)
        s->b1 = 1;
    s->f24 = GAME_DATA_GetMyStatus(a);
    s->f20 = func_02008530(s->f24);
    mon = POKEPARTY_GetMember(party, 0);
    s->f1A = POKE_TOOL_GetPartyValue(mon, 0x4C, 0);
    if (s->f1A == 0) {
        s->f16 = POKE_TOOL_GetPartyValue(mon, 5, 0);
        s->f18 = POKE_TOOL_GetPartyValue(mon, 6, 0);
        s->f1B = POKE_TOOL_GetPartyValue(mon, 10, 0);
        s->f1C = POKE_TOOL_GetPartyValue(mon, 0x6E, 0);
        s->f1D = POKE_TOOL_GetNature(mon);
        FIELD_ENCOUNT_ApplyLeadAbility(s, d);
    }
    s->b0 = ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(a), 0x960);
    if (MOVE_POKEMON_SAVE_IsCooldownDone(MOVE_POKEMON_SAVE_GetBlock(t)) == 0)
        s->b2 = 1;
    if (s->f0C == 2) {
        s->b3 = 1;
        s->f0C = 0;
    }
    if (s->f0C == 1)
        s->b3 = 1;
    s->b4 = 0;
    s->b5 = 0;
    if (s->f08 == 1 && (int)POKEPARTY_GetBattleReadyCount(party) >= 2 && FIELD_ENCOUNT_RandPercent() < 0x28)
        s->b5 = 1;
    if (s->b15 || s->b2)
        s->f1E = POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(party, POKEPARTY_FindFirstBattleReady(party)), 0x9E, 0);
    s->f15 = s->b5 + 1;
}

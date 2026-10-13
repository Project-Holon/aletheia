/*
 * function: MUSICAL_EVENT_BuildParty
 * address:  0x0215518C
 * packet:   pkt_ov010_0215518C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Rebuilds the list at +0x38: either from the party list at +0 (skipping
 * entries whose field 0x4c is set) or from a fresh six-slot list, then
 * refreshes it. func_0200BAC8 is a tail-calling wrapper whose result is
 * used here, so this unit declares it returning a value.
 *
 * symbols:
 *   func_0200BAC8  0x0200BAC8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   POKEPARTY_Copy  0x0201AC2C  thumb
 *   func_020307B0  0x020307B0  arm
 *   POKE_TOOL_HealParty  0x0201BA34  thumb
 *   MUSICAL_EVENT_SetPartyLevel50  0x02155160  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx {
    void *f00;
    u8 pad04[0x34];
    void *f38;
    u8 pad3c[0x10];
    void *f4c;
};

extern void *func_0200BAC8(void *p);
struct BigObj;
struct Party;
struct PartyMon;
struct Rec534;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern void *func_0200BAF4(int a, int b);
extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);
extern u32 func_020307B0(void *p);
extern void POKE_TOOL_HealParty(void *p);
extern void MUSICAL_EVENT_SetPartyLevel50(void *list);

void MUSICAL_EVENT_BuildParty(int mode, struct Ctx *ctx)
{
    int t;
    void *e;
    int i;
    void *list;
    void *h;
    t = (int)func_0200BAC8(ctx->f4c);
    if (mode == 0) {
        list = GAME_DATA_GetMyParty(GAMESYSTEM_GetGameData(ctx->f00));
        for (i = 0; i < (int)POKEPARTY_GetCount(list); i++) {
            e = POKEPARTY_GetMember(list, i);
            if (POKE_TOOL_GetPartyValue(e, 0x4c, 0) == 0)
                POKEPARTY_Add(ctx->f38, e);
        }
    } else {
        h = func_0200BAF4(t, 4);
        POKEPARTY_Copy(h, ctx->f38);
        func_020307B0(h);
    }
    POKE_TOOL_HealParty(ctx->f38);
    MUSICAL_EVENT_SetPartyLevel50(ctx->f38);
}

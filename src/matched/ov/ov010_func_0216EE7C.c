/*
 * function: EVENT_BATTLE_NotifyBattleEnd
 * address:  0x0216EE7C
 * packet:   pkt_ov010_0216EE7C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * After a battle: unless the outcome is 0 or 2, reports the lead party
 * member's state (fainted, at half HP or less, a move out of PP, a status
 * condition) by name, then reports the species depending on the mode and
 * outcome.
 *
 * symbols:
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_FindFirstNonEgg  0x0201AB18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GAME_BEACON_SEARCH_SetEventBattleNameC  0x021654AC  thumb  ov010
 *   GAME_BEACON_SEARCH_SetEventBattleNameA  0x02165424  thumb  ov010
 *   GAME_BEACON_SEARCH_SetEventBattleNameB  0x02165468  thumb  ov010
 *   GAME_BEACON_SEARCH_SetEventBattleNameD  0x021654F0  thumb  ov010
 *   STRBUF_Delete  0x02045808  arm
 *   EVENT_BATTLE_NotifyLeadSpecies  0x0216EE40  thumb  ov010
 *   EVENT_BATTLE_DispatchBattleKindNotify  0x0216EE20  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct BattleEnd {
    u32 mode;           /* 0x00 */
    u8 pad04[0x48];
    u32 *result;        /* 0x4C */
    u8 pad50[0x3C];
    u32 outcome;        /* 0x8C */
} BattleEnd;

typedef struct BattleEndCtx {
    u32 f00;
    void *sys;          /* 0x04 */
    BattleEnd *st;      /* 0x08 */
} BattleEndCtx;

struct BigObj;
struct U16Vec;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_FindFirstNonEgg(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 arg);
extern void GAME_BEACON_SEARCH_SetEventBattleNameC(void *name);
extern void GAME_BEACON_SEARCH_SetEventBattleNameA(void *name);
extern void GAME_BEACON_SEARCH_SetEventBattleNameB(void *name);
extern void GAME_BEACON_SEARCH_SetEventBattleNameD(void *name);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void EVENT_BATTLE_NotifyLeadSpecies(void *p, int which);
extern void EVENT_BATTLE_DispatchBattleKindNotify(u16 id, int col);

void EVENT_BATTLE_NotifyBattleEnd(BattleEndCtx *c)
{
    BattleEnd *st;
    void *party;
    void *mon;
    void *name;
    u16 hp;
    u16 maxHp;
    int i;

    st = c->st;
    party = GAME_DATA_GetMyParty(c->sys);
    mon = func_0201AB28(party, POKEPARTY_FindFirstNonEgg(party));
    if (st->outcome != 0 && st->outcome != 2) {
        name = STRBUF_Create(12, 0x8004);
        POKE_TOOL_GetPartyValue(mon, 0x73, (u32)name);
        hp = POKE_TOOL_GetPartyValue(mon, 0xA0, 0);
        maxHp = POKE_TOOL_GetPartyValue(mon, 0xA1, 0);
        if (hp == 0)
            GAME_BEACON_SEARCH_SetEventBattleNameC(name);
        else if (hp * 2 <= maxHp)
            GAME_BEACON_SEARCH_SetEventBattleNameA(name);
        for (i = 0; i < 4; i++) {
            if (POKE_TOOL_GetPartyValue(mon, 0x36 + i, 0) != 0 && POKE_TOOL_GetPartyValue(mon, 0x3A + i, 0) == 0) {
                GAME_BEACON_SEARCH_SetEventBattleNameB(name);
                break;
            }
        }
        if (POKE_TOOL_GetPartyValue(mon, 0x9D, 0) != 0)
            GAME_BEACON_SEARCH_SetEventBattleNameD(name);
        STRBUF_Delete(name);
    }
    switch (st->mode) {
    case 0:
        if (st->outcome == 3)
            EVENT_BATTLE_NotifyLeadSpecies(st, 2);
        else if (st->outcome == 1)
            EVENT_BATTLE_NotifyLeadSpecies(st, 1);
        break;
    case 1:
        if (st->outcome == 1)
            EVENT_BATTLE_DispatchBattleKindNotify(*st->result, 1);
        break;
    }
}

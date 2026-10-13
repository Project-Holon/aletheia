/*
 * function: EVENT_BATTLE_NotifyLeadSpecies
 * address:  0x0216EE40
 * packet:   pkt_ov010_0216EE40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reports the species of the first party member to one of three
 * notifiers.
 *
 * MATCH, first draft (2026-09-28 tree_ov010_4): the one wildcard is arm9
 * 0x0201313C, an unlabelled Thumb leaf (`lsls r1, #2; adds r0, r1;
 * ldr r0, [r0, #0x24]; bx lr`) inside the listing's ARM data run.
 *
 * 2026-10-05: byte-identical; the wildcard is arm9 BTL_SETUP_GetParty (matched file exists, no shard yet); integrator shard resolves it.
 *
 * symbols:
 *   BTL_SETUP_GetParty  0x0201313C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GAME_BEACON_SEARCH_SetBattlePokeStart  0x0216505C  thumb  ov010
 *   GAME_BEACON_SEARCH_SetBattlePokeWin  0x02165078  thumb  ov010
 *   GAME_BEACON_SEARCH_SetPokeEvent  0x021653F4  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *BTL_SETUP_GetParty(void *p, int i);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern int GAME_BEACON_SEARCH_SetBattlePokeStart(int a0);
extern int GAME_BEACON_SEARCH_SetBattlePokeWin(int a0);
extern void GAME_BEACON_SEARCH_SetPokeEvent(u16 species);

void EVENT_BATTLE_NotifyLeadSpecies(void *p, int which)
{
    u16 species;

    species = POKE_TOOL_GetPartyValue(func_0201AB28(BTL_SETUP_GetParty(p, 1), 0), 5, 0);
    switch (which) {
    case 0:
        GAME_BEACON_SEARCH_SetBattlePokeStart(species);
        break;
    case 1:
        GAME_BEACON_SEARCH_SetBattlePokeWin(species);
        break;
    case 2:
        GAME_BEACON_SEARCH_SetPokeEvent(species);
        break;
    }
}

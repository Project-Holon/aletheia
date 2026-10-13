/*
 * function: GAME_BEACON_SEARCH_SetBattleSpecialPokeWin
 * address:  0x0216513C
 * packet:   pkt_0216513C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Test the id against the overlay's table and, when it takes,
 * re-submit the record at the shared globals pointer.
 *
 * symbols:
 *   GAME_BEACON_CheckActionPriority   0x02027060  thumb
 *   GAME_BEACON_RequestSend   0x02026FB8  thumb
 *   GAME_BEACON_Work      0x02146940  data
 *   GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeWin   0x02165164  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 GAME_BEACON_CheckActionPriority(u32 a);
extern void GAME_BEACON_RequestSend(void *);
extern char *GAME_BEACON_Work;
extern void GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeWin(void *a0, unsigned a1);

void GAME_BEACON_SEARCH_SetBattleSpecialPokeWin(void *a0)
{
    if (GAME_BEACON_CheckActionPriority(0x5)) {
        GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeWin(GAME_BEACON_Work + 4, (unsigned int)a0);
        GAME_BEACON_RequestSend(GAME_BEACON_Work + 4);
    }
}


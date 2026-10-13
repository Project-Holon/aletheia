/*
 * function: GAME_BEACON_SEARCH_SetEventBattleNameD
 * address:  0x021654F0
 * packet:   pkt_021654F0
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
 *   GAME_BEACON_SEARCH_SetInfoEventBattleNameD   0x02165518  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 GAME_BEACON_CheckActionPriority(u32 a);
extern void GAME_BEACON_RequestSend(void *);
extern char *GAME_BEACON_Work;
extern int GAME_BEACON_SEARCH_SetInfoEventBattleNameD(int a0, int a1);

void GAME_BEACON_SEARCH_SetEventBattleNameD(void *a0)
{
    if (GAME_BEACON_CheckActionPriority(0x22)) {
        GAME_BEACON_SEARCH_SetInfoEventBattleNameD((int)(GAME_BEACON_Work + 4), (int)a0);
        GAME_BEACON_RequestSend(GAME_BEACON_Work + 4);
    }
}


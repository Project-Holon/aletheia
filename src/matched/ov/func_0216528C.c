/*
 * function: GAME_BEACON_SEARCH_SetBattleBigFourWin
 * address:  0x0216528C
 * packet:   pkt_0216528C
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
 *   GAME_BEACON_SEARCH_SetInfoBattleBigFourWin   0x021652B4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 GAME_BEACON_CheckActionPriority(u32 a);
extern void GAME_BEACON_RequestSend(void *);
extern char *GAME_BEACON_Work;
extern void GAME_BEACON_SEARCH_SetInfoBattleBigFourWin(void *a0, unsigned a1);

void GAME_BEACON_SEARCH_SetBattleBigFourWin(void *a0)
{
    if (GAME_BEACON_CheckActionPriority(0xB)) {
        GAME_BEACON_SEARCH_SetInfoBattleBigFourWin(GAME_BEACON_Work + 4, (unsigned int)a0);
        GAME_BEACON_RequestSend(GAME_BEACON_Work + 4);
    }
}


/*
 * function: GAME_BEACON_SEARCH_SetNamedEvent
 * address:  0x0216576C
 * packet:   pkt_ov010_0216576C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Test id 0x2F against the overlay's table and, when it takes, file the
 * record at the shared globals pointer (sibling of GAME_BEACON_SEARCH_SetWordValue).
 *
 * symbols:
 *   GAME_BEACON_CheckActionPriority   0x02027060  thumb
 *   GAME_BEACON_RequestSend   0x02026FB8  thumb
 *   GAME_BEACON_Work      0x02146940  data
 *   GAME_BEACON_SEARCH_SetInfoNamedEvent   0x02165794  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 GAME_BEACON_CheckActionPriority(u32 a);
extern void GAME_BEACON_RequestSend(void *);
extern char *GAME_BEACON_Work;
extern int GAME_BEACON_SEARCH_SetInfoNamedEvent(int a0, int a1);

void GAME_BEACON_SEARCH_SetNamedEvent(void *a0)
{
    if (GAME_BEACON_CheckActionPriority(0x2F)) {
        GAME_BEACON_SEARCH_SetInfoNamedEvent((int)(GAME_BEACON_Work + 4), (int)a0);
        GAME_BEACON_RequestSend(GAME_BEACON_Work + 4);
    }
}

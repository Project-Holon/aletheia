/*
 * function: GAME_BEACON_SEARCH_SetSymbolMapEnter
 * address:  0x0216556C
 * packet:   pkt_0216556C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Gate on an id test, then submit the record at the shared globals
 * pointer.
 *
 * symbols:
 *   GAME_BEACON_CheckActionPriority   0x02027060  thumb
 *   GAME_BEACON_RequestSend   0x02026FB8  thumb
 *   GAME_BEACON_Work      0x02146940  data
 *   GAME_BEACON_SEARCH_SetInfoSymbolMapEnter   0x02165590  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 GAME_BEACON_CheckActionPriority(u32 a);
extern void GAME_BEACON_RequestSend(void *);
extern char *GAME_BEACON_Work;
extern void GAME_BEACON_SEARCH_SetInfoSymbolMapEnter(void *);

void GAME_BEACON_SEARCH_SetSymbolMapEnter(void)
{
    if (GAME_BEACON_CheckActionPriority(0x25)) {
        GAME_BEACON_SEARCH_SetInfoSymbolMapEnter(GAME_BEACON_Work + 4);
        GAME_BEACON_RequestSend(GAME_BEACON_Work + 4);
    }
}


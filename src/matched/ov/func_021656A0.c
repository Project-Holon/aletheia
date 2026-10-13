/*
 * function: GAME_BEACON_SEARCH_SetSimpleEventA
 * address:  0x021656A0
 * packet:   pkt_021656A0
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
 *   GAME_BEACON_SEARCH_SetInfoSimpleEventA   0x021656C4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 GAME_BEACON_CheckActionPriority(u32 a);
extern void GAME_BEACON_RequestSend(void *);
extern char *GAME_BEACON_Work;
extern void GAME_BEACON_SEARCH_SetInfoSimpleEventA(void *);

void GAME_BEACON_SEARCH_SetSimpleEventA(void)
{
    if (GAME_BEACON_CheckActionPriority(0x2B)) {
        GAME_BEACON_SEARCH_SetInfoSimpleEventA(GAME_BEACON_Work + 4);
        GAME_BEACON_RequestSend(GAME_BEACON_Work + 4);
    }
}


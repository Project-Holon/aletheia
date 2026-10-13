/*
 * function: func_021655D4
 * address:  0x021655D4
 * packet:   pkt_021655D4
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
 *   func_021655F8   0x021655F8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 GAME_BEACON_CheckActionPriority(u32 a);
extern void GAME_BEACON_RequestSend(void *);
extern char *GAME_BEACON_Work;
extern void func_021655F8(void *);

void func_021655D4(void)
{
    if (GAME_BEACON_CheckActionPriority(0x27)) {
        func_021655F8(GAME_BEACON_Work + 4);
        GAME_BEACON_RequestSend(GAME_BEACON_Work + 4);
    }
}


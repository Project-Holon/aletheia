/*
 * function: func_02165534
 * address:  0x02165534
 * packet:   pkt_02165534
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
 *   func_0216555C   0x0216555C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 GAME_BEACON_CheckActionPriority(u32 a);
extern void GAME_BEACON_RequestSend(void *);
extern char *GAME_BEACON_Work;
extern void func_0216555C(void *a0, unsigned a1);

void func_02165534(void *a0)
{
    if (GAME_BEACON_CheckActionPriority(0x24)) {
        func_0216555C(GAME_BEACON_Work + 4, (unsigned int)a0);
        GAME_BEACON_RequestSend(GAME_BEACON_Work + 4);
    }
}


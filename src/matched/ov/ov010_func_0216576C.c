/*
 * function: func_0216576C
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
 * record at the shared globals pointer (sibling of func_02165634).
 *
 * symbols:
 *   GAME_BEACON_CheckActionPriority   0x02027060  thumb
 *   GAME_BEACON_RequestSend   0x02026FB8  thumb
 *   GAME_BEACON_Work      0x02146940  data
 *   func_02165794   0x02165794  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 GAME_BEACON_CheckActionPriority(u32 a);
extern void GAME_BEACON_RequestSend(void *);
extern char *GAME_BEACON_Work;
extern int func_02165794(int a0, int a1);

void func_0216576C(void *a0)
{
    if (GAME_BEACON_CheckActionPriority(0x2F)) {
        func_02165794((int)(GAME_BEACON_Work + 4), (int)a0);
        GAME_BEACON_RequestSend(GAME_BEACON_Work + 4);
    }
}

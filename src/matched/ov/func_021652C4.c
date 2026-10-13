/*
 * function: func_021652C4
 * address:  0x021652C4
 * packet:   pkt_021652C4
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
 *   func_021652EC   0x021652EC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 GAME_BEACON_CheckActionPriority(u32 a);
extern void GAME_BEACON_RequestSend(void *);
extern char *GAME_BEACON_Work;
struct Obj;
extern void func_021652EC(struct Obj *p, u32 v);

void func_021652C4(void *a0)
{
    if (GAME_BEACON_CheckActionPriority(0x12)) {
        func_021652EC((struct Obj *)(GAME_BEACON_Work + 4), (u32)a0);
        GAME_BEACON_RequestSend(GAME_BEACON_Work + 4);
    }
}


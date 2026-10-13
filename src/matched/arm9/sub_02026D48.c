/*
 * function: GAME_BEACON_GetReceivedFramesByTrainerId
 * address:  0x02026D48
 * packet:   pkt_02026CE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Answers the +0x5c halfword of the first live ring slot whose +0x10 id
 * equals v, or 0xffff.
 * Unlabelled leaf (no lr save): the integrator should seed 0x02026D48 into
 * layout/function_starts.txt.
 *
 * symbols:
 *   GAME_BEACON_Work  0x02146940  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* slot[i]: +0x00 live byte, +0x10 id halfword, +0x5c halfword answer */
struct Rec { u8 b00; u8 pad01[0x10 - 1]; u16 f10; u8 pad12[0x5c - 0x12]; u16 f5c; u8 pad5e[2]; };
struct Blk { u32 f00; u8 own[0x60]; struct Rec slot[30]; u32 mask; };
extern struct Blk *GAME_BEACON_Work;

u16 GAME_BEACON_GetReceivedFramesByTrainerId(u16 v)
{
    struct Blk *g = GAME_BEACON_Work;
    int i;
    for (i = 0; i < 30; i++) {
        if (g->slot[i].b00 != 0 && g->slot[i].f10 == v)
            return g->slot[i].f5c;
    }
    return 0xffff;
}

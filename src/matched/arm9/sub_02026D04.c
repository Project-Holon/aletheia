/*
 * function: sub_02026D04
 * address:  0x02026D04
 * packet:   pkt_02026CE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Finds the ring slot whose +0x10 id equals the record's, sets its live-mask
 * bit and answers 1; 0 when none does.
 * Unlabelled leaf (no lr save): the integrator should seed 0x02026D04 into
 * layout/function_starts.txt.
 *
 * symbols:
 *   g_GameBeacon  0x02146940  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* slot[i]: +0x00 live byte, +0x10 id halfword, +0x5c halfword answer */
struct Rec { u8 b00; u8 pad01[0x10 - 1]; u16 f10; u8 pad12[0x5c - 0x12]; u16 f5c; u8 pad5e[2]; };
struct Blk { u32 f00; u8 own[0x60]; struct Rec slot[30]; u32 mask; };
extern struct Blk *g_GameBeacon;

int sub_02026D04(const struct Rec *r)
{
    struct Blk *g = g_GameBeacon;
    int i;
    for (i = 0; i < 30; i++) {
        if (r->f10 == g->slot[i].f10) {
            g->mask |= 1 << i;
            return 1;
        }
    }
    return 0;
}

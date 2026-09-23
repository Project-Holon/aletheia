/*
 * function: func_02026CE0
 * address:  0x02026CE0
 * packet:   pkt_02026CE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clears bit `n` of the ring live mask at +0xba4 of the game beacon block.
 * The earlier MATCH park read the pool word as 0x02021440; the word at
 * 0x02026CFC is 0x02146940, g_GameBeacon, attested by 77 other pools.
 * EXACT* because the follower at 0x02026D04 is an unlabelled leaf.
 *
 * symbols:
 *   g_GameBeacon  0x02146940  data
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Ctx {
    u8  pad_0000[0xba4];
    u32 flags;
};

extern struct Ctx *g_GameBeacon;

void func_02026CE0(u32 n)
{
    g_GameBeacon->flags = ((1 << n) ^ 0xffffffff) & g_GameBeacon->flags;
}

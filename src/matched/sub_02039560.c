/*
 * function: sub_02039560
 * address:  0x02039560
 * packet:   pkt_020393A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   unk_021469D0   0x021469D0  data
 *
 * Clear the +0x1e9 flag sub_02039548 sets.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02039560.c \n *       --func sub_02039560 --addr 0x02039560 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct LinkState {
    u8 pad000[0x1e7];
    u8 unk_1e7;
    u8 pad1e8;
    u8 unk_1e9;
    u8 unk_1ea;
};

extern struct LinkState *unk_021469D0;

void sub_02039560(void)
{
    unk_021469D0->unk_1e9 = 0;
}

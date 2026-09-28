/*
 * function: sub_02039548
 * address:  0x02039548
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
 * Set the +0x1e9 flag on the link state.  sub_02039560 is the clearing half;
 * the two are byte-for-byte the same but for the stored constant.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02039548.c \n *       --func sub_02039548 --addr 0x02039548 --cc 1.1p1 --arm
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

void sub_02039548(void)
{
    unk_021469D0->unk_1e9 = 1;
}

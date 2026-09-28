/*
 * function: func_021D5BC0
 * address:  0x021D5BC0
 * packet:   pkt_021D5BC0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   func_021D5BC0   0x021D5BC0  arm
 *   func_020862F0   0x020862F0  arm
 *   func_0207EE68   0x0207EE68  arm
 *   func_0207EEFC   0x0207EEFC  arm
 *
 * PARKED: every instruction and all four relocations reproduce; the only
 * residue is register naming -- the image keeps the address of the 0x021DE680
 * global in r5 and the block-size constant in r6, the compiler swaps the pair
 * (r6/r5).  Omitting the `v` local and inlining the constants does not move it.
 * This is the O39 note 2 register-naming class.
 *
 * A one-shot flag at the byte handed in decides which of two VRAM blocks the
 * record published through 0x021DE680 clears: the +0x638 bank with 0x6000
 * when the byte is the +0x67c one, the +0x668 bank with 0x3000 otherwise.
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern void func_020862F0(int, int);
extern void func_0207EE68(int, int, int);
extern void func_0207EEFC(int, int, int);

void func_021D5BC0(int unused, u8 *p)
{
    int *g = (int *)0x021DE680;
    u8 *b;
    int v;

    if (*p == 0)
        return;

    b = *(u8 **)g;

    if (p == b + 0x67c) {
        v = 0x6000;
        func_020862F0(*(int *)(b + 0x638), v);
        func_0207EE68(*(int *)(*(u8 **)g + 0x638), 0, v);
    } else {
        v = 0x3000;
        func_020862F0(*(int *)(b + 0x668), v);
        func_0207EEFC(*(int *)(*(u8 **)g + 0x668), v, v);
    }

    *p = 0;
}

/*
 * function: func_02067B78
 * address:  0x02067B78
 * packet:   pkt_02067AAC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The NNS G2D cell-to-OAM flip setter: bit 0 of the composer state's +0x24
 * word is flip-H and bit 1 is flip-V, both set or cleared from a BOOL.  Its
 * four neighbours in the same `.word` run are src/matched/unit_02067B40.c.
 *
 * The second `ldr r1, [r0, #0x24]` is the plain re-read of the field the
 * first half just stored.  The NITRO 2.0 compiler keeps it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02067B78.c \
 *       --func func_02067B78 --addr 0x02067B78 --cc ../2.0/sp2 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct G2dOamState {
    u8  pad_00[0x24];
    u32 flip;   /* 0x24: bit0 flip-H, bit1 flip-V */
};

void func_02067B78(struct G2dOamState *p, u32 h, u32 v)
{
    if (h) p->flip |= 1;
    else   p->flip &= ~1u;

    if (v) p->flip |= 2;
    else   p->flip &= ~2u;
}

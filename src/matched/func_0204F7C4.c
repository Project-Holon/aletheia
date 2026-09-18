/*
 * function: func_0204F7C4
 * address:  0x0204F7C4
 * packet:   pkt_0204F684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Halfword store at +0x16 of one 0x1c-byte entry of the descriptor's +8
 * array.  Note +0x16 rather than +0x12/+0x14 - it is the third of the three
 * halfword fields that func_0204F684 and func_0204F6B4's family work on, and
 * it is the follower that makes func_0204F794 EXACT*.
 *
 * Unlabelled in the generated listing: the prologue saves nothing.  Seeding
 * 0x0204F7C4 in layout/function_starts.txt turns that EXACT* into EXACT; that
 * file is the integrator's, not this packet's.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent {
    u8  pad_00[0x16];
    u16 f16;
    u8  pad_18[4];
};

void func_0204F7C4(u8 *a0, int i, u16 *src)
{
    struct Ent *e = &((struct Ent *)*(u32 *)(a0 + 8))[i];

    e->f16 = *src;
}

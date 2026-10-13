/*
 * function: GFL_NET_RING_BUFF_Init
 * address:  0x0203640C
 * packet:   pkt_0203640C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Initialises a small record: the two leading words get the first two
 * arguments, and the two halfwords at +0x0C and +0x0E are cleared.  The
 * second argument is declared `s16` and that is visible in the code: the
 * compiler sign-extends it with an `lsl #16` / `asr #16` pair before the
 * two-word `stmia`, which is the only way a narrowed parameter reaches a
 * 32-bit store.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_RING_BUFF_Init.c \
 *       --func GFL_NET_RING_BUFF_Init --addr 0x0203640C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u32 unk0;
    u32 unk4;
    u8  pad8[4];
    u16 unkC;
    u16 unkE;
};

void GFL_NET_RING_BUFF_Init(struct Rec *p, u32 a, int b)
{
    p->unk0 = a;
    p->unk4 = (short)b;
    p->unkC = 0;
    p->unkE = 0;
}

/*
 * function: func_02067B78
 * address:  0x02067B78
 * packet:   pkt_02067AAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The NNS G2D cell-to-OAM flip setter: bit 0 of the composer state's +0x24
 * word is flip-H and bit 1 is flip-V, both set or cleared from a BOOL.  Its
 * four neighbours in the same `.word` run are src/matched/unit_02067B40.c.
 *
 * docs/notes/g2d_flip_setter.c.txt wrote this off as a four-byte near miss:
 * the second `ldr r1, [r0, #0x24]` is a re-read of the word the preceding
 * store just wrote, which the compiler proves redundant and degrades to
 * `mov r1, r1`, and making the field or the parameter `volatile` restores
 * the load but splits the predicated `orrne`/`biceq` pair into a full
 * predicated load-modify-store per arm (60 bytes instead of 44).  The
 * spelling that does reproduce it is a volatile read of that one word and
 * nothing else: the first half stays a plain read-modify-write on the
 * field, so its predication survives, and only the re-read is forced.  See
 * docs/idioms/a-re-read-of-a-field-just-stored-is-one-volatile-read-not-a-volatile-field.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02067B78.c \
 *       --func func_02067B78 --addr 0x02067B78 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct G2dOamState {
    u8  pad_00[0x24];
    u32 flip;   /* 0x24: bit0 flip-H, bit1 flip-V */
};

void func_02067B78(struct G2dOamState *p, u32 h, u32 v)
{
    u32 w;

    if (h) p->flip |= 1;
    else   p->flip &= ~1u;

    w = *(volatile u32 *)&p->flip;

    if (v) w |= 2;
    else   w &= ~2u;

    p->flip = w;
}

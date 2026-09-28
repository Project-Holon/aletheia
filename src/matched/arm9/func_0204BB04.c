/*
 * function: func_0204BB04
 * address:  0x0204BB04
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74   0x02146A74  data
 *
 * The reader for the word func_0204BAEC writes, returning 0 before the system
 * is constructed.  Both arms are predicated off the null test (`ldrne` and
 * `moveq` into the same register), which is why this has to be written as one
 * `if`/`else` over two returns rather than an early return followed by the
 * load.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BB04.c \
 *       --func func_0204BB04 --addr 0x0204BB04 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sys {
    u8  pad_000[0xf8];
    u32 unk_0f8;   /* 0xf8 */
};

extern struct Sys *g_02146A74;

u32 func_0204BB04(void)
{
    if (g_02146A74 != 0) {
        return g_02146A74->unk_0f8;
    } else {
        return 0;
    }
}

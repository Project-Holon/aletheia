/*
 * function: func_02046C24
 * address:  0x02046C24
 * packet:   pkt_02046C24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   g_02146A5C      0x02146A5C  data
 *   func_02046C88   0x02046C88  arm
 *   func_0206A884   0x0206A884  arm
 *   func_0206A8FC   0x0206A8FC  arm
 *
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * Install one of three handlers into the context's +0x88 word.  Modes 1 and
 * 2 have their own constant; mode 0 and everything else share the third
 * block, which is why the comparison chain starts at zero and the shared
 * body sits immediately after the last compare.
 *
 * The three values are code addresses: 0x0206A884 and 0x0206A8FC are
 * ordinary functions and 0x02046C88 is the eight-byte ARM tail stub
 * `ldr ip, [pc, #0]; bx ip; .word 0x0206A854` (attested as `veneer`), so the
 * mode-0 handler goes through one extra hop.
 *
 * Two of the four sites stay wildcarded: 0x0206A884 and 0x0206A8FC each have
 * exactly one witness image wide and it is the pool word inside this range.
 * Blocking evidence class: label/matched, no outside witness.  Either address
 * being matched elsewhere (`matched` class) closes it.
 *
 * The `*` is the unlabelled follower at 0x02046C88 - the tail stub itself is
 * inside this listing's extent because nothing in it saves lr.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Ctx {
    u8  pad_00[0x88];
    void *unk_88;
};

extern struct Ctx *g_02146A5C;
extern void func_02046C88(void);
extern void func_0206A884(void);
extern void func_0206A8FC(void);

void func_02046C24(u32 mode)
{
    switch (mode) {
    case 0:
    default:
        g_02146A5C->unk_88 = func_02046C88;
        break;
    case 1:
        g_02146A5C->unk_88 = func_0206A884;
        break;
    case 2:
        g_02146A5C->unk_88 = func_0206A8FC;
        break;
    }
}

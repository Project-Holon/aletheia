/*
 * A whole translation unit range, matched as one byte range.
 *
 * unit:     yes
 * function: sub_02049B40, sub_02049B68
 * address:  0x02049B40
 * packet:   pkt_0204961C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02049B90   0x02049B90  arm
 *   sub_02049BDC   0x02049BDC  arm
 *
 * Two sibling entry points of the text-printing layer, each a six-to-seven
 * argument forwarder that splices a zero in as the fourth argument of the
 * real worker (sub_02049B90 and sub_02049BDC respectively).
 *
 * The shape is the whole content: `stmdb sp!, {lr}` plus `sub sp, #0xc`
 * builds the outgoing stack argument area, the two incoming stack
 * arguments are lifted out at [sp,#0x10] and [sp,#0x14], and `stm sp,
 * {r3, lr}` writes the displaced r3 and the first lifted argument into
 * the callee's slots in one go.  Only then is r3 reloaded with the
 * spliced 0.  The last argument is read with `ldrh`, which is the only
 * evidence that it is a u16 rather than a word.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02049B40.c \
 *       --addr 0x02049B40 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void sub_02049B90(u32 a, u32 b, u32 c, u32 zero, u32 d, u32 e, u16 f);
extern void sub_02049BDC(u32 a, u32 b, u32 c, u32 zero, u32 d, u32 e, u16 f);

void sub_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f)
{
    sub_02049B90(a, b, c, 0, d, e, f);
}

void sub_02049B68(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f)
{
    sub_02049BDC(a, b, c, 0, d, e, f);
}

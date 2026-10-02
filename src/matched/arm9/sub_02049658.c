/*
 * function: sub_02049658
 * address:  0x02049658
 * packet:   pkt_0204961C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_0204A380   0x0204A380  arm
 *   sub_0204968C   0x0204968C  arm
 *
 * Seven-argument entry point of the text-printing layer: resolve a handle
 * through sub_0204A380 from the first two arguments and the last two, then
 * hand that handle plus the middle arguments to sub_0204968C.
 *
 * The sixth argument is read from the caller's stack slot twice, once as
 * sub_0204A380's third argument and once as sub_0204968C's fifth: the
 * compiler will not keep it in a callee-saved register across the first
 * call, because re-reading the incoming slot is free
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 * The seventh is read with `ldrh`, which is what names it u16.  The third
 * and fourth arguments are parked in r5/r4 because they are live across
 * the first call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02049658.c \
 *       --func sub_02049658 --addr 0x02049658 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  sub_0204A380(void *a, u32 b, u32 f, u16 g);
extern void sub_0204968C(u32 handle, u32 c, u32 d, u32 e, u32 f);

void sub_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g)
{
    sub_0204968C(sub_0204A380(a, b, f, g), c, d, e, f);
}

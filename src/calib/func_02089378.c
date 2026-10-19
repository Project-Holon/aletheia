/*
 * function: SND_StartPreparedSeq
 * address:  0x02089378
 * packet:   pkt_02089378
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A 32-byte forwarding leaf: hands the caller's single argument to
 * func_02089804 as the SECOND of five parameters, with a request code of 3
 * in the first and zeros in the remaining three.  The fifth argument is the
 * `str r2, [sp]` outgoing slot, which is what makes the frame `push {r3, lr}`
 * rather than a bare `push {lr}`.
 *
 * The three zeros are ONE value materialised once (`mov r2, #0`) and copied
 * (`mov r3, r2`, `str r2, [sp]`), not three separate immediates, so they are
 * written as a single named local reused at all three sites.
 *
 * This is the callee that unblocks src/pending/func_020731E0.c: the `bl` at
 * 0x0207331C inside that file is the only branch to this address anywhere in
 * the image, so `label` cannot attest it from there and only a `matched`
 * entry here can.
 *
 * symbols:
 *   func_02089804  0x02089804  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SND_StartPreparedSeq.c \
 *       --func SND_StartPreparedSeq --addr 0x02089378 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern int func_02089804(int code, u32 a, u32 b, u32 c, u32 d);

int SND_StartPreparedSeq(u32 a)
{
    u32 z = 0;

    return func_02089804(3, a, z, z, z);
}

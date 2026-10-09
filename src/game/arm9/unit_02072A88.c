/*
 * file:     unit_02072A88.c
 * function: func_02072A88
 * address:  0x02072A88
 * packet:   pkt_02072A44
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02072974  0x02072974  arm
 *
 * One-line tail-call wrapper: func_02072974(1 << *p).
 *
 * Built by the 1.2 front end.  The image issues the callee's pool load into
 * ip BEFORE the `lsl` that computes the last argument:
 *   02072A84  ldr r0, [r0] / mov r1, #1 / ldr ip, [pc, #4] / lsl r0, r1, r0 / bx ip
 * dsi/1.1p1 cannot emit that order -- it always puts the pool load last, and
 * every source shape in docs/idioms/a-tail-calls-pool-word-is-scheduled-before-the-last-argument-write.md
 * lands there (documented as an unspellable gap).  ../1.2/sp2 reproduces the
 * image instruction for instruction; the only other difference is the frame,
 * where 1.1p1 pads with a dead `push {r3}` and the image is 1.2's 1.2-shaped
 * `stmdb`/`sub sp, sp, #4` form.  Same measured tell as
 * src/matched/func_020525A0.c and src/matched/func_020528A8.c.
 *
 * Evidence recorded in docs/notes/pkt_02072A44.c.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02072A88.c \
 *       --func func_02072A88 --addr 0x02072A88 --arm --cc ../1.2/sp2
 */

typedef unsigned int u32;

extern void func_02072974(u32 chan);

void func_02072A88(u32 *p)
{
    func_02072974(1 << *p);
}

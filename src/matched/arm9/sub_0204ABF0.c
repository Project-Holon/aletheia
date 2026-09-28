/*
 * function: sub_0204ABF0
 * address:  0x0204ABF0
 * packet:   pkt_0204A03C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_0204AC18  0x0204AC18  arm
 *
 * The short-form entry point of sub_0204AC18: same call with the two
 * optional halfword parameters defaulted to zero.
 *
 * All the frame does is rebuild the stack half of the argument list.  The
 * four register arguments pass through untouched, so nothing in the body
 * mentions them; `sub sp, sp, #0xc` is the callee's three stack words, the
 * two zeros go in the first two, and the caller's own single stack argument
 * is copied from +0x10 (four bytes of saved lr plus the twelve just
 * reserved) into the third.  It is read with `ldrh`, which is what fixes
 * that parameter as a halfword rather than a word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204ABF0.c \
 *       --func sub_0204ABF0 --addr 0x0204ABF0 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void sub_0204AC18(u32 a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

void sub_0204ABF0(u32 a, u32 b, u32 c, u32 d, u16 g)
{
    sub_0204AC18(a, b, c, d, 0, 0, g);
}

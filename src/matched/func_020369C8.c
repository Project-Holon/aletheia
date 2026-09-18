/*
 * function: func_020369C8
 * address:  0x020369C8
 * packet:   pkt_020367C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * First non-null of three words of a queue owner: the word at +0x10, then the
 * word at +0, then the word at +8.  The first two arms load into r1 and only
 * move the answer into r0 on the taken path (`movne r0, r1`); the third arm
 * loads straight into r0, so its null case is the single `moveq r0, #0` that
 * the source's trailing `return 0;` produces.  Both taken arms branch on the
 * compare itself (`bxne lr`) instead of jumping to the shared epilogue.
 *
 * Written with three separate `if (...) return ...;` statements rather than a
 * chain of `?:`: the compiler rejects the GNU `?:` extension outright
 * (CCERR), and the merged `if` chain (`if (a) return a; if (b) return b;
 * return c;`) is 36 bytes and folds the third test away.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020369C8.c \
 *       --func func_020369C8 --addr 0x020369C8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

u32 func_020369C8(u32 *p)
{
    if (p[4] != 0)
        return p[4];
    if (p[0] != 0)
        return p[0];
    if (p[2] != 0)
        return p[2];
    return 0;
}

/*
 * unit:     no
 * function: func_0203F004
 * address:  0x0203F004
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * Byte-counting strlen over an unsigned char string.  The loop is written
 * as an unconditional one with the test and the return inside it, which is
 * why the original has a plain `b` back to the head and a dead `bx lr`
 * after it for the path that falls off the end.
 *
 * EXACT*, not EXACT: the inferred extent runs to 0x0203F034 because the
 * follower at 0x0203F028 has no label.  It is a twelve-byte ARM long-branch
 * veneer (ldr ip, [pc]; bx ip; .word 0x0208CD94), not a byte difference,
 * and wants seeding into layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F004.c \
 *       --func func_0203F004 --addr 0x0203F004 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

u32 func_0203F004(const u8 *s)
{
    u32 n = 0;

    while (1) {
        if (*s == 0) {
            return n;
        }
        s++;
        n++;
    }
}

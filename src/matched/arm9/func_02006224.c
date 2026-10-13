/*
 * function: func_02006224
 * address:  0x02006224
 * packet:   pkt_02006224
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02072EC8 (arm) reached only by the `blx` inside this function
 *
 * symbols:
 *   NNS_SndPlayerGetActiveSeqCount  0x02072EC8  arm
 *
 * `a0` is incremented in place before the call, so the source added one to
 * the parameter rather than passing a computed local; the boolean comes back
 * as two `return` constants rather than a shared tail.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006224.c \
 *       --func func_02006224 --addr 0x02006224 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern u16 NNS_SndPlayerGetActiveSeqCount(u32 idx);

int func_02006224(u32 a0)
{
    return NNS_SndPlayerGetActiveSeqCount(a0 + 1) != 0;
}

/*
 * function: func_02072974
 * address:  0x02072974
 * packet:   pkt_0207292C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  +0010 PC24 func_020895F8           -> unresolved: 020895F8 (arm, from header) has no witness outside 02072974..020729A4
 *
 * symbols:
 *   func_020895F8    0x020895F8  arm
 *   g_0214DEC0       0x0214DEC0  data
 *
 * Releases one channel of the allocator: unlocks it and clears the channel bit
 * from the word at g_0214DEC0 + 8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02072974.c \
 *       --func func_02072974 --addr 0x02072974 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void func_020895F8(u32 chan, u32 a);
extern u32  g_0214DEC0[];

void func_02072974(u32 chan)
{
    if (chan == 0) {
        return;
    }
    func_020895F8(chan, 0);
    g_0214DEC0[2] &= ~chan;
}

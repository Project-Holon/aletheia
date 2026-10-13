/*
 * function: func_02076070
 * address:  0x02076070
 * packet:   pkt_02075FCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02150200    0x02150200  data
 *
 * Unlabelled leaf: disasm.py only labels a prologue that saves lr, and this
 * one saves nothing, so it never appears in the worklist.  It sits inside
 * pkt_02075FCC's range (0x02075FCC..0x0207608C) after the 0x02075FCC extent
 * and its pool.  It is the sole caller-side witness for CARD_TryWaitBackupAsync's
 * one-word veneer, so filing it and then re-running that wrapper is the
 * bottom-up promotion for this pair.
 */

typedef unsigned int u32;

extern u32 g_02150200;

int func_02076070(void)
{
    return (*(u32 *)((char *)&g_02150200 + 4) & 4) ? 0 : 1;
}

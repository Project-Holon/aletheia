/*
 * function: func_021E1434
 * address:  0x021E1434
 * packet:   pkt_021E1434
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   g_021E5334  0x021E5334  data
 *
 * BLOCKED: `bl 0x02059F38` at +0004 has no witness -- 0x02059F38 is a .word
 * in asm/arm9/main.s (the pool word of the function that starts at
 * func_02059F54, 28 bytes later), never a traced start.  Every other byte,
 * the sole-ref 0x021E5334 pool word included, is identical: 4 once
 * 0x02059F38 says the block is live, else the queued count at +8.
 */

typedef unsigned long u32;

extern int func_02059F38(void);
extern u32 g_021E5334[];

int func_021E1434(void)
{
    if (func_02059F38())
        return 4;
    return g_021E5334[2];
}


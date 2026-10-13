/*
 * function: CPS_SocRegister
 * address:  0x0215AA5C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores a word at +0xa4 of the block held in the second word of the module state block.
 *
 * symbols:
 *   g_02150FEC  0x02150FEC  data
 */

extern char g_02150FEC[];

void CPS_SocRegister(int v)
{
    int blk = *(int *)(g_02150FEC + 4);

    *(int *)(blk + 0xa4) = v;
}


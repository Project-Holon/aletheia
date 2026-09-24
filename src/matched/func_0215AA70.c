/*
 * function: func_0215AA70
 * address:  0x0215AA70
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the word at +0xa4 of the block the state object holds.
 *
 * symbols:
 *   g_02150FEC  0x02150FEC  data
 */

extern char g_02150FEC[];

void func_0215AA70(void)
{
    int *p = *(int **)(g_02150FEC + 4);

    *(int *)((char *)p + 0xa4) = 0;
}


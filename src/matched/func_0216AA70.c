/*
 * function: func_0216AA70
 * address:  0x0216AA70
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * True when the block held in the global at 0x021AA874 has 5 in its +4
 * word.
 *
 * symbols:
 *   g_021AA874  0x021AA874  data

 */

extern char g_021AA874[];

int func_0216AA70(void)
{
    char *p = *(char **)g_021AA874;

    if (p != 0 && *(int *)(p + 4) == 5) return 1;
    return 0;
}



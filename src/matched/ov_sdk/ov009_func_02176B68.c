/*
 * function: func_02176B68
 * address:  0x02176B68
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the first two words of the state object.
 *
 * symbols:
 *   g_021AB178  0x021AB178  data
 */

extern char g_021AB178[];

void func_02176B68(void)
{
    *(int *)(g_021AB178) = 0;
    *(int *)(g_021AB178 + 4) = 0;
}


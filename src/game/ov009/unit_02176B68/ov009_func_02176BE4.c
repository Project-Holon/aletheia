/*
 * function: func_02176BE4
 * address:  0x02176BE4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Set while the word at +4 of the state object is under 0x6000.
 *
 * symbols:
 *   g_021AB178  0x021AB178  data
 */

extern char g_021AB178[];

int func_02176BE4(void)
{
    return *(int *)(g_021AB178 + 4) < 0x6000;
}


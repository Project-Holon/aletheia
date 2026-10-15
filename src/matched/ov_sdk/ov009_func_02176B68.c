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
 *   gDwcReliableQueue  0x021AB178  data
 */

extern char gDwcReliableQueue[];

void func_02176B68(void)
{
    *(int *)(gDwcReliableQueue) = 0;
    *(int *)(gDwcReliableQueue + 4) = 0;
}


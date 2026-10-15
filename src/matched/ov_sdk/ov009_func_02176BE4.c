/*
 * function: DWCi_IsReliableQueueFree
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
 *   gDwcReliableQueue  0x021AB178  data
 */

extern char gDwcReliableQueue[];

int DWCi_IsReliableQueueFree(void)
{
    return *(int *)(gDwcReliableQueue + 4) < 0x6000;
}


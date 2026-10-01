/*
 * function: func_021F9814
 * address:  0x021F9814
 * packet:   pkt_ov094_021F9814
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears flag bit 7 of the owner's work.
 *
 * symbols:
 *   func_02011324 0x02011324 thumb
 */
extern unsigned *func_02011324(void *);

void func_021F9814(void *a)
{
    *func_02011324(a) &= ~0x80;
}

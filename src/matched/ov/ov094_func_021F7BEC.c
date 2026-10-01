/*
 * function: func_021F7BEC
 * address:  0x021F7BEC
 * packet:   pkt_ov094_021F7BEC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_021F97E4 on the handle at 0x188 of the global work block, then sets the word at 0x1e8 to 0.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_021F97E4 0x021F97E4 thumb ov094
 */
extern char *d_0220AF20;
extern void func_021F97E4(void *);

void func_021F7BEC(void)
{
    func_021F97E4(*(void **)(d_0220AF20 + 0x188));
    *(int *)(d_0220AF20 + 0x1e8) = 0;
}

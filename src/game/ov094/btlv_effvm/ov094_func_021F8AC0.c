/*
 * function: func_021F8AC0
 * address:  0x021F8AC0
 * packet:   pkt_ov094_021F8AC0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_021F7BEC, then stores the argument at 0x238 and clears 0x23c and 0x240 of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_021F7BEC 0x021F7BEC thumb ov094
 */
extern char *d_0220AF20;
extern void func_021F7BEC(void);

void func_021F8AC0(int a)
{
    func_021F7BEC();
    *(int *)(d_0220AF20 + 0x238) = a;
    *(int *)(d_0220AF20 + 0x23c) = 0;
    *(int *)(d_0220AF20 + 0x240) = 0;
}

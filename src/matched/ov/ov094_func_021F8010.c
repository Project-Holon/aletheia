/*
 * function: func_021F8010
 * address:  0x021F8010
 * packet:   pkt_ov094_021F8010
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_021FF0F8 for slot a, then marks slot a-8 of the table at 0x1f8 free.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_021FF0F8 0x021FF0F8 thumb ov094
 */
extern char *d_0220AF20;
extern void func_021FF0F8(void *, int);

void func_021F8010(int a)
{
    func_021FF0F8(*(void **)(d_0220AF20 + 0x190), a);
    ((int *)(d_0220AF20 + 0x1f8))[a - 8] = -1;
}

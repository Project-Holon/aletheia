/*
 * function: func_021F8B90
 * address:  0x021F8B90
 * packet:   pkt_ov094_021F8B90
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_0204A648, then PALANM_TransferPalettes on the handle at 0x18c of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_0204A648 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 */
extern char *d_0220AF20;
extern void func_0204A648(void);
struct S02021D50;
extern void PALANM_TransferPalettes(struct S02021D50 *p);

void func_021F8B90(void)
{
    func_0204A648();
    PALANM_TransferPalettes(*(void **)(d_0220AF20 + 0x18c));
}

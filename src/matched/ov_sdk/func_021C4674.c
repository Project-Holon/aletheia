/*
 * function: func_021C4674
 * address:  0x021C4674
 * packet:   pkt_021C4674
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C4674   0x021C4674  arm
 *   DWCi_BTNlSet  0x021BCB28  arm
 *   DWCi_IPTlCheckTrigger  0x021D6824  arm
 *
 * Two-stage guard around DWCi_BTNlSet.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C4674.c \
 *       --func func_021C4674 --addr 0x021C4674 --region ov016 --cc dsi/1.1p1 --arm
 */

extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern int func_021C44EC(void);
extern void DWCi_BTNlSet(signed char v);

void func_021C4674(void)
{
    if (DWCi_IPTlCheckTrigger(2))
    {
        DWCi_BTNlSet(0);
        return;
    }
    if (func_021C44EC())
        DWCi_BTNlSet(0);
}

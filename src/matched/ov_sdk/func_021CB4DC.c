/*
 * function: func_021CB4DC
 * address:  0x021CB4DC
 * packet:   pkt_021CB4DC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CB4DC   0x021CB4DC  arm
 *   DWCi_BTNlSet  0x021BCB28  arm
 *   DWCi_IPTlCheckTrigger  0x021D6824  arm
 *
 * Two-stage guard around DWCi_BTNlSet.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CB4DC.c \
 *       --func func_021CB4DC --addr 0x021CB4DC --region ov016 --cc dsi/1.1p1 --arm
 */

extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern int func_021CB2C8(void);
extern void DWCi_BTNlSet(signed char v);

void func_021CB4DC(void)
{
    if (DWCi_IPTlCheckTrigger(2))
    {
        DWCi_BTNlSet(0);
        return;
    }
    if (func_021CB2C8())
        DWCi_BTNlSet(0);
}

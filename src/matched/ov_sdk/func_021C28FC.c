/*
 * function: func_021C28FC
 * address:  0x021C28FC
 * packet:   pkt_021C28FC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C28FC   0x021C28FC  arm
 *   DWCi_BTNlSet  0x021BCB28  arm
 *   DWCi_IPTlCheckTrigger  0x021D6824  arm
 *
 * Guard: if (DWCi_IPTlCheckTrigger(2)) call DWCi_IPTlCheckTrigger.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C28FC.c \
 *       --func func_021C28FC --addr 0x021C28FC --region ov016 --cc dsi/1.1p1 --arm
 */

extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern void DWCi_BTNlSet(signed char v);

void func_021C28FC(void)
{
    if (DWCi_IPTlCheckTrigger(2))
        DWCi_BTNlSet(0);
}

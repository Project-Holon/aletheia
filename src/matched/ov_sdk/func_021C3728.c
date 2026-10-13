/*
 * function: func_021C3728
 * address:  0x021C3728
 * packet:   pkt_021C3728
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C3728   0x021C3728  arm
 *   DWCi_BTNlSet  0x021BCB28  arm
 *   DWCi_IPTlCheckTrigger  0x021D6824  arm
 *
 * Guard: if (DWCi_IPTlCheckTrigger(1)) call DWCi_IPTlCheckTrigger.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C3728.c \
 *       --func func_021C3728 --addr 0x021C3728 --region ov016 --cc dsi/1.1p1 --arm
 */

extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern void DWCi_BTNlSet(signed char v);

void func_021C3728(void)
{
    if (DWCi_IPTlCheckTrigger(1))
        DWCi_BTNlSet(0);
}

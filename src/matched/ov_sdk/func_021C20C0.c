/*
 * function: func_021C20C0
 * address:  0x021C20C0
 * packet:   pkt_021C20C0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C20C0   0x021C20C0  arm
 *   DWCi_BTNlSet  0x021BCB28  arm
 *   DWCi_IPTlCheckTrigger  0x021D6824  arm
 *
 * Two guarded DWCi_BTNlSet calls keyed off DWCi_IPTlCheckTrigger.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C20C0.c \
 *       --func func_021C20C0 --addr 0x021C20C0 --region ov016 --cc dsi/1.1p1 --arm
 */

extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern void DWCi_BTNlSet(signed char v);

void func_021C20C0(void)
{
    if (DWCi_IPTlCheckTrigger(1))
        DWCi_BTNlSet(1);
    if (DWCi_IPTlCheckTrigger(2))
        DWCi_BTNlSet(0);
}

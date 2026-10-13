/*
 * function: func_021CADCC
 * address:  0x021CADCC
 * packet:   pkt_021CADCC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CADCC   0x021CADCC  arm
 *   DWCi_BTNlSet  0x021BCB28  arm
 *   DWCi_IPTlCheckTrigger  0x021D6824  arm
 *
 * Two-stage guard around DWCi_BTNlSet.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CADCC.c \
 *       --func func_021CADCC --addr 0x021CADCC --region ov016 --cc dsi/1.1p1 --arm
 */

extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern int func_021CAC44(void);
extern void DWCi_BTNlSet(signed char v);

void func_021CADCC(void)
{
    if (DWCi_IPTlCheckTrigger(2))
    {
        DWCi_BTNlSet(0);
        return;
    }
    if (func_021CAC44())
        DWCi_BTNlSet(0);
}

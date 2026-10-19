/*
 * function: input
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
 *   input   0x021CADCC  arm
 *   DWCi_BTNlSet  0x021BCB28  arm
 *   DWCi_IPTlCheckTrigger  0x021D6824  arm
 *   DWCi_SceneSetRakuButton_DetectFold  0x021CAC44  arm
 *
 * Two-stage guard around DWCi_BTNlSet.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/input.c \
 *       --func input --addr 0x021CADCC --region ov016 --cc dsi/1.1p1 --arm
 */

extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern int DWCi_SceneSetRakuButton_DetectFold(void);
extern void DWCi_BTNlSet(signed char v);

void input(void)
{
    if (DWCi_IPTlCheckTrigger(2))
    {
        DWCi_BTNlSet(0);
        return;
    }
    if (DWCi_SceneSetRakuButton_DetectFold())
        DWCi_BTNlSet(0);
}

/*
 * function: WORLDTRADE_ENTER_StateStartServerCheck
 * address:  0x021F8A74
 * packet:   pkt_021F8A74
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   DWC_NASLoginAsync  0x02168064  arm

 *
 * Call DWC_NASLoginAsync and report success.
 */

extern void DWC_NASLoginAsync(void);

int WORLDTRADE_ENTER_StateStartServerCheck(void *a0)
{
    DWC_NASLoginAsync();
    return 1;
}

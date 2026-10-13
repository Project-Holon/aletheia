/*
 * function: ITEMMENU_ReturnToBagMainAlias
 * address:  0x021B8F90
 * packet:   pkt_ov070_021B8F90
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub (00 4b 18 47 + pool word) after ITEMMENU_IsCheckModeAllowed;
 * installed as a callback by ITEMMENU_TaskBagMain and at 0x021B85E0.
 *
 * symbols:
 *   ITEMMENU_ReturnToBagMain  0x021B8AF4  thumb  ov070
 */

extern void ITEMMENU_ReturnToBagMain(void *o);

void ITEMMENU_ReturnToBagMainAlias(void *o)
{
    ITEMMENU_ReturnToBagMain(o);
}

/*
 * function: ITEMMENU_ShowMessageDefault
 * address:  0x021BADAC
 * packet:   pkt_ov070_021BADAC
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to ITEMMENU_ShowMessage(p, 0).
 *
 * symbols:
 *   ITEMMENU_ShowMessage  0x021BACF0  thumb  ov070
 */

void ITEMMENU_ShowMessageDefault(void *p)
{
    void ITEMMENU_ShowMessage(int p, int mode);
    ITEMMENU_ShowMessage((int)p, 0);
}

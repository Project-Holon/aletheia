/*
 * function: ITEMMENU_RefreshInputGuard
 * address:  0x021B80BC
 * packet:   pkt_ov070_021B80BC
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to ITEMMENU_UpdateInputGuardAnim.
 *
 * symbols:
 *   ITEMMENU_UpdateInputGuardAnim  0x021BB5A4  thumb  ov070
 */

void ITEMMENU_RefreshInputGuard(void *p)
{
    void ITEMMENU_UpdateInputGuardAnim(char *p);
    ITEMMENU_UpdateInputGuardAnim(p);
}

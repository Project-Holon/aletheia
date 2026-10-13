/*
 * function: EVENT_SHORTCUT_MENU_SuspendLinkHook
 * address:  0x021606D0
 * packet:   pkt_ov010_021606D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled thunk: tail-calls EVENT_SHORTCUT_MENU_CloseLink with its second argument.
 *
 * symbols:
 *   EVENT_SHORTCUT_MENU_CloseLink  0x0216060C  thumb  ov010
 */

extern int EVENT_SHORTCUT_MENU_CloseLink(int a0, int a1);

void EVENT_SHORTCUT_MENU_SuspendLinkHook(int a, int b)
{
    EVENT_SHORTCUT_MENU_CloseLink(b, b);
}

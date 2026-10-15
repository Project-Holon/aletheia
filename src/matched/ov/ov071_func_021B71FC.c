/*
 * function: MONOLITH_TOOL_CloseTaskMenu
 * address:  0x021B71FC
 * packet:   pkt_ov071_021B71FC
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to APP_TASKMENU_CloseMenu.
 *
 * symbols:
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 */

struct TaskMenu;
void MONOLITH_TOOL_CloseTaskMenu(void *p)
{
    void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
    APP_TASKMENU_CloseMenu(p);
}

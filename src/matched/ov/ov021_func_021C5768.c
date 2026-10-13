/*
 * function: SHORTCUT_MENU_GetSelection
 * address:  0x021C5768
 * packet:   pkt_ov021_021C5768
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save): returns the selection SHORTCUT_MENU_UpdateInput
 * stores at +0x18. Called from SHORTCUT_MENU_Main.
 */
#include "../include/Obj20207.h"

int SHORTCUT_MENU_GetSelection(char *p)
{
    return ((struct Obj20207 *)p)->f18;
}

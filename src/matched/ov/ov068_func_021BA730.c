/*
 * function: OPTION_MENU_HasButtonFocusChanged
 * address:  0x021BA730
 * packet:   pkt_ov068_021BA730
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf before OPTION_MENU_InitList; OPTION_MENU_StateMain tests its result.
 */
#include "../include/Obj20643.h"

typedef unsigned char u8;

int OPTION_MENU_HasButtonFocusChanged(u8 *p)
{
    return ((struct Obj20643 *)p)->f40;
}

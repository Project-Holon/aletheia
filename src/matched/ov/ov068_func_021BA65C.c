/*
 * function: OPTION_MENU_GetButtonChoice
 * address:  0x021BA65C
 * packet:   pkt_ov068_021BA65C
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf before OPTION_MENU_IsButtonFinished; OPTION_MENU_StateMain calls it with NULL
 * and with a stack int.
 */
#include "../include/Obj13139.h"

typedef unsigned char u8;

int OPTION_MENU_GetButtonChoice(u8 *p, int *out)
{
    if (out != 0)
        *out = ((struct Obj13139 *)p)->fC;
    return ((struct Obj13139 *)p)->f10;
}

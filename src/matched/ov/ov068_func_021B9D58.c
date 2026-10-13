/*
 * function: OPTION_MENU_RestartGfxBlink
 * address:  0x021B9D58
 * packet:   pkt_ov068_021B9D58
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf; the function thunk OPTION_MENU_RestartScreenBlink tail-calls.
 * movs r1,#0 / adds r0,#0x4c / strh r1,[r0] / bx lr.
 */
#include "../include/Obj20637.h"

void OPTION_MENU_RestartGfxBlink(char *p)
{
    ((struct Obj20637 *)p)->f4C = 0;
}

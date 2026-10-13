/*
 * function: OPTION_MENU_GetGfxWindow
 * address:  0x021B9BFC
 * packet:   pkt_ov068_021B9BFC
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf; the function thunk OPTION_MENU_GetScreenWindow tail-calls.
 * lsls r1,#2 / ldr r0,[r0,r1] / bx lr.
 */

int OPTION_MENU_GetGfxWindow(int *p, int i)
{
    return p[i];
}

/*
 * function: OPTION_MENU_GetSpriteUnit
 * address:  0x021BA020
 * packet:   pkt_ov068_021BA020
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf; the function thunk OPTION_MENU_GetScreenActorUnit tail-calls.
 * ldr r0,[r0] / bx lr.
 */

int OPTION_MENU_GetSpriteUnit(int *p)
{
    return *p;
}

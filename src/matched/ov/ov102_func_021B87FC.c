/*
 * function: IRC_COMPATIBLE_MENU_StartScrollEffect
 * address:  0x021B87FC
 * packet:   pkt_ov102_021B87FC
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Sets the +0x18 word to 1 then initialises the object through the four-argument
 * helper at 0x021B8A40 (0, 0x58, 0x78).  Blocker target of FIELD_RAIL_POINT_GetLineKey.
 *
 * symbols:
 *   IRC_COMPATIBLE_MENU_InitLinearStep  0x021B8A40  thumb  ov102
 * Addresses are Black-image addresses.
 */

extern void IRC_COMPATIBLE_MENU_InitLinearStep(int *p, int a, int b, int n);

void IRC_COMPATIBLE_MENU_StartScrollEffect(int *p)
{
    p[6] = 1;
    IRC_COMPATIBLE_MENU_InitLinearStep(p, 0, 0x58, 0x78);
}

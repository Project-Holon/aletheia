/*
 * function: TOWNMAP_CursorGetHeldKeys
 * address:  0x021BA3EC
 * packet:   pkt_021BA3EC
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetCont  0x0203630C  arm
 */

unsigned int KEY_GetCont(void);

void TOWNMAP_CursorGetHeldKeys(void)
{
    KEY_GetCont();
}

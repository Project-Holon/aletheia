/*
 * function: TOUCHBAR_SetButtonKeyMask
 * address: 0x021B6578
 * packet: pkt_ov067_021B6578
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_FindButton 0x021B65C8 thumb ov067
 *   TOUCHBAR_SetButtonKeys 0x021B69D4 thumb ov067
 */
extern void *TOUCHBAR_FindButton(unsigned char *p, unsigned int v);
extern void TOUCHBAR_SetButtonKeys(void *p, int v);

void TOUCHBAR_SetButtonKeyMask(unsigned char *p, unsigned int id, int v)
{
    TOUCHBAR_SetButtonKeys(TOUCHBAR_FindButton(p, id), v);
}

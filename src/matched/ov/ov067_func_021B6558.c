/*
 * function: TOUCHBAR_SetButtonVisible
 * address: 0x021B6558
 * packet: pkt_ov067_021B6558
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_FindButton 0x021B65C8 thumb ov067
 *   TOUCHBAR_SetButtonActorVisible 0x021B69BC thumb ov067
 */
extern void *TOUCHBAR_FindButton(unsigned char *p, unsigned int v);
extern void TOUCHBAR_SetButtonActorVisible(void *p, unsigned int v);

void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v)
{
    TOUCHBAR_SetButtonActorVisible(TOUCHBAR_FindButton(p, id), v);
}

/*
 * function: TOUCHBAR_SetButtonBgPriority
 * address: 0x021B6588
 * packet: pkt_ov067_021B6588
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_FindButton 0x021B65C8 thumb ov067
 *   TOUCHBAR_SetButtonActorBgPriority 0x021B6A1C thumb ov067
 */
extern void *TOUCHBAR_FindButton(unsigned char *p, unsigned int v);
extern void TOUCHBAR_SetButtonActorBgPriority(void *p, unsigned int v);

void TOUCHBAR_SetButtonBgPriority(unsigned char *p, unsigned int id, unsigned int v)
{
    TOUCHBAR_SetButtonActorBgPriority(TOUCHBAR_FindButton(p, id), v);
}

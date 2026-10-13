/*
 * function: TOUCHBAR_SetButtonEnabled
 * address: 0x021B6548
 * packet: pkt_ov067_021B6548
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_FindButton 0x021B65C8 thumb ov067
 *   TOUCHBAR_CallSetEnabled 0x021B69C8 thumb ov067
 */
extern void *TOUCHBAR_FindButton(unsigned char *p, unsigned int v);
extern int TOUCHBAR_CallSetEnabled(void *p, int v);

int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v)
{
    return TOUCHBAR_CallSetEnabled(TOUCHBAR_FindButton(p, id), v);
}

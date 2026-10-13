/*
 * function: TOUCHBAR_SetButtonToggled
 * address: 0x021B6598
 * packet: pkt_ov067_021B6598
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_FindButton 0x021B65C8 thumb ov067
 *   TOUCHBAR_SetButtonToggle 0x021B69D8 thumb ov067
 */
extern void *TOUCHBAR_FindButton(unsigned char *p, unsigned int v);
typedef unsigned int   u32;
struct S;
extern void TOUCHBAR_SetButtonToggle(struct S *p, u32 v);

void TOUCHBAR_SetButtonToggled(unsigned char *p, unsigned int id, unsigned int v)
{
    TOUCHBAR_SetButtonToggle(TOUCHBAR_FindButton(p, id), v);
}

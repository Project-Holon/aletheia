/*
 * function: C_GEAR_ResetTabPalettes
 * address: 0x021F0370
 * packet: pkt_ov029_021F0370
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   C_GEAR_BlendTabPalette 0x021F08BC thumb ov029
 */
struct W;
extern void C_GEAR_BlendTabPalette(struct W *p, int i, int j, int k);
void C_GEAR_ResetTabPalettes(void *p)
{
    int i;
    for (i = 0; i < 3; i++) C_GEAR_BlendTabPalette(p, i, 0, 31);
}

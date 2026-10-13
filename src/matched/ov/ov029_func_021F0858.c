/*
 * function: C_GEAR_UpdateTabPaletteKind0
 * address: 0x021F0858
 * packet: pkt_ov029_021F0858
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   C_GEAR_GetTabTimerCount 0x021F0D08 thumb ov029
 *   C_GEAR_BlendTabPalette 0x021F08BC thumb ov029
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021F3255 0x021F3255 data ov029 a1
 */
struct W;
extern unsigned short C_GEAR_GetTabTimerCount(unsigned short *p, int i);
extern void C_GEAR_BlendTabPalette(struct W *p, int i, int j, int k);
extern unsigned char d_021F3255[];
void C_GEAR_UpdateTabPaletteKind0(void *p, int i, unsigned short *q)
{
    unsigned int v = C_GEAR_GetTabTimerCount(q, i);
    if (v > 20) return;
    v = (unsigned)(((int)v % 10) * 28) / 10;
    v = d_021F3255[v];
    C_GEAR_BlendTabPalette(p, i, v, 31);
}

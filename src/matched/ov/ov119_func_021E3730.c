/*
 * function: POKETRADE_3D_SetCubeNormal
 * address:  0x021E3730
 * packet:   pkt_ov119_021E3730
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021E8178 0x021E8178 data a4
 */

typedef unsigned int u32;

extern u32 d_021E8178[];

void POKETRADE_3D_SetCubeNormal(int n)
{
    *(u32 *)0x04000484 = d_021E8178[n];
}

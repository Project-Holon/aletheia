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
 *   gCubeNormal 0x021E8178 data a4
 */

typedef unsigned int u32;

extern u32 gCubeNormal[];

void POKETRADE_3D_SetCubeNormal(int n)
{
    *(u32 *)0x04000484 = gCubeNormal[n];
}

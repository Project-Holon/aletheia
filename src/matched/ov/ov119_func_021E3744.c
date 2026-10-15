/*
 * function: POKETRADE_3D_SetCubeTexCoord
 * address:  0x021E3744
 * packet:   pkt_ov119_021E3744
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gCubeTexCoord 0x021E8168 data a4
 */

typedef unsigned int u32;

extern u32 gCubeTexCoord[];

void POKETRADE_3D_SetCubeTexCoord(int n)
{
    *(u32 *)0x04000488 = gCubeTexCoord[n];
}

/*
 * function: FIELDMAP_SetupG3d
 * address:  0x02188E50
 * packet:   pkt_ov021_02188E50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3X_SetFog  0x0207DC44  arm
 *   G3X_SetFogTable  0x0207DD10  arm
 *   G3X_SetClearColor  0x0207DD24  arm
 *   func_0207DCF8  0x0207DCF8  arm
 *   G3D_SYSTEM_SetSwapBuffersMode  0x02046BE0  arm
 *   sFogTable  0x021D3640  data  a4
 *   sEdgeColorTable  0x021D35E4  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u8 sFogTable[];
extern u8 sEdgeColorTable[];
extern void G3X_SetFog(int enable, int fogMode, int fogSlope, int fogOffset);
extern void G3X_SetFogTable(void *a);
extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void func_0207DCF8(void *a);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);

void FIELDMAP_SetupG3d(void)
{
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xFFFFCFFD;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 0x10;
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFFB;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & 0xFFFFCFFF) | 8;
    G3X_SetFog(0, 0, 5, 0xE00);
    *(volatile u32 *)0x04000358 = 0x7FFF;
    G3X_SetFogTable(sFogTable);
    G3X_SetClearColor(0, 0x1F, 0x7FFF, 0, 0);
    func_0207DCF8(sEdgeColorTable);
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
    *(volatile u32 *)0x04000580 = 0xBFFF0000;
    G3D_SYSTEM_SetSwapBuffersMode(1, 0);
}

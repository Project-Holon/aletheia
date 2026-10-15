/*
 * function: THE_END_GRAPHIC_Setup3d
 * address: 0x021B9840
 * packet: pkt_ov182_021B9840
 * region: ov182
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware 04000008/04000060 read/write 021B984E-021B988C, 04000580 write 021B98AA.
 * symbols:
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021B9C28 0x021B9C28 data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void G3X_SetFog(int, int, int, int);
extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
extern const u32 d_021B9C28[][2];
void THE_END_GRAPHIC_Setup3d(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1, 1);
    *(volatile u16 *)0x04000008 = *(volatile u16 *)0x04000008 & ~3;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3002) | 2;
    *(volatile u16 *)0x04000060 &= (u16)~0x3010;
    *(volatile u16 *)0x04000060 &= (u16)~0x3004;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 8;
    *(volatile u16 *)0x04000060 &= (u16)~0x3020;
    G3X_SetFog(0, 0, 0, 0);
    G3X_SetClearColor(0, 0, 0x7fff, 0x3f, 0);
    *(volatile u32 *)0x04000580 = 0xbfff0000;
    for (i = 0; i < 4; i++)
        G3D_SYSTEM_SetLight((u8)i, (const u16 *)d_021B9C28[i]);
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
}

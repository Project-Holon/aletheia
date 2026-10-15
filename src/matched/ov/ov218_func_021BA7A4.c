/*
 * function: UN_SELECT_SetupDisplay
 * address: 0x021BA7A4
 * packet: pkt_ov218_021BA7A4
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: BG0CNT04000008 masked A7B2-A7BA; DISP3DCNT04000060 re-read for each distinct mask A7BE-A7F0; VIEWPORT04000580 written A80E.
 * prototype: 46A94 index narrowed to u8 per A812/A816; its own wide prototype cannot observe caller truncation.
 * single-lever: explicit BG0CNT assignment preserves bics rather than narrowing a compound mask; alpha enable clears only overflow bits before setting bit 3.
 * symbols:
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021BAED8 0x021BAED8 data a2
 */
typedef enum { FogMode0 = 0 } FogMode;
typedef enum { FogSlope0 = 0 } FogSlope;
extern const unsigned short d_021BAED8[];
extern void BG_SYS_SetMainPlaneVisible(unsigned, unsigned);
extern void G3X_SetFog(int, FogMode, FogSlope, int);
extern void G3X_SetClearColor(unsigned short, int, int, int, int);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned, unsigned);
void UN_SELECT_SetupDisplay(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1, 1);
    *(volatile unsigned short *)0x04000008 = *(volatile unsigned short *)0x04000008 & ~3;
    *(volatile unsigned short *)0x04000060 = (*(volatile unsigned short *)0x04000060 & ~(2 | 0x3000)) | 2;
    *(volatile unsigned short *)0x04000060 &= ~(0x10 | 0x3000);
    *(volatile unsigned short *)0x04000060 &= ~(4 | 0x3000);
    *(volatile unsigned short *)0x04000060 = (*(volatile unsigned short *)0x04000060 & ~0x3000) | 8;
    *(volatile unsigned short *)0x04000060 &= ~(0x20 | 0x3000);
    G3X_SetFog(0, 0, 0, 0);
    G3X_SetClearColor(0, 0, 0x7fff, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for (i = 0; i < 4; i++)
        G3D_SYSTEM_SetLight((unsigned char)i, &d_021BAED8[i * 4]);
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
}

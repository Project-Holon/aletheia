/*
 * function: GURU2_MAIN_Setup3dState
 * address: 0x021DFA68
 * packet: pkt_ov137_021DFA68
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: DISP3DCNT 0x04000060 re-read at 021DFA70,76,82,8A,96; GXSTAT written 021DFABA.
 * symbols:
 *   func_0207DCF8 0x0207DCF8 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   gGuru2ToonTable 0x021E1D90 data a2
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { GX_SHADING_TOON = 0, GX_SHADING_HIGHLIGHT = 1 } GXShading;
extern void func_0207DCF8(const u16 *);
extern void G3X_SetClearColor(u16, int, int, int, int);
extern const u16 gGuru2ToonTable[];
#define DISP3D (*(volatile u16 *)0x04000060)
static inline void G3X_SetShading(GXShading shading)
{
    DISP3D = (u16)((DISP3D & ~(2 | 0x1000 | 0x2000)) | (shading << 1));
}
static inline void G3X_AntiAlias(int enable)
{
    if (enable) DISP3D = (u16)((DISP3D & ~0x3000) | 16);
    else DISP3D &= (u16)~0x3010;
}
static inline void G3X_AlphaTest(int enable, int ref)
{
    if (enable) {
        DISP3D = (u16)((DISP3D & ~0x3000) | 4);
        *(volatile u16 *)0x04000340 = (u16)ref;
    } else DISP3D &= (u16)~0x3004;
}
static inline void G3X_AlphaBlend(int enable)
{
    if (enable) DISP3D = (u16)((DISP3D & ~0x3000) | 8);
    else DISP3D &= (u16)~0x3008;
}
static inline void G3X_EdgeMarking(int enable)
{
    if (enable) DISP3D = (u16)((DISP3D & ~0x3000) | 32);
    else DISP3D &= (u16)~0x3020;
}
void GURU2_MAIN_Setup3dState(void)
{
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(1);
    G3X_AlphaTest(0, 0);
    G3X_AlphaBlend(1);
    G3X_EdgeMarking(1);
    func_0207DCF8(gGuru2ToonTable);
    G3X_SetClearColor(0x7fff, 0, 0x7fff, 63, 0);
    *(volatile u32 *)0x04000580 = 0xbfff0000;
}

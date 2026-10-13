/*
 * function: func_021BDB70
 * address: 0x021BDB70
 * packet: pkt_ov204_021BDB70
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021BDB80 BG0CNT; 021BDB8E..021BDBC2 DISP3DCNT repeated hardware updates; 021BDBE0 viewport.
 * symbols:
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021BFDAC 0x021BFDAC data a2
 */
#define REG3D (*(volatile unsigned short *)0x04000060)
typedef enum { SHADING1 = 1 } GXShading;
typedef int BOOL;
extern void BG_SYS_SetMainPlaneVisible(unsigned, unsigned);
extern void G3X_SetFog(BOOL, int, int, int);
extern void G3X_SetClearColor(unsigned short, int, int, int, BOOL);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned, unsigned);
extern const unsigned short d_021BFDAC[][4];
static inline void Shading(GXShading mode) { REG3D = (unsigned short)((REG3D & ~0x3002) | (mode << 1)); }
static inline void AntiAlias(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 0x10); else REG3D &= (unsigned short)~0x3010; }
static inline void AlphaTest(BOOL enable, int ref) { if (enable) { REG3D = (unsigned short)((REG3D & ~0x3000) | 4); *(volatile unsigned short *)0x04000340 = ref; } else REG3D &= (unsigned short)~0x3004; }
static inline void AlphaBlend(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 8); else REG3D &= (unsigned short)~0x3008; }
static inline void EdgeMarking(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 0x20); else REG3D &= (unsigned short)~0x3020; }
void func_021BDB70(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1, 1);
    *(volatile unsigned short *)0x04000008 = (unsigned short)((*(volatile unsigned short *)0x04000008 & ~3) | 1);
    Shading(SHADING1);
    AntiAlias(0);
    AlphaTest(0, 0);
    AlphaBlend(1);
    EdgeMarking(0);
    G3X_SetFog(0, 0, 0, 0);
    G3X_SetClearColor(0, 0, 0x7FFF, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xBFFF0000;
    for (i = 0; i < 4; i++) G3D_SYSTEM_SetLight((unsigned char)i, d_021BFDAC[i]);
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
}

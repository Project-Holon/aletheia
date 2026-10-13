/*
 * function: func_021BDD40
 * address: 0x021BDD40
 * packet: pkt_ov203_021BDD40
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: DISP3DCNT 04000060 reread at DD4E/DD5A/DD64/DD6E/DD7A; 04000580 store DD9E.
 * symbols:
 *   func_0204044C 0x0204044C arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021BFB7C 0x021BFB7C data a2
 */
typedef enum { ShadingToon = 0, ShadingHighlight = 1 } GXShading;
#define DISP3DCNT (*(volatile unsigned short *)0x04000060)
static inline void G3X_SetShading(GXShading shading) { DISP3DCNT = (unsigned short)((DISP3DCNT & ~0x3002) | (shading << 1)); }
static inline void G3X_AntiAlias(int enable) { if (enable) DISP3DCNT = (unsigned short)(DISP3DCNT & ~0x3000 | 16); else DISP3DCNT &= (unsigned short)~0x3010; }
static inline void G3X_AlphaTest(int enable, int ref) { if (enable) { DISP3DCNT = (unsigned short)(DISP3DCNT & ~0x3000 | 4); *(volatile unsigned short *)0x04000340 = ref; } else DISP3DCNT &= (unsigned short)~0x3004; }
static inline void G3X_AlphaBlend(int enable) { if (enable) DISP3DCNT = (unsigned short)(DISP3DCNT & ~0x3000 | 8); else DISP3DCNT &= (unsigned short)~0x3008; }
static inline void G3X_EdgeMarking(int enable) { if (enable) DISP3DCNT = (unsigned short)(DISP3DCNT & ~0x3000 | 32); else DISP3DCNT &= (unsigned short)~0x3020; }
extern const unsigned short d_021BFB7C[][4];
extern void func_0204044C(unsigned);
extern void func_0207DC44(int, int, int, int);
extern void func_0207DD24(unsigned short, int, int, int, int);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void func_02046BE0(unsigned, unsigned);
void func_021BDD40(void)
{
    unsigned i = 0;
    func_0204044C(0);
    G3X_SetShading(ShadingHighlight);
    G3X_AntiAlias(0);
    G3X_AlphaTest(0, 0);
    G3X_AlphaBlend(1);
    G3X_EdgeMarking(0);
    func_0207DC44(0, 0, 0, 0);
    func_0207DD24(0, 0, 32767, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for (; i < 4; i++) G3D_SYSTEM_SetLight((unsigned char)i, d_021BFB7C[i]);
    func_02046BE0(0, 0);
}

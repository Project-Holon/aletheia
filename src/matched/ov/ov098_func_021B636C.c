/*
 * function: func_021B636C
 * address: 0x021B636C
 * packet: pkt_ov098_021B636C
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B6394 POWCNT; 021B63C2,021B63D0,021B63D8 DISP3DCNT; 021B63F0 BG0CNT.
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   GF_FONT_ResetTextColor 0x0201DD60 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3X_SetFog 0x0207DC44 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   func_0204044C 0x0204044C arm
 *   func_020434DC 0x020434DC arm
 *   d_021B6DF4 0x021B6DF4 data a4
 *   d_021B6DB0 0x021B6DB0 data a4
 *   d_021B6DD8 0x021B6DD8 data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct DispVram;
struct DispConfig;
struct Cfg;
extern const struct DispVram d_021B6DF4;
extern struct DispConfig d_021B6DB0;
extern const struct Cfg d_021B6DD8;
extern void func_0203F8F4(u16);
extern void BMP_WIN_Init(u16);
extern void GF_FONT_ResetTextColor(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
extern void func_0203FC28(struct DispConfig *);
extern void G3D_SYSTEM_Init(u32, u32, u32, u32, u16, u32, void (*)(void));
extern void G3D_SYSTEM_SetSwapBuffersMode(u32, u32);
extern void G3X_SetFog(int, int, int, int);
extern void CLACT_InitSystem(const struct Cfg *, u32, u32);
extern void func_0204044C(u32);
extern void func_020434DC(u32, u32);
#define BLDCNT (*(volatile u16 *)0x04000050)
#define SBLDCNT (*(volatile u16 *)0x04001050)
#define POWCNT (*(volatile u16 *)0x04000304)
#define DISP3DCNT (*(volatile u16 *)0x04000060)
#define BG0CNT (*(volatile u16 *)0x04000008)
void func_021B636C(u16 heap)
{
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    GF_FONT_ResetTextColor();
    BG_SYS_SetVramBanks(&d_021B6DF4);
    BLDCNT = 0;
    SBLDCNT = 0;
    POWCNT = (u16)(POWCNT | 0x8000);
    func_0203FC28(&d_021B6DB0);
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, heap, 0);
    G3D_SYSTEM_SetSwapBuffersMode(1, 0);
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 8);
    DISP3DCNT &= (u16)~0x3020;
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 16);
    G3X_SetFog(0, 0, 0, 0);
    BG0CNT = (u16)((BG0CNT & ~3) | 1);
    CLACT_InitSystem(&d_021B6DD8, (u32)&d_021B6DF4, heap);
    func_0204044C(1);
    func_020434DC(16, 1);
}

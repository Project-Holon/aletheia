/*
 * function: BTLV_CORE_InitDisplay
 * address: 0x021E8E38
 * packet: pkt_ov093_021E8E38
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the POWCNT read/OR/write is spelled as assignment, not compound assignment.
 * volatile: 021E8E60 POWCNT; 021E8E8E,021E8E9C,021E8EA4 DISP3DCNT; 021E8EBE BG0CNT.
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   GF_FONT_ResetTextColor 0x0201DD60 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3X_SetFog 0x0207DC44 arm
 *   func_0207D63C 0x0207D63C arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   gBtlvCoreVramBanks 0x021F387C data a4
 *   gBtlvCoreDispConfig 0x021F3850 data a4
 *   gBtlvCoreBgConfig 0x021F3860 data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 gBtlvCoreVramBanks[], gBtlvCoreDispConfig[], gBtlvCoreBgConfig[];
extern void func_0203F8F4(u16);
extern void BMP_WIN_Init(u16);
extern void GF_FONT_ResetTextColor(void);
struct DispConfig;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void G3D_SYSTEM_Init(u32, u32, u32, u32, u16, u16, void (*)(void));
extern void G3D_SYSTEM_SetSwapBuffersMode(u32, u32);
extern void G3X_SetFog(int, int, int, int);
extern void func_0207D63C(void *, int, int, int, int);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
#define BLDCNT (*(volatile u16 *)0x04000050)
#define SBLDCNT (*(volatile u16 *)0x04001050)
#define POWCNT (*(volatile u16 *)0x04000304)
#define DISP3DCNT (*(volatile u16 *)0x04000060)
#define BG0CNT (*(volatile u16 *)0x04000008)
void BTLV_CORE_InitDisplay(u16 heap)
{
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    GF_FONT_ResetTextColor();
    BG_SYS_SetVramBanks((const struct DispVram *)gBtlvCoreVramBanks);
    BLDCNT = 0;
    SBLDCNT = 0;
    POWCNT = (u16)(POWCNT | 0x8000);
    func_0203FC28((struct DispConfig *)gBtlvCoreDispConfig);
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, heap, 0);
    G3D_SYSTEM_SetSwapBuffersMode(1, 0);
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 8);
    DISP3DCNT &= (u16)~0x3020;
    DISP3DCNT = (u16)((DISP3DCNT & ~0x3000) | 16);
    G3X_SetFog(0, 0, 0, 0);
    BG0CNT = (u16)((BG0CNT & ~3) | 1);
    func_0207D63C((void *)0x04000050, 2, 0x3d, 0x1f, 3);
    CLACT_InitSystem((const struct Cfg *)gBtlvCoreBgConfig, (u32)gBtlvCoreVramBanks, heap);
}

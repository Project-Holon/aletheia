/*
 * function: ERROR_SCREEN_Teardown
 * address:  0x021B641C
 * packet:   pkt_ov017_021B641C
 * region:   ov017
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   G2_GetBG1CharPtr  0x0207E24C  arm
 *   MIi_CpuClear16  0x02082A48  arm
 *   G2_GetBG1ScrPtr  0x0207DFB4  arm
 *   GX_ResetBankForSubBG  0x020809A0  arm
 *   GX_ResetBankForBG  0x020808F4  arm
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void *G2_GetBG1CharPtr(void);
extern void MIi_CpuClear16(int, u32, u32);
extern void *G2_GetBG1ScrPtr(void);
extern int GX_ResetBankForSubBG(void);
extern int GX_ResetBankForBG(void);

void ERROR_SCREEN_Teardown(void)
{
    GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, -16);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, -16);
    BG_SYS_SetSubVisiblePlanes(0);
    MIi_CpuClear16(0, (u32)G2_GetBG1CharPtr(), 0x4000);
    MIi_CpuClear16(0, (u32)G2_GetBG1ScrPtr(), 0x800);
    MIi_CpuClear16(0x7FFF, 0x05000000, 0x20);
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FF;
    GX_ResetBankForSubBG();
    GX_ResetBankForBG();
    GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, 0);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, 0);
}

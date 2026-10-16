/*
 * function: ERROR_SCREEN_Setup
 * address:  0x021B61F8
 * packet:   pkt_ov017_021B61F8
 * region:   ov017
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   GX_ResetBankForBG  0x020808F4  arm
 *   GX_ResetBankForSubBG  0x020809A0  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   GX_SetGraphicsMode  0x0207D4B0  arm
 *   ERROR_SCREEN_LoadBackground  0x021B6298  thumb  ov017
 *   ERROR_SCREEN_PrintMessage  0x021B6368  thumb  ov017
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern int GX_ResetBankForBG(void);
extern int GX_ResetBankForSubBG(void);
extern void func_0207FDCC(int);
extern void GX_SetGraphicsMode(int, int, int);
extern void ERROR_SCREEN_LoadBackground(void);
extern void ERROR_SCREEN_PrintMessage(int);

#define R32(a) (*(volatile u32 *)(a))
#define R16(a) (*(volatile u16 *)(a))

void ERROR_SCREEN_Setup(int a)
{
    GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, -16);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, -16);
    GX_ResetBankForBG();
    GX_ResetBankForSubBG();
    func_0207FDCC(4);
    GX_SetGraphicsMode(1, 0, 0);
    R32(0x04000000) = (R32(0x04000000) & 0xFFFFE0FF) | (1 << 9);
    R32(0x04000000) &= 0xFFFF1FFF;
    R16(0x0400000A) = (R16(0x0400000A) & 0x43) | 4;
    R16(0x0400000A) &= 0xFFBF;
    R32(0x04000014) = 0;
    R16(0x04000050) = 0;
    ERROR_SCREEN_LoadBackground();
    ERROR_SCREEN_PrintMessage(a);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, 0);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, 0x10);
}

/*
 * function: initGraph
 * address:  0x021C0B7C
 * packet:   pkt_ov016_021C0B7C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      initGraph (libdwcutil.TWL.HYB.a(main.o))
 *
 * symbols:
 *   GX_VBlankIntr                    0x0207d3e4 arm
 *   GX_SetBankForBG                  0x0207fdcc arm
 *   GX_SetBankForOBJ                 0x0207ffd0 arm
 *   GX_SetGraphicsMode               0x0207d4b0 arm
 *   GXx_SetMasterBrightness_         0x0207d534 arm
 *   G2x_SetBlendBrightness_          0x0207d658 arm
 *   GX_SetBankForSubBG               0x020806b0 arm
 *   GX_SetBankForSubOBJ              0x0208074c arm
 *   GXS_SetGraphicsMode              0x0207d518 arm
 *   DWCi_FNTlInit                    0x021d5824 arm
 *   DWCi_OBJlInit                    0x021d6e14 arm
 *   DWCi_OVRlInit                    0x021d6f9c arm
 *   DWCi_CELLlInit                   0x021d4cf4 arm
 *   GX_DispOn                        0x0207d46c arm
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

extern long GX_VBlankIntr(int enable);
extern void GX_SetBankForBG(int bg);
extern void GX_SetBankForOBJ(int obj);
extern void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d);
extern void GXx_SetMasterBrightness_(vu16 *reg, int brightness);
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern void GX_SetBankForSubBG(int sub_bg);
extern void GX_SetBankForSubOBJ(int sub_obj);
extern void GXS_SetGraphicsMode(int bgMode);
extern void DWCi_FNTlInit(void);
extern void DWCi_OBJlInit(void);
extern void DWCi_OVRlInit(void);
extern void DWCi_CELLlInit(void);
extern void GX_DispOn(void);

void initGraph(void)
{
    GX_VBlankIntr(0);
    GX_SetBankForBG(1);
    GX_SetBankForOBJ(2);
    GX_SetGraphicsMode(1, 0, 0);

    *(vu32 *)0x04000000 = *(vu32 *)0x04000000 & ~0x1f00;
    *(vu32 *)0x04000000 = *(vu32 *)0x04000000 & ~0xe000;
    GXx_SetMasterBrightness_((vu16 *)0x0400006c, 0);
    *(vu32 *)0x04000000 = (*(vu32 *)0x04000000 & 0xffcfffef) | 0x10 | 0x200000;
    *(vu16 *)0x04000008 = (u16)(*(vu16 *)0x04000008 & 0xffbf);
    *(vu16 *)0x0400000a = (u16)(*(vu16 *)0x0400000a & 0xffbf);
    *(vu16 *)0x0400000c = (u16)(*(vu16 *)0x0400000c & 0xffbf);
    *(vu16 *)0x0400000e = (u16)(*(vu16 *)0x0400000e & 0xffbf);
    *(vu32 *)0x04000010 = 0;
    *(vu32 *)0x04000014 = 0;
    *(vu32 *)0x04000018 = 0;
    *(vu32 *)0x0400001c = 0;
    G2x_SetBlendBrightness_(0x04000050, 0x3f, 0x10);
    GX_SetBankForSubBG(0x80);
    GX_SetBankForSubOBJ(0x100);
    GXS_SetGraphicsMode(0);

    *(vu32 *)0x04001000 = *(vu32 *)0x04001000 & ~0x1f00;
    *(vu32 *)0x04001000 = *(vu32 *)0x04001000 & ~0xe000;
    GXx_SetMasterBrightness_((vu16 *)0x0400106c, 0);
    *(vu32 *)0x04001000 = (*(vu32 *)0x04001000 & 0xffcfffef) | 0x10;
    *(vu16 *)0x04001008 = (u16)(*(vu16 *)0x04001008 & 0xffbf);
    *(vu16 *)0x0400100a = (u16)(*(vu16 *)0x0400100a & 0xffbf);
    *(vu16 *)0x0400100c = (u16)(*(vu16 *)0x0400100c & 0xffbf);
    *(vu16 *)0x0400100e = (u16)(*(vu16 *)0x0400100e & 0xffbf);
    *(vu32 *)0x04001010 = 0;
    *(vu32 *)0x04001014 = 0;
    *(vu32 *)0x04001018 = 0;
    *(vu32 *)0x0400101c = 0;
    G2x_SetBlendBrightness_(0x04001050, 0x3f, 0x10);

    *(vu16 *)0x04000008 = (u16)((*(vu16 *)0x04000008 & 0x43) | 0xc00);
    *(vu16 *)0x0400000a = (u16)((*(vu16 *)0x0400000a & 0x43) | 0x108 | 0xc00);
    *(vu16 *)0x0400000c = (u16)((*(vu16 *)0x0400000c & 0x43) | 0xe10);
    *(vu16 *)0x0400000e = (u16)((*(vu16 *)0x0400000e & 0x43) | 0xf10);
    *(vu16 *)0x04001008 = (u16)((*(vu16 *)0x04001008 & 0x43) | 0xc00);
    *(vu16 *)0x0400100a = (u16)((*(vu16 *)0x0400100a & 0x43) | 0xd00);
    *(vu16 *)0x0400100c = (u16)((*(vu16 *)0x0400100c & 0x43) | 0xe00);
    *(vu16 *)0x0400100e = (u16)((*(vu16 *)0x0400100e & 0x43) | 0xf00);

    *(vu32 *)0x04000000 = *(vu32 *)0x04000000 & ~0x38000000;
    *(vu32 *)0x04000000 = *(vu32 *)0x04000000 & ~0x7000000;
    *(vu16 *)0x04000304 = (u16)(*(vu16 *)0x04000304 & ~0x8000);

    DWCi_FNTlInit();
    DWCi_OBJlInit();
    DWCi_OVRlInit();
    DWCi_CELLlInit();
    GX_DispOn();
    *(vu32 *)0x04001000 = *(vu32 *)0x04001000 | 0x10000;
    GX_VBlankIntr(1);
}

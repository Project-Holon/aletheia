/*
 * file:     unit_021C0970_p01.c
 * unit:     yes
 * function: func_021C0B7C, func_021C0DE8, func_021C0E40, func_021C0E50
 * address:  0x021C0B7C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_0207D42C  0x0207D42C  arm
 *   func_021D7474  0x021D7474  arm  ov016
 *   PM_SetLCDPower 0x0208C64C  arm
 *   func_021D6538  0x021D6538  arm  ov016
 *   func_021D6CE4  0x021D6CE4  arm  ov016
 *   func_021CFF80  0x021CFF80  arm  ov016
 *   func_021D4DC8  0x021D4DC8  arm  ov016
 *   func_021D6EEC  0x021D6EEC  arm  ov016
 *   func_021D5904  0x021D5904  arm  ov016
 *   func_021D556C  0x021D556C  arm  ov016
 *   func_021D4A20  0x021D4A20  arm  ov016
 *   func_021D7588  0x021D7588  arm  ov016
 *   func_021D63A8  0x021D63A8  arm  ov016
 *   func_021D72F8  0x021D72F8  arm  ov016
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
extern void func_0207D42C(void);
extern void func_021D7474(void);
extern int PM_SetLCDPower(int sw);
extern void func_021D6538(void);
extern void func_021D6CE4(void);
extern void func_021CFF80(void);
extern void func_021D4DC8(void);
extern void func_021D6EEC(void);
extern void func_021D5904(void);
extern void func_021D556C(void);
extern void func_021D4A20(void);
extern void func_021D7588(void);
extern void func_021D63A8(void);
extern void func_021D72F8(void);
void initGraph(void);
void func_021C0DE8(void);
void func_021C0E40(unsigned int v);
void func_021C0E50(unsigned int a, unsigned int b);


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


/*
 * sdk:      procEnd (libdwcutil.TWL.HYB.a main.o)
 */
void func_021C0DE8(void)
{
    func_0207D42C();
    *(volatile unsigned int *)0x04001000 &= ~0x10000;
    func_021D7474();
    PM_SetLCDPower(1);
    func_021D6538();
    func_021D6CE4();
    func_021CFF80();
    func_021D4DC8();
    func_021D6EEC();
    func_021D5904();
    func_021D556C();
    func_021D4A20();
    func_021D7588();
    func_021D63A8();
    func_021D72F8();
}

/*
 * Store a word into the global object at 0x021DE56C, field +0x0c.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0E40.c \
 *       --func func_021C0E40 --addr 0x021C0E40 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C0E40(unsigned int v)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    p[3] = v;
}

/*
 * Store two words into fields +0x10 and +0x14 of the global object.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0E50.c \
 *       --func func_021C0E50 --addr 0x021C0E50 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C0E50(unsigned int a, unsigned int b)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    p[4] = a;
    p[5] = b;
}

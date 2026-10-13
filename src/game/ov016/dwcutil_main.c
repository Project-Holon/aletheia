/*
 * file:     dwcutil_main.c
 * unit:     yes
 * function: func_021C0970, func_021C0A2C, func_021C0AA8, func_021C0B7C, func_021C0DE8, func_021C0E40, func_021C0E50, func_021C0E64, func_021C0E8C, func_021C0EA0, func_021C0EC8, func_021C0ED8, func_021C0EF0, func_021C0F0C, func_021C0F20
 * address:  0x021C0970
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
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_02177ED8  0x02177ED8  arm  ov009
 *   func_02177EC8  0x02177EC8  arm  ov009
 *   func_021C0B7C  0x021C0B7C  arm  ov016
 *   func_021CFEBC  0x021CFEBC  arm  ov016
 *   DWCi_IPTlUpdate  0x021D656C  arm  ov016
 *   func_021D75D0  0x021D75D0  arm  ov016
 *   func_021D6BC8  0x021D6BC8  arm  ov016
 *   func_021D7448  0x021D7448  arm  ov016
 *   func_02087AE4  0x02087AE4  arm
 *   func_021C16F4  0x021C16F4  arm  ov016
 *   g_021DE56C     0x021DE56C  data
 *   g_021DB04C     0x021DB04C  data
 *   func_0207D42C  0x0207D42C  arm
 *   func_02087058  0x02087058  arm
 *   OS_Terminate   0x02088234  arm
 *   func_02087244  0x02087244  arm
 *   func_0207D3E4  0x0207D3E4  arm
 *   FX_Init  0x0207D148  arm
 *   func_0207AD04  0x0207AD04  arm
 *   func_0208A924  0x0208A924  arm
 *   func_02088788  0x02088788  arm
 *   func_021D7274  0x021D7274  arm  ov016
 *   func_021D6360  0x021D6360  arm  ov016
 *   func_021D6C78  0x021D6C78  arm  ov016
 *   func_021D7484  0x021D7484  arm  ov016
 *   func_021D486C  0x021D486C  arm  ov016
 *   func_021D64B8  0x021D64B8  arm  ov016
 *   func_021D551C  0x021D551C  arm  ov016
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_020589D0  0x020589D0  arm
 *   func_021D6438  0x021D6438  arm  ov016
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
 *   Language                         0x021DE56C  data
 */
typedef struct Param {
    unsigned int mode : 4;
    unsigned int flags : 28;
} Param;

typedef struct UtilState {
    unsigned char lang;
    unsigned char end;
    unsigned char pad2[2];
    void *work;
    Param param;
    void (*scene)(void);
    void (*scene_10)(void);
    void *f14;
} UtilState;

typedef union PU {
    Param b;
    unsigned int v;
} PU;

typedef unsigned short u16;

typedef unsigned long u32;

typedef volatile u16 vu16;

typedef volatile u32 vu32;

struct LANG {
    char pad[0x10];
    void *f10;
    void *f14;
};

struct Ov016Bits8 {
    char pad[8];
    unsigned int f : 4;
};

extern int OS_IsRunOnTwl(void);
extern char *func_02177ED8(void);
extern void func_02177EC8(int v);
extern void func_021C0B7C(void);
extern void func_021CFEBC(void);
extern void DWCi_IPTlUpdate();
extern void func_021D75D0(int kind);
extern void func_021D6BC8(void);
extern void func_021D7448(void);
extern void func_02087AE4(void);
extern void func_021C16F4(void);
extern void func_0207D42C(void);
extern int func_02087058(void);
extern void OS_Terminate(void);
extern int func_02087244(void);
extern long func_0207D3E4(int enable);
extern void FX_Init(void);
extern void func_0207AD04(unsigned long default_dma_no);
extern void func_0208A924(void);
extern void func_02088788(void);
extern void func_021D7274(void);
extern void func_021D6360(void *address);
extern void func_021D6C78(void);
extern void func_021D7484(void);
extern void func_021D486C(void);
extern void func_021D64B8(void);
extern void func_021D551C(void);
extern void *func_021D6414(unsigned long size, int alignment);
extern int func_020589D0(void *work);
extern void func_021D6438(void **mem);
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
int func_021C0970(void *work, int language, int param);
int func_021C0A2C(int lang, unsigned int param);
void func_021C0AA8(void);
void initGraph(void);
void func_021C0DE8(void);
void func_021C0E40(unsigned int v);
void func_021C0E50(unsigned int a, unsigned int b);
void DWCi_GetParam_(void **param0, void **param1);
void func_021C0E8C(unsigned int a, unsigned int b);
void func_021C0EA0(unsigned int *a, unsigned int *b);
unsigned char func_021C0EC8(void);
unsigned int func_021C0ED8(void);
int func_021C0EF0(unsigned int v);
void func_021C0F0C(void);
unsigned char func_021C0F20(void);
extern UtilState g_021DE56C;
extern char g_021DB04C[];
extern struct LANG Language;



/*
 * sdk:      DWC_StartUtility (libdwcutil.TWL.HYB.a main.o)
 */
int func_021C0970(void *work, int language, int param)
{
    char *tempNasUrl;
    int result;
    if (OS_IsRunOnTwl())
        return -2;
    g_021DE56C.work = work;
    if (!func_021C0A2C(language, param))
        return -1;
    tempNasUrl = func_02177ED8();
    func_02177EC8((int)g_021DB04C);
    g_021DE56C.end = 0;
    func_021C0AA8();
    func_021C0B7C();
    func_021CFEBC();
    func_021C0E40((unsigned int)func_021C16F4);
    result = 0;
    do {
        DWCi_IPTlUpdate();
        g_021DE56C.scene();
        func_021D75D0(result);
        func_021D6BC8();
        func_021D7448();
        func_02087AE4();
    } while (!g_021DE56C.end);
    func_021C0DE8();
    func_02177EC8((int)tempNasUrl);
    return result;
}



/*
 * sdk:      checkParam (libdwcutil.TWL.HYB.a main.o)
 */
int func_021C0A2C(int lang, unsigned int param)
{
    g_021DE56C.lang = lang;
    *(unsigned int *)&g_021DE56C.param = param;
    if (lang < 0 || lang > 6)
        return 0;
    if (g_021DE56C.param.mode > 1)
        return 0;
    if (g_021DE56C.param.flags & 2)
        return 0;
    if (lang != 0 && (g_021DE56C.param.flags & 1))
        return 0;
    if (lang == 0 && !(g_021DE56C.param.flags & 1))
        return 0;
    return 1;

}




/*
 * sdk:      initGame (libdwcutil.TWL.HYB.a main.o)
 */
void func_021C0AA8(void)
{
    void *work;
    int zero;
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    unsigned short old = *ime;
    *ime = 0;
    func_0207D42C();
    *(volatile unsigned int *)0x04001000 &= ~0x10000;
    if (!func_02087058())
        OS_Terminate();
    if (!func_02087244())
        OS_Terminate();
    zero = 0;
    func_0207D3E4(zero);
    FX_Init();
    func_0207AD04(zero - 1);
    func_0208A924();
    func_02088788();
    func_0207D42C();
    *(volatile unsigned int *)0x04001000 &= ~0x10000;
    func_021D7274();
    func_021D6360(g_021DE56C.work);
    func_021D6C78();
    func_021D7484();
    func_021D486C();
    func_021D64B8();
    func_021D551C();
    work = func_021D6414(0x1000, 0x20);
    func_020589D0(work);
    func_021D6438(&work);
}





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




void DWCi_GetParam_(void **param0, void **param1)
{
    if (param0)
        *param0 = Language.f10;
    if (param1)
        *param1 = Language.f14;
}



/*
 * Store two words into fields +0x18 and +0x1c of the global object.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0E8C.c \
 *       --func func_021C0E8C --addr 0x021C0E8C --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C0E8C(unsigned int a, unsigned int b)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    p[6] = a;
    p[7] = b;
}



/*
 * Hand back fields +0x18 and +0x1c through two optional out pointers.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0EA0.c \
 *       --func func_021C0EA0 --addr 0x021C0EA0 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C0EA0(unsigned int *a, unsigned int *b)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    if (a)
        *a = p[6];
    if (b)
        *b = p[7];
}



/*
 * Read the first byte of the global object at 0x021DE56C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0EC8.c \
 *       --func func_021C0EC8 --addr 0x021C0EC8 --region ov016 --cc dsi/1.1p1 --arm
 */
unsigned char func_021C0EC8(void)
{
    return *(unsigned char *)0x021DE56C;
}




/*
 * Low nibble of the word at +0x08 of the global object (4-bit field).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0ED8.c \
 *       --func func_021C0ED8 --addr 0x021C0ED8 --region ov016 --cc dsi/1.1p1 --arm
 */
unsigned int func_021C0ED8(void)
{
    struct Ov016Bits8 *p = (struct Ov016Bits8 *)0x021DE56C;
    return p->f;
}



/*
 * Test the argument against bits 4.. of the word at +0x08.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0EF0.c \
 *       --func func_021C0EF0 --addr 0x021C0EF0 --region ov016 --cc dsi/1.1p1 --arm
 */
int func_021C0EF0(unsigned int v)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    return (v & (p[2] >> 4)) != 0;
}



/*
 * Set byte +0x01 of the global object to 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0F0C.c \
 *       --func func_021C0F0C --addr 0x021C0F0C --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C0F0C(void)
{
    unsigned char *p = (unsigned char *)0x021DE56C;
    p[1] = 1;
}




/*
 * sdk:      kDWCi_Language (libdwcutil.TWL.HYB.a main.o)
 */
unsigned char func_021C0F20(void)
{
    if ((*(unsigned char *)&g_021DE56C) == 6)
        return 0x38;
    if ((*(unsigned char *)&g_021DE56C) == 1) {
        if (!((*(unsigned int *)((char *)&(*(unsigned char *)&g_021DE56C) + 8) >> 4) & 2))
            return 0x37;
    }
    return (*(unsigned char *)&g_021DE56C) + 0x31;
}

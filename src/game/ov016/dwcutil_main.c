/*
 * file:     dwcutil_main.c
 * unit:     yes
 * function: DWC_StartUtility, checkParam, initGame, initGraph, procEnd, DWCi_ChangeScene, DWCi_SetParam_, DWCi_GetParam_, DWCi_SetParam2_, DWCi_GetParam2_, DWCi_Language, DWCi_Entry, DWCi_Flag, DWCi_EndUtility, kDWCi_Language
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
 *   DWC_Auth_GetCustomNas  0x02177ED8  arm  ov009
 *   DWC_Auth_SetCustomNas  0x02177EC8  arm  ov009
 *   initGraph  0x021C0B7C  arm  ov016
 *   DWCi_SNDlInit  0x021CFEBC  arm  ov016
 *   DWCi_IPTlUpdate  0x021D656C  arm  ov016
 *   DWCi_TSKlAct  0x021D75D0  arm  ov016
 *   DWCi_IPTlCheckFold  0x021D6BC8  arm  ov016
 *   DWCi_SetLedWireless  0x021D7448  arm  ov016
 *   OS_WaitVBlankIntr  0x02087AE4  arm
 *   DWCi_SceneInit  0x021C16F4  arm  ov016
 *   gDwcutilMainWork     0x021DE56C  data
 *   sDwcutilMainTable     0x021DB04C  data
 *   GX_DispOff  0x0207D42C  arm
 *   OS_IsTickAvailable  0x02087058  arm
 *   OS_Terminate   0x02088234  arm
 *   OS_IsAlarmAvailable  0x02087244  arm
 *   GX_VBlankIntr  0x0207D3E4  arm
 *   FX_Init  0x0207D148  arm
 *   FS_Init  0x0207AD04  arm
 *   TP_Init  0x0208A924  arm
 *   RTC_Init  0x02088788  arm
 *   DWCi_ClearVram  0x021D7274  arm  ov016
 *   DWCi_HEAPlInit  0x021D6360  arm  ov016
 *   DWCi_ITRlIntr  0x021D6C78  arm  ov016
 *   DWCi_TSKlInit  0x021D7484  arm  ov016
 *   DWCi_ARClInit  0x021D486C  arm  ov016
 *   DWCi_IPTlInit  0x021D64B8  arm  ov016
 *   DWCi_EFFlInit  0x021D551C  arm  ov016
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWC_BM_Init  0x020589D0  arm
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
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
 *   DWCi_SetLedNormal  0x021D7474  arm  ov016
 *   PM_SetLCDPower 0x0208C64C  arm
 *   DWCi_IPTlEnd  0x021D6538  arm  ov016
 *   DWCi_ITRlEnd  0x021D6CE4  arm  ov016
 *   DWCi_SNDlEnd  0x021CFF80  arm  ov016
 *   DWCi_CELLlEnd  0x021D4DC8  arm  ov016
 *   DWCi_OBJlEnd  0x021D6EEC  arm  ov016
 *   DWCi_FNTlEnd  0x021D5904  arm  ov016
 *   DWCi_EFFlEnd  0x021D556C  arm  ov016
 *   DWCi_ARClEnd  0x021D4A20  arm  ov016
 *   DWCi_TSKlEnd  0x021D7588  arm  ov016
 *   DWCi_HEAPlEnd  0x021D63A8  arm  ov016
 *   DWCi_RepairVram  0x021D72F8  arm  ov016
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
    void *reserved14;
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
    void *stepParam;
    void *buttonParam;
};

struct Ov016Bits8 {
    char pad[8];
    unsigned int f : 4;
};

extern int OS_IsRunOnTwl(void);
extern char *DWC_Auth_GetCustomNas(void);
extern void DWC_Auth_SetCustomNas(char *v);
extern void DWCi_SNDlInit(void);
extern void DWCi_IPTlUpdate();
extern void DWCi_TSKlAct(int kind);
extern void DWCi_IPTlCheckFold(void);
extern void DWCi_SetLedWireless(void);
extern void OS_WaitVBlankIntr(void);
extern void DWCi_SceneInit(void);
extern void GX_DispOff(void);
extern int OS_IsTickAvailable(void);
extern void OS_Terminate(void);
extern int OS_IsAlarmAvailable(void);
extern void FX_Init(void);
extern void FS_Init(unsigned long default_dma_no);
extern void TP_Init(void);
extern void RTC_Init(void);
extern void DWCi_ClearVram(void);
extern void DWCi_HEAPlInit(void *address);
extern void DWCi_ITRlIntr(void);
extern void DWCi_TSKlInit(void);
extern void DWCi_ARClInit(void);
extern void DWCi_IPTlInit(void);
extern void DWCi_EFFlInit(void);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern int DWC_BM_Init(void *work);
extern void DWCi_HEAPlFree_(void **mem);
extern long GX_VBlankIntr(int enable);
extern void GX_SetBankForBG(int bg);
extern void GX_SetBankForOBJ(int obj);
extern void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d);
extern void GXx_SetMasterBrightness_(vu16 *reg, int brightness);
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern void GX_SetBankForSubBG(int sub_bg);
extern void GX_SetBankForSubOBJ(int sub_obj);
extern void GXS_SetGraphicsMode(u32 mode);
extern void DWCi_FNTlInit(void);
extern void DWCi_OBJlInit(void);
extern void DWCi_OVRlInit(void);
extern void DWCi_CELLlInit(void);
extern void GX_DispOn(void);
extern void DWCi_SetLedNormal(void);
extern int PM_SetLCDPower(int sw);
extern void DWCi_IPTlEnd(void);
extern void DWCi_ITRlEnd(void);
extern void DWCi_SNDlEnd(void);
extern void DWCi_CELLlEnd(void);
extern void DWCi_OBJlEnd(void);
extern void DWCi_FNTlEnd(void);
extern void DWCi_EFFlEnd(void);
extern void DWCi_ARClEnd(void);
extern void DWCi_TSKlEnd(void);
extern void DWCi_HEAPlEnd(void);
extern void DWCi_RepairVram(void);
int DWC_StartUtility(void *work, int language, int param);
void initGraph(void);
void DWCi_ChangeScene(unsigned int v);
void DWCi_SetParam_(unsigned int a, unsigned int b);
void DWCi_GetParam_(void **outStepParam, void **outButtonParam);
void DWCi_SetParam2_(unsigned int a, unsigned int b);
void DWCi_GetParam2_(unsigned int *a, unsigned int *b);
unsigned char DWCi_Language(void);
unsigned int DWCi_Entry(void);
int DWCi_Flag(unsigned int v);
void DWCi_EndUtility(void);
unsigned char kDWCi_Language(void);
extern UtilState gDwcutilMainWork;
extern char sDwcutilMainTable[];
extern struct LANG Language;


/*
 * sdk:      DWC_StartUtility (libdwcutil.TWL.HYB.a main.o)
 */

static int checkParam(int lang, unsigned int param);
static void initGame(void);
static void procEnd(void);
int DWC_StartUtility(void *work, int language, int param)
{
    char *tempNasUrl;
    int result;
    if (OS_IsRunOnTwl())
        return -2;
    gDwcutilMainWork.work = work;
    if (!checkParam(language, param))
        return -1;
    tempNasUrl = DWC_Auth_GetCustomNas();
    DWC_Auth_SetCustomNas(sDwcutilMainTable);
    gDwcutilMainWork.end = 0;
    initGame();
    initGraph();
    DWCi_SNDlInit();
    DWCi_ChangeScene((unsigned int)DWCi_SceneInit);
    result = 0;
    do {
        DWCi_IPTlUpdate();
        gDwcutilMainWork.scene();
        DWCi_TSKlAct(result);
        DWCi_IPTlCheckFold();
        DWCi_SetLedWireless();
        OS_WaitVBlankIntr();
    } while (!gDwcutilMainWork.end);
    procEnd();
    DWC_Auth_SetCustomNas(tempNasUrl);
    return result;
}


/*
 * sdk:      checkParam (libdwcutil.TWL.HYB.a main.o)
 */
static int checkParam(int lang, unsigned int param)
{
    gDwcutilMainWork.lang = lang;
    *(unsigned int *)&gDwcutilMainWork.param = param;
    if (lang < 0 || lang > 6)
        return 0;
    if (gDwcutilMainWork.param.mode > 1)
        return 0;
    if (gDwcutilMainWork.param.flags & 2)
        return 0;
    if (lang != 0 && (gDwcutilMainWork.param.flags & 1))
        return 0;
    if (lang == 0 && !(gDwcutilMainWork.param.flags & 1))
        return 0;
    return 1;

}


/*
 * sdk:      initGame (libdwcutil.TWL.HYB.a main.o)
 */
static void initGame(void)
{
    void *work;
    int zero;
    volatile unsigned short *ime = (volatile unsigned short *)0x04000208;
    unsigned short old = *ime;
    *ime = 0;
    GX_DispOff();
    *(volatile unsigned int *)0x04001000 &= ~0x10000;
    if (!OS_IsTickAvailable())
        OS_Terminate();
    if (!OS_IsAlarmAvailable())
        OS_Terminate();
    zero = 0;
    GX_VBlankIntr(zero);
    FX_Init();
    FS_Init(zero - 1);
    TP_Init();
    RTC_Init();
    GX_DispOff();
    *(volatile unsigned int *)0x04001000 &= ~0x10000;
    DWCi_ClearVram();
    DWCi_HEAPlInit(gDwcutilMainWork.work);
    DWCi_ITRlIntr();
    DWCi_TSKlInit();
    DWCi_ARClInit();
    DWCi_IPTlInit();
    DWCi_EFFlInit();
    work = DWCi_HEAPlAllocEx(0x1000, 0x20);
    DWC_BM_Init(work);
    DWCi_HEAPlFree_(&work);
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
static void procEnd(void)
{
    GX_DispOff();
    *(volatile unsigned int *)0x04001000 &= ~0x10000;
    DWCi_SetLedNormal();
    PM_SetLCDPower(1);
    DWCi_IPTlEnd();
    DWCi_ITRlEnd();
    DWCi_SNDlEnd();
    DWCi_CELLlEnd();
    DWCi_OBJlEnd();
    DWCi_FNTlEnd();
    DWCi_EFFlEnd();
    DWCi_ARClEnd();
    DWCi_TSKlEnd();
    DWCi_HEAPlEnd();
    DWCi_RepairVram();
}


/*
 * Store a word into the global object at 0x021DE56C, field +0x0c.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_ChangeScene.c \
 *       --func DWCi_ChangeScene --addr 0x021C0E40 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_ChangeScene(unsigned int v)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    p[3] = v;
}


/*
 * Store two words into fields +0x10 and +0x14 of the global object.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SetParam_.c \
 *       --func DWCi_SetParam_ --addr 0x021C0E50 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SetParam_(unsigned int stepParam, unsigned int buttonParam)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    p[4] = stepParam;
    p[5] = buttonParam;
}


void DWCi_GetParam_(void **outStepParam, void **outButtonParam)
{
    if (outStepParam)
        *outStepParam = Language.stepParam;
    if (outButtonParam)
        *outButtonParam = Language.buttonParam;
}


/*
 * Store two words into fields +0x18 and +0x1c of the global object.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SetParam2_.c \
 *       --func DWCi_SetParam2_ --addr 0x021C0E8C --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SetParam2_(unsigned int a, unsigned int b)
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
 *   python tools/match.py one --src src/matched/DWCi_GetParam2_.c \
 *       --func DWCi_GetParam2_ --addr 0x021C0EA0 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_GetParam2_(unsigned int *a, unsigned int *b)
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
 *   python tools/match.py one --src src/matched/DWCi_Language.c \
 *       --func DWCi_Language --addr 0x021C0EC8 --region ov016 --cc dsi/1.1p1 --arm
 */
unsigned char DWCi_Language(void)
{
    return *(unsigned char *)0x021DE56C;
}


/*
 * Low nibble of the word at +0x08 of the global object (4-bit field).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_Entry.c \
 *       --func DWCi_Entry --addr 0x021C0ED8 --region ov016 --cc dsi/1.1p1 --arm
 */
unsigned int DWCi_Entry(void)
{
    struct Ov016Bits8 *p = (struct Ov016Bits8 *)0x021DE56C;
    return p->f;
}


/*
 * Test the argument against bits 4.. of the word at +0x08.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_Flag.c \
 *       --func DWCi_Flag --addr 0x021C0EF0 --region ov016 --cc dsi/1.1p1 --arm
 */
int DWCi_Flag(unsigned int v)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    return (v & (p[2] >> 4)) != 0;
}


/*
 * Set byte +0x01 of the global object to 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_EndUtility.c \
 *       --func DWCi_EndUtility --addr 0x021C0F0C --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_EndUtility(void)
{
    unsigned char *p = (unsigned char *)0x021DE56C;
    p[1] = 1;
}


/*
 * sdk:      kDWCi_Language (libdwcutil.TWL.HYB.a main.o)
 */
unsigned char kDWCi_Language(void)
{
    if ((*(unsigned char *)&gDwcutilMainWork) == 6)
        return 0x38;
    if ((*(unsigned char *)&gDwcutilMainWork) == 1) {
        if (!((*(unsigned int *)((char *)&(*(unsigned char *)&gDwcutilMainWork) + 8) >> 4) & 2))
            return 0x37;
    }
    return (*(unsigned char *)&gDwcutilMainWork) + 0x31;
}

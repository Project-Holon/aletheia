/*
 * file:     scenesettest.c
 * unit:     yes
 * function: DWCi_SceneSetTest, initGraphics, initAc, procInit, procInit1, DWCi_SceneSetTest_procScene, DWCi_SceneSetTest_input, DWCi_SceneSetTest_draw, DWCi_SceneSetTest_button, endScene, endScene1, endScene2, taskAc, DWCi_SceneSetTestAcAlloc, DWCi_SceneSetTestAcFree
 * address:  0x021CD160
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      DWCi_SceneSetTest (libdwcutil.TWL.HYB.a scenesettest.o)
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/DWCi_SceneSetTest.c \n *       --func DWCi_SceneSetTest --addr 0x021CD160 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 * Load three tilemaps through DWCi_CMNlLoadResource, then set the low two bits of five
 * halfword registers (the 0x04001008/0x04000008 pair and their +2 neighbours).
 * Addresses are Black-image addresses.
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlist.o), symbol procInit1 (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 * The symbols_sdk row names scenesetlist.o, but this copy sits in the next scene's range
 * (after DWCi_SceneSetTest at 0x021CD160) and chains to its own procScene at 0x021CD3EC; the
 * body is the same static procInit1 every libdwcutil scene carries.
 *   python tools/match.py one --src src/matched/ov016_func_021CD3B8.c \
 *       --func procInit1 --addr 0x021CD3B8 --region ov016 --cc 1.1p1 --arm
 * sdk:      endScene (libdwcutil.TWL.HYB.a(sceneoptmovcomm.o))
 *
 * symbols:
 *   gSceneSetTestWork     0x021DE61C  data
 *   DWCi_GetParam2_  0x021C0EA0  arm  ov016
 *   DWCi_COMMENTlDispEx  0x021BD060  arm  ov016
 *   DWCi_CMNlStep  0x021BD214  arm  ov016
 *   DWCi_HLlLoadSet  0x021BD6D4  arm  ov016
 *   DWCi_CMNlMsgDraw  0x021BD29C  arm  ov016
 *   DWCi_ANIMElInitEx  0x021BC820  arm  ov016
 *   DWCi_ICONlInit  0x021BD744  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   sSceneSetTestPathJbBgStep3Char    0x021DB7BC  data
 *   sSceneSetTestPathYbBgStep3Pltt    0x021DB7D4  data
 *   sSceneSetTestPathXb4MultiScr    0x021DB7EC  data
 *   GX_LoadBG2Char    0x0207F0B8  data
 *   GX_LoadBGPltt    0x0207E3D0  data
 *   GX_LoadBG2Scr    0x0207EB78  data
 *   DWCi_SETTIGNlGet  0x021CF404  arm  ov016
 *   MIi_CpuCopy32  0x02082A90  arm
 *   DWC_AC_Create  0x0205B98C  arm
 *   OS_Terminate  0x02088234  arm
 *   DWCi_AC_InsertApInfo  0x0205BFEC  arm
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   sSceneSetTestConfig     0x021DA898  data
 *   DWCi_EFFlFade  0x021D55A4  arm
 *   DWCi_GXlVisible  0x021D603C  arm
 *   procInit1  0x021CD3B8  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_SETTINGlGetMemMap  0x021CFBD4  arm  ov016
 *   DWC_AC_Destroy  0x0205BE6C  arm
 *   DWCi_BACKUPlGetWifi  0x020589C4  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   DWCi_ANIMElEnd  0x021BC8EC  arm  ov016
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm  ov016
 *   DWCi_GXlInvisible  0x021D6090  arm  ov016
 *   DWCi_SetParam_  0x021C0E50  arm  ov016
 *   DWCi_SceneSetError  0x021C7CE4  arm  ov016
 *   DWCi_SceneSetTestCompletet  0x021CD580  arm  ov016
 *   DWC_AC_Process  0x0205BC78  arm
 *   DWCi_ICONlEnd  0x021BD7F4  arm  ov016
 *   DWCi_SNDlStop  0x021D0014  arm  ov016
 *   DWC_AC_GetStatus  0x0205BD64  arm
 *   DWCi_SetErrorCode  0x021C82EC  arm  ov016
 *   DWCi_TSKlDelete  0x021D7724  arm  ov016
 *   DWCi_HEAPlAllocEx            0x021D6414  arm
 *   DWCi_HEAPlFree2              0x021D647C  arm
 */
struct tagDWCACConfig;
#include "../types.h"

#include "../sdk_ncfg.h"

typedef struct { unsigned char pad[0xF4]; unsigned char ap; } SettingInfo;

typedef struct { unsigned char pad0[10]; unsigned char channel; unsigned char pad1[9]; } ACConfig;

typedef _Bool bool;

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

typedef struct tagAREA { unsigned short l, t, w, h; } AREA;

#include "gx_oam_types.h"

typedef struct tagSETTINGINFO {
    NCFGApInfo     ap;                /* 0x00 */
    unsigned char  netmask[4];        /* 0xF0 */
    unsigned char  idx;               /* 0xF4 */
    bool           ipAuto;            /* 0xF5 */
    bool           dnsAuto;           /* 0xF6 */
} SETTINGINFO;

typedef struct tagPUSH { void *task; unsigned char count[4]; } PUSH;

typedef struct tagMEMSSL {
    PUSH           push;              /* 0x00 */
    void          *back;              /* 0x08 */
    void          *pltt[2];           /* 0x0C */
    void          *canv;              /* 0x14 */
    GXOamAttr     *obj[7];            /* 0x18 */
    GXOamAttr     *icon;              /* 0x34 */
    void          *task;              /* 0x38 */
    void          *taskV;             /* 0x3C */
    unsigned char  choose;            /* 0x40 */
    unsigned char  disp;              /* 0x41 */
    unsigned char  focusLast;         /* 0x42 */
    unsigned char  lastDns;           /* 0x43 */
    bool           renew;             /* 0x44 */
    bool           scroll;            /* 0x45 */
    bool           sound[2];          /* 0x46 */
} MEMSSL;

/* scenesetlist.o .bss at 0x021DE5EC, members at their vendor offsets */
typedef struct {
    unsigned char  Focus;             /* 0x00 */
    unsigned char  RetScene;          /* 0x01 */
    unsigned char  FocusClm;          /* 0x02 */
    unsigned short Pos;               /* 0x04 */
    MEMSSL        *MemSsl;            /* 0x08 */
} SCENESETLIST_BSS;

/* scenesetlist.o .rodata at 0x021DA61C, members at their vendor offsets */
typedef struct {
    unsigned char  PALETTE_NUM[3];    /* 0x00 */
    signed char    MSG_IDX[7];        /* 0x03 */
    AREA           A_EDIT;            /* 0x0A */
    AREA           A_NO;              /* 0x12 */
    AREA           A_YES;             /* 0x1A */
    unsigned char  CLM2FCS_TBL[9];    /* 0x22 */
    unsigned char  OFS_BACK[9];       /* 0x2B */
    unsigned char  FCS2CLM_TBL[11];   /* 0x34 */
    unsigned char  CELL_IDX[5][3];    /* 0x3F */
    unsigned short BACK_POS[9];       /* 0x4E */
    RECT           R_BUTTON[3];       /* 0x60 */
    RECT           R_FOCUS[6];        /* 0x78 */
} SCENESETLIST_RODATA;

extern void DWCi_GetParam2_(unsigned int *a, unsigned int *b);
extern int DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_CMNlStep(int step);
extern void DWCi_HLlLoadSet(void);
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_ANIMElInitEx(int color);
extern void DWCi_ICONlInit(int type);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern char *DWCi_SETTIGNlGet(void);
extern void MIi_CpuCopy32(void *srcp, void *destp, unsigned long size);
extern int DWC_AC_Create(struct tagDWCACConfig *config);
extern void OS_Terminate(void);
extern void DWCi_AC_InsertApInfo(int no, struct NCFGApInfo *info);
struct TCB;
extern struct TCB *DWCi_TSKlForm(int kind, void (*func)(void *), void *work, unsigned char prio);
extern int DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int a, int b);
extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_ChangeScene(void (*scene)(void));
extern char *DWCi_SETTINGlGetMemMap(void);
extern int DWC_AC_Destroy(void);
extern void *DWCi_BACKUPlGetWifi();
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void DWCi_ANIMElEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SceneSetError(void);
extern void DWCi_SceneSetTestCompletet(void);
extern int DWC_AC_Process(void);
extern void DWCi_ICONlEnd(void);
extern void DWCi_SNDlStop(void);
extern int DWC_AC_GetStatus(void);
extern void DWCi_SetErrorCode(unsigned int v);
extern void DWCi_TSKlDelete(int kind, void *task);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_HEAPlFree2(void *mem);
void DWCi_SceneSetTest(void);
void procInit1(void);
void DWCi_SceneSetTest_procScene(void);
void DWCi_SceneSetTest_input(void);
void DWCi_SceneSetTest_draw(void);
void DWCi_SceneSetTest_button(void);
void *acAlloc(void *unused, unsigned long size);
void acFree(void *unused, void *ptr);
extern unsigned char gSceneSetTestWork;
extern unsigned short sSceneSetTestPathJbBgStep3Char[];
extern unsigned short sSceneSetTestPathYbBgStep3Pltt[];
extern unsigned short sSceneSetTestPathXb4MultiScr[];
extern unsigned short GX_LoadBG2Char[];
extern unsigned short GX_LoadBGPltt[];
extern unsigned short GX_LoadBG2Scr[];
extern ACConfig sSceneSetTestConfig;
extern SCENESETLIST_BSS scenesetlist_bss;
extern const SCENESETLIST_RODATA scenesetlist_rodata;

static void initGraphics(void);
static void initAc(void);
static void procInit(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
static void taskAc(void *task);

void DWCi_SceneSetTest(void)
{
    int scene;
    gSceneSetTestWork = 0;
    initGraphics();
    DWCi_GetParam2_(0, (unsigned int *)((void **)&scene));
    if (scene == 0)
        DWCi_COMMENTlDispEx(49, -1, 0);
    DWCi_CMNlStep(2);
    if (scene == 0)
        DWCi_HLlLoadSet();
    DWCi_CMNlMsgDraw(44);
    DWCi_ANIMElInitEx(0);
    initAc();
    DWCi_ICONlInit(0);
    DWCi_SNDlPlay(12);
    DWCi_ChangeScene(procInit);
}

static void initGraphics(void)
{
    u16 *p;

    DWCi_CMNlLoadResource((char *)((int)sSceneSetTestPathJbBgStep3Char), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Char));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetTestPathYbBgStep3Pltt), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBGPltt));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetTestPathXb4MultiScr), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Scr));

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x04000008;
    p[0] = (p[0] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}

/*
 * sdk:      initAc (libdwcutil.TWL.HYB.a scenesettest.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/initAc.c \n *       --func initAc --addr 0x021CD2A0 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void initAc(void)
{
    SettingInfo *info;
    ACConfig config;
    int scene;
    info = (SettingInfo *)DWCi_SETTIGNlGet();
    MIi_CpuCopy32(&sSceneSetTestConfig, &config, 0x14);
    DWCi_GetParam2_(0, (unsigned int *)((void **)&scene));
    if (scene == 2)
        config.channel = 4;
    else
        config.channel = info->ap + 1;
    if (DWC_AC_Create((struct tagDWCACConfig *)(&config)) == 0)
        OS_Terminate();
    if (scene == 0)
        DWCi_AC_InsertApInfo(info->ap, (struct NCFGApInfo *)info);
    DWCi_TSKlForm(0, taskAc, 0, 0x78);
}

static void procInit(void)
{
    int v;

    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(0, 0x15);
    DWCi_GetParam2_(0, (unsigned int *)(&v));
    if (v == 0) {
        DWCi_EFFlFade(2, 1, 1, 8);
        DWCi_GXlVisible(1, 1);
    }
    DWCi_ChangeScene(procInit1);
}

void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_ChangeScene(DWCi_SceneSetTest_procScene);
}

/*
 * Call DWCi_SceneSetTest_input, DWCi_SceneSetTest_draw, DWCi_SceneSetTest_button.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetTest_procScene.c \
 *       --func DWCi_SceneSetTest_procScene --addr 0x021CD3EC --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetTest_procScene(void)
{
    DWCi_SceneSetTest_input();
    DWCi_SceneSetTest_draw();
    DWCi_SceneSetTest_button();
}

void DWCi_SceneSetTest_input(void)
{
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetTest_draw.c \
 *       --func DWCi_SceneSetTest_draw --addr 0x021CD404 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetTest_draw(void)
{
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetTest_button.c \
 *       --func DWCi_SceneSetTest_button --addr 0x021CD408 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetTest_button(void)
{
}

static void endScene(void)
{
	DWCi_EFFlFade(3, 0, 0x15, 8);
	DWCi_ChangeScene(endScene1);
}

/*
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesettest.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD434.c \n *       --func endScene1 --addr 0x021CD434 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void endScene1(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_ChangeScene(endScene2);
}

/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a scenesettest.o)
 */
static void endScene2(void)
{
    unsigned char *map = (unsigned char *)DWCi_SETTINGlGetMemMap();
    if (DWC_AC_Destroy() == 0)
        return;
    MI_CpuCopy8(DWCi_BACKUPlGetWifi(), map + 0xF0, 14);
    MI_CpuCopy8(DWCi_BACKUPlGetWifi(), map + 0x1F0, 14);
    DWCi_ANIMElEnd();
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_GXlInvisible(0, 21);
    if (gSceneSetTestWork == 0) {
        DWCi_SetParam_(0, (unsigned int)(1));
        DWCi_ChangeScene(DWCi_SceneSetError);
    } else {
        DWCi_SetParam_(0, (unsigned int)(1));
        DWCi_ChangeScene(DWCi_SceneSetTestCompletet);
    }
}

/*
 * sdk:      taskAc (libdwcutil.TWL.HYB.a scenesettest.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/taskAc.c \n *       --func taskAc --addr 0x021CD4F4 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 */
static void taskAc(void *task)
{
    int rs = DWC_AC_Process();
    if (rs == 0)
        return;
    DWCi_ICONlEnd();
    DWCi_SNDlStop();
    if (rs > 0) {
        gSceneSetTestWork = 1;
        DWCi_SNDlPlay(17);
    } else {
        DWCi_SetErrorCode(DWC_AC_GetStatus());
        DWCi_SNDlPlay(18);
    }
    DWCi_ChangeScene(endScene);
    DWCi_TSKlDelete(0, task);
}

void *acAlloc(void *unused, unsigned long size)
{
    return DWCi_HEAPlAllocEx(size, 0x20);
}

void acFree(void *unused, void *ptr)
{
    DWCi_HEAPlFree2(ptr);
}

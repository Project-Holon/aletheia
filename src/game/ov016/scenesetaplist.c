/*
 * file:     scenesetaplist.c
 * unit:     yes
 * function: DWCi_SceneSetApList, initGraphics, DWCi_SceneSetApListInitScrollBar, DWCi_SceneSetApListGetCharName, DWCi_SceneSetApListProcInit, procInit1, procInit2, DWCi_SceneSetApList_procScene, input, draw, button, DWCi_SceneSetApListEndScene, DWCi_SceneSetApListEndScene1, DWCi_SceneSetApListEndScene2, DWCi_SceneSetApListDrawApInfo, DWCi_SceneSetApListDrawAp, drapApObj, DWCi_SceneSetApListSetOffset, DWCi_SceneSetApListTaskUp, taskDown, DWCi_SceneSetApListTaskVBlank, DWCi_SceneSetApListDispFocus, DWCi_SceneSetApListMoveFocus, DWCi_SceneSetApListScrollUp, scrollDown, DWCi_SceneSetApListDispPushButton, DWCi_SceneSetApListProcError, DWCi_SceneSetApListProcError1
 * address:  0x021C50D4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Call input, draw, button.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetApList_procScene.c \
 *       --func DWCi_SceneSetApList_procScene --addr 0x021C55B4 --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_CMNlStep                    0x021BD214  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_FNTlFormBgEx                0x021D5A58  arm
 *   DWCi_GetParam2_                  0x021C0EA0  arm
 *   DWCi_HEAPlAllocEx                0x021D6414  arm
 *   DWCi_HLlLoadSet                  0x021BD6D4  arm
 *   DWCi_SEARCHlGetApInfo            0x021CF114  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   initGraphics                     0x021C519C  arm
 *   scenesetaplist_bss               0x021DE5D8  data
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   DWCi_Char   0x021BD170  arm  ov016
 *   DWCi_ARClReadEx   0x021D4B68  arm  ov016
 *   DWCi_SCREENlInit   0x021CE668  arm  ov016
 *   DWCi_SCREENlRenew   0x021CE6F0  arm  ov016
 *   sSceneSetApListPathXb4ApListBackScr   0x021DA58C  data
 *   sSceneSetApListPathYbBgStep31Pltt   0x021DA574  data
 *   sSceneSetApListPathJb4ApListScr   0x021DB438  data
 *   GX_LoadBG3Scr   0x0207ECF0  data
 *   gSceneSetApListWork   0x021DE5D8  data
 *   DWCi_SBlInit                     0x021CE874  arm
 *   FX_DivS32                        0x0207C958  arm
 *   CELL_LV                          0x021DA51F  data
 *   DWCi_CEINlSet                    0x021D52D4  arm
 *   DWCi_CEINlSetExObj               0x021D5368  arm
 *   scenesetaplist_rodata            0x021DA51C  data
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlSet                     0x021BCB28  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_FOCUSlDisp4                 0x021BD4C8  arm
 *   DWCi_IPTlCheckRepeat             0x021D6864  arm
 *   DWCi_IPTlCheckTrigger            0x021D6824  arm
 *   DWCi_SCREENlCopyPalette          0x021CE7B0  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_SceneEnd                    0x021C1630  arm
 *   DWCi_TPlCheckTrigger             0x021D696C  arm
 *   scenemenu_bss                    0x021DE59C  data
 *   scenemenu_init_20658             0x021DA474  data
 *   scenemenu_rodata                 0x021DA478  data
 *   DWCi_IPTlCheckRelease            0x021D68A4  arm
 *   DWCi_R_SCR                       0x021DAA7C  data
 *   DWCi_SBlDisable                  0x021CE9D0  arm
 *   DWCi_TPlCheckRelease             0x021D6A7C  arm
 *   scrollDown                       0x021C6488  arm
 *   DWCi_FOCUSlDelete                0x021BD5A8  arm
 *   DWCi_SBlGet                      0x021CE984  arm
 *   DWCi_SBlGetState                 0x021CE998  arm
 *   FX_ModS32                        0x0207C994  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_ARClRelease                 0x021D4C68  arm
 *   DWCi_BTNlIsEnd                   0x021BCB58  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_FNTlDeleteBg                0x021D5C48  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_HEAPlFree_                  0x021D6438  arm
 *   DWCi_OBJlDelete                  0x021D6F38  arm
 *   DWCi_SBlEnd                      0x021CE94C  arm
 *   DWCi_SCREENlEnd                  0x021CE6C4  arm
 *   DWCi_SEARCHlEnd                  0x021CEF50  arm
 *   DWCi_SETTIGNlGet                 0x021CF404  arm
 *   DWCi_SETTINGlSetSetting          0x021CF80C  arm
 *   DWCi_SETTINGlSetSsid             0x021CF440  arm
 *   DWCi_SceneSetEdit32              0x021C6588  arm
 *   DWCi_SceneSetSearch              0x021CB780  arm
 *   DWCi_SceneSetSelectWay           0x021CC998  arm
 *   DWCi_SceneSetTestConfirm         0x021CD80C  arm
 *   DWCi_SetParam2_                  0x021C0E8C  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   DWCi_TSKlDeleteEx                0x021D7744  arm
 *   DWCi_FNTlClear                   0x021D5F14  arm
 *   DWCi_FNTlRenewBg                 0x021D5FC4  arm
 *   drapApObj                        0x021C5FA8  arm
 *   DWCi_FNTlDrawStringEx            0x021D5DB0  arm
 *   DWCi_STRlNLen                    0x021D7200  arm
 *   MI_CpuFill8                      0x02082BCC  arm
 *   DWCi_SBlEnable                   0x021CE9B8  arm
 *   DWCi_SBlSet                      0x021CE9AC  arm
 *   DWCi_TSKlDelete                  0x021D7724  arm
 *   DWCi_FOCUSlDisp                  0x021BD41C  arm
 *   taskDown   0x021C61A4   arm
 *   gSceneSetApListWorkBytes      0x021DE5D8   data
 *   scenesetaplist_str_20957         0x021DA518  data
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 */
#include "../../matched/include/G_SCENEMENU_BSS.h"
#include "../../matched/include/G_SCENESETAPLIST_BSS.h"

typedef _Bool bool;

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

#include "gx_oam_types.h"

typedef struct tagAPINFO {
    unsigned char  ssid[32];          /* 0x00 */
    unsigned char  bssid[6];          /* 0x20 */
    unsigned short level;             /* 0x26 */
    unsigned char  wep;               /* 0x28 */
} APINFO;

typedef struct tagMEMSSAL {
    APINFO        *info;              /* 0x00 */
    void          *back;              /* 0x04 */
    void          *pltt;              /* 0x08 */
    void          *canv;              /* 0x0C */
    GXOamAttr     *objWep[5];         /* 0x10 */
    GXOamAttr     *objLevel[5];       /* 0x24 */
    void          *task;              /* 0x38 */
    void          *taskV;             /* 0x3C */
    unsigned short distScroll;        /* 0x40 */
    unsigned short nameWep[3];        /* 0x42 */
    unsigned short nameLv[4];         /* 0x48 */
    signed char    push;              /* 0x50 */
    unsigned char  apNum;             /* 0x51 */
    unsigned char  apIdx;             /* 0x52 */
    unsigned char  distBar;           /* 0x53 */
    unsigned char  choose;            /* 0x54 */
    unsigned char  disp;              /* 0x55 */
    bool           renew;             /* 0x56 */
    bool           scroll;            /* 0x57 */
    bool           sound[2];          /* 0x58 */
} MEMSSAL;

/* scenesetaplist.o .bss at 0x021DE5D8, members at their vendor offsets */
typedef struct {
    unsigned char  Focus;             /* 0x00 */
    unsigned short Pos;               /* 0x02 */
    MEMSSAL       *MemSsal;           /* 0x04 */
} SCENESETAPLIST_BSS;

/* scenesetaplist.o .rodata at 0x021DA51C, members at their vendor offsets */
typedef struct {
    unsigned char  CELL_WEP[3];       /* 0x00 */
    unsigned char  CELL_LV[4];        /* 0x03 */
    RECT           R_TOUCH[5];        /* 0x08 */
    RECT           R_FOCUS[5];        /* 0x30 */
} SCENESETAPLIST_RODATA;

#include "../sdk_ncfg.h"

typedef struct tagSETTINGINFO {
    NCFGApInfo     ap;                /* 0x00 */
    unsigned char  netmask[4];        /* 0xF0 */
    unsigned char  idx;               /* 0xF4 */
    bool           ipAuto;            /* 0xF5 */
    bool           dnsAuto;           /* 0xF6 */
} SETTINGINFO;

#include "../types.h"

typedef struct { char s[0x19]; } T25;

typedef struct { char s[0x17]; } T23;

typedef struct { char s[0x16]; } T22;

typedef struct { char s[0x15]; } T21;

/* scenemenu.o .bss at 0x021DE59C, members at their vendor offsets */
typedef struct {
    unsigned char  FocusPos;          /* 0x00 */
    void          *Palette;           /* 0x04 */
} SCENEMENU_BSS;

/* scenemenu.o .rodata at 0x021DA478, members at their vendor offsets */
typedef struct {
    RECT           R_TOUCH[2];        /* 0x00 */
    RECT           R_FOCUS[2];        /* 0x10 */
} SCENEMENU_RODATA;

/* PALETTE's initialiser is the compiler's @20658 in its own .rodata section */
typedef struct { unsigned char v[2]; } PALETTE_INIT;

typedef struct { unsigned char v[1]; } SSAL_N1;

extern void DWCi_ARClRelease(void *file);
extern void DWCi_BTNlDisable(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_BTNlEnd(void);
extern char DWCi_BTNlGet(void);
extern int DWCi_BTNlIsEnd(void);
extern void DWCi_BTNlSet(char v);
extern void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);
extern GXOamAttr *DWCi_CEINlSetExObj(int lcd, int idx);
extern void DWCi_CMNlStep(int step);
extern int DWCi_COMMENTlDelete(void);
extern int DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_ChangeScene(void (*scene)());
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_FNTlClear(void *canvas, int color);
extern void DWCi_FNTlDeleteBg(void *canvas);
extern void DWCi_FNTlDrawStringEx(void *canvas, int x, int y, int color, int interval, unsigned short *txt, int font);
extern void *DWCi_FNTlFormBgEx(int lcd, int font);
extern void DWCi_FNTlRenewBg(int x);
extern void DWCi_FOCUSlDelete(void);
extern void DWCi_FOCUSlDisp(int kind, int x0, int x1, int y);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_GetParam2_(unsigned int *a, unsigned int *b);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_HEAPlFree_(void **mem);
extern void DWCi_HLlLoadSet(void);
extern int DWCi_IPTlCheckRelease(unsigned int f);
extern int DWCi_IPTlCheckRepeat(unsigned int f);
extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern void DWCi_OBJlDelete(unsigned int *obj);
extern void DWCi_SBlDisable(void);
extern void DWCi_SBlEnable(void);
extern void DWCi_SBlEnd(void);
extern unsigned char DWCi_SBlGet(void);
extern unsigned char DWCi_SBlGetState(void);
extern void DWCi_SBlInit(int kind, int max, int x, int y, int pos);
extern void DWCi_SBlSet(int pos);
extern void DWCi_SCREENlCopyPalette(void *src, int sColor, int dColor);
extern void DWCi_SCREENlEnd(void);
extern void DWCi_SEARCHlEnd(void);
extern int DWCi_SEARCHlGetApInfo(APINFO **info);
extern SETTINGINFO *DWCi_SETTIGNlGet(void);
extern void DWCi_SETTINGlSetSetting(int idx);
extern void DWCi_SETTINGlSetSsid(char *ssid);
extern void DWCi_SNDlPlay(int no);
extern int DWCi_STRlNLen(unsigned char *s, int maxlen);
extern void DWCi_SetParam2_(unsigned int a, unsigned int b);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern int DWCi_TPlCheckRelease(unsigned short *a);
extern int DWCi_TPlCheckTrigger(unsigned short *a);
extern void DWCi_TSKlDelete(int kind, void *task);
extern void DWCi_TSKlDeleteEx(int kind, void *task);
struct TCB;
extern struct TCB *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void DWCi_WINlEnd(void);
extern char DWCi_WINlGet(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern int DWCi_WINlIsInit(void);
extern long FX_DivS32(long a, long b);
extern long FX_ModS32(long a, long b);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void DWCi_SceneSetEdit32(void);
extern void DWCi_SceneSetSearch(void);
extern void DWCi_SceneSetSelectWay(void);
extern void DWCi_SceneSetTestConfirm(void);
extern void DWCi_CMNlLoadResource(int, int);
extern unsigned char *DWCi_Char(unsigned char *name);
extern void *DWCi_ARClReadEx(char *path, unsigned int *size, int alignment);
extern void DWCi_SCREENlInit(void *scr);
extern void DWCi_SCREENlRenew(void);
extern void DWCi_CMNlButton(int kind);
extern void DWCi_FOCUSlDisp4(int x0, int x1, int y0, int y1);
extern void DWCi_SceneEnd(void);
void DWCi_SceneSetApList(void);
void DWCi_SceneSetApList_procScene(void);
extern SCENESETAPLIST_BSS scenesetaplist_bss;
extern const SCENESETAPLIST_RODATA scenesetaplist_rodata;
extern RECT DWCi_R_SCR;
extern T25 sSceneSetApListPathXb4ApListBackScr;
extern T22 sSceneSetApListPathYbBgStep31Pltt;
extern unsigned char sSceneSetApListPathJb4ApListScr[];
extern unsigned char GX_LoadBG3Scr[];
extern unsigned char gSceneSetApListWorkBytes[];
extern struct SCENESETAPLIST_BSS gSceneSetApListWork;
/* CELL_LV is named on its own: the loop reaches it through its own pool word
   (the vendor symbol at scenesetaplist_rodata + 3), not through the section base. */
extern const unsigned char CELL_LV[4];
extern struct SCENEMENU_BSS scenemenu_bss;
extern const SCENEMENU_RODATA scenemenu_rodata;
extern const PALETTE_INIT scenemenu_init_20658;
extern const SSAL_N1 scenesetaplist_str_20957;


static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y)
{
    oam->attr01 = (oam->attr01 & 0xFE00FF00) | (y & 0xFF) | ((x & 0x1FF) << 16);
}

static inline void G2_SetOBJPriority(GXOamAttr *oam, int priority)
{
    oam->attr2 = (unsigned short)((oam->attr2 & ~0xC00) | (priority << 10));
}

static void initGraphics(void);
static void initScrollBar(void);
static void getCharName(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void input(void);
static void draw(void);
static void button(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
static void drawApInfo(void);
static void drawAp(int ap, int column);
static void drapApObj(int entryIndex, int objIndex);
static void setOffset(void);
static void taskUp(void *task);
static void taskDown(void *task);
static void taskVBlank(void);
static void dispFocus(void);
static void moveFocus(int dir);
static void scrollUp(void);
static void scrollDown(void);
static void dispPushButton(void);
static void procError(void);
static void procError1(void);

void DWCi_SceneSetApList(void)
{
    int prm;

    scenesetaplist_bss.MemSsal = DWCi_HEAPlAllocEx(sizeof(MEMSSAL), 4);
    DWCi_GetParam2_((unsigned int *)&prm, 0);
    if (prm == 0) {
        scenesetaplist_bss.Focus = 0;
        scenesetaplist_bss.Pos = 0;
    }
    scenesetaplist_bss.MemSsal->apNum = DWCi_SEARCHlGetApInfo(&scenesetaplist_bss.MemSsal->info);
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_COMMENTlDispEx(0x34, -1, 0);
    DWCi_CMNlStep(2);
    initScrollBar();
    getCharName();
    scenesetaplist_bss.MemSsal->canv = DWCi_FNTlFormBgEx(0, 0);
    scenesetaplist_bss.MemSsal->taskV = DWCi_TSKlForm(1, (void (*)(void *, void *))taskVBlank, 0, 0x6e);
    drawApInfo();
    dispFocus();
    DWCi_ChangeScene(procInit);
}

/*
 * Copy a 0x19-byte and a 0x16-byte NCL resource path into two stack buffers
 * (the first copy is odd-sized, so it ends with a trailing byte), load one
 * tilemap through DWCi_CMNlLoadResource, publish both buffers through
 * DWCi_Char/DWCi_ARClReadEx into the record held by 0x021DE5D8+4, poke
 * DWCi_SCREENlInit/DWCi_SCREENlRenew on it, then set the low two bits of the
 * 0x04001008 pair, 0x04000008 and the 0x0400000A triple.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/initGraphics.c \
 *       --func initGraphics --addr 0x021C519C --region ov016 --cc dsi/1.1p1 --arm
 */
static void initGraphics(void)
{
    T25 buf2;
    T22 buf;
    u16 *p;

    buf2 = sSceneSetApListPathXb4ApListBackScr;
    buf = sSceneSetApListPathYbBgStep31Pltt;
    DWCi_CMNlLoadResource((int)sSceneSetApListPathJb4ApListScr, (int)GX_LoadBG3Scr);

    (*(int **)(gSceneSetApListWorkBytes + 4))[1] = (int)DWCi_ARClReadEx((char *)DWCi_Char((unsigned char *)(&buf2)), 0, (int)4);
    DWCi_SCREENlInit((void *)((*(int **)(gSceneSetApListWorkBytes + 4))[1]));
    DWCi_SCREENlRenew();
    (*(int **)(gSceneSetApListWorkBytes + 4))[2] = (int)DWCi_ARClReadEx((char *)DWCi_Char((unsigned char *)(&buf)), 0, (int)4);

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x04000008;
    p[0] = (p[0] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 2;
    p[1] = (p[1] & ~3) | 3;
    p[2] = (p[2] & ~3) | 2;
}

static void initScrollBar(void)
{
    int kind;
    int pos = 0;

    scenesetaplist_bss.MemSsal->distScroll = (scenesetaplist_bss.MemSsal->apNum - 4) * 28;
    if (scenesetaplist_bss.MemSsal->apNum <= 4) {
        kind = 0;
        scenesetaplist_bss.MemSsal->distBar = 0;
    } else if (scenesetaplist_bss.MemSsal->apNum <= 8) {
        scenesetaplist_bss.MemSsal->distBar = 31;
        kind = 1;
    } else {
        scenesetaplist_bss.MemSsal->distBar = 55;
        kind = 2;
    }
    if (kind != 0)
        pos = FX_DivS32(scenesetaplist_bss.Pos * scenesetaplist_bss.MemSsal->distBar, scenesetaplist_bss.MemSsal->distScroll);
    DWCi_SBlInit(kind, 0x55, 0xec, 0x3f, pos);
}

static void getCharName(void)
{
    int num;
    int i;

    num = scenesetaplist_bss.MemSsal->apNum;
    if (num > 5)
        num = 5;
    for (i = 0; i < num; i++) {
        scenesetaplist_bss.MemSsal->objWep[i] = DWCi_CEINlSetExObj(0, 0x2e);
        scenesetaplist_bss.MemSsal->objLevel[i] = DWCi_CEINlSetExObj(0, 0x18);
    }
    for (i = 0; i < sizeof(scenesetaplist_rodata.CELL_WEP); i++) {
        DWCi_CEINlSet(0, scenesetaplist_rodata.CELL_WEP[i], scenesetaplist_bss.MemSsal->objWep[0]);
        scenesetaplist_bss.MemSsal->nameWep[i] = scenesetaplist_bss.MemSsal->objWep[0]->attr2 & 0x3ff;
    }
    for (i = 0; i < sizeof(scenesetaplist_rodata.CELL_LV); i++) {
        DWCi_CEINlSet(0, CELL_LV[i], scenesetaplist_bss.MemSsal->objLevel[0]);
        scenesetaplist_bss.MemSsal->nameLv[i] = scenesetaplist_bss.MemSsal->objLevel[0]->attr2 & 0x3ff;
    }
    for (i = 0; i < num; i++) {
        G2_SetOBJPriority(scenesetaplist_bss.MemSsal->objWep[i], 3);
        G2_SetOBJPriority(scenesetaplist_bss.MemSsal->objLevel[i], 3);
    }
}

static void procInit(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x1d, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x1d);
    DWCi_ChangeScene(procInit1);
}

static void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(0);
    DWCi_ChangeScene(procInit2);
}

static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(DWCi_SceneSetApList_procScene);
}

void DWCi_SceneSetApList_procScene(void)
{
    input();
    draw();
    button();
}

static void input(void)
{
    int i;

    if (scenesetaplist_bss.MemSsal->task != 0 || scenesetaplist_bss.MemSsal->scroll)
        return;
    if (DWCi_TPlCheckTrigger((unsigned short *)(&DWCi_R_SCR))) {
        scenesetaplist_bss.MemSsal->push = -1;
        for (i = 0; i < sizeof(scenesetaplist_rodata.R_TOUCH) / sizeof(RECT); i++) {
            if (DWCi_TPlCheckTrigger((unsigned short *)&scenesetaplist_rodata.R_TOUCH[i])) {
                if (i < 4) {
                    scenesetaplist_bss.MemSsal->push = i;
                    break;
                }
                DWCi_BTNlSet(1);
                scenesetaplist_bss.Focus = i;
                dispFocus();
                return;
            }
        }
    }
    if (DWCi_TPlCheckRelease((unsigned short *)(&DWCi_R_SCR))) {
        for (i = 0; i < 4; i++) {
            if (DWCi_TPlCheckRelease((unsigned short *)&scenesetaplist_rodata.R_TOUCH[i])) {
                if (scenesetaplist_bss.MemSsal->push != i)
                    break;
                if (i >= scenesetaplist_bss.MemSsal->apNum) {
                    DWCi_SNDlPlay(9);
                    break;
                }
                DWCi_BTNlSet(1);
                scenesetaplist_bss.Focus = i;
                dispFocus();
                return;
            }
        }
    }
    if (DWCi_IPTlCheckTrigger(0x01)) {
        DWCi_BTNlSet(1);
        DWCi_SBlDisable();
        return;
    }
    if (DWCi_IPTlCheckTrigger(0x02)) {
        DWCi_BTNlSet(0);
        return;
    }
    if (DWCi_IPTlCheckRepeat(0x200)) {
        scrollDown();
        return;
    }
    if (DWCi_IPTlCheckRelease(0x200)) {
        scenesetaplist_bss.MemSsal->sound[1] = 0;
        return;
    }
    if (DWCi_IPTlCheckRepeat(0x100)) {
        scrollUp();
        return;
    }
    if (DWCi_IPTlCheckRelease(0x100)) {
        scenesetaplist_bss.MemSsal->sound[1] = 0;
        return;
    }
    if (DWCi_IPTlCheckRepeat(0x40)) {
        moveFocus(1);
        return;
    }
    if (DWCi_IPTlCheckRelease(0x40)) {
        scenesetaplist_bss.MemSsal->sound[1] = 0;
        return;
    }
    if (DWCi_IPTlCheckRepeat(0x80)) {
        moveFocus(3);
        return;
    }
    if (DWCi_IPTlCheckRelease(0x80))
        scenesetaplist_bss.MemSsal->sound[1] = 0;
}

static void draw(void)
{
    int def;

    if (scenesetaplist_bss.MemSsal->task != 0)
        return;
    if (scenesetaplist_bss.MemSsal->disp != 0)
        scenesetaplist_bss.MemSsal->disp--;

    switch (DWCi_SBlGetState()) {
    case 1:
        scenesetaplist_bss.MemSsal->scroll = 1;
        DWCi_BTNlDisable();
        return;
    case 2:
        if (scenesetaplist_bss.MemSsal->disp != 0)
            return;
        DWCi_FOCUSlDelete();
        scenesetaplist_bss.Pos = FX_DivS32(DWCi_SBlGet() * scenesetaplist_bss.MemSsal->distScroll, scenesetaplist_bss.MemSsal->distBar);
        drawApInfo();
        scenesetaplist_bss.MemSsal->disp = 4;
        return;
    case 3:
        scenesetaplist_bss.MemSsal->scroll = 0;
        DWCi_BTNlEnable();
        scenesetaplist_bss.Pos = FX_DivS32(DWCi_SBlGet() * scenesetaplist_bss.MemSsal->distScroll, scenesetaplist_bss.MemSsal->distBar);
        DWCi_SNDlPlay(0x13);
        drawApInfo();
        def = FX_ModS32(scenesetaplist_bss.Pos, 28);
        if (def == 0) {
            dispFocus();
            return;
        }
        if (def < 14) {
            scenesetaplist_bss.MemSsal->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskUp, 0, 0x78);
            return;
        }
        scenesetaplist_bss.MemSsal->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskDown, 0, 0x78);
        return;
    case 4:
        if (scenesetaplist_bss.Pos == 0) {
            if (scenesetaplist_bss.MemSsal->sound[0] != 0)
                return;
            DWCi_SNDlPlay(9);
            scenesetaplist_bss.MemSsal->sound[0] = 1;
            return;
        }
        DWCi_SNDlPlay(0x13);
        scenesetaplist_bss.MemSsal->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskUp, 0, 0x78);
        return;
    case 6:
        if (scenesetaplist_bss.MemSsal->apNum > 4 && scenesetaplist_bss.Pos != scenesetaplist_bss.MemSsal->distScroll)
            goto down;
        if (scenesetaplist_bss.MemSsal->sound[0] != 0)
            return;
        DWCi_SNDlPlay(9);
        scenesetaplist_bss.MemSsal->sound[0] = 1;
        return;
    down:
        DWCi_SNDlPlay(0x13);
        scenesetaplist_bss.MemSsal->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskDown, 0, 0x78);
        return;
    case 5:
    case 7:
        scenesetaplist_bss.MemSsal->sound[0] = 0;
        return;
    }
    return;
}

static void button(void)
{
    int idx;

    if (scenesetaplist_bss.MemSsal->task != 0 || scenesetaplist_bss.MemSsal->scroll)
        return;
    switch (DWCi_BTNlGet()) {
    case 0:
        DWCi_SNDlPlay(7);
        goto change;
    case 1:
        if (scenesetaplist_bss.Focus == 4) {
            scenesetaplist_bss.MemSsal->choose = 1;
            DWCi_SNDlPlay(6);
            dispPushButton();
        } else {
            idx = FX_DivS32(scenesetaplist_bss.Pos, 28) + scenesetaplist_bss.Focus;
            if (scenesetaplist_bss.MemSsal->info[idx].wep == 2) {
                DWCi_SNDlPlay(9);
                DWCi_SBlDisable();
                DWCi_BTNlDisable();
                DWCi_WINlInitEx(0xe, 1, 1, -1, 0);
                DWCi_ChangeScene(procError);
                return;
            }
            scenesetaplist_bss.MemSsal->choose = 1;
            scenesetaplist_bss.MemSsal->apIdx = idx;
            DWCi_SNDlPlay(6);
        }
    change:
        DWCi_ChangeScene(endScene);
        break;
    }
}

static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (scenesetaplist_bss.MemSsal->choose)
        DWCi_BTNlEnd();
    else
        DWCi_BTNlDisable();
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x1d, 8);
    DWCi_ChangeScene(endScene2);
}

static void endScene2(void)
{
    int i;

    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    if (!DWCi_BTNlIsEnd())
        return;
    DWCi_TSKlDeleteEx(1, scenesetaplist_bss.MemSsal->taskV);
    for (i = 0; i < 5; i++) {
        if (scenesetaplist_bss.MemSsal->objWep[i])
            DWCi_OBJlDelete((unsigned int *)scenesetaplist_bss.MemSsal->objWep[i]);
        if (scenesetaplist_bss.MemSsal->objLevel[i])
            DWCi_OBJlDelete((unsigned int *)scenesetaplist_bss.MemSsal->objLevel[i]);
    }
    DWCi_FNTlDeleteBg(scenesetaplist_bss.MemSsal->canv);
    DWCi_SBlEnd();
    DWCi_FOCUSlDelete();
    DWCi_COMMENTlDelete();
    DWCi_SCREENlEnd();
    DWCi_ARClRelease(scenesetaplist_bss.MemSsal->back);
    DWCi_ARClRelease(scenesetaplist_bss.MemSsal->pltt);
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x1d);
    *(volatile unsigned long *)0x04000010 = 0;
    *(volatile unsigned long *)0x04000018 = 0;
    if (!scenesetaplist_bss.MemSsal->choose) {
        DWCi_SEARCHlEnd();
        DWCi_SETTINGlSetSetting(DWCi_SETTIGNlGet()->idx);
        DWCi_SetParam_(2, 0);
        DWCi_ChangeScene(DWCi_SceneSetSelectWay);
    } else if (scenesetaplist_bss.Focus == 4) {
        DWCi_SEARCHlEnd();
        DWCi_SetParam_(0, 1);
        DWCi_ChangeScene(DWCi_SceneSetSearch);
    } else {
        DWCi_SETTINGlSetSsid((char *)scenesetaplist_bss.MemSsal->info[scenesetaplist_bss.MemSsal->apIdx].ssid);
        DWCi_SetParam_(0, 0);
        if (scenesetaplist_bss.MemSsal->info[scenesetaplist_bss.MemSsal->apIdx].wep) {
            DWCi_SetParam_(0, 1);
            DWCi_SetParam2_(1, 1);
            DWCi_ChangeScene(DWCi_SceneSetEdit32);
        } else {
            DWCi_SetParam_(0, 1);
            DWCi_SetParam2_(0, 1);
            DWCi_ChangeScene(DWCi_SceneSetTestConfirm);
        }
    }
    DWCi_HEAPlFree_((void **)&scenesetaplist_bss.MemSsal);
}

static void drawApInfo(void)
{
    int num;
    int n;
    int i;
    int idx;

    idx = FX_DivS32(scenesetaplist_bss.Pos, 28);
    num = scenesetaplist_bss.MemSsal->apNum;
    DWCi_FNTlClear(scenesetaplist_bss.MemSsal->canv, 0);
    if (num > 5)
        num = 5;
    for (i = 0, n = idx; i < num; i++, n++)
        drawAp(n, i);
    for (i = 0; i < num; i++, idx++)
        drapApObj(idx, i);
    DWCi_FNTlRenewBg((int)scenesetaplist_bss.MemSsal->canv);
    setOffset();
}

static void drawAp(int ap, int column)
{
    int len;
    int y;
    int i;
    int n;
    unsigned short buf[17];

    len = DWCi_STRlNLen((unsigned char *)scenesetaplist_bss.MemSsal->info[ap].ssid, 32);
    y = column * 28;
    if (ap >= scenesetaplist_bss.MemSsal->apNum)
        return;
    if (len <= 16)
        y += 6;
    MI_CpuFill8(buf, 0, sizeof(buf));
    if (len <= 16)
        n = len;
    else
        n = 16;
    for (i = 0; i < n; i++)
        buf[i] = scenesetaplist_bss.MemSsal->info[ap].ssid[i];
    DWCi_FNTlDrawStringEx(scenesetaplist_bss.MemSsal->canv, 10, y, 2, 10, buf, 1);
    if (len <= 16)
        return;
    MI_CpuFill8(buf, 0, sizeof(buf));
    for (i = 0; i < len - 16; i++)
        buf[i] = scenesetaplist_bss.MemSsal->info[ap].ssid[i + 16];
    DWCi_FNTlDrawStringEx(scenesetaplist_bss.MemSsal->canv, 10, y + 12, 2, 10, buf, 1);
}

static void drapApObj(int entryIndex, int objIndex)
{
    u8 *g = (u8 *)0x021DE5D8;
    u8 *p = *(u8 **)(g + 4);
    int i;
    int mask = -0x400;
    u16 *d;

    if (entryIndex >= p[0x51])
        return;

    i = entryIndex * 0x2a;

    d = *(u16 **)(p + objIndex * 4 + 0x10);
    d[2] = (d[2] & mask) | *(u16 *)(p + (*(u8 *)(*(int *)p + i + 0x28) << 1) + 0x42);

    p = *(u8 **)(g + 4);
    d = *(u16 **)(p + objIndex * 4 + 0x24);
    d[2] = (d[2] & mask) | *(u16 *)(p + (*(u16 *)(*(int *)p + i + 0x26) << 1) + 0x48);
}

static void setOffset(void)
{
    int y;
    int num;
    int i;

    y = 54 - FX_ModS32(scenesetaplist_bss.Pos, 28);
    num = scenesetaplist_bss.MemSsal->apNum;
    if (num > 5)
        num = 5;
    for (i = 0; i < num; i++, y += 28) {
        G2_SetOBJPosition(scenesetaplist_bss.MemSsal->objWep[i], 0xb3, y - 2);
        G2_SetOBJPosition(scenesetaplist_bss.MemSsal->objLevel[i], 0xd2, y + 1);
    }
    scenesetaplist_bss.MemSsal->renew = 1;
}

static void taskUp(void *task)
{
    int pos;
    int def;

    DWCi_SBlDisable();
    DWCi_FOCUSlDelete();
    if (scenesetaplist_bss.Pos > 4)
        scenesetaplist_bss.Pos -= 4;
    else
        scenesetaplist_bss.Pos = 0;
    def = FX_ModS32(scenesetaplist_bss.Pos, 28);
    if (def == 24) {
        drawApInfo();
        return;
    }
    if (def > 24) {
        scenesetaplist_bss.Pos += (unsigned short)(28 - def);
        def = 0;
    }
    setOffset();
    if (def != 0)
        return;
    pos = FX_DivS32(scenesetaplist_bss.Pos * scenesetaplist_bss.MemSsal->distBar, scenesetaplist_bss.MemSsal->distScroll);
    DWCi_SBlSet(pos);
    DWCi_SBlEnable();
    dispFocus();
    scenesetaplist_bss.MemSsal->task = 0;
    DWCi_TSKlDelete(0, task);
}

static void taskDown(void *task)
{
    int pos;
    int def;

    DWCi_SBlDisable();
    DWCi_FOCUSlDelete();
    scenesetaplist_bss.Pos += 4;
    def = FX_ModS32(scenesetaplist_bss.Pos, 28);
    if (def >= 4) {
        setOffset();
        return;
    }
    scenesetaplist_bss.Pos -= (unsigned short)def;
    drawApInfo();
    pos = FX_DivS32(scenesetaplist_bss.Pos * scenesetaplist_bss.MemSsal->distBar, scenesetaplist_bss.MemSsal->distScroll);
    DWCi_SBlSet(pos);
    DWCi_SBlEnable();
    dispFocus();
    scenesetaplist_bss.MemSsal->task = 0;
    DWCi_TSKlDelete(0, task);
}

static void taskVBlank(void)
{
    int ost;

    if (!scenesetaplist_bss.MemSsal->renew)
        return;
    ost = FX_ModS32(scenesetaplist_bss.Pos, 28) - 50;
    *(volatile unsigned long *)0x04000010 = (unsigned long)((ost << 16) & 0x01FF0000);
    *(volatile unsigned long *)0x04000018 = (unsigned long)((ost << 16) & 0x01FF0000);
    scenesetaplist_bss.MemSsal->renew = 0;
}

static void dispFocus(void)
{
    int kind;

    kind = scenesetaplist_bss.Focus < 4 ? 2 : 3;
    DWCi_FOCUSlDisp(kind, scenesetaplist_rodata.R_FOCUS[scenesetaplist_bss.Focus].l, scenesetaplist_rodata.R_FOCUS[scenesetaplist_bss.Focus].r, scenesetaplist_rodata.R_FOCUS[scenesetaplist_bss.Focus].t);
}

static void moveFocus(int dir)
{
    bool move = 1;

    switch (scenesetaplist_bss.Focus) {
    case 0:
        if (dir == 1) {
            if (scenesetaplist_bss.Pos == 0) {
                scenesetaplist_bss.Focus = 4;
            } else {
                DWCi_SNDlPlay(0x13);
                scenesetaplist_bss.MemSsal->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskUp, 0, 0x78);
                return;
            }
        } else if (scenesetaplist_bss.MemSsal->apNum > 1) {
            scenesetaplist_bss.Focus++;
        } else {
            move = 0;
        }
        break;
    case 1:
    case 2:
        if (dir == 1)
            scenesetaplist_bss.Focus--;
        else if (scenesetaplist_bss.MemSsal->apNum > scenesetaplist_bss.Focus + 1)
            scenesetaplist_bss.Focus++;
        else
            move = 0;
        break;
    case 3:
        if (dir == 1) {
            scenesetaplist_bss.Focus--;
        } else {
            scrollDown();
            return;
        }
        break;
    case 4:
        if (dir == 1) {
            move = 0;
        } else {
            scenesetaplist_bss.Pos = 0;
            scenesetaplist_bss.Focus = 0;
            drawApInfo();
            DWCi_SBlSet(0);
        }
        break;
    }
    if (!move) {
        if (!scenesetaplist_bss.MemSsal->sound[1]) {
            DWCi_SNDlPlay(9);
            scenesetaplist_bss.MemSsal->sound[1] = 1;
        }
        return;
    }
    DWCi_SNDlPlay(8);
    dispFocus();
}

static void scrollUp(void)
{
    if (scenesetaplist_bss.Pos == 0) {
        if (!scenesetaplist_bss.MemSsal->sound[1]) {
            DWCi_SNDlPlay(9);
            scenesetaplist_bss.MemSsal->sound[1] = 1;
        }
    } else {
        DWCi_SNDlPlay(0x13);
        scenesetaplist_bss.MemSsal->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskUp, 0, 0x78);
    }
}

static void scrollDown(void)
{
    u8 *p = gSceneSetApListWork.MemSsal;

    if (gSceneSetApListWork.Pos == *(u16 *)(p + 0x40) || p[0x51] <= 4) {
        if (p[0x59] == 0) {
            DWCi_SNDlPlay(9);
            ((u8 *)gSceneSetApListWork.MemSsal)[0x59] = 1;
        }
        return;
    }
    DWCi_SNDlPlay(0x13);
    *(void **)(((u8 *)gSceneSetApListWork.MemSsal) + 0x38) = DWCi_TSKlForm(0, (void (*)(void *, void *))taskDown, 0, 0x78);
}

static void dispPushButton(void)
{
    unsigned char PALETTE[1];

    *(SSAL_N1 *)PALETTE = scenesetaplist_str_20957;
    DWCi_SCREENlCopyPalette(scenesetaplist_bss.MemSsal->pltt, PALETTE[0], PALETTE[0]);
}

static void procError(void)
{
    if (DWCi_WINlGet() != 0)
        return;
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_ChangeScene(procError1);
}

static void procError1(void)
{
    if (DWCi_WINlIsInit())
        return;
    DWCi_BTNlEnable();
    DWCi_SBlEnable();
    DWCi_ChangeScene(DWCi_SceneSetApList_procScene);
}

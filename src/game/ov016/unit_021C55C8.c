/*
 * file:     unit_021C55C8.c
 * unit:     yes
 * function: func_021C55C8, func_021C57E4, func_021C5A10, func_021C5B24, func_021C5B44, func_021C5BBC, func_021C5D9C, func_021C5E40, func_021C5FA8, func_021C6034, func_021C60EC, func_021C61A4, func_021C6234, func_021C628C, func_021C62D8, func_021C641C, func_021C6488, func_021C6508, func_021C6534, func_021C6560
 * address:  0x021C55C8
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
 *   DWCi_BTNlSet                     0x021BCB28  arm
 *   DWCi_IPTlCheckRelease            0x021D68A4  arm
 *   DWCi_IPTlCheckRepeat             0x021D6864  arm
 *   DWCi_IPTlCheckTrigger            0x021D6824  arm
 *   DWCi_R_SCR                       0x021DAA7C  data
 *   DWCi_SBlDisable                  0x021CE9D0  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_TPlCheckRelease             0x021D6A7C  arm
 *   DWCi_TPlCheckTrigger             0x021D696C  arm
 *   scenesetaplist_bss               0x021DE5D8  data
 *   scenesetaplist_rodata            0x021DA51C  data
 *   scrollDown                       0x021C6488  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_FOCUSlDelete                0x021BD5A8  arm
 *   DWCi_SBlGet                      0x021CE984  arm
 *   DWCi_SBlGetState                 0x021CE998  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   FX_DivS32                        0x0207C958  arm
 *   FX_ModS32                        0x0207C994  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
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
 *   func_021CFFAC   0x021CFFAC   arm
 *   func_021D7680   0x021D7680   arm
 *   func_021C61A4   0x021C61A4   arm
 *   g_021DE5D8      0x021DE5D8   data
 *   DWCi_SCREENlCopyPalette          0x021CE7B0  arm
 *   scenesetaplist_str_20957         0x021DA518  data
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   procScene                        0x021C55B4  arm
 */
#include "../../matched/include/G_SCENESETAPLIST_BSS.h"

typedef _Bool bool;

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;

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

typedef struct NCFGApInfo {
    unsigned char  ispId[32];         /* 0x00 */
    unsigned char  ispPass[32];       /* 0x20 */
    unsigned char  ssid[2][32];       /* 0x40 */
    unsigned char  wep[4][16];        /* 0x80 */
    unsigned char  ip[4];             /* 0xC0 */
    unsigned char  gateway[4];        /* 0xC4 */
    unsigned char  dns[2][4];         /* 0xC8 */
    unsigned char  netmask;           /* 0xD0 */
    unsigned char  wep2[4][5];        /* 0xD1 */
    unsigned char  authType;          /* 0xE5 */
    unsigned char  wepMode : 2;       /* 0xE6 */
    unsigned char  wepNotation : 6;   /* 0xE6 */
    unsigned char  setType;           /* 0xE7 */
    unsigned char  ssidLength[2];     /* 0xE8 */
    unsigned short mtu;               /* 0xEA */
    unsigned char  rsv[2];            /* 0xEC */
    unsigned char  flags;             /* 0xEE */
    unsigned char  state;             /* 0xEF */
} NCFGApInfo;

typedef struct tagSETTINGINFO {
    NCFGApInfo     ap;                /* 0x00 */
    unsigned char  netmask[4];        /* 0xF0 */
    unsigned char  idx;               /* 0xF4 */
    bool           ipAuto;            /* 0xF5 */
    bool           dnsAuto;           /* 0xF6 */
} SETTINGINFO;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { unsigned char v[1]; } SSAL_N1;

extern void DWCi_ARClRelease(void *file);
extern void DWCi_BTNlDisable(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_BTNlEnd(void);
extern int DWCi_BTNlGet(void);
extern bool DWCi_BTNlIsEnd(void);
extern void DWCi_BTNlSet(int idx);
extern void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);
extern GXOamAttr *DWCi_CEINlSetExObj(int lcd, int idx);
extern void DWCi_CMNlStep(int step);
extern bool DWCi_COMMENTlDelete(void);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_ChangeScene(void (*scene)());
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_FNTlClear(void *canvas, int color);
extern void DWCi_FNTlDeleteBg(void *canvas);
extern void DWCi_FNTlDrawStringEx(void *canvas, int x, int y, int color, int interval, unsigned short *txt, int font);
extern void *DWCi_FNTlFormBgEx(int lcd, int font);
extern void DWCi_FNTlRenewBg(void *canvas);
extern void DWCi_FOCUSlDelete(void);
extern void DWCi_FOCUSlDisp(int kind, int x0, int x1, int y);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_GetParam2_(void **param2, void **param3);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_HEAPlFree_(void **mem);
extern void DWCi_HLlLoadSet(void);
extern bool DWCi_IPTlCheckRelease(unsigned short input);
extern bool DWCi_IPTlCheckRepeat(unsigned short input);
extern bool DWCi_IPTlCheckTrigger(unsigned short input);
extern void DWCi_OBJlDelete(GXOamAttr *obj);
extern void DWCi_SBlDisable(void);
extern void DWCi_SBlEnable(void);
extern void DWCi_SBlEnd(void);
extern int DWCi_SBlGet(void);
extern int DWCi_SBlGetState(void);
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
extern int DWCi_STRlNLen(char *s, int maxlen);
extern void DWCi_SetParam2_(void *param2, void *param3);
extern void DWCi_SetParam_(void *param0, void *param1);
extern bool DWCi_TPlCheckRelease(RECT *r);
extern bool DWCi_TPlCheckTrigger(RECT *r);
extern void DWCi_TSKlDelete(int kind, void *task);
extern void DWCi_TSKlDeleteEx(int kind, void *task);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void DWCi_WINlEnd(void);
extern int DWCi_WINlGet(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern bool DWCi_WINlIsInit(void);
extern long FX_DivS32(long a, long b);
extern long FX_ModS32(long a, long b);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void DWCi_SceneSetEdit32(void);
extern void DWCi_SceneSetSearch(void);
extern void DWCi_SceneSetSelectWay(void);
extern void DWCi_SceneSetTestConfirm(void);
extern void func_021CFFAC(unsigned int v);
extern void *func_021D7680(int a, void *b, int c, int d);
extern void  func_021C61A4(void);
void func_021C5FA8(int a0, int a1);
void func_021C6488(void);
extern SCENESETAPLIST_BSS scenesetaplist_bss;
extern const SCENESETAPLIST_RODATA scenesetaplist_rodata;
extern RECT DWCi_R_SCR;
extern struct SCENESETAPLIST_BSS g_021DE5D8;
extern const SSAL_N1 scenesetaplist_str_20957;


static void dispFocus(void);

static void dispPushButton(void);

static void drapApObj(int ap, int column);

static void drawAp(int ap, int column);

static void drawApInfo(void);

static void endScene(void);

static void endScene1(void);

static void endScene2(void);

static void getCharName(void);

static void initGraphics(void);

static void initScrollBar(void);

static void moveFocus(int dir);

static void procError(void);

static void procError1(void);

static void procInit(void);

static void procInit1(void);

static void procScene(void);

static void scrollDown(void);

static void scrollUp(void);

static void setOffset(void);

static void taskDown(void *task);

static void taskUp(void *task);

static void taskVBlank(void);


static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y)
{
    oam->attr01 = (oam->attr01 & 0xFE00FF00) | (y & 0xFF) | ((x & 0x1FF) << 16);
}


static inline void G2_SetOBJPriority(GXOamAttr *oam, int priority)
{
    oam->attr2 = (unsigned short)((oam->attr2 & ~0xC00) | (priority << 10));
}


static void input(void)
{
    int i;

    if (scenesetaplist_bss.MemSsal->task != 0 || scenesetaplist_bss.MemSsal->scroll)
        return;
    if (DWCi_TPlCheckTrigger(&DWCi_R_SCR)) {
        scenesetaplist_bss.MemSsal->push = -1;
        for (i = 0; i < sizeof(scenesetaplist_rodata.R_TOUCH) / sizeof(RECT); i++) {
            if (DWCi_TPlCheckTrigger((RECT *)&scenesetaplist_rodata.R_TOUCH[i])) {
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
    if (DWCi_TPlCheckRelease(&DWCi_R_SCR)) {
        for (i = 0; i < 4; i++) {
            if (DWCi_TPlCheckRelease((RECT *)&scenesetaplist_rodata.R_TOUCH[i])) {
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
            DWCi_OBJlDelete(scenesetaplist_bss.MemSsal->objWep[i]);
        if (scenesetaplist_bss.MemSsal->objLevel[i])
            DWCi_OBJlDelete(scenesetaplist_bss.MemSsal->objLevel[i]);
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
        DWCi_SetParam_((void *)2, 0);
        DWCi_ChangeScene(DWCi_SceneSetSelectWay);
    } else if (scenesetaplist_bss.Focus == 4) {
        DWCi_SEARCHlEnd();
        DWCi_SetParam_(0, (void *)1);
        DWCi_ChangeScene(DWCi_SceneSetSearch);
    } else {
        DWCi_SETTINGlSetSsid((char *)scenesetaplist_bss.MemSsal->info[scenesetaplist_bss.MemSsal->apIdx].ssid);
        DWCi_SetParam_(0, 0);
        if (scenesetaplist_bss.MemSsal->info[scenesetaplist_bss.MemSsal->apIdx].wep) {
            DWCi_SetParam_(0, (void *)1);
            DWCi_SetParam2_((void *)1, (void *)1);
            DWCi_ChangeScene(DWCi_SceneSetEdit32);
        } else {
            DWCi_SetParam_(0, (void *)1);
            DWCi_SetParam2_(0, (void *)1);
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
    DWCi_FNTlRenewBg(scenesetaplist_bss.MemSsal->canv);
    setOffset();
}


static void drawAp(int ap, int column)
{
    int len;
    int y;
    int i;
    int n;
    unsigned short buf[17];

    len = DWCi_STRlNLen((char *)scenesetaplist_bss.MemSsal->info[ap].ssid, 32);
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


void func_021C5FA8(int a0, int a1)
{
    u8 *g = (u8 *)0x021DE5D8;
    u8 *p = *(u8 **)(g + 4);
    int i;
    int mask = -0x400;
    u16 *d;

    if (a0 >= p[0x51])
        return;

    i = a0 * 0x2a;

    d = *(u16 **)(p + a1 * 4 + 0x10);
    d[2] = (d[2] & mask) | *(u16 *)(p + (*(u8 *)(*(int *)p + i + 0x28) << 1) + 0x42);

    p = *(u8 **)(g + 4);
    d = *(u16 **)(p + a1 * 4 + 0x24);
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


void func_021C6488(void)
{
    u8 *p = g_021DE5D8.MemSsal;

    if (g_021DE5D8.Pos == *(u16 *)(p + 0x40) || p[0x51] <= 4) {
        if (p[0x59] == 0) {
            func_021CFFAC(9);
            ((u8 *)g_021DE5D8.MemSsal)[0x59] = 1;
        }
        return;
    }
    func_021CFFAC(0x13);
    *(void **)(((u8 *)g_021DE5D8.MemSsal) + 0x38) = func_021D7680(0, func_021C61A4, 0, 0x78);
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
    DWCi_ChangeScene(procScene);
}

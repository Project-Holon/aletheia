/*
 * file:     unit_021C87A4.c
 * unit:     yes
 * function: func_021C87A4, func_021C89E8, func_021C8A6C, func_021C8BE4, func_021C8C50, func_021C8C88, func_021C8EA8, func_021C8EC8, func_021C8F20, func_021C91F4, func_021C92B0, func_021C9450, func_021C9584, func_021C9610, func_021C9700, func_021C984C, func_021C98E4, func_021C9A94, func_021C9D10, func_021C9D54, func_021C9D78, func_021C9E3C, func_021C9ED8, func_021C9F58, func_021CA030, func_021CA0D4, func_021CA100, func_021CA390, func_021CA3C4, func_021CA418, func_021CA4C0, func_021CA560
 * address:  0x021C87A4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_IPTlCheckRelease            0x021D68A4  arm
 *   DWCi_IPTlCheckRepeat             0x021D6864  arm
 *   DWCi_IPTlCheckTrigger            0x021D6824  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   scenesetlist_bss                 0x021DE5EC  data
 *   DWCi_SETTIGNlGet                 0x021CF404  arm
 *   applyForcus1                     0x021CA0D4  arm
 *   DWCi_SBlDisable                  0x021CE9D0  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   calcColumnIdx                    0x021C9D10  arm
 *   dispPushButton                   0x021CA390  arm
 *   procError                        0x021CA560  arm
 *   scenesetlist_rodata              0x021DA61C  data
 *   DWCi_SETTINGlSetDnsAuto          0x021CF42C  arm
 *   DWCi_SETTINGlSetIpAuto           0x021CF418  arm
 *   DWCi_FOCUSlDelete                0x021BD5A8  arm
 *   DWCi_SBlGet                      0x021CE984  arm
 *   DWCi_SBlGetState                 0x021CE998  arm
 *   FX_ModS32                        0x0207C994  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_ARClRelease                 0x021D4C68  arm
 *   DWCi_BACKUPlConvMaskCidr         0x020587F8  arm
 *   DWCi_CMNlLoadResource            0x021BD1D4  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_HEAPlFree_                  0x021D6438  arm
 *   DWCi_OBJlDelete                  0x021D6F38  arm
 *   DWCi_SBlEnd                      0x021CE94C  arm
 *   DWCi_SCREENlEnd                  0x021CE6C4  arm
 *   DWCi_SETTINGlSetSetting          0x021CF80C  arm
 *   DWCi_SceneSetEdit32              0x021C6588  arm
 *   DWCi_SceneSetEditAddress         0x021C7088  arm
 *   DWCi_SceneSetListSave            0x021CA5D0  arm
 *   DWCi_SceneSetSelectAp            0x021CBC90  arm
 *   DWCi_SceneSetSelectWay           0x021CC998  arm
 *   DWCi_SceneSetTest                0x021CD160  arm
 *   DWCi_SetParam2_                  0x021C0E8C  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   DWCi_TSKlDeleteEx                0x021D7744  arm
 *   GX_LoadOBJPltt                   0x0207E51C  arm
 *   MI_CpuFill8                      0x02082BCC  arm
 *   scenesetlist_str_21900           0x021DB5D8  data
 *   DWCi_FNTlClear                   0x021D5F14  arm
 *   DWCi_FNTlRenewBg                 0x021D5FC4  arm
 *   DWCi_SCREENlCopy                 0x021CE708  arm
 *   DWCi_SCREENlRenew                0x021CE6F0  arm
 *   FX_DivS32                        0x0207C958  arm
 *   memset                           0x020923B0  arm
 *   DWCi_CEINlSet                    0x021D52D4  arm
 *   calcIdxColumn                    0x021C9D54  arm
 *   DWCi_FNTlDrawStringEx            0x021D5DB0  arm
 *   DWCi_STRlNLen                    0x021D7200  arm
 *   DWCi_STRlConvertStringAsciiToUnicode 0x021D722C  arm
 *   OS_SNPrintf                      0x02084F80  arm
 *   scenesetlist_str_22070           0x021DB5F0  data
 *   DWCi_R_SCR                       0x021DAA7C  data
 *   DWCi_TPlCheckATrigger            0x021D6B04  arm
 *   DWCi_TPlCheckTrigger             0x021D696C  arm
 *   Focus                            0x021DE5EC  data
 *   RetScene                         0x021DE5ED  data
 *   FocusClm                         0x021DE5EE  data
 *   Pos                              0x021DE5F0  data
 *   MemSsl                           0x021DE5F4  data
 *   PALETTE_NUM                      0x021DA61C  data
 *   MSG_IDX                          0x021DA61F  data
 *   A_EDIT                           0x021DA626  data
 *   A_NO                             0x021DA62E  data
 *   A_YES                            0x021DA636  data
 *   CLM2FCS_TBL                      0x021DA63E  data
 *   OFS_BACK                         0x021DA647  data
 *   FCS2CLM_TBL                      0x021DA650  data
 *   CELL_IDX                         0x021DA65B  data
 *   BACK_POS                         0x021DA66A  data
 *   R_BUTTON                         0x021DA67C  data
 *   R_FOCUS                          0x021DA694  data
 *   func_0207C958   0x0207C958  arm
 *   DWCi_SBlEnable                   0x021CE9B8  arm
 *   DWCi_SBlSet                      0x021CE9AC  arm
 *   DWCi_TSKlDelete                  0x021D7724  arm
 *   DWCi_FOCUSlDisp                  0x021BD41C  arm
 *   scenesetlist_init_21137          0x021DA6C8  data
 *   tbl_021DA650   0x021DA650  data
 *   func_021C9F58   0x021C9F58  arm
 *   tbl_021DA61C   0x021DA61C  data
 *   func_021CE7B0   0x021CE7B0  arm
 *   scenesetlist_init_21261          0x021DA6C4  data
 *   DWC_BACKUPlCheckAddress          0x020588D0  arm
 *   DWC_BACKUPlCheckIp               0x02058868  arm
 *   func_021D1568   0x021D1568  arm
 *   func_021CFFAC   0x021CFFAC  arm
 *   func_021D1524   0x021D1524  arm
 *   func_021CE818   0x021CE818  arm
 *   func_021C0E40   0x021C0E40  arm
 */
#include "../../matched/include/G_SCENESETLIST_BSS.h"

typedef _Bool bool;

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

typedef struct tagAREA { unsigned short l, t, w, h; } AREA;

typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;

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

/* TYEP's initialiser is the compiler's @21137 in its own .rodata section */
typedef struct { unsigned char v[14]; } TYEP_INIT;

/* FCS's initialiser { 2, 3, 7, 8 } is the compiler's @21261 in its own .rodata section */
typedef struct { unsigned char v[4]; } FCS_INIT;

extern bool DWCi_IPTlCheckTrigger(unsigned short input);
extern bool DWCi_IPTlCheckRepeat(unsigned short input);
extern bool DWCi_IPTlCheckRelease(unsigned short input);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_ChangeScene(void (*scene)());
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern SETTINGINFO *DWCi_SETTIGNlGet(void);
extern void applyForcus1(int focus);
extern void dispPushButton(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern void procError(void);
extern int calcColumnIdx(int clm);
extern void DWCi_SBlDisable(void);
extern void DWCi_SETTINGlSetIpAuto(bool yes);
extern void DWCi_SETTINGlSetDnsAuto(bool yes);
extern int DWCi_SBlGetState(void);
extern int DWCi_SBlGet(void);
extern void DWCi_FOCUSlDelete(void);
extern long FX_ModS32(long a, long b);
extern bool DWCi_EFFlWait(int frame);
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_TSKlDeleteEx(int kind, void *task);
extern void DWCi_OBJlDelete(GXOamAttr *obj);
extern void DWCi_SBlEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_SCREENlEnd(void);
extern void DWCi_ARClRelease(void *file);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam2_(void *param2, void *param3);
extern void DWCi_SetParam_(void *param0, void *param1);
extern unsigned char DWCi_BACKUPlConvMaskCidr(unsigned char *mask);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void DWCi_SETTINGlSetSetting(int idx);
extern void DWCi_HEAPlFree_(void **mem);
extern void GX_LoadOBJPltt(void *src, unsigned long offset, unsigned long size);
extern void DWCi_SceneSetEdit32(void);
extern void DWCi_SceneSetEditAddress(void);
extern void DWCi_SceneSetTest(void);
extern void DWCi_SceneSetListSave(void);
extern void DWCi_SceneSetSelectAp(void);
extern void DWCi_SceneSetSelectWay(void);
extern long FX_DivS32(long a, long b);
extern void DWCi_FNTlClear(void *canvas, int color);
extern void DWCi_FNTlRenewBg(void *canvas);
extern void DWCi_SCREENlCopy(void *src, int pos, int w, int h);
extern void DWCi_SCREENlRenew(void);
extern void *memset(void *dst, int c, unsigned long n);
extern int calcIdxColumn(int idx);
extern void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);
extern int DWCi_STRlNLen(char *s, int maxlen);
extern void DWCi_FNTlDrawStringEx(void *canvas, int x, int y, int color, int interval, unsigned short *txt, int font);
extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);
extern int DWCi_STRlConvertStringAsciiToUnicode(unsigned short *dst, char *src, int len);
extern unsigned char DWCi_TPlCheckTrigger(RECT *r);
extern unsigned char DWCi_TPlCheckATrigger(AREA *a);
extern int func_0207C958(int, int);
extern void DWCi_SBlEnable(void);
extern void DWCi_SBlSet(int pos);
extern void DWCi_TSKlDelete(int kind, void *task);
extern void DWCi_FOCUSlDisp(int kind, int x0, int x1, int y);
extern void func_021C9F58(void);
extern void func_021CE7B0(void *src, int sColor, int dColor);
extern int DWC_BACKUPlCheckAddress(unsigned char *address);
extern int DWC_BACKUPlCheckIp(unsigned char *ip, unsigned char *mask);
extern signed char func_021D1568(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021D1524(void);
extern void func_021CE818(unsigned int v);
extern void func_021C0E40(unsigned int v);
void input(void);
bool inputWinButton(void);
void pushWinButton(int focus);
void pushIpAuto(bool yes);
void pushDnsAuto(bool yes);
void draw(void);
void endScene(void);
void endScene1(void);
void endScene2(void);
void drawWindow(void);
void drawColumnChar(int column, int idx);
void drawColumnObj(int column, int idx);
bool isEnablePush(int area);
void dispObj(int kind, int st, int idx);
void drawString(unsigned char *txt, int idx);
void drawAddress(const unsigned char *addr, int idx);
void setOffset(void);
int isPush(void);
int func_021C9D10(int a);
int func_021C9D54(int a);
void taskUp(void *task);
void taskDown(void *task);
void taskVBlank(void);
void dispFocus(void);
void applyForcus(void);
void func_021CA0D4(int a);
void moveFocus(int dir);
void func_021CA390(void);
void taskPushCount(void);
void pushButtonYesNo(void);
bool isCorrect(void);
void func_021CA560(void);
extern struct SCENESETLIST_BSS scenesetlist_bss;
extern const SCENESETLIST_RODATA scenesetlist_rodata;
extern char scenesetlist_str_21900[];
extern char scenesetlist_str_22070[];
extern RECT DWCi_R_SCR;
extern const TYEP_INIT scenesetlist_init_21137;
extern unsigned char tbl_021DA650[];
extern unsigned char tbl_021DA61C[];
extern const FCS_INIT scenesetlist_init_21261;



void input(void)
{
    if (((MEMSSL *)scenesetlist_bss.MemSsl)->task != 0 || ((MEMSSL *)scenesetlist_bss.MemSsl)->scroll != 0)
        return;
    if (inputWinButton())
        return;
    if (DWCi_IPTlCheckTrigger(1)) {
        pushWinButton(scenesetlist_bss.Focus);
    } else if (DWCi_IPTlCheckTrigger(2)) {
        DWCi_SNDlPlay(7);
        ((MEMSSL *)scenesetlist_bss.MemSsl)->choose = 13;
        DWCi_ChangeScene(endScene);
    } else if (DWCi_IPTlCheckRepeat(0x200)) {
        if (scenesetlist_bss.Pos == 145) {
            if (!((MEMSSL *)scenesetlist_bss.MemSsl)->sound[1]) {
                DWCi_SNDlPlay(9);
                ((MEMSSL *)scenesetlist_bss.MemSsl)->sound[1] = 1;
            }
        } else {
            DWCi_SNDlPlay(0x13);
            ((MEMSSL *)scenesetlist_bss.MemSsl)->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskDown, 0, 0x78);
        }
    } else if (DWCi_IPTlCheckRelease(0x200)) {
        ((MEMSSL *)scenesetlist_bss.MemSsl)->sound[1] = 0;
    } else if (DWCi_IPTlCheckRepeat(0x100)) {
        if (scenesetlist_bss.Pos == 0) {
            if (!((MEMSSL *)scenesetlist_bss.MemSsl)->sound[1]) {
                DWCi_SNDlPlay(9);
                ((MEMSSL *)scenesetlist_bss.MemSsl)->sound[1] = 1;
            }
        } else {
            DWCi_SNDlPlay(0x13);
            ((MEMSSL *)scenesetlist_bss.MemSsl)->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskUp, 0, 0x78);
        }
    } else if (DWCi_IPTlCheckRelease(0x100)) {
        ((MEMSSL *)scenesetlist_bss.MemSsl)->sound[1] = 0;
    } else if (DWCi_IPTlCheckRepeat(0x40)) {
        moveFocus(1);
    } else if (DWCi_IPTlCheckRelease(0x40)) {
        ((MEMSSL *)scenesetlist_bss.MemSsl)->sound[1] = 0;
    } else if (DWCi_IPTlCheckRepeat(0x80)) {
        moveFocus(3);
    } else if (DWCi_IPTlCheckRelease(0x80)) {
        ((MEMSSL *)scenesetlist_bss.MemSsl)->sound[1] = 0;
    } else if (DWCi_IPTlCheckRepeat(0x20)) {
        moveFocus(0);
    } else if (DWCi_IPTlCheckRepeat(0x10)) {
        moveFocus(2);
    }
}



bool inputWinButton(void)
{
    int area;

    DWCi_SETTIGNlGet();
    area = isPush();
    if (area == 14)
        return 0;
    if (!isEnablePush(area)) {
        DWCi_SNDlPlay(9);
        return 1;
    }
    applyForcus1(area);
    switch (area) {
    case 0:
    case 1:
    case 4:
    case 5:
    case 6:
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        pushButtonYesNo();
        break;
    }
    pushWinButton(area);
    return 1;
}



void pushWinButton(int focus)
{
    if (!isEnablePush(focus)) {
        DWCi_SNDlPlay(9);
        return;
    }
    switch (focus) {
    case 2:
    case 3:
        DWCi_SNDlPlay(6);
        pushIpAuto(((focus - 2) ^ 1) != 0);
        return;
    case 7:
    case 8:
        DWCi_SNDlPlay(6);
        pushDnsAuto(((focus - 7) ^ 1) != 0);
        return;
    }
    ((MEMSSL *)scenesetlist_bss.MemSsl)->choose = focus;
    if (focus == 11 || focus == 12) {
        dispPushButton();
        if (!isCorrect()) {
            DWCi_SNDlPlay(9);
            DWCi_WINlInitEx(6, 1, 1, -1, 0);
            DWCi_ChangeScene(procError);
            return;
        }
        if (focus == 11)
            DWCi_SNDlPlay(6);
        else
            DWCi_SNDlPlay(14);
    } else if (focus == 13) {
        dispPushButton();
        DWCi_SNDlPlay(7);
    } else {
        DWCi_SNDlPlay(6);
        dispObj(0, 1, calcColumnIdx(scenesetlist_rodata.FCS2CLM_TBL[focus]));
        setOffset();
    }
    DWCi_SBlDisable();
    DWCi_ChangeScene(endScene);
}



void pushIpAuto(bool yes)
{
    SETTINGINFO *info = DWCi_SETTIGNlGet();
    bool dns;

    if (info->ipAuto == yes)
        return;
    if (yes) {
        dns = 1;
        if (((MEMSSL *)scenesetlist_bss.MemSsl)->lastDns == 0)
            dns = 0;
    } else {
        ((MEMSSL *)scenesetlist_bss.MemSsl)->lastDns = info->dnsAuto;
        dns = 0;
    }
    DWCi_SETTINGlSetIpAuto(yes);
    DWCi_SETTINGlSetDnsAuto(dns);
    drawWindow();
}



void pushDnsAuto(bool yes)
{
    SETTINGINFO *info = DWCi_SETTIGNlGet();

    if (info->dnsAuto == yes)
        return;
    ((MEMSSL *)scenesetlist_bss.MemSsl)->lastDns = yes;
    DWCi_SETTINGlSetDnsAuto(yes);
    drawWindow();
}



void draw(void)
{
    int def;

    if (((MEMSSL *)scenesetlist_bss.MemSsl)->task)
        return;
    if (((MEMSSL *)scenesetlist_bss.MemSsl)->disp)
        ((MEMSSL *)scenesetlist_bss.MemSsl)->disp--;
    switch (DWCi_SBlGetState()) {
    case 0:
        break;
    case 1:
        ((MEMSSL *)scenesetlist_bss.MemSsl)->scroll = 1;
        break;
    case 2:
        if (((MEMSSL *)scenesetlist_bss.MemSsl)->disp)
            break;
        DWCi_FOCUSlDelete();
        scenesetlist_bss.Pos = DWCi_SBlGet() * 145 / 55;
        drawWindow();
        ((MEMSSL *)scenesetlist_bss.MemSsl)->disp = 4;
        break;
    case 3:
        ((MEMSSL *)scenesetlist_bss.MemSsl)->scroll = 0;
        scenesetlist_bss.Pos = DWCi_SBlGet() * 145 / 55;
        DWCi_SNDlPlay(0x13);
        drawWindow();
        def = FX_ModS32(scenesetlist_bss.Pos, 29);
        if (def == 0)
            applyForcus();
        else if (def < 16)
            ((MEMSSL *)scenesetlist_bss.MemSsl)->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskUp, 0, 0x78);
        else
            ((MEMSSL *)scenesetlist_bss.MemSsl)->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskDown, 0, 0x78);
        break;
    case 4:
        if (scenesetlist_bss.Pos == 0) {
            if (!((MEMSSL *)scenesetlist_bss.MemSsl)->sound[0]) {
                DWCi_SNDlPlay(9);
                ((MEMSSL *)scenesetlist_bss.MemSsl)->sound[0] = 1;
            }
        } else {
            DWCi_SNDlPlay(0x13);
            ((MEMSSL *)scenesetlist_bss.MemSsl)->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskUp, 0, 0x78);
        }
        break;
    case 6:
        if (scenesetlist_bss.Pos == 145) {
            if (!((MEMSSL *)scenesetlist_bss.MemSsl)->sound[0]) {
                DWCi_SNDlPlay(9);
                ((MEMSSL *)scenesetlist_bss.MemSsl)->sound[0] = 1;
            }
        } else {
            DWCi_SNDlPlay(0x13);
            ((MEMSSL *)scenesetlist_bss.MemSsl)->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskDown, 0, 0x78);
        }
        break;
    case 5:
    case 7:
        ((MEMSSL *)scenesetlist_bss.MemSsl)->sound[0] = 0;
        break;
    }
}



void endScene(void)
{
    DWCi_SBlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}



void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x1D, 8);
    DWCi_ChangeScene(endScene2);
}



void endScene2(void)
{
    SETTINGINFO *info;
    int ix;
    int i;

    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_TSKlDeleteEx(0, ((MEMSSL *)scenesetlist_bss.MemSsl)->push.task);
    DWCi_TSKlDeleteEx(1, ((MEMSSL *)scenesetlist_bss.MemSsl)->taskV);
    for (i = 0; i < 7; i++)
        DWCi_OBJlDelete(((MEMSSL *)scenesetlist_bss.MemSsl)->obj[i]);
    if (((MEMSSL *)scenesetlist_bss.MemSsl)->icon)
        DWCi_OBJlDelete(((MEMSSL *)scenesetlist_bss.MemSsl)->icon);
    DWCi_SBlEnd();
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_FOCUSlDelete();
    if (((MEMSSL *)scenesetlist_bss.MemSsl)->choose != 12)
        DWCi_COMMENTlDelete();
    DWCi_SCREENlEnd();
    DWCi_ARClRelease(((MEMSSL *)scenesetlist_bss.MemSsl)->back);
    for (i = 0; i < 2; i++)
        DWCi_ARClRelease(((MEMSSL *)scenesetlist_bss.MemSsl)->pltt[i]);
    DWCi_CMNlLoadResource(scenesetlist_str_21900, GX_LoadOBJPltt);
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x1D);
    *(volatile unsigned long *)0x04000010 = 0;
    *(volatile unsigned long *)0x04000018 = 0;
    *(volatile unsigned short *)0x0400000C = (unsigned short)((*(volatile unsigned short *)0x0400000C & 0x43) | 0xE10);
    switch (((MEMSSL *)scenesetlist_bss.MemSsl)->choose) {
    case 0:
    case 1:
        DWCi_SetParam2_((void *)((MEMSSL *)scenesetlist_bss.MemSsl)->choose, 0);
        DWCi_SetParam_((void *)2, 0);
        DWCi_ChangeScene(DWCi_SceneSetEdit32);
        break;
    case 4:
    case 5:
    case 6:
    case 9:
    case 10:
        ix = ((MEMSSL *)scenesetlist_bss.MemSsl)->choose - 4;
        if (((MEMSSL *)scenesetlist_bss.MemSsl)->choose >= 9)
            ix -= 2;
        DWCi_SetParam_((void *)2, 0);
        DWCi_SetParam2_((void *)ix, 0);
        DWCi_ChangeScene(DWCi_SceneSetEditAddress);
        break;
    case 11:
        info = DWCi_SETTIGNlGet();
        info->ap.netmask = DWCi_BACKUPlConvMaskCidr(info->netmask);
        if (info->ipAuto) {
            MI_CpuFill8(info->ap.ip, 0, 4);
            MI_CpuFill8(info->ap.gateway, 0, 4);
            MI_CpuFill8(info->netmask, 0, 4);
            info->ap.netmask = 0;
        }
        if (info->dnsAuto)
            MI_CpuFill8(info->ap.dns, 0, 8);
        DWCi_SetParam_((void *)2, 0);
        DWCi_SetParam2_(0, 0);
        DWCi_ChangeScene(DWCi_SceneSetTest);
        break;
    case 12:
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene(DWCi_SceneSetListSave);
        break;
    case 13:
        if (scenesetlist_bss.RetScene == 0) {
            DWCi_SetParam_((void *)2, (void *)1);
            DWCi_ChangeScene(DWCi_SceneSetSelectAp);
        } else {
            DWCi_SETTINGlSetSetting(DWCi_SETTIGNlGet()->idx);
            DWCi_SetParam_(0, (void *)1);
            DWCi_ChangeScene(DWCi_SceneSetSelectWay);
        }
        break;
    }
    DWCi_HEAPlFree_((void **)&scenesetlist_bss.MemSsl);
}



void drawWindow(void)
{
    int cell;
    int idx;
    int i;

    cell = FX_DivS32(scenesetlist_bss.Pos, 29);
    DWCi_FNTlClear(((MEMSSL *)scenesetlist_bss.MemSsl)->canv, 0);
    for (i = 0, idx = cell; i < 5; i++, idx++)
        drawColumnChar(idx, i);
    DWCi_SCREENlCopy((unsigned short *)((MEMSSL *)scenesetlist_bss.MemSsl)->back + scenesetlist_rodata.BACK_POS[cell], 0, 30, 19);
    for (idx = 0; idx < 5; idx++, cell++)
        drawColumnObj(cell, idx);
    DWCi_SCREENlRenew();
    DWCi_FNTlRenewBg(((MEMSSL *)scenesetlist_bss.MemSsl)->canv);
    setOffset();
}



void drawColumnChar(int column, int idx)
{
    SETTINGINFO *info;
    int len;
    unsigned char buf[33];

    info = DWCi_SETTIGNlGet();
    switch (column) {
    case 0:
        drawString(info->ap.ssid[0], idx);
        break;
    case 1:
        switch (info->ap.wepMode) {
        case 0:
            return;
        case 1:
            len = 10;
            break;
        case 2:
            len = 26;
            break;
        case 3:
            len = 32;
            break;
        }
        if (info->ap.wepNotation == 1)
            len /= 2;
        MI_CpuFill8(buf, 0, sizeof(buf));
        memset(buf, '*', len);
        drawString(buf, idx);
        break;
    case 3:
        if (!info->ipAuto)
            drawAddress(info->ap.ip, idx);
        break;
    case 4:
        if (!info->ipAuto)
            drawAddress(info->netmask, idx);
        break;
    case 5:
        if (!info->ipAuto)
            drawAddress(info->ap.gateway, idx);
        break;
    case 7:
        if (!info->dnsAuto)
            drawAddress(info->ap.dns[0], idx);
        break;
    case 8:
        if (!info->dnsAuto)
            drawAddress(info->ap.dns[1], idx);
        break;
    }
}



void drawColumnObj(int column, int idx)
{
    SETTINGINFO *info;
    int kind;
    int kind1;
    int st;
    int st1;

    info = DWCi_SETTIGNlGet();
    switch (column) {
    case 0:
    case 1:
        kind = 0;
        st = 0;
        if (!isEnablePush(kind))
            st = 2;
        break;
    case 2:
        st = st1 = 0;
        if (info->ipAuto) {
            kind = 1;
            kind1 = 4;
        } else {
            kind = 2;
            kind1 = 3;
        }
        if (((MEMSSL *)scenesetlist_bss.MemSsl)->push.count[0])
            st = 1;
        if (((MEMSSL *)scenesetlist_bss.MemSsl)->push.count[1])
            st1 = 1;
        dispObj(kind1, st1, idx);
        break;
    case 3:
    case 4:
    case 5:
        kind = 0;
        if (info->ipAuto)
            st = 2;
        else
            st = 0;
        break;
    case 6:
        st = st1 = 0;
        if (info->dnsAuto) {
            kind = 1;
            kind1 = 4;
        } else {
            if (!info->ipAuto)
                st = 2;
            kind = 2;
            kind1 = 3;
        }
        if (((MEMSSL *)scenesetlist_bss.MemSsl)->push.count[2])
            st = 1;
        if (((MEMSSL *)scenesetlist_bss.MemSsl)->push.count[3])
            st1 = 1;
        dispObj(kind1, st1, idx);
        break;
    case 7:
    case 8:
        kind = 0;
        if (info->dnsAuto)
            st = 2;
        else
            st = 0;
        break;
    default:
        kind = 0;
        st = 2;
        break;
    }
    dispObj(kind, st, idx);
}



bool isEnablePush(int area)
{
    SETTINGINFO *info = DWCi_SETTIGNlGet();
    bool rs = 1;

    switch (area) {
    case 7:
        if (!info->ipAuto)
            rs = 0;
        break;
    case 0:
    case 1:
        if (info->ap.setType == 1 || info->ap.setType == 2)
            rs = 0;
        break;
    case 4:
    case 5:
    case 6:
        if (info->ipAuto)
            rs = 0;
        break;
    case 9:
    case 10:
        if (info->dnsAuto)
            rs = 0;
        break;
    case 2:
    case 3:
    case 8:
        break;
    }
    return rs;
}



static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y)
{
    oam->attr01 = (oam->attr01 & 0xFE00FF00) | (y & 0xFF) | ((x & 0x1FF) << 16);
}



static inline void G2_SetOBJPriority(GXOamAttr *oam, int priority)
{
    oam->attr2 = (unsigned short)((oam->attr2 & ~0xC00) | (priority << 10));
}



void dispObj(int kind, int st, int idx)
{
    unsigned short X[5];
    GXOamAttr **ob;

    X[0] = 0xCC;
    X[1] = 0xC0;
    X[2] = 0xC0;
    X[3] = 0x8F;
    X[4] = 0x8F;
    ob = &((MEMSSL *)scenesetlist_bss.MemSsl)->obj[idx];
    if (kind == 1 || kind == 2) {
        if (calcIdxColumn(idx) == 2)
            ob = &((MEMSSL *)scenesetlist_bss.MemSsl)->obj[5];
        else
            ob = &((MEMSSL *)scenesetlist_bss.MemSsl)->obj[6];
    }
    if (scenesetlist_rodata.CELL_IDX[kind][st] != 0) {
        DWCi_CEINlSet(0, scenesetlist_rodata.CELL_IDX[kind][st], *ob);
        G2_SetOBJPosition(*ob, X[kind], 0);
        G2_SetOBJPriority(*ob, 3);
    } else {
        G2_SetOBJPosition(*ob, 256, 0);
    }
}



void drawString(unsigned char *txt, int idx)
{
    int len;
    int y;
    int i;
    int n;
    unsigned short buf[17];

    MI_CpuFill8(buf, 0, sizeof(buf));
    len = DWCi_STRlNLen((char *)txt, 32);
    n = len;
    if (len > 16)
        n = 16;
    for (i = 0; i < n; i++) {
        if (txt[i] == ' ')
            buf[i] = 0xE01D;
        else
            buf[i] = txt[i];
    }
    y = idx * 29 + 2;
    if (len <= 16)
        y += 5;
    DWCi_FNTlDrawStringEx(((MEMSSL *)scenesetlist_bss.MemSsl)->canv, 0x48, y, 2, 8, buf, 1);
    if (len <= 16)
        return;
    MI_CpuFill8(buf, 0, sizeof(buf));
    n = len - 16;
    for (i = 0; i < n; i++) {
        if (txt[i + 16] == ' ')
            buf[i] = 0xE01D;
        else
            buf[i] = txt[i + 16];
    }
    DWCi_FNTlDrawStringEx(((MEMSSL *)scenesetlist_bss.MemSsl)->canv, 0x48, y + 12, 2, 8, buf, 1);
}



void drawAddress(const unsigned char *addr, int idx)
{
    unsigned short buf[16];
    char tmpbuf[16];

    OS_SNPrintf(tmpbuf, 16, scenesetlist_str_22070, addr[0], addr[1], addr[2], addr[3]);
    DWCi_STRlConvertStringAsciiToUnicode(buf, tmpbuf, 16);
    DWCi_FNTlDrawStringEx(((MEMSSL *)scenesetlist_bss.MemSsl)->canv, 0x5F, idx * 29 + 8, 2, 7, buf, 1);
}




static inline void G2_GetOBJPosition(const GXOamAttr *oam, unsigned long *x, unsigned long *y)
{
    *x = (oam->attr01 & 0x01FF0000) >> 16;
    *y = (oam->attr01 & 0x000000FF) >> 0;
}



void setOffset(void)
{
    int cell;
    int dif;
    int cy;
    int x;
    int y;
    int i;

    cell = FX_DivS32(scenesetlist_bss.Pos, 29);
    dif = 0x34 - FX_ModS32(scenesetlist_bss.Pos, 29);
    if (((MEMSSL *)scenesetlist_bss.MemSsl)->icon) {
        if (!cell)
            x = 38;
        else
            x = 256;
        G2_SetOBJPosition(((MEMSSL *)scenesetlist_bss.MemSsl)->icon, x, dif);
    }
    for (i = 0, cy = dif; i < 5; i++, cy += 29) {
        G2_GetOBJPosition(((MEMSSL *)scenesetlist_bss.MemSsl)->obj[i], (unsigned long *)&x, (unsigned long *)&y);
        G2_SetOBJPosition(((MEMSSL *)scenesetlist_bss.MemSsl)->obj[i], x, cy);
    }
    if (cell <= 2) {
        G2_GetOBJPosition(((MEMSSL *)scenesetlist_bss.MemSsl)->obj[5], (unsigned long *)&x, (unsigned long *)&y);
        G2_SetOBJPosition(((MEMSSL *)scenesetlist_bss.MemSsl)->obj[5], x, (2 - cell) * 29 + dif);
    } else {
        G2_SetOBJPosition(((MEMSSL *)scenesetlist_bss.MemSsl)->obj[5], 256, 0);
    }
    if (cell >= 2 && cell <= 6) {
        G2_GetOBJPosition(((MEMSSL *)scenesetlist_bss.MemSsl)->obj[6], (unsigned long *)&x, (unsigned long *)&y);
        G2_SetOBJPosition(((MEMSSL *)scenesetlist_bss.MemSsl)->obj[6], x, (6 - cell) * 29 + dif);
    } else {
        G2_SetOBJPosition(((MEMSSL *)scenesetlist_bss.MemSsl)->obj[6], 256, 0);
    }
    ((MEMSSL *)scenesetlist_bss.MemSsl)->renew = 1;
}



static unsigned char  FocusClm = 0;


static unsigned char  RetScene = 0;


static unsigned char  Focus = 0;


static unsigned short Pos = 0;


static MEMSSL        *MemSsl = 0;



static const unsigned char PALETTE_NUM[3] = { 6, 8, 7 };


static const signed char   MSG_IDX[7] = { -1, 0x23, 0x27, -1, 0x23, 0x2f, -1 };


static const AREA A_EDIT = { 0xcc, 0x34, 0x1c, 0x18 };


static const AREA A_NO = { 0x8f, 0x34, 0x2c, 0x18 };


static const AREA A_YES = { 0xc0, 0x34, 0x2c, 0x18 };


static const unsigned char CLM2FCS_TBL[9] = { 0, 1, 0xe, 4, 5, 6, 0xe, 9, 0xa };


static const unsigned char OFS_BACK[9] = { 0, 5, 2, 7, 4, 1, 6, 3, 0 };


static const unsigned char FCS2CLM_TBL[11] = { 0, 1, 2, 2, 3, 4, 5, 6, 6, 7, 8 };


static const unsigned char CELL_IDX[5][3] = { {0,0x29,0x2c},{0x52,0x53,0x30},{0,0x2a,0x30},{0x54,0x55,0},{0,0x2b,0} };


static const unsigned short BACK_POS[9] = { 0x60, 0xe0, 0x140, 0x1c0, 0x240, 0x2a0, 0x320, 0x3a0, 0 };


static const RECT R_BUTTON[3] = { {0x84,0x1b,0xfc,0x2c},{0x84,0xac,0xfc,0xbd},{4,0xac,0x7c,0xbd} };


static const RECT R_FOCUS[6] = { {0xc8,0x31,0xe0,0x4d},{0xbc,0x31,0xe0,0x4d},{0x8b,0x31,0xaf,0x4d},{0x82,0x18,0xee,0x2c},{0x82,0xa9,0xee,0xbd},{2,0xa9,0x6e,0xbd} };



int isPush(void)
{
    AREA a;
    int cell;
    int i;

    if (!DWCi_TPlCheckTrigger(&DWCi_R_SCR))
        return 14;
    cell = FX_DivS32(Pos, 29);
    a = A_EDIT;
    for (i = 0; i < 4; i++, cell++) {
        if (cell != 2 && cell != 6) {
            if (DWCi_TPlCheckATrigger((AREA *)&a))
                return CLM2FCS_TBL[cell];
        }
        a.t += 29;
    }
    cell = FX_DivS32(Pos, 29);
    for (i = 0; i < 4; i++, cell++) {
        if (cell == 2) {
            a = A_YES;
            a.t += (unsigned short)(i * 29);
            if (DWCi_TPlCheckATrigger((AREA *)&a))
                return 2;
            a = A_NO;
            a.t += (unsigned short)(i * 29);
            if (DWCi_TPlCheckATrigger((AREA *)&a))
                return 3;
            break;
        }
    }
    cell = FX_DivS32(Pos, 29);
    for (i = 0; i < 4; i++, cell++) {
        if (cell == 6) {
            a = A_YES;
            a.t += (unsigned short)(i * 29);
            if (DWCi_TPlCheckATrigger((AREA *)&a))
                return 7;
            a = A_NO;
            a.t += (unsigned short)(i * 29);
            if (DWCi_TPlCheckATrigger((AREA *)&a))
                return 8;
            break;
        }
    }
    for (i = 0; i < 3; i++) {
        if (DWCi_TPlCheckTrigger((RECT *)&R_BUTTON[i]))
            return i + 11;
    }
    return 14;
}



/*
 * Scan four consecutive halfword entries of the global table for the argument,
 * returning the index of the hit or -1.  Every concrete byte matches the image
 * (68 bytes, no register or constant residue).
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x0207C958 is the ARM
 * SDK symbol FX_DivS32 (also an EXACT sdk_calibration entry).  Declaring it
 * `arm` (the image's ISA) lets the `sdk`/`matched` class attest the +0x14
 * call; the old `thumb` declaration fought the image's ISA and suppressed it.
 * Verified EXACT, 68 bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C9D10.c \
 *       --func func_021C9D10 --addr 0x021C9D10 --region ov016 --cc dsi/1.1p1 --arm
 */
int func_021C9D10(int a)
{
    unsigned char *g = (unsigned char *)0x021DE5EC;
    int i;
    int v = func_0207C958(*(unsigned short *)(g + 4), 0x1d);

    for (i = 0; i < 4; i++) {
        if (v == a)
            return i;
        v++;
    }
    return -1;
}



/*
 * Scale the shared halfword counter by 1/0x1d and bias by the argument.
 * Every concrete byte matches the image (36 bytes, no register or constant
 * residue).
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x0207C958 is the ARM
 * SDK symbol FX_DivS32 (also an EXACT sdk_calibration entry).  Declaring it
 * `arm` (the image's ISA) lets the `sdk`/`matched` class attest the +0x14
 * call.  The old `thumb` declaration fought the image's ISA and suppressed it.
 *
 * The bias `+ a` must be written with the call result on the left of a local
 * (`v + a`), not `func(...) + a`: the latter emits `add r0, r4, r0` instead of
 * the image's `add r0, r0, r4`.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C9D54.c \
 *       --func func_021C9D54 --addr 0x021C9D54 --region ov016 --cc dsi/1.1p1 --arm
 */
int func_021C9D54(int a)
{
    unsigned char *g = (unsigned char *)0x021DE5EC;
    int v = func_0207C958(*(unsigned short *)(g + 4), 0x1d);

    return v + a;
}



void taskUp(void *task)
{
    int def;

    DWCi_SBlDisable();
    DWCi_FOCUSlDelete();
    if (scenesetlist_bss.Pos > 6)
        scenesetlist_bss.Pos -= 6;
    else
        scenesetlist_bss.Pos = 0;
    def = FX_ModS32(scenesetlist_bss.Pos, 29);
    if (def == 23) {
        drawWindow();
        return;
    }
    if (def > 23) {
        scenesetlist_bss.Pos += 29 - def;
        def = 0;
    }
    setOffset();
    if (def != 0)
        return;
    DWCi_SBlSet(scenesetlist_bss.Pos * 55 / 145);
    DWCi_SBlEnable();
    applyForcus();
    ((MEMSSL *)scenesetlist_bss.MemSsl)->task = 0;
    DWCi_TSKlDelete(0, task);
}



void taskDown(void *task)
{
    int def;

    DWCi_SBlDisable();
    DWCi_FOCUSlDelete();
    scenesetlist_bss.Pos += 6;
    def = FX_ModS32(scenesetlist_bss.Pos, 29);
    if (def >= 6) {
        setOffset();
    } else {
        scenesetlist_bss.Pos -= def;
        drawWindow();
        DWCi_SBlSet(scenesetlist_bss.Pos * 55 / 145);
        DWCi_SBlEnable();
        applyForcus();
        ((MEMSSL *)scenesetlist_bss.MemSsl)->task = 0;
        DWCi_TSKlDelete(0, task);
    }
}



void taskVBlank(void)
{
    int cell;
    int oft;

    if (!((MEMSSL *)scenesetlist_bss.MemSsl)->renew)
        return;
    cell = FX_DivS32(scenesetlist_bss.Pos, 29);
    oft = FX_ModS32(scenesetlist_bss.Pos, 29) - 0x33;
    *(volatile unsigned long *)0x04000010 = (unsigned long)((oft << 16) & 0x01FF0000);
    *(volatile unsigned long *)0x04000018 = (unsigned long)(((oft + scenesetlist_rodata.OFS_BACK[cell]) << 16) & 0x01FF0000);
    ((MEMSSL *)scenesetlist_bss.MemSsl)->renew = 0;
}



void dispFocus(void)
{
    TYEP_INIT TYEP = scenesetlist_init_21137;
    RECT r;
    int type;

    type = TYEP.v[scenesetlist_bss.Focus];
    if (type >= 3) {
        DWCi_FOCUSlDisp(3, scenesetlist_rodata.R_FOCUS[type].l, scenesetlist_rodata.R_FOCUS[type].r,
                        scenesetlist_rodata.R_FOCUS[type].t);
        return;
    }
    r = scenesetlist_rodata.R_FOCUS[type];
    r.t += scenesetlist_bss.FocusClm * 29;
    DWCi_FOCUSlDisp(1, r.l, r.r, r.t);
}



void applyForcus(void)
{
    SETTINGINFO *info;
    int c;

    if (scenesetlist_bss.Focus == 11 || scenesetlist_bss.Focus == 12 || scenesetlist_bss.Focus == 13) {
        dispFocus();
        return;
    }
    info = DWCi_SETTIGNlGet();
    c = scenesetlist_bss.FocusClm + FX_DivS32(scenesetlist_bss.Pos, 29);
    switch (c) {
    case 2:
        if (info->ipAuto)
            scenesetlist_bss.Focus = 2;
        else
            scenesetlist_bss.Focus = 3;
        break;
    case 6:
        if (info->dnsAuto)
            scenesetlist_bss.Focus = 7;
        else
            scenesetlist_bss.Focus = 8;
        break;
    default:
        scenesetlist_bss.Focus = scenesetlist_rodata.CLM2FCS_TBL[c];
        break;
    }
    dispFocus();
}



/*
 * Map the argument through the shared byte table into the global's second byte.
 * Addresses are Black-image addresses.
 */
void func_021CA0D4(int a)
{
    unsigned char *g = (unsigned char *)0x021DE5EC;

    *g = a;
    *(unsigned char *)(g + 2) = func_021C9D10(tbl_021DA650[a]);
    func_021C9F58();
}



void moveFocus(int dir)
{
    SETTINGINFO *info;
    int move;
    int f;

    info = DWCi_SETTIGNlGet();
    move = 0;
    f = scenesetlist_bss.Focus;
    if (f == 8 && !info->ipAuto) {
        if (dir == 0 || dir == 2)
            return;
    }
    switch (f) {
    case 0:
        if (dir == 1) {
            scenesetlist_bss.Focus = 11;
            break;
        }
        if (dir == 3)
            scenesetlist_bss.FocusClm++;
        else
            move = 2;
        break;
    case 10:
        if (dir == 1) {
            scenesetlist_bss.FocusClm--;
            break;
        }
        if (dir == 3)
            scenesetlist_bss.Focus = ((MEMSSL *)scenesetlist_bss.MemSsl)->focusLast;
        else
            move = 2;
        break;
    case 11:
        if (dir == 1) {
            if (!((MEMSSL *)scenesetlist_bss.MemSsl)->sound[1]) {
                DWCi_SNDlPlay(9);
                ((MEMSSL *)scenesetlist_bss.MemSsl)->sound[1] = 1;
            }
            return;
        }
        if (dir == 3) {
            scenesetlist_bss.Focus = 0;
            scenesetlist_bss.FocusClm = 0;
            scenesetlist_bss.Pos = 0;
            drawWindow();
            DWCi_SBlSet(0);
        } else {
            move = 2;
        }
        break;
    case 12:
    case 13:
        ((MEMSSL *)scenesetlist_bss.MemSsl)->focusLast = f;
        if (dir == 1) {
            scenesetlist_bss.Focus = 10;
            scenesetlist_bss.FocusClm = 3;
            scenesetlist_bss.Pos = 145;
            drawWindow();
            DWCi_SBlSet(55);
            break;
        }
        if (dir == 3) {
            if (!((MEMSSL *)scenesetlist_bss.MemSsl)->sound[1]) {
                DWCi_SNDlPlay(9);
                ((MEMSSL *)scenesetlist_bss.MemSsl)->sound[1] = 1;
            }
            return;
        }
        if (f == 12)
            scenesetlist_bss.Focus = 13;
        else
            scenesetlist_bss.Focus = 12;
        break;
    default:
        if (dir == 1) {
            if (scenesetlist_bss.FocusClm) {
                scenesetlist_bss.FocusClm--;
                break;
            }
            DWCi_SNDlPlay(0x13);
            ((MEMSSL *)scenesetlist_bss.MemSsl)->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskUp, 0, 0x78);
            return;
        }
        if (dir == 3) {
            if (scenesetlist_bss.FocusClm < 3) {
                scenesetlist_bss.FocusClm++;
                break;
            }
            DWCi_SNDlPlay(0x13);
            ((MEMSSL *)scenesetlist_bss.MemSsl)->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskDown, 0, 0x78);
            return;
        }
        move = 2;
        if (f == 2)
            scenesetlist_bss.Focus = 3;
        else if (f == 3)
            scenesetlist_bss.Focus = 2;
        else if (f == 7)
            scenesetlist_bss.Focus = 8;
        else if (f == 8)
            scenesetlist_bss.Focus = 7;
        else
            break;
        DWCi_SNDlPlay(8);
        dispFocus();
        break;
    }
    if (move == 2)
        return;
    DWCi_SNDlPlay(8);
    if (move == 0)
        applyForcus();
}



/*
 * Index the shared byte table and tail-call the dispatcher.
 * Addresses are Black-image addresses.
 */
void func_021CA390(void)
{
    unsigned char *g = (unsigned char *)0x021DE5EC;
    int i = *g - 0xb;
    int y = tbl_021DA61C[i];

    func_021CE7B0((void *)(*(int *)(*(int *)(g + 8) + 0x10)), y, y);
}



void taskPushCount(void)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (((MEMSSL *)scenesetlist_bss.MemSsl)->push.count[i] != 0) {
            ((MEMSSL *)scenesetlist_bss.MemSsl)->push.count[i]--;
            if (((MEMSSL *)scenesetlist_bss.MemSsl)->push.count[i] == 0)
                drawWindow();
        }
    }
}



void pushButtonYesNo(void)
{
    FCS_INIT FCS = scenesetlist_init_21261;
    int i;

    for (i = 0; i < 4; i++) {
        if (scenesetlist_bss.Focus == FCS.v[i]) {
            ((MEMSSL *)scenesetlist_bss.MemSsl)->push.count[i] = 20;
            if (i & 1)
                ((MEMSSL *)scenesetlist_bss.MemSsl)->push.count[i - 1] = 0;
            else
                ((MEMSSL *)scenesetlist_bss.MemSsl)->push.count[i + 1] = 0;
            break;
        }
    }
}



bool isCorrect(void)
{
    SETTINGINFO *info = DWCi_SETTIGNlGet();

    if (info->ap.ssid[0][0] == 0)
        return 0;
    if (!info->dnsAuto && !DWC_BACKUPlCheckAddress(info->ap.dns[0]) && !DWC_BACKUPlCheckAddress(info->ap.dns[1]))
        return 0;
    if (!info->ipAuto) {
        if (!DWC_BACKUPlCheckAddress(info->ap.ip))
            return 0;
        if (!DWC_BACKUPlCheckAddress(info->ap.gateway))
            return 0;
        if (!DWC_BACKUPlCheckIp(info->ap.ip, info->netmask))
            return 0;
    }
    return 1;
}



/*
 * Gate on the driver state, then reset the shared block and hand the next state off.
 * Addresses are Black-image addresses.
 */
void func_021CA560(void)
{
    unsigned char *g = (unsigned char *)0x021DE5EC;

    if (func_021D1568() != 0)
        return;
    func_021CFFAC(6);
    func_021D1524();
    func_021CE818(*(int *)(*(int *)(g + 8) + 0xc));
    func_021C0E40(0x021CA5A0);
}

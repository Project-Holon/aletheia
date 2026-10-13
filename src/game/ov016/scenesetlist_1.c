/*
 * file:     scenesetlist_1.c
 * unit:     yes
 * function: func_021C82FC, func_021C84BC, func_021C86B8
 * address:  0x021C82FC
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
 *   DWCi_CEINlSetExObj               0x021D5368  arm
 *   DWCi_CMNlStep                    0x021BD214  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_FNTlFormBgEx                0x021D5A58  arm
 *   DWCi_HEAPlAllocEx                0x021D6414  arm
 *   DWCi_HLlLoadList                 0x021BD6EC  arm
 *   DWCi_Language                    0x021C0EC8  arm
 *   DWCi_SBlInit                     0x021CE874  arm
 *   DWCi_SETTIGNlGet                 0x021CF404  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   calcParam                        0x021C86B8  arm
 *   dispFocus                        0x021C9F58  arm
 *   drawWindow                       0x021C91F4  arm
 *   initGraphics                     0x021C84BC  arm
 *   procInit                         0x021C86F8  arm
 *   scenesetlist_bss                 0x021DE5EC  data
 *   scenesetlist_rodata              0x021DA61C  data
 *   taskPushCount                    0x021CA3C4  arm
 *   taskVBlank                       0x021C9ED8  arm
 *   DWCi_ARClReadEx                  0x021D4B68  arm
 *   DWCi_CMNlLoadResource            0x021BD1D4  arm
 *   DWCi_Char                        0x021BD170  arm
 *   DWCi_SCREENlInit                 0x021CE668  arm
 *   DWCi_SCREENlRenew                0x021CE6F0  arm
 *   GX_LoadBG2Char                   0x0207F0B8  arm
 *   GX_LoadBG3Char                   0x0207F1E0  arm
 *   GX_LoadBG3Scr                    0x0207ECF0  arm
 *   GX_LoadBGPltt                    0x0207E3D0  arm
 *   GX_LoadOBJPltt                   0x0207E51C  arm
 *   scenesetlist_str_20617           0x021DA708  data
 *   scenesetlist_str_20619           0x021DA6D8  data
 *   scenesetlist_str_20621           0x021DA6F0  data
 *   scenesetlist_str_21706           0x021DB580  data
 *   scenesetlist_str_21707           0x021DB594  data
 *   scenesetlist_str_21708           0x021DB5AC  data
 *   scenesetlist_str_21709           0x021DB5C4  data
 */
#include "../../matched/include/G_SCENESETLIST_BSS.h"

#define REG_BG(a) (*(volatile unsigned short *)(a))
typedef _Bool bool_021C82FC;

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
    bool_021C82FC           ipAuto;            /* 0xF5 */
    bool_021C82FC           dnsAuto;           /* 0xF6 */
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
    bool_021C82FC           renew;             /* 0x44 */
    bool_021C82FC           scroll;            /* 0x45 */
    bool_021C82FC           sound[2];          /* 0x46 */
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

typedef unsigned char bool_021C84BC;

/* The three local file names are initialised from the compiler's @20617, @20619 and
 * @20621, each in its own .rodata section. */
typedef struct { char s[23]; } NAME23;

typedef struct { char s[21]; } NAME21;

typedef struct { char s[22]; } NAME22;

extern SETTINGINFO *DWCi_SETTIGNlGet(void);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void calcParam(void);
extern void initGraphics(void);
extern int DWCi_Language(void);
extern bool_021C82FC DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_CMNlStep(int step);
extern void DWCi_HLlLoadList(void);
extern void DWCi_SBlInit(int kind, int max, int x, int y, int pos);
extern void *DWCi_FNTlFormBgEx(int lcd, int font);
extern GXOamAttr *DWCi_CEINlSetExObj(int lcd, int idx);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void taskVBlank(void);
extern void taskPushCount(void);
extern void drawWindow(void);
extern void dispFocus(void);
extern void DWCi_ChangeScene(void (*scene)());
extern void procInit(void);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern char *DWCi_Char(char *name);
extern void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment);
extern void DWCi_SCREENlInit(void *scr);
extern void DWCi_SCREENlRenew(void);
extern void GX_LoadOBJPltt(void *src, unsigned long offset, unsigned long size);
extern void GX_LoadBG3Char(void *src, unsigned long offset, unsigned long size);
extern void GX_LoadBG2Char(void *src, unsigned long offset, unsigned long size);
extern void GX_LoadBGPltt(void *src, unsigned long offset, unsigned long size);
extern void GX_LoadBG3Scr(void *src, unsigned long offset, unsigned long size);
extern char *func_021CF404(void);
extern void func_021C0EA0(unsigned int *a, unsigned int *b);
void DWCi_SceneSetList(void);
void func_021C84BC(void);
void func_021C86B8(void);
extern struct SCENESETLIST_BSS scenesetlist_bss;
extern const SCENESETLIST_RODATA scenesetlist_rodata;
extern char scenesetlist_str_21706[];
extern char scenesetlist_str_21707[];
extern char scenesetlist_str_21708[];
extern char scenesetlist_str_21709[];
extern const NAME23 scenesetlist_str_20617;
extern const NAME21 scenesetlist_str_20619;
extern const NAME22 scenesetlist_str_20621;


static inline void G2_SetOBJPriority(GXOamAttr *oam, int priority)
{
    oam->attr2 = (unsigned short)((oam->attr2 & ~0xC00) | (priority << 10));
}


void DWCi_SceneSetList(void)
{
    SETTINGINFO *info;
    int i;

    info = DWCi_SETTIGNlGet();
    scenesetlist_bss.MemSsl = DWCi_HEAPlAllocEx(sizeof(MEMSSL), 4);
    ((MEMSSL *)scenesetlist_bss.MemSsl)->lastDns = info->dnsAuto;
    ((MEMSSL *)scenesetlist_bss.MemSsl)->focusLast = 12;
    calcParam();
    initGraphics();
    if (scenesetlist_bss.RetScene == 0)
        DWCi_COMMENTlDispEx(0x30, scenesetlist_rodata.MSG_IDX[DWCi_Language()], info->idx + 1);
    else
        DWCi_COMMENTlDispEx(0x45, -1, 0);
    DWCi_CMNlStep(1);
    DWCi_HLlLoadList();
    DWCi_SBlInit(2, 0x55, 0xF1, 0x41, scenesetlist_bss.Pos * 55 / 145);
    ((MEMSSL *)scenesetlist_bss.MemSsl)->canv = DWCi_FNTlFormBgEx(0, 1);
    for (i = 0; i < 7; i++)
        ((MEMSSL *)scenesetlist_bss.MemSsl)->obj[i] = DWCi_CEINlSetExObj(0, 0x29);
    switch (info->ap.setType) {
    case 1:
        ((MEMSSL *)scenesetlist_bss.MemSsl)->icon = DWCi_CEINlSetExObj(0, 0x50);
        G2_SetOBJPriority(((MEMSSL *)scenesetlist_bss.MemSsl)->icon, 3);
        break;
    case 2:
        ((MEMSSL *)scenesetlist_bss.MemSsl)->icon = DWCi_CEINlSetExObj(0, 0x51);
        G2_SetOBJPriority(((MEMSSL *)scenesetlist_bss.MemSsl)->icon, 3);
        break;
    }
    ((MEMSSL *)scenesetlist_bss.MemSsl)->taskV = DWCi_TSKlForm(1, (void (*)(void *, void *))taskVBlank, 0, 0x6E);
    ((MEMSSL *)scenesetlist_bss.MemSsl)->push.task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskPushCount, 0, 0x78);
    drawWindow();
    dispFocus();
    DWCi_ChangeScene(procInit);
}


static inline void SetBGPriority(volatile unsigned short *reg, int priority)
{
    unsigned short v = *reg;
    *reg = (unsigned short)((v & ~3) | priority);
}


/*
 * sdk:      initGraphics (libdwcutil.TWL.HYB.a(scenesetlist.o))
 *
 * EXACT (2026-10-01, wave 4): the six priority writes go through an inline setter
 * that reads the register into a local first, `u16 v = *reg; *reg = (u16)((v & ~3) | p);`.
 * Every spelling without that temporary (macros, struct casts, inline setters without a
 * local, all measured in earlier waves) leaves 1.1p1 computing 0x04000008 = base - 0x1000
 * right after the pool load and hoisting it into the first ldrh stall. Probing showed the
 * eager/lazy placement of that derived address flips on function size (two extra calls or
 * one extra store anywhere before the tail also made it lazy); the inline's local adds
 * the IR weight without emitting code, so the derived address is formed at its use as in
 * the image. Inline locals do not appear in the caller DWARF, consistent with the vendor
 * listing showing only n and the three arrays.
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlist.o), symbol initGraphics (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ov_sdk/ov016_func_021C84BC.c \
 *       --func func_021C84BC --addr 0x021C84BC --region ov016 --lang c99 --arm
 */
void func_021C84BC(void)
{
    NAME23 SCR_BACK = scenesetlist_str_20617;
    NAME21 PLLT = scenesetlist_str_20619;
    NAME22 PLLT_PUSH = scenesetlist_str_20621;
    char *n;

    REG_BG(0x0400000C) = (unsigned short)((REG_BG(0x0400000C) & 0x43) | 0xE18);
    DWCi_CMNlLoadResource(scenesetlist_str_21706, GX_LoadOBJPltt);
    DWCi_CMNlLoadResource(scenesetlist_str_21707, GX_LoadBG3Char);
    DWCi_CMNlLoadResource(scenesetlist_str_21708, GX_LoadBG2Char);
    DWCi_CMNlLoadResource(PLLT.s, GX_LoadBGPltt);
    DWCi_CMNlLoadResource(scenesetlist_str_21709, GX_LoadBG3Scr);
    n = DWCi_Char(SCR_BACK.s);
    ((MEMSSL *)scenesetlist_bss.MemSsl)->back = DWCi_ARClReadEx(n, 0, 4);
    DWCi_SCREENlInit(((MEMSSL *)scenesetlist_bss.MemSsl)->back);
    DWCi_SCREENlRenew();
    n = DWCi_Char(PLLT.s);
    ((MEMSSL *)scenesetlist_bss.MemSsl)->pltt[0] = DWCi_ARClReadEx(n, 0, 4);
    n = DWCi_Char(PLLT_PUSH.s);
    ((MEMSSL *)scenesetlist_bss.MemSsl)->pltt[1] = DWCi_ARClReadEx(n, 0, 4);
    SetBGPriority((volatile unsigned short *)0x04001008, 3);
    SetBGPriority((volatile unsigned short *)0x0400100A, 3);
    SetBGPriority((volatile unsigned short *)0x04000008, 3);
    SetBGPriority((volatile unsigned short *)0x0400000A, 2);
    SetBGPriority((volatile unsigned short *)0x0400000C, 3);
    SetBGPriority((volatile unsigned short *)0x0400000E, 2);
}


void func_021C86B8(void)
{
    unsigned char *g = (unsigned char *)0x021DE5EC;
    int z = 0;
    int v;

    func_021CF404();
    func_021C0EA0((unsigned int *)z, (unsigned int *)(&v));
    if (v == 0) {
        *(unsigned short *)(g + 4) = z;
        *(unsigned char *)g = z;
        *(unsigned char *)(g + 2) = z;
    }
}

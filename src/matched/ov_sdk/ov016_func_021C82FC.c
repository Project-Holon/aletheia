/*
 * function: DWCi_SceneSetList
 * address:  0x021C82FC
 * packet:   pkt_ov016_021C8F20
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
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
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlist.o), symbol DWCi_SceneSetList (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021C82FC.c \
 *       --func DWCi_SceneSetList --addr 0x021C82FC --region ov016 --cc 1.1p1 --arm
 */

#include "../include/G_SCENESETLIST_BSS.h"

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
extern struct SCENESETLIST_BSS scenesetlist_bss;

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
extern const SCENESETLIST_RODATA scenesetlist_rodata;

extern SETTINGINFO *DWCi_SETTIGNlGet(void);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void calcParam(void);
extern void initGraphics(void);
extern int DWCi_Language(void);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
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

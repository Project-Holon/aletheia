/*
 * function: moveFocus
 * address:  0x021CA100
 * packet:   pkt_ov016_021C8F20
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SBlSet                      0x021CE9AC  arm
 *   DWCi_SETTIGNlGet                 0x021CF404  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   applyForcus                      0x021CA030  arm
 *   dispFocus                        0x021C9F58  arm
 *   drawWindow                       0x021C91F4  arm
 *   scenesetlist_bss                 0x021DE5EC  data
 *   taskDown                         0x021C9E3C  arm
 *   taskUp                           0x021C9D78  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlist.o), symbol moveFocus (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021CA100.c \
 *       --func moveFocus --addr 0x021CA100 --region ov016 --cc 1.1p1 --arm
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
extern void DWCi_SNDlPlay(int no);
extern void drawWindow(void);
extern void DWCi_SBlSet(int pos);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void taskUp(void *task);
extern void taskDown(void *task);
extern void dispFocus(void);
extern void applyForcus(void);

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

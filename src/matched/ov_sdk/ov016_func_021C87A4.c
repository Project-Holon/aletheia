/*
 * function: input
 * address:  0x021C87A4
 * packet:   pkt_ov016_021C8F20
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_IPTlCheckRelease            0x021D68A4  arm
 *   DWCi_IPTlCheckRepeat             0x021D6864  arm
 *   DWCi_IPTlCheckTrigger            0x021D6824  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   endScene                         0x021C8EA8  arm
 *   inputWinButton                   0x021C89E8  arm
 *   moveFocus                        0x021CA100  arm
 *   pushWinButton                    0x021C8A6C  arm
 *   scenesetlist_bss                 0x021DE5EC  data
 *   taskDown                         0x021C9E3C  arm
 *   taskUp                           0x021C9D78  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlist.o), symbol input (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021C87A4.c \
 *       --func input --addr 0x021C87A4 --region ov016 --cc 1.1p1 --arm
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

extern bool inputWinButton(void);
extern bool DWCi_IPTlCheckTrigger(unsigned short input);
extern bool DWCi_IPTlCheckRepeat(unsigned short input);
extern bool DWCi_IPTlCheckRelease(unsigned short input);
extern void pushWinButton(int focus);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_ChangeScene(void (*scene)());
extern void endScene(void);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void taskUp(void *task);
extern void taskDown(void *task);
extern void moveFocus(int dir);

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

/*
 * function: pushWinButton
 * address:  0x021C8A6C
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
 *   DWCi_SBlDisable                  0x021CE9D0  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   calcColumnIdx                    0x021C9D10  arm
 *   dispObj                          0x021C9610  arm
 *   dispPushButton                   0x021CA390  arm
 *   endScene                         0x021C8EA8  arm
 *   isCorrect                        0x021CA4C0  arm
 *   isEnablePush                     0x021C9584  arm
 *   procError                        0x021CA560  arm
 *   pushDnsAuto                      0x021C8C50  arm
 *   pushIpAuto                       0x021C8BE4  arm
 *   scenesetlist_bss                 0x021DE5EC  data
 *   scenesetlist_rodata              0x021DA61C  data
 *   setOffset                        0x021C98E4  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlist.o), symbol pushWinButton (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021C8A6C.c \
 *       --func pushWinButton --addr 0x021C8A6C --region ov016 --cc 1.1p1 --arm
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

extern bool isEnablePush(int area);
extern void DWCi_SNDlPlay(int no);
extern void pushIpAuto(bool yes);
extern void pushDnsAuto(bool yes);
extern void dispPushButton(void);
extern bool isCorrect(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern void DWCi_ChangeScene(void (*scene)());
extern void procError(void);
extern int calcColumnIdx(int clm);
extern void dispObj(int kind, int st, int idx);
extern void setOffset(void);
extern void DWCi_SBlDisable(void);
extern void endScene(void);

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

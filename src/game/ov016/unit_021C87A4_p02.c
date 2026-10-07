/*
 * file:     unit_021C87A4_p02.c
 * unit:     yes
 * function: func_021C98E4, func_021C9A94, func_021C9D10, func_021C9D54, func_021C9D78, func_021C9E3C, func_021C9ED8, func_021C9F58, func_021CA030, func_021CA0D4, func_021CA100, func_021CA390, func_021CA3C4, func_021CA418, func_021CA4C0, func_021CA560
 * address:  0x021C98E4
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
 *   FX_DivS32                        0x0207C958  arm
 *   FX_ModS32                        0x0207C994  arm
 *   scenesetlist_bss                 0x021DE5EC  data
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
 *   DWCi_FOCUSlDelete                0x021BD5A8  arm
 *   DWCi_SBlDisable                  0x021CE9D0  arm
 *   DWCi_SBlEnable                   0x021CE9B8  arm
 *   DWCi_SBlSet                      0x021CE9AC  arm
 *   DWCi_TSKlDelete                  0x021D7724  arm
 *   drawWindow                       0x021C91F4  arm
 *   scenesetlist_rodata              0x021DA61C  data
 *   DWCi_FOCUSlDisp                  0x021BD41C  arm
 *   scenesetlist_init_21137          0x021DA6C8  data
 *   DWCi_SETTIGNlGet                 0x021CF404  arm
 *   tbl_021DA650   0x021DA650  data
 *   func_021C9F58   0x021C9F58  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
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

typedef _Bool bool_021C98E4;

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
    bool_021C98E4           ipAuto;            /* 0xF5 */
    bool_021C98E4           dnsAuto;           /* 0xF6 */
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
    bool_021C98E4           renew;             /* 0x44 */
    bool_021C98E4           scroll;            /* 0x45 */
    bool_021C98E4           sound[2];          /* 0x46 */
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

typedef unsigned char bool_021C9A94;

typedef _Bool bool_021C9D78;

typedef _Bool bool_021C9E3C;

typedef _Bool bool_021C9ED8;

typedef _Bool bool_021C9F58;

/* TYEP's initialiser is the compiler's @21137 in its own .rodata section */
typedef struct { unsigned char v[14]; } TYEP_INIT;

typedef _Bool bool_021CA030;

typedef _Bool bool_021CA100;

typedef _Bool bool_021CA3C4;

typedef _Bool bool_021CA418;

/* FCS's initialiser { 2, 3, 7, 8 } is the compiler's @21261 in its own .rodata section */
typedef struct { unsigned char v[4]; } FCS_INIT;

typedef _Bool bool_021CA4C0;

extern long FX_DivS32(long a, long b);
extern long FX_ModS32(long a, long b);
extern bool_021C9A94 DWCi_TPlCheckTrigger(RECT *r);
extern bool_021C9A94 DWCi_TPlCheckATrigger(AREA *a);
extern int func_0207C958(int, int);
extern void DWCi_SBlDisable(void);
extern void DWCi_SBlEnable(void);
extern void DWCi_SBlSet(int pos);
extern void DWCi_FOCUSlDelete(void);
extern void drawWindow(void);
extern void DWCi_TSKlDelete(int kind, void *task);
extern void DWCi_FOCUSlDisp(int kind, int x0, int x1, int y);
extern SETTINGINFO *DWCi_SETTIGNlGet(void);
extern void func_021C9F58(void);
extern void DWCi_SNDlPlay(int no);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021CE7B0(void *src, int sColor, int dColor);
extern int DWC_BACKUPlCheckAddress(unsigned char *address);
extern int DWC_BACKUPlCheckIp(unsigned char *ip, unsigned char *mask);
extern signed char func_021D1568(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021D1524(void);
extern void func_021CE818(unsigned int v);
extern void func_021C0E40(unsigned int v);
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
bool_021CA4C0 isCorrect(void);
void func_021CA560(void);
extern struct SCENESETLIST_BSS scenesetlist_bss;
extern const SCENESETLIST_RODATA scenesetlist_rodata;
extern RECT DWCi_R_SCR;
extern const TYEP_INIT scenesetlist_init_21137;
extern unsigned char tbl_021DA650[];
extern unsigned char tbl_021DA61C[];
extern const FCS_INIT scenesetlist_init_21261;


static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y)
{
    oam->attr01 = (oam->attr01 & 0xFE00FF00) | (y & 0xFF) | ((x & 0x1FF) << 16);
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


bool_021CA4C0 isCorrect(void)
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

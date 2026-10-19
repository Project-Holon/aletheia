/*
 * function: initGraphics
 * sdk:      initGraphics (libdwcutil.TWL.HYB.a(scenesetlist.o))
 * address:  0x021C84BC
 * packet:   pkt_ov016_021C8F20
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
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
 *   scenesetlist_bss                 0x021DE5EC  data
 *   scenesetlist_str_20617           0x021DA708  data
 *   scenesetlist_str_20619           0x021DA6D8  data
 *   scenesetlist_str_20621           0x021DA6F0  data
 *   scenesetlist_str_21706           0x021DB580  data
 *   scenesetlist_str_21707           0x021DB594  data
 *   scenesetlist_str_21708           0x021DB5AC  data
 *   scenesetlist_str_21709           0x021DB5C4  data
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
 *       --func initGraphics --addr 0x021C84BC --region ov016 --lang c99 --arm
 */

#include "../include/G_SCENESETLIST_BSS.h"

typedef unsigned char bool;

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
extern char scenesetlist_str_21706[];
extern char scenesetlist_str_21707[];
extern char scenesetlist_str_21708[];
extern char scenesetlist_str_21709[];

/* The three local file names are initialised from the compiler's @20617, @20619 and
 * @20621, each in its own .rodata section. */
typedef struct { char s[23]; } NAME23;
typedef struct { char s[21]; } NAME21;
typedef struct { char s[22]; } NAME22;
extern const NAME23 scenesetlist_str_20617;
extern const NAME21 scenesetlist_str_20619;
extern const NAME22 scenesetlist_str_20621;

#define REG_BG(a) (*(volatile unsigned short *)(a))

static inline void SetBGPriority(volatile unsigned short *reg, int priority)
{
    unsigned short v = *reg;
    *reg = (unsigned short)((v & ~3) | priority);
}

void initGraphics(void)
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

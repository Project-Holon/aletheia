/*
 * function: isPush
 * address:  0x021C9A94
 * packet:   pkt_ov016_021C8F20
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * w8 scan: `volatile AREA a` + `a.t = <src>.t + i*29` reproduces the original 636-byte size,
 * the AREA copy schedule (l,t then w,h pairs) and the four dead t stores; register allocation
 * now matches. Residue 120 B: (a) original loads t before l in the A_YES/A_NO copies and reuses
 * the copy's t for the add, ours reloads t; (b) original uses the truncating `lsl; add ...,lsr #16`
 * pair where ours folds to `add r1,r1,r5`; (c) loop2/loop3 counter lives in r2 in the original, r1 here.
 * Parked at the deadline, not a toolchain blocker.
 * w8b follow-up: replacing `a = <src>` with five explicit per-field stores in order
 * t,l,w,h + `a.t = <src>.t + (u16)(i*29)` DOES reproduce the original t-before-l load
 * order, the single-t-load reuse, and the `lsl #16 / add ...,lsr #16` truncation pair,
 * but recouples the whole block's register colours (product r0 vs r5, counter r1 vs r2,
 * 628 B / 330 B diff). A `u16 d = i*29` intermediate does not help (644 B). The prior
 * struct-copy shape keeps the exact 636 B size, the mul-before-loads schedule and the
 * r5/r0 product/shift colours; its only deltas are the l/t load order + redundant t
 * reload and the missing truncation pair.
 *
 * symbols:
 *   DWCi_R_SCR                       0x021DAA7C  data
 *   DWCi_TPlCheckATrigger            0x021D6B04  arm
 *   DWCi_TPlCheckTrigger             0x021D696C  arm
 *   FX_DivS32                        0x0207C958  arm
 *   scenesetlist_bss                 0x021DE5EC  data
 *   scenesetlist_rodata              0x021DA61C  data
 *
 * Blocker: DIFF, 16 bytes short. Each AREA copy in the original is scheduled in pairs
 * (l,t then w,h) with t stored twice; this draft loads all four fields first and drops the
 * dead store of t (permuter seed 9202 flat).
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlist.o), symbol isPush (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ov016_func_021C9A94.c \
 *       --func isPush --addr 0x021C9A94 --region ov016 --cc 1.1p1 --arm
 * lane 05 (2026-10-01): new and inert/worse: non-volatile `a` with
 * `a.t += (u16)(i * 29)` (620/409, DSE drops the first t store and the copy
 * loads all four fields first); the same through a static inline
 * setArea(AREA *, const AREA *, u16) (identical, and 652/366 with a volatile
 * pointer).  The image's paired copy (l,t store before w,h load) plus the
 * kept dead t store look like 4.0.0.1025's conservative store/load ordering
 * between a stack local and global data; volatile is the nearest emulation.
 */
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
extern SCENESETLIST_BSS scenesetlist_bss;

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
extern SCENESETLIST_RODATA scenesetlist_rodata;

extern bool DWCi_TPlCheckTrigger(RECT *r);
extern bool DWCi_TPlCheckATrigger(AREA *a);
extern long FX_DivS32(long a, long b);
extern RECT DWCi_R_SCR;

int isPush(void)
{
    volatile AREA a;
    int cell;
    int i;

    if (!DWCi_TPlCheckTrigger(&DWCi_R_SCR))
        return 14;
    cell = FX_DivS32(scenesetlist_bss.Pos, 29);
    a = scenesetlist_rodata.A_EDIT;
    for (i = 0; i < 4; i++, cell++) {
        if (cell != 2 && cell != 6) {
            if (DWCi_TPlCheckATrigger((AREA *)&a))
                return scenesetlist_rodata.CLM2FCS_TBL[cell];
        }
        a.t += 29;
    }
    cell = FX_DivS32(scenesetlist_bss.Pos, 29);
    for (i = 0; i < 4; i++, cell++) {
        if (cell == 2) {
            a = scenesetlist_rodata.A_YES;
            a.t = scenesetlist_rodata.A_YES.t + i * 29;
            if (DWCi_TPlCheckATrigger((AREA *)&a))
                return 2;
            a = scenesetlist_rodata.A_NO;
            a.t = scenesetlist_rodata.A_NO.t + i * 29;
            if (DWCi_TPlCheckATrigger((AREA *)&a))
                return 3;
            break;
        }
    }
    cell = FX_DivS32(scenesetlist_bss.Pos, 29);
    for (i = 0; i < 4; i++, cell++) {
        if (cell == 6) {
            a = scenesetlist_rodata.A_YES;
            a.t = scenesetlist_rodata.A_YES.t + i * 29;
            if (DWCi_TPlCheckATrigger((AREA *)&a))
                return 7;
            a = scenesetlist_rodata.A_NO;
            a.t = scenesetlist_rodata.A_NO.t + i * 29;
            if (DWCi_TPlCheckATrigger((AREA *)&a))
                return 8;
            break;
        }
    }
    for (i = 0; i < 3; i++) {
        if (DWCi_TPlCheckTrigger((RECT *)&scenesetlist_rodata.R_BUTTON[i]))
            return i + 11;
    }
    return 14;
}

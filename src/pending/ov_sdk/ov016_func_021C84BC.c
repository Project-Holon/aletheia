/*
 * function: func_021C84BC
 * sdk:      initGraphics (libdwcutil.TWL.HYB.a(scenesetlist.o))
 * address:  0x021C84BC
 * packet:   pkt_ov016_021C8F20
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
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
 * Blocker: DIFF, 14 concrete bytes in the last six register writes only. File is the raw-address
 * struct-cast spelling below (best measured; the inline-setter spelling is 17). The original
 * computes 0x04000008 as 0x04001008 - 0x1000 just before its use and keeps the 0x04001008 pool
 * base in r1 with MemSsl in r2; this draft puts the pool base in r3, MemSsl in r1, hoists the
 * sub to +0154 and swaps r1/r2. Inline setters, macros, non-volatile registers, a pointer walk,
 * a const/named base pointer and a per-store derived local all measured (docs/notes/
 * pkt_ov016_021C8F20.c.txt); permuter seed 9204 flat. Unresolved: pure allocator/scheduler tie.
 *
 * Lane U37: the six tail writes as raw-address struct casts,
 *   typedef struct { unsigned short priority : 2; unsigned short rest : 14; } BgCnt;
 *   ((BgCnt *)0x04001008)->priority = 3;   (then 0x0400100A=3, 0x04000008=3, 0x0400000A=2,
 *                                           0x0400000C=3, 0x0400000E=2)
 * (the spelling of docs/idioms/a-nearby-absolute-address-is-synthesized-from-the-loaded-base.md)
 * take the residue from 17 to 14 concrete bytes at 508 exact.  Residue left: image
 * `ldr r1, [pc, #0xa8]` | ours `ldr r3, [pc, #0xa8]` - the image keeps the 0x04001008 pool base
 * in r1 with MemSsl in r2 and issues `sub r2, r1, #0x1000` at +0170 (ours hoists it to +0154 and
 * swaps r3/r1); then `sub r1, r4, #2` lands 0xc bytes early.  Variant best-of table (1.1p1):
 * raw struct casts / image order 14, interleaved DC-DB 15, DB group first 22, DC group repeated
 * 49.  Pin scan: 1.1p1 508/17, 1.1 508/17, 1.2 508/17, 1.6sp1 508/21, ../2.0/base 532/125.
 *
 * lane04 (2026-10-01): measured 37 under the brief's command (the 14 above is
 * not reproduced by this body). New and inert: scenesetlist.o's .bss as
 * separate zero-initialised file statics (Focus, RetScene, FocusClm, Pos,
 * MemSsl) instead of one struct (same 37, same +0144 block); the inline
 * G2/G2S setter spelling measures 38.
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlist.o), symbol initGraphics (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ov016_func_021C84BC.c \
 *       --func func_021C84BC --addr 0x021C84BC --region ov016 --cc 1.1p1 --arm
 */
typedef unsigned char bool;

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;
typedef struct tagAREA { unsigned short l, t, w, h; } AREA;
typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;

typedef struct { unsigned short priority : 2; unsigned short rest : 14; } BgCnt;

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

static inline void G2_SetBG0Priority(int priority)
{
    REG_BG(0x04000008) = (unsigned short)((REG_BG(0x04000008) & ~3) | priority);
}
static inline void G2_SetBG1Priority(int priority)
{
    REG_BG(0x0400000A) = (unsigned short)((REG_BG(0x0400000A) & ~3) | priority);
}
static inline void G2_SetBG2Priority(int priority)
{
    REG_BG(0x0400000C) = (unsigned short)((REG_BG(0x0400000C) & ~3) | priority);
}
static inline void G2_SetBG3Priority(int priority)
{
    REG_BG(0x0400000E) = (unsigned short)((REG_BG(0x0400000E) & ~3) | priority);
}
static inline void G2S_SetBG0Priority(int priority)
{
    REG_BG(0x04001008) = (unsigned short)((REG_BG(0x04001008) & ~3) | priority);
}
static inline void G2S_SetBG1Priority(int priority)
{
    REG_BG(0x0400100A) = (unsigned short)((REG_BG(0x0400100A) & ~3) | priority);
}

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
    scenesetlist_bss.MemSsl->back = DWCi_ARClReadEx(n, 0, 4);
    DWCi_SCREENlInit(scenesetlist_bss.MemSsl->back);
    DWCi_SCREENlRenew();
    n = DWCi_Char(PLLT.s);
    scenesetlist_bss.MemSsl->pltt[0] = DWCi_ARClReadEx(n, 0, 4);
    n = DWCi_Char(PLLT_PUSH.s);
    scenesetlist_bss.MemSsl->pltt[1] = DWCi_ARClReadEx(n, 0, 4);
    ((BgCnt *)0x04001008)->priority = 3;
    ((BgCnt *)0x0400100A)->priority = 3;
    ((BgCnt *)0x04000008)->priority = 3;
    ((BgCnt *)0x0400000A)->priority = 2;
    ((BgCnt *)0x0400000C)->priority = 3;
    ((BgCnt *)0x0400000E)->priority = 2;
}

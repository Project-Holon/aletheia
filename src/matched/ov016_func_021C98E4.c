/*
 * function: setOffset
 * address:  0x021C98E4
 * packet:   pkt_ov016_021C8F20
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   FX_DivS32                        0x0207C958  arm
 *   FX_ModS32                        0x0207C994  arm
 *   scenesetlist_bss                 0x021DE5EC  data
 *
 * Blocker: DIFF, 8 bytes short. The original keeps an 8-byte frame for x and y (their
 * addresses feed the inlined G2_GetOBJPosition) and re-reads MemSsl->icon after the test;
 * no spelling tried here keeps the frame under 1.1p1 (permuter seed 9203 flat).
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlist.o), symbol setOffset (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ov016_func_021C98E4.c \
 *       --func setOffset --addr 0x021C98E4 --region ov016 --cc 1.1p1 --arm
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
extern const SCENESETLIST_RODATA scenesetlist_rodata;

extern long FX_DivS32(long a, long b);
extern long FX_ModS32(long a, long b);

static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y)
{
    oam->attr01 = ((x & 0x1FF) << 16) | (oam->attr01 & 0xFE00FF00) | (y & 0xFF);
}

static inline void G2_GetOBJPosition(const GXOamAttr *oam, int *x, int *y)
{
    *x = (int)((oam->attr01 & 0x01FF0000) >> 16);
    *y = (int)(oam->attr01 & 0xFF);
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
    if (scenesetlist_bss.MemSsl->icon) {
        if (cell)
            x = 256;
        else
            x = 38;
        G2_SetOBJPosition(scenesetlist_bss.MemSsl->icon, x, dif);
    }
    for (i = 0, cy = dif; i < 5; i++, cy += 29) {
        G2_GetOBJPosition(scenesetlist_bss.MemSsl->obj[i], &x, &y);
        G2_SetOBJPosition(scenesetlist_bss.MemSsl->obj[i], x, cy);
    }
    if (cell > 2) {
        G2_SetOBJPosition(scenesetlist_bss.MemSsl->obj[5], 256, 0);
    } else {
        G2_GetOBJPosition(scenesetlist_bss.MemSsl->obj[5], &x, &y);
        G2_SetOBJPosition(scenesetlist_bss.MemSsl->obj[5], x, (2 - cell) * 29 + dif);
    }
    if (cell >= 2 && cell <= 6) {
        G2_GetOBJPosition(scenesetlist_bss.MemSsl->obj[6], &x, &y);
        G2_SetOBJPosition(scenesetlist_bss.MemSsl->obj[6], x, (6 - cell) * 29 + dif);
    } else {
        G2_SetOBJPosition(scenesetlist_bss.MemSsl->obj[6], 256, 0);
    }
    scenesetlist_bss.MemSsl->renew = 1;
}

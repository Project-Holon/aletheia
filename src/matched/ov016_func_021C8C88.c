/*
 * function: draw
 * address:  0x021C8C88
 * packet:   pkt_ov016_021C8F20
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_FOCUSlDelete                0x021BD5A8  arm
 *   DWCi_SBlGet                      0x021CE984  arm
 *   DWCi_SBlGetState                 0x021CE998  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   FX_ModS32                        0x0207C994  arm
 *   applyForcus                      0x021CA030  arm
 *   drawWindow                       0x021C91F4  arm
 *   scenesetlist_bss                 0x021DE5EC  data
 *   taskDown                         0x021C9E3C  arm
 *   taskUp                           0x021C9D78  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlist.o), symbol draw (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021C8C88.c \
 *       --func draw --addr 0x021C8C88 --region ov016 --cc 1.1p1 --arm
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

extern int DWCi_SBlGetState(void);
extern int DWCi_SBlGet(void);
extern void DWCi_FOCUSlDelete(void);
extern void drawWindow(void);
extern void DWCi_SNDlPlay(int no);
extern long FX_ModS32(long a, long b);
extern void applyForcus(void);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void taskUp(void *task);
extern void taskDown(void *task);

void draw(void)
{
    int def;

    if (scenesetlist_bss.MemSsl->task)
        return;
    if (scenesetlist_bss.MemSsl->disp)
        scenesetlist_bss.MemSsl->disp--;
    switch (DWCi_SBlGetState()) {
    case 0:
        break;
    case 1:
        scenesetlist_bss.MemSsl->scroll = 1;
        break;
    case 2:
        if (scenesetlist_bss.MemSsl->disp)
            break;
        DWCi_FOCUSlDelete();
        scenesetlist_bss.Pos = DWCi_SBlGet() * 145 / 55;
        drawWindow();
        scenesetlist_bss.MemSsl->disp = 4;
        break;
    case 3:
        scenesetlist_bss.MemSsl->scroll = 0;
        scenesetlist_bss.Pos = DWCi_SBlGet() * 145 / 55;
        DWCi_SNDlPlay(0x13);
        drawWindow();
        def = FX_ModS32(scenesetlist_bss.Pos, 29);
        if (def == 0)
            applyForcus();
        else if (def < 16)
            scenesetlist_bss.MemSsl->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskUp, 0, 0x78);
        else
            scenesetlist_bss.MemSsl->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskDown, 0, 0x78);
        break;
    case 4:
        if (scenesetlist_bss.Pos == 0) {
            if (!scenesetlist_bss.MemSsl->sound[0]) {
                DWCi_SNDlPlay(9);
                scenesetlist_bss.MemSsl->sound[0] = 1;
            }
        } else {
            DWCi_SNDlPlay(0x13);
            scenesetlist_bss.MemSsl->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskUp, 0, 0x78);
        }
        break;
    case 6:
        if (scenesetlist_bss.Pos == 145) {
            if (!scenesetlist_bss.MemSsl->sound[0]) {
                DWCi_SNDlPlay(9);
                scenesetlist_bss.MemSsl->sound[0] = 1;
            }
        } else {
            DWCi_SNDlPlay(0x13);
            scenesetlist_bss.MemSsl->task = DWCi_TSKlForm(0, (void (*)(void *, void *))taskDown, 0, 0x78);
        }
        break;
    case 5:
    case 7:
        scenesetlist_bss.MemSsl->sound[0] = 0;
        break;
    }
}

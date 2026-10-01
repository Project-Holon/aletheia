/*
 * function: isPush
 * address:  0x021C9A94
 * packet:   pkt_ov016_021C8F20
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * Closed 2026-10-01 (w3 lane18): scenesetlist.o keeps Focus..MemSsl and PALETTE_NUM..R_FOCUS
 * as separate file statics (vendor symtab), not two extern structs. Defined here as
 * initialised statics, a plain (non-volatile) `AREA a` keeps the paired copy schedule and
 * the dead t store, and `a.t += (unsigned short)(i * 29)` gives the lsl/lsr truncation.
 * The 1-byte .bss group is declared in reverse (FocusClm, RetScene, Focus) so 1.1p1 lays
 * Focus at +0 and Pos at +4.
 *
 * symbols:
 *   DWCi_R_SCR                       0x021DAA7C  data
 *   DWCi_TPlCheckATrigger            0x021D6B04  arm
 *   DWCi_TPlCheckTrigger             0x021D696C  arm
 *   FX_DivS32                        0x0207C958  arm
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
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlist.o), symbol isPush (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021C9A94.c \
 *       --func isPush --addr 0x021C9A94 --region ov016 --cc 1.1p1 --arm
 */
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

extern bool DWCi_TPlCheckTrigger(RECT *r);
extern bool DWCi_TPlCheckATrigger(AREA *a);
extern long FX_DivS32(long a, long b);
extern RECT DWCi_R_SCR;

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

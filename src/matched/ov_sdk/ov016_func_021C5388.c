/*
 * function: getCharName
 * address:  0x021C5388
 * packet:   pkt_ov016_021C50D4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CELL_LV                          0x021DA51F  data
 *   DWCi_CEINlSet                    0x021D52D4  arm
 *   DWCi_CEINlSetExObj               0x021D5368  arm
 *   scenesetaplist_bss               0x021DE5D8  data
 *   scenesetaplist_rodata            0x021DA51C  data
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetaplist.o), symbol getCharName (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021C5388.c \
 *       --func getCharName --addr 0x021C5388 --region ov016 --cc 1.1p1 --arm
 */
typedef _Bool bool;

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;
typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;

typedef struct tagAPINFO {
    unsigned char  ssid[32];          /* 0x00 */
    unsigned char  bssid[6];          /* 0x20 */
    unsigned short level;             /* 0x26 */
    unsigned char  wep;               /* 0x28 */
} APINFO;

typedef struct tagMEMSSAL {
    APINFO        *info;              /* 0x00 */
    void          *back;              /* 0x04 */
    void          *pltt;              /* 0x08 */
    void          *canv;              /* 0x0C */
    GXOamAttr     *objWep[5];         /* 0x10 */
    GXOamAttr     *objLevel[5];       /* 0x24 */
    void          *task;              /* 0x38 */
    void          *taskV;             /* 0x3C */
    unsigned short distScroll;        /* 0x40 */
    unsigned short nameWep[3];        /* 0x42 */
    unsigned short nameLv[4];         /* 0x48 */
    signed char    push;              /* 0x50 */
    unsigned char  apNum;             /* 0x51 */
    unsigned char  apIdx;             /* 0x52 */
    unsigned char  distBar;           /* 0x53 */
    unsigned char  choose;            /* 0x54 */
    unsigned char  disp;              /* 0x55 */
    bool           renew;             /* 0x56 */
    bool           scroll;            /* 0x57 */
    bool           sound[2];          /* 0x58 */
} MEMSSAL;

/* scenesetaplist.o .bss at 0x021DE5D8, members at their vendor offsets */
typedef struct {
    unsigned char  Focus;             /* 0x00 */
    unsigned short Pos;               /* 0x02 */
    MEMSSAL       *MemSsal;           /* 0x04 */
} SCENESETAPLIST_BSS;
extern SCENESETAPLIST_BSS scenesetaplist_bss;

/* scenesetaplist.o .rodata at 0x021DA51C, members at their vendor offsets */
typedef struct {
    unsigned char  CELL_WEP[3];       /* 0x00 */
    unsigned char  CELL_LV[4];        /* 0x03 */
    RECT           R_TOUCH[5];        /* 0x08 */
    RECT           R_FOCUS[5];        /* 0x30 */
} SCENESETAPLIST_RODATA;
extern const SCENESETAPLIST_RODATA scenesetaplist_rodata;

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

extern RECT DWCi_R_SCR;

extern void DWCi_ARClRelease(void *file);
extern void DWCi_BTNlDisable(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_BTNlEnd(void);
extern int DWCi_BTNlGet(void);
extern bool DWCi_BTNlIsEnd(void);
extern void DWCi_BTNlSet(int idx);
extern void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);
extern GXOamAttr *DWCi_CEINlSetExObj(int lcd, int idx);
extern void DWCi_CMNlStep(int step);
extern bool DWCi_COMMENTlDelete(void);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_ChangeScene(void (*scene)());
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_FNTlClear(void *canvas, int color);
extern void DWCi_FNTlDeleteBg(void *canvas);
extern void DWCi_FNTlDrawStringEx(void *canvas, int x, int y, int color, int interval, unsigned short *txt, int font);
extern void *DWCi_FNTlFormBgEx(int lcd, int font);
extern void DWCi_FNTlRenewBg(void *canvas);
extern void DWCi_FOCUSlDelete(void);
extern void DWCi_FOCUSlDisp(int kind, int x0, int x1, int y);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_GetParam2_(void **param2, void **param3);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_HEAPlFree_(void **mem);
extern void DWCi_HLlLoadSet(void);
extern bool DWCi_IPTlCheckRelease(unsigned short input);
extern bool DWCi_IPTlCheckRepeat(unsigned short input);
extern bool DWCi_IPTlCheckTrigger(unsigned short input);
extern void DWCi_OBJlDelete(GXOamAttr *obj);
extern void DWCi_SBlDisable(void);
extern void DWCi_SBlEnable(void);
extern void DWCi_SBlEnd(void);
extern int DWCi_SBlGet(void);
extern int DWCi_SBlGetState(void);
extern void DWCi_SBlInit(int kind, int max, int x, int y, int pos);
extern void DWCi_SBlSet(int pos);
extern void DWCi_SCREENlCopyPalette(void *src, int sColor, int dColor);
extern void DWCi_SCREENlEnd(void);
extern void DWCi_SEARCHlEnd(void);
extern int DWCi_SEARCHlGetApInfo(APINFO **info);
extern SETTINGINFO *DWCi_SETTIGNlGet(void);
extern void DWCi_SETTINGlSetSetting(int idx);
extern void DWCi_SETTINGlSetSsid(char *ssid);
extern void DWCi_SNDlPlay(int no);
extern int DWCi_STRlNLen(char *s, int maxlen);
extern void DWCi_SetParam2_(void *param2, void *param3);
extern void DWCi_SetParam_(void *param0, void *param1);
extern bool DWCi_TPlCheckRelease(RECT *r);
extern bool DWCi_TPlCheckTrigger(RECT *r);
extern void DWCi_TSKlDelete(int kind, void *task);
extern void DWCi_TSKlDeleteEx(int kind, void *task);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void DWCi_WINlEnd(void);
extern int DWCi_WINlGet(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern bool DWCi_WINlIsInit(void);
extern long FX_DivS32(long a, long b);
extern long FX_ModS32(long a, long b);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);

extern void DWCi_SceneSetEdit32(void);
extern void DWCi_SceneSetSearch(void);
extern void DWCi_SceneSetSelectWay(void);
extern void DWCi_SceneSetTestConfirm(void);

static void dispFocus(void);
static void dispPushButton(void);
static void drapApObj(int ap, int column);
static void drawAp(int ap, int column);
static void drawApInfo(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
static void getCharName(void);
static void initGraphics(void);
static void initScrollBar(void);
static void moveFocus(int dir);
static void procError(void);
static void procError1(void);
static void procInit(void);
static void procInit1(void);
static void procScene(void);
static void scrollDown(void);
static void scrollUp(void);
static void setOffset(void);
static void taskDown(void *task);
static void taskUp(void *task);
static void taskVBlank(void);

static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y)
{
    oam->attr01 = (oam->attr01 & 0xFE00FF00) | (y & 0xFF) | ((x & 0x1FF) << 16);
}

static inline void G2_SetOBJPriority(GXOamAttr *oam, int priority)
{
    oam->attr2 = (unsigned short)((oam->attr2 & ~0xC00) | (priority << 10));
}

/* CELL_LV is named on its own: the loop reaches it through its own pool word
   (the vendor symbol at scenesetaplist_rodata + 3), not through the section base. */
extern const unsigned char CELL_LV[4];

static void getCharName(void)
{
    int num;
    int i;

    num = scenesetaplist_bss.MemSsal->apNum;
    if (num > 5)
        num = 5;
    for (i = 0; i < num; i++) {
        scenesetaplist_bss.MemSsal->objWep[i] = DWCi_CEINlSetExObj(0, 0x2e);
        scenesetaplist_bss.MemSsal->objLevel[i] = DWCi_CEINlSetExObj(0, 0x18);
    }
    for (i = 0; i < sizeof(scenesetaplist_rodata.CELL_WEP); i++) {
        DWCi_CEINlSet(0, scenesetaplist_rodata.CELL_WEP[i], scenesetaplist_bss.MemSsal->objWep[0]);
        scenesetaplist_bss.MemSsal->nameWep[i] = scenesetaplist_bss.MemSsal->objWep[0]->attr2 & 0x3ff;
    }
    for (i = 0; i < sizeof(scenesetaplist_rodata.CELL_LV); i++) {
        DWCi_CEINlSet(0, CELL_LV[i], scenesetaplist_bss.MemSsal->objLevel[0]);
        scenesetaplist_bss.MemSsal->nameLv[i] = scenesetaplist_bss.MemSsal->objLevel[0]->attr2 & 0x3ff;
    }
    for (i = 0; i < num; i++) {
        G2_SetOBJPriority(scenesetaplist_bss.MemSsal->objWep[i], 3);
        G2_SetOBJPriority(scenesetaplist_bss.MemSsal->objLevel[i], 3);
    }
}

/*
 * file:     unit_021C50D4.c
 * unit:     yes
 * function: func_021C50D4, func_021C519C, func_021C52E4, func_021C5388, func_021C54E8
 * address:  0x021C50D4
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
 *   DWCi_CMNlStep                    0x021BD214  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_FNTlFormBgEx                0x021D5A58  arm
 *   DWCi_GetParam2_                  0x021C0EA0  arm
 *   DWCi_HEAPlAllocEx                0x021D6414  arm
 *   DWCi_HLlLoadSet                  0x021BD6D4  arm
 *   DWCi_SEARCHlGetApInfo            0x021CF114  arm
 *   DWCi_TSKlForm                    0x021D7680  arm
 *   dispFocus                        0x021C628C  arm
 *   drawApInfo                       0x021C5D9C  arm
 *   initGraphics                     0x021C519C  arm
 *   scenesetaplist_bss               0x021DE5D8  data
 *   taskVBlank                       0x021C6234  arm
 *   func_021BD1D4   0x021BD1D4  arm  ov016
 *   func_021BD170   0x021BD170  arm  ov016
 *   func_021D4B68   0x021D4B68  arm  ov016
 *   func_021CE668   0x021CE668  arm  ov016
 *   func_021CE6F0   0x021CE6F0  arm  ov016
 *   dat_021DA58C   0x021DA58C  data
 *   dat_021DA574   0x021DA574  data
 *   dat_021DB438   0x021DB438  data
 *   dat_0207ECF0   0x0207ECF0  data
 *   dat_021DE5D8   0x021DE5D8  data
 *   DWCi_SBlInit                     0x021CE874  arm
 *   FX_DivS32                        0x0207C958  arm
 *   CELL_LV                          0x021DA51F  data
 *   DWCi_CEINlSet                    0x021D52D4  arm
 *   DWCi_CEINlSetExObj               0x021D5368  arm
 *   scenesetaplist_rodata            0x021DA51C  data
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   procInit1                        0x021C5550  arm
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

/* scenesetaplist.o .rodata at 0x021DA51C, members at their vendor offsets */
typedef struct {
    unsigned char  CELL_WEP[3];       /* 0x00 */
    unsigned char  CELL_LV[4];        /* 0x03 */
    RECT           R_TOUCH[5];        /* 0x08 */
    RECT           R_FOCUS[5];        /* 0x30 */
} SCENESETAPLIST_RODATA;

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

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct { char s[0x19]; } T25;

typedef struct { char s[0x17]; } T23;

typedef struct { char s[0x16]; } T22;

typedef struct { char s[0x15]; } T21;

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
extern void func_021BD1D4(int, int);
extern int func_021BD170(void *);
extern int func_021D4B68(int, int, int);
void DWCi_SceneSetApList(void);
void func_021C519C(void);
extern SCENESETAPLIST_BSS scenesetaplist_bss;
extern const SCENESETAPLIST_RODATA scenesetaplist_rodata;
extern RECT DWCi_R_SCR;
extern T25 dat_021DA58C;
extern T22 dat_021DA574;
extern unsigned char dat_021DB438[];
extern unsigned char dat_0207ECF0[];
extern unsigned char dat_021DE5D8[];
/* CELL_LV is named on its own: the loop reaches it through its own pool word
   (the vendor symbol at scenesetaplist_rodata + 3), not through the section base. */
extern const unsigned char CELL_LV[4];


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


void DWCi_SceneSetApList(void)
{
    int prm;

    scenesetaplist_bss.MemSsal = DWCi_HEAPlAllocEx(sizeof(MEMSSAL), 4);
    DWCi_GetParam2_((void **)&prm, 0);
    if (prm == 0) {
        scenesetaplist_bss.Focus = 0;
        scenesetaplist_bss.Pos = 0;
    }
    scenesetaplist_bss.MemSsal->apNum = DWCi_SEARCHlGetApInfo(&scenesetaplist_bss.MemSsal->info);
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_COMMENTlDispEx(0x34, -1, 0);
    DWCi_CMNlStep(2);
    initScrollBar();
    getCharName();
    scenesetaplist_bss.MemSsal->canv = DWCi_FNTlFormBgEx(0, 0);
    scenesetaplist_bss.MemSsal->taskV = DWCi_TSKlForm(1, (void (*)(void *, void *))taskVBlank, 0, 0x6e);
    drawApInfo();
    dispFocus();
    DWCi_ChangeScene(procInit);
}


/*
 * Copy a 0x19-byte and a 0x16-byte NCL resource path into two stack buffers
 * (the first copy is odd-sized, so it ends with a trailing byte), load one
 * tilemap through func_021BD1D4, publish both buffers through
 * func_021BD170/func_021D4B68 into the record held by 0x021DE5D8+4, poke
 * func_021CE668/func_021CE6F0 on it, then set the low two bits of the
 * 0x04001008 pair, 0x04000008 and the 0x0400000A triple.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C519C.c \
 *       --func func_021C519C --addr 0x021C519C --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C519C(void)
{
    T25 buf2;
    T22 buf;
    u16 *p;

    buf2 = dat_021DA58C;
    buf = dat_021DA574;
    func_021BD1D4((int)dat_021DB438, (int)dat_0207ECF0);

    (*(int **)(dat_021DE5D8 + 4))[1] = func_021D4B68(func_021BD170(&buf2), 0, 4);
    func_021CE668((*(int **)(dat_021DE5D8 + 4))[1]);
    func_021CE6F0();
    (*(int **)(dat_021DE5D8 + 4))[2] = func_021D4B68(func_021BD170(&buf), 0, 4);

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x04000008;
    p[0] = (p[0] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 2;
    p[1] = (p[1] & ~3) | 3;
    p[2] = (p[2] & ~3) | 2;
}


static void initScrollBar(void)
{
    int kind;
    int pos = 0;

    scenesetaplist_bss.MemSsal->distScroll = (scenesetaplist_bss.MemSsal->apNum - 4) * 28;
    if (scenesetaplist_bss.MemSsal->apNum <= 4) {
        kind = 0;
        scenesetaplist_bss.MemSsal->distBar = 0;
    } else if (scenesetaplist_bss.MemSsal->apNum <= 8) {
        scenesetaplist_bss.MemSsal->distBar = 31;
        kind = 1;
    } else {
        scenesetaplist_bss.MemSsal->distBar = 55;
        kind = 2;
    }
    if (kind != 0)
        pos = FX_DivS32(scenesetaplist_bss.Pos * scenesetaplist_bss.MemSsal->distBar, scenesetaplist_bss.MemSsal->distScroll);
    DWCi_SBlInit(kind, 0x55, 0xec, 0x3f, pos);
}


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


static void procInit(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x1d, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x1d);
    DWCi_ChangeScene(procInit1);
}

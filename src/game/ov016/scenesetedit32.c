/*
 * file:     scenesetedit32.c
 * unit:     yes
 * function: DWCi_SceneSetEdit32, initGraphics, DWCi_SceneSetEdit32ProcInit, procInit1, procInit2, DWCi_SceneSetEdit32_procScene, input, DWCi_SceneSetEdit32_draw, endScene, endScene1, DWCi_SceneSetEdit32EndScene2, DWCi_SceneSetEdit32EndScene3, DWCi_SceneSetEdit32DrawSsid, DWCi_SceneSetEdit32DispCaret, DWCi_SceneSetEdit32ProcWin, DWCi_SceneSetEdit32ProcWin1, DWCi_SceneSetEdit32IsCorrect, DWCi_SceneSetEdit32ProcError, DWCi_SceneSetEdit32ProcError1
 * address:  0x021C6588
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Call input, DWCi_SceneSetEdit32_draw.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetEdit32_procScene.c \
 *       --func DWCi_SceneSetEdit32_procScene --addr 0x021C686C --region ov016 --cc dsi/1.1p1 --arm
 * closed (lane27, 2026-10-01): a plain `switch (c)` over 0, 0x80, 0x82, 0x83 plus one more
 *   case label sharing the default body (`case 0xFF: default:`). The extra label is a third
 *   case group above the 0x80..0x83 cluster, so mwcc roots the compare tree at the cluster
 *   (cmp #0x83 / bgt, cmp #0x80 / blt low / beq) and emits the 0 test as the left subtree
 *   after the chain; the right leaf targets default, so its compare folds away and bgt goes
 *   straight to the default body. Any value above 0x84 gives the same bytes (0x84 joins the
 *   cluster); 0xFF is the keyboard code procInit2 tests. Default test is `pos != 32`.
 *   The DWARF of input has no local at all; `c` is kept as the switch value holder.
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetedit32.o), symbol input (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *   python tools/match.py one --src src/pending/ov_sdk/ov016_func_021C687C.c \
 *       --func input --addr 0x021C687C --region ov016 --cc 1.1p1 --arm --lang c99
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneSetEdit32_draw.c \
 *       --func DWCi_SceneSetEdit32_draw --addr 0x021C6A0C --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_CEINlSetExObj               0x021D5368  arm
 *   DWCi_CMNlLoadResource            0x021BD1D4  arm
 *   DWCi_CMNlStep                    0x021BD214  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_FNTlClear                   0x021D5F14  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_FNTlDrawRect                0x021D5E5C  arm
 *   DWCi_FNTlFormBgEx                0x021D5A58  arm
 *   DWCi_FNTlRenewBg                 0x021D5FC4  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_GetParam2_                  0x021C0EA0  arm
 *   DWCi_HEAPlAllocEx                0x021D6414  arm
 *   DWCi_HEAPlFree_                  0x021D6438  arm
 *   DWCi_HLlLoad                     0x021BD674  arm
 *   DWCi_KB10lEnd                    0x021BF6B0  arm
 *   DWCi_KBlEnd                      0x021BDC24  arm
 *   DWCi_KBlGet                      0x021BDC54  arm
 *   DWCi_KBlIsInit                   0x021BDC90  arm
 *   DWCi_KBlSetErase                 0x021BDC68  arm
 *   DWCi_KBlSetInput                 0x021BDC7C  arm
 *   DWCi_OBJlDelete                  0x021D6F38  arm
 *   DWCi_SETTINGlGetSsid             0x021CF684  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_STRlNLen                    0x021D7200  arm
 *   DWCi_SceneSetApList              0x021C50D4  arm
 *   DWCi_SceneSetList                0x021C82FC  arm
 *   DWCi_SceneSetTestConfirm         0x021CD80C  arm
 *   DWCi_SetParam2_                  0x021C0E8C  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   GX_LoadOBJPltt                   0x0207E51C  arm
 *   MemSse                           0x021DE5E0  data
 *   X_IPT                            0x021DA5B2  data
 *   Y_IPT                            0x021DA5AC  data
 *   initGraphics                     0x021C66A8  arm
 *   procInit1                        0x021C67CC  arm
 *   procScene                        0x021C686C  arm
 *   scenesetedit32_bss               0x021DE5E0  data
 *   scenesetedit32_init_20570        0x021DA5A8  data
 *   scenesetedit32_init_20639        0x021DA5C4  data
 *   scenesetedit32_init_20694        0x021DB450  data
 *   scenesetedit32_str_20937         0x021DB4B0  data
 *   sSceneSetEdit32PathYbObjKbPltt    0x021DB458  data
 *   GX_LoadOBJPltt    0x0207E51C  data
 *   sSceneSetEdit32PathJbBgStep3Char    0x021DB46C  data
 *   GX_LoadBG2Char    0x0207F0B8  data
 *   sSceneSetEdit32PathYbBgStep3Pltt    0x021DB484  data
 *   GX_LoadBGPltt    0x0207E3D0  data
 *   sSceneSetEdit32PathXb4EditScr    0x021DB49C  data
 *   GX_LoadBG2Scr    0x0207EB78  data
 *   DWCi_KBlInit  0x021BD8D8  arm
 *   gMemSse     0x021DE5E0  data
 *   procInit2  0x021C684C  arm
 *   DWCi_EFFlWait                0x021D5790  arm
 */
typedef _Bool bool;

/* scenesetedit32.o was built with plain char unsigned (ldrb and unsigned compares on
   the DWARF `char` data): every DWARF `char` below is written `unsigned char`. */

typedef struct tagAREA { unsigned short l, t, w, h; } AREA;

typedef struct { unsigned long attr01; unsigned short attr2; unsigned short _3; } GXOamAttr;

typedef struct tagMEMSSE {
    void          *canv;              /* 0x00 */
    GXOamAttr     *caret;             /* 0x04 */
    unsigned char  ssid[33];          /* 0x08 */
    unsigned char  pos;               /* 0x29 */
    unsigned char  choose;            /* 0x2A */
} MEMSSE;

typedef struct { MEMSSE *MemSse; } SCENESETEDIT32_BSS;

/* the local initialisers, the compiler's @NNNNN objects, copied by struct assignment */
typedef struct { unsigned char v[2]; } SSE_MSG2;

typedef struct { int v[2]; } SSE_MSG;

typedef struct { void (*v[2])(unsigned char *); } SSE_FUNC;

typedef unsigned short u16;

typedef unsigned char u8;

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_HEAPlFree_(void **mem);
extern void DWCi_GetParam2_(void **param2, void **param3);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SetParam2_(unsigned int a, unsigned int b);
extern void DWCi_SETTINGlGetSsid(unsigned char *buf);
extern int DWCi_STRlNLen(unsigned char *s, int maxlen);
extern void DWCi_HLlLoad(int idx);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_CMNlStep(int step);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void GX_LoadOBJPltt(void *src, unsigned long offset, unsigned long size);
extern void *DWCi_FNTlFormBgEx(int lcd, int font);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern void DWCi_FNTlClear(void *canvas, int color);
extern void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, unsigned long flag, unsigned short *txt);
extern void DWCi_FNTlRenewBg(void *canvas);
extern GXOamAttr *DWCi_CEINlSetExObj(int lcd, int idx);
extern void DWCi_OBJlDelete(GXOamAttr *obj);
extern int DWCi_KBlGet(void);
extern void DWCi_KBlSetErase(bool enable);
extern void DWCi_KBlSetInput(bool enable);
extern void DWCi_KBlEnd(void);
extern void DWCi_KB10lEnd(void);
extern bool DWCi_KBlIsInit(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern int DWCi_WINlGet(void);
extern void DWCi_WINlEnd(void);
extern bool DWCi_WINlIsInit(void);
extern void DWCi_SNDlPlay(int no);
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_ChangeScene(void (*scene)(void));
extern void DWCi_SceneSetList(void);
extern void DWCi_SceneSetApList(void);
extern void DWCi_SceneSetTestConfirm(void);
extern void DWCi_KBlInit(void);
extern void DWCi_EFFlWait(int lcd);
void DWCi_SceneSetEdit32(void);
void DWCi_SceneSetEdit32_procScene(void);
void DWCi_SceneSetEdit32_draw(void);
/* scenesetedit32.o .bss at 0x021DE5E0, its only member the file static MemSse. The object
   reaches a static through the section symbol, and takes &MemSse through the variable's own
   symbol (a second pool word): endScene3 reads through the section and frees &MemSse. */
extern MEMSSE *MemSse;
extern SCENESETEDIT32_BSS scenesetedit32_bss;
/* scenesetedit32.o .rodata */
extern const unsigned char Y_IPT[2];
extern const unsigned char X_IPT[16];
extern const SSE_MSG2 scenesetedit32_init_20570;
extern const SSE_MSG scenesetedit32_init_20639;
extern const SSE_FUNC scenesetedit32_init_20694;
extern char scenesetedit32_str_20937[];
extern unsigned short sSceneSetEdit32PathYbObjKbPltt[];
extern unsigned short sSceneSetEdit32PathJbBgStep3Char[];
extern unsigned short GX_LoadBG2Char[];
extern unsigned short sSceneSetEdit32PathYbBgStep3Pltt[];
extern unsigned short GX_LoadBGPltt[];
extern unsigned short sSceneSetEdit32PathXb4EditScr[];
extern unsigned short GX_LoadBG2Scr[];
extern u8  *gMemSse;


static void procScene(void);


static inline void G2_SetOBJEffect(GXOamAttr *oam, int effect, int affine)
{
    oam->attr01 = (oam->attr01 & ~(0x0300 | 0x3E000000)) | effect | (affine << 25);
}


static inline void G2_SetOBJPosition(GXOamAttr *oam, int x, int y)
{
    oam->attr01 = (oam->attr01 & 0xFE00FF00) | (y & 0xFF) | ((x & 0x1FF) << 16);
}


static inline void G2_SetOBJPriority(GXOamAttr *oam, int priority)
{
    oam->attr2 = (unsigned short)((oam->attr2 & ~0xC00) | (priority << 10));
}

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void input(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
static void endScene3(void);
static void drawSsid(void);
static void dispCaret(void);
static void procWin(void);
static void procWin1(void);
static bool isCorrect(void);
static void procError(void);
static void procError1(void);


void DWCi_SceneSetEdit32(void)
{
    int prm;
    int sce;
    SSE_MSG2 MSG = scenesetedit32_init_20570;

    MemSse = DWCi_HEAPlAllocEx(sizeof(MEMSSE), 4);
    DWCi_GetParam2_((void **)&prm, (void **)&sce);
    if (prm == 0) {
        DWCi_SETTINGlGetSsid(MemSse->ssid);
        MemSse->pos = DWCi_STRlNLen(MemSse->ssid, 32);
    }
    initGraphics();
    DWCi_HLlLoad(prm + 9);
    if (sce == 1)
        DWCi_COMMENTlDispEx(0x35, -1, 0);
    else
        DWCi_COMMENTlDispEx(MSG.v[prm], -1, 0);
    DWCi_CMNlStep(2);
    MemSse->canv = DWCi_FNTlFormBgEx(0, 0);
    MemSse->caret = DWCi_CEINlSetExObj(0, 0x3E);
    G2_SetOBJPriority(MemSse->caret, 3);
    dispCaret();
    drawSsid();
    DWCi_ChangeScene(procInit);
}


static void initGraphics(void)
{
    u16 *p;

    DWCi_CMNlLoadResource((char *)((int)sSceneSetEdit32PathYbObjKbPltt), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadOBJPltt));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetEdit32PathJbBgStep3Char), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Char));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetEdit32PathYbBgStep3Pltt), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBGPltt));
    DWCi_CMNlLoadResource((char *)((int)sSceneSetEdit32PathXb4EditScr), (void (*)(void *, long unsigned int,  long unsigned int))((int)GX_LoadBG2Scr));
    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x04000008;
    p[0] = (p[0] & ~3) | 2;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}


static void procInit(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene(procInit1);
}


static void procInit1(void)
{
    u8 *p;

    if (DWCi_EFFlCheck(1) != 0)
        return;
    if (DWCi_EFFlCheck(0) != 0)
        return;
    DWCi_KBlInit();
    DWCi_SNDlPlay(0x14);
    p = gMemSse;
    if (p[0x29] == 0)
        DWCi_KBlSetErase(0);
    p = gMemSse;
    if (p[0x29] == 0x20)
        DWCi_KBlSetInput(0);
    DWCi_ChangeScene(procInit2);
}


static void procInit2(void)
{
    if (DWCi_KBlGet() == 0xFF)
        return;
    DWCi_ChangeScene(procScene);
}


void DWCi_SceneSetEdit32_procScene(void)
{
    input();
    DWCi_SceneSetEdit32_draw();
}

static void input(void)
{
    int c = DWCi_KBlGet();

    switch (c) {
    case 0:
        break;
    case 0x80:
        if (MemSse->pos > 0) {
            DWCi_SNDlPlay(3);
            MemSse->pos--;
            MemSse->ssid[MemSse->pos] = 0;
            if (MemSse->pos == 0)
                DWCi_KBlSetErase(0);
            DWCi_KBlSetInput(1);
        }
        break;
    case 0x82:
        DWCi_SNDlPlay(7);
        MemSse->choose = 0;
        DWCi_ChangeScene(endScene);
        return;
    case 0x83:
        if (isCorrect()) {
            DWCi_SNDlPlay(6);
            MemSse->choose = 1;
        } else {
            MemSse->choose = 2;
            DWCi_SNDlPlay(9);
        }
        G2_SetOBJEffect(MemSse->caret, 0x200, 0);
        DWCi_ChangeScene(endScene);
        return;
    case 0xFF:
    default:
        if (MemSse->pos != 32) {
            DWCi_SNDlPlay(1);
            MemSse->ssid[MemSse->pos] = c;
            MemSse->pos++;
            DWCi_KBlSetErase(1);
            if (MemSse->pos == 32)
                DWCi_KBlSetInput(0);
        }
        break;
    }
    drawSsid();
    dispCaret();
}

void DWCi_SceneSetEdit32_draw(void)
{
}


static void endScene(void)
{
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}


static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_KBlEnd();
    DWCi_SNDlPlay(0x15);
    DWCi_ChangeScene(endScene2);
}


static void endScene2(void)
{
    SSE_MSG MSG = scenesetedit32_init_20639;
    int sce;

    if (DWCi_KBlIsInit())
        return;
    if (MemSse->choose == 0) {
        DWCi_ChangeScene(endScene3);
        return;
    }
    if (MemSse->choose == 2) {
        DWCi_WINlInitEx(6, 3, 1, -1, 0);
        DWCi_ChangeScene(procError);
        return;
    }
    DWCi_GetParam2_(0, (void **)&sce);
    DWCi_WINlInitEx(MSG.v[sce], 2, 1, -1, 0);
    DWCi_ChangeScene(procWin);
}


static void endScene3(void)
{
    int p;
    int s;

    DWCi_COMMENTlDelete();
    DWCi_OBJlDelete(scenesetedit32_bss.MemSse->caret);
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_CMNlLoadResource(scenesetedit32_str_20937, GX_LoadOBJPltt);
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_GetParam2_((void **)&p, (void **)&s);
    if (s == 0) {
        DWCi_SetParam_(2, 1);
        DWCi_SetParam2_(0, p);
        DWCi_ChangeScene(DWCi_SceneSetList);
    } else if (scenesetedit32_bss.MemSse->choose == 0) {
        DWCi_SetParam_(0, 1);
        DWCi_SetParam2_(1, 0);
        DWCi_ChangeScene(DWCi_SceneSetApList);
    } else {
        DWCi_SetParam_(0, 0);
        DWCi_SetParam2_(0, 1);
        DWCi_ChangeScene(DWCi_SceneSetTestConfirm);
    }
    DWCi_HEAPlFree_((void **)&MemSse);
}


static void drawSsid(void)
{
    AREA a = { 0 };
    int x;
    int i;
    unsigned short buf[2];

    a.t = 32;
    a.w = 14;
    a.h = 16;
    DWCi_FNTlClear(MemSse->canv, 0);
    buf[1] = 0;
    for (i = 0, x = 0; i < 32; i++, x++) {
        if (i == 16) {
            x = 0;
            a.t = 49;
        }
        if (MemSse->ssid[i] == ' ')
            buf[0] = 0xE01D;
        else
            buf[0] = MemSse->ssid[i];
        a.l = X_IPT[x];
        DWCi_FNTlDrawRect(MemSse->canv, a.l, a.t, a.w, a.h, 2, 0x480, buf);
    }
    DWCi_FNTlRenewBg(MemSse->canv);
}


static void dispCaret(void)
{
    int y;
    int x;

    x = MemSse->pos & 15;
    y = MemSse->pos >> 4;
    if (MemSse->pos >= 32) {
        y = 1;
        x = 15;
    }
    G2_SetOBJPosition(MemSse->caret, X_IPT[x], Y_IPT[y]);
}


static void procWin(void)
{
    MemSse->choose = DWCi_WINlGet();
    switch (MemSse->choose) {
    case 0:
        DWCi_SNDlPlay(7);
        break;
    case 1:
        DWCi_SNDlPlay(14);
        break;
    default:
        return;
    }
    DWCi_WINlEnd();
    DWCi_ChangeScene(procWin1);
}


static void procWin1(void)
{
    SSE_FUNC FUNC = scenesetedit32_init_20694;
    int prm;

    if (DWCi_WINlIsInit())
        return;
    if (MemSse->choose == 0) {
        G2_SetOBJEffect(MemSse->caret, 0, 0);
        DWCi_ChangeScene(procInit1);
        return;
    }
    DWCi_GetParam2_((void **)&prm, 0);
    FUNC.v[prm](MemSse->ssid);
    DWCi_ChangeScene(endScene3);
}


static bool isCorrect(void)
{
    unsigned char c;
    int i;
    int prm;
    int sce;
    int len;

    DWCi_GetParam2_((void **)&prm, (void **)&sce);
    if (sce == 1)
        DWCi_COMMENTlDispEx(0x35, -1, 0);
    DWCi_GetParam2_((void **)&prm, (void **)&sce);
    if (prm == 0)
        return MemSse->ssid[0] != 0;
    if (sce == 1 && MemSse->ssid[0] == 0)
        return 0;
    len = DWCi_STRlNLen(MemSse->ssid, 32);
    switch (len) {
    case 0:
    case 5:
    case 13:
    case 16:
        return 1;
    case 10:
    case 26:
    case 32:
        for (i = 0; i < len; i++) {
            c = MemSse->ssid[i];
            if (c >= '0' && c <= '9')
                continue;
            if (c >= 'A' && c <= 'F')
                continue;
            if (c >= 'a' && c <= 'f')
                continue;
            return 0;
        }
        return 1;
    }
    return 0;
}


static void procError(void)
{
    if (DWCi_WINlGet() != 0)
        return;
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_ChangeScene(procError1);
}


static void procError1(void)
{
    if (DWCi_WINlIsInit())
        return;
    G2_SetOBJEffect(MemSse->caret, 0, 0);
    DWCi_ChangeScene(procInit1);
}

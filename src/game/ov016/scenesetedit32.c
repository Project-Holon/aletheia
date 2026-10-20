/*
 * file:     scenesetedit32.c
 * unit:     yes
 * function: DWCi_SceneSetEdit32, initGraphics, procInit, procInit1, procInit2, DWCi_SceneSetEdit32_procScene, input, DWCi_SceneSetEdit32_draw, endScene, endScene1, endScene2, endScene3, drawSsid, dispCaret, procWin, procWin1, isCorrect, procError, procError1
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
 *   scenesetedit32_bss               0x021DE5E0  data
 *   scenesetedit32_init_20570        0x021DA5A8  data
 *   scenesetedit32_init_20639        0x021DA5C4  data
 *   scenesetedit32_init_20694        0x021DB450  data
 *   scenesetedit32_str_20937         0x021DB4B0  data
 *   sSceneSetEdit32PathYbObjKbPltt    0x021DB458  data
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

#include "dwcutil_types.h"
#include "../sdk_ioreg.h"

#include "gx_oam_types.h"

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

#include "../types.h"

#include "heap.h"
#include "dwcutil_main.h"
#include "setting.h"
#include "str.h"
#include "headline.h"
#include "comment.h"
#include "common.h"
#include "../arm9/gx_load2d.h"
typedef int bool_0;
#include "font.h"
struct Canvas;
#include "cellinfo.h"
#include "obj.h"
#include "keyboard.h"
#include "keyboard10.h"
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
#include "window.h"
#include "sound.h"
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
#include "graphics.h"
#include "scenesetlist.h"
#include "scenesetaplist.h"
#include "scenesettestconfirm.h"
extern bool DWCi_EFFlWait(int lcd);
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
extern unsigned short sSceneSetEdit32PathYbBgStep3Pltt[];
extern unsigned short sSceneSetEdit32PathXb4EditScr[];
extern u8  *gMemSse;


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
    DWCi_GetParam2_((u32 *)&prm, (u32 *)&sce);
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
    DWCi_ChangeScene((uptr)procInit);
}

static void initGraphics(void)
{
    u16 *p;

    DWCi_CMNlLoadResource((char *)((sptr)sSceneSetEdit32PathYbObjKbPltt), GX_LoadOBJPltt);
    DWCi_CMNlLoadResource((char *)((sptr)sSceneSetEdit32PathJbBgStep3Char), GX_LoadBG2Char);
    DWCi_CMNlLoadResource((char *)((sptr)sSceneSetEdit32PathYbBgStep3Pltt), GX_LoadBGPltt);
    DWCi_CMNlLoadResource((char *)((sptr)sSceneSetEdit32PathXb4EditScr), GX_LoadBG2Scr);
    p = (u16 *)REG_DB_BG0CNT_ADDR;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)REG_BG0CNT_ADDR;
    p[0] = (p[0] & ~3) | 2;
    p = (u16 *)REG_BG1CNT_ADDR;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}

static void procInit(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene((uptr)procInit1);
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
    DWCi_ChangeScene((uptr)procInit2);
}

static void procInit2(void)
{
    if (DWCi_KBlGet() == 0xFF)
        return;
    DWCi_ChangeScene((uptr)DWCi_SceneSetEdit32_procScene);
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
        DWCi_ChangeScene((uptr)endScene);
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
        DWCi_ChangeScene((uptr)endScene);
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
    DWCi_ChangeScene((uptr)endScene1);
}

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_KBlEnd();
    DWCi_SNDlPlay(0x15);
    DWCi_ChangeScene((uptr)endScene2);
}

static void endScene2(void)
{
    SSE_MSG MSG = scenesetedit32_init_20639;
    int sce;

    if (DWCi_KBlIsInit())
        return;
    if (MemSse->choose == 0) {
        DWCi_ChangeScene((uptr)endScene3);
        return;
    }
    if (MemSse->choose == 2) {
        DWCi_WINlInitEx(6, 3, 1, -1, 0);
        DWCi_ChangeScene((uptr)procError);
        return;
    }
    DWCi_GetParam2_((u32 *)0, (u32 *)&sce);
    DWCi_WINlInitEx(MSG.v[sce], 2, 1, -1, 0);
    DWCi_ChangeScene((uptr)procWin);
}

static void endScene3(void)
{
    int p;
    int s;

    DWCi_COMMENTlDelete();
    DWCi_OBJlDelete((unsigned int *)scenesetedit32_bss.MemSse->caret);
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_CMNlLoadResource(scenesetedit32_str_20937, GX_LoadOBJPltt);
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_GetParam2_((u32 *)&p, (u32 *)&s);
    if (s == 0) {
        DWCi_SetParam_(2, 1);
        DWCi_SetParam2_(0, p);
        DWCi_ChangeScene((uptr)DWCi_SceneSetList);
    } else if (scenesetedit32_bss.MemSse->choose == 0) {
        DWCi_SetParam_(0, 1);
        DWCi_SetParam2_(1, 0);
        DWCi_ChangeScene((uptr)DWCi_SceneSetApList);
    } else {
        DWCi_SetParam_(0, 0);
        DWCi_SetParam2_(0, 1);
        DWCi_ChangeScene((uptr)DWCi_SceneSetTestConfirm);
    }
    DWCi_HEAPlFree_((void **)&MemSse);
}

static void drawSsid(void)
{
    AREA a = { 0 };
    int x;
    int i;
    unsigned short buf[2];

    a.y = 32;
    a.w = 14;
    a.h = 16;
    DWCi_FNTlClear(MemSse->canv, 0);
    buf[1] = 0;
    for (i = 0, x = 0; i < 32; i++, x++) {
        if (i == 16) {
            x = 0;
            a.y = 49;
        }
        if (MemSse->ssid[i] == ' ')
            buf[0] = 0xE01D;
        else
            buf[0] = MemSse->ssid[i];
        a.x = X_IPT[x];
        DWCi_FNTlDrawRect(MemSse->canv, a.x, a.y, a.w, a.h, 2, 0x480, buf);
    }
    DWCi_FNTlRenewBg((sptr)MemSse->canv);
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
    DWCi_ChangeScene((uptr)procWin1);
}

static void procWin1(void)
{
    SSE_FUNC FUNC = scenesetedit32_init_20694;
    int prm;

    if (DWCi_WINlIsInit())
        return;
    if (MemSse->choose == 0) {
        G2_SetOBJEffect(MemSse->caret, 0, 0);
        DWCi_ChangeScene((uptr)procInit1);
        return;
    }
    DWCi_GetParam2_((u32 *)&prm, 0);
    FUNC.v[prm](MemSse->ssid);
    DWCi_ChangeScene((uptr)endScene3);
}

static bool isCorrect(void)
{
    unsigned char c;
    int i;
    int prm;
    int sce;
    int len;

    DWCi_GetParam2_((u32 *)&prm, (u32 *)&sce);
    if (sce == 1)
        DWCi_COMMENTlDispEx(0x35, -1, 0);
    DWCi_GetParam2_((u32 *)&prm, (u32 *)&sce);
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
    DWCi_ChangeScene((uptr)procError1);
}

static void procError1(void)
{
    if (DWCi_WINlIsInit())
        return;
    G2_SetOBJEffect(MemSse->caret, 0, 0);
    DWCi_ChangeScene((uptr)procInit1);
}

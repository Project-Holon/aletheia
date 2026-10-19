/*
 * file:     scenesetselectap.c
 * unit:     yes
 * function: DWCi_SceneSetSelectAp, initGraphics, initObj, procInit, procInit1, procInit2, procScene, input, draw, button, endScene, endScene1, endScene2, dispFocus, moveFocus, dispPushClear, procErase, procErase1, dispPush
 * address:  0x021CBC90
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetselectap), symbol procInit2 (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CBFA8.c \
 *       --func procInit2 --addr 0x021CBFA8 --region ov016 --cc 1.1p1 --arm --lang c99
 * Call input, draw, button.
 * Addresses are Black-image addresses.
 *   python tools/match.py one --src src/matched/DWCi_SceneSetSelectAp_procScene.c \
 *       --func procScene --addr 0x021CBFD8 --region ov016 --cc dsi/1.1p1 --arm
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetselectap), symbol input (name and prototype from the vendor object DWARF).
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CBFEC.c \
 *       --func input --addr 0x021CBFEC --region ov016 --cc 1.1p1 --arm --lang c99
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/draw.c \
 *       --func draw --addr 0x021CC0E4 --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   GX_LoadBGPltt                  0x0207E3D0  arm  arm9
 *   GX_LoadBG2Scr                  0x0207EB78  arm  arm9
 *   GX_LoadBG2Char                 0x0207F0B8  arm  arm9
 *   initGraphics 0x021CBCF0  arm  ov016
 *   DWCi_SceneSetSelectAp  0x021CBC90  arm
 *   DWCi_HEAPlAllocEx                0x021d6414 arm
 *   DWCi_HLlLoad                     0x021bd674 arm
 *   DWCi_COMMENTlDispEx              0x021bd060 arm
 *   DWCi_CMNlStep                    0x021bd214 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   scenesetselectap_bss             0x021de60c data
 *   DWCi_CMNlLoadResource   0x021BD1D4  arm  ov016
 *   DWCi_Char   0x021BD170  arm  ov016
 *   DWCi_ARClReadEx   0x021D4B68  arm  ov016
 *   DWCi_GXlVisible   0x021D603C  arm  ov016
 *   sSceneSetSelectApPathYbBgStep11Pltt   0x021DA7BC  data
 *   sSceneSetSelectApPathYbObjWayPltt   0x021DB708  data
 *   GX_LoadOBJPltt   0x0207E51C  data
 *   sSceneSetSelectApPathJbBgStep1Char   0x021DB71C  data
 *   sSceneSetSelectApPathJbBgStep1Pltt   0x021DB734  data
 *   sSceneSetSelectApPathJb2ApScr   0x021DB74C  data
 *   DWCi_SETTINGlGetSetType  0x021CF7F4 arm   ov016
 *   DWCi_CEINlSetExCell  0x021D5394 arm   ov016
 *   DWCi_CELLlSetPosition  0x021D5118 arm   ov016
 *   DWCi_CELLlSetPriority  0x021D51F0 arm   ov016
 *   C_CELL    0x021DA72C data
 *   sSceneSetSelectApCellTypes    0x021DA720 data
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_BTNlGet                     0x021bcb14 arm
 *   DWCi_STEPlGet                    0x021d0684 arm
 *   DWCi_BTNlEnable                  0x021bcb84 arm
 *   DWCi_TPlCheckTrigger             0x021d696c arm
 *   DWCi_BTNlSet                     0x021bcb28 arm
 *   DWCi_IPTlCheckTrigger            0x021d6824 arm
 *   DWCi_IPTlCheckRepeat             0x021d6864 arm
 *   R_TOUCH                          0x021da744 data
 *   FocusPos                         0x021de60c data
 *   DWCi_Entry                       0x021C0ED8  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlSetForce                0x021BCB44  arm
 *   DWCi_Language                    0x021C0EC8  arm
 *   DWCi_WINlInitEx                  0x021D1208  arm
 *   DWCi_SETTINGlSetSetting          0x021CF80C  arm
 *   DWCi_SceneEnd                    0x021C1630  arm
 *   sSceneSetSelectApMessageByLanguage                       0x021DA724  data
 *   DWCi_STEPlEnd                    0x021d0580 arm
 *   DWCi_EFFlWait                    0x021d5790 arm
 *   DWCi_SETTIGNlGet                 0x021cf404 arm
 *   DWCi_BTNlEnd                     0x021bcae4 arm
 *   DWCi_STEPlIsEnd  0x021D0A84  arm  ov016
 *   DWCi_BTNlIsEnd  0x021BCB58  arm  ov016
 *   DWCi_CELLlDelete  0x021D4F60  arm  ov016
 *   DWCi_FOCUSlDelete  0x021BD5A8  arm  ov016
 *   DWCi_COMMENTlDelete  0x021BD138  arm  ov016
 *   DWCi_ARClRelease  0x021D4C68  arm  ov016
 *   DWCi_GXlInvisible  0x021D6090  arm  ov016
 *   DWCi_SetParam_  0x021C0E50  arm  ov016
 *   DWCi_SetParam2_  0x021C0E8C  arm  ov016
 *   DWCi_SetListReturn  0x021CA5C0  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   DWCi_SceneMenu  0x021C1984  arm  ov016
 *   DWCi_SceneSetSelectWay  0x021CC998  arm  ov016
 *   DWCi_SceneSetList  0x021C82FC  arm  ov016
 *   DWCi_SceneSetUsbReady  0x021CDCAC  arm  ov016
 *   sSceneSetSelectApFocusPos  0x021DE610  data
 *   DWCi_FOCUSlDisp4                 0x021bd4c8 arm
 *   DWCi_FOCUSlDisp                  0x021bd41c arm
 *   R_FOCUS                          0x021da77c data
 *   dispFocus  0x021CC46C  arm  ov016
 *   DWCi_CELLlGetObj                 0x021d4fe0 arm
 *   DWCi_CEINlSet                    0x021d52d4 arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_SETTINGlErasePage           0x021CFBE4  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   sSceneSetSelectApCellPosY                       0x021DA72E  data
 *   DWCi_WINlIsInit                  0x021d157c arm
 *   DWCi_SCREENlCopyPalette          0x021ce7b0 arm
 *   DWCi_CELLlSetPalette             0x021d5098 arm
 *   sSceneSetSelectApBgPalette                      0x021da7b4 data
 *   sSceneSetSelectApObjPalette                      0x021da7b8 data
 *   @21063  0x021DB760  data
 */
#define NELEMS(a) (sizeof(a) / sizeof((a)[0]))
typedef _Bool bool;

typedef struct tagMEMSSSA {
    void *arc;                        /* 0x00 */
    void *cellA[3];                   /* 0x04 */
    void *cellB[3];                   /* 0x10 */
    unsigned char column;             /* 0x1C */
    unsigned char mode;               /* 0x1D */
} MEMSSSA;

/* scenesetselectap.o .bss at 0x021DE60C */
typedef struct {
    unsigned char FocusPos;           /* 0x00 */
    MEMSSSA *MemSssa;                 /* 0x04 */
} SCENESETSELECTAP_BSS;

#include "../types.h"

typedef struct {
    char name[0x14];
    u8 pad14;
    u8 pad15;
} T22;

typedef struct tagCOORD { unsigned short x, y; } COORD;

typedef struct Rect {
    unsigned short left, top, right, bottom;
} Rect;

typedef struct tagSETTINGINFO {
    unsigned char pad[0xE7];
    unsigned char setting;            /* 0xE7 */
} SETTINGINFO;

#include "gx_oam_types.h"

/* the compiler's g_021DA7B4and g_021DA7B8initialisers, each in its own .rodata section */
typedef struct { unsigned char v[4]; } PLT4;

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void DWCi_HLlLoad(int idx);
extern int DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_CMNlStep(int step);
extern void DWCi_ChangeScene(void (*scene)(void));
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned char *DWCi_Char(unsigned char *name);
extern void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment);
extern void *DWCi_CEINlSetExCell(int lcd, int idx, int head);
extern void GX_LoadOBJPltt(void *, unsigned long, unsigned long);
extern void GX_LoadBG2Char(void *, unsigned long, unsigned long);
extern void GX_LoadBGPltt(void *, unsigned long, unsigned long);
extern void GX_LoadBG2Scr(void *, unsigned long, unsigned long);
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_CMNlButton(int kind);
extern s8 DWCi_BTNlGet(void);
extern int DWCi_STEPlGet(void);
extern void DWCi_BTNlEnable(void);
extern int DWCi_TPlCheckTrigger(unsigned short *a);
extern void DWCi_BTNlSet(s8 v);
extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern int DWCi_IPTlCheckRepeat(unsigned int f);
extern unsigned int DWCi_Entry(void);
extern void DWCi_SNDlPlay(u32 v);
extern void DWCi_BTNlDisable(void);
extern u8 DWCi_SETTINGlGetSetType(u32 i);
extern void DWCi_BTNlSetForce(int idx);
extern u8 DWCi_Language(void);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern void DWCi_SETTINGlSetSetting(int idx);
extern void DWCi_SceneEnd(void);
extern void DWCi_STEPlEnd(void);
extern bool DWCi_EFFlWait(int frame);
extern SETTINGINFO *DWCi_SETTIGNlGet(void);
extern void DWCi_BTNlEnd(void);
extern int DWCi_STEPlIsEnd(void);
extern int DWCi_BTNlIsEnd(void);
extern void DWCi_FOCUSlDelete(void);
extern int DWCi_COMMENTlDelete(void);
extern void DWCi_ARClRelease(void *file);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SetParam2_(unsigned int a, unsigned int b);
extern void DWCi_SetListReturn(unsigned char v);
extern void DWCi_HEAPlFree_(void **mem);
extern void DWCi_SceneMenu(void);
extern void DWCi_SceneSetSelectWay(void);
extern void DWCi_SceneSetList(void);
extern void DWCi_SceneSetUsbReady(void);
extern void DWCi_FOCUSlDisp4(int x0, int x1, int y0, int y1);
extern void DWCi_FOCUSlDisp(int kind, int x0, int x1, int y);
extern GXOamAttr *DWCi_CELLlGetObj(void *cell, int idx);
extern void DWCi_CEINlSet(int lcd, int idx, GXOamAttr *obj);
extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern void DWCi_CELLlSetPriority(void *cell, int idx, int priority);
extern s8 DWCi_WINlGet(void);
extern void DWCi_SETTINGlErasePage(int page);
extern void DWCi_CELLlDelete(void *cell);
extern void DWCi_WINlEnd(void);
extern int DWCi_WINlIsInit(void);
extern void DWCi_SCREENlCopyPalette(void *src, int sColor, int dColor);
extern void DWCi_CELLlSetPalette(unsigned char *obj, int idx, unsigned int v, unsigned int w);
void DWCi_SceneSetSelectAp(void);
extern SCENESETSELECTAP_BSS scenesetselectap_bss;
extern T22 sSceneSetSelectApPathYbBgStep11Pltt;
extern unsigned char sSceneSetSelectApPathYbObjWayPltt[];
extern unsigned char sSceneSetSelectApPathJbBgStep1Char[];
extern unsigned char sSceneSetSelectApPathJbBgStep1Pltt[];
extern unsigned char sSceneSetSelectApPathJb2ApScr[];
/* scenesetselectap.o .rodata at 0x021DA72C */
extern const COORD C_CELL[6];
extern unsigned char sSceneSetSelectApCellTypes[4];
/* scenesetselectap.o .rodata at 0x021DA744 */
extern const Rect R_TOUCH[7];
extern const s8 sSceneSetSelectApMessageByLanguage[7];
/* scenesetselectap.o .rodata at 0x021DA77C */
extern const Rect R_FOCUS[7];
extern const PLT4 sSceneSetSelectApBgPalette;
extern const PLT4 sSceneSetSelectApObjPalette;

static void initGraphics(void);
static void initObj(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void procScene(void);
static void input(void);
static void draw(void);
static void button(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
static void dispFocus(void);
static void moveFocus(int dir);
static void dispPushClear(void);
static void procErase(void);
static void procErase1(void);
static void dispPush(void);

void DWCi_SceneSetSelectAp(void)
{
    MEMSSSA *p = DWCi_HEAPlAllocEx(0x20, 4);

    scenesetselectap_bss.MemSssa = p;
    p->mode = 0;
    initGraphics();
    DWCi_HLlLoad(1);
    DWCi_COMMENTlDispEx(0x2f, -1, 0);
    DWCi_CMNlStep(0);
    initObj();
    dispFocus();
    DWCi_ChangeScene(procInit);
}

/*
 * Copy a 0x16-byte NCL resource path into a stack buffer, load four
 * tilemaps through DWCi_CMNlLoadResource, publish the buffer through
 * DWCi_Char/DWCi_ARClReadEx into the record held by 0x021DE60C+4, poke
 * DWCi_GXlVisible, then set the low two bits of the 0x04001008 and
 * 0x0400000A halfword pairs.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetSelectApInitGraphics.c \
 *       --func DWCi_SceneSetSelectApInitGraphics --addr 0x021CBCF0 --region ov016 --cc dsi/1.1p1 --arm
 */
static void initGraphics(void)
{
    T22 buf;
    u16 *p;
    void *r;

    buf = sSceneSetSelectApPathYbBgStep11Pltt;
    DWCi_CMNlLoadResource((char *)sSceneSetSelectApPathYbObjWayPltt, GX_LoadOBJPltt);
    DWCi_CMNlLoadResource((char *)sSceneSetSelectApPathJbBgStep1Char, GX_LoadBG2Char);
    DWCi_CMNlLoadResource((char *)sSceneSetSelectApPathJbBgStep1Pltt, GX_LoadBGPltt);
    DWCi_CMNlLoadResource((char *)sSceneSetSelectApPathJb2ApScr, GX_LoadBG2Scr);

    r = DWCi_ARClReadEx((char *)DWCi_Char((unsigned char *)&buf), 0, 4);
    scenesetselectap_bss.MemSssa->arc = r;
    DWCi_GXlVisible(1, 0x10);

    p = (u16 *)0x04001008;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
    p = (u16 *)0x0400000A;
    p[0] = (p[0] & ~3) | 3;
    p[1] = (p[1] & ~3) | 3;
}

/*
 * notes: EXACT at 264 bytes, 10/10 relocations.  The park's 3-line residue
 *        (+0050..+0058: the image computes the C_CELL index `lsl r2, r3, #2`
 *        before the cell store, the parked source after it) closes on the
 *        table's own qualifier: declaring C_CELL `extern const struct tagCOORD
 *        C_CELL[6]` instead of plain makes the load read through a const
 *        table and the front end hoists the scaled index above the store.
 *        Nothing else in the body moves: `j = i + 3` stays.
 *
 * sdk:      initObj (libdwcutil.TWL.HYB.a scenesetselectap.o)
 */
static void initObj(void)
{
    int j;
    int type;
    int i;

    for (i = 0; i < 3; i++) {
        type = DWCi_SETTINGlGetSetType(i);
        if (type == 0xff) {
            type = 3;
        } else {
            j = i + 3;
            scenesetselectap_bss.MemSssa->cellB[i] = DWCi_CEINlSetExCell(0, 0x11, 1);
            DWCi_CELLlSetPosition(scenesetselectap_bss.MemSssa->cellB[i], -1, C_CELL[j].x, C_CELL[j].y);
            DWCi_CELLlSetPriority(scenesetselectap_bss.MemSssa->cellB[i], -1, 3);
        }
        scenesetselectap_bss.MemSssa->cellA[i] = DWCi_CEINlSetExCell(0, sSceneSetSelectApCellTypes[type], 1);
        DWCi_CELLlSetPosition(scenesetselectap_bss.MemSssa->cellA[i], -1, C_CELL[i].x, C_CELL[i].y);
        DWCi_CELLlSetPriority(scenesetselectap_bss.MemSssa->cellA[i], -1, 3);
    }
}

static void procInit(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x14, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x14);
    DWCi_ChangeScene(procInit1);
}

static void procInit1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_CMNlButton(0);
    DWCi_ChangeScene(procInit2);
}

static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2) {
        return;
    }
    if (DWCi_STEPlGet() == 1) {
        return;
    }
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}

static void procScene(void)
{
    input();
    draw();
    button();
}

static void input(void)
{
    int i;

    for (i = 0; (unsigned int)i < 7; i++) {
        if (DWCi_TPlCheckTrigger((unsigned short *)&R_TOUCH[i])) {
            DWCi_BTNlSet(1);
            scenesetselectap_bss.FocusPos = i;
            dispFocus();
            return;
        }
    }
    if (DWCi_IPTlCheckTrigger(1)) {
        DWCi_BTNlSet(1);
    } else if (DWCi_IPTlCheckTrigger(2)) {
        DWCi_BTNlSet(0);
    } else if (DWCi_IPTlCheckRepeat(0x40)) {
        moveFocus(1);
    } else if (DWCi_IPTlCheckRepeat(0x80)) {
        moveFocus(3);
    } else if (DWCi_IPTlCheckRepeat(0x20)) {
        moveFocus(0);
    } else if (DWCi_IPTlCheckRepeat(0x10)) {
        moveFocus(2);
    }
}

static void draw(void)
{
}

static void button(void)
{
    int idx;
    int lang;

    switch (DWCi_BTNlGet()) {
    case 0:
        switch (DWCi_Entry()) {
        case 0:
            DWCi_SNDlPlay(7);
            scenesetselectap_bss.MemSssa->mode = 2;
            break;
        case 1:
            DWCi_BTNlDisable();
            DWCi_ChangeScene(DWCi_SceneEnd);
            return;
        }
        break;
    case 1:
        scenesetselectap_bss.MemSssa->mode = 1;
        if (scenesetselectap_bss.FocusPos >= 4) {
            idx = scenesetselectap_bss.FocusPos - 4;
            if (DWCi_SETTINGlGetSetType(idx) == 0xff) {
                DWCi_SNDlPlay(9);
                DWCi_BTNlSetForce(-1);
                return;
            }
            DWCi_SNDlPlay(6);
            lang = sSceneSetSelectApMessageByLanguage[DWCi_Language()];
            DWCi_WINlInitEx(0x46, 0, 1, lang, idx + 1);

            dispPushClear();
            DWCi_BTNlDisable();
            DWCi_ChangeScene(procErase);
            return;
        }
        if (scenesetselectap_bss.FocusPos <= 2)
            DWCi_SETTINGlSetSetting(scenesetselectap_bss.FocusPos);
        DWCi_SNDlPlay(6);
        dispPush();
        break;
    default:
        return;
    }
    DWCi_ChangeScene(endScene);
}

static void endScene(void)
{
    if (scenesetselectap_bss.MemSssa->mode == 2) {
        DWCi_STEPlEnd();
    }
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1)) {
        return;
    }
    if (scenesetselectap_bss.MemSssa->mode == 1) {
        if (scenesetselectap_bss.FocusPos == 3 || DWCi_SETTIGNlGet()->setting != 0xFF) {
            DWCi_BTNlEnd();
        }
    }
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x14, 8);
    DWCi_ChangeScene(endScene2);
}

/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a(scenesetselectap))
 */
static void endScene2(void)
{
    int i;

    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    if (!DWCi_STEPlIsEnd())
        return;
    if (!DWCi_BTNlIsEnd())
        return;

    for (i = 0; i < NELEMS(scenesetselectap_bss.MemSssa->cellA); i++) {
        if (scenesetselectap_bss.MemSssa->cellA[i])
            DWCi_CELLlDelete(scenesetselectap_bss.MemSssa->cellA[i]);
    }
    for (i = 0; i < NELEMS(scenesetselectap_bss.MemSssa->cellB); i++) {
        if (scenesetselectap_bss.MemSssa->cellB[i])
            DWCi_CELLlDelete(scenesetselectap_bss.MemSssa->cellB[i]);
    }
    DWCi_FOCUSlDelete();
    DWCi_COMMENTlDelete();
    DWCi_ARClRelease(scenesetselectap_bss.MemSssa->arc);
    DWCi_CMNlLoadResource("char/ybObjMain.ncl.l", GX_LoadOBJPltt);
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x14);

    if (scenesetselectap_bss.MemSssa->mode == 2) {
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene(DWCi_SceneMenu);
    } else {
        switch (scenesetselectap_bss.FocusPos) {
        case 0:
        case 1:
        case 2:
            DWCi_SetParam_(2, 0);
            if (DWCi_SETTIGNlGet()->setting == 0xff) {
                DWCi_ChangeScene(DWCi_SceneSetSelectWay);
            } else {
                DWCi_SetParam2_(0, 0);
                DWCi_SetListReturn(0);
                DWCi_ChangeScene(DWCi_SceneSetList);
            }
            break;
        case 3:
            DWCi_SetParam_(2, 1);
            DWCi_ChangeScene(DWCi_SceneSetUsbReady);
            break;
        }
    }
    DWCi_HEAPlFree_((void **)&scenesetselectap_bss.MemSssa);
}

static void dispFocus(void)
{
    if (scenesetselectap_bss.FocusPos < 4) {
        DWCi_FOCUSlDisp4(R_FOCUS[scenesetselectap_bss.FocusPos].left, R_FOCUS[scenesetselectap_bss.FocusPos].right, R_FOCUS[scenesetselectap_bss.FocusPos].top, R_FOCUS[scenesetselectap_bss.FocusPos].bottom);
    } else {
        DWCi_FOCUSlDisp(0, R_FOCUS[scenesetselectap_bss.FocusPos].left, R_FOCUS[scenesetselectap_bss.FocusPos].right, R_FOCUS[scenesetselectap_bss.FocusPos].top);
    }
}

/*
 * sdk:      moveFocus (libdwcutil.TWL.HYB.a(scenesetselectap))
 *
 * The DWARF lists
 * only move and clear; the object computes clear + 4 unconditionally before the
 * dir test, which the second local next reproduces.
 */
static void moveFocus(int dir)
{
    int clear;
    int next;
    int move = 1;

    switch (scenesetselectap_bss.FocusPos) {
    case 0:
        scenesetselectap_bss.MemSssa->column = 0;
        if (dir == 0)
            scenesetselectap_bss.FocusPos = 2;
        else if (dir == 2)
            scenesetselectap_bss.FocusPos = 1;
        else if (dir == 1)
            scenesetselectap_bss.FocusPos = 3;
        else
            scenesetselectap_bss.FocusPos = 4;
        break;
    case 1:
        scenesetselectap_bss.MemSssa->column = 1;
        if (dir == 0)
            scenesetselectap_bss.FocusPos = 0;
        else if (dir == 2)
            scenesetselectap_bss.FocusPos = 2;
        else if (dir == 1)
            scenesetselectap_bss.FocusPos = 3;
        else
            scenesetselectap_bss.FocusPos = 5;
        break;
    case 2:
        scenesetselectap_bss.MemSssa->column = 2;
        if (dir == 0)
            scenesetselectap_bss.FocusPos = 1;
        else if (dir == 2)
            scenesetselectap_bss.FocusPos = 0;
        else if (dir == 1)
            scenesetselectap_bss.FocusPos = 3;
        else
            scenesetselectap_bss.FocusPos = 6;
        break;
    case 3:
        clear = scenesetselectap_bss.MemSssa->column;
        next = clear + 4;
        if (dir == 1)
            scenesetselectap_bss.FocusPos = next;
        else if (dir == 3)
            scenesetselectap_bss.FocusPos = clear;
        else
            move = 0;
        break;
    case 4:
        scenesetselectap_bss.MemSssa->column = 0;
        if (dir == 0)
            scenesetselectap_bss.FocusPos = 6;
        else if (dir == 2)
            scenesetselectap_bss.FocusPos = 5;
        else if (dir == 1)
            scenesetselectap_bss.FocusPos = 0;
        else
            scenesetselectap_bss.FocusPos = 3;
        break;
    case 5:
        scenesetselectap_bss.MemSssa->column = 1;
        if (dir == 0)
            scenesetselectap_bss.FocusPos = 4;
        else if (dir == 2)
            scenesetselectap_bss.FocusPos = 6;
        else if (dir == 1)
            scenesetselectap_bss.FocusPos = 1;
        else
            scenesetselectap_bss.FocusPos = 3;
        break;
    case 6:
        scenesetselectap_bss.MemSssa->column = 2;
        if (dir == 0)
            scenesetselectap_bss.FocusPos = 5;
        else if (dir == 2)
            scenesetselectap_bss.FocusPos = 4;
        else if (dir == 1)
            scenesetselectap_bss.FocusPos = 2;
        else
            scenesetselectap_bss.FocusPos = 3;
        break;
    }
    if (move) {
        DWCi_SNDlPlay(8);
        dispFocus();
    }
}

static void dispPushClear(void)
{
    int fp = scenesetselectap_bss.FocusPos - 4;

    DWCi_CEINlSet(0, 0x32, DWCi_CELLlGetObj(scenesetselectap_bss.MemSssa->cellB[fp], 0));
    DWCi_CELLlSetPosition(scenesetselectap_bss.MemSssa->cellB[fp], -1, C_CELL[fp + 3].x, C_CELL[fp + 3].y);
    DWCi_CELLlSetPriority(scenesetselectap_bss.MemSssa->cellB[fp], -1, 3);
}

static void procErase(void)
{
    int ix;

    ix = scenesetselectap_bss.FocusPos - 4;
    switch (DWCi_WINlGet()) {
    case 1:
        DWCi_SNDlPlay(14);
        DWCi_SETTINGlErasePage(ix);
        DWCi_CEINlSet(0, 0x56, DWCi_CELLlGetObj(scenesetselectap_bss.MemSssa->cellA[ix], 0));
        DWCi_CELLlSetPosition(scenesetselectap_bss.MemSssa->cellA[ix], -1, C_CELL[ix].x, C_CELL[ix].y);
        DWCi_CELLlSetPriority(scenesetselectap_bss.MemSssa->cellA[ix], -1, 3);
        DWCi_CELLlDelete(scenesetselectap_bss.MemSssa->cellB[ix]);
        scenesetselectap_bss.MemSssa->cellB[ix] = 0;
        break;
    case 0:
        DWCi_SNDlPlay(7);
        DWCi_CEINlSet(0, 0x11, DWCi_CELLlGetObj(scenesetselectap_bss.MemSssa->cellB[ix], 0));
        DWCi_CELLlSetPosition(scenesetselectap_bss.MemSssa->cellB[ix], -1, C_CELL[ix + 3].x, C_CELL[ix + 3].y);
        DWCi_CELLlSetPriority(scenesetselectap_bss.MemSssa->cellB[ix], -1, 3);
        break;
    default:
        return;
    }
    DWCi_WINlEnd();
    DWCi_ChangeScene(procErase1);
}

static void procErase1(void)
{
    if (DWCi_WINlIsInit()) {
        return;
    }
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}

static void dispPush(void)
{
    PLT4 PALETTE = sSceneSetSelectApBgPalette;
    PLT4 OBJ_PLTT = sSceneSetSelectApObjPalette;
    int type = scenesetselectap_bss.FocusPos;

    if ((unsigned int)type > 3) {
        return;
    }
    DWCi_SCREENlCopyPalette(scenesetselectap_bss.MemSssa->arc, PALETTE.v[type], PALETTE.v[type]);
    if (scenesetselectap_bss.FocusPos == 3) {
        return;
    }
    type = DWCi_SETTINGlGetSetType(scenesetselectap_bss.FocusPos);
    if (type > 2) {
        type = 3;
    }
    DWCi_CELLlSetPalette(scenesetselectap_bss.MemSssa->cellA[scenesetselectap_bss.FocusPos], -1, 0, OBJ_PLTT.v[type]);
}

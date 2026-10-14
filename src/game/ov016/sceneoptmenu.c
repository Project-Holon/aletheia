/*
 * file:     sceneoptmenu.c
 * unit:     yes
 * function: DWCi_SceneOptMenu, initGraphics, procInit, procInit1, procInit2, DWCi_SceneOptMenu_procScene, input, DWCi_SceneOptMenu_draw, button, endScene, endScene1, endScene2, moveFocus, DWCi_SceneOptMenuDispPush
 * address:  0x021C2A3C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Call input, DWCi_SceneOptMenu_draw, button.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMenu_procScene.c \
 *       --func DWCi_SceneOptMenu_procScene --addr 0x021C2D60 --region ov016 --cc dsi/1.1p1 --arm
 * sdk:      input (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 *   python tools/match.py one --src src/matched/DWCi_SceneOptMenu_draw.c \
 *       --func DWCi_SceneOptMenu_draw --addr 0x021C2E68 --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   DWCi_HLlLoad  0x021BD674  arm
 *   DWCi_STEPlChangeScr  0x021D0AB0  arm
 *   DWCi_COMMENTlDispEx  0x021BD060  arm
 *   DWCi_CEINlSetExObj  0x021D5368  arm
 *   DWCi_FOCUSlDisp4  0x021BD4C8  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   gSceneOptMenuState     0x021DE5A8  data
 *   d_021DA4D0     0x021DA4D0  data
 *   d_021DA4D2     0x021DA4D2  data
 *   d_021DA4D4     0x021DA4D4  data
 *   d_021DA4D6     0x021DA4D6  data
 *   procInit  0x021C2C94  arm
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm  ov016
 *   DWCi_Char  0x021BD170  arm  ov016
 *   DWCi_ARClReadEx  0x021D4B68  arm  ov016
 *   DWCi_BM_GetWiFiInfo  0x02058518  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   GX_LoadBGPltt  0x0207E3D0  arm
 *   DWCi_ARClRelease  0x021D4C68  arm  ov016
 *   GX_LoadBG2Char 0x0207F0B8  arm
 *   GX_LoadBG2Scr  0x0207EB78  arm
 *   @20575         0x021DA4E8  data
 *   @20577         0x021DA500  data
 *   @20751         0x021DB338  data
 *   @20752         0x021DB350  data
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlSet                     0x021BCB28  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_IPTlCheckRepeat             0x021D6864  arm
 *   DWCi_IPTlCheckTrigger            0x021D6824  arm
 *   DWCi_SCREENlCopyPalette          0x021CE7B0  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_SceneEnd                    0x021C1630  arm
 *   DWCi_TPlCheckTrigger             0x021D696C  arm
 *   dispPushButton                   0x021C1EDC  arm
 *   scenemenu_bss                    0x021DE59C  data
 *   scenemenu_init_20658             0x021DA474  data
 *   scenemenu_rodata                 0x021DA478  data
 *   procScene                        0x021C2D60  arm
 *   gSceneOptMenuButtonRects  0x021DA4B8  data
 *   gSceneOptMenuFocusRects  0x021DA4D0  data
 *   g_021DA4D4  0x021DA4D4  data
 *   g_021DA4D2  0x021DA4D2  data
 *   g_021DA4D6  0x021DA4D6  data
 *   DWCi_BTNlSetForce  0x021BCB44  arm  ov016
 *   DWCi_BTNlEnd  0x021BCAE4  arm  ov016
 *   DWCi_BTNlIsEnd 0x021BCB58 arm ov016
 *   DWCi_OBJlDelete 0x021D6F38 arm ov016
 *   DWCi_FOCUSlDelete 0x021BD5A8 arm ov016
 *   DWCi_COMMENTlDelete 0x021BD138 arm ov016
 *   DWCi_GXlInvisible 0x021D6090 arm ov016
 *   DWCi_SetParam_ 0x021C0E50 arm ov016
 *   DWCi_SceneMenu 0x021C1984 arm ov016
 *   DWCi_SceneOptInfo 0x021C255C arm ov016
 *   DWCi_SceneOptErase 0x021C1F1C arm ov016
 *   DWCi_SceneOptMovConfirm1 0x021C3824 arm ov016
 *   FX_ModS32  0x0207C994  arm
 *   gSceneOptMenuPushPalette  0x021DA4B0  data
 */
#include "../../matched/include/G_SCENEMENU_BSS.h"
#include "../../matched/include/G_FocusPosT.h"
#include "../../matched/include/G_RectT.h"

#define BG_PRIORITY_3(reg) (*(vu16 *)(reg) = (u16)((*(vu16 *)(reg) & ~3) | 3))
struct tagDWCWiFiInfo;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32_021C2A3C;

typedef unsigned long long u64;

typedef volatile u16 vu16;

typedef struct tagDWCWiFiInfo {
    u64 attestedUserId;
    u64 notAttestedId;
    u16 pass;
    u16 randomHistory;
} DWCWiFiInfo;

typedef _Bool bool;

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

/* scenemenu.o .bss at 0x021DE59C, members at their vendor offsets */
typedef struct {
    unsigned char  FocusPos;          /* 0x00 */
    void          *Palette;           /* 0x04 */
} SCENEMENU_BSS;

/* scenemenu.o .rodata at 0x021DA478, members at their vendor offsets */
typedef struct {
    RECT           R_TOUCH[2];        /* 0x00 */
    RECT           R_FOCUS[2];        /* 0x10 */
} SCENEMENU_RODATA;

/* PALETTE's initialiser is the compiler's @20658 in its own .rodata section */
typedef struct { unsigned char v[2]; } PALETTE_INIT;

typedef struct {
	unsigned short l;
	unsigned short t;
	unsigned short r;
	unsigned short b;
} RectT;

typedef struct {
	unsigned char idx;
	unsigned char flag;
	unsigned char pad[2];
	void *ptr;
} FocusPosT;

typedef struct {
	unsigned long long a;
	int c[3];
} WiFiInfoT;

extern void DWCi_HLlLoad(int x);
extern void DWCi_STEPlChangeScr(int x);
extern void DWCi_COMMENTlDispEx(int a, int b, int c);
extern int  DWCi_CEINlSetExObj(int a, int b);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned char *DWCi_Char(unsigned char *name);
extern void *DWCi_ARClReadEx(char *path, u32_021C2A3C *size, int alignment);
extern void DWCi_BM_GetWiFiInfo(DWCWiFiInfo *buf);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32_021C2A3C size);
extern void DWCi_ScreenDC_FlushRange(const void *startAddr, u32_021C2A3C nBytes);
extern void GX_LoadBGPltt(const void *pSrc, u32_021C2A3C offset, u32_021C2A3C szByte);
extern void DWCi_ARClRelease(void *file);
extern void GX_LoadBG2Char(const void *pSrc, u32_021C2A3C offset, u32_021C2A3C szByte);
extern void GX_LoadBG2Scr(const void *pSrc, u32_021C2A3C offset, u32_021C2A3C szByte);
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_ChangeScene(void (*scene)(void));
extern void DWCi_CMNlButton(int kind);
extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_BTNlDisable(void);
extern void DWCi_BTNlSet(int idx);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_FOCUSlDisp4(int x0, int x1, int y0, int y1);
extern bool DWCi_TPlCheckTrigger(RECT *r);
extern bool DWCi_IPTlCheckTrigger(unsigned short input);
extern bool DWCi_IPTlCheckRepeat(unsigned short input);
extern void DWCi_SCREENlCopyPalette(void *src, int sColor, int dColor);
extern void DWCi_SceneEnd(void);
extern void DWCi_BTNlSetForce(int idx);
extern void DWCi_BTNlEnd(void);
extern int DWCi_BTNlIsEnd(void);
extern void DWCi_OBJlDelete(unsigned int *obj);
extern void DWCi_FOCUSlDelete(void);
extern int DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_SceneMenu();
extern void DWCi_SceneOptInfo();
extern void DWCi_SceneOptErase();
extern void DWCi_SceneOptMovConfirm1();
extern int  FX_ModS32(int a, int b);
void DWCi_SceneOptMenu(void);
void DWCi_SceneOptMenu_procScene(void);
void DWCi_SceneOptMenu_draw(void);
extern struct FocusPosT gSceneOptMenuState;
extern struct SCENEMENU_BSS scenemenu_bss;
extern const SCENEMENU_RODATA scenemenu_rodata;
extern const PALETTE_INIT scenemenu_init_20658;
extern RectT gSceneOptMenuButtonRects[3];
extern struct RectT gSceneOptMenuFocusRects[3];
extern unsigned char gSceneOptMenuPushPalette[3];

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void input(void);
static void button(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
static void moveFocus(int a);
static void DWCi_SceneOptMenuDispPush(void);


void DWCi_SceneOptMenu(void)
{
    int q;
    u8 i;

    gSceneOptMenuState.flag = 0;
    initGraphics();
    DWCi_HLlLoad(0x10);
    DWCi_STEPlChangeScr(3);
    DWCi_COMMENTlDispEx(0x39, -1, 0);
    gSceneOptMenuState.obj = (void *)DWCi_CEINlSetExObj(0, 0x5b);
    q = (int)gSceneOptMenuState.obj;
    *(u32_021C2A3C *)q = (*(u32_021C2A3C *)q & 0xFE00FF00) | 0x84 | 0xE00000;
    q = (int)gSceneOptMenuState.obj;
    *(u16 *)(q + 4) = (*(u16 *)(q + 4) & ~0xC00) | 0xC00;
    i = gSceneOptMenuState.idx;
    DWCi_FOCUSlDisp4(gSceneOptMenuFocusRects[i].l, gSceneOptMenuFocusRects[i].r,
                  gSceneOptMenuFocusRects[i].t, gSceneOptMenuFocusRects[i].b);
    DWCi_ChangeScene(procInit);
}


/*
 * sdk:      initGraphics (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 */
static void initGraphics(void)
{
    char PLLT0[] = "char/ybBgOption.ncl.l";
    char PLLT1[] = "char/ybBgOption1.ncl.l";
    u8 *src;
    u8 *dst;
    char *n;
    DWCWiFiInfo info;
    int i;
    u8 *pltt;

    DWCi_CMNlLoadResource("char/jbBgOption.ncg.l", (void (*)(void *, long unsigned int,  long unsigned int))GX_LoadBG2Char);
    DWCi_CMNlLoadResource("char/jb5OptMenu.nsc.l", (void (*)(void *, long unsigned int,  long unsigned int))GX_LoadBG2Scr);
    n = (char *)DWCi_Char((unsigned char *)PLLT1);
    gSceneOptMenuState.ptr = DWCi_ARClReadEx(n, 0, 4);
    n = (char *)DWCi_Char((unsigned char *)PLLT0);
    pltt = DWCi_ARClReadEx(n, 0, 4);
    DWCi_BM_GetWiFiInfo(&info);
    if (info.attestedUserId == 0) {
        src = pltt + 0xc0;
        dst = pltt + 0x40;
        for (i = 0; i < 2; i++) {
            MI_CpuCopy8(src, dst, 0x20);
            src += 0x20;
            dst += 0x20;
        }
    }
    DWCi_ScreenDC_FlushRange(pltt, 0x200);
    GX_LoadBGPltt(pltt, 0, 0x200);
    DWCi_ARClRelease(pltt);
    BG_PRIORITY_3(0x04001008);
    BG_PRIORITY_3(0x0400100a);
    BG_PRIORITY_3(0x0400000a);
    BG_PRIORITY_3(0x0400000c);
}


static void procScene(void);


static void dispPushButton(void);


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
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}


void DWCi_SceneOptMenu_procScene(void)
{
    input();
    DWCi_SceneOptMenu_draw();
    button();
}


static void input(void)
{
	unsigned i;

	for (i = 0; i < 3; i++) {
		if (DWCi_TPlCheckTrigger((RECT *)(&gSceneOptMenuButtonRects[i]))) {
			DWCi_BTNlSet(1);
			gSceneOptMenuState.idx = i;
			DWCi_FOCUSlDisp4(gSceneOptMenuFocusRects[gSceneOptMenuState.idx].l, gSceneOptMenuFocusRects[gSceneOptMenuState.idx].r,
				gSceneOptMenuFocusRects[gSceneOptMenuState.idx].t, gSceneOptMenuFocusRects[gSceneOptMenuState.idx].b);
			return;
		}
	}
	if (DWCi_IPTlCheckTrigger(1)) {
		DWCi_BTNlSet(1);
		return;
	}
	if (DWCi_IPTlCheckTrigger(2)) {
		DWCi_BTNlSet(0);
		return;
	}
	if (DWCi_IPTlCheckRepeat(0x40)) {
		moveFocus(1);
		return;
	}
	if (DWCi_IPTlCheckRepeat(0x80))
		moveFocus(3);
}

void DWCi_SceneOptMenu_draw(void)
{
}


static void button(void)
{
	WiFiInfoT info;

	switch (DWCi_BTNlGet()) {
	case 0:
		DWCi_SNDlPlay(7);
		break;
	case 1:
		DWCi_BM_GetWiFiInfo((struct tagDWCWiFiInfo *)(&info));
		if (gSceneOptMenuState.idx != 0 && info.a == 0) {
			DWCi_SNDlPlay(9);
			DWCi_BTNlSetForce(-1);
			return;
		}
		DWCi_SNDlPlay(6);
		DWCi_SceneOptMenuDispPush();
		gSceneOptMenuState.flag = 1;
		break;
	default:
		return;
	}
	DWCi_ChangeScene(endScene);
}


static void endScene(void)
{
	DWCi_BTNlDisable();
	DWCi_EFFlWait(8);
	DWCi_ChangeScene(endScene1);
}


/*
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 */
static void endScene1(void)
{
	if (DWCi_EFFlCheck(1))
		return;
	if (gSceneOptMenuState.flag)
		DWCi_BTNlEnd();
	DWCi_EFFlFade(3, 1, 1, 8);
	DWCi_EFFlFade(3, 0, 0x14, 8);
	DWCi_ChangeScene(endScene2);
}


/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 */
static void endScene2(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    if (!DWCi_BTNlIsEnd())
        return;
    DWCi_OBJlDelete(gSceneOptMenuState.obj);
    DWCi_FOCUSlDelete();
    DWCi_COMMENTlDelete();
    DWCi_ARClRelease(gSceneOptMenuState.ptr);
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x14);
    if (gSceneOptMenuState.flag == 0) {
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene(DWCi_SceneMenu);
        return;
    }
    switch (gSceneOptMenuState.idx) {
    case 0:
        DWCi_SetParam_(0, (unsigned int)(1));
        DWCi_ChangeScene(DWCi_SceneOptInfo);
        return;
    case 1:
        DWCi_SetParam_(0, (unsigned int)(1));
        DWCi_ChangeScene(DWCi_SceneOptErase);
        return;
    case 2:
        DWCi_SetParam_(0, (unsigned int)(1));
        DWCi_ChangeScene(DWCi_SceneOptMovConfirm1);
        return;
    }
}


/*
 * Advances the flag byte gSceneOptMenuState.f0 and dispatches the indexed record.
 */
static void moveFocus(int a)
{
    u8 i;

    if (a == 1)
        gSceneOptMenuState.idx = (u8)FX_ModS32(gSceneOptMenuState.idx + 2, 3);
    else
        gSceneOptMenuState.idx = (u8)FX_ModS32(gSceneOptMenuState.idx + 1, 3);
    DWCi_SNDlPlay(8);
    i = gSceneOptMenuState.idx;
    DWCi_FOCUSlDisp4(gSceneOptMenuFocusRects[i].l, gSceneOptMenuFocusRects[i].r,
                  gSceneOptMenuFocusRects[i].t, gSceneOptMenuFocusRects[i].b);
}


/*
 * sdk:      DWCi_SceneOptMenuDispPush (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 */
static void DWCi_SceneOptMenuDispPush(void)
{
	int n = gSceneOptMenuPushPalette[gSceneOptMenuState.idx];
	DWCi_SCREENlCopyPalette(gSceneOptMenuState.ptr, n, n);
}

/*
 * function: func_0200F83C
 * address:  0x0200F83C
 * packet:   pkt_0200F83C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02010054        0x02010054  thumb
 *   func_02006210        0x02006210  thumb
 *   sub_0200FD38         0x0200FD38  thumb
 *   GX_VBlankIntr        0x0207D3E4  arm
 *   func_02037174        0x02037174  arm
 *   func_02037200        0x02037200  arm
 *   func_0201034C        0x0201034C  thumb
 *   sub_0200F824         0x0200F824  thumb
 *   sub_0200FEBC         0x0200FEBC  thumb
 *   func_02037190        0x02037190  arm
 *   GXS_SetGraphicsMode  0x0207D518  arm
 *   g_0214617C           0x0214617C  data
 *
 * net_err.c's fatal-error screen: snapshots the sub-engine DISPCNT and the
 * WINOUT outside / OBJ-window planes of both engines, blanks and redraws
 * through sub_0200FD38, narrows the chosen engine's windowing to BG1+OBJ,
 * waits for A/B to be released and pressed (PAD_DetachedCover / PAD_Read
 * inlines, polling func_0201034C and sub_0200F824 per frame), restores via
 * sub_0200FEBC and puts the snapshotted window state back on whichever
 * engine func_02037200 now names.  Written directly from NitroSDK's
 * gx.h / g2.h inline shapes (GXDispCnt, GXWndPlane, G2[S]_SetWnd*Plane,
 * GX[S]_SetVisible*); exact on the first compile.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            BOOL;

typedef union {
    u32 raw;
    struct {
        u32 bgMode:3;
        u32 bg0_2d3d:1;
        u32 objMapChar:1;
        u32 objMapBmp:2;
        u32 blankScr:1;
        u32 visiblePlane:5;
        u32 visibleWnd:3;
        u32 dispMode:4;
        u32 extObjMapChar:2;
        u32 extObjMapBmp:1;
        u32 hBlankObjProc:1;
        u32 bgCharOffset:3;
        u32 bgScrOffset:3;
        u32 bgExtPltt:1;
        u32 objExtPltt:1;
    };
} GXDispCnt;

typedef struct {
    u8 planeMask:5;
    u8 effect:1;
    u8 _reserve:2;
} GXWndPlane;

extern u32  func_02010054(void);
extern void func_02006210(void);
extern void sub_0200FD38(u32 a, u32 b);
extern BOOL GX_VBlankIntr(BOOL on);
extern void func_02037174(void);
extern u32 func_02037200(void);
extern void func_0201034C(void);
extern void sub_0200F824(void);
extern void sub_0200FEBC(BOOL a);
extern void func_02037190(void);
extern void GXS_SetGraphicsMode(u32 bgMode);
extern u8   g_0214617C[];

#define reg_GX_DISPCNT      (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT  (*(volatile u32 *)0x04001000)
#define reg_G2_WINOUT       (*(volatile u16 *)0x0400004A)
#define reg_G2S_DB_WINOUT   (*(volatile u16 *)0x0400104A)
#define reg_PAD_KEYINPUT    (*(volatile u16 *)0x04000130)
#define HW_BUTTON_XY_BUF    (*(volatile u16 *)0x02FFFFA8)

static inline GXDispCnt GXS_GetDispCnt(void)
{
    return *(volatile GXDispCnt *)&reg_GXS_DB_DISPCNT;
}

static inline GXWndPlane G2_GetWndOutsidePlane(void)
{
    return *(volatile GXWndPlane *)&reg_G2_WINOUT;
}

static inline GXWndPlane G2_GetWndOBJInsidePlane(void)
{
    return *(volatile GXWndPlane *)((u8 *)&reg_G2_WINOUT + 1);
}

static inline GXWndPlane G2S_GetWndOutsidePlane(void)
{
    return *(volatile GXWndPlane *)&reg_G2S_DB_WINOUT;
}

static inline GXWndPlane G2S_GetWndOBJInsidePlane(void)
{
    return *(volatile GXWndPlane *)((u8 *)&reg_G2S_DB_WINOUT + 1);
}

static inline void G2_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (reg_G2_WINOUT & ~0x3F) | wnd;
    if (effect) {
        tmp |= 0x20;
    }
    reg_G2_WINOUT = (u16)tmp;
}

static inline void G2_SetWndOBJInsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (reg_G2_WINOUT & ~0x3F00) | (wnd << 8);
    if (effect) {
        tmp |= 0x2000;
    }
    reg_G2_WINOUT = (u16)tmp;
}

static inline void G2S_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (reg_G2S_DB_WINOUT & ~0x3F) | wnd;
    if (effect) {
        tmp |= 0x20;
    }
    reg_G2S_DB_WINOUT = (u16)tmp;
}

static inline void G2S_SetWndOBJInsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (reg_G2S_DB_WINOUT & ~0x3F00) | (wnd << 8);
    if (effect) {
        tmp |= 0x2000;
    }
    reg_G2S_DB_WINOUT = (u16)tmp;
}

static inline void GX_SetVisiblePlane(int plane)
{
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1F00) | (plane << 8);
}

static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}

static inline void GXS_SetVisiblePlane(int plane)
{
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1F00) | (plane << 8);
}

static inline void GXS_SetVisibleWnd(int window)
{
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~0xE000 | (window << 13);
}

static inline BOOL PAD_DetachedCover(void)
{
    return (BOOL)((HW_BUTTON_XY_BUF & 0x8000) >> 15);
}

static inline u16 PAD_Read(void)
{
    return (u16)(((reg_PAD_KEYINPUT | HW_BUTTON_XY_BUF) ^ 0x2FFF) & 0x2FFF);
}

static inline u16 KeyFilter(u16 k)
{
    return (u16)(k & ~((k & 0x40) << 1) & ~((k & 0x20) >> 1));
}

void func_0200F83C(void)
{
    GXDispCnt dispCnt = GXS_GetDispCnt();
    GXWndPlane outMain = G2_GetWndOutsidePlane();
    GXWndPlane outSub = G2S_GetWndOutsidePlane();
    GXWndPlane objMain = G2_GetWndOBJInsidePlane();
    GXWndPlane objSub = G2S_GetWndOBJInsidePlane();

    if (func_02010054() == 0) {
        return;
    }
    func_02006210();
    sub_0200FD38(0, 0);
    GX_VBlankIntr(1);
    func_02037174();
    if (func_02037200() == 1) {
        G2_SetWndOutsidePlane(2, 0);
        G2_SetWndOBJInsidePlane(0x10, 0);
        GX_SetVisibleWnd(4);
        GX_SetVisiblePlane(0x12);
    } else {
        G2S_SetWndOutsidePlane(2, 0);
        G2S_SetWndOBJInsidePlane(0x10, 0);
        GXS_SetVisibleWnd(4);
        GXS_SetVisiblePlane(0x12);
    }
    while (PAD_DetachedCover() == 1 || (KeyFilter(PAD_Read()) & 3) != 0) {
        func_0201034C();
        sub_0200F824();
    }
    while (PAD_DetachedCover() == 1 || (KeyFilter(PAD_Read()) & 3) == 0) {
        func_0201034C();
        sub_0200F824();
    }
    sub_0200FEBC(*(u32 *)(g_0214617C + 0x44) == 1);
    func_02037190();
    if (func_02037200() == 2) {
        GXS_SetGraphicsMode(dispCnt.bgMode);
        GXS_SetVisiblePlane(dispCnt.visiblePlane);
        GXS_SetVisibleWnd(dispCnt.visibleWnd);
        G2S_SetWndOutsidePlane(outSub.planeMask, outSub.effect);
        G2S_SetWndOBJInsidePlane(objSub.planeMask, objSub.effect);
    } else {
        G2_SetWndOutsidePlane(outMain.planeMask, outMain.effect);
        G2_SetWndOBJInsidePlane(objMain.planeMask, objMain.effect);
    }
}

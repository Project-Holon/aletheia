/*
 * function: sub_0200FEBC
 * address:  0x0200FEBC
 * packet:   pkt_0200FEBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02010054             0x02010054  thumb
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   func_020435F4             0x020435F4  arm
 *   G2_GetBG1CharPtr          0x0207E24C  arm
 *   G2_GetBG1ScrPtr           0x0207DFB4  arm
 *   MIi_CpuCopy16             0x02082A60  arm
 *   func_0203D828             0x0203D828  arm
 *   GX_SetGraphicsMode        0x0207D4B0  arm
 *   func_020809A0             0x020809A0  arm
 *   func_020808F4             0x020808F4  arm
 *   GX_SetBankForBG           0x0207FDCC  arm
 *   GX_SetBankForSubBG        0x020806B0  arm
 *   GX_HBlankIntr             0x0207D3AC  arm
 *   GX_VBlankIntr             0x0207D3E4  arm
 *   OS_WaitIrq                0x0208459C  arm
 *   g_0214617C                0x0214617C  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200FEBC.c  *       --func sub_0200FEBC --addr 0x0200FEBC --cc 1.1p1 --thumb
 *
 * net_err.c: restore the 2D state sub_0200FD38 saved (docs/families/
 * net_err.h).  Wave 14 closed the 43-byte bitfield-unpack schedule of
 * docs/notes/sub_0200FEBC.c.txt: G2_SetBG1Control's parameters are the
 * SDK's ENUM types (GXBGScrSizeText, GXBGColorMode, GXBGScrBase,
 * GXBGCharBase, GXBGExtPltt), not int.  With enum parameters mwcc
 * materialises each bitfield argument into a temporary, right to left,
 * before the inline body reads reg_G2_BG1CNT; with int parameters it
 * substitutes the extractions into the expression after the read.
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

typedef union {
    u16 raw;
    struct {
        u16 priority:2;
        u16 charBase:4;
        u16 mosaic:1;
        u16 colorMode:1;
        u16 screenBase:5;
        u16 bgExtPltt:1;
        u16 screenSize:2;
    };
} GXBg01Control;

typedef struct {
    void          *bg1Char;     /* +0x00 */
    void          *bg1Scr;      /* +0x04 */
    void          *pltt;        /* +0x08 */
    GXDispCnt      dispCnt;     /* +0x0C */
    GXBg01Control  bg1Cnt;      /* +0x10 */
    u16            pad12;
    int            bright;      /* +0x14 */
    int            subBright;   /* +0x18 */
    BOOL           hBlank;      /* +0x1C */
    BOOL           vBlank;      /* +0x20 */
    u32            bankBG;      /* +0x24 */
    u32            bankSubBG;   /* +0x28 */
    u32            state;       /* +0x2C */
    u32            f30;         /* +0x30 */
    u16            bldCnt;      /* +0x34 */
    u16            subBldCnt;   /* +0x36 */
    u32            f38;         /* +0x38 */
    int            subWnd;      /* +0x3C */
    u16            pltt0;       /* +0x40 */
} NetErrWork;

extern u32  func_02010054(void);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int v);
extern void func_020435F4(u32 a);
extern void *G2_GetBG1CharPtr(void);
extern void *G2_GetBG1ScrPtr(void);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern void func_0203D828(u32 *a, u32 *b);
extern void GX_SetGraphicsMode(u32 dispMode, u32 bgMode, u32 bg0_2d3d);
extern int func_020809A0(void);
extern int func_020808F4(void);
extern void GX_SetBankForBG(u32 bank);
extern void GX_SetBankForSubBG(u32 bank);
extern BOOL GX_HBlankIntr(BOOL on);
extern BOOL GX_VBlankIntr(BOOL on);
extern u32  OS_WaitIrq(BOOL clear, u32 mask);
extern u8   g_0214617C[];

#define reg_GX_MASTER_BRIGHT     (*(volatile u16 *)0x0400006C)
#define reg_GXS_DB_MASTER_BRIGHT (*(volatile u16 *)0x0400106C)
#define reg_GX_DISPCNT           (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT       (*(volatile u32 *)0x04001000)
#define reg_G2_BG1CNT            (*(volatile u16 *)0x0400000A)
#define reg_G2_BG1OFS            (*(volatile u32 *)0x04000014)
#define reg_G2_BLDCNT            (*(volatile u16 *)0x04000050)
#define reg_G2S_DB_BLDCNT        (*(volatile u16 *)0x04001050)

static inline void GX_SetVisiblePlane(int plane)
{
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1F00) | (plane << 8);
}

static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}

static inline void GXS_SetVisibleWnd(int window)
{
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~0xE000 | (window << 13);
}

typedef enum { GX_BG_SCRSIZE_TEXT_256x256 = 0 } GXBGScrSizeText;
typedef enum { GX_BG_COLORMODE_16 = 0 } GXBGColorMode;
typedef enum { GX_BG_SCRBASE_0x0000 = 0 } GXBGScrBase;
typedef enum { GX_BG_CHARBASE_0x00000 = 0 } GXBGCharBase;
typedef enum { GX_BG_EXTPLTT_01 = 0 } GXBGExtPltt;
static inline void G2_SetBG1Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase,
                                    GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    reg_G2_BG1CNT = (u16)((reg_G2_BG1CNT & 0x43) | (screenSize << 14) |
                          (colorMode << 7) | (screenBase << 8) |
                          (charBase << 2) | (bgExtPltt << 13));
}

static inline void G2_BG1Mosaic(BOOL enable)
{
    if (enable) {
        reg_G2_BG1CNT |= 0x40;
    } else {
        reg_G2_BG1CNT &= ~0x40;
    }
}

static inline void G2_SetBG1Offset(int hOffset, int vOffset)
{
    reg_G2_BG1OFS = (u32)(((hOffset << 0) & 0x1FF) | ((vOffset << 16) & 0x1FF0000));
}

void sub_0200FEBC(BOOL keepDark)
{
    NetErrWork *w = (NetErrWork *)g_0214617C;
    u32 x;
    u32 y;

    if (func_02010054() == 0) {
        return;
    }
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, -16);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, -16);
    *(volatile u16 *)0x05000400 = w->pltt0;
    func_020435F4(w->f38);
    reg_G2_BLDCNT = w->bldCnt;
    reg_G2S_DB_BLDCNT = w->subBldCnt;
    MIi_CpuCopy16(w->bg1Char, G2_GetBG1CharPtr(), 0x4000);
    MIi_CpuCopy16(w->bg1Scr, G2_GetBG1ScrPtr(), 0x800);
    MIi_CpuCopy16(w->pltt, (void *)0x05000000, 0x20);
    G2_SetBG1Control(w->bg1Cnt.screenSize, w->bg1Cnt.colorMode, w->bg1Cnt.screenBase,
                     w->bg1Cnt.charBase, w->bg1Cnt.bgExtPltt);
    G2_BG1Mosaic(w->bg1Cnt.mosaic);
    func_0203D828(&x, &y);
    G2_SetBG1Offset(x, y);
    GX_SetGraphicsMode(w->dispCnt.dispMode, w->dispCnt.bgMode, w->dispCnt.bg0_2d3d);
    GX_SetVisiblePlane(w->dispCnt.visiblePlane);
    GX_SetVisibleWnd(w->dispCnt.visibleWnd);
    GXS_SetVisibleWnd(w->subWnd);
    func_020809A0();
    func_020808F4();
    GX_SetBankForBG(w->bankBG);
    GX_SetBankForSubBG(w->bankSubBG);
    GX_HBlankIntr(w->hBlank);
    GX_VBlankIntr(w->vBlank);
    OS_WaitIrq(1, 1);
    if (keepDark == 0) {
        GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, w->bright);
        GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, w->subBright);
    }
}

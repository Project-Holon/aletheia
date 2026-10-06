/*
 * file:     net_err_p05.c
 * unit:     yes
 * function: sub_0200FEBC, CTRDGi_IsTaskAvailable_02010054, sub_02010068
 * address:  0x0200FEBC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   g0209DEA0      0x0209DEA0  data
 *   func_0207E24C  0x0207E24C  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_02062A4C  0x02062A4C  arm
 *   func_020862F0  0x020862F0  arm
 *   func_02082A60  0x02082A60  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02062B30  0x02062B30  arm
 *   func_0207DFB4  0x0207DFB4  arm
 *   func_02062AD4  0x02062AD4  arm
 *   func_02062A98  0x02062A98  arm
 */
struct NitroFileHeader;
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

typedef enum { GX_BG_SCRSIZE_TEXT_256x256 = 0 } GXBGScrSizeText;

typedef enum { GX_BG_COLORMODE_16 = 0 } GXBGColorMode;

typedef enum { GX_BG_SCRBASE_0x0000 = 0 } GXBGScrBase;

typedef enum { GX_BG_CHARBASE_0x00000 = 0 } GXBGCharBase;

typedef enum { GX_BG_EXTPLTT_01 = 0 } GXBGExtPltt;

struct ent {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
};

struct res0 {
    u8  pad[0x10];
    u32 len;
    void *ptr;
};

struct res1 {
    u32 pad0;
    u32 pad4;
    u32 len;
    u8  buf[4];
};

struct res2 {
    u8  pad[0xc];
    void *ptr;
};

typedef signed int     s32;

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
extern void *func_0207E24C(void);
extern void *func_0207DFB4(void);
extern void func_02082A7C(u32 val, void *dst, u32 n);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern void func_020862F0(void *p, u32 n);
extern void func_02082A60(void *dst, const void *src, u32 n);
extern u32 func_020307B0(void *p);
extern int func_02062B30(void *file, void **out);
extern s32 func_02062AD4(struct NitroFileHeader *file, void **out);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
void sub_0200FEBC(BOOL keepDark);
asm void CTRDGi_IsTaskAvailable_02010054(void);
void sub_02010068(u32 a0);
extern u8   g_0214617C[];
extern struct ent g0209DEA0[];



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



/*
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


asm void CTRDGi_IsTaskAvailable_02010054(void)
{
    ldr r0, =0x0214617C
    ldr r0, [r0]
    cmp r0, #0
    beq _zero
    mov r0, #1
    bx lr
_zero:
    mov r0, #0
    bx lr
}


/*
 * blocked: literal.  Every concrete byte matches; the only four unresolved
 * sites are the four ABS32 pool words for g0209DEA0 (base+0/+2/+4/+6, the
 * four u16 fields of an 8-byte-stride table indexed by a0).  The word
 * 0x0209DEA0 appears in exactly one literal pool image-wide, at 0x02010148,
 * which is inside this function's own extent, so no witness exists outside
 * the compared range and no cut can free it.  Needs a second referrer of
 * the table, or a matched neighbour that pools the same address.
 *   func_0207E24C  0x0207E24C  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_02062A4C  0x02062A4C  arm
 *   func_020862F0  0x020862F0  arm
 *   func_02082A60  0x02082A60  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02062B30  0x02062B30  arm
 *   func_0207DFB4  0x0207DFB4  arm
 *   func_02062AD4  0x02062AD4  arm
 *   func_02062A98  0x02062A98  arm
 */
void sub_02010068(u32 a0)
{
    void *h;
    struct res0 *r0p;
    struct res1 *r1p;
    struct res2 *r2p;
    u32 sp0;
    u16 id;

    func_02082A7C(0, func_0207E24C(), 0x4000);

    id = g0209DEA0[a0].f0;
    h = (void *)func_0204A1BC(id, g0209DEA0[a0].f2, 0, 1);
    if (func_02062A4C(h, (void **)(&r0p)) != 0) {
        u32 n;
        void *src;
        func_020862F0(r0p->ptr, r0p->len);
        n = r0p->len;
        src = func_0207E24C();
        func_02082A60(r0p->ptr, src, n);
    }
    func_020307B0(h);

    h = (void *)func_0204A1BC(id, g0209DEA0[a0].f4, 0, 1);
    if (func_02062B30(h, (void **)(&r1p)) != 0) {
        u32 n;
        void *src;
        func_020862F0(r1p->buf, r1p->len);
        n = r1p->len;
        src = func_0207DFB4();
        func_02082A60(r1p->buf, src, n);
    }
    func_020307B0(h);

    h = (void *)func_0204A1BC(id, g0209DEA0[a0].f6, 0, 1);
    func_02062AD4(h, (void **)(&sp0));
    if (func_02062A98(h, (void **)(&r2p)) != 0) {
        func_020862F0(r2p->ptr, 0x20);
        func_02082A60(r2p->ptr, (void *)0x05000000, 0x20);
    }
    func_020307B0(h);
}

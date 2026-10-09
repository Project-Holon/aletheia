/*
 * file:     net_err_p03.c
 * unit:     yes
 * function: func_0200FB6C, func_0200FBA0, func_0200FBB0, func_0200FC0C, sub_0200FD38
 * address:  0x0200FB6C
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
 *   func_020307B0  0x020307B0  arm
 *   func_020306F0  0x020306F0  arm
 *   func_0200F7B8  0x0200F7B8  thumb
 *   g_021461BC     0x021461BC  data
 *   sub_0200FBA0_Obj  0x0214617C  data
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203D798  0x0203D798  arm
 *   func_0203CF04  0x0203CF04  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203D0D0  0x0203D0D0  arm
 *   func_02178E4C  0x02178E4C  thumb
 *   func_0203CFA0  0x0203CFA0  arm
 *   func_0201034C  0x0201034C  thumb
 *   func_0208459C  0x0208459C  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_02010054  0x02010054  thumb
 *   sub_0200FA94   0x0200FA94  thumb
 *   GX_HBlankIntr  0x0207D3AC  arm
 *   GX_VBlankIntr  0x0207D3E4  arm
 *   func_020101D4  0x020101D4  thumb
 *   sub_0200FEBC   0x0200FEBC  thumb
 *   g_0214617C     0x0214617C  data
 *   GXx_GetMasterBrightness_  0x0207D55C  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   func_020808F4             0x020808F4  arm
 *   func_020809A0             0x020809A0  arm
 *   GX_SetBankForBG           0x0207FDCC  arm
 *   GX_SetGraphicsMode        0x0207D4B0  arm
 *   G2_GetBG1CharPtr          0x0207E24C  arm
 *   G2_GetBG1ScrPtr           0x0207DFB4  arm
 *   MIi_CpuCopy16             0x02082A60  arm
 *   func_02043668             0x02043668  arm
 *   func_020435F4             0x020435F4  arm
 *   sub_02010068              0x02010068  thumb
 */
#include "../../matched/include/Obj05696.h"
#include "../../matched/include/Obj01327.h"

typedef unsigned char u8;

typedef unsigned int  u32;

struct Sub0200FB6CObj {
    void *unk00;
    void *unk04;
    void *unk08;
};

struct Sub0200FBA0Obj {
    unsigned char pad[0x60];
};

typedef unsigned short u16;

typedef int            BOOL;

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

extern u32 func_020307B0(void *p);
extern void func_020306F0(u32 id);
extern u32 func_0200F7B8(u32 a0);
extern int func_0203CD98(void);
extern void *func_0203D798(void);
extern void func_0203CF04(void);
extern int func_0203CEAC(int a0);
extern void func_0203D0D0(void);
extern u32  func_02178E4C(void);
extern void func_0203CFA0(void);
extern int func_0201034C(void);
extern void func_0208459C(int clear, u32 irqFlags);
extern int func_0203CDBC(void);
extern u32  func_02010054(void);
extern void sub_0200FA94(void);
extern u32  GX_HBlankIntr(BOOL on);
extern u32  GX_VBlankIntr(BOOL on);
extern void func_020101D4(u32 a, u32 b);
extern void sub_0200FEBC(int keepDark);
extern int  GXx_GetMasterBrightness_(volatile u16 *reg);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int v);
extern int func_020808F4(void);
extern int func_020809A0(void);
extern void GX_SetBankForBG(u32 bank);
extern void GX_SetGraphicsMode(u32 dispMode, u32 bgMode, u32 bg0_2d3d);
extern void *G2_GetBG1CharPtr(void);
extern void *G2_GetBG1ScrPtr(void);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern u32  func_02043668(void);
extern void func_020435F4(u32 a);
extern void sub_02010068(u32 a);
void sub_0200FB6C(void);
void sub_0200FBA0(void);
u32 sub_0200FBB0(void);
u32 func_0200FC0C(u32 a0);
void sub_0200FD38(u32 a0, u32 a1);
extern u8   g_021461BC[0x1A];
extern struct Sub0200FBA0Obj sub_0200FBA0_Obj;
extern u8   g_0214617C[];



/*
 * Teardown for the module object at 0x0214617C (same object as
 * sub_0200FB24.c and sub_0200FB38): frees its three owned pointers, frees
 * pool id 8, marks offset 0x19 of a second object at 0x021461BC (which is
 * numerically 0x0214617C + 0x40, but the original loads it through its
 * own fresh literal-pool word rather than as an offset off r4, so the two
 * are declared as separate objects here to keep the same register/pool
 * shape) and forwards flag 1 to func_0200F7B8.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0200FB6C.c \
 *       --func sub_0200FB6C --addr 0x0200FB6C --cc 1.1p1 --thumb
 */
void sub_0200FB6C(void)
{
    struct Sub0200FB6CObj *obj = (struct Sub0200FB6CObj *)0x0214617C;

    func_020307B0(obj->unk00);
    func_020307B0(obj->unk04);
    func_020307B0(obj->unk08);
    func_020306F0(8);

    g_021461BC[0x19] = 0x60;

    func_0200F7B8(1);
}



/*
 * Zeroes two word fields of the module-wide object at 0x0214617C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200FBA0.c \
 *       --func sub_0200FBA0 --addr 0x0200FBA0 --cc 1.1p1
 */
void sub_0200FBA0(void)
{
    *(u32 *)((unsigned char *)&sub_0200FBA0_Obj + 0x2c) = 0;
    *(u32 *)((unsigned char *)&sub_0200FBA0_Obj + 0x5c) = 0;
}



/*
 * A polling loop, gated on func_0203CD98(): returns 1 immediately if it is
 * zero. Otherwise fetches the same status object sub_0200F734 reads
 * (func_0203D798, offset +0x65), resets three link-state counters, then
 * polls func_0203CDBC() once per iteration, quitting the moment it stops
 * returning zero. Each iteration checks the status byte first: 0 or 5
 * means "ready to ask", and if func_02178E4C() then answers 0xa the
 * function returns 0 straight out of the loop.
 *
 * Every concrete byte matches; func_0203CFA0 is called from exactly this
 * one site in the whole ROM, so that relocation stays unresolved under
 * the honesty rule. The other nine calls all resolve.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0200FBB0.c \
 *       --func sub_0200FBB0 --addr 0x0200FBB0 --cc 1.1p1
 *
 * The `matched` class does not reach it: func_0203CFA0 is not matched, so
 * no EXACT entry covers that address. Closes to EXACT the day either
 * func_0203CFA0 gets a second caller elsewhere in the image, or is itself
 * matched.
 */
u32 sub_0200FBB0(void)
{
    u8 *obj;
    u32 flag;

    if (func_0203CD98() != 0) {
        obj = func_0203D798();
        func_0203CF04();
        func_0203CEAC(0);
        func_0203D0D0();
        flag = 1;

        for (;;) {
            if (obj != 0) {
                u8 v = obj[0x65];
                if (v == 0 || v == 5) {
                    if (func_02178E4C() == 0xa) {
                        return 0;
                    }
                }
            }
            func_0203CFA0();
            func_0201034C();
            func_0208459C(flag, flag);
            if (func_0203CDBC() == 0) {
                continue;
            }
            break;
        }
    }

    return 1;
}



#define reg_PAD_KEYINPUT  (*(volatile u16 *)0x04000130)


#define HW_BUTTON_XY_BUF  (*(volatile u16 *)0x02FFFFA8)



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



/*
 * The net_err.c error screen's blocking entry: bail unless the module is
 * live (func_02010054), abort on a1 == 1, and only when the module object's
 * +0x2c state is 2 run the screen -- re-init graphics (sub_0200FD38) for a
 * link-mode error (+0x59 in 1, 2, 6), poll the link (sub_0200FBB0), draw
 * (func_020101D4 or sub_0200FD38), then wait for A/B to be released and
 * pressed again (the two PAD loops are NitroSDK's PAD_DetachedCover and
 * PAD_Read inlines plus a filter that drops the opposing D-pad bit), then
 * tear down.  Two lessons: the 0x2c test is a WRAPPING if, not an early
 * return (the shared 'return 0' sits after the body); and the object is a
 * named local 'u8 *g', which makes mwccarm rematerialise the pool word per
 * access and reach +0x59 with 'adds' -- the extern spelled directly folds
 * to a second pool word g+0x40 instead.
 */
u32 func_0200FC0C(u32 a0)
{
    u8 *g = g_0214617C;
    u32 mode;

    if (func_02010054() == 0) {
        return 0;
    }
    if (a0 == 1) {
        sub_0200FA94();
    }
    if (((struct Obj05696 *)g)->f2C == 2) {
        mode = 0;
        {
            u8 t = g[0x59];
            if (t == 1 || t == 2 || t == 6) {
                mode = 1;
            }
        }
        if (mode == 1) {
            sub_0200FD38(a0, 1);
        }
        if (sub_0200FBB0() == 0) {
            sub_0200FA94();
        }
        if (mode == 1) {
            ((struct Obj05696 *)g)->f1C = GX_HBlankIntr(0);
            ((struct Obj05696 *)g)->f20 = GX_VBlankIntr(0);
            func_020101D4(a0, 0);
        } else {
            sub_0200FD38(a0, 0);
        }
        while (PAD_DetachedCover() == 1 || (KeyFilter(PAD_Read()) & 3) != 0) {
            func_0201034C();
        }
        while (PAD_DetachedCover() == 1 || (KeyFilter(PAD_Read()) & 3) == 0) {
            func_0201034C();
        }
        sub_0200FEBC(0);
        sub_0200FBA0();
        ((struct Obj05696 *)g)->f30 = 0;
    return 1;
    }
    return 0;
}


#define reg_GX_MASTER_BRIGHT   (*(volatile u16 *)0x0400006C)

#define reg_GXS_DB_MASTER_BRIGHT (*(volatile u16 *)0x0400106C)

#define reg_GX_DISPCNT         (*(volatile u32 *)0x04000000)

#define reg_GXS_DB_DISPCNT     (*(volatile u32 *)0x04001000)

#define reg_G2_BG1CNT          (*(volatile u16 *)0x0400000A)

#define reg_G2_BG1OFS          (*(volatile u32 *)0x04000014)

#define reg_G2_BLDCNT          (*(volatile u16 *)0x04000050)

#define reg_G2S_DB_BLDCNT      (*(volatile u16 *)0x04001050)


static inline void GX_SetVisiblePlane(int plane)
{
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1F00) | (plane << 8);
}


static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}


static inline int GXS_GetVisibleWnd(void)
{
    return (int)((reg_GXS_DB_DISPCNT & 0xE000) >> 13);
}


static inline void GXS_SetVisibleWnd(int window)
{
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~0xE000 | (window << 13);
}


static inline GXBg01Control G2_GetBG1Control(void)
{
    return *(volatile GXBg01Control *)&reg_G2_BG1CNT;
}


static inline void G2_SetBG1Control(int screenSize, int colorMode, int screenBase,
                                    int charBase, int bgExtPltt)
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


/*
 * net_err.c's graphics save-and-blank: saves both master brightness levels,
 * the H/V-blank interrupt enables, two VRAM bank states, DISPCNT, the sub
 * window mask and BG1CNT into the module object at 0x0214617C, reprograms
 * BG1 as a 16-colour text layer, backs up BG1's character, screen and the
 * first palette block (unless +0x59 is 0x60), then draws the error screen
 * (sub_02010068 and func_020101D4).  The SDK inlines are NitroSDK's gx.h /
 * g2.h shapes (GX_SetVisiblePlane, G2_SetBG1Control with the saved control
 * word's bgExtPltt bit, G2_BG1Mosaic).  The lever that closed it (the
 * earlier note was 20 bytes short): the two backup copies read their buffer
 * pointer and call the pointer getter into NAMED LOCALS, dst first, which
 * loads the buffer before the call and raises the pressure that spills a0
 * to [sp] exactly as the image does.
 */
void sub_0200FD38(u32 a0, u32 a1)
{
    u8 *g = g_0214617C;

    if (func_02010054() == 0) {
        return;
    }
    ((struct Obj01327 *)g)->f14 = GXx_GetMasterBrightness_(&reg_GX_MASTER_BRIGHT);
    ((struct Obj01327 *)g)->f18 = GXx_GetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT);
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, -16);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, -16);
    if (a1 == 0) {
        ((struct Obj01327 *)g)->f1C = GX_HBlankIntr(0);
        ((struct Obj01327 *)g)->f20 = GX_VBlankIntr(0);
    }
    ((struct Obj01327 *)g)->f24 = func_020808F4();
    ((struct Obj01327 *)g)->f28 = func_020809A0();
    GX_SetBankForBG(4);
    ((struct Obj01327 *)g)->fC = reg_GX_DISPCNT;
    GX_SetGraphicsMode(1, 0, 0);
    GX_SetVisiblePlane(2);
    GX_SetVisibleWnd(0);
    ((struct Obj01327 *)g)->f3C = GXS_GetVisibleWnd();
    GXS_SetVisibleWnd(0);
    *(GXBg01Control *)(g + 0x10) = G2_GetBG1Control();
    G2_SetBG1Control(0, 0, 0, 1, ((GXBg01Control *)(g + 0x10))->bgExtPltt);
    G2_BG1Mosaic(0);
    reg_G2_BG1OFS = 0;
    if (g[0x59] != 0x60) {
        void *dst;
        void *src;
        dst = ((struct Obj01327 *)g)->f0;
        src = G2_GetBG1CharPtr();
        MIi_CpuCopy16(src, dst, 0x4000);
        dst = ((struct Obj01327 *)g)->f4;
        src = G2_GetBG1ScrPtr();
        MIi_CpuCopy16(src, dst, 0x800);
        MIi_CpuCopy16((void *)0x05000000, ((struct Obj01327 *)g)->f8, 0x20);
    }
    ((struct Obj01327 *)g)->f34 = reg_G2_BLDCNT;
    ((struct Obj01327 *)g)->f34 = reg_G2S_DB_BLDCNT;
    reg_G2_BLDCNT = 0;
    reg_G2S_DB_BLDCNT = 0;
    ((struct Obj01327 *)g)->f38 = func_02043668();
    func_020435F4(0);
    ((struct Obj01327 *)g)->f40 = *(volatile u16 *)0x05000400;
    *(volatile u16 *)0x05000400 = 0x7eea;
    if (g_0214617C[0x59] == 0x60) {
        sub_02010068(1);
    } else {
        sub_02010068(0);
        func_020101D4(a0, a1);
    }
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, 0);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, 0);
}

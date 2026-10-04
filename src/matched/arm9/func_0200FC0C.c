/*
 * function: func_0200FC0C
 * address:  0x0200FC0C
 * packet:   pkt_0200FC0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02010054  0x02010054  thumb
 *   sub_0200FA94   0x0200FA94  thumb
 *   sub_0200FD38   0x0200FD38  thumb
 *   sub_0200FBB0   0x0200FBB0  thumb
 *   GX_HBlankIntr  0x0207D3AC  arm
 *   GX_VBlankIntr  0x0207D3E4  arm
 *   func_020101D4  0x020101D4  thumb
 *   func_0201034C  0x0201034C  thumb
 *   sub_0200FEBC   0x0200FEBC  thumb
 *   sub_0200FBA0   0x0200FBA0  thumb
 *   g_0214617C     0x0214617C  data
 *
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
#include "../include/Obj05696.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            BOOL;

extern u32  func_02010054(void);
extern void sub_0200FA94(void);
extern void sub_0200FD38(u32 a, u32 b);
extern u32  sub_0200FBB0(void);
extern u32  GX_HBlankIntr(BOOL on);
extern u32  GX_VBlankIntr(BOOL on);
extern void func_020101D4(u32 a, u32 b);
extern void func_0201034C(void);
extern void sub_0200FEBC(int keepDark);
extern void sub_0200FBA0(void);
extern u8   g_0214617C[];

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

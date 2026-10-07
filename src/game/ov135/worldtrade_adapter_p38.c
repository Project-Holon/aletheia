/*
 * file:     worldtrade_adapter_p38.c
 * unit:     yes
 * function: func_02201C24, func_02201C88, func_02201CBC, func_02201D14
 * address:  0x02201C24
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F513C  0x021F513C  thumb  ov135
 *   func_021C866C  0x021C866C  arm
 *   func_021C86A8  0x021C86A8  arm
 *   func_021F4FC4  0x021F4FC4  thumb  ov135
 *   func_0200ADE0 0x0200ADE0 thumb
 *   func_022022B8 0x022022B8 thumb ov135
 *   func_022024B0 0x022024B0 thumb ov135
 *   func_02201B44 0x02201B44 thumb ov135
 *   func_0220251C 0x0220251C thumb ov135
 */
#include "../../matched/include/Obj07255.h"
#include "../../matched/include/Obj00018.h"
#include "../../matched/include/Obj23457.h"
#include "../../matched/include/Obj12239.h"

struct Rec0200AD94;
struct RegB;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed char s8;

extern u32 func_021C866C(u8 *p);
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern void func_021C8658(u8 *p);
extern void func_021F4FC4(u8 *p);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u16 func_0200ADE0(struct RegB *p);
extern void func_022022B8(void *, void *, u32, int);
extern void func_022024B0(void *obj, u8 *p);
extern void func_02201B44(u8 *p, void *mon, u8 *r, void *old);
extern void func_0200AD94(struct Rec0200AD94 *p, u16 v);
extern void func_0220251C(u8 *p, u16 a, u16 b);
extern void func_021C88FC(u8 *p);
int func_02201C24(u8 *p);
int func_02201C88(u8 *p);
int func_02201CBC(u8 *p);
int func_02201D14(u8 *p);


/*
 * Small sparse switch on the 0x021C86A8 index: state 0x30 for the +15 index
 * 3 and for the 0/1/13 group, the plain redraw for index 2, and a
 * state-0x30 (not redraw) counter arm.  This handler does not clear
 * p+0xf8c.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because 0x021C866C / 0x021C86A8 carry no func_ label in any
 * overlay listing (see the wave-5 residue note for the one-line fix).
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int func_02201C24(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        switch (n) {
        case -12:
            ((struct Obj07255 *)p)->f28 = 0x30;
            break;
        case -15:
        case -14:
        case -2:
            ((struct Obj07255 *)p)->f28 = 0x30;
            break;
        case -13:
            func_021F513C(p);
            break;
        }
    } else {
        if (++((struct Obj07255 *)p)->fF8C == 0xe10) {
            ((struct Obj07255 *)p)->f28 = 0x30;
        }
    }
    return 2;
}


/*
 * Every concrete byte is reproduced (52 bytes of code; the listing's extra two
 * are alignment padding).  The one wildcard is the BLX at +0006 to
 * func_021C8658, which has no independent witness outside 0x02201C88..0x02201CBA; the
 * resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Naming one of those eight
 * regions would be a guess, so the site stays parked.
 *
 * Shape: two hand-overs, then the fixed 6/1/0x48 opener, state 0, return 3.
 */
int func_02201C88(u8 *p)
{
    func_021C8658(p);
    func_021F4FC4(p);
    func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
    ((struct Obj00018 *)p)->f28 = 0;
    return 3;
}

int func_02201CBC(u8 *p)
{
    func_022022B8(p, p + 0xe4, func_0200ADE0(**(void ** *)&((struct Obj00018 *)p)->f0), ((struct Obj00018 *)p)->f207);
    func_022024B0(((struct Obj23457 *)(*(u8 * *)&((struct Obj00018 *)p)->f0))->f18, p + 0xe4);
    func_02201B44(p, p + 0xe4, p + 0xe4, 0);
    func_0200AD94(**(void ** *)&((struct Obj00018 *)p)->f0, 0);
    ((struct Obj00018 *)p)->f28 = 0x22;
    func_0220251C(p, 0x17, 0xf);
    return 2;
}


/*
 * State setter: hand over the object, latch the state word at +0x28 and clear the slot.
 */
int func_02201D14(u8 *p)
{
    func_021C88FC(p);
    ((struct Obj12239 *)p)->f28 = 0x18;
    ((struct Obj12239 *)p)->fF8C = 0x0;
    return 0x2;
}

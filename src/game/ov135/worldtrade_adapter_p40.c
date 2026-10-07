/*
 * file:     worldtrade_adapter_p40.c
 * unit:     yes
 * function: func_02201E1C, func_02201E38, func_02201ED4, func_02201F18
 * address:  0x02201E1C
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
 *   func_02201B18  0x02201B18  thumb  ov135
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203CA04  0x0203CA04  arm
 *   func_0203C968  0x0203C968  arm
 *   func_021C866C  0x021C866C  arm
 *   func_021C86A8  0x021C86A8  arm
 *   func_021F90A0 0x021F90A0 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021F4FC4 0x021F4FC4 thumb ov135
 *   func_021FFBC8 0x021FFBC8 thumb ov135
 *   func_021F9088  0x021F9088  thumb  ov135
 */
#include "../../matched/include/Obj12243.h"
#include "../../matched/include/Obj07256.h"
#include "../../matched/include/Obj00018.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

extern void func_021C8978(u8 *p);
extern u32 func_021C866C(u8 *p);
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern void func_02201B18(u8 *p);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void func_0203CA04(void);
extern void func_0203C968(void);
extern void func_021F90A0(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_021F4E98(u8 *, u32, u32);
extern void func_021F4EC0(u8 *, u32, u32);
extern void func_021F4FC4(u8 *);
extern void func_021FFBC8(u8 *);
extern u32 func_021F9088(u8 *p, u32 a, u32 b, u32 c, u32 d);
int func_02201E1C(u8 *p);
int func_02201E38(u8 *p);
int func_02201ED4(u8 *p);
u32 func_02201F18(u8 *p);


/*
 * State setter: hand over the object, latch the state word at +0x28 and clear the slot.
 */
int func_02201E1C(u8 *p)
{
    func_021C8978(p);
    ((struct Obj12243 *)p)->f28 = 0x1b;
    ((struct Obj12243 *)p)->fF8C = 0x0;
    return 0x2;
}


/*
 * Switch on the 0x021C86A8 index (case value = index + 15): three
 * func_02201B18 calls falling into the state-0x2b group (archive at +0x38,
 * then the four redraw calls), the two func_021F513C groups at indexes 0/1/3/13
 * and 2, and the plain redraw; indexes 4..9 and 14 are table holes.
 * Every concrete byte reproduced; parked only because 0x021C866C / 0x021C86A8
 * carry no func_ label in any overlay listing (wave-5 residue note).
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int func_02201E38(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj07256 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            func_02201B18(p);
            break;
        case 12:
            func_02201B18(p);
        case 11:
            func_02201B18(p);
        case 10:
            ((struct Obj07256 *)p)->f38 = n;
            ((struct Obj07256 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 0:
        case 1:
        case 3:
        case 13:
            func_021F513C(p);
            break;
        case 2:
            func_021F513C(p);
            break;
        }
    } else {
        if (++((struct Obj07256 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}

int func_02201ED4(u8 *p)
{
    func_021F90A0((u32)p, (u32)(((struct Obj00018 *)p)->fB6C), 0x99, 1, 0xf0f);
    func_021F4E98(p, 0x2a, 0x28);
    func_021F4EC0(p, 1, 0);
    func_021F4FC4(p);
    func_021FFBC8(p);
    return 2;
}


/*
 * Maps the state word at +0x38 to one of fifteen codes (cases written in
 * descending order, which is the order MWCC lays the bodies out in) and
 * forwards to func_021F9088 with p, the +0xb6c word, the code, 1 and 0x0f0f.
 */
u32 func_02201F18(u8 *p)
{
    u32 v;

    switch (((struct Obj00018 *)p)->f38 + 15) {
    case 14:
        v = 0x9d;
        break;
    case 13:
        v = 0xa9;
        break;
    case 12:
        v = 0xa2;
        break;
    case 11:
        v = 0xa4;
        break;
    case 10:
        v = 0xa3;
        break;
    case 9:
        v = 0x1b;
        break;
    case 8:
        v = 0x1c;
        break;
    case 7:
        v = 0x1d;
        break;
    case 6:
        v = 0x1e;
        break;
    case 5:
        v = 0x1f;
        break;
    case 4:
        v = 0x20;
        break;
    case 3:
        v = 0xa0;
        break;
    case 2:
        v = 0xa5;
        break;
    case 1:
        v = 0xaa;
        break;
    case 0:
        v = 0xa1;
        break;
    default:
        v = 0x9f;
        break;
    }
    return func_021F9088(p, *(u32 *)&((struct Obj00018 *)p)->fB6C, v, 1, 0x0f0f);
}

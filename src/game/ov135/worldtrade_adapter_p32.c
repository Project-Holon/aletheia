/*
 * file:     worldtrade_adapter_p32.c
 * unit:     yes
 * function: func_022014D8, func_02201554, func_0220157C, func_0220163C
 * address:  0x022014D8
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
 *   func_0220251C  0x0220251C  thumb  ov135
 *   func_022022B8  0x022022B8  thumb  ov135
 *   func_0200ADB4  0x0200ADB4  thumb
 *   func_0200ADE0  0x0200ADE0  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203CA04  0x0203CA04  arm
 *   func_0203C968  0x0203C968  arm
 */
#include "../../matched/include/Obj04908.h"
#include "../../matched/include/Obj12232.h"
#include "../../matched/include/Obj01829.h"
#include "../../matched/include/Obj12233.h"

struct RegB;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed char s8;

extern u32 func_021C866C(u8 *p);
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern void func_021C87FC(u8 *p);
extern void func_0220251C(u8 *p, u16 a, u16 b);
extern void func_022022B8(u8 *p, u32 a, u32 b, s32 c);
extern u32 func_0200ADB4(u32 a);
extern u16 func_0200ADE0(struct RegB *p);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void func_0203CA04(void);
extern void func_0203C968(void);
extern void func_021C8978(u8 *p);
int func_022014D8(u8 *p);
int func_02201554(u8 *p);
int func_0220157C(u8 *p);
int func_0220163C(u8 *p);


/*
 * Switch on the 0x021C86A8 index (case value = index + 15): state 0x25
 * with the u16 at +0x36 cleared, state 0x2d with the index archived at
 * +0x38, or a plain func_021F513C redraw.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because TWO of its callees have no witness anywhere in the tree.
 * Both BLX sites resolve as "(arm, from name) has no witness outside
 * 02201414..02201480; 8 overlays overlap this address (ov016, ov021, ov093,
 * ov111, ov114, ov128, ov172, ov208), none resolvable without a region hint
 * on the symbols: line".  A region hint cannot help: match.py's `label`
 * class needs EXACTLY ONE overlay listing to carry a func_ label at the
 * address, and 0x021C866C / 0x021C86A8 carry none in any overlay.  The
 * neighbours 0x021C8770/0x021C87FC/0x021C887C/0x021C8978 DO carry labels --
 * they are in asm/overlays/ov114.s -- so the fix is to trace those two
 * entries (layout/function_starts.txt is not this lane's file).
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int func_022014D8(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj04908 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            ((struct Obj04908 *)p)->f36 = 0;
            ((struct Obj04908 *)p)->f28 = 0x25;
            break;
        case 3:
        case 11:
            ((struct Obj04908 *)p)->f38 = n;
            ((struct Obj04908 *)p)->f28 = 0x2d;
            break;
        case 0:
        case 1:
        case 10:
        case 12:
        case 13:
        case 14:
            func_021F513C(p);
            break;
        case 2:
            func_021F513C(p);
            break;
        }
    } else {
        if (++((struct Obj04908 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}


/*
 * State 0xc, slot cleared, then publish the 0xd/0xf pair.
 */
int func_02201554(u8 *p)
{
    func_021C87FC(p + 0xe4);
    ((struct Obj12232 *)p)->f28 = 0xc;
    ((struct Obj12232 *)p)->fF8C = 0;
    func_0220251C(p, 0xd, 0xf);
    return 2;
}


/*
 * Switch on the 0x021C86A8 index (case value = index + 15): state 0x22
 * (with the two 0x0200ADxx queries and a 0x022022B8 call, or 0x1c when the
 * s8 flag at +0x207 is set), then the 0x2b pair (index 12 with the +0x38
 * archive, index 11 without), 0x2d, the +0x38/0x2b group and the plain
 * redraw; indexes 4..10 and 14 are table holes.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because 0x021C866C / 0x021C86A8 carry no func_ label in any
 * overlay listing (see the wave-5 residue note for the one-line fix).
 */
int func_0220157C(u8 *p)
{
    s32 n;
    s32 v;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj01829 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            v = ((struct Obj01829 *)p)->f207;
            if (v != 0) {
                ((struct Obj01829 *)p)->f28 = 0x1c;
            } else {
                func_022022B8(p, func_0200ADB4(*(u32 *)(((struct Obj01829 *)p)->f0)),
                              func_0200ADE0((struct RegB *)(*(u32 *)(((struct Obj01829 *)p)->f0))), v);
                ((struct Obj01829 *)p)->f28 = 0x22;
            }
            break;
        case 12:
            ((struct Obj01829 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 11:
            ((struct Obj01829 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 3:
            ((struct Obj01829 *)p)->f38 = n;
            ((struct Obj01829 *)p)->f28 = 0x2d;
            break;
        case 0:
        case 1:
        case 13:
            ((struct Obj01829 *)p)->f38 = n;
            ((struct Obj01829 *)p)->f28 = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 2:
            func_021F513C(p);
            break;
        }
    } else {
        if (++((struct Obj01829 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}


/*
 * State-setter: hand the object to func_021C8978, latch state 0xe at +0x28,
 * clear the word at +0xf8c and report 2.
 */
int func_0220163C(u8 *p)
{
    func_021C8978(p);
    ((struct Obj12233 *)p)->f28 = 0xe;
    ((struct Obj12233 *)p)->fF8C = 0;
    return 2;
}

/*
 * file:     worldtrade_adapter_p33.c
 * unit:     yes
 * function: func_02201658, func_022016CC
 * address:  0x02201658
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
 *   func_021C8C68 0x021C8C68 arm ov114
 *   func_0220251C 0x0220251C thumb ov135
 */
#include "../../matched/include/Obj09245.h"
#include "../../matched/include/Obj10595.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

extern u32 func_021C866C(u8 *p);
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern void func_021C8C68(u32, const void *, u32, const void *, u32);
extern void func_0220251C(u8 *p, u16 a, u16 b);
int func_02201658(u8 *p);
int func_022016CC(u8 *p);


/*
 * Switch on the 0x021C86A8 index (case value = index + 15): state 0x25
 * or a plain func_021F513C redraw.
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
int func_02201658(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj09245 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            ((struct Obj09245 *)p)->f28 = 0x25;
            break;
        case 10:
        case 11:
        case 12:
            func_021F513C(p);
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
        if (++((struct Obj09245 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}

int func_022016CC(u8 *p)
{
    func_021C8C68(*(u32 *)(p + ((struct Obj10595 *)p)->fD4 * 0x128 + 0x314), p + 0xe4, (u32)(p + 0xa24), p + 0x10ec, 0x80);
    func_0220251C(p, 0x12, 0x14);
    ((struct Obj10595 *)p)->f28 = 0x11;
    ((struct Obj10595 *)p)->fF8C = 0;
    return 2;
}

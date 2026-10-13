/*
 * function: func_022014D8
 * address:  0x022014D8
 * packet:   pkt_022014D8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F513C  0x021F513C  thumb  ov135
 *   DPW_TR_IsAsyncEnd  0x021C866C  arm
 *   DPW_TR_GetAsyncResult  0x021C86A8  arm
 *
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
 * UNBLOCKED: DPW_TR_IsAsyncEnd (0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
*/
#include "../include/Obj04908.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 DPW_TR_IsAsyncEnd(u8 *p);
extern s32 DPW_TR_GetAsyncResult(void);
extern void func_021F513C(u8 *p);

int func_022014D8(u8 *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd(p) != 0) {
        n = DPW_TR_GetAsyncResult();
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

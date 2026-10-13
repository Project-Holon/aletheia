/*
 * function: func_02201414
 * address:  0x02201414
 * packet:   pkt_02201414
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F513C  0x021F513C  thumb  ov135
 *   func_022021F8  0x022021F8  thumb  ov135
 *   func_02008DF0  0x02008DF0  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   GFL_NET_STATE_SetWifiError  0x0203CA04  arm
 *   GFL_NET_STATE_ClearErrorMode  0x0203C968  arm
 *   func_021C866C  0x021C866C  arm
 *   func_021C86A8  0x021C86A8  arm
 *
 * Switch on the 0x021C86A8 index (case value = index + 15): state
 * 0x22 with the 0x022021F8/0x02008DF0 pair, state 0x2b with the four
 * middleware calls, state 0x2d alone, or a plain func_021F513C redraw.
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
#include "../include/Obj02054.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 func_021C866C(u8 *p);
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern void func_022021F8(u8 *p, int flag);
struct Sub02008C20Obj;
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void GFL_NET_STATE_SetWifiError(void);
extern void GFL_NET_STATE_ClearErrorMode(void);

int func_02201414(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj02054 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            func_022021F8(p, 1);
            func_02008DF0((struct Sub02008C20Obj *)(*(u32 *)(((struct Obj02054 *)p)->f0 + 0x24)), 0x1c);
            ((struct Obj02054 *)p)->f28 = 0x22;
            break;
        case 14:
            ((struct Obj02054 *)p)->f38 = n;
            ((struct Obj02054 *)p)->f28 = 0x2b;
            func_0200FBB0();
            GFL_NET_STATE_SetWifiError();
            func_0200FBA0();
            GFL_NET_STATE_ClearErrorMode();
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            ((struct Obj02054 *)p)->f38 = n;
            ((struct Obj02054 *)p)->f28 = 0x2d;
            break;
        case 3:
        case 11:
            ((struct Obj02054 *)p)->f38 = n;
            ((struct Obj02054 *)p)->f28 = 0x2d;
            break;
        case 0:
        case 1:
        case 13:
            ((struct Obj02054 *)p)->f38 = n;
            ((struct Obj02054 *)p)->f28 = 0x2b;
            func_0200FBB0();
            GFL_NET_STATE_SetWifiError();
            func_0200FBA0();
            GFL_NET_STATE_ClearErrorMode();
            break;
        case 2:
            func_021F513C(p);
            break;
        }
    } else {
        if (++((struct Obj02054 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}

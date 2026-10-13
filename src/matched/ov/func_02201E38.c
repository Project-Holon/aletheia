/*
 * function: func_02201E38
 * address:  0x02201E38
 * packet:   pkt_02201E38
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F513C  0x021F513C  thumb  ov135
 *   func_02201B18  0x02201B18  thumb  ov135
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   GFL_NET_STATE_SetWifiError  0x0203CA04  arm
 *   GFL_NET_STATE_ClearErrorMode  0x0203C968  arm
 *   func_021C866C  0x021C866C  arm
 *   func_021C86A8  0x021C86A8  arm
 *
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
#include "../include/Obj07256.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 func_021C866C(u8 *p);
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern void func_02201B18(u8 *p);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void GFL_NET_STATE_SetWifiError(void);
extern void GFL_NET_STATE_ClearErrorMode(void);

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
            GFL_NET_STATE_SetWifiError();
            func_0200FBA0();
            GFL_NET_STATE_ClearErrorMode();
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

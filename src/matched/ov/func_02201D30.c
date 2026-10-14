/*
 * function: WORLDTRADE_SERVER_WaitDelete
 * address:  0x02201D30
 * packet:   pkt_02201D30
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORLDTRADE_CancelSave  0x021F513C  thumb  ov135
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   GFL_NET_STATE_SetWifiError  0x0203CA04  arm
 *   GFL_NET_STATE_ClearErrorMode  0x0203C968  arm
 *   DPW_TR_IsAsyncEnd  0x021C866C  arm
 *   DPW_TR_GetAsyncResult  0x021C86A8  arm
 *
 * Switch on the 0x021C86A8 index (case value = index + 15): state 0x25, the
 * +0x38/0x2b four-call group, the +0x38 archive with a plain redraw for the
 * 3+11 pair, the 0/1/13 and 2 redraw groups; 4..10 and 14 are table holes.
 * Concrete bytes reproduced; parked because 0x021C866C / 0x021C86A8 carry
 * no func_ label in any overlay listing (see pkt_ov135_residue.c.txt).
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 
 *
 * UNBLOCKED: DPW_TR_IsAsyncEnd (0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT*.
*/
#include "../include/Obj04909.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 DPW_TR_IsAsyncEnd(u8 *p);
extern s32 DPW_TR_GetAsyncResult(void);
extern void WORLDTRADE_CancelSave(u8 *p);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void GFL_NET_STATE_SetWifiError(void);
extern void GFL_NET_STATE_ClearErrorMode(void);

int WORLDTRADE_SERVER_WaitDelete(u8 *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd(p) != 0) {
        n = DPW_TR_GetAsyncResult();
        ((struct Obj04909 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            ((struct Obj04909 *)p)->f28 = 0x25;
            break;
        case 12:
            ((struct Obj04909 *)p)->f38 = n;
            ((struct Obj04909 *)p)->f28 = 0x2b;
            func_0200FBB0();
            GFL_NET_STATE_SetWifiError();
            func_0200FBA0();
            GFL_NET_STATE_ClearErrorMode();
            break;
        case 3:
        case 11:
            ((struct Obj04909 *)p)->f38 = n;
        case 0:
        case 1:
        case 13:
            WORLDTRADE_CancelSave(p);
            break;
        case 2:
            WORLDTRADE_CancelSave(p);
            break;
        }
    } else {
        if (++((struct Obj04909 *)p)->fF8C == 0xe10) {
            WORLDTRADE_CancelSave(p);
        }
    }
    return 2;
}

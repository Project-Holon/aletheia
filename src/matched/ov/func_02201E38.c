/*
 * function: WORLDTRADE_SERVER_StateWaitUploadFinishAsync
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
 *   WORLDTRADE_CancelSave  0x021F513C  thumb  ov135
 *   WORLDTRADE_SERVER_ShowResultByMode  0x02201B18  thumb  ov135
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   GFL_NET_STATE_SetWifiError  0x0203CA04  arm
 *   GFL_NET_STATE_ClearErrorMode  0x0203C968  arm
 *   DPW_TR_IsAsyncEnd  0x021C866C  arm
 *   DPW_TR_GetAsyncResult  0x021C86A8  arm
 *
 * Switch on the 0x021C86A8 index (case value = index + 15): three
 * WORLDTRADE_SERVER_ShowResultByMode calls falling into the state-0x2b group (archive at +0x38,
 * then the four redraw calls), the two WORLDTRADE_CancelSave groups at indexes 0/1/3/13
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
 * UNBLOCKED: DPW_TR_IsAsyncEnd (0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
*/
#include "../include/Obj07256.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 DPW_TR_IsAsyncEnd(u8 *p);
extern s32 DPW_TR_GetAsyncResult(void);
extern void WORLDTRADE_CancelSave(u8 *p);
extern void WORLDTRADE_SERVER_ShowResultByMode(u8 *p);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void GFL_NET_STATE_SetWifiError(void);
extern void GFL_NET_STATE_ClearErrorMode(void);

int WORLDTRADE_SERVER_StateWaitUploadFinishAsync(u8 *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd(p) != 0) {
        n = DPW_TR_GetAsyncResult();
        ((struct Obj07256 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            WORLDTRADE_SERVER_ShowResultByMode(p);
            break;
        case 12:
            WORLDTRADE_SERVER_ShowResultByMode(p);
        case 11:
            WORLDTRADE_SERVER_ShowResultByMode(p);
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
            WORLDTRADE_CancelSave(p);
            break;
        case 2:
            WORLDTRADE_CancelSave(p);
            break;
        }
    } else {
        if (++((struct Obj07256 *)p)->fF8C == 0xe10) {
            WORLDTRADE_CancelSave(p);
        }
    }
    return 2;
}

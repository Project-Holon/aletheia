/*
 * function: WORLDTRADE_SEARCH_WaitDownloadResult
 * address:  0x021FE744
 * packet:   pkt_021FE744
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_CancelSave  0x021F513C  thumb  ov135
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   GFL_NET_STATE_SetWifiError  0x0203CA04  arm
 *   GFL_NET_STATE_ClearErrorMode  0x0203C968  arm
 *   DPW_TR_IsAsyncEnd  0x021C866C  arm
 *   DPW_TR_GetAsyncResult  0x021C86A8  arm
 *
 * 23-slot switch on the 0x021C86A8 index (case value = index + 15, so the
 * bound is 22): the +0xd0 archive with state 0x13 for indexes 15..22, the
 * state-0x1e group with the four redraw calls for 1 and 13, the shared redraw
 * for 2 and the state-0x16 pair for 0 and 3; 4..12 and 14 are table holes.
 * The counter in the else arm compares against 0x1c20, not 0xe10.
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
#include "../include/Obj04907.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 DPW_TR_IsAsyncEnd(u8 *p);
extern s32 DPW_TR_GetAsyncResult(void);
extern void WORLDTRADE_CancelSave(u8 *p);
extern void GFL_USE_StopAllSe(void);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void GFL_NET_STATE_SetWifiError(void);
extern void GFL_NET_STATE_ClearErrorMode(void);

int WORLDTRADE_SEARCH_WaitDownloadResult(u8 *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd(p) != 0) {
        n = DPW_TR_GetAsyncResult();
        ((struct Obj04907 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
            ((struct Obj04907 *)p)->fD0 = n;
            ((struct Obj04907 *)p)->f28 = 0x13;
            break;
        case 1:
        case 13:
            GFL_USE_StopAllSe();
            ((struct Obj04907 *)p)->f28 = 0x1e;
            func_0200FBB0();
            GFL_NET_STATE_SetWifiError();
            func_0200FBA0();
            GFL_NET_STATE_ClearErrorMode();
            break;
        case 2:
            GFL_USE_StopAllSe();
            WORLDTRADE_CancelSave(p);
            break;
        case 0:
        case 3:
            GFL_USE_StopAllSe();
            ((struct Obj04907 *)p)->f28 = 0x16;
            break;
        }
    } else {
        if (++((struct Obj04907 *)p)->fF8C == 0x1c20) {
            GFL_USE_StopAllSe();
            WORLDTRADE_CancelSave(p);
        }
    }
    return 2;
}

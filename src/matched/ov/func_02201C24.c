/*
 * function: WORLDTRADE_SERVER_WaitCancel
 * address:  0x02201C24
 * packet:   pkt_02201C24
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_CancelSave  0x021F513C  thumb  ov135
 *   DPW_TR_IsAsyncEnd  0x021C866C  arm
 *   DPW_TR_GetAsyncResult  0x021C86A8  arm
 *
 * Small sparse switch on the 0x021C86A8 index: state 0x30 for the +15 index
 * 3 and for the 0/1/13 group, the plain redraw for index 2, and a
 * state-0x30 (not redraw) counter arm.  This handler does not clear
 * p+0xf8c.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because 0x021C866C / 0x021C86A8 carry no func_ label in any
 * overlay listing (see the wave-5 residue note for the one-line fix).
 
 *
 * UNBLOCKED: DPW_TR_IsAsyncEnd (0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
*/
#include "../include/Obj07255.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 DPW_TR_IsAsyncEnd(u8 *p);
extern s32 DPW_TR_GetAsyncResult(void);
extern void WORLDTRADE_CancelSave(u8 *p);

int WORLDTRADE_SERVER_WaitCancel(u8 *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd(p) != 0) {
        n = DPW_TR_GetAsyncResult();
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
            WORLDTRADE_CancelSave(p);
            break;
        }
    } else {
        if (++((struct Obj07255 *)p)->fF8C == 0xe10) {
            ((struct Obj07255 *)p)->f28 = 0x30;
        }
    }
    return 2;
}

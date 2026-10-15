/*
 * function: WORLDTRADE_SERVER_WaitDownload
 * address:  0x0220157C
 * packet:   pkt_0220157C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_CancelSave  0x021F513C  thumb  ov135
 *   WORLDTRADE_ADAPTER_RegisterReceivedMon  0x022022B8  thumb  ov135
 *   WORLDTRADE_NoOp  0x0200ADB4  thumb
 *   WORLDTRADE_GetReturnBox  0x0200ADE0  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   GFL_NET_STATE_SetWifiError  0x0203CA04  arm
 *   GFL_NET_STATE_ClearErrorMode  0x0203C968  arm
 *   DPW_TR_IsAsyncEnd  0x021C866C  arm
 *   DPW_TR_GetAsyncResult  0x021C86A8  arm
 *
 * Switch on the 0x021C86A8 index (case value = index + 15): state 0x22
 * (with the two 0x0200ADxx queries and a 0x022022B8 call, or 0x1c when the
 * s8 flag at +0x207 is set), then the 0x2b pair (index 12 with the +0x38
 * archive, index 11 without), 0x2d, the +0x38/0x2b group and the plain
 * redraw; indexes 4..10 and 14 are table holes.
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because 0x021C866C / 0x021C86A8 carry no func_ label in any
 * overlay listing (see the wave-5 residue note for the one-line fix).
 */
#include "../include/Obj01829.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed char s8;

extern u32 DPW_TR_IsAsyncEnd(u8 *p);
extern s32 DPW_TR_GetAsyncResult(void);
extern void WORLDTRADE_CancelSave(u8 *p);
extern void WORLDTRADE_ADAPTER_RegisterReceivedMon(u8 *p, u32 a, u32 b, s32 c);
extern u32 WORLDTRADE_NoOp(u32 a);
struct RegB;
extern u16 WORLDTRADE_GetReturnBox(struct RegB *p);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void GFL_NET_STATE_SetWifiError(void);
extern void GFL_NET_STATE_ClearErrorMode(void);

int WORLDTRADE_SERVER_WaitDownload(u8 *p)
{
    s32 n;
    s32 v;

    if (DPW_TR_IsAsyncEnd(p) != 0) {
        n = DPW_TR_GetAsyncResult();
        ((struct Obj01829 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            v = ((struct Obj01829 *)p)->f207;
            if (v != 0) {
                ((struct Obj01829 *)p)->f28 = 0x1c;
            } else {
                WORLDTRADE_ADAPTER_RegisterReceivedMon(p, WORLDTRADE_NoOp(*(u32 *)(((struct Obj01829 *)p)->f0)),
                              WORLDTRADE_GetReturnBox((struct RegB *)(*(u32 *)(((struct Obj01829 *)p)->f0))), v);
                ((struct Obj01829 *)p)->f28 = 0x22;
            }
            break;
        case 12:
            ((struct Obj01829 *)p)->f28 = 0x2b;
            func_0200FBB0();
            GFL_NET_STATE_SetWifiError();
            func_0200FBA0();
            GFL_NET_STATE_ClearErrorMode();
            break;
        case 11:
            ((struct Obj01829 *)p)->f28 = 0x2b;
            func_0200FBB0();
            GFL_NET_STATE_SetWifiError();
            func_0200FBA0();
            GFL_NET_STATE_ClearErrorMode();
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
            GFL_NET_STATE_SetWifiError();
            func_0200FBA0();
            GFL_NET_STATE_ClearErrorMode();
            break;
        case 2:
            WORLDTRADE_CancelSave(p);
            break;
        }
    } else {
        if (++((struct Obj01829 *)p)->fF8C == 0xe10) {
            WORLDTRADE_CancelSave(p);
        }
    }
    return 2;
}

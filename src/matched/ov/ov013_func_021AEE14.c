/*
 * function: VCT_MAIN_Update
 * address:  0x021AEE14
 * packet:   pkt_ov013_021AEE14
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Frame step: records the input halfword at G+0x19B0, accumulates the
 * elapsed microseconds past one 60 Hz frame (16666 us) at G+0x1A44 since
 * the tick stamped at G+0x1A3C, runs VCT_Update once per whole frame
 * owed, then advances the state machine at G+0x19AC unless G+0x19A8 is 3.
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   VCT_Update  0x021B386C  arm  ov013
 *   DWC_GetMyAID  0x0216B838  arm  ov009
 *   VCT_MAIN_RequestConnection  0x021AEC74  thumb  ov013
 *   VCT_MAIN_AcceptPendingPeer  0x021AECC4  thumb  ov013
 *   gVctWork     0x021B3C80  data  ov013
 */

#include "../include/G_Work.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;

extern struct Work *gVctWork;

extern u64 func_020870D0(void);
extern void VCT_Update(void);
extern unsigned char DWC_GetMyAID(void);
extern int VCT_MAIN_RequestConnection(int x);
extern int VCT_MAIN_AcceptPendingPeer(int x);

void VCT_MAIN_Update(int input)
{
    u64 tick;

    gVctWork->f19B0 = input;
    tick = func_020870D0();
    gVctWork->f1A44 +=
        (s32)(((u32)tick - (u32)gVctWork->f1A3C) * 64000 / 33514) - 16666;
    if (gVctWork->f1A44 < -10000) {
        gVctWork->f1A44 = 0;
    }
    gVctWork->f1A3C = tick;
    VCT_Update();
    while (gVctWork->f1A44 >= 16666) {
        VCT_Update();
        gVctWork->f1A44 -= 16666;
    }
    if (gVctWork->f19A8 == 3) {
        return;
    }
    switch (gVctWork->f19AC) {
    case 0:
        if (DWC_GetMyAID() == 0) {
            if (VCT_MAIN_RequestConnection(1) != 0) {
                gVctWork->f19AC = 1;
                gVctWork->f1A48 = 60;
            }
        } else if (DWC_GetMyAID() == 1) {
            if (VCT_MAIN_AcceptPendingPeer(0) != 0) {
                gVctWork->f19AC = 2;
            }
        }
        break;
    case 1:
        gVctWork->f1A48 -= 1;
        if (gVctWork->f1A48 == 0) {
            gVctWork->f19AC = 0;
        }
        break;
    case 2:
        break;
    }
}

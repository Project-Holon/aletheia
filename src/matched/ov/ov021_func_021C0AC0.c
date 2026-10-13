/*
 * function: EVENT_RECOVERY_RunParty
 * address:  0x021C0AC0
 * packet:   pkt_ov021_021C0AC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *   EVENT_RECOVERY_PlacePartyBall  0x021C0BE8  thumb  ov021
 *   EVENT_RECOVERY_ActivateParty  0x021C0C48  thumb  ov021
 *   EVENT_RECOVERY_IsMachineAnimeDone  0x021C0C80  thumb  ov021
 *   EVENT_RECOVERY_DeleteMachineNode  0x021C0BD8  thumb  ov021
 */
#include "../include/Obj00959.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void EVENT_RECOVERY_PlacePartyBall(u8 *p);
extern void EVENT_RECOVERY_ActivateParty(u8 *p);
extern int EVENT_RECOVERY_IsMachineAnimeDone(u32 a);
extern void EVENT_RECOVERY_DeleteMachineNode(int *p);

int EVENT_RECOVERY_RunParty(u32 a, int *st, u8 *p)
{
    switch (*st) {
    case 0:
        if ((int)((struct Obj00959 *)p)->f16 % 20 == 0) {
            EVENT_RECOVERY_PlacePartyBall(p);
            if (p[0x14] <= p[0x15]) {
                *st = *st + 1;
                ((struct Obj00959 *)p)->f16 = 0;
            }
        }
        break;
    case 1:
        if (((struct Obj00959 *)p)->f16 > 10) {
            EVENT_RECOVERY_ActivateParty(p);
            *st = *st + 1;
            ((struct Obj00959 *)p)->f16 = 0;
        }
        break;
    case 2:
        if (EVENT_RECOVERY_IsMachineAnimeDone((u32)p) != 0) {
            *st = *st + 1;
        }
        break;
    case 3:
        EVENT_RECOVERY_DeleteMachineNode((int *)p);
        return 1;
    }
    ((struct Obj00959 *)p)->f16 = ((struct Obj00959 *)p)->f16 + 1;
    return 0;
}

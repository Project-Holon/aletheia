/*
 * function: BTLV_EFFVM_CmdSaveCameraPosition
 * address:  0x021FA108
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFVM_CmdSaveCameraPosition   0x021FA108  thumb
 *   BTLV_EFFECT_GetCamera 0x021F8684 thumb ov094
 *   BTLV_CAMERA_GetEyeAndTarget 0x021F70F0 thumb ov094

 *
 * lane O10 candidate
 */
#include "../include/Obj12208.h"

extern int  BTLV_EFFECT_GetCamera(void);
extern void BTLV_CAMERA_GetEyeAndTarget(void **p, void *b, int c);

int BTLV_EFFVM_CmdSaveCameraPosition(int a, char *b)
{
    ((struct Obj12208 *)b)->f284 = 1;
    BTLV_CAMERA_GetEyeAndTarget((void **)BTLV_EFFECT_GetCamera(), b + 0x288, (int)(b + 0x294));
    return ((struct Obj12208 *)b)->f23C;
}


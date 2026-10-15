/*
 * function: INTRO_CMD_CmdMoveVoice
 * address:  0x021BE7A8
 * packet:   pkt_ov204_021BE7A8
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_IsAnySeBusy  0x02006238  thumb
 *   PM_VOICE_Start  0x02006A64  thumb
 *   PM_VOICE_IsActive  0x02006BD0  thumb
 *   INTRO_G3D_SetSlotAnim  0x021BF744  thumb ov204
 *   INTRO_G3D_MoveSlot1  0x021BF864  thumb ov204
 */
#include "../include/Obj08382.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void GFL_USE_PlaySeDefaultVolume(u32);
extern int  GFL_USE_IsAnySeBusy(void);
extern int PM_VOICE_Start(u32 idx);
extern u32 PM_VOICE_IsActive(u32 i);
extern void INTRO_G3D_SetSlotAnim(char *p, unsigned int i, unsigned int flag, unsigned int v);
extern int INTRO_G3D_MoveSlot1(char *p, int delta, int limit);

int INTRO_CMD_CmdMoveVoice(u8 *p, u32 *q)
{
    switch (*q) {
    case 0:
        if (q[1] == 3) {
            q[1] = 0;
            (*q)++;
        } else {
            q[1] = q[1] + 1;
        }
        break;
    case 1:
        if (INTRO_G3D_MoveSlot1((char *)(((struct Obj08382 *)p)->f8), 0x1000, 0xFFFF4800) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x7F5);
            (*q)++;
        }
        break;
    case 2:
        if (GFL_USE_IsAnySeBusy() == 0) {
            INTRO_G3D_SetSlotAnim((char *)(((struct Obj08382 *)p)->f8), 1, 0, 1);
            PM_VOICE_Start(*(u32 *)(((struct Obj08382 *)p)->f4 + 0x10));
            (*q)++;
        }
        break;
    case 3:
        if (PM_VOICE_IsActive(*(u32 *)(((struct Obj08382 *)p)->f4 + 0x10)) == 0) {
            *q = 0;
            return 1;
        }
        break;
    }
    return 0;
}

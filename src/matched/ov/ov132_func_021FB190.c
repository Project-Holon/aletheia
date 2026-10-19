/*
 * function: SCRIPT_COMMAND_TaskCameraTarget
 * address: 0x021FB190
 * packet: pkt_ov132_021FB190
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STA_ACT_SCRIPT_StepTaskInt 0x021FAE1C thumb ov132
 *   STA_ACTING_SetCameraTarget 0x021F9E08 thumb ov132
 *   STA_ACTING_SetCameraHoldScript 0x021F9E40 thumb ov132
 *   STA_ACT_SCRIPT_RemoveTask 0x021FADF8 thumb ov132
 */
#include "../include/Obj08161.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int STA_ACT_SCRIPT_StepTaskInt(char *, int *);
typedef unsigned int   u32;
extern void STA_ACTING_SetCameraTarget(u8 *p, u16 v);
extern void STA_ACTING_SetCameraHoldScript(u8 *p, u32 v);
extern void STA_ACT_SCRIPT_RemoveTask(char *, char *);
void SCRIPT_COMMAND_TaskCameraTarget(void *unused, char *p)
{
    int v;
    int done = STA_ACT_SCRIPT_StepTaskInt(p, &v);
    STA_ACTING_SetCameraTarget(((struct Obj08161 *)p)->f0, v);
    if (done == 1) {
        STA_ACTING_SetCameraHoldScript(((struct Obj08161 *)p)->f0, 0);
        STA_ACT_SCRIPT_RemoveTask(*(char * *)&((struct Obj08161 *)p)->f10, *(char * *)&((struct Obj08161 *)p)->f14);
    }
}

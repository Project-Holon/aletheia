/*
 * function: SCRIPT_COMMAND_CmdSetCameraTarget
 * address: 0x021FB104
 * packet: pkt_ov132_021FB104
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   func_02030734 0x02030734 arm
 *   STA_ACTING_GetCameraTarget 0x021F9E04 thumb ov132
 *   STA_ACTING_SetCameraTarget 0x021F9E08 thumb ov132
 *   STA_ACT_SCRIPT_AddTask 0x021FADA0 thumb ov132
 *   SCRIPT_COMMAND_TaskCameraTarget 0x021FB190 thumb ov132
 *   d_021FDD00 0x021FDD00 data ov132 a4
 */
#include "../include/Obj03820.h"
#include "../include/Obj06491.h"
#include "../include/Obj08160.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021FDD00[];
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
typedef unsigned char  u8;
extern u16 STA_ACTING_GetCameraTarget(u8 *p);
extern void STA_ACTING_SetCameraTarget(u8 *p, u16 v);
extern void *STA_ACT_SCRIPT_AddTask(char *, u32, u32, u32);
extern void SCRIPT_COMMAND_TaskCameraTarget(void *unused, char *p);
int SCRIPT_COMMAND_CmdSetCameraTarget(void *unused, char *ctx)
{
    char *p;
    char *owner;
    int time;
    int target;
    int wait;
    owner = *(char * *)&((struct Obj06491 *)ctx)->f0;
    time = VM_GetU32(((struct Obj06491 *)ctx)->f4);
    target = VM_GetU32(((struct Obj06491 *)ctx)->f4);
    wait = VM_GetU32(((struct Obj06491 *)ctx)->f4);
    if (time == 0) {
        STA_ACTING_SetCameraTarget(((struct Obj08160 *)owner)->f34, target);
    } else {
        p = func_02030734(((struct Obj08160 *)owner)->f0, 0x18, 0, d_021FDD00, 0x225);
        *(char * *)&((struct Obj03820 *)p)->f10 = owner;
        ((struct Obj03820 *)p)->f0 = ((struct Obj08160 *)owner)->f34;
        ((struct Obj03820 *)p)->fE = 0;
        ((struct Obj03820 *)p)->f4 = STA_ACTING_GetCameraTarget(((struct Obj08160 *)owner)->f34);
        ((struct Obj03820 *)p)->f8 = target;
        ((struct Obj03820 *)p)->fC = time;
        ((struct Obj03820 *)p)->f14 = STA_ACT_SCRIPT_AddTask(owner, (u32)SCRIPT_COMMAND_TaskCameraTarget, (u32)p, 10);
        if (wait == 1) {
            ((struct Obj06491 *)ctx)->f14 = ((struct Obj03820 *)p)->fC;
            return 1;
        }
    }
    return 0;
}

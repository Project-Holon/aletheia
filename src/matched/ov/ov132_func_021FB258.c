/*
 * function: SCRIPT_COMMAND_CmdSetActorVisible
 * address: 0x021FB258
 * packet: pkt_ov132_021FB258
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: inferred extent ends with two zero padding bytes before the next labelled function.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   SCRIPT_COMMAND_GetActorMask 0x021FB1F4 thumb ov132
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   STA_ACT_LIGHT_SetActorFlagB 0x021F812C thumb ov112
 */
#include "../include/Obj10549.h"
#include "../include/Obj14102.h"
typedef unsigned char u8;
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
extern int SCRIPT_COMMAND_GetActorMask(char *, int);
typedef unsigned int   u32;
extern void *STA_ACTING_GetActorSystem(char *p);
extern void *STA_ACTING_GetActor(char *p, u32 i);
extern int STA_ACT_LIGHT_SetActorFlagB(int unused, int *p, int flag);
int SCRIPT_COMMAND_CmdSetActorVisible(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct Obj10549 *)p)->f0;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct Obj10549 *)p)->f4));
    value = VM_GetU32(((struct Obj10549 *)p)->f4);
    ctx = STA_ACTING_GetActorSystem(((struct Obj14102 *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            char *slot;
            int flag;
            slot = STA_ACTING_GetActor(((struct Obj14102 *)obj)->f34, i);
            flag = 0;
            if (value != 0) flag = 1;
            STA_ACT_LIGHT_SetActorFlagB((int)ctx, (int *)slot, flag);
        }
    }
    return 0;
}

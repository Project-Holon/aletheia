/*
 * function: SCRIPT_COMMAND_CmdSetActorScale
 * address: 0x021FB640
 * packet: pkt_ov132_021FB640
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
 *   STA_ACT_LIGHT_CallElemE 0x021F8140 thumb ov112
 */
#include "../include/Obj10550.h"
#include "../include/Obj14107.h"
typedef unsigned char u8;
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *p);
extern int SCRIPT_COMMAND_GetActorMask(char *, int);
typedef unsigned int   u32;
extern void *STA_ACTING_GetActorSystem(char *p);
extern void *STA_ACTING_GetActor(char *p, u32 i);
extern void STA_ACT_LIGHT_CallElemE(int a, u8 *p, int b);
int SCRIPT_COMMAND_CmdSetActorScale(int unused, char *p)
{
    char *obj;
    int mask;
    int value;
    char *ctx;
    u8 i;
    obj = *(char * *)&((struct Obj10550 *)p)->f0;
    mask = SCRIPT_COMMAND_GetActorMask(p, VM_GetU32(((struct Obj10550 *)p)->f4));
    value = VM_GetU32(((struct Obj10550 *)p)->f4);
    ctx = STA_ACTING_GetActorSystem(((struct Obj14107 *)obj)->f34);
    for (i = 0; i < 4; i++) {
        if ((1 << i) & mask) {
            STA_ACT_LIGHT_CallElemE((int)ctx, STA_ACTING_GetActor(((struct Obj14107 *)obj)->f34, i), value != 0);
        }
    }
    return 0;
}

/*
 * function: SCRIPT_COMMAND_TaskActorMove
 * address: 0x021FB528
 * packet: pkt_ov132_021FB528
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Void callback return omits the extra zero result instruction.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACT_SCRIPT_StepTaskVec 0x021FAE4C thumb ov132
 *   STA_ACT_LIGHT_SetActorPos 0x021F8054 thumb ov112
 *   STA_ACT_SCRIPT_RemoveTask 0x021FADF8 thumb ov132
 */
#include "../include/Obj08163.h"
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *);
extern void *STA_ACTING_GetActorSystem(char *p);
extern int STA_ACT_SCRIPT_StepTaskVec(char *,int *);
extern void STA_ACT_LIGHT_SetActorPos(void *,unsigned int *,const unsigned int *);
extern void STA_ACT_SCRIPT_RemoveTask(char *p, char *q);
void SCRIPT_COMMAND_TaskActorMove(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=STA_ACTING_GetActorSystem(((struct Obj08163 *)p)->f4); result=STA_ACT_SCRIPT_StepTaskVec(p+4,pos); STA_ACT_LIGHT_SetActorPos(ctx,*(unsigned int * *)&((struct Obj08163 *)p)->f0,(unsigned int *)pos); if(result==1)STA_ACT_SCRIPT_RemoveTask(((struct Obj08163 *)p)->f30,((struct Obj08163 *)p)->f34); }

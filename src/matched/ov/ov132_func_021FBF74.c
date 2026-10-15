/*
 * function: SCRIPT_COMMAND_TaskEntryTarget
 * address: 0x021FBF74
 * packet: pkt_ov132_021FBF74
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   STA_ACTING_GetActObj 0x021F9DAC thumb ov132
 *   STA_ACT_SCRIPT_StepTaskVec 0x021FAE4C thumb ov132
 *   STA_ACT_OBJ_SetEntryTarget 0x021F6B9C thumb ov112
 *   STA_ACT_SCRIPT_RemoveTask 0x021FADF8 thumb ov132
 */
#include "../include/Obj08168.h"
struct Cursor;
extern unsigned int VM_GetU32(struct Cursor *);
extern void *STA_ACTING_GetActObj(void *);
extern int STA_ACT_SCRIPT_StepTaskVec(char *,int *);
extern void STA_ACT_OBJ_SetEntryTarget(void *,unsigned int *,unsigned int *);
extern void STA_ACT_SCRIPT_RemoveTask(char *p, char *q);
void SCRIPT_COMMAND_TaskEntryTarget(int unused,char *p) { int pos[3]; void *ctx; int result;ctx=STA_ACTING_GetActObj(((struct Obj08168 *)p)->f4);result=STA_ACT_SCRIPT_StepTaskVec(p+4,pos);STA_ACT_OBJ_SetEntryTarget(ctx,*(unsigned int * *)&((struct Obj08168 *)p)->f0,(unsigned int *)pos);if(result==1)STA_ACT_SCRIPT_RemoveTask(((struct Obj08168 *)p)->f30,((struct Obj08168 *)p)->f34);}

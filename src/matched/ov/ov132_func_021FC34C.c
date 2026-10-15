/*
 * function: SCRIPT_COMMAND_TaskCharMove
 * address: 0x021FC34C
 * packet: pkt_ov132_021FC34C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STA_ACTING_GetCharSystem 0x021F9DD4 thumb ov132
 *   STA_ACT_SCRIPT_StepTaskVec 0x021FAE4C thumb ov132
 *   STA_ACT_LIGHT_CopyElemA 0x021F6EF4 thumb ov112
 *   STA_ACT_SCRIPT_RemoveTask 0x021FADF8 thumb ov132
 */
#include "../include/Obj08171.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern void *STA_ACTING_GetCharSystem(void *);
extern int STA_ACT_SCRIPT_StepTaskVec(char *,int *);
extern void STA_ACT_LIGHT_CopyElemA(void *,u32 *,const u32 *);
extern void STA_ACT_SCRIPT_RemoveTask(char *,char *);
void SCRIPT_COMMAND_TaskCharMove(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=STA_ACTING_GetCharSystem(((struct Obj08171 *)p)->f4); result=STA_ACT_SCRIPT_StepTaskVec(p+4,pos); STA_ACT_LIGHT_CopyElemA(ctx,*(u32 * *)&((struct Obj08171 *)p)->f0,(u32 *)pos); if(result==1) STA_ACT_SCRIPT_RemoveTask(*(char * *)&((struct Obj08171 *)p)->f30,*(char * *)&((struct Obj08171 *)p)->f34); }

/*
 * function: SCRIPT_COMMAND_TaskCharFollow
 * address: 0x021FC490
 * packet: pkt_ov132_021FC490
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STA_ACTING_GetCharSystem 0x021F9DD4 thumb ov132
 *   STA_ACTING_GetAudience 0x021F9DF4 thumb ov132
 *   STA_ACT_SCRIPT_StepTaskActor 0x021FAEA8 thumb ov132
 *   STA_ACT_LIGHT_CopyElemA 0x021F6EF4 thumb ov112
 *   STA_ACT_SCRIPT_RemoveTask 0x021FADF8 thumb ov132
 */
#include "../include/Obj06492.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern void *STA_ACTING_GetCharSystem(void *);
extern void *STA_ACTING_GetAudience(void *p);
extern int STA_ACT_SCRIPT_StepTaskActor(char *,void *);
extern void STA_ACT_LIGHT_CopyElemA(void *,u32 *,const u32 *);
extern void STA_ACT_SCRIPT_RemoveTask(char *,char *);
void SCRIPT_COMMAND_TaskCharFollow(int unused,char *p) { int pos[3]; void *ctx; int result; ctx=STA_ACTING_GetCharSystem(((struct Obj06492 *)p)->f8); STA_ACTING_GetAudience(((struct Obj06492 *)p)->f8); result=STA_ACT_SCRIPT_StepTaskActor(p+8,pos); STA_ACT_LIGHT_CopyElemA(ctx,*(u32 * *)&((struct Obj06492 *)p)->f4,(u32 *)pos); if(result==1) STA_ACT_SCRIPT_RemoveTask(*(char * *)&((struct Obj06492 *)p)->f28,*(char * *)&((struct Obj06492 *)p)->f2C); }

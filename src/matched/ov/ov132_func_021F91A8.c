/*
 * function: STA_ACTING_LoadAnimMember
 * address: 0x021F91A8
 * packet: pkt_ov132_021F91A8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   ARC_UTIL_LoadHandleMember 0x0204A380 arm
 *   STA_ACT_SCRIPT_AddScriptFromTable 0x021FAD0C thumb ov132
 */
#include "../include/Obj10531.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern void *ARC_UTIL_LoadHandleMember(void *a0, u32 a1, u32 a2, u32 a3);
extern char *STA_ACT_SCRIPT_AddScriptFromTable(char *p, char *base, unsigned index, unsigned char flag);
void STA_ACTING_LoadAnimMember(char *p, u8 n, u8 mask){void *table;table=ARC_UTIL_LoadHandleMember((void *)(((struct Obj10531 *)p)->f18),n+0x4b,0,((struct Obj10531 *)p)->f0);STA_ACT_SCRIPT_AddScriptFromTable(((struct Obj10531 *)p)->fB0,table,0,mask);}

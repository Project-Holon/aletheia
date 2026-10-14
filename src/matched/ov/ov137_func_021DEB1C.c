/*
 * function: GURU2_MAIN_StateWaitAllMembers
 * address: 0x021DEB1C
 * packet: pkt_ov137_021DEB1C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_CountReadyMembers 0x021E170C thumb ov137
 *   GURU2_MAIN_GetUnionApp 0x021DEB10 thumb ov137
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 */
#include "../include/Obj01753.h"
typedef unsigned short u16;
extern int GURU2_MAIN_CountReadyMembers(char *);
extern void *GURU2_MAIN_GetUnionApp(char *);
extern int UNION_APP_GetMemberCount(unsigned char *p);
int GURU2_MAIN_StateWaitAllMembers(char *p) {unsigned v;v=GURU2_MAIN_CountReadyMembers(p)+1;if(v!=UNION_APP_GetMemberCount(GURU2_MAIN_GetUnionApp(p)))return 0;((struct Obj01753 *)p)->f0=5;return 1;}

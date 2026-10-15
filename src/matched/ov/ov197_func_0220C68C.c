/*
 * function: func_0220C68C
 * address: 0x0220C68C
 * packet: pkt_ov197_0220C68C
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_APP_TOOL_CreateActors 0x0220AF6C thumb ov196
 *   B_APP_TOOL_SetActorsVisible 0x0220AFDC thumb ov196
 */
#include "../include/Obj00315.h"
extern void B_APP_TOOL_CreateActors(char *,int,int,int,int),B_APP_TOOL_SetActorsVisible(char *,void *);
void func_0220C68C(char *p){B_APP_TOOL_CreateActors(*(char * *)&((struct Obj00315 *)p)->f148,*(int *)&((struct Obj00315 *)p)->f420,((struct Obj00315 *)p)->f564,((struct Obj00315 *)p)->f588,((struct Obj00315 *)p)->f594);B_APP_TOOL_SetActorsVisible(*(char * *)&((struct Obj00315 *)p)->f148,0);}

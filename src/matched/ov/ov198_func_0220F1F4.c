/*
 * function: func_0220F1F4
 * address: 0x0220F1F4
 * packet: pkt_ov198_0220F1F4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_APP_TOOL_CreateActors 0x0220AF6C thumb ov196
 *   B_APP_TOOL_SetActorsVisible 0x0220AFDC thumb ov196
 */
#include "../include/Obj00172.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void B_APP_TOOL_CreateActors(char *,int,int,int,int),B_APP_TOOL_SetActorsVisible(char *,void *);
void func_0220F1F4(u8 *p) { B_APP_TOOL_CreateActors(*(char * *)&((struct Obj00172 *)p)->f2188,*(int *)&((struct Obj00172 *)p)->f1EB8,((struct Obj00172 *)p)->f2504,((struct Obj00172 *)p)->f251C,((struct Obj00172 *)p)->f2534);B_APP_TOOL_SetActorsVisible(*(char * *)&((struct Obj00172 *)p)->f2188,0); }

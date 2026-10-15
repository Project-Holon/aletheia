/*
 * function: DIGITALCARDCHECK_End
 * address: 0x0217D010
 * packet: pkt_ov176_0217D010
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   LIVEBATTLEMATCH_FLOW_End 0x0217BBD4 thumb ov176
 */
#include "../include/Obj14365.h"
typedef unsigned char u8;
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *,int);
extern void LIVEBATTLEMATCH_FLOW_End(int);
void DIGITALCARDCHECK_End(u8 *p,int v){((struct Obj14365 *)p)->f19C=v;WIFIBATTLEMATCH_UTIL_SetCallback(*(int * *)&((struct Obj14365 *)p)->f0,(int)LIVEBATTLEMATCH_FLOW_End);}

/*
 * function: BR_POKESEARCH_DestroyDetail
 * address: 0x021F8E60
 * packet: pkt_ov185_021F8E60
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BR_BTN_DeleteObject 0x021FB494 thumb ov186
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 */
#include "../include/Obj04583.h"
#include "../include/Obj06623.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void BR_RES_ApplyBgSet(int,unsigned);
extern void BR_BTN_DeleteObject(char *p);
extern void BR_UTIL_Delete(u8 *p);
void BR_POKESEARCH_DestroyDetail(char *p,char *q) { if(((struct Obj06623 *)p)->f1C){BR_RES_ApplyBgSet(*(int *)&((struct Obj04583 *)q)->fC,22);BR_BTN_DeleteObject(((struct Obj06623 *)p)->f18);((struct Obj06623 *)p)->f18=0;BR_UTIL_Delete(((struct Obj06623 *)p)->f1C);((struct Obj06623 *)p)->f1C=0;BR_RES_ApplyBgSet(*(int *)&((struct Obj04583 *)q)->fC,22);} }

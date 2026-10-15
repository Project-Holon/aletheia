/*
 * function: LOCAL_TVT_CHARA_LoadPalette
 * address: 0x021B7180
 * packet: pkt_ov174_021B7180
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   ARC_UTIL_LoadBgCharDataFromHandle 0x02049DF4 arm
 */
#include "../include/Obj14322.h"
#include "../include/Obj24208.h"
extern void *ARC_UTIL_LoadBgCharDataFromHandle(void *,unsigned,unsigned,unsigned,unsigned short);
void LOCAL_TVT_CHARA_LoadPalette(char *p, char *q, int id) {((struct Obj24208 *)q)->f10=ARC_UTIL_LoadBgCharDataFromHandle(((struct Obj14322 *)p)->f18,id,0,(unsigned)(q+12),((struct Obj14322 *)p)->f0);}

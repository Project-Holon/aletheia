/*
 * function: WIFICLUBACTOR_RestoreActorUpdate
 * address: 0x021B9AE0
 * packet: pkt_ov099_021B9AE0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C57D8 0x021C57D8 thumb ov127
 */
#include "../include/Obj04411.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C57D8(u8 *p, int v);
void WIFICLUBACTOR_RestoreActorUpdate(void *w,u8 *s) { if (s) { if (((struct Obj04411 *)s)->f14) { ((struct Obj04411 *)s)->f10=((struct Obj04411 *)s)->f14; ((struct Obj04411 *)s)->f14=0; ((struct Obj04411 *)s)->fC=((struct Obj04411 *)s)->fE; func_021C57D8(((struct Obj04411 *)s)->f4,1); } } }

/*
 * function: func_021B7F60
 * address: 0x021B7F60
 * packet: pkt_ov103_021B7F60
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02047804 0x02047804 arm
 */
#include "../include/Obj10243.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct AnmCtl;
extern u32 func_02047804(struct AnmCtl *c, u16 idx);
void func_021B7F60(u8 *p,int n) {if(((struct Obj10243 *)p)->f58!=n) {func_02047804(((struct Obj10243 *)p)->f10,0); ((struct Obj10243 *)p)->f58=n;}}

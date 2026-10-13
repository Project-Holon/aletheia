/*
 * function: func_021D50DC
 * address: 0x021D50DC
 * packet: pkt_ov122_021D50DC
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   func_02082D44 0x02082D44 arm
 */
#include "../include/Obj13966.h"
#include "../include/Obj22933.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *GFL_NET_GetInitParam(void);extern void func_02082D44(const void *,void *,u32);
void func_021D50DC(char *p) {u8 buf[6]={0};GFL_NET_GetInitParam();((struct Obj22933 *)(*(char * *)&((struct Obj13966 *)p)->f344))->f10=1;func_02082D44(buf,*(char * *)&((struct Obj13966 *)p)->f344+20,6);}

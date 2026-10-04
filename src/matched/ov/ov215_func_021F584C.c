/*
 * function: func_021F584C
 * address: 0x021F584C
 * packet: pkt_ov215_021F584C
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203133C 0x0203133C arm
 *   func_021F5EC8 0x021F5EC8 thumb ov215
 *   func_021F5CFC 0x021F5CFC thumb ov215
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj14704.h"
typedef unsigned int u32;
struct S020314B8;struct S020315D4;
extern void func_0203133C(struct S020314B8 *),func_020315D4(struct S020315D4 *),func_020306F0(u32);
extern void func_021F5EC8(u32,char *),func_021F5CFC(u32,char *);
int func_021F584C(struct S020315D4 *task,int unused,u32 a,char *p) { func_0203133C(*(struct S020314B8 * *)&((struct Obj14704 *)p)->f88);func_021F5EC8(a,p);if(((struct Obj14704 *)p)->f10!=17)func_021F5CFC(a,p);func_020315D4(task);func_020306F0(143);return 1; }

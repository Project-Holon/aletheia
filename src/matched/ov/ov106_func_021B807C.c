/*
 * function: func_021B807C
 * address: 0x021B807C
 * packet: pkt_ov106_021B807C
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021B7FC8 0x021B7FC8 thumb ov106
 *   func_021B7F00 0x021B7F00 thumb ov106
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj22261.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_021B7FC8(void **);
extern void func_021B7F00(u32 *);
extern void MI_CpuFill8(void *,int,int);
void func_021B807C(u8 *p) { func_02030EAC(((struct Obj22261 *)p)->f24); func_021B7FC8((void **)(p+16)); func_021B7F00((u32 *)p); MI_CpuFill8(p,0,40); }

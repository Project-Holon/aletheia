/*
 * function: func_021B78A0
 * address: 0x021B78A0
 * packet: pkt_ov105_021B78A0
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021B7A3C 0x021B7A3C thumb ov105
 *   func_021B7BC0 0x021B7BC0 thumb ov105
 */
#include "../include/Obj22240.h"
struct Node; extern void func_02030EAC(struct Node *); extern void func_021B7A3C(unsigned int *); extern void func_021B7BC0(void **);
void func_021B78A0(unsigned char *p) { func_02030EAC(*(struct Node * *)&((struct Obj22240 *)p)->fAC); func_021B7A3C((unsigned int *)p); func_021B7BC0((void **)(p+4)); }

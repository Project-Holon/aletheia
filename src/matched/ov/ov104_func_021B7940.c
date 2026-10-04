/*
 * function: func_021B7940
 * address: 0x021B7940
 * packet: pkt_ov104_021B7940
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow compiled code.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021B7AD4 0x021B7AD4 thumb ov104
 *   func_021B7CA4 0x021B7CA4 thumb ov104
 */
#include "../include/Obj22216.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Node;
extern void func_02030EAC(struct Node *);
extern void func_021B7AD4(u32 *);
extern void func_021B7CA4(void **);
void func_021B7940(u8 *p) { func_02030EAC(*(struct Node * *)&((struct Obj22216 *)p)->fB8); func_021B7AD4((u32 *)p); func_021B7CA4((void **)(p+4)); }

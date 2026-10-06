/*
 * function: func_021F5400
 * address: 0x021F5400
 * packet: pkt_ov083_021F5400
 * region: ov083
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_02010F8C 0x02010F8C thumb
 *   func_0216D9E4 0x0216D9E4 thumb ov010
 */
#include "../include/Obj05165.h"
typedef unsigned char u8;
struct Rec;
struct U16Vec;
struct WordSet;
extern void func_02045808(struct U16Vec *vec);
typedef unsigned int   u32;
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02010F8C(void *p);
extern u32 *func_0216D9E4(void *c);
void func_021F5400(u8 *p) { func_02045808(((struct Obj05165 *)p)->f38);func_02045808(((struct Obj05165 *)p)->f34);func_0201ED04(((struct Obj05165 *)p)->f2C);func_02045C04(((struct Obj05165 *)p)->f28);func_02010F8C(((struct Obj05165 *)p)->f30);func_0216D9E4(((struct Obj05165 *)p)->f1C); }

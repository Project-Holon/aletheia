/*
 * function: func_021B7DAC
 * address: 0x021B7DAC
 * packet: pkt_ov104_021B7DAC
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj07988.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WordSet; struct Rec;
extern void func_0201ED04(struct WordSet *);
extern void func_02045C04(struct Rec *);
struct PrintSys;
extern void func_0201C4C0(struct PrintSys *p);
extern void func_0201D83C(void *);
extern void func_02082BCC(void *,int,int);
void func_021B7DAC(u8 *p) { func_0201ED04(*(struct WordSet * *)&((struct Obj07988 *)p)->fC); func_02045C04(*(struct Rec * *)&((struct Obj07988 *)p)->f4); func_0201C4C0(((struct Obj07988 *)p)->f8); func_0201D83C(((struct Obj07988 *)p)->f0); func_02082BCC(p,0,16); }

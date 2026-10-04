/*
 * function: func_02210774
 * address: 0x02210774
 * packet: pkt_ov198_02210774
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj06656.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec;struct WordSet;struct PrintSys;struct U16Vec;
extern void func_02045C04(struct Rec *),func_0201D83C(void *),func_0201ED04(struct WordSet *),func_0201C4C0(struct PrintSys *),func_02045808(struct U16Vec *);
void func_02210774(u8 *p) { func_02045C04(*(struct Rec * *)&((struct Obj06656 *)p)->f1EA0);func_0201D83C(((struct Obj06656 *)p)->f1E9C);func_0201ED04(*(struct WordSet * *)&((struct Obj06656 *)p)->f1EA4);func_0201C4C0(*(struct PrintSys * *)&((struct Obj06656 *)p)->f1EAC);func_02045808(*(struct U16Vec * *)&((struct Obj06656 *)p)->f1EA8); }

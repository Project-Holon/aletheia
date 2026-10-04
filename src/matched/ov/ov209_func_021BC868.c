/*
 * function: func_021BC868
 * address: 0x021BC868
 * packet: pkt_ov209_021BC868
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 */
#include "../include/Obj00088.h"
struct U16Vec;struct PrintSys;struct WordSet;struct Rec;extern void func_02045808(struct U16Vec *);extern void func_0201C4C0(struct PrintSys *);extern void func_0201ED04(struct WordSet *);extern void func_0201D83C(void *);extern void func_02045C04(struct Rec *);
void func_021BC868(char *p){func_02045808(*(struct U16Vec * *)&((struct Obj00088 *)p)->f44);func_0201C4C0(*(struct PrintSys * *)&((struct Obj00088 *)p)->f48);func_0201ED04(*(struct WordSet * *)&((struct Obj00088 *)p)->f40);func_0201D83C(((struct Obj00088 *)p)->f38);func_02045C04(*(struct Rec * *)&((struct Obj00088 *)p)->f3C);}

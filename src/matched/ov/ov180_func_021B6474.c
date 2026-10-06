/*
 * function: func_021B6474
 * address: 0x021B6474
 * packet: pkt_ov180_021B6474
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 */
#include "../include/Obj05469.h"
typedef unsigned int u32;
typedef unsigned short u16;
struct WordSet; struct Rec;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
void func_021B6474(char *p) {func_02045808(((struct Obj05469 *)p)->f9040);func_0201ED04(*(struct WordSet * *)&((struct Obj05469 *)p)->f903C);func_0201D83C(((struct Obj05469 *)p)->f9034);func_0201D83C(((struct Obj05469 *)p)->f9030);func_02045C04(*(struct Rec * *)&((struct Obj05469 *)p)->f9038);}

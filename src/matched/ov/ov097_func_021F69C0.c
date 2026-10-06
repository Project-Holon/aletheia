/*
 * function: func_021F69C0
 * address: 0x021F69C0
 * packet: pkt_ov097_021F69C0
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 */
#include "../include/Obj06345.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct PrintSys;
struct Rec;
struct WordSet;
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201C4C0(struct PrintSys *p);
void func_021F69C0(u8 *p) { func_02045C04(((struct Obj06345 *)p)->f14); func_0201D83C(((struct Obj06345 *)p)->fC); func_0201D83C(((struct Obj06345 *)p)->f10); func_0201ED04(((struct Obj06345 *)p)->f18); func_0201C4C0(((struct Obj06345 *)p)->f1C); }

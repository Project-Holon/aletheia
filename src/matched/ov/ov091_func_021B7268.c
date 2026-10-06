/*
 * function: func_021B7268
 * address: 0x021B7268
 * packet: pkt_ov091_021B7268
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 */
#include "../include/Obj06209.h"
struct PrintSys;
struct Rec;
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_02045C04(struct Rec *rec);
typedef unsigned int   u32;
extern u32 func_0201D83C(void *ptr);
void func_021B7268(unsigned p) { func_0201C6EC((struct PrintSys *)(((struct Obj06209 *)p)->f140)); func_0201C4C0((struct PrintSys *)(((struct Obj06209 *)p)->f140)); func_02045C04((struct Rec *)(((struct Obj06209 *)p)->f134)); func_0201D83C(((struct Obj06209 *)p)->f13C); func_0201D83C(((struct Obj06209 *)p)->f138); }

/*
 * function: func_021BF510
 * address: 0x021BF510
 * packet: pkt_ov203_021BF510
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_021BF550 0x021BF550 thumb ov203
 *   func_021BF710 0x021BF710 thumb ov203
 */
#include "../include/Obj03917.h"
struct Context;
struct S02030FB4;
struct TcblNode;
extern void * func_020311B8(void *,void (*)(void *,void *),unsigned,unsigned);
extern void *func_02031290(struct S02030FB4 *p);
extern void func_021BF550(struct TcblNode *task, struct Context *ctx);
extern void func_021BF710(char *,void *,int,int,int,int,int,int);
void func_021BF510(char *p,int a,int b,int c,int d,int e,int f)
{
    func_021BF710(p,func_02031290(func_020311B8(((struct Obj03917 *)p)->f20,(void (*)(void *, void *))func_021BF550,0x2C,1)),a,b,c,d,e,f);
}

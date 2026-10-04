/*
 * function: func_021B9AE4
 * address: 0x021B9AE4
 * region: ov223
 * isa: thumb
 * packet: pkt_ov223_021B9AE4
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT*
 * symbols:
 *   table 0x021BC78C data a4
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021B95A0 0x021B95A0 thumb ov223
 *   func_021BC52C 0x021BC52C thumb ov223
 *   func_02011B8C 0x02011B8C thumb
 */
#include "../include/Obj05572.h"
typedef unsigned short u16;
extern u16 table[][5];
extern int func_021B95A0(int,int);
extern unsigned func_021BC52C(unsigned char *p);
extern void func_02011B8C(void *,void *);
void func_021B9AE4(char *p,int type,int flag)
{
    u16 v;
    float f;
    v=table[type][flag?1:0];
    if(v!=0) f=0.5f+(float)(v<<12);
    else f=(float)(v<<12)-0.5f;
    func_021B95A0(*(int *)&((struct Obj05572 *)p)->f40,(int)f);
    func_02011B8C((void *)func_021BC52C(((struct Obj05572 *)p)->f14),((struct Obj05572 *)p)->f40);
    ((struct Obj05572 *)p)->f44=type;
    ((struct Obj05572 *)p)->f48=flag;
    ((struct Obj05572 *)p)->f4C=v;
}

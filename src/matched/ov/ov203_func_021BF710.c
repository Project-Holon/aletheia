/*
 * function: func_021BF710
 * address: 0x021BF710
 * packet: pkt_ov203_021BF710
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02049658 0x02049658 arm
 */
#include "../include/Obj03917.h"
typedef struct { char *ctx;int pad4[2];int c;int a;int b;int d;int e;int f;int pad24[2]; } Work;
extern void func_02082BCC(void *,int,int);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
void func_021BF710(char *p,Work *out,int a,int b,int c,int d,int e,int f)
{
    func_02082BCC(out,0,0x2C);
    out->ctx=p;out->c=d;out->a=a;out->d=c;out->b=b;out->e=e;out->f=f;
    func_02049658((void *)(((struct Obj03917 *)p)->f28),out->b,1,0,0,1,((struct Obj03917 *)p)->f2);
}

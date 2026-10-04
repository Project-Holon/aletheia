/*
 * function: func_021BE4A8
 * address: 0x021BE4A8
 * packet: pkt_ov209_021BE4A8
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD8D8 0x021BD8D8 thumb ov209
 */
#include "../include/Obj08412.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_021BD8D8(char *p, u32 idx, u32 value);
void func_021BE4A8(char *p)
{
    unsigned i;
    for(i=10;i<26;i++)if(((struct Obj08412 *)p)->fC28&(1<<(i-10)))func_021BD8D8(p,i,0);
    for(i=26;i<42;i++)if(((struct Obj08412 *)p)->fC2A&(1<<(i-26))){func_021BD8D8(p,i,0);func_021BD8D8(p,i+16,0);}
    ((struct Obj08412 *)p)->fC28=0;
    ((struct Obj08412 *)p)->fC2A=0;
}

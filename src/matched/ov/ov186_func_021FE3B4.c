/*
 * function: func_021FE3B4
 * address: 0x021FE3B4
 * packet: pkt_ov186_021FE3B4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: The two-word origin copy is a Pair assignment; separate field stores reorder it.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021FE3E4 0x021FE3E4 thumb ov186
 */
#include "../include/Obj10797.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Pair{int x,y;} Pair;
extern void func_02082BCC(void *,int,int);
extern int func_021FE3E4(char *p, int *out, int step);
int func_021FE3B4(u8 *p,const Pair *origin,u16 a,u16 b,int duration)
{
    func_02082BCC(p,0,24);
    *(Pair *)p=*origin;
    ((struct Obj10797 *)p)->f14=duration;
    ((struct Obj10797 *)p)->f10=a;
    ((struct Obj10797 *)p)->f12=b;
    return func_021FE3E4((char *)p,0,0);
}

/*
 * function: func_021FE2BC
 * address: 0x021FE2BC
 * packet: pkt_ov186_021FE2BC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: A named x load before the last halfword store preserves the interleaved copy.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021FE2F8 0x021FE2F8 thumb ov186
 */
#include "../include/Obj01284.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Pair{int x,y;} Pair;
extern void MI_CpuFill8(void *,int,int);
extern int func_021FE2F8(char *,int *,int);
int func_021FE2BC(u8 *p,const Pair *origin,u16 a,u16 b,u16 c,u16 d,int duration)
{
    int x;
    MI_CpuFill8(p,0,28);
    ((struct Obj01284 *)p)->f10=a;
    ((struct Obj01284 *)p)->f12=b;
    ((struct Obj01284 *)p)->f14=c;
    x=origin->x;
    ((struct Obj01284 *)p)->f16=d;
    ((struct Obj01284 *)p)->f0=x;
    ((struct Obj01284 *)p)->f18=duration;
    ((struct Obj01284 *)p)->f4=origin->y;
    return func_021FE2F8((char *)p,(int *)(p+8),0);
}

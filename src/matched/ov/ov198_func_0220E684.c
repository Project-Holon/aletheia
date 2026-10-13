/*
 * function: func_0220E684
 * address: 0x0220E684
 * packet: pkt_ov198_0220E684
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 */
#include "../include/Obj00172.h"
#include "../include/Obj25220.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {short x,y,z; u8 a,b;} Point;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
unsigned func_0220E684(char *p,const int *q)
{
    Point point;
    point.x=0;
    point.y=0;
    point.z=0;
    point.a=q[4];
    point.b=q[3];
    return (unsigned)CLACT_CreateActor((void *)((struct Obj00172 *)p)->f1EB8,*(unsigned *)(p+q[0]*4+0x24a4),*(unsigned *)(p+q[1]*4+0x250c),*(unsigned *)(p+q[2]*4+0x2524),&point,1,((struct Obj25220 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
}

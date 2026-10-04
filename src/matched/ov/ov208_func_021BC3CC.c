/*
 * function: func_021BC3CC
 * address: 0x021BC3CC
 * packet: pkt_ov208_021BC3CC
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200D064 0x0200D064 thumb
 */
#include "../include/Obj01178.h"
extern void *func_0200CA1C(void *a);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Blk37;
extern u32 func_0200D064(struct Blk37 *p, u16 id);
void func_021BC3CC(char *p)
{
    unsigned short old=**(unsigned short * *)&((struct Obj01178 *)p)->f20;
    void *owner=func_0200CA1C((void *)(*(int *)&((struct Obj01178 *)p)->f0));
    do {
        ++**(unsigned short * *)&((struct Obj01178 *)p)->f20;
        if(**(unsigned short * *)&((struct Obj01178 *)p)->f20>=((struct Obj01178 *)p)->f1C)
            **(unsigned short * *)&((struct Obj01178 *)p)->f20=0;
        if(**(unsigned short * *)&((struct Obj01178 *)p)->f20==old)break;
    }while(func_0200D064(owner,(*(unsigned short **)(p+0x18))[**(unsigned short * *)&((struct Obj01178 *)p)->f20])==0);
}

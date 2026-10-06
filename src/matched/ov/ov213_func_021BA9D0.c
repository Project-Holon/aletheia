/*
 * function: func_021BA9D0
 * address: 0x021BA9D0
 * packet: pkt_ov213_021BA9D0
 * region: ov213
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_02047910 0x02047910 arm
 *   d_021BB320 0x021BB320 data a4
 * width: 47910 index u16: original narrows at 021BA9FA-021BAA00.
 */
#include "../include/Obj08420.h"
typedef unsigned short u16;
typedef struct Util Util;
extern int d_021BB320;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02048A18(u8 *a0, int i);
extern int func_0204779C(int *p);
extern int func_02047910(void *a, int idx, int amount);
int func_021BA9D0(unsigned char *p)
{
    int result=1;
    int *object;
    int count,i;
    if(p[14]) return 0;
    object=(int *)func_02048A18((u8 *)(*(Util * *)&((struct Obj08420 *)p)->f8), ((struct Obj08420 *)p)->fC);
    count=func_0204779C(object);
    for(i=0;i<count;i++) {
        result=func_02047910(object,(u16)i,d_021BB320<<12);
        if(!result) p[14]=1;
    }
    return result;
}

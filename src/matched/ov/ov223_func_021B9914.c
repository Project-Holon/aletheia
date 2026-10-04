/*
 * function: func_021B9914
 * address: 0x021B9914
 * region: ov223
 * isa: thumb
 * packet: pkt_ov223_021B9914
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_02047910 0x02047910 arm
 *   func_02011590 0x02011590 thumb
 *   func_021BC52C 0x021BC52C thumb ov223
 *   func_02011B8C 0x02011B8C thumb
 */
#include "../include/Obj01594.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char  u8;
extern u32 func_02048A18(u8 *a0, int i);
extern int func_0204779C(int *);
extern int func_02047910(void *,int,int);
typedef signed int     s32;
struct IcaAnime;
extern u32 func_02011590(struct IcaAnime *p, s32 v);
extern unsigned func_021BC52C(unsigned char *p);
extern void func_02011B8C(void *,void *);
void func_021B9914(char *p)
{
    int *obj;
    u32 n;
    u16 i,j;
    for(i=0;i<((struct Obj01594 *)p)->f3A;i++) {
        obj=(int *)func_02048A18(*(unsigned char * *)&((struct Obj01594 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj01594 *)p)->f3C+i*68));
        n=func_0204779C(obj);
        for(j=0;j<n;j++) func_02047910(obj,j,2048);
    }
    func_02011590(((struct Obj01594 *)p)->f40,2048);
    func_02011B8C((void *)func_021BC52C(((struct Obj01594 *)p)->f14),((struct Obj01594 *)p)->f40);
    (*(u32 *)&((struct Obj01594 *)p)->f50)++;
}

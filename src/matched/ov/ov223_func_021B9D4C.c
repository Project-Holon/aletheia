/*
 * function: func_021B9D4C
 * address: 0x021B9D4C
 * packet: pkt_ov223_021B9D4C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: keep 2*(state+2) grouped before adding the table-field base.
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_02047910 0x02047910 arm
 */
#include "../include/Obj00738.h"
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02048A18(u8 *a0, int i);
extern int func_0204779C(int *p);
extern int func_02047910(void *,int,int);
void func_021B9D4C(char *p)
{
    void *object;
    unsigned count;
    u16 i;
    if(((struct Obj00738 *)p)->f22C!=4) {
        object=(void *)func_02048A18(((struct Obj00738 *)p)->f28,*(u16 *)(*(char * *)&((struct Obj00738 *)p)->f3C+68*(*(u16 *)(p+48+2*(((struct Obj00738 *)p)->f22C+2)))));
        count=func_0204779C(object);
        for(i=0;i<count;i++) func_02047910(object,i,2048);
    }
}

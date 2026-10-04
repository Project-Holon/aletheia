/*
 * function: func_021BB184
 * address: 0x021BB184
 * packet: pkt_ov206_021BB184
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202D81C 0x0202D81C thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 */
#include "../include/Obj00790.h"
extern int func_0202D81C(int,int,int,int,int,int,int,int,int,unsigned short);
extern int func_0202D7D8(int,int,int,int,int,int,int,int,unsigned short,unsigned short);
extern int func_0202D898(int,int,int,int,int,int,int,int,unsigned short);
void func_021BB184(char *p,int index)
{
    int flag=0;
    int handle;
    if (((struct Obj00790 *)p)->f1C) flag=1;
    handle=((struct Obj00790 *)p)->f1D4;
    *(int *)(p+0x94+index*4)=func_0202D81C(handle,((struct Obj00790 *)p)->fC,((struct Obj00790 *)p)->fE,((struct Obj00790 *)p)->f10,((struct Obj00790 *)p)->f12,0,0,((struct Obj00790 *)p)->f14,flag,((struct Obj00790 *)p)->f0);
    *(int *)(p+0x9c+index*4)=func_0202D7D8(handle,((struct Obj00790 *)p)->fC,((struct Obj00790 *)p)->fE,((struct Obj00790 *)p)->f10,((struct Obj00790 *)p)->f12,0,0,flag,index<<5,((struct Obj00790 *)p)->f0);
    *(int *)(p+0xa4+index*4)=func_0202D898(((struct Obj00790 *)p)->fC,((struct Obj00790 *)p)->fE,((struct Obj00790 *)p)->f10,((struct Obj00790 *)p)->f12,0,0,2,flag,((struct Obj00790 *)p)->f0);
}

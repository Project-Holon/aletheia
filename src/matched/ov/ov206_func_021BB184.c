/*
 * function: ZUKAN_INFO_RegisterGfx
 * address: 0x021BB184
 * packet: pkt_ov206_021BB184
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKEGRA_RegisterCgr 0x0202D81C thumb
 *   POKEGRA_RegisterPalette 0x0202D7D8 thumb
 *   POKEGRA_RegisterCellAnim 0x0202D898 thumb
 */
#include "../include/Obj00790.h"
extern int POKEGRA_RegisterCgr(int,int,int,int,int,int,int,int,int,unsigned short);
extern int POKEGRA_RegisterPalette(int,int,int,int,int,int,int,int,unsigned short,unsigned short);
extern int POKEGRA_RegisterCellAnim(int,int,int,int,int,int,int,int,unsigned short);
void ZUKAN_INFO_RegisterGfx(char *p,int index)
{
    int flag=0;
    int handle;
    if (((struct Obj00790 *)p)->f1C) flag=1;
    handle=((struct Obj00790 *)p)->f1D4;
    *(int *)(p+0x94+index*4)=POKEGRA_RegisterCgr(handle,((struct Obj00790 *)p)->fC,((struct Obj00790 *)p)->fE,((struct Obj00790 *)p)->f10,((struct Obj00790 *)p)->f12,0,0,((struct Obj00790 *)p)->f14,flag,((struct Obj00790 *)p)->f0);
    *(int *)(p+0x9c+index*4)=POKEGRA_RegisterPalette(handle,((struct Obj00790 *)p)->fC,((struct Obj00790 *)p)->fE,((struct Obj00790 *)p)->f10,((struct Obj00790 *)p)->f12,0,0,flag,index<<5,((struct Obj00790 *)p)->f0);
    *(int *)(p+0xa4+index*4)=POKEGRA_RegisterCellAnim(((struct Obj00790 *)p)->fC,((struct Obj00790 *)p)->fE,((struct Obj00790 *)p)->f10,((struct Obj00790 *)p)->f12,0,0,2,flag,((struct Obj00790 *)p)->f0);
}

/*
 * function: func_021DF614
 * address: 0x021DF614
 * packet: pkt_ov119_021DF614
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AF4 0x021D8AF4 thumb ov119
 *   func_021D8B0C 0x021D8B0C thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 */
#include "../include/Obj04479.h"
extern int func_021D8AF4(int,char *);
extern int func_021D8B0C(int,int);
extern int func_021D8AA8(void *);
int func_021DF614(char *p,int a,int b)
{
    int x,y,i;
    x=func_021D8AF4(a,p);
    y=func_021D8B0C(a,b);
    if(((struct Obj04479 *)p)->fF7C==y && ((struct Obj04479 *)p)->fF80==x) return 1;
    if(func_021D8AA8(p)) {
        for(i=0;i<3;i++) {
            if(*(int *)(p+i*4+0xfa4)==-1) continue;
            if(y==*(int *)(p+i*4+0xfa4) && x==*(int *)(p+i*4+0xfbc)) return 1;
        }
    } else {
        if(((struct Obj04479 *)p)->fF84==y && ((struct Obj04479 *)p)->fF88==x && ((struct Obj04479 *)p)->fF7C==-1 && ((struct Obj04479 *)p)->fF80==-1) return 1;
    }
    return 0;
}

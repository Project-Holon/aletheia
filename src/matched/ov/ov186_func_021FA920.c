/*
 * function: func_021FA920
 * address: 0x021FA920
 * packet: pkt_ov186_021FA920
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_BTN_DATA_GetRowField 0x021FB7B0 thumb ov186
 *   func_021FAD18 0x021FAD18 thumb ov186
 *   func_021FAFA0 0x021FAFA0 thumb ov186
 *   func_021FAD74 0x021FAD74 thumb ov186
 *   func_021FA21C 0x021FA21C thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FA500 0x021FA500 thumb ov186
 *   d_02200358 0x02200358 data a4
 */
#include "../include/Obj02234.h"
typedef unsigned char u8;
extern int BR_BTN_DATA_GetRowField(void *,int);
extern void func_021FAD18(char *,int,const int *);
extern int func_021FAFA0(void *,int),func_021FAD74(char *);
extern void func_021FA21C(u8 *,int);
extern int *func_021FD73C(int *p, int v);
extern void func_021FA500(void *,int *,u8 *);
extern const int d_02200358[];
void func_021FA920(int *task,int *state,u8 *ctx)
{
    int position[2];
    int i;
    int ready;
    switch(*state) {
    case 0:
        for(i=0;i<ctx[0x3B];i++) {
            if(i==ctx[0x3B]-1) {
                position[0]=BR_BTN_DATA_GetRowField(*(void **)(*(u8 * *)&((struct Obj02234 *)ctx)->f3C+i*0x44+0xC),0);
                position[1]=BR_BTN_DATA_GetRowField(*(void **)(*(u8 * *)&((struct Obj02234 *)ctx)->f3C+i*0x44+0xC),1);
                func_021FAD18(*(char * *)&((struct Obj02234 *)ctx)->f3C+i*0x44,3,position);
                func_021FAFA0(*(char * *)&((struct Obj02234 *)ctx)->f3C+i*0x44,1);
            } else func_021FAD18(*(char * *)&((struct Obj02234 *)ctx)->f3C+i*0x44,4,(const int *)((unsigned)d_02200358+(ctx[0x3B]-i-2)*8));
        }
        for(i=0;i<ctx[0x39];i++)func_021FAFA0(*(char * *)&((struct Obj02234 *)ctx)->f40+i*0x44,3);
        *state=1;
        break;
    case 1:
        ready=1;
        for(i=0;i<ctx[0x3B];i++)ready&=func_021FAD74(*(char * *)&((struct Obj02234 *)ctx)->f3C+i*0x44);
        if(ready){func_021FA21C(ctx,1);*state=2;}
        break;
    case 2:func_021FD73C(task,(int)func_021FA500);break;
    }
}

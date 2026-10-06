/*
 * function: func_021D83DC
 * address: 0x021D83DC
 * packet: pkt_ov121_021D83DC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware argument 04001050 passed to blend helper
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045994 0x02045994 arm
 *   func_02045808 0x02045808 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021DA1BC 0x021DA1BC thumb ov121
 *   func_021D694C 0x021D694C thumb ov121
 *   d_021DF544 0x021DF544 data a4
 */
#include "../include/Obj06446.h"
typedef unsigned char u8;
typedef struct { int w[12]; } Config;
extern const Config d_021DF544;
typedef unsigned int   u32;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
struct Strbuf;
extern void func_02045994(struct Strbuf *,const unsigned short *,u32);
extern void func_02045808(struct U16Vec *vec);
extern void func_020409B4(u32 index);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_0207D63C(void *,int,int,int,int);
extern void *func_021DA1BC(int,Config *,int,int,int,void *,void *,void *,int);
typedef unsigned short u16;
extern void func_021D694C(u16 *p, int mode);
void func_021D83DC(u8 *p,int heap)
{
    Config c;
    if(((struct Obj06446 *)p)->f28C==0) {
        c=d_021DF544;
        c.w[2]=(int)func_020457B0(37,heap);
        func_02045994((struct Strbuf *)c.w[2],(const unsigned short *)(p+1068),37);
        c.w[8]=(int)func_020457B0(253,heap);
        func_02045994((struct Strbuf *)c.w[8],(const unsigned short *)(p+1180),253);
        ((struct Obj06446 *)p)->f28C=func_021DA1BC(0,&c,2,4,15,((struct Obj06446 *)p)->f39C,((struct Obj06446 *)p)->f3A4,((struct Obj06446 *)p)->f398,heap);
        func_02045808((void *)c.w[2]);
        func_02045808((void *)c.w[8]);
        func_021D694C((u16 *)(p+912),1);
        func_020409B4(6);
        func_02040588(6,1);
        func_0207D63C((void *)0x04001050,4,24,15,3);
    }
}

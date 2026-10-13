/*
 * function: func_021F19A0
 * address: 0x021F19A0
 * packet: pkt_ov194_021F19A0
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021F1998 0x021F1998 thumb ov194
 *   func_02049F34 0x02049F34 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj24898.h"
#include "../include/Obj24899.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,int);
extern void *func_021F1998(u8 *p, u32 i);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern u32 func_020307B0(void *p);
void func_021F19A0(u8 *a,void *b,void *c,u32 d)
{
    int i;
    void *x;
    void *p;
    u8 *q;
    int j;
    MI_CpuFill8(a,0,180);
    ((struct Obj24898 *)a)->fA0=b;
    for(i=0;i<2;i++) *(u32 *)(a+164+i*4)=(u32)func_021F1998(c,i+18);
    p=func_02049F34(118,2,(u32)(&x),d);
    q=*(u8 * *)&((struct Obj24899 *)x)->fC;
    for(i=0;i<16;i++) *(u16 *)(a+i*2)=*(u16 *)(q+32+i*2);
    for(j=0;j<16;j++) *(u16 *)(a+32+j*2)=*(u16 *)(q+64+j*2);
    func_020307B0(p);
}

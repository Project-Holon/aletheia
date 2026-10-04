/*
 * function: func_021BA1D0
 * address: 0x021BA1D0
 * packet: pkt_ov100_021BA1D0
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02027778 0x02027778 thumb
 *   func_02027CD8 0x02027CD8 thumb
 *   func_02045808 0x02045808 arm
 *   func_021B967C 0x021B967C thumb ov100
 */
#include "../include/Obj00060.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Template { int heap; u8 count,pad[3]; int ptr,flag; u8 x,y,z,w; };
typedef unsigned int   u32;
struct MsgBank;
struct TaskMenu;
struct TaskMenuTmpl;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02027CD8(int,int);
extern void func_02045808(struct U16Vec *vec);
extern void func_021B967C(int,int);
void func_021BA1D0(int a) {
 struct Template t;
 int v;
 t.heap=((struct Obj00060 *)a)->f278;
 t.count=2;
 t.ptr=a+0xcc8;
 t.flag=1;
 t.x=32; t.y=13; t.z=13; t.w=3;
 v=(int)func_020457B0(100,t.heap);
 ((struct Obj00060 *)a)->fCC8=v;
 func_02045CAC((struct MsgBank *)(((struct Obj00060 *)a)->f288),26,(void *)v);
 ((struct Obj00060 *)a)->fCCC=0x39e3;
 v=(int)func_020457B0(100,((struct Obj00060 *)a)->f278);
 ((struct Obj00060 *)a)->fCD4=v;
 func_02045CAC((struct MsgBank *)(((struct Obj00060 *)a)->f288),27,(void *)v);
 ((struct Obj00060 *)a)->fCD8=0x39e3;
 ((struct Obj00060 *)a)->fCD0=0;
 ((struct Obj00060 *)a)->fCDC=0;
 v=(int)func_02027778((struct TaskMenuTmpl *)(&t),(void *)(((struct Obj00060 *)a)->fCC4));
 ((struct Obj00060 *)a)->fCC0=v;
 switch(((struct Obj00060 *)a)->f24C) {case 9: case 10: case 11: break; default: func_02027CD8(v,1); break;}
 func_02045808((struct U16Vec *)(((struct Obj00060 *)a)->fCC8));
 func_02045808((struct U16Vec *)(((struct Obj00060 *)a)->fCD4));
 func_021B967C(a,1);
}

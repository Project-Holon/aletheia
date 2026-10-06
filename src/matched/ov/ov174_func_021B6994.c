/*
 * function: func_021B6994
 * address: 0x021B6994
 * packet: pkt_ov174_021B6994
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 0x021B6A02..0x021B6A04 is two zero alignment bytes.
 * symbols:
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045730 0x02045730 arm
 *   func_021B7350 0x021B7350 thumb ov174
 */
#include "../include/Obj02218.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Descriptor;
struct Rec3;
struct U16Vec;
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern void func_02041B6C(unsigned);
extern void func_020452E8(struct Descriptor *d);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
struct Descriptor;
extern u8 func_02045730(struct Descriptor *p);
extern void func_021B7350(int,int *);
void func_021B6994(u8 *p)
{
 void *tmp; u8 i;
 if(((struct Obj02218 *)p)->f5C){
 func_0201F7A8(((struct Obj02218 *)p)->f5C,1);tmp=((struct Obj02218 *)p)->f5C;
 func_020456F8(tmp);func_02041B6C(func_02045730(tmp));
 func_020452E8(((struct Obj02218 *)p)->f5C);((struct Obj02218 *)p)->f5C=0;
 }
 if(((struct Obj02218 *)p)->f64){func_0201CE48(((struct Obj02218 *)p)->f64);((struct Obj02218 *)p)->f64=0;}
 if(((struct Obj02218 *)p)->f70){func_02045808(((struct Obj02218 *)p)->f70);((struct Obj02218 *)p)->f70=0;}
 for(i=0;i<((struct Obj02218 *)p)->f8;i++) if(*(int **)(p+28+i*4)) func_021B7350((int)p,*(int **)(p+28+i*4));
}

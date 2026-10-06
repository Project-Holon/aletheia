/*
 * function: func_021B68F8
 * address: 0x021B68F8
 * packet: pkt_ov174_021B68F8
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 0x021B6992..0x021B6994 is two zero alignment bytes.
 * symbols:
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020452E8 0x020452E8 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02028470 0x02028470 thumb
 *   func_02045730 0x02045730 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 */
#include "../include/Obj02507.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct CharBuf;
struct Cfg;
struct Descriptor;
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern void func_02041B6C(unsigned);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0201F73C(void *,int,int,int);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_02028470(u8 *p, u32 v);
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *);
void func_021B68F8(u8 *p,int mode)
{
 void *tmp;
 if(((struct Obj02507 *)p)->f5C){
 func_0201F7A8(((struct Obj02507 *)p)->f5C,1);
 tmp=((struct Obj02507 *)p)->f5C;func_020456F8(tmp);func_02041B6C(func_02045730(tmp));
 func_020452E8(((struct Obj02507 *)p)->f5C);((struct Obj02507 *)p)->f5C=0;
 }
 if(mode==0) ((struct Obj02507 *)p)->f5C=(void *)func_020450F0(0,1,1,30,4,12,1);
 else if(mode==1) ((struct Obj02507 *)p)->f5C=(void *)func_020450F0(0,1,19,30,4,12,1);
 func_0201F73C(((struct Obj02507 *)p)->f5C,1,1,13);
 func_02043B5C(func_02045770(((struct Obj02507 *)p)->f5C),15);
 func_02045334(((struct Obj02507 *)p)->f5C);func_02045374(((struct Obj02507 *)p)->f5C);
 func_02041B6C(0);func_02028470(p+128,6);
}

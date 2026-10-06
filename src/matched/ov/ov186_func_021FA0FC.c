/*
 * function: func_021FA0FC
 * address: 0x021FA0FC
 * packet: pkt_ov186_021FA0FC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FACE0 0x021FACE0 thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FB760 0x021FB760 thumb ov186
 *   func_021FB704 0x021FB704 thumb ov186
 *   func_021FB7D0 0x021FB7D0 thumb ov186
 *   func_021FAC20 0x021FAC20 thumb ov186
 *   func_021FAFA0 0x021FAFA0 thumb ov186
 *   func_021FB514 0x021FB514 thumb ov186
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj01277.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
struct Fields;
struct U16Vec;
extern void func_021FACE0(char *p);
extern int func_021FC214(char *);
extern u16 func_021FB760(void *,int);
extern void *func_021FB704(char *ctx, int section, unsigned item);
extern void *func_021FB7D0(unsigned *const *,void *,int,u16);
extern void func_021FAC20(struct Fields *,unsigned,unsigned,unsigned,void *,const void *,unsigned,u16);
extern int func_021FAFA0(void *,int);
extern void func_021FB514(char *p, short x, int y);
extern void func_02045808(struct U16Vec *vec);
void func_021FA0FC(u8 *p,int section,const int *pos)
{
 int i,bank;
 void *rec,*text;
 for(i=0;i<p[0x38];i++)func_021FACE0((char *)(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44));
 bank=func_021FC214(*(char * *)&((struct Obj01277 *)p)->f4);
 p[0x39]=func_021FB760(((struct Obj01277 *)p)->f44,section);
 for(i=0;i<p[0x39];i++){
  rec=func_021FB704(*(char * *)&((struct Obj01277 *)p)->f44,section,(u16)i);
  text=func_021FB7D0(*(unsigned *const * *)&((struct Obj01277 *)p)->f44,rec,bank,(((struct Obj01277 *)p)->f0&0x7fff)|0x8000);
  func_021FAC20((struct Fields *)(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44),(u32)rec,((struct Obj01277 *)p)->f8,((struct Obj01277 *)p)->f48,((struct Obj01277 *)p)->f4,text,((struct Obj01277 *)p)->f10,((struct Obj01277 *)p)->f0);
  func_02045808(text);
  func_021FAFA0(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44,3);
  if(pos)func_021FB514(*(void **)(*(u8 * *)&((struct Obj01277 *)p)->f40+i*0x44+8),pos[0],(short)pos[1]);
 }
}

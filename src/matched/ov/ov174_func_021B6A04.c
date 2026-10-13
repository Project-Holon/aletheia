/*
 * function: func_021B6A04
 * address: 0x021B6A04
 * packet: pkt_ov174_021B6A04
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 0x021B6A8E..0x021B6A90 is two zero alignment bytes.
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045770 0x02045770 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 */
#include "../include/Obj00919.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct CharBuf;
typedef unsigned int   u32;
struct MsgBank;
struct Rec3;
struct U16Vec;
struct WordSet;
extern void func_0201CE48(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct Descriptor;
extern void * func_02045770(struct Descriptor *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern signed char func_02012FFC(void);
extern unsigned PRINTSYS_PrintStream(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16,u16);
void func_021B6A04(u8 *p, int message)
{
 void *tmp; unsigned speed;
 if(((struct Obj00919 *)p)->f64){func_0201CE48(((struct Obj00919 *)p)->f64);((struct Obj00919 *)p)->f64=0;}
 if(((struct Obj00919 *)p)->f70){STRBUF_Delete(((struct Obj00919 *)p)->f70);((struct Obj00919 *)p)->f70=0;}
 BMP_Clear(func_02045770(((struct Obj00919 *)p)->f5C),15);
 ((struct Obj00919 *)p)->f70=func_02045EC0(((struct Obj00919 *)p)->f6C,message);
 if(((struct Obj00919 *)p)->f74){
 tmp=STRBUF_Create(1024,((struct Obj00919 *)p)->f0);
 func_0201F250(((struct Obj00919 *)p)->f74,tmp,((struct Obj00919 *)p)->f70);
 STRBUF_Delete(((struct Obj00919 *)p)->f70);((struct Obj00919 *)p)->f70=tmp;
 }
 speed=func_02012FFC();
 *(unsigned *)&((struct Obj00919 *)p)->f64=PRINTSYS_PrintStream(*(unsigned *)&((struct Obj00919 *)p)->f5C,0,0,*(unsigned *)&((struct Obj00919 *)p)->f70,((struct Obj00919 *)p)->f60,speed,((struct Obj00919 *)p)->f58,2,((struct Obj00919 *)p)->f0,15);
}

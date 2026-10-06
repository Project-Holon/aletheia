/*
 * function: func_021BDAA4
 * address: 0x021BDAA4
 * packet: pkt_ov110_021BDAA4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C38F0 0x021C38F0 data a1
 *   d_021C395C 0x021C395C data a1
 *   func_02035C60 0x02035C60 arm
 *   func_02035C08 0x02035C08 arm
 *   func_02035D20 0x02035D20 arm
 *   func_02035D40 0x02035D40 arm
 *   func_02024158 0x02024158 thumb
 *   func_021BABE8 0x021BABE8 thumb ov110
 *   func_021BAC00 0x021BAC00 thumb ov110
 */
#include "../include/Obj10282.h"
typedef unsigned char u8;
typedef struct { u8 b[8]; } Box;
extern const Box d_021C38F0;
extern const Box d_021C395C;
extern int func_02035C60(void);
extern int func_02035C08(const void *p);
struct Ctx;
extern unsigned int func_02035D20(unsigned int *outA, unsigned int *outB);
extern unsigned int func_02035D40(struct Ctx *ctx, unsigned int a, unsigned int b);
typedef unsigned int   u32;
extern u32 func_02024158(const u8 *p);
extern int func_021BABE8(u8 *p);
extern void func_021BAC00(void *,Box *,u8);
int func_021BDAA4(u8 *p) {
 int x,y;
 Box box=d_021C38F0;
 int i,count,result;
 if(!func_02035C60()) return -1;
 result=func_02035C08(&d_021C395C);
 if(result!=-1) {
  if(func_02024158((const u8 *)(((struct Obj10282 *)p)->f0))) { if((unsigned)(result-2)<=3) result=-1; return result; }
  return result;
 }
 count=func_021BABE8(((struct Obj10282 *)p)->f14);
 func_02035D20((unsigned int *)(&x),(unsigned int *)(&y));
 for(i=0;i<count;i++) { func_021BAC00(((struct Obj10282 *)p)->f14,&box,i); if(func_02035D40((struct Ctx *)(&box),x,y)!=-1) return i+6; }
 return -1;
}

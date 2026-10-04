/*
 * function: func_021FC6EC
 * address: 0x021FC6EC
 * packet: pkt_ov132_021FC6EC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203D378 0x0203D378 arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02012124 0x02012124 thumb
 *   func_021FCDEC 0x021FCDEC thumb ov132
 *   func_021FCE00 0x021FCE00 thumb ov132
 * 0203D1B4's forwarding matched void declaration loses its live result.
 * 0203D7BC retains the original caller's unused zero argument.
 */
#include "../include/Obj08173.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry; struct Ctx;
extern int func_0203D1B4(void);
extern int func_0203CEAC(int);
extern void func_0203A5E4(u32);
extern void func_0203D7BC(u32);
extern u32 func_0200FB24(void);
extern u32 func_0203D378(void);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *,u16,u16,u32);
extern void func_02012124(struct Ctx *,u8);
extern void func_021FCDEC(int,int);
extern int func_021FCE00(void *,int);
int func_021FC6EC(int *state,u8 *p)
{
 switch(*state) {
 case 0:
  if(func_0203D1B4()<=1) {func_0203CEAC(0);return 1;}
  if(((struct Obj08173 *)p)->fC==1) func_0203A5E4(0x1100);
  if(((struct Obj08173 *)p)->f8==1) {func_0203D7BC(0);func_021FCDEC((int)p,0x41);*state=1;}
  else *state=2;
  break;
 case 1:
  if(func_021FCE00(p,0x41)==1) *state=2;
  if(func_0203D1B4()<=1 || func_0200FB24()!=0) *state=10;
  break;
 case 2:
  if(((struct Obj08173 *)p)->f8==0) {func_0203CEAC(0);return 1;}
  if(func_0203D378()==0) {
   if(func_0203D3A8(func_020399A8(),1,0,0)==1) return 1;
  } else if(func_0203D1B4()<=1) {func_0203CEAC(0);return 1;}
  if(func_0200FB24()!=0) *state=10;
  break;
 case 10:
  if(func_0200FB24()!=0) func_02012124(*(struct Ctx * *)&((struct Obj08173 *)p)->f54,1);
  func_0203CEAC(0);return 1;
 }
 return 0;
}

/*
 * function: func_021C2604
 * address: 0x021C2604
 * packet: pkt_ov099_021C2604
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_02157170 0x02157170 thumb ov009
 *   func_021BC0C4 0x021BC0C4 thumb ov099
 *   func_021BB0B4 0x021BB0B4 thumb ov099
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_0202223C 0x0202223C thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_0204A600 0x0204A600 arm
 *   func_0201DE00 0x0201DE00 thumb
 *   func_0201DD78 0x0201DD78 thumb
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021C2438 0x021C2438 thumb ov099
 *   d_021C3C0C 0x021C3C0C data a4
 */
#include "../include/Obj00825.h"
typedef unsigned char u8;
typedef int (*Handler)(char *,int);
extern const Handler d_021C3C0C[];
extern int func_0203CD98(int),func_02157170(int,int),func_0200FB24(void),func_021C2438(char *);
typedef unsigned int   u32;
struct PrintSys;
extern void func_021BC0C4(char *);
extern void func_021BB0B4(char *);
extern void func_0203D7B0(int);
extern void func_0203D7BC(int);
extern void func_021C18C8(char *,int,int);
extern void func_0202223C(unsigned int,unsigned int);
extern void func_0202208C(void *,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
extern void func_0204A600(void *);
extern void func_0201DE00(u8 *,u8 *,u8 *);
extern void func_0201DD78(unsigned int,unsigned int,unsigned int);
struct Tcbl;
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
int func_021C2604(int task,int *state,int unused,char *p) {
 u8 r,g,b;
 Handler fn;
 if(func_0203CD98(task)!=0) {
  switch(func_02157170(1,1)) {
   case 4:
    func_021BC0C4(p);func_021BB0B4(p);func_0203D7B0(0);func_0203D7BC(0);func_021C18C8(p,1,2);
    ((struct Obj00825 *)p)->f1E0=20;((struct Obj00825 *)p)->f1CC=0x39;return 0;
   case 2:
    func_0202223C(0,0);func_0202223C(1,0);((struct Obj00825 *)p)->f1D0=1;return 1;
  }
 }
 if(func_0200FB24()==0) {
  fn=d_021C3C0C[((struct Obj00825 *)p)->f1CC];
  if(fn!=0) {
   *state=fn(p,*state);
   if(*state==2) {func_0202208C(0,0,0,0,6,1,0x21);return 1;}
  }
 }
 if(((struct Obj00825 *)p)->f110!=0) func_0204A600(((struct Obj00825 *)p)->f110);
 if(((struct Obj00825 *)p)->f1B8!=0) {
  func_0201DE00(&r,&g,&b);func_0201DD78(1,2,15);func_020310C4(((struct Obj00825 *)p)->f1C0);func_0201DD78(r,g,b);func_0201C4E4(((struct Obj00825 *)p)->f1B8);
 }
 if(((struct Obj00825 *)p)->f1B4!=0) func_0201C4E4(((struct Obj00825 *)p)->f1B4);
 func_021C2438(p);return 0;
}

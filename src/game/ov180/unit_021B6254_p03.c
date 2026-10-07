/*
 * file:     unit_021B6254_p03.c
 * unit:     yes
 * function: func_021B64DC, func_021B654C, func_021B65A0, func_021B65FC, func_021B66A0, func_021B66D4, func_021B66E4, func_021B6704
 * address:  0x021B64DC
 * region:   ov180
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017D30 0x02017D30 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017D70 0x02017D70 thumb
 *   func_02006CAC 0x02006CAC thumb
 *   func_020069D4 0x020069D4 thumb
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021B8040 0x021B8040 data a4
 *   func_02046440 0x02046440 arm
 *   func_02047CFC 0x02047CFC arm
 *   func_02047E54  0x02047E54  arm
 *   func_02046788  0x02046788  arm
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02014C08 0x02014C08 thumb
 *   func_02014D2C 0x02014D2C thumb
 *   func_02047970 0x02047970 arm
 *   func_0204EA38 0x0204EA38 arm
 *   func_021B6844 0x021B6844 thumb ov180
 *   func_02050BE8 0x02050BE8 arm
 *   func_0204EA4C 0x0204EA4C arm
 */
#include "../../matched/include/Obj02515.h"
#include "../../matched/include/Obj08297.h"
#include "../../matched/include/Obj04568.h"
#include "../../matched/include/Obj00547.h"
#include "../../matched/include/Obj24484.h"
#include "../../matched/include/Obj14398.h"

#define REG(a) (*(volatile u16 *)(a))
struct Sav;
struct Util;
struct Rec;
struct McssSys;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef short s16;

extern unsigned func_0201AA18(void *);
extern void *func_0201AB28(void *,unsigned);
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern void func_02006CAC(void **out);
extern int func_020069D4(int a0, int a1, int a2, int a3, int a5, int a6, int a7, int a8);
extern void func_020434DC(unsigned,unsigned);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(u16,int,int,int,int);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(unsigned,unsigned);
extern void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u16 fifoSize, s16 heap, void (*setup)(void));
extern struct Util *func_02047CFC(u16,u16,u16);
extern void func_02047E54(struct Rec *p);
extern void func_02046788(void);
extern void func_02047964(void);
extern void func_020479D8(void);
extern void func_02014C08(char *);
extern void func_02014D2C(struct McssSys *);
extern void func_02047970(void);
extern unsigned func_0204EA38(void);
extern void func_021B6844(char *,void *,int);
extern void func_02050BE8(void);
extern void func_0204EA4C(void);
void func_021B64DC(unsigned char *p);
void func_021B654C(char *p);
void func_021B65A0(char *p);
void func_021B65FC(void);
void func_021B66A0(char *p);
void func_021B66D4(int *p);
void func_021B66E4(char *p);
void func_021B6704(char *p);
extern const unsigned char d_021B8040[];

void func_021B64DC(unsigned char *p) {
 unsigned i; void *mon; unsigned saved;
 p[0x915E]=0;
 for(i=0;i<func_0201AA18(**(void ** *)&((struct Obj02515 *)p)->f0);i++) {
  mon=func_0201AB28(**(void ** *)&((struct Obj02515 *)p)->f0,i); saved=func_02017D30(mon);
  if(func_02017E1C(mon,76,0)==0) { *(void **)(p+(unsigned char)p[0x915E]*4+0x9140)=mon; p[0x915E]++; }
  func_02017D70(mon,saved);
 }
}

void func_021B654C(char *p) {
 void *mon; unsigned saved;
 mon=*(void **)(p+(unsigned char)p[0x915D]*4+0x9140);
 saved=func_02017D30(mon);
 ((struct Obj08297 *)p)->f9158=func_02017E1C(mon,5,0);
 ((struct Obj08297 *)p)->f915A=func_02017E1C(mon,174,0);
 p[0x915C]=func_02017E1C(mon,111,0);
 func_02017D70(mon,saved);
}

void func_021B65A0(char *p) {
 unsigned value;
 if(((struct Obj04568 *)p)->f9158==441) {
  func_02006CAC((void **)(&value));
  ((struct Obj04568 *)p)->f9184=func_020069D4(((struct Obj04568 *)p)->f9158,(unsigned char)p[0x915C],64,0,0,0,0,(int)(&value));
 } else ((struct Obj04568 *)p)->f9184=func_020069D4(((struct Obj04568 *)p)->f9158,(unsigned char)p[0x915C],64,0,0,0,0,0);
}

/*
 * volatile: 021B660A..021B6648 re-read hardware 0x04000008 and 0x04000060; hardware write 0x04000580.
 */
void func_021B65FC(void) {
 unsigned i;
 func_020434DC(1,1);
 REG(0x04000008)=REG(0x04000008)&~3;
 REG(0x04000060)=(u16)((REG(0x04000060)&~0x3002)|2);
 REG(0x04000060)&=(u16)~0x3010;
 REG(0x04000060)&=(u16)~0x3004;
 REG(0x04000060)=(u16)((REG(0x04000060)&~0x3000)|8);
 REG(0x04000060)&=(u16)~0x3020;
 func_0207DC44(0,0,0,0); func_0207DD24(0,0,32767,63,0);
 *(volatile unsigned *)0x04000580=0xBFFF0000;
 for(i=0;i<4;i++) func_02046A94((unsigned char)i,(const u16 *)(d_021B8040+i*8));
 func_02046BE0(1,0);
}

void func_021B66A0(char *p) {func_02046440(0,1,0,1,4096,141,func_021B65FC);*(struct Util * *)&((struct Obj00547 *)p)->f10=func_02047CFC(32,32,141);}


void func_021B66D4(int *p)
{
    func_02047E54((struct Rec *)(((struct Obj24484 *)p)->f10));
    func_02046788();
}

void func_021B66E4(char *p) {func_02047964();func_020479D8();func_02014C08(*(char * *)&((struct Obj14398 *)p)->f18);func_02014D2C(*(struct McssSys * *)&((struct Obj14398 *)p)->f18);func_02047970();}

void func_021B6704(char *p) {
 func_02047964(); func_020479D8();
 if(func_0204EA38()==1) { func_021B6844(p,*(void **)(p+0x28),1); func_021B6844(p,*(void **)(p+0x2C),1); }
 else { func_021B6844(p,*(void **)(p+0x28),0); func_021B6844(p,*(void **)(p+0x2C),0); }
 func_02050BE8(); func_02047970(); func_0204EA4C();
}

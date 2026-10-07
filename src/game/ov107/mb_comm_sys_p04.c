/*
 * file:     mb_comm_sys_p04.c
 * unit:     yes
 * function: func_021EF79C, func_021EF96C
 * address:  0x021EF79C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02178E4C 0x02178E4C thumb ov014
 *   func_02178E84 0x02178E84 thumb ov014
 *   func_02179498 0x02179498 thumb ov014
 *   func_021F0DB4 0x021F0DB4 thumb ov107
 *   func_02179158 0x02179158 thumb ov014
 *   func_021790E4 0x021790E4 thumb ov014
 *   func_02037010 0x02037010 arm
 *   func_02037118 0x02037118 arm
 *   func_020351F8 0x020351F8 arm
 *   func_02012944 0x02012944 thumb
 *   func_021F1898 0x021F1898 thumb ov107
 *   func_021F1628 0x021F1628 thumb ov107
 *   func_021F18D8 0x021F18D8 thumb ov107
 *   func_02008534 0x02008534 thumb
 *   func_021F1918 0x021F1918 thumb ov107
 *   func_02012FFC 0x02012FFC thumb
 *   func_021F1704 0x021F1704 thumb ov107
 *   func_021F18EC 0x021F18EC thumb ov107
 *   func_021EFA14 0x021EFA14 thumb ov107
 *   func_021F17E0 0x021F17E0 thumb ov107
 *   func_021F1B38 0x021F1B38 thumb ov107
 *   func_0204B878 0x0204B878 arm
 *   func_02179570 0x02179570 thumb ov014
 *   func_021EFC10 0x021EFC10 thumb ov107
 *   func_021EFCA8 0x021EFCA8 thumb ov107
 *   func_0208EE9C 0x0208EE9C arm
 *   func_020370F4 0x020370F4 arm
 *   func_02037154 0x02037154 arm
 *   d_021F6EA0 0x021F6EA0 data a4
 *   d_021F6D68 0x021F6D68 data ov107 a4
 *   d_021F6D70 0x021F6D70 data ov107 a4
 *   d_021F6D60 0x021F6D60 data ov107 a4
 *   d_021F6C40 0x021F6C40 data ov107 a4
 *   func_02179024 0x02179024 thumb ov014
 *   func_02082D44 0x02082D44 arm
 *   func_021F0754 0x021F0754 thumb ov107
 *   func_021F080C 0x021F080C thumb ov107
 */
#include "../../matched/include/Obj00072.h"
#include "../../matched/include/Obj22277.h"
#include "../../matched/include/G_Counter.h"

struct Sub0200852CObj;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int a,b; } Pair;

typedef struct { int words[15]; } Config;

extern int func_02178E4C(void),func_02178E84(void),func_02179498(void);
extern void func_021F0DB4(void),func_02179158(void);
extern int func_021790E4(u32,int,int);
extern void func_02037010(u32,u32,u32,u32),func_02037118(u32,u32);
extern void func_020351F8(u32 a, u32 b);
extern u8 *func_02012944(void *p);
extern void func_021EF96C(u8 *),func_021F1898(void *),func_021F1628(void *,int),func_021F18D8(void *);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern void func_021F1918(unsigned char *a, int b, int c, int d);
extern signed char func_02012FFC(void);
extern void func_021F1704(void *,int,int);
extern void func_021F18EC(void *);
extern void func_021EFA14(u8 *);
extern void func_021F17E0(void *,int);
extern void func_021F1B38(u8 *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_02179570(void (*cb)(int));
extern int func_021EFC10(void);
extern int func_0208EE9C(void);
extern u32 func_020370F4(u32);
extern void func_02037154(void);
extern void func_021EFCA8(u8 *p);
extern u16 func_02179024(void);
extern void func_02082D44(const void *,void *,unsigned);
extern void func_021F0754(int,int);
extern void func_021F080C(void *,int);
int func_021EF79C(u8 *p);
void func_021EF96C(u8 *p);
extern struct Counter d_021F6EA0;
extern const Pair d_021F6D68,d_021F6D70,d_021F6D60;
extern const Config d_021F6C40;

int func_021EF79C(u8 *p)
{
 void *q;
 if(func_02178E4C()==9 || func_02178E4C()==10){
  ((struct Obj00072 *)p)->f30=0;((struct Obj00072 *)p)->f14=1;
  if(func_02179498()==1){func_021F0DB4();func_02179158();return 1;}return 0;
 }
 switch(p[0x24]){
 case 0:
  *(int *)(((u8 *)&d_021F6EA0)+8)=0;((struct Obj00072 *)p)->f1C=1;
  func_021790E4(((struct Obj00072 *)p)->f0,(int)func_021EFC10,0);
  func_02037010(240,0,0,((struct Obj00072 *)p)->f0);
  if(p[0x28]==0)func_02037118(0,((struct Obj00072 *)p)->f0);
  else func_02037118(1,((struct Obj00072 *)p)->f0);
  p[0x24]=1;func_020351F8((u32)func_021EFCA8,(u32)p);break;
 case 1:
  if(func_02178E4C()==1 && func_02178E84()==1)p[0x24]=2;break;
 default:break;
 case 2:
  if(func_02178E4C()==7){
   q=func_02012944(((struct Obj22277 *)(*(u8 * *)&((struct Obj00072 *)p)->f8))->f4);func_021EF96C(p);
   func_021F1898(((struct Obj00072 *)p)->f68);
   if(p[0x28]==0)func_021F1628(((struct Obj00072 *)p)->f68,2);
   else func_021F1628(((struct Obj00072 *)p)->f68,3);
   func_021F18D8(((struct Obj00072 *)p)->f68);func_021F1918(((struct Obj00072 *)p)->f68,0,func_02008534(q),5);
   if(p[0x28]==0)func_021F1704(((struct Obj00072 *)p)->f68,0,func_02012FFC());
   else func_021F1704(((struct Obj00072 *)p)->f68,20,func_02012FFC());
   func_021F18EC(((struct Obj00072 *)p)->f68);p[0x24]=3;
  }break;
 case 3:func_021EFA14(p);break;
 case 4:
  func_021F1898(((struct Obj00072 *)p)->f68);func_021F1628(((struct Obj00072 *)p)->f68,1);
  if(p[0x28]==0)func_021F17E0(((struct Obj00072 *)p)->f68,1);
  else func_021F17E0(((struct Obj00072 *)p)->f68,21);
  func_021F1B38(((struct Obj00072 *)p)->f68,1);func_0204B878(((struct Obj00072 *)p)->f7C,15);p[0x24]=5;break;
 case 5:((struct Obj00072 *)p)->f30=1;p[0x24]=6;break;
 case 8:p[0x24]=6;break;
 case 6:*(int *)(((u8 *)&d_021F6EA0)+8)=0;func_02179570((void (*)(int))((int (*)(int))func_021EFC10));((struct Obj00072 *)p)->f1C=0;p[0x24]=7;break;
 case 7:if(*(int *)(((u8 *)&d_021F6EA0)+8)==1){func_020351F8(0,0);func_02179158();return 1;}break;
 }
 func_020370F4(3-func_0208EE9C());func_02037154();return 0;
}

void func_021EF96C(u8 *p) {
 Pair a=d_021F6D68,b=d_021F6D70,c=d_021F6D60;
 Config cfg=d_021F6C40;
 int v=func_02179024();
 func_02082D44(&cfg,p+128,60);
 ((struct Obj00072 *)p)->f80=p[40]==0?a.a:a.b;
 ((struct Obj00072 *)p)->f8C=b.b;((struct Obj00072 *)p)->f90=c.b;
 ((struct Obj00072 *)p)->f84=((struct Obj00072 *)p)->f50;((struct Obj00072 *)p)->f88=((struct Obj00072 *)p)->f54;
 func_021F0754(4992,65536);func_021F080C(p+128,v);
}

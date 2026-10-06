/*
 * function: func_021BAD1C
 * address: 0x021BAD1C
 * packet: pkt_ov100_021BAD1C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_021BA5F4 0x021BA5F4 thumb ov100
 *   func_021B95C0 0x021B95C0 thumb ov100
 *   func_021B967C 0x021B967C thumb ov100
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B96B8 0x021B96B8 thumb ov100
 *   func_021BACC8 0x021BACC8 thumb ov100
 */
#include "../include/Obj07962.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(struct TaskMenu *m);
extern void func_02041B6C(u32 bit);
extern void func_021BA5F4(unsigned a);
extern int func_021B95C0(u8 *p);
extern void func_021B967C(int,int);
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021B96B8(u8 *a);
extern void func_021BACC8(int a);
void func_021BAD1C(int a) {
 if(func_020279E8((struct TaskMenu *)(*(int *)&((struct Obj07962 *)a)->fCC0))!=0) {
  int v=func_02027A04(*(const u8 * *)&((struct Obj07962 *)a)->fCC0);
  func_02027858((struct TaskMenu *)(*(int *)&((struct Obj07962 *)a)->fCC0));
  *(int *)&((struct Obj07962 *)a)->fCC0=0;
  func_02041B6C(6);
  if(v==0) {
   func_021BA5F4(a); func_021B95C0((u8 *)a); func_021B95B8((u8 *)a,(u32)func_021B96B8);
  } else func_021B95B8((u8 *)a,(u32)func_021BACC8);
  func_021B967C(a,0);
 }
}

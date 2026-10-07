/*
 * file:     namein_graphic_p05.c
 * unit:     yes
 * function: func_021F23B8, func_021F23E4, func_021F23F4, func_021F23F8, func_021F23FC, func_021F253C, func_021F256C, func_021F25F8, func_021F2608
 * address:  0x021F23B8
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045A98 0x02045A98 arm
 *   func_021F2190 0x021F2190 thumb ov194
 *   func_021F4E58 0x021F4E58 thumb ov194
 *   func_021F4E18 0x021F4E18 thumb ov194
 *   func_021F4ED8 0x021F4ED8 thumb ov194
 *   func_021F2150 0x021F2150 thumb ov194
 *   func_021F4DDC 0x021F4DDC thumb ov194
 *   func_021F4E98 0x021F4E98 thumb ov194
 *   func_02082BCC 0x02082BCC arm
 *   func_021F4D94 0x021F4D94 thumb ov194
 *   func_021F299C 0x021F299C thumb ov194
 *   func_021F2BC8 0x021F2BC8 thumb ov194
 *   func_021F2F8C 0x021F2F8C thumb ov194
 *   func_021F28FC 0x021F28FC thumb ov194
 *   func_021F2A88 0x021F2A88 thumb ov194
 *   func_021F2F68 0x021F2F68 thumb ov194
 *   d_021F555C 0x021F555C data a4
 */
#include "../../matched/include/Obj14496.h"
#include "../../matched/include/Obj24902.h"
#include "../../matched/include/Obj24903.h"
#include "../../matched/include/Obj01574.h"
#include "../../matched/include/Obj14497.h"
#include "../../matched/include/Obj02530.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct {u8 count,pad;u16 values[4];} Group;

extern u16 func_02045A98(void);
extern int func_021F2190(char *,u16);
extern int func_021F4E58(int,int,u16 *,int,u8 *),func_021F4E18(int,int,u16 *,int,u8 *);
extern u16 func_021F4ED8(const char *p, const u16 *b);
extern int func_021F2190(char *,u16),func_021F2150(u8 *);
extern void func_021F4DDC(const char *p, int i, u16 *dst, u32 n, u8 *count);
extern int func_021F4E98(char *,int,u16 *,unsigned,u8 *);
extern void func_02082BCC(void *,unsigned,unsigned);
extern u32 func_021F4D94(const unsigned char *p, u32 i);
extern int func_021F299C(int *,int *);
extern void func_021F2BC8(int *,int *,void *);
extern int func_021F2F8C(int *,int *);
extern int func_021F28FC(int *,int *);
extern void func_021F2A88(int *p, int *delta, u8 *saved);
extern int func_021F2F68(int *,int *);
void func_021F23B8(char *p,const u16 *q);
int func_021F23E4(char *p);
u32 func_021F23F4(const u8 *p);
u32 func_021F23F8(const u8 *p);
int func_021F23FC(u8 *p,int direction);
int func_021F253C(u8 *p);
void func_021F256C(char *p, unsigned mode, int index, void *table, u32 a4);
void func_021F25F8(int *a, int b, int c);
void func_021F2608(void *p);
extern const unsigned char d_021F555C[];

void func_021F23B8(char *p,const u16 *q) {while(*q!=func_02045A98()) {if(!func_021F2190(p,*q)) break;q++;}}


int func_021F23E4(char *p)
{
    return ((struct Obj14496 *)p)->f1E == ((struct Obj14496 *)p)->f22;
}

u32 func_021F23F4(const u8 *p) {return ((struct Obj24902 *)p)->f1E;}

u32 func_021F23F8(const u8 *p) {return ((struct Obj24903 *)p)->f20;}

/*
 * lever: read Group values through ((u16 *)((char *)&group+2))[i] to hoist its member base.
 */
int func_021F23FC(u8 *p,int direction)
{
 Group group;
 int (*pick)(int,int,u16 *,int,u8 *);
 int i,j;
 u16 index;
 pick=direction?func_021F4E58:func_021F4E18;
 for(i=0;i<((struct Obj01574 *)p)->f20;i++){
  index=func_021F4ED8(((struct Obj01574 *)p)->f8C,(u16 *)(p+0x16+i*2));
  if(index==0xffff)continue;
  for(j=0;j<i;j++)func_021F2190((char *)p,*(u16 *)(p+0x16+j*2));
  for(j=0;j<i;j++)func_021F2150(p);
  if(pick(*(int *)&((struct Obj01574 *)p)->f8C,index,group.values,4,&group.count)){
   for(i=0;i<group.count;i++)func_021F2190((char *)p,*((u16 *)((char *)&group+2)+i));
   func_021F4DDC(((struct Obj01574 *)p)->f8C,index,group.values,4,&group.count);
   for(i=0;i<group.count;i++)func_021F2150(p);
   func_021F4E98(*(char * *)&((struct Obj01574 *)p)->f8C,index,group.values,4,&group.count);
   for(i=0;i<group.count;i++){
    *(u16 *)(p+0x16+((struct Obj01574 *)p)->f20*2)=*((u16 *)((char *)&group+2)+i);
    ((struct Obj01574 *)p)->f20+=1;
    *(u16 *)(p+0x16+((struct Obj01574 *)p)->f20*2)=func_02045A98();
   }
   return 1;
  }
 }
 return 0;
}

int func_021F253C(u8 *p) {int i,spaces,n;n=*(volatile u16 *)&((struct Obj14497 *)p)->f1E;if(!n) return 0;spaces=0;i=0;while(i<n) {if(*(u16 *)(p+i*2)==32) spaces++;n=*(volatile u16 *)&((struct Obj14497 *)p)->f1E;i++;}return i!=spaces;}

void func_021F256C(char *p, unsigned mode, int index, void *table, u32 a4) {
 int i;
 func_02082BCC(p,0,36);((struct Obj02530 *)p)->f0=(void *)func_021F4D94(table,index);
 switch(mode) {
 case 3:
 ((struct Obj02530 *)p)->f20=11;((struct Obj02530 *)p)->f22=4;
 ((struct Obj02530 *)p)->f14=func_021F299C;((struct Obj02530 *)p)->f18=func_021F2BC8;((struct Obj02530 *)p)->f1C=func_021F2F8C;break;
 case 0:case 1:case 2:
 ((struct Obj02530 *)p)->f20=13;((struct Obj02530 *)p)->f22=6;
 ((struct Obj02530 *)p)->f14=func_021F28FC;((struct Obj02530 *)p)->f18=func_021F2A88;((struct Obj02530 *)p)->f1C=func_021F2F68;break;
 }
 for(i=0;i<13;i++)*(unsigned char *)(p+4+i)=d_021F555C[i];
}


void func_021F25F8(int *a, int b, int c)
{
    *a = func_021F4D94((const u8 *)c, b);
}

void func_021F2608(void *p) {func_02082BCC(p,0,36);}

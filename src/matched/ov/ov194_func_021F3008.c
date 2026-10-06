/*
 * function: func_021F3008
 * address: 0x021F3008
 * packet: pkt_ov194_021F3008
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: two zero alignment bytes at 021F31B6 before 31B8.
 * prototype: 256C retains fifth heap input visibly stored by caller; heap forwards use full words without caller-side truncation.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02049EB4 0x02049EB4 arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_02040588 0x02040588 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021F19A0 0x021F19A0 thumb ov194
 *   func_021F3358 0x021F3358 thumb ov194
 *   func_021F256C 0x021F256C thumb ov194
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_021F26F0 0x021F26F0 thumb ov194
 *   func_020355C4 0x020355C4 arm
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_021F1A1C 0x021F1A1C thumb ov194
 */
#include "../include/Obj00733.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef struct {int x,y,z,w;} Box;
typedef struct {int x,y;} Pair;
extern void func_02082BCC(void *,int,int);
extern void *func_02049EB4(u32,u32,u32,u32,u32);
extern void func_02040AE0(u32,const void *,u32);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020409B4(u32);
extern void func_021F19A0(u8 *,void *,void *,u32);
struct Descriptor;
extern u32 func_021F3358(u32 a, u32 b, u32 c);
extern void func_021F256C(char *,unsigned,int,void *,u32);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
struct Cfg;
struct Rect;
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_021F26F0(char *,char *,void *,void *,u32);
extern u8 func_020355C4(void);
extern int func_021F2818(char *,Pair *,Box *);
extern void func_021F1A1C(char *p, int mode, const struct Rect *rect, int flag, int selected);
void func_021F3008(u8 *p,int mode,void *font,void *window,void *data,void *palette,u32 heap)
{
 Box box;
 void *bg;
 int index;
 func_02082BCC(p,0,0x130);
 ((struct Obj00733 *)p)->fD8=0;((struct Obj00733 *)p)->fDC=0;
 ((struct Obj00733 *)p)->fF4=font;((struct Obj00733 *)p)->fF8=window;((struct Obj00733 *)p)->fFE=heap;
 ((struct Obj00733 *)p)->f100=mode;((struct Obj00733 *)p)->f114=mode;((struct Obj00733 *)p)->f12C=data;
 ((struct Obj00733 *)p)->f11C=func_02049EB4(118,10,0,(u32)(p+0x124),heap);
 ((struct Obj00733 *)p)->f120=func_02049EB4(118,5,0,(u32)(p+0x128),heap);
 if(mode==3){func_02040AE0(1,*(char * *)&((struct Obj00733 *)p)->f124+12,2048);func_02040588(2,0);}
 else {func_02040AE0(1,*(char * *)&((struct Obj00733 *)p)->f128+12,2048);func_02040588(2,1);}
 func_020409B4(1);
 func_021F19A0(p+0x24,(void *)mode,palette,heap);
 index=func_021F3358(((struct Obj00733 *)p)->f100,((struct Obj00733 *)p)->f104,p[0x108]);
 func_021F256C((char *)p,mode,index,((struct Obj00733 *)p)->f12C,heap);
 bg=(void *)func_020450F0(3,3,5,26,15,15,1);
 ((struct Obj00733 *)p)->fE0=bg;
 func_02045334(bg);func_02045374(bg);func_020409B4(func_02045730(bg));
 ((struct Obj00733 *)p)->fEC=((struct Obj00733 *)p)->fE0;p[0xf0]=0;
 func_021F26F0((char *)p,(char *)p+0xec,window,font,heap);
 if(func_020355C4()==0){
  if(func_021F2818((char *)p,(Pair *)(p+0xd8),&box))func_021F1A1C((char *)p+0x24,1,(const struct Rect *)(&box),((struct Obj00733 *)p)->f104,((struct Obj00733 *)p)->f100);
 }else {
  if(func_021F2818((char *)p,(Pair *)(p+0xd8),&box))func_021F1A1C((char *)p+0x24,0,(const struct Rect *)(&box),((struct Obj00733 *)p)->f104,((struct Obj00733 *)p)->f100);
 }
}

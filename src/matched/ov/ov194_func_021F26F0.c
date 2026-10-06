/*
 * function: func_021F26F0
 * address: 0x021F26F0
 * packet: pkt_ov194_021F26F0
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: two zero alignment bytes at 021F2816 before matched 2818.
 * lever: cast measured width/height to u16 after division by two.
 * prototype: 2818 tail forwarder leaves r0 live; 4D9C/4DA0 read incoming r0 despite legacy void extern.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045A98 0x02045A98 arm
 *   func_02045994 0x02045994 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045808 0x02045808 arm
 *   func_021F4DA0 0x021F4DA0 thumb ov194
 *   func_021F4D9C 0x021F4D9C thumb ov194
 *   func_021F2818 0x021F2818 thumb ov194
 *   func_021F2614 0x021F2614 thumb ov194
 */
#include "../include/Obj10808.h"
#include "../include/Obj14500.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef struct {int x,y,z,w;} Box;
typedef struct {int x,y;} Pair;
struct Descriptor;
struct PrintSys;
struct Strbuf;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u16 func_02045A98(void);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02045808(struct U16Vec *vec);
extern u16 func_021F4DA0(const u16 *p);
extern u16 func_021F4D9C(void *);
extern int func_021F2818(char *,Pair *,Box *);
extern unsigned func_021F2614(char *,int *,u16 *);
void func_021F26F0(char *p,char *target,void *window,void *font,u16 heap)
{
 Box box;
 Pair xy;
 u16 codes[3];
 void *text;
 u16 x,y;
 unsigned kind;
 text=func_020457B0(2,heap);
 for(xy.y=0;xy.y<func_021F4DA0(((struct Obj10808 *)p)->f0);xy.y++){
  for(xy.x=0;xy.x<func_021F4D9C(((struct Obj10808 *)p)->f0);xy.x++){
   if(func_021F2818(p,&xy,&box)){
    kind=func_021F2614(p,(int *)&xy,codes);
    if(kind==1 || kind==10 || kind==11){
     codes[1]=codes[0];codes[2]=func_02045A98();
     func_02045994(text,codes+1,2);
     box.x*=8;box.y*=8;box.z*=8;box.w*=8;
     x=box.x+(box.z-box.x)/2-24;
     y=box.y+(box.w-box.y)/2-40;
     x-=(u16)(func_0201D304(text,(u32)font,0)/2);
     y-=(u16)(func_0201D42C(text,font)/2);
     func_0201C6FC(window,(u32)func_02045770(((struct Obj14500 *)target)->f0),(short)(x-1),(short)y,text,(u32)font);
     target[4]=1;
    }
   }
  }
 }
 func_02045808(text);
}

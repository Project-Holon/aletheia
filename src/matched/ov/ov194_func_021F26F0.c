/*
 * function: NAMEIN_GRAPHIC_DrawCellTips
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
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   STRBUF_SetStringN 0x02045994 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   STRBUF_Delete 0x02045808 arm
 *   NAMEIN_GRAPHIC_GetGridHeight 0x021F4DA0 thumb ov194
 *   NAMEIN_GRAPHIC_GetGridWidth 0x021F4D9C thumb ov194
 *   NAMEIN_GRAPHIC_PickerGetBox 0x021F2818 thumb ov194
 *   NAMEIN_GRAPHIC_PickerToChar 0x021F2614 thumb ov194
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
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u16 STRBUF_GetEosChar(void);
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len);
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u16 NAMEIN_GRAPHIC_GetGridHeight(const u16 *p);
extern u16 NAMEIN_GRAPHIC_GetGridWidth(const u16 *p);
extern int NAMEIN_GRAPHIC_PickerGetBox(char *,Pair *,Box *);
extern unsigned NAMEIN_GRAPHIC_PickerToChar(char *,int *,u16 *);
void NAMEIN_GRAPHIC_DrawCellTips(char *p,char *target,void *window,void *font,u16 heap)
{
 Box box;
 Pair xy;
 u16 codes[3];
 void *text;
 u16 x,y;
 unsigned kind;
 text=STRBUF_Create(2,heap);
 for(xy.y=0;xy.y<NAMEIN_GRAPHIC_GetGridHeight(((struct Obj10808 *)p)->f0);xy.y++){
  for(xy.x=0;xy.x<NAMEIN_GRAPHIC_GetGridWidth(((struct Obj10808 *)p)->f0);xy.x++){
   if(NAMEIN_GRAPHIC_PickerGetBox(p,&xy,&box)){
    kind=NAMEIN_GRAPHIC_PickerToChar(p,(int *)&xy,codes);
    if(kind==1 || kind==10 || kind==11){
     codes[1]=codes[0];codes[2]=STRBUF_GetEosChar();
     STRBUF_SetStringN(text,codes+1,2);
     box.x*=8;box.y*=8;box.z*=8;box.w*=8;
     x=box.x+(box.z-box.x)/2-24;
     y=box.y+(box.w-box.y)/2-40;
     x-=(u16)(func_0201D304(text,(u32)font,0)/2);
     y-=(u16)(func_0201D42C(text,font)/2);
     PRINTSYS_PrintQue(window,(u32)BMP_WIN_GetBmp(((struct Obj14500 *)target)->f0),(short)(x-1),(short)y,text,(u32)font);
     target[4]=1;
    }
   }
  }
 }
 STRBUF_Delete(text);
}

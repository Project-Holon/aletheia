/*
 * function: NAMEIN_GRAPHIC_InitGrid
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
 *   MI_CpuFill8 0x02082BCC arm
 *   ARC_UTIL_LoadPaletteDataFromArchive 0x02049EB4 arm
 *   BG_SYS_DecodeTile 0x02040AE0 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   NAMEIN_GRAPHIC_InitCursor 0x021F19A0 thumb ov194
 *   NAMEIN_GRAPHIC_GridIndex 0x021F3358 thumb ov194
 *   NAMEIN_GRAPHIC_InitPicker 0x021F256C thumb ov194
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   NAMEIN_GRAPHIC_DrawCellTips 0x021F26F0 thumb ov194
 *   func_020355C4 0x020355C4 arm
 *   NAMEIN_GRAPHIC_PickerGetBox 0x021F2818 thumb ov194
 *   NAMEIN_GRAPHIC_SetupCursor 0x021F1A1C thumb ov194
 */
#include "../include/Obj00733.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef struct {int x,y,z,w;} Box;
typedef struct {int x,y;} Pair;
extern void MI_CpuFill8(void *,int,int);
extern void *ARC_UTIL_LoadPaletteDataFromArchive(u32,u32,u32,u32,u32);
extern void BG_SYS_DecodeTile(u32,const void *,u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_PushTile(u32);
extern void NAMEIN_GRAPHIC_InitCursor(u8 *,void *,void *,u32);
struct Descriptor;
extern u32 NAMEIN_GRAPHIC_GridIndex(u32 a, u32 b, u32 c);
extern void NAMEIN_GRAPHIC_InitPicker(char *,unsigned,int,void *,u32);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
struct Cfg;
struct Rect;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void NAMEIN_GRAPHIC_DrawCellTips(char *,char *,void *,void *,u32);
extern u8 func_020355C4(void);
extern int NAMEIN_GRAPHIC_PickerGetBox(char *,Pair *,Box *);
extern void NAMEIN_GRAPHIC_SetupCursor(char *p, int mode, const struct Rect *rect, int flag, int selected);
void NAMEIN_GRAPHIC_InitGrid(u8 *p,int mode,void *font,void *window,void *data,void *palette,u32 heap)
{
 Box box;
 void *bg;
 int index;
 MI_CpuFill8(p,0,0x130);
 ((struct Obj00733 *)p)->fD8=0;((struct Obj00733 *)p)->fDC=0;
 ((struct Obj00733 *)p)->fF4=font;((struct Obj00733 *)p)->fF8=window;((struct Obj00733 *)p)->fFE=heap;
 ((struct Obj00733 *)p)->f100=mode;((struct Obj00733 *)p)->f114=mode;((struct Obj00733 *)p)->f12C=data;
 ((struct Obj00733 *)p)->f11C=ARC_UTIL_LoadPaletteDataFromArchive(118,10,0,(u32)(p+0x124),heap);
 ((struct Obj00733 *)p)->f120=ARC_UTIL_LoadPaletteDataFromArchive(118,5,0,(u32)(p+0x128),heap);
 if(mode==3){BG_SYS_DecodeTile(1,*(char * *)&((struct Obj00733 *)p)->f124+12,2048);func_02040588(2,0);}
 else {BG_SYS_DecodeTile(1,*(char * *)&((struct Obj00733 *)p)->f128+12,2048);func_02040588(2,1);}
 BG_SYS_PushTile(1);
 NAMEIN_GRAPHIC_InitCursor(p+0x24,(void *)mode,palette,heap);
 index=NAMEIN_GRAPHIC_GridIndex(((struct Obj00733 *)p)->f100,((struct Obj00733 *)p)->f104,p[0x108]);
 NAMEIN_GRAPHIC_InitPicker((char *)p,mode,index,((struct Obj00733 *)p)->f12C,heap);
 bg=(void *)BMP_WIN_Create(3,3,5,26,15,15,1);
 ((struct Obj00733 *)p)->fE0=bg;
 BMP_WIN_TransferChars(bg);BMP_WIN_MakeScreen(bg);BG_SYS_PushTile(BMP_WIN_GetBgLayer(bg));
 ((struct Obj00733 *)p)->fEC=((struct Obj00733 *)p)->fE0;p[0xf0]=0;
 NAMEIN_GRAPHIC_DrawCellTips((char *)p,(char *)p+0xec,window,font,heap);
 if(func_020355C4()==0){
  if(NAMEIN_GRAPHIC_PickerGetBox((char *)p,(Pair *)(p+0xd8),&box))NAMEIN_GRAPHIC_SetupCursor((char *)p+0x24,1,(const struct Rect *)(&box),((struct Obj00733 *)p)->f104,((struct Obj00733 *)p)->f100);
 }else {
  if(NAMEIN_GRAPHIC_PickerGetBox((char *)p,(Pair *)(p+0xd8),&box))NAMEIN_GRAPHIC_SetupCursor((char *)p+0x24,0,(const struct Rect *)(&box),((struct Obj00733 *)p)->f104,((struct Obj00733 *)p)->f100);
 }
}

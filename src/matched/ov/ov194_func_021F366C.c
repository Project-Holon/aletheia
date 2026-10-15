/*
 * function: NAMEIN_GRAPHIC_SetGridSelection
 * address: 0x021F366C
 * packet: pkt_ov194_021F366C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * volatile: 021F3676 and 021F3696 re-read the mode word at +0x100.
 * symbols:
 *   NAMEIN_GRAPHIC_GridIndex 0x021F3358 thumb ov194
 *   NAMEIN_GRAPHIC_LoadGrid 0x021F25F8 thumb ov194
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   NAMEIN_GRAPHIC_DrawCellTips 0x021F26F0 thumb ov194
 */
#include "../include/Obj00117.h"
typedef unsigned int   u32;
extern u32 NAMEIN_GRAPHIC_GridIndex(u32 a, u32 b, u32 c);extern void NAMEIN_GRAPHIC_LoadGrid(int *,int,void *);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);extern void BMP_Clear(int,unsigned);
typedef unsigned short u16;
extern void NAMEIN_GRAPHIC_DrawCellTips(char *p, char *target, void *window, void *font, u16 heap);
void NAMEIN_GRAPHIC_SetGridSelection(char *p,int index,int variant) {
 int selected;
 if(*(volatile int *)&((struct Obj00117 *)p)->f100!=3)return;
 if(((struct Obj00117 *)p)->f108==variant && ((struct Obj00117 *)p)->f104==index)return;
 selected=(int)NAMEIN_GRAPHIC_GridIndex((int)(*(volatile int *)&((struct Obj00117 *)p)->f100),(int)index,(unsigned char)variant);
 NAMEIN_GRAPHIC_LoadGrid((int *)p,selected,((struct Obj00117 *)p)->f12C);
 BMP_Clear((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00117 *)p)->fE0),0);
 NAMEIN_GRAPHIC_DrawCellTips(p,p+0xEC,(void *)(((struct Obj00117 *)p)->fF8),(void *)(((struct Obj00117 *)p)->fF4),((struct Obj00117 *)p)->fFE);
 ((struct Obj00117 *)p)->f104=index;((struct Obj00117 *)p)->f108=variant;
}

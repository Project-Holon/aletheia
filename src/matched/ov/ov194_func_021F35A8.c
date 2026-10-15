/*
 * function: NAMEIN_GRAPHIC_SwitchGridMode
 * address: 0x021F35A8
 * packet: pkt_ov194_021F35A8
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   NAMEIN_GRAPHIC_ClearPicker 0x021F2608 thumb ov194
 *   NAMEIN_GRAPHIC_GridIndex 0x021F3358 thumb ov194
 *   NAMEIN_GRAPHIC_InitPicker 0x021F256C thumb ov194
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   NAMEIN_GRAPHIC_DrawCellTips 0x021F26F0 thumb ov194
 *   BG_SYS_DecodeTile 0x02040AE0 arm
 *   func_02040588 0x02040588 arm
 *   func_020409B4 0x020409B4 arm
 *   NAMEIN_GRAPHIC_ConvertCellMode 0x021F2884 thumb ov194
 */
#include "../include/Obj01773.h"
typedef unsigned int   u32;
extern void NAMEIN_GRAPHIC_ClearPicker(void *p);
extern u32 NAMEIN_GRAPHIC_GridIndex(u32 a, u32 b, u32 c);
extern void NAMEIN_GRAPHIC_InitPicker(char *p, unsigned mode, int index, void *table, u32 a4);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);extern void BMP_Clear(int,unsigned);
typedef unsigned short u16;
extern void NAMEIN_GRAPHIC_DrawCellTips(char *p, char *target, void *window, void *font, u16 heap);
extern void BG_SYS_DecodeTile(unsigned,const void *,unsigned);extern void func_02040588(unsigned,unsigned);extern void func_020409B4(unsigned);
extern void NAMEIN_GRAPHIC_ConvertCellMode(int *,int,int);
void NAMEIN_GRAPHIC_SwitchGridMode(char *p, u32 mode) {
 int index;
 if(((struct Obj01773 *)p)->f100==mode)return;
 NAMEIN_GRAPHIC_ClearPicker(p);
 index=NAMEIN_GRAPHIC_GridIndex(mode,((struct Obj01773 *)p)->f104,((struct Obj01773 *)p)->f108);
 NAMEIN_GRAPHIC_InitPicker(p,mode,index,((struct Obj01773 *)p)->f12C,((struct Obj01773 *)p)->fFE);
 BMP_Clear((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01773 *)p)->fE0),0);
 NAMEIN_GRAPHIC_DrawCellTips(p,p+0xEC,(void *)(((struct Obj01773 *)p)->fF8),(void *)(((struct Obj01773 *)p)->fF4),((struct Obj01773 *)p)->fFE);
 if(mode==3) {BG_SYS_DecodeTile(1,*(char * *)&((struct Obj01773 *)p)->f124+12,2048);func_02040588(2,0);}
 else BG_SYS_DecodeTile(1,*(char * *)&((struct Obj01773 *)p)->f128+12,2048);
 func_020409B4(1);
 if(mode==3 || ((struct Obj01773 *)p)->f100==3)NAMEIN_GRAPHIC_ConvertCellMode((int *)(p+0xD8),((struct Obj01773 *)p)->f100,mode);
 ((struct Obj01773 *)p)->f100=mode;
}

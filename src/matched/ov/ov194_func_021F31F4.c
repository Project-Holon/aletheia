/*
 * function: NAMEIN_GRAPHIC_UpdateGrid
 * address: 0x021F31F4
 * packet: pkt_ov194_021F31F4
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   NAMEIN_GRAPHIC_KanaTouch 0x021F38CC thumb ov194
 *   NAMEIN_GRAPHIC_KanaKeyMove 0x021F36E8 thumb ov194
 *   NAMEIN_GRAPHIC_KanaKeyAction 0x021F37EC thumb ov194
 *   NAMEIN_GRAPHIC_ApplyKanaAction 0x021F391C thumb ov194
 *   NAMEIN_GRAPHIC_SymbolTouch 0x021F3BD4 thumb ov194
 *   NAMEIN_GRAPHIC_SymbolKeyMove 0x021F3A0C thumb ov194
 *   NAMEIN_GRAPHIC_SymbolKeyAction 0x021F3B18 thumb ov194
 *   NAMEIN_GRAPHIC_ApplySymbolAction 0x021F3C40 thumb ov194
 *   NAMEIN_GRAPHIC_AnimateGrid 0x021F33C0 thumb ov194
 *   NAMEIN_GRAPHIC_IsFieldFull 0x021F23E4 thumb ov194
 *   NAMEIN_GRAPHIC_FindCellByValue 0x021F2828 thumb ov194
 *   NAMEIN_GRAPHIC_PickerGetBox 0x021F2818 thumb ov194
 *   NAMEIN_GRAPHIC_UpdateCursor 0x021F1BFC thumb ov194
 *   NAMEIN_GRAPHIC_IsGridDrawDone 0x021F3304 thumb ov194
 */
#include "../include/Obj00117.h"
typedef struct {int x,y;} Pair;
typedef struct {int left,top,right,bottom;} Rect;
extern void MI_CpuFill8(void *,unsigned,unsigned);
extern int NAMEIN_GRAPHIC_KanaTouch(char *,int *),NAMEIN_GRAPHIC_KanaKeyMove(char *,int *),NAMEIN_GRAPHIC_KanaKeyAction(char *,int *);
extern void NAMEIN_GRAPHIC_ApplyKanaAction(char *,int *);
extern int NAMEIN_GRAPHIC_SymbolTouch(char *,int *),NAMEIN_GRAPHIC_SymbolKeyMove(char *,int *),NAMEIN_GRAPHIC_SymbolKeyAction(char *,int *);
extern void NAMEIN_GRAPHIC_ApplySymbolAction(char *,int *);
extern int NAMEIN_GRAPHIC_AnimateGrid(char *),NAMEIN_GRAPHIC_IsFieldFull(char *),NAMEIN_GRAPHIC_IsGridDrawDone(char *);
extern int NAMEIN_GRAPHIC_FindCellByValue(const char *,int,Pair *);
extern void NAMEIN_GRAPHIC_PickerGetBox(char *a, int b, int c);
extern void NAMEIN_GRAPHIC_UpdateCursor(char *p, int sel, const void *rect);
void NAMEIN_GRAPHIC_UpdateGrid(char *p,char *q)
{
    int out0[4];
    int out2[4];
    Rect rect;
    int result;
    ((struct Obj00117 *)p)->fE8=0;
    switch(((struct Obj00117 *)p)->fE4){
    case 0:
        MI_CpuFill8(out0,0,16);
        result=NAMEIN_GRAPHIC_KanaTouch(p,out0);
        if(!result){NAMEIN_GRAPHIC_KanaKeyMove(p,out0);result=NAMEIN_GRAPHIC_KanaKeyAction(p,out0);}
        if(result)NAMEIN_GRAPHIC_ApplyKanaAction(p,out0);
        break;
    case 2:
        MI_CpuFill8(out2,0,16);
        result=NAMEIN_GRAPHIC_SymbolTouch(p,out2);
        if(!result){NAMEIN_GRAPHIC_SymbolKeyMove(p,out2);result=NAMEIN_GRAPHIC_SymbolKeyAction(p,out2);}
        if(result)NAMEIN_GRAPHIC_ApplySymbolAction(p,out2);
        if(NAMEIN_GRAPHIC_AnimateGrid(p))((struct Obj00117 *)p)->fE4=0;
        break;
    case 1:
        if(NAMEIN_GRAPHIC_IsFieldFull(q)){NAMEIN_GRAPHIC_FindCellByValue(p,7,(Pair *)(p+0xD8));((struct Obj00117 *)p)->fE8=11;}
        ((struct Obj00117 *)p)->fE4=0;
        break;
    }
    NAMEIN_GRAPHIC_PickerGetBox(p,(int)(p+0xD8),(int)&rect);
    NAMEIN_GRAPHIC_UpdateCursor(p+0x24,((struct Obj00117 *)p)->f100,&rect);
    NAMEIN_GRAPHIC_IsGridDrawDone(p);
}

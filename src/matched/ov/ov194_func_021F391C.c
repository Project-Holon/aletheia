/*
 * function: NAMEIN_GRAPHIC_ApplyKanaAction
 * address: 0x021F391C
 * packet: pkt_ov194_021F391C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NAMEIN_GRAPHIC_PickerToChar 0x021F2614 thumb ov194
 *   NAMEIN_GRAPHIC_SetGridMode 0x021F3364 thumb ov194
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   NAMEIN_GRAPHIC_SetGridSelection 0x021F366C thumb ov194
 *   NAMEIN_GRAPHIC_PickerGetBox 0x021F2818 thumb ov194
 *   NAMEIN_GRAPHIC_SetupCursor 0x021F1A1C thumb ov194
 */
#include "../include/Obj00117.h"
typedef struct {int left,top,right,bottom;} Rect;
extern unsigned NAMEIN_GRAPHIC_PickerToChar(char *,int *,unsigned short *);
extern int NAMEIN_GRAPHIC_SetGridMode(char *,int),NAMEIN_GRAPHIC_PickerGetBox(char *,int,int);
extern void GFL_USE_PlaySeDefaultVolume(unsigned),NAMEIN_GRAPHIC_SetGridSelection(char *,int,int);
struct Rect;
extern void NAMEIN_GRAPHIC_SetupCursor(char *p, int mode, const struct Rect *rect, int flag, int selected);
void NAMEIN_GRAPHIC_ApplyKanaAction(char *p,int *input)
{
    unsigned code;
    Rect rect;
    if(input[1])code=NAMEIN_GRAPHIC_PickerToChar(p,(int *)(p+0xD8),(unsigned short *)(p+0xFC));
    else code=input[0];
    switch(code){
    case 0:break;
    case 1:((struct Obj00117 *)p)->fE8=1;((struct Obj00117 *)p)->fE4=1;break;
    case 9:((struct Obj00117 *)p)->fE8=9;((struct Obj00117 *)p)->fE4=1;break;
    case 2:case 3:case 4:case 5:
        if(NAMEIN_GRAPHIC_SetGridMode(p,code-2)){
            GFL_USE_PlaySeDefaultVolume(1611);((struct Obj00117 *)p)->fE4=2;((struct Obj00117 *)p)->fE8=6;
        }break;
    case 6:((struct Obj00117 *)p)->fE8=5;break;
    case 7:((struct Obj00117 *)p)->fE8=7;break;
    case 8:
        GFL_USE_PlaySeDefaultVolume(1356);((struct Obj00117 *)p)->fE8=8;
        NAMEIN_GRAPHIC_SetGridSelection(p,((struct Obj00117 *)p)->f104^1,((struct Obj00117 *)p)->f108);break;
    case 10:((struct Obj00117 *)p)->fE8=3;break;
    case 11:((struct Obj00117 *)p)->fE8=4;break;
    }
    if(NAMEIN_GRAPHIC_PickerGetBox(p,(int)(input+2),(int)&rect))
        NAMEIN_GRAPHIC_SetupCursor(p+0x24,2,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
}

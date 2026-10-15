/*
 * function: NAMEIN_GRAPHIC_KanaKeyMove
 * address: 0x021F36E8
 * packet: pkt_ov194_021F36E8
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Integer address arithmetic for26E0 keeps p+D8 apart from2818's pointer arithmetic.
 * symbols:
 *   KEY_GetRepeat 0x0203633C arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   NAMEIN_GRAPHIC_FindCellByValue 0x021F2828 thumb ov194
 *   NAMEIN_GRAPHIC_PickerGetBox 0x021F2818 thumb ov194
 *   NAMEIN_GRAPHIC_PickerMove 0x021F26E0 thumb ov194
 *   NAMEIN_GRAPHIC_SetupCursor 0x021F1A1C thumb ov194
 */
#include "../include/Obj00117.h"
typedef unsigned char u8;
typedef struct {int x,y;} Pair;
typedef struct {unsigned char pad[0xD8];Pair xy;} Ctx;
typedef struct {int left,top,right,bottom;} Rect;
extern unsigned KEY_GetRepeat(void),KEY_GetTrg(void);
extern u8 func_020355C4(void);
extern void func_020355D8(u8),GFL_USE_PlaySeDefaultVolume(unsigned);
extern int NAMEIN_GRAPHIC_FindCellByValue(const char *,int,Pair *);
extern int NAMEIN_GRAPHIC_PickerGetBox(char *,int,int);
extern void NAMEIN_GRAPHIC_PickerMove(char *,int,int);
struct Rect;
extern void NAMEIN_GRAPHIC_SetupCursor(char *p, int mode, const struct Rect *rect, int flag, int selected);
int NAMEIN_GRAPHIC_KanaKeyMove(char *p,int *out)
{
    Rect rect;
    Pair delta;
    int changed=0;
    if(KEY_GetRepeat()&64){delta.x=0;delta.y=-1;changed=1;}
    else if(KEY_GetRepeat()&128){delta.x=0;delta.y=1;changed=1;}
    else if(KEY_GetRepeat()&32){delta.x=-1;delta.y=0;changed=1;}
    else if(KEY_GetRepeat()&16){delta.x=1;delta.y=0;changed=1;}
    else if(KEY_GetTrg()&8){
        delta.x=0;delta.y=0;changed=1;
        NAMEIN_GRAPHIC_FindCellByValue(p,7,(Pair *)(p+0xD8));
        NAMEIN_GRAPHIC_PickerMove(p,(int)(p+0xD8),(int)&delta);
    }
    if(changed){
        if(func_020355C4()==1){
            if(NAMEIN_GRAPHIC_PickerGetBox(p,(int)(p+0xD8),(int)&rect)){
                func_020355D8(0);
                NAMEIN_GRAPHIC_SetupCursor(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
                GFL_USE_PlaySeDefaultVolume(1352);
            }
        }else{
            NAMEIN_GRAPHIC_PickerMove(p,(int)p+0xD8,(int)&delta);
            if(NAMEIN_GRAPHIC_PickerGetBox(p,(int)(p+0xD8),(int)&rect)){
                GFL_USE_PlaySeDefaultVolume(1352);
                NAMEIN_GRAPHIC_SetupCursor(p+0x24,1,(const struct Rect *)(&rect),((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
            }
        }
    }
    return 0;
}

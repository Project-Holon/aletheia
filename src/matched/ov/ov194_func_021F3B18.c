/*
 * function: NAMEIN_GRAPHIC_SymbolKeyAction
 * address: 0x021F3B18
 * packet: pkt_ov194_021F3B18
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: eight-byte coordinate pair assignment loads both words before either store.
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   NAMEIN_GRAPHIC_FindCellByValue 0x021F2828 thumb ov194
 *   func_020355C4 0x020355C4 arm
 *   NAMEIN_GRAPHIC_PickerGetBox 0x021F2818 thumb ov194
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_020355D8 0x020355D8 arm
 *   NAMEIN_GRAPHIC_SetupCursor 0x021F1A1C thumb ov194
 */
#include "../include/Obj00117.h"

typedef unsigned int u32;
typedef struct {int x,y;} Pair;
extern u32 KEY_GetTrg(void);
extern int NAMEIN_GRAPHIC_FindCellByValue(char *,int,int *);
typedef unsigned char  u8;
extern u8 func_020355C4(void);
extern int NAMEIN_GRAPHIC_PickerGetBox(char *,int,int);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_020355D8(u8 v);
struct Rect;
extern void NAMEIN_GRAPHIC_SetupCursor(char *p, int mode, const struct Rect *rect, int flag, int selected);
int NAMEIN_GRAPHIC_SymbolKeyAction(char *p,int *out) {
    int changed=0;
    int rect[4];
    if (((struct Obj00117 *)p)->f118==0) {
        if (KEY_GetTrg()&1) {
            *(Pair *)(out+2)=*(Pair *)(p+0xd8);
            changed=1; out[1]=1;
        }
        if (KEY_GetTrg()&4) {
            out[0]=((struct Obj00117 *)p)->f100+3;
            if (out[0]>5) out[0]=2;
            NAMEIN_GRAPHIC_FindCellByValue(p,out[0],(int *)(p+0xd8));
            *(Pair *)(out+2)=*(Pair *)(p+0xd8);
            changed=1;
        }
        if (changed && func_020355C4()==1) {
            if (NAMEIN_GRAPHIC_PickerGetBox(p,(int)(p+0xd8),(int)rect)) {
                GFL_USE_PlaySeDefaultVolume(1352); func_020355D8(0);
                NAMEIN_GRAPHIC_SetupCursor(p+0x24,1,(const struct Rect *)rect,((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
                return 0;
            }
        }
    }
    return changed;
}

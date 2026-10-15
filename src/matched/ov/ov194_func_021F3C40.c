/*
 * function: NAMEIN_GRAPHIC_ApplySymbolAction
 * address: 0x021F3C40
 * packet: pkt_ov194_021F3C40
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NAMEIN_GRAPHIC_PickerToChar 0x021F2614 thumb ov194
 *   NAMEIN_GRAPHIC_SetGridMode 0x021F3364 thumb ov194
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   NAMEIN_GRAPHIC_PickerGetBox 0x021F2818 thumb ov194
 *   NAMEIN_GRAPHIC_SetupCursor 0x021F1A1C thumb ov194
 */
#include "../include/Obj00117.h"
extern unsigned NAMEIN_GRAPHIC_PickerToChar(char *,int *,unsigned short *);
extern int NAMEIN_GRAPHIC_SetGridMode(char *,int);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int NAMEIN_GRAPHIC_PickerGetBox(char *,int,int);
struct Rect;
extern void NAMEIN_GRAPHIC_SetupCursor(char *p, int mode, const struct Rect *rect, int flag, int selected);
void NAMEIN_GRAPHIC_ApplySymbolAction(char *p,int *input) {
    unsigned code;
    int rect[4];
    if (input[1]) code=NAMEIN_GRAPHIC_PickerToChar(p,(int *)(p+0xd8),(unsigned short *)(p+0xfc));
    else code=input[0];
    switch (code) {
    case 0: case 1: break;
    case 2: case 3: case 4: case 5:
        if (NAMEIN_GRAPHIC_SetGridMode(p,code-2)) {
            GFL_USE_PlaySeDefaultVolume(1611);
            ((struct Obj00117 *)p)->fE4=2; ((struct Obj00117 *)p)->fE8=6;
        }
        break;
    }
    if (NAMEIN_GRAPHIC_PickerGetBox(p,(int)(input+2),(int)rect))
        NAMEIN_GRAPHIC_SetupCursor(p+0x24,2,(const struct Rect *)rect,((struct Obj00117 *)p)->f104,((struct Obj00117 *)p)->f100);
}

/*
 * function: NAMEIN_GRAPHIC_SymbolTouch
 * address: 0x021F3BD4
 * packet: pkt_ov194_021F3BD4
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: unsigned result minus two tests the contiguous range; point precedes x/y declarations.
 * symbols:
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   NAMEIN_GRAPHIC_FindCellAtPoint 0x021F265C thumb ov194
 *   NAMEIN_GRAPHIC_PickerToChar 0x021F2614 thumb ov194
 *   func_020355D8 0x020355D8 arm
 */
#include "../include/Obj00117.h"
extern unsigned TOUCHPANEL_GetPointTrg(unsigned *,unsigned *);
extern int NAMEIN_GRAPHIC_FindCellAtPoint(char *,int *,int *);
extern unsigned NAMEIN_GRAPHIC_PickerToChar(char *,int *,unsigned short *);
typedef unsigned char  u8;
extern void func_020355D8(u8 v);
int NAMEIN_GRAPHIC_SymbolTouch(char *p,int *out) {
    int point[2],u;
    unsigned x,y;
    if (((struct Obj00117 *)p)->f118==0) {
        if (TOUCHPANEL_GetPointTrg(&x,&y)) {
            point[0]=x; point[1]=y;
            if (NAMEIN_GRAPHIC_FindCellAtPoint(p,point,(int *)(p+0xd8))) {
                if (NAMEIN_GRAPHIC_PickerToChar(p,(int *)(p+0xd8),0)-2<=3) {
                    u=((struct Obj00117 *)p)->fD8;
                    out[3]=((struct Obj00117 *)p)->fDC;
                    out[1]=1; out[2]=u;
                    func_020355D8(1);
                    return 1;
                }
            }
        }
    }
    return 0;
}

/*
 * function: C_GEAR_HandleButton
 * address:  0x021F1758
 * packet:   pkt_ov029_021F1758
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stack order: c, d, x, y declared in that order ([sp,#0x10], #0xc, #8, #4).
 * The inner switch lists case 3 before case 2 (bodies 1, 6, 5 in the image).
 * C_GEAR_IsColumnRowValid is the unlabelled ov029 leaf filed as ov029_func_021EFEC0.c.
 *
 * symbols:
 *   C_GEAR_HandleButton  0x021F1758  thumb  ov029
 *   UI_SetInputMode  0x020355D8  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   C_GEAR_HitTestTile  0x021F020C  thumb  ov029
 *   C_GEAR_CountCellsOfKind  0x021F0D80  thumb  ov029
 *   C_GEAR_IsColumnRowValid  0x021EFEC0  thumb  ov029
 *   C_GEAR_SetCellKind  0x021F2AEC  thumb  ov029
 *   BG_SYS_PushTile  0x020409B4  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   C_GEAR_IsAnyIndicatorShown  0x021F2DA8  thumb  ov029
 *   C_GEAR_SetPaintModeIcon  0x021F1910  thumb  ov029
 *   BG_SYS_DeleteHalf  0x0203FB44  arm
 *   func_020090E8  0x020090E8  thumb
 *   C_GEAR_LoadSkin  0x021F1458  thumb  ov029
 *   C_GEAR_DrawAllCells  0x021F13FC  thumb  ov029
 *   C_GEAR_SetTileMarkersVisible  0x021F1A44  thumb  ov029
 */
#include "../include/Obj00042.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void UI_SetInputMode(u8 v);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int C_GEAR_HitTestTile(const void *p, int a, int b, int *c, int *d);
extern int C_GEAR_CountCellsOfKind(void *p, int k);
extern int C_GEAR_IsColumnRowValid(int a, int b);
struct Sub020090B0Obj;
extern void C_GEAR_SetCellKind(unsigned char *p, int a1, int a2, int a3, int k);
extern void BG_SYS_PushTile(u32 layer);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern int C_GEAR_IsAnyIndicatorShown(u8 *p);
extern void C_GEAR_SetPaintModeIcon(char *p, int on);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void func_020090E8(struct Sub020090B0Obj *obj, u8 value);
extern u32 C_GEAR_LoadSkin(u8 *p, int a, int b, int c);
extern void C_GEAR_DrawAllCells(void *p);
extern void C_GEAR_SetTileMarkersVisible(char *p, int flag);

void C_GEAR_HandleButton(u8 *p, int key)
{
    int c;
    int d;
    int x;
    int y;
    int r;
    u32 v;

    if (p[0x45A] == 0 && key != 6 && key != 0)
        return;
    if (((struct Obj00042 *)p)->f214 != 0)
        return;
    UI_SetInputMode(1);
    switch (key) {
    case 0:
        (int)TOUCHPANEL_GetPointCont((u32 *)(&x), (u32 *)(&y));
        r = C_GEAR_HitTestTile(p, x, y, &c, &d);
        if (p[0x457] != 0) {
            ((struct Obj00042 *)p)->f2CC = x;
            ((struct Obj00042 *)p)->f2CE = y;
            if ((C_GEAR_CountCellsOfKind(p, r) > 1 || r == 4) && C_GEAR_IsColumnRowValid(c, d) != 0) {
                C_GEAR_SetCellKind((unsigned char *)p, *(int *)&((struct Obj00042 *)p)->f20, c, d, (r + 1) % 5);
                BG_SYS_PushTile(4);
                GFL_USE_PlaySeDefaultVolume(0x628);
            }
        } else if (C_GEAR_IsAnyIndicatorShown(p) == 0) {
            p[0x452] = c;
            p[0x453] = d;
            switch (r) {
            case 1:
                ((struct Obj00042 *)p)->f214 = 1;
                break;
            case 3:
                ((struct Obj00042 *)p)->f214 = 6;
                break;
            case 2:
                ((struct Obj00042 *)p)->f214 = 5;
                break;
            }
        }
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x628);
        p[0x457] ^= 1;
        C_GEAR_SetPaintModeIcon((char *)p, p[0x457]);
        break;
    case 2:
        ((struct Obj00042 *)p)->f214 = 0xC;
        break;
    case 3:
        ((struct Obj00042 *)p)->f214 = 7;
        break;
    case 4:
        ((struct Obj00042 *)p)->f214 = 0xB;
        break;
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x628);
        v = ((struct Obj00042 *)p)->f14;
        BG_SYS_DeleteHalf((int)6, (u16)v, (u16)(v >> 16));
        p[0x458]++;
        p[0x458] = p[0x458] % 5;
        func_020090E8((struct Sub020090B0Obj *)(*(int *)&((struct Obj00042 *)p)->f20), p[0x458]);
        C_GEAR_LoadSkin(p, p[0x459], p[0x458], 0);
        C_GEAR_DrawAllCells(p);
        C_GEAR_SetTileMarkersVisible((char *)p, 1);
        break;
    case 6:
        ((struct Obj00042 *)p)->f214 = 0xD;
        break;
    }
}

/*
 * function: func_021C4700
 * address: 0x021C4700
 * packet: pkt_ov136_021C4700
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_021C446C 0x021C446C thumb ov136
 *   d_021C7784 0x021C7784 data a4
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj00274.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int TOUCHPANEL_HitTrg(const void *p);
typedef unsigned int   u32;
struct Obj;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int func_021C446C(void *a);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
extern u8 d_021C7784[];
int func_021C4700(u8 *p)
{
    int n;
    n = TOUCHPANEL_HitTrg(d_021C7784);
    if (n == -1) return 0;
    if (n == 4) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        p[0xB] = 3;
        return 0;
    }
    if (n < 4) {
        (*(u8 **)(p + 0x1C))[2] = n;
        *(u16 *)*(u8 * *)&((struct Obj00274 *)p)->f1C = (*(u8 **)(p + 0x1C))[2];
        (*(u8 **)(p + 0x1C))[3] = p[0x17];
        GFL_USE_PlaySeDefaultVolume(0x54D);
        return 1;
    }
    if (func_021C446C(p)) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        p[0xB] = 2;
        return 0;
    }
    *(u16 *)*(u8 * *)&((struct Obj00274 *)p)->f1C = 4;
    GFL_USE_PlaySeDefaultVolume(0x54E);
    (*(u8 **)(p + 0x1C))[2] = 0;
    (*(u8 **)(p + 0x1C))[3] = 0;
    APP_TASKMENU_WIN_SetDecide(((struct Obj00274 *)p)->f128, 1);
    APP_TASKMENU_WIN_SetActive(((struct Obj00274 *)p)->f12C, 0);
    return 1;
}

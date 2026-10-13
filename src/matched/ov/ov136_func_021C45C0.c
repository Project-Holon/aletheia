/*
 * function: func_021C45C0
 * address: 0x021C45C0
 * packet: pkt_ov136_021C45C0
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_021C446C 0x021C446C thumb
 *   func_020061E4 0x020061E4 thumb
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   _s32_div_f 0x0209C0A4 arm
 */
#include "../include/Obj00274.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020362DC(void);
struct Obj;
extern int func_021C446C(void *a);
extern void func_020061E4(u32);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);

int func_021C45C0(u8 *p)
{
    int moved;

    if (func_020362DC() & 1) {
        if (p[0x16] == 4) {
            if (func_021C446C(p)) {
                func_020061E4(0x551);
                p[0xB] = 2;
                return 0;
            }
            **(u16 * *)&((struct Obj00274 *)p)->f1C = 4;
            func_020061E4(0x54E);
            (*(u8 **)(p + 0x1C))[2] = 0;
            (*(u8 **)(p + 0x1C))[3] = 0;
            APP_TASKMENU_WIN_SetDecide(((struct Obj00274 *)p)->f128, 1);
            return 1;
        }
        if (p[0x16] == 5) {
            func_020061E4(0x551);
            p[0xB] = 3;
            return 0;
        }
        (*(u8 **)(p + 0x1C))[2] = p[0x16];
        **(u16 * *)&((struct Obj00274 *)p)->f1C = (*(u8 **)(p + 0x1C))[2];
        (*(u8 **)(p + 0x1C))[3] = p[0x17];
        func_020061E4(0x54D);
        return 1;
    }
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        p[0xB] = 3;
        return 0;
    }
    if (func_020362DC() & 8) {
        p[0x16] = 4;
        p[0x17] = 0;
        moved = 1;
    } else if (func_020362DC() & 0x80) {
        p[0x16] = (p[0x16] + 1) % 6;
        moved = 1;
    } else if (func_020362DC() & 0x40) {
        p[0x16] = (p[0x16] + 5) % 6;
        moved = 1;
    } else {
        return 0;
    }
    if (moved == 0) {
        return 0;
    }
    func_020061E4(0x54C);
    if (p[0x16] < 4) {
        APP_TASKMENU_WIN_SetActive(((struct Obj00274 *)p)->f128, 0);
        APP_TASKMENU_WIN_SetActive(((struct Obj00274 *)p)->f12C, 0);
    } else if (p[0x16] == 4) {
        APP_TASKMENU_WIN_SetActive(((struct Obj00274 *)p)->f128, 1);
        APP_TASKMENU_WIN_SetActive(((struct Obj00274 *)p)->f12C, 0);
    } else if (p[0x16] == 5) {
        APP_TASKMENU_WIN_SetActive(((struct Obj00274 *)p)->f128, 0);
        APP_TASKMENU_WIN_SetActive(((struct Obj00274 *)p)->f12C, 1);
    }
    p[0x1A] = p[0x16];
    return 0;
}

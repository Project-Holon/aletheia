/*
 * function: MAILSYS_HandleKeyInput
 * address: 0x021C45C0
 * packet: pkt_ov136_021C45C0
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   MAILSYS_IsMessageIncomplete 0x021C446C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   _s32_div_f 0x0209C0A4 arm
 */
#include "../include/Obj00274.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
struct Obj;
extern int MAILSYS_IsMessageIncomplete(void *a);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);

int MAILSYS_HandleKeyInput(u8 *p)
{
    int moved;

    if (KEY_GetTrg() & 1) {
        if (p[0x16] == 4) {
            if (MAILSYS_IsMessageIncomplete(p)) {
                GFL_USE_PlaySeDefaultVolume(0x551);
                p[0xB] = 2;
                return 0;
            }
            **(u16 * *)&((struct Obj00274 *)p)->f1C = 4;
            GFL_USE_PlaySeDefaultVolume(0x54E);
            (*(u8 **)(p + 0x1C))[2] = 0;
            (*(u8 **)(p + 0x1C))[3] = 0;
            APP_TASKMENU_WIN_SetDecide(((struct Obj00274 *)p)->f128, 1);
            return 1;
        }
        if (p[0x16] == 5) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            p[0xB] = 3;
            return 0;
        }
        (*(u8 **)(p + 0x1C))[2] = p[0x16];
        **(u16 * *)&((struct Obj00274 *)p)->f1C = (*(u8 **)(p + 0x1C))[2];
        (*(u8 **)(p + 0x1C))[3] = p[0x17];
        GFL_USE_PlaySeDefaultVolume(0x54D);
        return 1;
    }
    if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        p[0xB] = 3;
        return 0;
    }
    if (KEY_GetTrg() & 8) {
        p[0x16] = 4;
        p[0x17] = 0;
        moved = 1;
    } else if (KEY_GetTrg() & 0x80) {
        p[0x16] = (p[0x16] + 1) % 6;
        moved = 1;
    } else if (KEY_GetTrg() & 0x40) {
        p[0x16] = (p[0x16] + 5) % 6;
        moved = 1;
    } else {
        return 0;
    }
    if (moved == 0) {
        return 0;
    }
    GFL_USE_PlaySeDefaultVolume(0x54C);
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

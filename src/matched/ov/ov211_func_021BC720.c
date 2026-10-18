/*
 * function: ZUKAN_SEARCH_SCREEN_HandleInput
 * address:  0x021BC720
 * packet:   pkt_ov211_021BC720
 * region:   ov211
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TOUCHPANEL_GetCont   0x02035C38  arm
 *   UI_SetInputMode   0x020355D8  arm
 *   KEY_GetTrg   0x020362DC  arm
 *   ZUKAN_StartWipeOut   0x021C93C4  thumb ov212
 */
#include "../include/Obj06700.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int  TOUCHPANEL_GetCont(void);
extern void UI_SetInputMode(u8 v);
extern u32 KEY_GetTrg(void);
extern void ZUKAN_StartWipeOut(u32 heap);

int ZUKAN_SEARCH_SCREEN_HandleInput(char *p)
{
    u32 v = 1;

    if (((struct Obj06700 *)p)->f8 == 0x12C)
        return 5;
    ((struct Obj06700 *)p)->f8 = ((struct Obj06700 *)p)->f8 + 1;
    if (TOUCHPANEL_GetCont() == 1) {
        UI_SetInputMode(1);
        return 5;
    }
    if (KEY_GetTrg() & 1) {
        UI_SetInputMode(0);
        return 5;
    }
    if (KEY_GetTrg() & 2) {
        UI_SetInputMode(0);
        v = 0;
        *(u32 *)(((struct Obj06700 *)p)->f0 + 8) = v;
        ZUKAN_StartWipeOut(0x7E);
        return 3;
    }
    if (KEY_GetTrg() & 0x400) {
        UI_SetInputMode(0);
        *(u32 *)(((struct Obj06700 *)p)->f0 + 8) = v;
        ZUKAN_StartWipeOut(0x7E);
        return 3;
    }
    return 4;
}

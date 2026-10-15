/*
 * function: MYSTERY_ALBUM_SingleHandler
 * address: 0x021DCEC4
 * packet: pkt_ov121_021DCEC4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_UTIL_CreateMenuWindow 0x021D9CA4 thumb ov121
 *   MYSTERY_UTIL_DrawMenuWindow 0x021D9FFC thumb ov121
 *   MYSTERY_UTIL_SetMenuMessage 0x021D9F08 thumb ov121
 *   MYSTERY_UTIL_GetMenuState 0x021D9FF8 thumb ov121
 *   MYSTERY_UTIL_DeleteMenuWindow 0x021D9E04 thumb ov121
 *   MYSTERY_UTIL_SetTaskHandler 0x021DA8B0 thumb ov121
 *   MYSTERY_UTIL_UpdateMenuWindow 0x021D9E50 thumb ov121
 *   MYSTERY_ALBUM_SelectHandler 0x021DC08C thumb ov121
 */
#include "../include/Obj01930.h"
typedef unsigned short u16;
extern void *MYSTERY_UTIL_CreateMenuWindow(int a, unsigned char b, void *c, void *d, u16 heap);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void MYSTERY_UTIL_DrawMenuWindow(u8 *p, int a, int b);
extern void MYSTERY_UTIL_SetMenuMessage(u8 *a, int b, int c, int d);
extern unsigned MYSTERY_UTIL_GetMenuState(u8 *p);
extern void MYSTERY_UTIL_DeleteMenuWindow(u8 *p);
extern void MYSTERY_UTIL_SetTaskHandler(u32 *p, u32 a);
extern void MYSTERY_UTIL_UpdateMenuWindow(u8 *p);
extern void MYSTERY_ALBUM_SelectHandler(void *task, u32 *state, char *p);
void MYSTERY_ALBUM_SingleHandler(void *arg,int *state,char *p)
{
    switch (*state) {
    case 0:
        if (!((struct Obj01930 *)p)->fABC)
            ((struct Obj01930 *)p)->fABC=MYSTERY_UTIL_CreateMenuWindow(0,15,((struct Obj01930 *)p)->f14,((struct Obj01930 *)p)->f10,29);
        MYSTERY_UTIL_DrawMenuWindow(((struct Obj01930 *)p)->fABC,1,13);
        MYSTERY_UTIL_SetMenuMessage(((struct Obj01930 *)p)->fABC,((struct Obj01930 *)p)->f1C,92,1);
        *state=1; break;
    case 1:
        if (MYSTERY_UTIL_GetMenuState(((struct Obj01930 *)p)->fABC)) *state=2;
        break;
    case 2:
        if (((struct Obj01930 *)p)->fABC) {
            MYSTERY_UTIL_DeleteMenuWindow(((struct Obj01930 *)p)->fABC);
            ((struct Obj01930 *)p)->fABC=0;
        }
        MYSTERY_UTIL_SetTaskHandler(arg,(u32)MYSTERY_ALBUM_SelectHandler);
        break;
    }
    if (((struct Obj01930 *)p)->fABC) MYSTERY_UTIL_UpdateMenuWindow(((struct Obj01930 *)p)->fABC);
}

/*
 * function: STARTMENU_StateWaitStart
 * address:  0x021BA1A0
 * packet:   pkt_ov088_021BA1A0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_IsIdle  0x0203D210  arm
 *   func_02043534  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   STARTMENU_RemoveVblankTask  0x021BA9C8  thumb  ov088
 *   STARTMENU_DeleteBlinkPalette  0x021BAC64  thumb  ov088
 *   STARTMENU_DeleteFrameManager  0x021BB474  thumb  ov088
 *   STARTMENU_DeleteActors  0x021BB328  thumb  ov088
 *   STARTMENU_DeleteRowWindows  0x021BB164  thumb  ov088
 *   STARTMENU_FreeRowBuffers  0x021BB5C4  thumb  ov088
 *   STARTMENU_DeleteTextSystem  0x021BACD8  thumb  ov088
 *   STARTMENU_TeardownBackgrounds  0x021BAB20  thumb  ov088
 */
#include "../include/Obj13232.h"

typedef unsigned int   u32;
extern u32 GFL_NET_IsIdle(void);
extern void func_02043534(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void STARTMENU_RemoveVblankTask(int *p);
extern void STARTMENU_DeleteBlinkPalette(char *p);
extern void STARTMENU_DeleteFrameManager(char *p);
extern void STARTMENU_DeleteActors(char *p);
extern void STARTMENU_DeleteRowWindows(char *p);
extern void STARTMENU_FreeRowBuffers(char *p);
extern void STARTMENU_DeleteTextSystem(int *p);
extern void STARTMENU_TeardownBackgrounds(void);

int STARTMENU_StateWaitStart(char *p)
{
    unsigned s;
    s = ((struct Obj13232 *)p)->f12A;
    switch (s) {
    case 0:
        ((struct Obj13232 *)p)->f12A = s + 1;
    case 1:
        if (GFL_NET_IsIdle() != 0) {
            STARTMENU_RemoveVblankTask((int *)p);
            STARTMENU_DeleteBlinkPalette(p);
            STARTMENU_DeleteFrameManager(p);
            STARTMENU_DeleteActors(p);
            STARTMENU_DeleteRowWindows(p);
            STARTMENU_FreeRowBuffers(p);
            STARTMENU_DeleteTextSystem((int *)p);
            STARTMENU_TeardownBackgrounds();
            *(unsigned short *)0x04000050 = 0;
            *(unsigned short *)0x04001050 = 0;
            func_02043534(0);
            BG_SYS_SetSubVisiblePlanes(0);
            return 12;
        }
    }
    return 1;
}

/*
 * function: func_021BA1C0
 * address: 0x021BA1C0
 * packet: pkt_ov218_021BA1C0
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UI_SCENE_GetPhaseFrame 0x021B61FC thumb ov067
 *   UI_SCENE_AdvancePhaseFrame 0x021B6200 thumb ov067
 *   func_021B9924 0x021B9924 thumb ov218
 *   func_021B9B78 0x021B9B78 thumb ov218
 *   FADE_IsActive 0x0204E804 arm
 *   BRIGHTNESS_IsFinished 0x02024004 thumb
 */
#include "../include/Obj26046.h"
extern unsigned UI_SCENE_GetPhaseFrame(const unsigned char *);
extern void UI_SCENE_AdvancePhaseFrame(unsigned char *);
extern int func_021B9924(void);
typedef unsigned int   u32;
extern void func_021B9B78(char *p, u32 id);
extern int FADE_IsActive(void);
extern int BRIGHTNESS_IsFinished(int);
int func_021BA1C0(unsigned char *task, char *ctx)
{
    switch (UI_SCENE_GetPhaseFrame(task)) {
    case 0:
        func_021B9924();
advance:
        UI_SCENE_AdvancePhaseFrame(task);
        break;
    case 1:
        if (FADE_IsActive() == 1)
            break;
        if (BRIGHTNESS_IsFinished(1) == 0)
            break;
        func_021B9B78(((struct Obj26046 *)ctx)->f28, 0xef);
        goto advance;
    case 2:
        return 1;
    }
    return 0;
}

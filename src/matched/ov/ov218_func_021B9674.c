/*
 * function: UN_SELECT_SceneUpdate
 * address: 0x021B9674
 * packet: pkt_ov218_021B9674
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   UI_SCENE_Step 0x021B6144 thumb ov067
 *   UN_SELECT_Main 0x021B9AD0 thumb ov218
 *   UN_SELECT_GRAPHIC_Update 0x021BA94C thumb ov218
 */
#include "../include/Obj10971.h"
struct S;
extern void FADE_Start(unsigned int, int, int, int);
extern int FADE_IsActive(void);
extern int UI_SCENE_Step(struct S *);
extern void UN_SELECT_Main(char *);
extern void UN_SELECT_GRAPHIC_Update(char *);
int UN_SELECT_SceneUpdate(void *ctx, int *state, void *unused, char *p)
{
    int result = 0;
    switch (*state) {
    case 0:
        FADE_Start(3, 16, 0, 1);
        ++*state;
        break;
    case 1:
        if (FADE_IsActive() == 0)
            ++*state;
        break;
    case 2:
        if (UI_SCENE_Step(*(struct S * *)&((struct Obj10971 *)p)->f24) != 0)
            result = 1;
        break;
    }
    UN_SELECT_Main(*(char * *)&((struct Obj10971 *)p)->f28);
    UN_SELECT_GRAPHIC_Update(*(char * *)&((struct Obj10971 *)p)->f4);
    return result != 0;
}

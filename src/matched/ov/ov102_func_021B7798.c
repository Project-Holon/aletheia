/*
 * function: IRC_COMPATIBLE_MENU_ProcMain
 * address: 0x021B7798
 * packet: pkt_ov102_021B7798
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 78EC forwards the live index in r1 to 7C14 and leaves its u32 result live.
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   IRC_COMPATIBLE_MENU_GetSprite 0x021B78EC thumb ov102
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   IRC_COMPATIBLE_MENU_StartScrollEffect 0x021B87FC thumb ov102
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   IRC_COMPATIBLE_MENU_UpdateFloaters 0x021B89F0 thumb ov102
 *   IRC_COMPATIBLE_MENU_UpdateScrollEffect 0x021B87C8 thumb ov102
 *   IRC_COMPATIBLE_MENU_UpdateScene 0x021B842C thumb ov102
 */
#include "../include/Obj22139.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void FADE_Start(u32, int, int, int);
extern int FADE_IsActive(void);
extern u32 IRC_COMPATIBLE_MENU_GetSprite(void *, int);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void IRC_COMPATIBLE_MENU_StartScrollEffect(int *);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u16);
extern void IRC_COMPATIBLE_MENU_UpdateFloaters(u8 *);
extern void IRC_COMPATIBLE_MENU_UpdateScrollEffect(u8 *p);
extern void IRC_COMPATIBLE_MENU_UpdateScene(unsigned char *p);
int IRC_COMPATIBLE_MENU_ProcMain(void *unused, u32 *state, int unused2, char *p)
{
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        FADE_Start(3, 16, 0, 0);
        *state = 2;
        break;
    case 2:
        if (FADE_IsActive() == 0) {
            CLACT_SetActorAutoAnim((void *)IRC_COMPATIBLE_MENU_GetSprite(p, 31), 1);
            IRC_COMPATIBLE_MENU_StartScrollEffect((int *)(p + 0xfc));
            GFL_USE_CancelChangeAndPlayBgm(0x52a, 0xffff);
            *state = 3;
        }
        break;
    case 3:
        IRC_COMPATIBLE_MENU_UpdateFloaters((u8 *)(p + 0x118));
        IRC_COMPATIBLE_MENU_UpdateScrollEffect((u8 *)(p + 0xfc));
        (*(void (**)(char *, char *))(p + 0x480))(p, p + 0x484);
        if (((struct Obj22139 *)p)->f488 != 0) *state = 4;
        break;
    case 4:
        FADE_Start(3, 0, 16, 0);
        *state = 5;
        break;
    case 5:
        if (FADE_IsActive() == 0) *state = 6;
        break;
    case 6:
        return 1;
    }
    IRC_COMPATIBLE_MENU_UpdateScene((unsigned char *)p);
    return 0;
}

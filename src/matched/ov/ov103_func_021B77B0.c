/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_ProcMain
 * address: 0x021B77B0
 * packet: pkt_ov103_021B77B0
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 7FF0 tail-forwards to u32-returning 0201C4E4; caller tests live r0.
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   IRC_COMPATIBLE_TOUCH_TEST_UpdateTextQueue 0x021B7FF0 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_UpdateWindow 0x021B8100 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_UpdateScene 0x021B7918 thumb ov103
 *   COMPATIBLE_IRC_SYS_UpdateValueSync 0x021B63D0 thumb ov101
 *   IRC_APPBAR_Update 0x021B71E4 thumb ov101
 */
#include "../include/Obj10240.h"
#include "../include/Obj22175.h"
typedef unsigned int u32;
typedef unsigned char u8;
extern void FADE_Start(u32, int, int, int);
extern int FADE_IsActive(void);
extern u32 IRC_COMPATIBLE_TOUCH_TEST_UpdateTextQueue(u8 *);
extern int IRC_COMPATIBLE_TOUCH_TEST_UpdateWindow(u8 *p, u8 *q);
extern void IRC_COMPATIBLE_TOUCH_TEST_UpdateScene(u8 *);
struct Obj;
extern int COMPATIBLE_IRC_SYS_UpdateValueSync(struct Obj *p);
extern void IRC_APPBAR_Update(int);
int IRC_COMPATIBLE_TOUCH_TEST_ProcMain(void *unused, u32 *state, int unused2, char *p)
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
        if (FADE_IsActive() == 0) *state = 3;
        break;
    case 3:
        (*(void (**)(char *, char *))(p + 0x728))(p, p + 0x72c);
        if (((struct Obj10240 *)p)->f730 != 0) *state = 4;
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
    if (IRC_COMPATIBLE_TOUCH_TEST_UpdateTextQueue((u8 *)(p + 0x174)) != 0) {
        IRC_COMPATIBLE_TOUCH_TEST_UpdateWindow((u8 *)(p + 0x184), (u8 *)(p + 0x174));
        IRC_COMPATIBLE_TOUCH_TEST_UpdateWindow((u8 *)(p + 0x748), (u8 *)(p + 0x174));
    }
    IRC_COMPATIBLE_TOUCH_TEST_UpdateScene((u8 *)p);
    COMPATIBLE_IRC_SYS_UpdateValueSync(((struct Obj22175 *)(*(u8 * *)&((struct Obj10240 *)p)->fB0C))->f4);
    IRC_APPBAR_Update(((struct Obj10240 *)p)->fA38);
    return 0;
}

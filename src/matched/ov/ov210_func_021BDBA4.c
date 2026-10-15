/*
 * function: ZKNSEARCH_MAIN_UpdateListPage4
 * address:  0x021BDBA4
 * packet:   pkt_ov210_021BDBA4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FRAME_LIST_Update  0x021B7AB0  thumb  ov067
 *   func_020355C4  0x020355C4  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   ZKNSEARCH_MAIN_ToggleEntry3  0x021BE22C  thumb  ov210
 *   ZKNSEARCH_MAIN_UpdateCursorActors  0x021BF728  thumb  ov210
 *   ZKNSEARCH_MAIN_SetActorAnimAuto  0x021BEDB8  thumb  ov210
 *   ZKNSEARCH_MAIN_EnterMessageState  0x021BE2F4  thumb  ov210
 *   ZKNSEARCH_MAIN_HideColumnActors  0x021BF81C  thumb  ov210
 *   ZKNSEARCH_MAIN_PlaceScrollActor  0x021BFABC  thumb  ov210
 *   ZKNSEARCH_MAIN_PollListInput  0x021C014C  thumb  ov210
 *   ZKNSEARCH_MAIN_ClearEntry4  0x021BE278  thumb  ov210
 *   ZKNSEARCH_MAIN_UpdateScrollBarActor  0x021BF6E0  thumb  ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00085.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
struct S;
extern int FRAME_LIST_Update(struct S *p);
extern u8 func_020355C4(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void ZKNSEARCH_MAIN_ToggleEntry3(u8 *p, int index);
extern void ZKNSEARCH_MAIN_UpdateCursorActors(u8 *p, int a);
extern void ZKNSEARCH_MAIN_SetActorAnimAuto(int p, int i, int v);
extern u32 ZKNSEARCH_MAIN_EnterMessageState(u8 *p, u32 a, u32 b, u32 c);
extern void ZKNSEARCH_MAIN_HideColumnActors(char *p);
extern void ZKNSEARCH_MAIN_PlaceScrollActor(char *ctx, int slot, int index);
extern int ZKNSEARCH_MAIN_PollListInput(char *ctx);
extern void ZKNSEARCH_MAIN_ClearEntry4(u8 *p);
extern void ZKNSEARCH_MAIN_UpdateScrollBarActor(char *p);

u32 ZKNSEARCH_MAIN_UpdateListPage4(u8 *p)
{
    u32 ret = 19;
    u32 r5 = FRAME_LIST_Update((struct S *)(*(u32 *)&((struct Obj00085 *)p)->f1E0));

    switch (r5) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        if (func_020355C4() == 0) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZKNSEARCH_MAIN_ToggleEntry3(p, r5);
        }
        break;
    case (u32)-12:
        break;
    case (u32)-11:
    case (u32)-10:
    case (u32)-9:
    case (u32)-8:
        ZKNSEARCH_MAIN_UpdateCursorActors(p, 0);
        break;
    case (u32)-7:
        ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 6, 12);
        p[0x2c1] = 6;
        ((struct Obj00085 *)p)->f14 = 0;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-6:
        ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 5, 13);
        p[0x2c1] = 5;
        ((struct Obj00085 *)p)->f14 = 0;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-5:
        ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 6, 12);
        return ZKNSEARCH_MAIN_EnterMessageState(p, 1, 6, 19);
    case (u32)-4:
        ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 5, 13);
        return ZKNSEARCH_MAIN_EnterMessageState(p, 1, 5, 19);
    case (u32)-3:
    case (u32)-2:
        ZKNSEARCH_MAIN_HideColumnActors((char *)p);
        ZKNSEARCH_MAIN_PlaceScrollActor((char *)p, 0, (*(u8 **)(*(u8 * *)&((struct Obj00085 *)p)->f0 + 8))[5]);
        p[0x2c1] = 0x39;
        ((struct Obj00085 *)p)->f14 = 1;
        ((struct Obj00085 *)p)->f18 = ret;
        ret = 0x18;
        break;
    case (u32)-1:
        r5 = ZKNSEARCH_MAIN_PollListInput((char *)p);
        switch (r5) {
        case 0:
            GFL_USE_PlaySeDefaultVolume(0x551);
            ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 2, 9);
            return ZKNSEARCH_MAIN_EnterMessageState(p, 1, 2, 0x14);
        case 8:
            GFL_USE_PlaySeDefaultVolume(0x551);
            ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 2, 9);
            return ZKNSEARCH_MAIN_EnterMessageState(p, 1, 2, 0x14);
        case 9:
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZKNSEARCH_MAIN_ClearEntry4(p);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZKNSEARCH_MAIN_UpdateCursorActors(p, 0);
            ZKNSEARCH_MAIN_ToggleEntry3(p, r5 - 1);
            break;
        }
        break;
    }
    ZKNSEARCH_MAIN_UpdateScrollBarActor((char *)p);
    return ret;
}

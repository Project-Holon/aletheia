/*
 * function: ZKNSEARCH_MAIN_UpdateListPage1
 * address:  0x021BD568
 * packet:   pkt_ov210_021BD568
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FRAME_LIST_Update  0x021B7AB0  thumb  ov067
 *   ZKNSEARCH_MAIN_PollListInput  0x021C014C  thumb  ov210
 *   func_020355C4  0x020355C4  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   ZKNSEARCH_MAIN_SelectEntry1  0x021BE0E4  thumb  ov210
 *   ZKNSEARCH_MAIN_SetActorAnimAuto  0x021BEDB8  thumb  ov210
 *   ZKNSEARCH_MAIN_EnterMessageState  0x021BE2F4  thumb  ov210
 *   ZKNSEARCH_MAIN_ClearEntry1  0x021BE110  thumb  ov210
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
extern int ZKNSEARCH_MAIN_PollListInput(char *ctx);
extern u8 func_020355C4(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void ZKNSEARCH_MAIN_SelectEntry1(u8 *p, u32 v);
extern void ZKNSEARCH_MAIN_SetActorAnimAuto(int p, int i, int v);
extern u32 ZKNSEARCH_MAIN_EnterMessageState(u8 *p, u32 a, u32 b, u32 c);
extern void ZKNSEARCH_MAIN_ClearEntry1(u8 *p);

u32 ZKNSEARCH_MAIN_UpdateListPage1(u8 *p)
{
    int r5 = FRAME_LIST_Update((struct S *)(*(u32 *)&((struct Obj00085 *)p)->f1E0));

    if (r5 != -1) {
        switch (r5) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            if (func_020355C4() == 0) {
                GFL_USE_PlaySeDefaultVolume(0x54c);
                ZKNSEARCH_MAIN_SelectEntry1(p, r5);
            }
            break;
        }
    } else {
    r5 = ZKNSEARCH_MAIN_PollListInput((char *)p);
    switch (r5) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x551);
        ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 2, 9);
        return ZKNSEARCH_MAIN_EnterMessageState(p, 1, 2, 11);
    case 8:
        GFL_USE_PlaySeDefaultVolume(0x551);
        ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 2, 9);
        return ZKNSEARCH_MAIN_EnterMessageState(p, 1, 2, 11);
    case 9:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        ZKNSEARCH_MAIN_ClearEntry1(p);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        ZKNSEARCH_MAIN_SelectEntry1(p, r5 - 1);
        break;
    }
    }
    return 10;
}

/*
 * function: ZKNSEARCH_MAIN_UpdateSearchResult
 * address:  0x021BD19C
 * packet:   pkt_ov210_021BD19C
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_UpdateScrollMove  0x021BCE58  thumb  ov210
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   ZKNSEARCH_MAIN_PollMenuInput  0x021BFF68  thumb  ov210
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   ZKNSEARCH_MAIN_EnterListState  0x021BE314  thumb  ov210
 *   ZKNSEARCH_MAIN_EnterMessageState  0x021BE2F4  thumb  ov210
 *   ZKNSEARCH_MAIN_ToggleSaveFlag  0x021BE324  thumb  ov210
 *   ZKNSEARCH_MAIN_SetActorAnimAuto  0x021BEDB8  thumb  ov210
 *   ZKNSEARCH_MAIN_DenormalizeRecordByte  0x021BCF38  thumb  ov210
 *   BLINK_PALANM_Update  0x0202EA40  thumb
 * 2026-10-02: bytes identical. Only blocker: ZKNSEARCH_MAIN_EnterListState has no witness yet.
 * Lane 07 filed src/matched/ov/ov210_func_021BE314.c (EXACT); after its shard
 * exists, re-verify; this should then be EXACT and move to src/matched/ov/.
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00085.h"
#include "../include/Obj25602.h"
#include "../include/Obj25603.h"
#include "../include/Obj25604.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern int ZKNSEARCH_MAIN_UpdateScrollMove(char *p);
struct Row;
extern u32 PALANM_GetFadeRequestBits(const char *ptr);
extern u32 ZKNSEARCH_MAIN_PollMenuInput(int p);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern u32 ZKNSEARCH_MAIN_EnterListState(u8 *p, u32 a);
extern u32 ZKNSEARCH_MAIN_EnterMessageState(u8 *p, u32 a, u32 b, u32 c);
extern void ZKNSEARCH_MAIN_ToggleSaveFlag(u8 *p);
extern void ZKNSEARCH_MAIN_SetActorAnimAuto(int p, int i, int v);
extern void ZKNSEARCH_MAIN_DenormalizeRecordByte(u8 *p);
extern s32 BLINK_PALANM_Update(struct Row *p);

u32 ZKNSEARCH_MAIN_UpdateSearchResult(u8 *p)
{
    if (ZKNSEARCH_MAIN_UpdateScrollMove((char *)p) == 1 || PALANM_GetFadeRequestBits((const char *)(*(u32 *)&((struct Obj00085 *)p)->fC)) != 0) {
        return 4;
    }
    switch (ZKNSEARCH_MAIN_PollMenuInput((int)p)) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ZKNSEARCH_MAIN_EnterMessageState(p, 0, 0, ZKNSEARCH_MAIN_EnterListState(p, 9));
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ZKNSEARCH_MAIN_EnterMessageState(p, 0, 1, ZKNSEARCH_MAIN_EnterListState(p, 12));
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ZKNSEARCH_MAIN_EnterMessageState(p, 0, 2, ZKNSEARCH_MAIN_EnterListState(p, 15));
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ZKNSEARCH_MAIN_EnterMessageState(p, 0, 3, ZKNSEARCH_MAIN_EnterListState(p, 18));
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ZKNSEARCH_MAIN_EnterMessageState(p, 0, 4, ZKNSEARCH_MAIN_EnterListState(p, 21));
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ZKNSEARCH_MAIN_EnterMessageState(p, 0, 5, 7);
    case 6:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return ZKNSEARCH_MAIN_EnterMessageState(p, 0, 6, 6);
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x646);
        ZKNSEARCH_MAIN_ToggleSaveFlag(p);
        break;
    case 8:
        GFL_USE_PlaySeDefaultVolume(0x556);
        ((struct Obj25602 *)(*(u8 * *)&((struct Obj00085 *)p)->f0))->fC = 2;
        ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 3, 8);
        return ZKNSEARCH_MAIN_EnterMessageState(p, 1, 3, 0x1a);
    case 9:
        GFL_USE_PlaySeDefaultVolume(0x551);
        ZKNSEARCH_MAIN_DenormalizeRecordByte(p);
        ((struct Obj25603 *)(*(u8 * *)&((struct Obj00085 *)p)->f0))->fC = 1;
        ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 2, 9);
        return ZKNSEARCH_MAIN_EnterMessageState(p, 1, 2, 0x1a);
    case (u32)-4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case (u32)-3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case (u32)-2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        ZKNSEARCH_MAIN_DenormalizeRecordByte(p);
        ((struct Obj25604 *)(*(u8 * *)&((struct Obj00085 *)p)->f0))->fC = 1;
        ZKNSEARCH_MAIN_SetActorAnimAuto((int)p, 2, 9);
        return ZKNSEARCH_MAIN_EnterMessageState(p, 1, 2, 0x1a);
    }
    BLINK_PALANM_Update((struct Row *)(((struct Obj00085 *)p)->f2B4));
    return 4;
}

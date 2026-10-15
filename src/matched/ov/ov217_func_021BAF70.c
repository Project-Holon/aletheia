/*
 * function: RESEARCH_LIST_HandleSelectInput
 * address: 0x021BAF70
 * packet: pkt_ov217_021BAF70
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   RESEARCH_LIST_IncKeyRepeatTimer 0x021BC600 thumb ov217
 *   RESEARCH_LIST_ClearKeyRepeatTimer 0x021BC608 thumb ov217
 *   RESEARCH_LIST_GetInputFlag 0x021BC6D0 thumb ov217
 *   RESEARCH_LIST_StartEntryPaletteAnime 0x021BBAD0 thumb ov217
 *   RESEARCH_LIST_SetEntryHandled 0x021BB934 thumb ov217
 *   RESEARCH_LIST_SetCommandReady 0x021BB91C thumb ov217
 *   RESEARCH_LIST_PushCommand 0x021BB910 thumb ov217
 *   RESEARCH_LIST_GetKeyRepeatTimer 0x021BC5FC thumb ov217
 *   RESEARCH_LIST_HideCursor 0x021BBDAC thumb ov217
 *   RESEARCH_LIST_AdvanceEndIndex 0x021BBD40 thumb ov217
 *   RESEARCH_LIST_GetEntryCount 0x021BC6DC thumb ov217
 *   RESEARCH_LIST_StartListPaletteAnime 0x021BC580 thumb ov217
 *   RESEARCH_LIST_SetSelectedIndex 0x021BC6EC thumb ov217
 *   RESEARCH_LIST_IsValidIndex 0x021BC6F4 thumb ov217
 *   RESEARCH_LIST_SelectEntry 0x021BBAA4 thumb ov217
 *   RESEARCH_LIST_PrintCurrentEntry 0x021BC06C thumb ov217
 *   RESEARCH_COMMON_GetTouchRects 0x021C09B8 thumb ov217
 *   RESEARCH_LIST_NeedsScrollbar 0x021BC428 thumb ov217
 *   RESEARCH_LIST_HideEntryLabels 0x021BC0E8 thumb ov217
 *   KEY_GetCont 0x0203630C arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj00025.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_HitTrg(const void *p);
extern int TOUCHPANEL_HitCont(const void *p);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void *RESEARCH_COMMON_GetTouchRects(void *p);
extern void RESEARCH_LIST_IncKeyRepeatTimer(void *p);
extern void RESEARCH_LIST_ClearKeyRepeatTimer(void *p);
extern u32 RESEARCH_LIST_GetInputFlag(void *p);
extern u32 RESEARCH_LIST_GetEntryCount(void *p);
extern void RESEARCH_LIST_StartEntryPaletteAnime(u32 a0);
extern void RESEARCH_LIST_SetEntryHandled(u8 *a0, u32 a1);
extern void RESEARCH_LIST_SetCommandReady(void *p);
extern void RESEARCH_LIST_PushCommand(u8 *a0, u32 a1);
extern u32 RESEARCH_LIST_GetKeyRepeatTimer(void *p);
extern void RESEARCH_LIST_HideCursor(u8 *p);
extern void RESEARCH_LIST_AdvanceEndIndex(u8 *p, int a);
extern void RESEARCH_LIST_StartListPaletteAnime(char *p, int i);
extern void RESEARCH_LIST_SetSelectedIndex(void *p, u8 v);
extern u32 RESEARCH_LIST_IsValidIndex(u32 a0, u32 a1);
extern u32 RESEARCH_LIST_SelectEntry(u32 a0, u8 a1);
extern int RESEARCH_LIST_PrintCurrentEntry(char *p);
extern int RESEARCH_LIST_NeedsScrollbar(void *p);
extern u32 RESEARCH_LIST_HideEntryLabels(u32 a0);

void RESEARCH_LIST_HandleSelectInput(char *p)
{
    u32 trg = KEY_GetCont();
    u32 keys = KEY_GetTrg();
    int sel = TOUCHPANEL_HitTrg(p + 0x64);
    int flag;
    u32 a;
    u32 b;
    flag = TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(*(void **)p));
    TOUCHPANEL_GetPointCont(&a, &b);
    if (trg & 0xc0) {
        RESEARCH_LIST_IncKeyRepeatTimer(p);
    } else {
        RESEARCH_LIST_ClearKeyRepeatTimer(p);
    }
    if (RESEARCH_LIST_GetInputFlag(p) != 0 || flag == 0) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_LIST_StartEntryPaletteAnime((u32)p);
        RESEARCH_LIST_SetEntryHandled((u8 *)p, (int)1);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand((u8 *)p, (int)6);
        return;
    }
    if ((keys & 0x40) || ((trg & 0x40) && ((struct Obj00025 *)p)->f32 != 0 && RESEARCH_LIST_GetKeyRepeatTimer(p) > 10)) {
        RESEARCH_LIST_HideCursor((u8 *)p);
        RESEARCH_LIST_AdvanceEndIndex((u8 *)p, -1);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand((u8 *)p, (int)3);
        RESEARCH_LIST_PushCommand((u8 *)p, (int)2);
        return;
    }
    if ((keys & 0x80) || ((trg & 0x80) && ((struct Obj00025 *)p)->f32 < (int)RESEARCH_LIST_GetEntryCount(p) - 1 && RESEARCH_LIST_GetKeyRepeatTimer(p) > 10)) {
        RESEARCH_LIST_HideCursor((u8 *)p);
        RESEARCH_LIST_AdvanceEndIndex((u8 *)p, 1);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand((u8 *)p, (int)3);
        RESEARCH_LIST_PushCommand((u8 *)p, (int)2);
        return;
    }
    if (keys & 1) {
        RESEARCH_LIST_StartListPaletteAnime(p, 2);
        RESEARCH_LIST_SetSelectedIndex(p, ((struct Obj00025 *)p)->f32);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        RESEARCH_LIST_PushCommand((u8 *)p, (int)9);
        RESEARCH_LIST_SetCommandReady(p);
        return;
    }
    if (sel >= 0 && sel <= 9) {
        if (b >= 0x18 && b <= 0xa8 && RESEARCH_LIST_IsValidIndex((u32)p, (u8)sel) == 1) {
            RESEARCH_LIST_SelectEntry((u32)p, (u8)sel);
            RESEARCH_LIST_SetSelectedIndex(p, ((struct Obj00025 *)p)->f32);
            RESEARCH_LIST_StartListPaletteAnime(p, 2);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            RESEARCH_LIST_PrintCurrentEntry(p);
            RESEARCH_LIST_SetCommandReady(p);
            RESEARCH_LIST_PushCommand((u8 *)p, (int)7);
        }
        return;
    }
    if (keys & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_LIST_StartEntryPaletteAnime((u32)p);
        RESEARCH_LIST_SetEntryHandled((u8 *)p, (int)0);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand((u8 *)p, (int)6);
        return;
    }
    if (TOUCHPANEL_HitCont(p + 0x90) == 0 || TOUCHPANEL_HitTrg(p + 0x90) == 0) {
        if (RESEARCH_LIST_NeedsScrollbar(p) == 1) {
            RESEARCH_LIST_HideCursor((u8 *)p);
            RESEARCH_LIST_HideEntryLabels((u32)p);
            RESEARCH_LIST_SetCommandReady(p);
            RESEARCH_LIST_PushCommand((u8 *)p, (int)4);
            RESEARCH_LIST_PushCommand((u8 *)p, (int)1);
        }
    }
}

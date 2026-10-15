/*
 * function: RESEARCH_GRAPH_HandleInputAlt
 * address:  0x021BDC18
 * packet:   pkt_ov217_021BDC18
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetCont  0x0203630C  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   RESEARCH_COMMON_GetTouchRects  0x021C09B8  thumb  ov217
 *   RESEARCH_GRAPH_SetStateChanged  0x021BE448  thumb  ov217
 *   RESEARCH_GRAPH_SetEntryHandled  0x021BE454  thumb  ov217
 *   RESEARCH_GRAPH_PushCommand  0x021BE498  thumb  ov217
 *   RESEARCH_GRAPH_SelectPrev  0x021BE4E8  thumb  ov217
 *   RESEARCH_GRAPH_SelectNext  0x021BE580  thumb  ov217
 *   RESEARCH_GRAPH_SelectDirect  0x021BE614  thumb  ov217
 *   RESEARCH_GRAPH_MoveGroupBackward  0x021BE678  thumb  ov217
 *   RESEARCH_GRAPH_MoveGroupForward  0x021BE704  thumb  ov217
 *   RESEARCH_GRAPH_MoveEntryForward  0x021BE790  thumb  ov217
 *   RESEARCH_GRAPH_MoveEntryBackward  0x021BE7B4  thumb  ov217
 *   RESEARCH_GRAPH_ToggleEntry  0x021BE808  thumb  ov217
 *   RESEARCH_GRAPH_SetHighlightSelected  0x021BEB40  thumb  ov217
 *   RESEARCH_GRAPH_StartPaletteAnime  0x021BEC00  thumb  ov217
 *   RESEARCH_GRAPH_GetInputFlag  0x021BF758  thumb  ov217
 *   RESEARCH_GRAPH_GetGroupValue  0x021BF810  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern unsigned int KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_HitTrg(const void *rect);
extern void *RESEARCH_COMMON_GetTouchRects(void *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void RESEARCH_GRAPH_SetStateChanged(void *p);
extern void RESEARCH_GRAPH_SelectPrev(u8 *p);
extern void RESEARCH_GRAPH_SelectNext(u8 *p);
extern void RESEARCH_GRAPH_SetEntryHandled(u8 *a0, u32 a1);
extern void RESEARCH_GRAPH_PushCommand(u8 *a0, u32 a1);
extern u32 RESEARCH_GRAPH_SelectDirect(u32 a0, u32 a1);
extern void RESEARCH_GRAPH_MoveGroupBackward(char *p);
extern void RESEARCH_GRAPH_MoveGroupForward(char *p);
extern u32 RESEARCH_GRAPH_MoveEntryForward(u32 a0);
extern u32 RESEARCH_GRAPH_MoveEntryBackward(u32 a0);
extern void RESEARCH_GRAPH_ToggleEntry(char *p);
extern u32 RESEARCH_GRAPH_SetHighlightSelected(u32 a0);
extern void RESEARCH_GRAPH_StartPaletteAnime(u32 *p);
extern u32 RESEARCH_GRAPH_GetInputFlag(void *p);
extern u32 RESEARCH_GRAPH_GetGroupValue(void *p);

void RESEARCH_GRAPH_HandleInputAlt(u8 *p)
{
    u32 keys;
    int hit;
    int sub;

    KEY_GetCont();
    keys = KEY_GetTrg();
    hit = TOUCHPANEL_HitTrg(p + 0x2FE);
    sub = TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(((struct Obj00021 *)p)->f0));
    if (*(int *)&((struct Obj00021 *)p)->f3C8 != 0 && ((struct Obj00021 *)p)->f3D8 != 0 && *(int *)&((struct Obj00021 *)p)->f3D4 != 0) {
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 9);
        RESEARCH_GRAPH_PushCommand(p, 6);
        RESEARCH_GRAPH_PushCommand(p, 7);
        RESEARCH_GRAPH_PushCommand(p, 5);
        RESEARCH_GRAPH_PushCommand(p, 3);
        return;
    }
    if (RESEARCH_GRAPH_GetInputFlag(p) != 0 || sub == 0) {
        RESEARCH_GRAPH_SetEntryHandled(p, 1);
        RESEARCH_GRAPH_StartPaletteAnime((u32 *)p);
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 11);
        RESEARCH_GRAPH_PushCommand(p, 10);
        RESEARCH_GRAPH_PushCommand(p, 12);
        return;
    }
    if (keys & 0x40) {
        RESEARCH_GRAPH_SelectPrev(p);
    } else if (keys & 0x80) {
        RESEARCH_GRAPH_SelectNext(p);
    } else if (hit == 6 && *(int *)&((struct Obj00021 *)p)->f3C8 == 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0) {
        ((struct Obj00021 *)p)->f3CC = 1;
        RESEARCH_GRAPH_SetHighlightSelected((u32)p);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 4);
        RESEARCH_GRAPH_PushCommand(p, 6);
        RESEARCH_GRAPH_PushCommand(p, 7);
        RESEARCH_GRAPH_PushCommand(p, 5);
        RESEARCH_GRAPH_PushCommand(p, 2);
    } else if (hit == 7) {
        if (*(int *)&((struct Obj00021 *)p)->f3C8 == 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0) {
            ((struct Obj00021 *)p)->f3CC = 1;
            RESEARCH_GRAPH_SetHighlightSelected((u32)p);
            RESEARCH_GRAPH_SetStateChanged(p);
            RESEARCH_GRAPH_PushCommand(p, 4);
            RESEARCH_GRAPH_PushCommand(p, 6);
            RESEARCH_GRAPH_PushCommand(p, 7);
            RESEARCH_GRAPH_PushCommand(p, 5);
            RESEARCH_GRAPH_PushCommand(p, 2);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x557);
        }
    } else if (hit == 2) {
        if (*(int *)&((struct Obj00021 *)p)->f3C8 == 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0) {
            ((struct Obj00021 *)p)->f3CC = 1;
            RESEARCH_GRAPH_SetHighlightSelected((u32)p);
            RESEARCH_GRAPH_SetStateChanged(p);
            RESEARCH_GRAPH_PushCommand(p, 4);
            RESEARCH_GRAPH_PushCommand(p, 6);
            RESEARCH_GRAPH_PushCommand(p, 7);
            RESEARCH_GRAPH_PushCommand(p, 5);
            RESEARCH_GRAPH_PushCommand(p, 2);
        } else {
            RESEARCH_GRAPH_SelectDirect((u32)p, 0);
        }
    } else if (*(int *)&((struct Obj00021 *)p)->f3C8 != 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0 && hit == 3) {
        RESEARCH_GRAPH_SelectDirect((u32)p, 1);
    } else if (*(int *)&((struct Obj00021 *)p)->f3C8 != 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0 && hit == 4) {
        RESEARCH_GRAPH_SelectDirect((u32)p, 2);
    } else if (hit == 5) {
        RESEARCH_GRAPH_SelectDirect((u32)p, 3);
    } else if ((keys & 0x20) || hit == 0) {
        switch (*(int *)&((struct Obj00021 *)p)->f34) {
        case 0: RESEARCH_GRAPH_MoveGroupForward((char *)p); break;
        case 1: RESEARCH_GRAPH_MoveEntryBackward((u32)p); break;
        case 3: RESEARCH_GRAPH_ToggleEntry((char *)p); break;
        }
    } else if ((keys & 0x10) || hit == 1) {
        switch (*(int *)&((struct Obj00021 *)p)->f34) {
        case 0: RESEARCH_GRAPH_MoveGroupBackward((char *)p); break;
        case 1: RESEARCH_GRAPH_MoveEntryForward((u32)p); break;
        case 3: RESEARCH_GRAPH_ToggleEntry((char *)p); break;
        }
    } else if ((keys & 1) && *(int *)&((struct Obj00021 *)p)->f3C8 == 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0
               && (*(int *)&((struct Obj00021 *)p)->f34 == 0 || *(int *)&((struct Obj00021 *)p)->f34 == 4)) {
        ((struct Obj00021 *)p)->f3CC = 0;
        RESEARCH_GRAPH_SetHighlightSelected((u32)p);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 4);
        RESEARCH_GRAPH_PushCommand(p, 6);
        RESEARCH_GRAPH_PushCommand(p, 7);
        RESEARCH_GRAPH_PushCommand(p, 5);
        RESEARCH_GRAPH_PushCommand(p, 3);
    } else if (keys & 2) {
        RESEARCH_GRAPH_SetEntryHandled(p, 0);
        RESEARCH_GRAPH_StartPaletteAnime((u32 *)p);
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_GRAPH_SetStateChanged(p);
        RESEARCH_GRAPH_PushCommand(p, 11);
        RESEARCH_GRAPH_PushCommand(p, 10);
        RESEARCH_GRAPH_PushCommand(p, 12);
    }
}

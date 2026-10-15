/*
 * function: RESEARCH_LIST_HandleCancel
 * address: 0x021BB37C
 * packet: pkt_ov217_021BB37C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   RESEARCH_LIST_SetCommandReady 0x021BB91C thumb ov217
 *   RESEARCH_LIST_PushCommand 0x021BB910 thumb ov217
 *   RESEARCH_LIST_SetSelectionMode 0x021BBA00 thumb ov217
 *   RESEARCH_LIST_StopListPaletteAnime 0x021BC5A8 thumb ov217
 *   RESEARCH_LIST_StartListPaletteAnime 0x021BC580 thumb ov217
 *   RESEARCH_LIST_SetEntryHandled 0x021BB934 thumb ov217
 *   RESEARCH_LIST_GetInputFlag 0x021BC6D0 thumb ov217
 *   RESEARCH_LIST_SelectPrevious 0x021BB9A0 thumb ov217
 *   RESEARCH_LIST_SelectNext 0x021BB9D0 thumb ov217
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj02928.h"
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_HitTrg(const void *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void RESEARCH_LIST_SetCommandReady(void *p);
extern void RESEARCH_LIST_PushCommand(unsigned char *a0, u32 a1);
extern u32 RESEARCH_LIST_SetSelectionMode(u32 a0, u32 a1);
typedef unsigned char  u8;
extern void RESEARCH_LIST_StopListPaletteAnime(u8 *a0, int a1);
extern void RESEARCH_LIST_StartListPaletteAnime(char *p, int i);
extern void RESEARCH_LIST_SetEntryHandled(u8 *a0, u32 a1);
extern u32 RESEARCH_LIST_GetInputFlag(void *p);
extern u32 RESEARCH_LIST_SelectPrevious(u32 a0);
extern u32 RESEARCH_LIST_SelectNext(u32 a0);

void RESEARCH_LIST_HandleCancel(char *p)
{
    u32 keys = KEY_GetTrg();
    int st = TOUCHPANEL_HitTrg(p + 0x58);
    if (keys & 0x40) {
        RESEARCH_LIST_SelectPrevious((u32)p);
    }
    if (keys & 0x80) {
        RESEARCH_LIST_SelectNext((u32)p);
    }
    if (keys & 1) {
        RESEARCH_LIST_StopListPaletteAnime((u8 *)p, 3);
        RESEARCH_LIST_StartListPaletteAnime(p, 5);
        switch (*(int *)&((struct Obj02928 *)p)->f2C) {
        case 0:
            RESEARCH_LIST_SetEntryHandled((u8 *)p, 0);
            RESEARCH_LIST_SetCommandReady(p);
            RESEARCH_LIST_PushCommand((unsigned char *)p, 12);
            break;
        case 1:
            GFL_USE_PlaySeDefaultVolume(0x551);
            RESEARCH_LIST_SetCommandReady(p);
            RESEARCH_LIST_PushCommand((unsigned char *)p, 11);
            RESEARCH_LIST_PushCommand((unsigned char *)p, 2);
            break;
        }
        return;
    }
    if (st == 0) {
        RESEARCH_LIST_SetSelectionMode((u32)p, 0);
        RESEARCH_LIST_StopListPaletteAnime((u8 *)p, 3);
        RESEARCH_LIST_StartListPaletteAnime(p, 5);
        RESEARCH_LIST_SetEntryHandled((u8 *)p, 1);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand((unsigned char *)p, 12);
        return;
    }
    if (RESEARCH_LIST_GetInputFlag(p) != 0 || (keys & 2) || st == 1) {
        RESEARCH_LIST_SetSelectionMode((u32)p, 1);
        RESEARCH_LIST_StopListPaletteAnime((u8 *)p, 3);
        RESEARCH_LIST_StartListPaletteAnime(p, 5);
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand((unsigned char *)p, 11);
        RESEARCH_LIST_PushCommand((unsigned char *)p, 2);
    }
}

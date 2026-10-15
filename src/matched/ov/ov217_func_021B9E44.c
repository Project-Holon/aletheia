/*
 * function: RESEARCH_TOP_HandleListInputAlt
 * address: 0x021B9E44
 * packet: pkt_ov217_021B9E44
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: 02035C08 result is compared in the original; matched 02025EA4/02027E3C callers also declare its int return despite the forwarding body's void spelling.
 * The key-1 sound uses pool 021BA070 (1356), unlike the early abort's 1361.
 * Original passes p to 020362DC although the own matched body ignores entry r0.
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   RESEARCH_COMMON_GetTouchRects 0x021C09B8 thumb ov217
 *   RESEARCH_TOP_GetInputFlag 0x021BA4D4 thumb ov217
 *   RESEARCH_TOP_SetEntryHandled 0x021BA1C0 thumb ov217
 *   RESEARCH_TOP_SetMode 0x021BA1CC thumb ov217
 *   RESEARCH_TOP_StartPaletteAnime 0x021BA31C thumb ov217
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   RESEARCH_TOP_SetStateTimer 0x021BA380 thumb ov217
 *   RESEARCH_TOP_SetCommandReady 0x021BA150 thumb ov217
 *   RESEARCH_TOP_PushCommand 0x021BA144 thumb ov217
 *   RESEARCH_TOP_DrawSelector 0x021BA284 thumb ov217
 *   RESEARCH_TOP_StartEntryPaletteAnime 0x021BA3E8 thumb ov217
 *   RESEARCH_TOP_IsSelectionValid 0x021BA3B4 thumb ov217
 *   RESEARCH_TOP_SelectDirect 0x021BA254 thumb ov217
 *   RESEARCH_TOP_StopEntryPaletteAnime 0x021BA40C thumb ov217
 *   RESEARCH_TOP_SelectPrev 0x021BA1F8 thumb ov217
 *   RESEARCH_TOP_SelectNext 0x021BA228 thumb ov217
 */
#include "../include/Obj00511.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_HitTrg(const void *);
extern void * RESEARCH_COMMON_GetTouchRects(void *);
extern u32 RESEARCH_TOP_GetInputFlag(void *);
extern void RESEARCH_TOP_SetEntryHandled(u8 *,u32);
extern void RESEARCH_TOP_SetMode(void *,u32);
extern void RESEARCH_TOP_StartPaletteAnime(u8 *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void RESEARCH_TOP_SetStateTimer(void *,u32);
extern void RESEARCH_TOP_SetCommandReady(void *);
extern void RESEARCH_TOP_PushCommand(u8 *,u32);
extern void RESEARCH_TOP_DrawSelector(int);
extern void RESEARCH_TOP_StartEntryPaletteAnime(char *,int);
extern u32 RESEARCH_TOP_IsSelectionValid(u32,u32);
extern u32 RESEARCH_TOP_SelectDirect(u32,u32);
extern void RESEARCH_TOP_StopEntryPaletteAnime(u8 *,u32);
extern u32 RESEARCH_TOP_SelectPrev(u32);
extern u32 RESEARCH_TOP_SelectNext(u32);
void RESEARCH_TOP_HandleListInputAlt(char *p)
{
    u32 keys=KEY_GetTrg();
    int choice=TOUCHPANEL_HitTrg(p+44);
    int other=TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(((struct Obj00511 *)p)->f0));
    if(RESEARCH_TOP_GetInputFlag(p)!=0 || other==0) {
        RESEARCH_TOP_SetEntryHandled((u8 *)p,1);RESEARCH_TOP_SetMode(p,2);RESEARCH_TOP_StartPaletteAnime((u8 *)p);GFL_USE_PlaySeDefaultVolume(1361);RESEARCH_TOP_SetStateTimer(p,15);RESEARCH_TOP_SetCommandReady(p);RESEARCH_TOP_PushCommand((u8 *)p,3);RESEARCH_TOP_PushCommand((u8 *)p,4);RESEARCH_TOP_PushCommand((u8 *)p,5);return;
    }
    if(keys&64)RESEARCH_TOP_SelectPrev((u32)p);
    if(keys&128)RESEARCH_TOP_SelectNext((u32)p);
    if(keys&1) {
        RESEARCH_TOP_SetEntryHandled((u8 *)p,0);RESEARCH_TOP_StopEntryPaletteAnime((u8 *)p,0);RESEARCH_TOP_StartEntryPaletteAnime(p,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetStateTimer(p,15);RESEARCH_TOP_SetCommandReady(p);RESEARCH_TOP_PushCommand((u8 *)p,3);RESEARCH_TOP_PushCommand((u8 *)p,4);RESEARCH_TOP_PushCommand((u8 *)p,5);
        switch(((struct Obj00511 *)p)->f28) {
        case 0:RESEARCH_TOP_SetMode(p,0);return;
        case 1:RESEARCH_TOP_SetMode(p,1);return;
        default:RESEARCH_TOP_SetMode(p,2);return;
        }
    }
    if(choice==0) {
        if(RESEARCH_TOP_IsSelectionValid((u32)p,0)!=0) {
            RESEARCH_TOP_SetEntryHandled((u8 *)p,1);RESEARCH_TOP_SelectDirect((u32)p,0);RESEARCH_TOP_StopEntryPaletteAnime((u8 *)p,0);RESEARCH_TOP_StartEntryPaletteAnime(p,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetMode(p,0);RESEARCH_TOP_SetStateTimer(p,15);RESEARCH_TOP_SetCommandReady(p);RESEARCH_TOP_PushCommand((u8 *)p,3);RESEARCH_TOP_PushCommand((u8 *)p,4);RESEARCH_TOP_PushCommand((u8 *)p,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    } else if(choice==1) {
        if(RESEARCH_TOP_IsSelectionValid((u32)p,1)!=0) {
            RESEARCH_TOP_SetEntryHandled((u8 *)p,1);RESEARCH_TOP_SelectDirect((u32)p,1);RESEARCH_TOP_StopEntryPaletteAnime((u8 *)p,0);RESEARCH_TOP_StartEntryPaletteAnime(p,2);GFL_USE_PlaySeDefaultVolume(1356);RESEARCH_TOP_SetMode(p,1);RESEARCH_TOP_SetStateTimer(p,15);RESEARCH_TOP_SetCommandReady(p);RESEARCH_TOP_PushCommand((u8 *)p,3);RESEARCH_TOP_PushCommand((u8 *)p,4);RESEARCH_TOP_PushCommand((u8 *)p,5);
        } else GFL_USE_PlaySeDefaultVolume(1367);
    } else if(keys&2) {
        RESEARCH_TOP_StartPaletteAnime((u8 *)p);GFL_USE_PlaySeDefaultVolume(1361);RESEARCH_TOP_SetMode(p,2);RESEARCH_TOP_SetStateTimer(p,15);RESEARCH_TOP_SetCommandReady(p);RESEARCH_TOP_PushCommand((u8 *)p,3);RESEARCH_TOP_PushCommand((u8 *)p,4);RESEARCH_TOP_PushCommand((u8 *)p,5);
    }
}

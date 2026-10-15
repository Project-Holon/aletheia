/*
 * function: POKELIST_ApplySelection
 * address: 0x021B7CC4
 * packet: pkt_ov091_021B7CC4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: final two bytes at 021B817E are alignment padding.
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   FILE_UTIL_Check136C 0x0202136C thumb
 *   func_02009050 0x02009050 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   func_0200902C 0x0200902C thumb
 *   func_020409B4 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 *   POKELIST_EnterMenuPhase 0x021B907C thumb ov091
 *   POKELIST_OpenContextMenu 0x021B8180 thumb ov091
 *   PLIST_MENU_IsSpecialItemKind 0x021BC17C thumb ov091
 *   PLIST_DEMO_CheckItemUsable 0x021BDD78 thumb ov091
 *   PLIST_MENU_StartItemUse 0x021BC350 thumb ov091
 *   PLIST_DEMO_UseItemOnMon 0x021BE2B4 thumb ov091
 *   PLIST_PLATE_SetMon 0x021BB200 thumb ov091
 *   PLIST_PLATE_Redraw 0x021BB2C0 thumb ov091
 *   POKELIST_RemoveBagItem 0x021BA670 thumb ov091
 *   PLIST_DEMO_CanUseGracidea 0x021BDCC0 thumb ov091
 *   PLIST_DEMO_ApplyShayminSkyForm 0x021BDD58 thumb ov091
 *   PLIST_MENU_ShowItemUsedThenContinue 0x021BC30C thumb ov091
 *   POKELIST_CheckEvolution 0x021B9BF4 thumb ov091
 *   POKELIST_ShowMessage 0x021B9788 thumb ov091
 *   POKELIST_SetHeldItem 0x021BA624 thumb ov091
 *   PLIST_MESSAGE_CreateWordSet 0x021BB97C thumb ov091
 *   PLIST_MESSAGE_SetWordSetPokemon 0x021BB99C thumb ov091
 *   PLIST_MESSAGE_SetWordSetItem 0x021BB9AC thumb ov091
 *   PLIST_MESSAGE_SetWordSetHeldItem 0x021BB9BC thumb ov091
 *   PLIST_MESSAGE_SetWordSetMove 0x021BB9CC thumb ov091
 *   PLIST_MESSAGE_DestroyWordSet 0x021BB98C thumb ov091
 *   PLIST_MENU_ApplyArceusPlateForm 0x021BC24C thumb ov091
 *   PLIST_MENU_ApplyGenesectDriveForm 0x021BC288 thumb ov091
 *   PLIST_DEMO_CheckGiratinaToOrigin 0x021BDBF8 thumb ov091
 *   PLIST_DEMO_ApplyGiratinaOriginForm 0x021BDC3C thumb ov091
 *   POKELIST_GetMoveLearnStatus 0x021B9AC8 thumb ov091
 *   POKELIST_FindMoveSlot 0x021BA5B4 thumb ov091
 *   POKELIST_ApplyItemEffect 0x021BA60C thumb ov091
 *   POKELIST_EndMessageToExit 0x021B9E3C thumb ov091
 *   POKELIST_EndMessageToEvolve 0x021BA4E4 thumb ov091
 *   POKELIST_OpenTakeItemMenu 0x021BA098 thumb ov091
 *   POKELIST_OpenLearnMoveMenu 0x021B9EB0 thumb ov091
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj00009.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sub02008F80Obj;
extern void func_020409B4(u32 index);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern u32 FILE_UTIL_Check136C(u16);
extern struct Sub02008F80Obj *func_02009050(struct Sub02008F80Obj *arr, u32 unused, int i, u32 heap);
extern void POKE_TOOL_SetPartyValue(void *,u32,u32);
extern u32 func_020307B0(void *p);
extern void func_0200902C(struct Sub02008F80Obj *arr, u32 unused, int i);
extern void POKELIST_EnterMenuPhase(u8 *);
extern void POKELIST_OpenContextMenu(u8 *);
extern int PLIST_MENU_IsSpecialItemKind(unsigned short *p, int id);
extern int PLIST_DEMO_CheckItemUsable(void *a, u32 id, int slot, u32 heap);
extern int PLIST_MENU_StartItemUse(u8 *,int);
extern int PLIST_DEMO_UseItemOnMon(void *mon, u16 item, u16 moveSlot, u16 arg, int heap);
extern void PLIST_PLATE_SetMon(u8 *a, u8 *s, int p, int q);
extern void PLIST_PLATE_Redraw(u8 *a, u8 *s);
extern u32 POKELIST_RemoveBagItem(u8 *p, u16 id);
extern int PLIST_DEMO_CanUseGracidea(char *p, u32 a1);
extern void PLIST_DEMO_ApplyShayminSkyForm(u32 p, void *m);
extern void PLIST_MENU_ShowItemUsedThenContinue(int p);
extern u32 POKELIST_CheckEvolution(u8 *p, void *mon, u32 param);
extern void POKELIST_ShowMessage(u8 *,int,int,int);
extern void POKELIST_SetHeldItem(u8 *,void *,u16);
extern void PLIST_MESSAGE_CreateWordSet(u16 *p, u32 s);
extern void PLIST_MESSAGE_SetWordSetPokemon(int a, int b, int c, int d);
extern void PLIST_MESSAGE_SetWordSetItem(int a, int b, int c, int d);
extern void PLIST_MESSAGE_SetWordSetHeldItem(int a, u32 b, u32 c, int d);
extern void PLIST_MESSAGE_SetWordSetMove(int a, int b, int c, int d);
extern void PLIST_MESSAGE_DestroyWordSet(void *p, u32 s);
extern void PLIST_MENU_ApplyArceusPlateForm(void *unused, void *a, int b);
extern void PLIST_MENU_ApplyGenesectDriveForm(int unused, int a, int b);
extern int PLIST_DEMO_CheckGiratinaToOrigin(u8 *,u32);
extern void PLIST_DEMO_ApplyGiratinaOriginForm(u32 p, void *m);
extern int POKELIST_GetMoveLearnStatus(u8 *p, void *mon, u8 bit);
extern u32 POKELIST_FindMoveSlot(u8 *p, void *q);
extern void POKELIST_ApplyItemEffect(u8 *p, void *q);
extern void POKELIST_EndMessageToExit(char *p);
extern void POKELIST_EndMessageToEvolve(u8 *p);
extern void POKELIST_OpenTakeItemMenu(u8 *p);
extern void POKELIST_OpenLearnMoveMenu(u8 *p);
#define W(k) (*(u32 *)(p+(k)))
#define S (*(u8 **)(p+0x280))
#define H(k) (*(u16 *)(S+(k)))
#define T(k) (*(u32 *)(S+(k)))
void POKELIST_ApplySelection(u8 *p)
{
    u32 old,buf;
    int r;
    if (S[0x63] == 1) { p[0xc]=0x13; return; }
    switch (T(0x34)) {
    case 0: case 1: case 18: case 21: case 22: case 23: case 25:
        POKELIST_EnterMenuPhase(p); func_020409B4(0); POKELIST_OpenContextMenu(p); return;
    case 5:
        if (PLIST_MENU_IsSpecialItemKind((short unsigned int *)p,H(0x44)) == 1) {
            POKELIST_EnterMenuPhase(p); POKELIST_OpenContextMenu(p); return;
        }
        if (PLIST_DEMO_CheckItemUsable((void *)W(0x38),(u16)H(0x44),0,(u16)(((struct Obj00009 *)p)->f0)) == 1) {
            r=PLIST_MENU_StartItemUse(p,0);
            PLIST_DEMO_UseItemOnMon((void *)W(0x38),H(0x44),(int)0,H(0x30),(u16)(((struct Obj00009 *)p)->f0));
            if (r == 2) PLIST_PLATE_SetMon(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)),(u32)W(0x38),0);
            else if (r == 19 || r == 13) {
                PLIST_PLATE_SetMon(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)),(u32)W(0x38),0);
                GFL_USE_PlaySeDefaultVolume(0x56f);
            } else {
                PLIST_PLATE_Redraw(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
                GFL_USE_PlaySeDefaultVolume(0x56f);
            }
            POKELIST_RemoveBagItem(p,H(0x44)); return;
        }
        if (H(0x44)==0x1d2 && PLIST_DEMO_CanUseGracidea((char *)p,W(0x38))==1) {
            PLIST_DEMO_ApplyShayminSkyForm((u32)p,(void *)W(0x38)); T(0x40)=10; p[0xc]=14; W(0x264)=3; return;
        }
        PLIST_MENU_ShowItemUsedThenContinue((int)p); return;
    case 16:
        if (POKELIST_CheckEvolution(p,(void *)W(0x38),H(0x44)) != 0) {
            POKELIST_RemoveBagItem(p,H(0x44)); p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=8;
        } else POKELIST_ShowMessage(p,0x51,1,(int)POKELIST_EndMessageToExit);
        return;
    case 9:
        old=POKE_TOOL_GetPartyValue((void *)W(0x38),6,0);
        if (old == 0) {
            if (FILE_UTIL_Check136C(H(0x44)) == 1) {
                p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=6; return;
            }
            T(0x40)=10;
            POKELIST_SetHeldItem(p,(void *)W(0x38),H(0x44));
            PLIST_PLATE_Redraw(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
            PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150));
            PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
            PLIST_MESSAGE_SetWordSetItem((int)p,W(0x150),1,H(0x44));
            PLIST_MENU_ApplyArceusPlateForm(p,(void *)W(0x38),(u16)H(0x44));
            PLIST_MENU_ApplyGenesectDriveForm((int)p,(int)((void *)W(0x38)),H(0x44));
            if (PLIST_DEMO_CheckGiratinaToOrigin(p,W(0x38)) == 1) {
                PLIST_DEMO_ApplyGiratinaOriginForm((u32)p,(void *)W(0x38));
                POKELIST_ShowMessage(p,0x56,1,(int)POKELIST_EndMessageToEvolve); W(0x264)=1;
            } else POKELIST_ShowMessage(p,0x56,1,(int)POKELIST_EndMessageToExit);
            PLIST_MESSAGE_DestroyWordSet(p,W(0x150)); return;
        }
        if (FILE_UTIL_Check136C(old)==1) {
            T(0x40)=10; POKELIST_ShowMessage(p,0x39,1,(int)POKELIST_EndMessageToExit); return;
        }
        PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150));
        PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
        PLIST_MESSAGE_SetWordSetHeldItem((int)p,W(0x150),1,(u16)old);
        POKELIST_ShowMessage(p,0x3a,0,(int)POKELIST_OpenTakeItemMenu);
        PLIST_MESSAGE_DestroyWordSet(p,W(0x150)); return;
    case 14:
        if (POKE_TOOL_GetPartyValue((void *)W(0x38),6,0) == 0) {
            buf=(u32)func_02009050((void *)T(8),0,H(0x5c),((struct Obj00009 *)p)->f0);
            POKE_TOOL_SetPartyValue((void *)W(0x38),0xa7,buf); func_020307B0((void *)buf);
            POKE_TOOL_SetPartyValue((void *)W(0x38),6,H(0x44));
            func_0200902C((void *)T(8),0,H(0x5c));
            POKELIST_ShowMessage(p,0x62,1,(int)POKELIST_EndMessageToExit);
        } else POKELIST_ShowMessage(p,0x63,1,(int)POKELIST_EndMessageToExit);
        return;
    case 6:
        switch ((u32)POKELIST_GetMoveLearnStatus(p,(void *)W(0x38),T(0x3c))) {
        case 0:
            T(0x40)=10;
            PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150)); PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
            PLIST_MESSAGE_SetWordSetMove((int)p,W(0x150),1,H(0x46));
            POKELIST_ShowMessage(p,0x29,1,(int)POKELIST_EndMessageToExit); PLIST_MESSAGE_DestroyWordSet(p,W(0x150));
            POKELIST_FindMoveSlot(p,(void *)W(0x38)); POKELIST_ApplyItemEffect(p,(void *)W(0x38)); return;
        case 1:
            PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150)); PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
            PLIST_MESSAGE_SetWordSetMove((int)p,W(0x150),1,H(0x46));
            POKELIST_ShowMessage(p,0x20,0,(int)POKELIST_OpenLearnMoveMenu); PLIST_MESSAGE_DestroyWordSet(p,W(0x150)); return;
        case 2:
            T(0x40)=10;
            PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150)); PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
            PLIST_MESSAGE_SetWordSetMove((int)p,W(0x150),1,H(0x46));
            POKELIST_ShowMessage(p,0x2a,1,(int)POKELIST_EndMessageToExit); PLIST_MESSAGE_DestroyWordSet(p,W(0x150)); return;
        case 3:
            T(0x40)=10;
            PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150)); PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
            PLIST_MESSAGE_SetWordSetMove((int)p,W(0x150),1,H(0x46));
            POKELIST_ShowMessage(p,0x2b,1,(int)POKELIST_EndMessageToExit); PLIST_MESSAGE_DestroyWordSet(p,W(0x150)); return;
        }
        return;
    case 3:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=0; return;
    default:
        POKELIST_EnterMenuPhase(p); POKELIST_OpenContextMenu(p); return;
    }
}

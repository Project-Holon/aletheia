/*
 * function: POKELIST_StartMode
 * address: 0x021B7698
 * packet: pkt_ov091_021B7698
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: one named offset shared across the case 7/8 branch join.
 * symbols:
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   PLIST_MENU_CreateButtonWindow 0x021BBDEC thumb ov091
 *   POKELIST_SetupModeScreen 0x021B7B98 thumb ov091
 *   PLIST_MENU_ItemRestoresHp 0x021BC1B4 thumb ov091
 *   PLIST_MENU_FindItemTarget 0x021BC1D0 thumb ov091
 *   PLIST_MENU_ShowItemUsedThenClose 0x021BC2C8 thumb ov091
 *   POKELIST_CheckBagItem 0x021BA65C thumb ov091
 *   PLIST_MESSAGE_CloseWindow 0x021BB7A4 thumb ov091
 *   PLIST_PLATE_SetSelected 0x021BAFA0 thumb ov091
 *   PLIST_DEMO_CheckGiratinaToAltered 0x021BDC5C thumb ov091
 *   PLIST_DEMO_ApplyGiratinaAlteredForm 0x021BDCA0 thumb ov091
 *   POKELIST_OpenForgetMoveMenu 0x021B9F34 thumb ov091
 *   POKELIST_ShowLearnMoveResult 0x021BA004 thumb ov091
 *   POKELIST_EndMessageToList 0x021B9E20 thumb ov091
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
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
extern void func_020409B4(u32 index);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern u32 func_0202136C(u16);
struct Sub02008F80Obj;
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
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern int PLIST_MENU_CreateButtonWindow(int p, int unused, int id, int r3, u8 a4, int a5);
extern void POKELIST_SetupModeScreen(u8 *);
extern int PLIST_MENU_ItemRestoresHp(unsigned short *p, void *id);
extern int PLIST_MENU_FindItemTarget(u8 *);
extern void PLIST_MENU_ShowItemUsedThenClose(int p);
extern u32 POKELIST_CheckBagItem(u8 *p, u16 id);
extern void PLIST_MESSAGE_CloseWindow(void *p, u32 *s);
extern void PLIST_PLATE_SetSelected(u8 *a, u8 *s, int k);
extern int PLIST_DEMO_CheckGiratinaToAltered(u8 *,u32);
extern void PLIST_DEMO_ApplyGiratinaAlteredForm(u32 p, void *m);
extern void POKELIST_OpenForgetMoveMenu(u8 *p);
extern void POKELIST_ShowLearnMoveResult(u8 *p);
extern void POKELIST_EndMessageToList(u8 *p);
void POKELIST_StartMode(u8 *p)
{
    u32 old;
    int r,id,off;
    switch (T(0x34)) {
    case 1:
        W(0x108)=PLIST_MENU_CreateButtonWindow((int)p,W(0x154),0,0x16,0x15,0);
        POKELIST_SetupModeScreen(p); p[0xd]=2; return;
    case 22: case 23:
        W(0x108)=PLIST_MENU_CreateButtonWindow((int)p,W(0x154),0,0xc,0x15,0);
        W(0x10c)=PLIST_MENU_CreateButtonWindow((int)p,W(0x154),1,0x16,0x15,1);
        POKELIST_SetupModeScreen(p); p[0xd]=2; return;
    case 0: case 6: case 9: case 14: case 16: case 18: case 21: case 25:
        POKELIST_SetupModeScreen(p); p[0xd]=2; return;
    case 3:
        W(0x14)=0; POKELIST_SetupModeScreen(p); p[0xd]=2; return;
    case 5:
        if (PLIST_MENU_ItemRestoresHp((short unsigned int *)p,(void *)H(0x44))==1) {
            r=PLIST_MENU_FindItemTarget(p);
            if (r != -1) {
                W(0x2c)=r; W(0x38)=(u32)POKEPARTY_GetMember((void *)T(0),r);
                PLIST_MENU_StartItemUse(p,0);
                PLIST_DEMO_UseItemOnMon((void *)W(0x38),H(0x44),(int)0,H(0x30),(u16)(((struct Obj00009 *)p)->f0));
                PLIST_PLATE_Redraw(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
                W(0x24)=1; p[0xd]=p[0xc]; p[0xc]=0;
                POKELIST_RemoveBagItem(p,H(0x44)); return;
            }
            PLIST_MENU_ShowItemUsedThenClose((int)p); p[0xd]=p[0xc]; p[0xc]=0; return;
        }
        if (POKELIST_CheckBagItem(p,H(0x44)) != 0) {
            POKELIST_SetupModeScreen(p); p[0xd]=2; return;
        }
        T(0x40)=10;
        PLIST_MESSAGE_CloseWindow(p,(u32 *)W(0x150)); PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150));
        PLIST_MESSAGE_SetWordSetItem((int)p,(u32)W(0x150),(u32)0,(u16)H(0x44));
        POKELIST_ShowMessage(p,0xb3,1,(int)POKELIST_EndMessageToExit);
        PLIST_MESSAGE_DestroyWordSet(p,W(0x150)); p[0xd]=p[0xc]; p[0xc]=0; return;
    case 7: case 8:
        W(0x2c)=T(0x3c); W(0x38)=(u32)POKEPARTY_GetMember((void *)T(0),T(0x3c));
        if (S[0x48] < 4) {
            old=POKE_TOOL_GetPartyValue((void *)W(0x38),S[0x48]+0x36,0);
            off=0x150;
            PLIST_MESSAGE_CreateWordSet((u16 *)p,W(off)); PLIST_MESSAGE_SetWordSetPokemon((int)p,W(off),0,W(0x38));
            PLIST_MESSAGE_SetWordSetMove((int)p,(u32)W(off),(u32)1,(u16)old);
            POKELIST_ShowMessage(p,0x28,1,(int)POKELIST_ShowLearnMoveResult);
        } else {
            off=0x150;
            PLIST_MESSAGE_CreateWordSet((u16 *)p,W(off)); PLIST_MESSAGE_SetWordSetMove((int)p,(u32)W(off),(u32)1,(u16)H(0x46));
            POKELIST_ShowMessage(p,0x23,0,(int)POKELIST_OpenForgetMoveMenu);
        }
        PLIST_MESSAGE_DestroyWordSet(p,W(off));
        p[0xd]=7; p[0xc]=0; W(0x14)=0;
        PLIST_PLATE_SetSelected(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)),1); return;
    case 10:
        W(0x2c)=T(0x3c); W(0x38)=(u32)POKEPARTY_GetMember((void *)T(0),T(0x3c));
        if (H(0x44) == 0) {
            T(0x34)=0; POKELIST_SetupModeScreen(p); p[0xd]=2;
        } else {
            old=POKE_TOOL_GetPartyValue((void *)W(0x38),6,0);
            if (old == 0) {
                POKELIST_SetHeldItem(p,(void *)W(0x38),H(0x44));
                PLIST_PLATE_Redraw(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
                PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150)); PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
                PLIST_MESSAGE_SetWordSetItem((int)p,(u32)W(0x150),(u32)1,(u16)H(0x44));
                PLIST_MENU_ApplyArceusPlateForm(p,(void *)W(0x38),(u16)H(0x44));
                PLIST_MENU_ApplyGenesectDriveForm((int)p,(int)((void *)W(0x38)),H(0x44));
                if (PLIST_DEMO_CheckGiratinaToOrigin(p,W(0x38))==1) {
                    PLIST_DEMO_ApplyGiratinaOriginForm((u32)p,(void *)W(0x38)); POKELIST_ShowMessage(p,0x56,1,(int)POKELIST_EndMessageToEvolve); W(0x264)=1;
                } else POKELIST_ShowMessage(p,0x56,1,(int)POKELIST_EndMessageToList);
                PLIST_MESSAGE_DestroyWordSet(p,W(0x150)); T(0x34)=0;
            } else {
                PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150)); PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
                PLIST_MESSAGE_SetWordSetHeldItem((int)p,W(0x150),1,(u16)old);
                POKELIST_ShowMessage(p,0x3a,0,(int)POKELIST_OpenTakeItemMenu); PLIST_MESSAGE_DestroyWordSet(p,W(0x150));
            }
        }
        p[0xd]=7; p[0xc]=0; W(0x14)=1;
        PLIST_PLATE_SetSelected(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)),1); return;
    case 11: case 12:
        W(0x2c)=T(0x3c); W(0x38)=(u32)POKEPARTY_GetMember((void *)T(0),T(0x3c));
        old=POKE_TOOL_GetPartyValue((void *)W(0x38),6,0);
        PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150));
        if (old == 0) {
            id=0x56;
            PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
            PLIST_MESSAGE_SetWordSetItem((int)p,(u32)W(0x150),(u32)1,(u16)H(0x44));
        } else {
            id=0x40;
            PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
            PLIST_MESSAGE_SetWordSetItem((int)p,(u32)W(0x150),(u32)1,(u16)old);
            PLIST_MESSAGE_SetWordSetItem((int)p,(u32)W(0x150),(u32)2,(u16)H(0x44));
        }
        POKELIST_SetHeldItem(p,(void *)W(0x38),H(0x44));
        PLIST_PLATE_Redraw(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
        PLIST_MENU_ApplyArceusPlateForm(p,(void *)W(0x38),(u16)H(0x44));
        PLIST_MENU_ApplyGenesectDriveForm((int)p,(int)((void *)W(0x38)),H(0x44));
        if (PLIST_DEMO_CheckGiratinaToAltered(p,W(0x38))==1) {
            PLIST_DEMO_ApplyGiratinaAlteredForm((u32)p,(void *)W(0x38)); POKELIST_ShowMessage(p,id,1,(int)POKELIST_EndMessageToEvolve); W(0x264)=2;
        } else if (T(0x34)==11) POKELIST_ShowMessage(p,id,1,(int)POKELIST_EndMessageToExit);
        else POKELIST_ShowMessage(p,id,1,(int)POKELIST_EndMessageToList);
        PLIST_MESSAGE_DestroyWordSet(p,W(0x150));
        if (T(0x34)==11) T(0x40)=10; else T(0x34)=0;
        p[0xd]=7; p[0xc]=0; W(0x14)=1;
        break;
    }
}

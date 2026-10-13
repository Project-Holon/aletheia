/*
 * function: POKELIST_DispatchMenuChoice
 * address: 0x021B916C
 * packet: pkt_ov091_021B916C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: final push 2026-10-05 G8L7. The only residue of the old draft was the 0xa1/0xa0 getter arm (case 16..19): the image keeps n (the 0xa1 getter result) in a stack word at [sp,#4] below the two item tables and keeps the pooled zero in r7, frame 0x28. With n as a plain local the allocator rematerialised the zero instead and kept n in r7 (frame 0x24, 122 bytes off). A local aggregate that holds n together with the two item tables (tables address-taken for PLIST_MENU_Open) keeps n in memory at that place with no other change: EXACT in c99 and c. A volatile n and a one-field struct n give EXACT and the old residue respectively; the aggregate is the form kept. The original may have used another aggregate that holds one count next to the lists; the layout shows only that one word sits below table b. Held for integrator review of the form.
 * symbols:
 *   POKELIST_MoveCursorToPlate 0x021B8F68 thumb ov091
 *   POKELIST_MoveSwapMarkerToPlate 0x021B8FC4 thumb ov091
 *   PLIST_MESSAGE_OpenWindow 0x021BB714 thumb ov091
 *   PLIST_MESSAGE_PrintText 0x021BB7E8 thumb ov091
 *   PLIST_MENU_Open 0x021BBAF8 thumb ov091
 *   POKELIST_RefreshCursor 0x021B8418 thumb ov091
 *   PLIST_PLATE_CheckSelection 0x021BB4A0 thumb ov091
 *   PLIST_PLATE_SetLabelState 0x021BB440 thumb ov091
 *   PLIST_PLATE_GetLabelState 0x021BB43C thumb ov091
 *   PLIST_MENU_ButtonWinSetActive 0x021BBE5C thumb ov091
 *   POKELIST_OpenTakeMailMenu 0x021BA394 thumb ov091
 *   POKELIST_GetFieldMoveMenuIndex 0x021B99E4 thumb ov091
 *   MOVE_POKEMON_IsSkillBlocked 0x0215EA14 thumb ov010
 *   func_02013E04 0x02013E04 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021BEC0C 0x021BEC0C data a4
 *   d_021BEC1C 0x021BEC1C data a4
 *   func_0201AB28 0x0201AB28 thumb
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
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
struct Sub02008F80Obj;
extern void func_020409B4(u32 index);
extern void func_020061E4(u32);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern u32 func_0202136C(u16);
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
extern int PLIST_DEMO_CheckGiratinaToOrigin(char *p);
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
extern void *func_0201AB28(void *p, u32 idx);
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
extern void POKELIST_MoveCursorToPlate(u8 *,int);
extern void POKELIST_MoveSwapMarkerToPlate(u8 *,int);
extern void PLIST_MESSAGE_OpenWindow(void *,u32 *,u32);
extern void PLIST_MESSAGE_PrintText(u8 *,u32 *,u32);
extern void PLIST_MENU_Open(u8 *,u8 *,int *);
extern void POKELIST_RefreshCursor(u8 *);
extern int PLIST_PLATE_CheckSelection(u8 *,int *);
extern void PLIST_PLATE_SetLabelState(u8 *p, u32 *q, int v);
extern int PLIST_PLATE_GetLabelState(int *);
extern void PLIST_MENU_ButtonWinSetActive(int,int);
extern void POKELIST_OpenTakeMailMenu(u8 *p);
extern int POKELIST_GetFieldMoveMenuIndex(void *p, int i);
extern int MOVE_POKEMON_IsSkillBlocked(int a0, int a1);
extern u32 func_02013E04(u32 id);
extern void func_0204B3DC(struct Obj *p, u32 v);
typedef struct { int v[4]; } Four;
extern const Four d_021BEC0C,d_021BEC1C;
#define A (*(int **)((p+W(0x2c)*4)+0x160))
void POKELIST_DispatchMenuChoice(u8 *p)
{
    struct { u32 n; Four b; Four a; } L;
    u32 old;
    int r,level;
    u32 flag;
    u8 i;
    u8 *q;
    if (S[0x63] == 1) { p[0xc]=19; return; }
    switch (W(0x3c)) {
    case 6:
        POKELIST_MoveCursorToPlate(p,W(0x2c)); W(0x38)=0; p[0xc]=2; POKELIST_SetupModeScreen(p); return;
    case 3:
        POKELIST_MoveCursorToPlate(p,W(0x2c)); POKELIST_MoveSwapMarkerToPlate(p,W(0x2c));
        W(0x30)=W(0x2c); p[0xc]=3; W(0x38)=0; W(0x14)=0;
        PLIST_MESSAGE_OpenWindow(p,(u32 *)W(0x150),0); PLIST_MESSAGE_PrintText(p,(u32 *)W(0x150),11);
        POKELIST_RefreshCursor(p); return;
    case 4:
        L.a=d_021BEC0C;
        POKELIST_EnterMenuPhase(p); PLIST_MESSAGE_OpenWindow(p,(u32 *)W(0x150),2);
        PLIST_MESSAGE_PrintText(p,(u32 *)W(0x150),19);
        PLIST_MENU_Open(p,(u8 *)W(0x154),L.a.v); func_020409B4(0); return;
    case 5:
        L.b=d_021BEC1C;
        POKELIST_EnterMenuPhase(p); PLIST_MESSAGE_OpenWindow(p,(u32 *)W(0x150),2);
        PLIST_MESSAGE_PrintText(p,(u32 *)W(0x150),19);
        PLIST_MENU_Open(p,(u8 *)W(0x154),L.b.v); func_020409B4(0); return;
    case 0:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=1; return;
    case 20:
        q=(u8 *)T(0x14); flag=0;
        r=PLIST_PLATE_CheckSelection(p,A);
        if (r == 0) {
            PLIST_PLATE_SetLabelState(p,(u32 *)A,p[0x105]); p[0x105]=p[0x105]+1;
            POKELIST_SetupModeScreen(p);
            if (p[0x105] == q[3]) flag=1;
            p[0xc]=2;
        } else if (r == 2) {
            POKELIST_ShowMessage(p,0x90,1,(int)POKELIST_EndMessageToList); func_020061E4(0x557);
        } else if (r == 3) {
            POKELIST_ShowMessage(p,0x91,1,(int)POKELIST_EndMessageToList); func_020061E4(0x557);
        } else if (r == 4) {
            POKELIST_ShowMessage(p,q[3]+0x5c,1,(int)POKELIST_EndMessageToList); func_020061E4(0x557);
        }
        W(0x38)=0;
        if (flag==1) {
            PLIST_PLATE_SetSelected(p,(u8 *)((u32)A),0); W(0x2c)=6;
            if (W(8)==0) {
                PLIST_MENU_ButtonWinSetActive(*(int *)((p+(u8)(W(0x2c)-6)*4)+0x108),1);
                func_0204B3DC((struct Obj *)W(0x1d8),0); return;
            }
        } else if (W(8)==0) POKELIST_MoveCursorToPlate(p,W(0x2c));
        return;
    case 21:
        level=PLIST_PLATE_GetLabelState(A);
        for (i=0; i<6; i++) {
            r=PLIST_PLATE_GetLabelState(*(int **)((p+i*4)+0x160));
            if (r <= 5 && r > level) PLIST_PLATE_SetLabelState(p,(u32 *)(*(int **)((p+i*4)+0x160)),r-1);
        }
        PLIST_PLATE_SetLabelState(p,(u32 *)A,6); p[0x105]=p[0x105]-1;
        if (W(8)==0) POKELIST_MoveCursorToPlate(p,W(0x2c));
        W(0x38)=0; p[0xc]=2; POKELIST_SetupModeScreen(p); return;
    case 10:
        old=POKE_TOOL_GetPartyValue((void *)W(0x38),6,0);
        PLIST_MENU_ApplyArceusPlateForm(p,(void *)W(0x38),0); PLIST_MENU_ApplyGenesectDriveForm((int)p,(int)((void *)W(0x38)),0);
        if (old==0) {
            PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150)); PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
            POKELIST_ShowMessage(p,0x3d,1,(int)POKELIST_EndMessageToList); PLIST_MESSAGE_DestroyWordSet(p,W(0x150)); return;
        }
        if (POKELIST_CheckBagItem(p,old)==999) {
            POKELIST_ShowMessage(p,0x3f,1,(int)POKELIST_EndMessageToList); return;
        }
        POKELIST_SetHeldItem(p,(void *)W(0x38),0); PLIST_PLATE_Redraw(p,(u8 *)((u32)A));
        PLIST_MESSAGE_CreateWordSet((u16 *)p,W(0x150)); PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
        PLIST_MESSAGE_SetWordSetItem((int)p,(u32)W(0x150),(u32)1,(u16)old);
        if (PLIST_DEMO_CheckGiratinaToAltered(p,W(0x38))==1) {
            PLIST_DEMO_ApplyGiratinaAlteredForm((u32)p,(void *)W(0x38)); POKELIST_ShowMessage(p,0x3e,1,(int)POKELIST_EndMessageToEvolve); W(0x264)=2;
        } else POKELIST_ShowMessage(p,0x3e,1,(int)POKELIST_EndMessageToList);
        PLIST_MESSAGE_DestroyWordSet(p,W(0x150)); return;
    case 11:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=0; return;
    case 9:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=3; return;
    case 12:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=7; return;
    case 13:
        POKELIST_ShowMessage(p,0x17,0,(int)POKELIST_OpenTakeMailMenu); return;
    case 7:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=0; return;
    case 16: case 17: case 18: case 19:
        if (T(0x34)==5) {
            if (PLIST_DEMO_CheckItemUsable((void *)W(0x38),H(0x44),(u16)(W(0x3c)-16),*(u16 *)p)==1) {
                old=POKE_TOOL_GetPartyValue((void *)W(0x38),W(0x3c)+0x26,0);
                func_020409B4(0); PLIST_MENU_StartItemUse(p,old);
                PLIST_DEMO_UseItemOnMon((void *)W(0x38),H(0x44),(u16)(W(0x3c)-16),H(0x30),*(u16 *)p);
                PLIST_PLATE_Redraw(p,(u8 *)((u32)A)); POKELIST_RemoveBagItem(p,H(0x44)); func_020061E4(0x56f);
            } else PLIST_MENU_ShowItemUsedThenContinue((int)p);
            return;
        }
        r=POKELIST_GetFieldMoveMenuIndex((void *)W(0x38),(u8)(W(0x3c)-16));
        if ((u32)(r-22)<=1) {
            if (func_02013E04(H(0x30))==0) {
                POKELIST_ShowMessage(p,0x50,1,(int)POKELIST_EndMessageToList); return;
            }
            L.n=POKE_TOOL_GetPartyValue((void *)W(0x38),0xa1,0);
            old=POKE_TOOL_GetPartyValue((void *)W(0x38),0xa0,0);
            if (old > L.n/5) {
                POKELIST_MoveCursorToPlate(p,W(0x2c)); POKELIST_MoveSwapMarkerToPlate(p,W(0x2c)); W(0x34)=W(0x2c);
                p[0xc]=4; W(0x38)=0; W(0x14)=0;
                PLIST_MESSAGE_OpenWindow(p,(u32 *)W(0x150),0); PLIST_MESSAGE_PrintText(p,(u32 *)W(0x150),17);
                POKELIST_RefreshCursor(p);
            } else POKELIST_ShowMessage(p,0x6b,1,(int)POKELIST_EndMessageToList);
            return;
        }
        switch (MOVE_POKEMON_IsSkillBlocked(r-11,(int)(S+0x1c))) {
        case 0: p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=r; return;
        case 1: POKELIST_ShowMessage(p,0x50,1,(int)POKELIST_EndMessageToList); return;
        case 2: POKELIST_ShowMessage(p,0x38,1,(int)POKELIST_EndMessageToList); return;
        case 3: POKELIST_ShowMessage(p,0x9f,1,(int)POKELIST_EndMessageToList); return;
        case 4: POKELIST_ShowMessage(p,0x4f,1,(int)POKELIST_EndMessageToList); return;
        }
        return;
    default:
        POKELIST_MoveCursorToPlate(p,W(0x2c)); W(0x38)=0; p[0xc]=2; POKELIST_SetupModeScreen(p); return;
    }
}

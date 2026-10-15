/*
 * function: RESEARCH_LIST_EnterSetup
 * address: 0x021BACA0
 * packet: pkt_ov217_021BACA0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   RESEARCH_LIST_CreateCommandQueue 0x021BC93C thumb ov217
 *   RESEARCH_LIST_CreateFont 0x021BC8B4 thumb ov217
 *   RESEARCH_LIST_CreateMessages 0x021BC8E4 thumb ov217
 *   RESEARCH_LIST_InitTables 0x021BC960 thumb ov217
 *   RESEARCH_LIST_UpdateTouchRects 0x021BC43C thumb ov217
 *   RESEARCH_LIST_CountUnlockedEntries 0x021BC820 thumb ov217
 *   RESEARCH_LIST_InitBackgrounds 0x021BC9FC thumb ov217
 *   RESEARCH_LIST_LoadBackground6 0x021BCAE8 thumb ov217
 *   RESEARCH_LIST_UpdateBackground7 0x021BCB48 thumb ov217
 *   RESEARCH_LIST_LoadBackground2 0x021BCB70 thumb ov217
 *   RESEARCH_LIST_LoadListBackground 0x021BCBD0 thumb ov217
 *   RESEARCH_LIST_UpdateBackground3 0x021BCC40 thumb ov217
 *   RESEARCH_LIST_CreateLabels 0x021BCC68 thumb ov217
 *   RESEARCH_LIST_RegisterEntryResources 0x021BCDF0 thumb ov217
 *   RESEARCH_LIST_RegisterCursorResources 0x021BCE7C thumb ov217
 *   RESEARCH_LIST_CreateUnits 0x021BCF68 thumb ov217
 *   RESEARCH_LIST_CreateActors 0x021BCFD0 thumb ov217
 *   RESEARCH_LIST_CreateBmps 0x021BD094 thumb ov217
 *   RESEARCH_LIST_DrawBmps 0x021BD0C4 thumb ov217
 *   RESEARCH_LIST_DrawBadgeA 0x021BD178 thumb ov217
 *   RESEARCH_LIST_DrawBadgeB 0x021BD274 thumb ov217
 *   RESEARCH_LIST_CreateOamSys 0x021BD38C thumb ov217
 *   RESEARCH_LIST_CreateOamObjects 0x021BD3B4 thumb ov217
 *   RESEARCH_LIST_CreatePalAnm 0x021BD47C thumb ov217
 *   RESEARCH_LIST_CreatePaletteAnime 0x021BD4F0 thumb ov217
 *   RESEARCH_LIST_BindPaletteAnime 0x021BD53C thumb ov217
 *   RESEARCH_LIST_RegisterVBlank 0x021BD5C4 thumb ov217
 *   RESEARCH_LIST_RestartNetwork 0x021BD5B4 thumb ov217
 *   RESEARCH_LIST_UpdateCenterActor 0x021BD588 thumb ov217
 *   RESEARCH_LIST_StartListPaletteAnime 0x021BC580 thumb ov217
 *   RESEARCH_LIST_SetOamEnabled 0x021BC72C thumb ov217
 *   RESEARCH_LIST_SyncFromListView 0x021BC644 thumb ov217
 *   RESEARCH_LIST_FindSaveIndex 0x021BBC50 thumb ov217
 *   RESEARCH_LIST_ShiftTextRight 0x021BBDF0 thumb ov217
 *   RESEARCH_LIST_SetSelectedIndex 0x021BC6EC thumb ov217
 *   RESEARCH_LIST_UpdateEntryActor 0x021BC014 thumb ov217
 *   RESEARCH_LIST_UpdateScrollbarActor 0x021BC168 thumb ov217
 *   RESEARCH_LIST_UpdateWindowMask 0x021BBF60 thumb ov217
 *   RESEARCH_LIST_PrintCurrentEntry 0x021BC06C thumb ov217
 *   RESEARCH_LIST_GetEntryHandled 0x021BB928 thumb ov217
 *   RESEARCH_LIST_ShowCursor 0x021BBD68 thumb ov217
 *   RESEARCH_LIST_ShowEntryLabels 0x021BC128 thumb ov217
 *   RESEARCH_LIST_SetCommandReady 0x021BB91C thumb ov217
 *   RESEARCH_LIST_PushCommand 0x021BB910 thumb ov217
 *   RESEARCH_LIST_HideCursor 0x021BBDAC thumb ov217
 *   RESEARCH_LIST_HideEntryLabels 0x021BC0E8 thumb ov217
 *   RESEARCH_LIST_FadeIn 0x021BC480 thumb ov217
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct S;
/* The caller supplies r0 to B48/C40 and consumes BB928 r0 despite legacy prototypes. */
extern void RESEARCH_LIST_CreateCommandQueue(u32);
extern void RESEARCH_LIST_CreateFont(u32);
extern void RESEARCH_LIST_CreateMessages(struct S *);
extern void RESEARCH_LIST_InitTables(u8 *);
extern void RESEARCH_LIST_UpdateTouchRects(u8 *);
extern void RESEARCH_LIST_CountUnlockedEntries(u8 *);
extern void RESEARCH_LIST_InitBackgrounds(char *);
extern void RESEARCH_LIST_LoadBackground6(char *);
extern u32 RESEARCH_LIST_UpdateBackground7(u32);
extern void RESEARCH_LIST_LoadBackground2(char *);
extern void RESEARCH_LIST_LoadListBackground(struct S *);
extern u32 RESEARCH_LIST_UpdateBackground3(u32);
extern void RESEARCH_LIST_CreateLabels(struct S *);
extern void RESEARCH_LIST_RegisterEntryResources(char *);
extern void RESEARCH_LIST_RegisterCursorResources(char *);
extern void RESEARCH_LIST_CreateUnits(struct S *);
extern void RESEARCH_LIST_CreateActors(u8 *);
extern void RESEARCH_LIST_CreateBmps(struct S *);
extern void RESEARCH_LIST_DrawBmps(u8 *);
extern void RESEARCH_LIST_DrawBadgeA(struct S *p);
extern void RESEARCH_LIST_DrawBadgeB(struct S *p);
extern void RESEARCH_LIST_CreateOamSys(char *);
extern void RESEARCH_LIST_CreateOamObjects(u8 *);
extern void RESEARCH_LIST_CreatePalAnm(u8 *);
extern void RESEARCH_LIST_CreatePaletteAnime(char *);
extern void RESEARCH_LIST_BindPaletteAnime(int *);
extern void RESEARCH_LIST_RegisterVBlank(char *p);
extern void RESEARCH_LIST_RestartNetwork(u32);
extern void RESEARCH_LIST_UpdateCenterActor(void *);
extern void RESEARCH_LIST_StartListPaletteAnime(char *,int);
extern void RESEARCH_LIST_SetOamEnabled(u8 *,u32,u8 *);
extern void RESEARCH_LIST_SyncFromListView(struct S *);
extern u8 RESEARCH_LIST_FindSaveIndex(u8 *);
extern void RESEARCH_LIST_ShiftTextRight(u32,u32);
extern void RESEARCH_LIST_SetSelectedIndex(void *,u8);
extern void RESEARCH_LIST_UpdateEntryActor(u8 *);
extern void RESEARCH_LIST_UpdateScrollbarActor(u32);
extern void RESEARCH_LIST_UpdateWindowMask(u8 *);
extern int RESEARCH_LIST_PrintCurrentEntry(char *p);
extern u32 RESEARCH_LIST_GetEntryHandled(u8 *);
extern void RESEARCH_LIST_ShowCursor(u8 *);
extern u32 RESEARCH_LIST_ShowEntryLabels(u32);
extern void RESEARCH_LIST_SetCommandReady(void *);
extern void RESEARCH_LIST_PushCommand(u8 *,u32);
extern void RESEARCH_LIST_HideCursor(u8 *);
extern u32 RESEARCH_LIST_HideEntryLabels(u32);
extern void RESEARCH_LIST_FadeIn(void);
void RESEARCH_LIST_EnterSetup(u8 *p)
{
    u8 slot;
    RESEARCH_LIST_CreateCommandQueue((u32)p);
    RESEARCH_LIST_CreateFont((u32)p);
    RESEARCH_LIST_CreateMessages((struct S *)p);
    RESEARCH_LIST_InitTables(p);
    RESEARCH_LIST_UpdateTouchRects(p);
    RESEARCH_LIST_CountUnlockedEntries(p);
    RESEARCH_LIST_InitBackgrounds((char *)p);
    RESEARCH_LIST_LoadBackground6((char *)p);
    RESEARCH_LIST_UpdateBackground7((u32)p);
    RESEARCH_LIST_LoadBackground2((char *)p);
    RESEARCH_LIST_LoadListBackground((struct S *)p);
    RESEARCH_LIST_UpdateBackground3((u32)p);
    RESEARCH_LIST_CreateLabels((struct S *)p);
    RESEARCH_LIST_RegisterEntryResources((char *)p);
    RESEARCH_LIST_RegisterCursorResources((char *)p);
    RESEARCH_LIST_CreateUnits((struct S *)p);
    RESEARCH_LIST_CreateActors(p);
    RESEARCH_LIST_CreateBmps((struct S *)p);
    RESEARCH_LIST_DrawBmps(p);
    RESEARCH_LIST_DrawBadgeA((struct S *)p);
    RESEARCH_LIST_DrawBadgeB((struct S *)p);
    RESEARCH_LIST_CreateOamSys((char *)p);
    RESEARCH_LIST_CreateOamObjects(p);
    RESEARCH_LIST_CreatePalAnm(p);
    RESEARCH_LIST_CreatePaletteAnime((char *)p);
    RESEARCH_LIST_BindPaletteAnime((int *)p);
    RESEARCH_LIST_RegisterVBlank((char *)p);
    RESEARCH_LIST_RestartNetwork((u32)p);
    RESEARCH_LIST_UpdateCenterActor(p);
    RESEARCH_LIST_StartListPaletteAnime((char *)p,0);
    RESEARCH_LIST_SetOamEnabled(p,0,0);
    RESEARCH_LIST_SetOamEnabled(p,1,0);
    RESEARCH_LIST_SetOamEnabled(p,2,0);
    RESEARCH_LIST_SyncFromListView((struct S *)p);
    slot=RESEARCH_LIST_FindSaveIndex(p);
    if(slot!=255) {
        RESEARCH_LIST_ShiftTextRight((u32)p,slot);
        RESEARCH_LIST_SetSelectedIndex(p,slot);
        RESEARCH_LIST_UpdateEntryActor(p);
    }
    RESEARCH_LIST_UpdateTouchRects(p);
    RESEARCH_LIST_UpdateScrollbarActor((u32)p);
    RESEARCH_LIST_UpdateEntryActor(p);
    RESEARCH_LIST_UpdateWindowMask(p);
    RESEARCH_LIST_PrintCurrentEntry((char *)p);
    if(RESEARCH_LIST_GetEntryHandled(p)==0) {
        RESEARCH_LIST_ShowCursor(p);
        RESEARCH_LIST_ShowEntryLabels((u32)p);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand(p,2);
    } else {
        RESEARCH_LIST_HideCursor(p);
        RESEARCH_LIST_HideEntryLabels((u32)p);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand(p,1);
    }
    RESEARCH_LIST_FadeIn();
}

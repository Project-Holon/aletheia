/*
 * file:     wf2dmap_touch.c
 * unit:     yes
 * function: WF2DMAP_TOUCH_CreateNameEntry, WF2DMAP_TOUCH_FriendKeyScreen, WF2DMAP_TOUCH_GetFriendKeyInput, WF2DMAP_TOUCH_DrawFriendKey, WF2DMAP_TOUCH_DeleteScreens, WF2DMAP_TOUCH_InitGfx, WF2DMAP_TOUCH_ClearScreens, WF2DMAP_TOUCH_StartFriendEdit, WF2DMAP_TOUCH_FriendEditScreen, WF2DMAP_TOUCH_SelectMenu, WF2DMAP_TOUCH_GetMenuKeyInput, WF2DMAP_TOUCH_GetMenuTouchInput, WF2DMAP_TOUCH_GetMenuInput, WF2DMAP_TOUCH_StartEditAnim, WF2DMAP_TOUCH_StepSlideIn, WF2DMAP_TOUCH_CreateEditWidgets, WF2DMAP_TOUCH_DeleteEditWidgets, WF2DMAP_TOUCH_InitEditScreen, WF2DMAP_TOUCH_CloseEditScreen, WF2DMAP_TOUCH_ReleaseEditWidgets, WF2DMAP_TOUCH_CreateTrainerWidgets, WF2DMAP_TOUCH_ClearTrainerScreens, WF2DMAP_TOUCH_SetValue, WF2DMAP_TOUCH_DrawSlider, WF2DMAP_TOUCH_DrawCursorBg, WF2DMAP_TOUCH_FindPrevEntry, WF2DMAP_TOUCH_FindNextEntry, WF2DMAP_TOUCH_CreateWidgetHandles, WF2DMAP_TOUCH_DeleteWidgetHandles, WF2DMAP_TOUCH_CreateTileWidgets, WF2DMAP_TOUCH_DeleteTileScreens, WF2DMAP_TOUCH_InitTileRecord, WF2DMAP_TOUCH_Noop, WF2DMAP_TOUCH_SetTileRecordField, WF2DMAP_TOUCH_ClearTileRecord, WF2DMAP_TOUCH_ClearScreenAt, WF2DMAP_TOUCH_ClearAllScreens, WF2DMAP_TOUCH_SetBgScroll, WF2DMAP_TOUCH_PrintItem, WF2DMAP_TOUCH_ParseKey, WF2DMAP_TOUCH_GetConfirmInput, WF2DMAP_TOUCH_CreatePalAnims, WF2DMAP_TOUCH_DeletePalAnims, WF2DMAP_TOUCH_DrawTopHighlight, WF2DMAP_TOUCH_SetTopHighlight1, WF2DMAP_TOUCH_SetTopHighlight3, WF2DMAP_TOUCH_SetTopHighlight, WF2DMAP_TOUCH_UpdateTopBar, WF2DMAP_TOUCH_StepTopBarBlink, WF2DMAP_TOUCH_DrawItemHighlight, WF2DMAP_TOUCH_SetItemHighlight1, WF2DMAP_TOUCH_SetItemHighlight3, WF2DMAP_TOUCH_SetItemHighlight, WF2DMAP_TOUCH_UpdateItemBar, WF2DMAP_TOUCH_StepItemBarBlink, WF2DMAP_TOUCH_PlayActorAnimA, WF2DMAP_TOUCH_PlayActorAnimB, WF2DMAP_TOUCH_SetScreenBrightness, WF2DMAP_TOUCH_SetActorAnimSeq, WF2DMAP_TOUCH_MakeScreen, WF2DMAP_TOUCH_ClearSlotArray, WF2DMAP_TOUCH_AddSlot, WF2DMAP_TOUCH_UpdateSlots, WF2DMAP_TOUCH_TransferScreen, WF2DMAP_TOUCH_ReleaseActor
 * address:  0x021C8DA0
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   NAMEIN_SETUP_CreateArgs 0x0216BFD4 thumb ov010
 *   STRBUF_SetString 0x02045924 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   Wf2dmapFriend_SetState 0x021C6438 thumb ov128
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   gWf2dmapFriendKeyHitRects 0x021CA529 data a1
 *   Wf2dmapFriend_CreateWindow 0x021C63AC thumb ov128
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   STRBUF_Create 0x020457B0 arm
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   WIFILIST_GetWork 0x02009860 thumb
 *   DWC_CreateFriendKey 0x0205994C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   STRBUF_Clear 0x0204581C arm
 *   STRBUF_AppendChar 0x02045AFC arm
 *   STRBUF_Delete 0x02045808 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   gWf2dmapCursorTileTable 0x021CA674 data a4
 *   BMP_WIN_Delete 0x020452E8 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   Wf2dmapFriend_DrawText 0x021C6ADC thumb ov128
 *   BG_SYS_DrawTile 0x02041090 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   Wf2dmapFriend_ClearWindow 0x021C6B38 thumb ov128
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   Wf2dmapFriend_RestartActorAnim 0x021C6E18 thumb ov128
 *   KEY_GetCont 0x0203630C arm
 *   gWf2dmapEditHitRects 0x021CA576 data a1
 *   Wf2dmapFriend_SetActorAutoAnim 0x021C6DF8 thumb ov128
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   gWf2dmapEntryPositions 0x021CA564 data a2
 *   gWf2dmapTileValues 0x021CA538 data a4
 *   gWf2dmapTileItemValues 0x021CA7E0 data a4
 *   gWf2dmapTileItemIds 0x021CA521 data a1
 *   Wf2dmapFriend_PrintMyStatus 0x021C6BCC thumb ov128
 *   Wf2dmapFriend_SetActorDrawEnable 0x021C6DD8 thumb ov128
 *   WIFILIST_GetFriendInfoField 0x02009864 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_GetDispWidth 0x02045748 arm
 *   TOUCHBAR_PrintYesNoCancelLabels 0x021B6B2C thumb ov067
 *   Wf2dmapFriend_SetWordSlot 0x021C6C94 thumb ov128
 *   Wf2dmapFriend_PrintTrainerStats 0x021C6C20 thumb ov128
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   CURSOR_MOVE_GetTableGroup 0x02025C88 thumb
 *   POKEGRA_OpenTrainerHandle 0x0202DA04 thumb
 *   POKEGRA_RegisterTrainerCgr 0x0202DA48 thumb
 *   POKEGRA_RegisterTrainerPalette 0x0202DA18 thumb
 *   POKEGRA_RegisterTrainerCellAnim 0x0202DA6C thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   gWf2dmapTrainerActorBounds 0x021CA640 data a2
 *   BG_SYS_DrawTileEx 0x020410D0 arm
 *   gWf2dmapSliderTileX 0x021CA544 data a1
 *   gWf2dmapSliderFlags 0x021CA4F7 data a1
 *   gWf2dmapSliderTileY 0x021CA554 data a1
 *   _u32_div_f 0x0209C2B0 arm
 *   gWf2dmapWidgetFileIds 0x021CA648 data a2
 *   gWf2dmapTileWindowParams 0x021CA5A2 data a2
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   _ull_mul 0x0209C054 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   BLINK_PALANM_Create 0x0202E940 thumb
 *   BLINK_PALANM_LoadPalettes 0x0202E9AC thumb
 *   BLINK_PALANM_Delete  0x0202EA20  thumb
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   BLINK_PALANM_ResetPhase  0x0202EB04  thumb
 *   UI_GetInputMode 0x020355C4 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   MISC_GetBlock  0x0200C0F0  thumb  arm9
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb  arm9
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 */
#include "wf2dmap_ui_types.h"

struct Big;
struct Sub020097BCObj;
struct BigObj;
struct Strbuf;
struct Actor;
struct DWCstAccUserData;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PrintSys;
struct CharBuf;
struct Obj;
struct CodeIn;
struct BlinkPalAnm;
struct Cfg;
#include "../types.h"

typedef struct { u16 v[10]; } Tbl;

typedef struct {u16 v[4];} Bounds;

struct GameData;
struct SaveControl;

extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gd);
struct MiscSave;
extern struct MiscSave *MISC_GetBlock(struct SaveControl *save);
struct FieldState;
extern struct FieldState *GAME_DATA_GetWifiList(struct GameData *gameData);
extern u32 WIFILIST_GetFriendInfoField(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern char *NAMEIN_SETUP_CreateArgs(int,int,u32,u32,int,int,void *);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void Wf2dmapFriend_SetState(u8 *p, u8 a, u8 b);
extern void WIPE_SYS_Start(void *divisionMode, u32 mainPattern, u32 subPattern, u16 color, u32 frames, u32 wait, u32 heapId);
extern u32 WIPE_SYS_EndCheck(void);
extern int TOUCHPANEL_HitTrg(const void *);
extern void UI_SetInputMode(u8 v);
extern u32 KEY_GetTrg(void);
extern void Wf2dmapFriend_CreateWindow(void *, u32 *, u32, u32, u8, u8, u8, u8, u32, u8);
extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
struct WifiList;
extern struct WifiList *WIFILIST_GetWork(struct WifiList *list);
extern unsigned long long DWC_CreateFriendKey(struct DWCstAccUserData *userdata);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, struct Strbuf *dest);
struct BmpWin;
extern u8 BMP_WIN_GetWidth(struct BmpWin *win);
extern void STRBUF_Clear(struct Strbuf *strbuf);
extern void STRBUF_AppendChar(struct Strbuf *strbuf, u16 ch);
extern void STRBUF_Delete(struct Strbuf *strbuf);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *arc, u32 id, u32 comp, void **out, u16 heap);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern u32 GFL_HEAP_Free(void *p);
struct MyStatus;
extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gd);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void Wf2dmapFriend_DrawText(u8 *p, u8 *q, unsigned v);
extern void BG_SYS_DrawTile(u32 index, void *src, u8 dx, u8 dy, u8 cw, u8 ch);
extern void BG_SYS_MarkTileDirty(u32 bit);
extern void Wf2dmapFriend_ClearWindow(u8 *p);
extern void BG_SYS_SetTileEntry(u32 layer, u16 value, u8 x0, u8 y0, u8 w, u8 h, u8 mode);
extern void BMP_WIN_ClearScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
struct PrintQueue;
extern u32 PRINTSYS_QUE_IsFinished(struct PrintQueue *queue);
extern void BG_SYS_ChangeScroll(u32 index, u32 a, u32 b);
extern void Wf2dmapFriend_RestartActorAnim(u8 *p, int i, u16 a);
extern unsigned int KEY_GetCont(void);
extern void Wf2dmapFriend_SetActorAutoAnim(u8 *p, u32 a);
extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);
extern void Wf2dmapFriend_PrintMyStatus(u8 *,u8 *,int,unsigned);
extern void Wf2dmapFriend_SetActorDrawEnable(u8 *p, u32 a);
struct Bmp;
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
extern void BMP_Clear(struct Bmp *bmp, u8 value);
extern u8 BMP_WIN_GetDispWidth(struct BmpWin *win);
extern void TOUCHBAR_PrintYesNoCancelLabels(u32 window, void *textCtx, u32 fontId, u16 x, u16 y, u16 color, u32 firstNumber, u32 secondNumber, u16 heap);
extern void Wf2dmapFriend_SetWordSlot(char **,int);
extern int Wf2dmapFriend_PrintTrainerStats(u8 *,u8 *,int);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern u32 CURSOR_MOVE_GetTableGroup(u32);
extern int POKEGRA_OpenTrainerHandle(int);
extern u32 POKEGRA_RegisterTrainerCgr(u32,u32,u32,u32);
extern s32 POKEGRA_RegisterTrainerPalette(u32 a, u32 b, u32 c, u32 d, u16 e);
extern int POKEGRA_RegisterTrainerCellAnim(u32 unusedArg, u32 mapping, u32 drawType, u16 heapId);
extern void ARC_TOOL_DeleteHandle(void *);
extern struct Obj *CLACT_CreateActor(void *,u32,u32,u32,const void *,u16,u16);
extern void BG_SYS_DrawTileEx(u32 index, u8 dx, u8 dy, u8 cw, u8 ch, void *src, u8 sx, u8 sy, u8 sw, u8 sh);
extern void WORDSET_CopyTaggedText(struct WordSet *words, struct Strbuf *dst, struct Strbuf *src);
extern u16 STRBUF_GetEosChar(void);
extern u16 *STRBUF_GetChars(struct Strbuf *strbuf);
extern int TOUCHPANEL_GetTrg(void);
extern struct BlinkPalAnm *BLINK_PALANM_Create(u16 firstColor, u16 colorCount, u32 mode, u16 heap);
extern void BLINK_PALANM_LoadPalettes(struct BlinkPalAnm *anm, void *archive, u32 fileId, u32 srcStart, u32 dstStart);
extern u32 BLINK_PALANM_Delete(struct BlinkPalAnm *p);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BLINK_PALANM_ResetPhase(struct BlinkPalAnm *anm);
extern u8 UI_GetInputMode(void);
extern void CLACT_SetActorAnimFrame(struct Actor *actor, u32 frame);
extern void CLACT_SetActorAnimSeq(struct Actor *actor, u16 value);
extern void CLACT_SetActorAutoAnim(struct Actor *actor, u32 enable);
extern void G2x_SetBlendBrightness_(u32,int,int);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQueue *queue, struct Bmp *bmp);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_DeleteActor(struct Actor *actor);
char *WF2DMAP_TOUCH_CreateNameEntry(void *unused,char *q,int mode,int heap);
void WF2DMAP_TOUCH_DrawFriendKeyThunk(void *p,void *q,void *r,u16 s);
int WF2DMAP_TOUCH_FriendKeyScreen(void *p, u8 *q, u8 *r, int heap);
void WF2DMAP_TOUCH_DeleteScreenThunk(void *p, void *q, void *r);
int WF2DMAP_TOUCH_GetFriendKeyInput(void *unused,int *q);
void WF2DMAP_TOUCH_DrawFriendKey(u8 *p, u8 *q, u8 *ctx, u16 heap);
void WF2DMAP_TOUCH_DeleteScreens(char *p,int unused,char *q);
void WF2DMAP_TOUCH_InitGfx(char *p,char *q,char *r);
void WF2DMAP_TOUCH_ClearScreens(char *p,void *q);
void WF2DMAP_TOUCH_StartFriendEdit(u8 *p,u8 *b,u8 *c,u16 d);
int WF2DMAP_TOUCH_FriendEditScreen(u8 *p,u8 *q,u8 *r,u16 heap);
int WF2DMAP_TOUCH_SelectMenu(char *p,void *q,void *r,int n);
int WF2DMAP_TOUCH_GetMenuKeyInput(void *p,int *q,void *r);
int WF2DMAP_TOUCH_GetMenuTouchInput(void *p,void *q,void *r,int *flag);
int WF2DMAP_TOUCH_GetMenuInput(void *p,int *q,char *r);
void WF2DMAP_TOUCH_StartEditAnim(char *p, void *q, void *r, int s);
int WF2DMAP_TOUCH_StepSlideIn(u8 *p,void *a,void *b,int c);
void WF2DMAP_TOUCH_CreateEditWidgets(u8 *p, void *unused, u8 *q, u16 heap);
void WF2DMAP_TOUCH_DeleteEditWidgets(u8 *p,void *unused,u8 *q);
void WF2DMAP_TOUCH_InitEditScreen(u8 *p,u8 *q,u8 *r,u16 heap);
void WF2DMAP_TOUCH_CloseEditScreen(u8 *p,u8 *q);
void WF2DMAP_TOUCH_ReleaseEditWidgets(char *p,u8 *q);
void WF2DMAP_TOUCH_CreateTrainerWidgets(u8 *p,u8 *q,u8 *ctx,u16 heap);
void WF2DMAP_TOUCH_ClearTrainerScreens(u32 p);
void WF2DMAP_TOUCH_SetValue(u16 *p, void *b, void *c, int flag, int value, int unused);
void WF2DMAP_TOUCH_DrawSlider(u8 *p,u8 *q,int idx);
void WF2DMAP_TOUCH_DrawCursorBg(void *unused,u8 *p);
int WF2DMAP_TOUCH_FindPrevEntry(u8 *p,int direction);
int WF2DMAP_TOUCH_FindNextEntry(u8 *p,int direction);
void WF2DMAP_TOUCH_CreateWidgetHandles(u8 *p,u8 *q,u16 heap);
void WF2DMAP_TOUCH_DeleteWidgetHandles(u8 *p);
void WF2DMAP_TOUCH_CreateTileWidgets(u8 *p,void *q);
void WF2DMAP_TOUCH_DeleteTileScreens(u8 *p, void *unused);
void WF2DMAP_TOUCH_InitTileRecord(u32 p,int unused,const u16 *q,u32 value,u16 heap);
void WF2DMAP_TOUCH_Noop(void *unused);
void WF2DMAP_TOUCH_SetTileRecordField(u32 p,int unused,u32 index,u32 value,u32 unused5,u16 heap);
void WF2DMAP_TOUCH_ClearTileRecord(Wf2dmapTouchTileRecord *p,u32 index);
void WF2DMAP_TOUCH_ClearScreenAt(char *p,u32 index);
void WF2DMAP_TOUCH_ClearAllScreens(char *p,void *q);
void WF2DMAP_TOUCH_SetBgScroll(void *q,char *p);
void WF2DMAP_TOUCH_PrintItem(u8 *p,void *unused,u8 *q,u32 item,int x,int y,int color);
u64 WF2DMAP_TOUCH_ParseKey(void *p,int *ok);
int WF2DMAP_TOUCH_GetConfirmInput(int *p);
void WF2DMAP_TOUCH_CreatePalAnims(u8 *p,u16 heap);
void WF2DMAP_TOUCH_DeletePalAnims(u8 *p);
void WF2DMAP_TOUCH_DrawTopHighlight(u32 a,u32 b);
void WF2DMAP_TOUCH_SetTopHighlight1(u8 *p, int a);
void WF2DMAP_TOUCH_SetTopHighlight3(u8 *p, int a);
void WF2DMAP_TOUCH_SetTopHighlight(u8 *p, int a, int b);
void WF2DMAP_TOUCH_UpdateTopBar(unsigned *p);
int WF2DMAP_TOUCH_StepTopBarBlink(char *p);
void WF2DMAP_TOUCH_DrawItemHighlight(u32 a,u32 b);
void WF2DMAP_TOUCH_SetItemHighlight1(u8 *p, int a);
void WF2DMAP_TOUCH_SetItemHighlight3(u8 *p, int a);
void WF2DMAP_TOUCH_SetItemHighlight(u8 *p, int a, int b);
void WF2DMAP_TOUCH_UpdateItemBar(char *p);
int WF2DMAP_TOUCH_StepItemBarBlink(char *p);
void WF2DMAP_TOUCH_PlayActorAnimA(char *p);
void WF2DMAP_TOUCH_PlayActorAnimB(char *p);
void WF2DMAP_TOUCH_SetScreenBrightness(int a);
void WF2DMAP_TOUCH_SetActorAnimSeq(char *p, int n);
void WF2DMAP_TOUCH_MakeScreen(char *p);
void WF2DMAP_TOUCH_ClearSlotArray(char *p);
void WF2DMAP_TOUCH_AddSlot(char *p,void *q);
void WF2DMAP_TOUCH_UpdateSlots(char *p);
void WF2DMAP_TOUCH_TransferScreen(char *p);
void WF2DMAP_TOUCH_ReleaseActor(int *p);
extern const u8 gWf2dmapFriendKeyHitRects[];
extern const Tbl gWf2dmapCursorTileTable;
extern const u8 gWf2dmapEditHitRects[];
extern const s16 gWf2dmapEntryPositions[][3];
extern const u32 gWf2dmapTileValues[];
extern const u32 gWf2dmapTileItemValues[];
extern const u8 gWf2dmapTileItemIds[];
extern const Bounds gWf2dmapTrainerActorBounds;
extern const u8 gWf2dmapSliderTileX[];
extern const u8 gWf2dmapSliderFlags[];
extern const u8 gWf2dmapSliderTileY[];
extern const u16 gWf2dmapWidgetFileIds[4];
extern const u8 gWf2dmapTileWindowParams[10][4];

char *WF2DMAP_TOUCH_CreateNameEntry(void *unused,char *q,int mode,int heap) {
 void *v;void *base;int idx;char *ret;unsigned kind;
 v=MISC_GetBlock(GAME_DATA_GetSaveControl(((Wf2dmapTouchFriendData *)q)->saveData));
 base=(void *)GAME_DATA_GetWifiList(((Wf2dmapTouchFriendData *)q)->saveData);idx=*(u8 *)(q+24+*(signed char *)&((Wf2dmapTouchFriendData *)q)->index);
 kind=WIFILIST_GetFriendInfoField(base,idx,9);
 if(mode==1 || kind==2) ret=NAMEIN_SETUP_CreateArgs(heap,4,65535,0,7,0,v);
 else ret=NAMEIN_SETUP_CreateArgs(heap,4,WIFILIST_GetFriendInfoField(base,idx,8),0,7,0,v);
 if(((Wf2dmapTouchFriendData *)q)->nameFlag==1) {STRBUF_SetString(((Wf2dmapNameEntry *)ret)->text,(const u16 *)(((Wf2dmapTouchFriendData *)q)->nameText));((Wf2dmapTouchFriendData *)q)->nameFlag=0;}
 return ret;
}

/*
 * extent: includes the eight-byte forwarding follower at 0x021C8E24.
 */
void WF2DMAP_TOUCH_DrawFriendKeyThunk(void *p,void *q,void *r,u16 s) {
 WF2DMAP_TOUCH_DrawFriendKey(p,q,r,s);
}

/*
 * extent: Includes the eight-byte forwarding follower at 0x021C8F24.
 */
int WF2DMAP_TOUCH_FriendKeyScreen(void *p, u8 *q, u8 *r, int heap)
{
    int v;
    switch (q[8]) {
    case 0:
        WF2DMAP_TOUCH_DrawFriendKeyThunk(p, q, r, 52);
        WF2DMAP_TOUCH_InitGfx(p, (char *)q, (char *)r);
        q[8] = 1;
        break;
    case 1:
        v = WF2DMAP_TOUCH_GetFriendKeyInput(p, (int *)q);
        if (v == 0) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            WF2DMAP_TOUCH_PlayActorAnimA((char *)r);
            q[8] = 2;
        } else if (v == 1) {
            GFL_USE_PlaySeDefaultVolume(0x556);
            WF2DMAP_TOUCH_PlayActorAnimB((char *)r);
            q[8] = 3;
        }
        break;
    case 2:
        if (CLACT_IsActorAnimActive(((Wf2dmapTouchGfx *)r)->actorA) != 1) {
            Wf2dmapFriend_SetState(q, 0, 2);
            WF2DMAP_TOUCH_ClearScreens(p, r);
            WF2DMAP_TOUCH_DeleteScreenThunk(p, q, r);
            return 1;
        }
        break;
    case 3:
        if (CLACT_IsActorAnimActive(((Wf2dmapTouchGfx *)r)->actorB) != 1) q[8] = 4;
        break;
    case 4:
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, heap);
        q[8] = 5;
        break;
    case 5:
        if (WIPE_SYS_EndCheck() == 1) {
            Wf2dmapFriend_SetState(q, 6, 0);
            WF2DMAP_TOUCH_DeleteScreenThunk(p, q, r);
            return 1;
        }
        break;
    }
    return 0;
}

void WF2DMAP_TOUCH_DeleteScreenThunk(void *p, void *q, void *r)
{
    WF2DMAP_TOUCH_DeleteScreens(p, (int)q, r);
}

int WF2DMAP_TOUCH_GetFriendKeyInput(void *unused,int *q) {
 int v=TOUCHPANEL_HitTrg(gWf2dmapFriendKeyHitRects);
 if(v!=-1) {UI_SetInputMode(1);*q=1;return v;}
 if(KEY_GetTrg()&2) {UI_SetInputMode(0);*q=0;return 0;}
 if(KEY_GetTrg()&1024) {UI_SetInputMode(0);*q=0;return 1;}
 return -1;
}

static inline u8 *Wf2dmapTouchSecondWindow(u8 *p)
{
    return p + 8;
}

/*
 * note 2026-10-05 (wave P5 lane T2): written from the listing, 460 bytes, same size, same
 *   instruction stream. Only residue: the loop counter i and the text buffer are in swapped
 *   callee-saved registers (original text r4, i/const 10 r5; build text r5, i/10 r4), 38 bytes
 *   of register operands plus entry-prologue order. Spill slots match (w1, buf2, gfx, pal, n
 *   declared in that order). Tried: six per-function pragmas (opt_lifetimes, opt_propagation,
 *   opt_common_subs, opt_dead_assignments, scheduling, peephole; none helps, opt_propagation
 *   is worse), decl order of i/x/t/text, do-while loop, i assigned before pal, ctx fields read
 *   inline in the loop (worse), int n. 17 compiles used.
 *   Struct: p is two 8-byte windows (desc at +0, +8), p+0x10 = archive handle, p+0x14 = out ptr;
 *   q+4 holds the save object; ctx+4 bank, +8 archive, +0x34 / +0x17c gfx args. Friend code
 *   screen: u64 key, 12 digits (u64 /10, %10), gap of 8 after every 4th digit.
 *   All callee prototypes already match the arity of the call sites.
 *   recoup 2026-10-05 (lane R20): lever 2 closed the entry-prologue part: heap as u16 here AND
 *   in STRBUF_Create / ARC_UTIL_LoadPaletteDataFromHandle prototypes (38 -> 22 B, the str r3 spill now comes first).
 *   Remaining 22 B: pure colour swap, classes {10, i} and {2, text} swapped (orig r5/r4, build r4/r5).
 *   Tried, no change: u8 heap, text/i decl order, w1 inline, x decl order, long i/x/n, six pragmas
 *   (propagation worse), pal/gfx swap 28, t before call 98, w1 late 39, u32/u8 i 146/130, i<13 24.
 *   Twin search: grep DWC_CreateFriendKey / WF2DMAP_TOUCH_TransferScreen / STRBUF_AppendChar in src/matched/ov: no loop twin.
 *   Idioms checked: two-long-lived-values-in-each-others-registers (no applicable form),
 *   a-long-index-colours-apart-from-an-int (22), a-colour-swap-...-opt-lifetimes-off (22),
 *   a-loop-counter-zero-before-an-offset-assignment (n/a).
 *   final push 2026-10-05 G5L9 (40 compiles, all 22 B, same pure swap): the (u16) cast on the
 *   third blit argument is dropped (callee takes u16; same bytes, now plain). Tried, no change:
 *   block-scoped t/x/i, declarations at the point of use, u8* text, key decl first/last, i/x
 *   first, STRBUF_AppendChar u16 value, Wf2dmapFriend_CreateWindow with u8 fourth parameter, BMP_WIN_GetWidth as u8
 *   (same bytes) with n u32/int/u8, named constants ten/two (int, u8; with opt_propagation off 449 B),
 *   constants as locals in both orders, text/buf2/key as declaration initialisers (30 B, only slot
 *   order moves), inline put()/blit() helpers, struct view of p (two windows), i++ as body statement
 *   (while, for with empty step; i++ before key= is 27 B), pragma pairs (lifetimes+common_subs,
 *   lifetimes+dead_assignments, common_subs+dead_assignments, lifetimes+peephole,
 *   lifetimes+scheduling, common_subs+peephole, dead_assignments+peephole). Reading of mwcc
 *   Coloring.c: nodes with degree >= K are pushed by lowest spill_cost/degree, popped last-first and
 *   take the lowest free colour. Both colourings are legal; in the build i is coloured before text
 *   (i takes r4, then text r5, v10 shares r4 with i, v2 shares r5 with text); the original colours
 *   text first. So the lever is i's cost/degree versus text's, not a declaration order. No human
 *   source form found that lowers i's cost or raises text's without changing the code.
 *   Matched-assembly search: halfword copy loops with a counter (asm/overlays, asm/arm9): only
 *   ov021 021CFB1C, ov093 021D54F4 (leaf copies) share the counter shape; neither shows the rule.
 *   pass 2 2026-10-06 P2L33 (35 compiles): EXACT in --lang c99 and --lang c. The text buffer is
 *   held as a u32 handle (the type TOUCHBAR_PrintAligned takes for its string argument, as the sibling
 *   ov128 021C9FC8 passes a u32 field), with (void *) at the pointer callees. A u32 local and a
 *   pointer local colour differently; with the u32 handle text takes r4 before the held constant
 *   10 and the loop counter, as in the original. Tried before this, no change: a local
 *   u16 digit array with an initialiser, explicit copy loops, inline helpers, statement order,
 *   prototype widths, loop/strength/unroll pragmas, a non-const table.
 */
void WF2DMAP_TOUCH_DrawFriendKey(u8 *p, u8 *q, u8 *ctx, u16 heap)
{
    u8 *w1;
    void *buf2;
    u32 gfx;
    u32 pal;
    u32 n;
    u32 text;
    u64 key;
    Tbl t;
    int x;
    int i;
    Wf2dmapFriend_CreateWindow(ctx, (u32 *)p, 3, 2, 10, 0x1e, 8, 10, 1, 0);
    Wf2dmapFriend_CreateWindow(ctx, (u32 *)(p + 8), 3, 9, 6, 0xe, 2, 10, 0xf1, 0);
    text = (u32)STRBUF_Create(0xc0, heap);
    buf2 = STRBUF_Create(0x80, heap);
    key = DWC_CreateFriendKey((struct DWCstAccUserData *)WIFILIST_GetWork((void *)GAME_DATA_GetWifiList(*(void **)(q + 4))));
    if (key != 0) {
        MSGDATA_ReadString(*(void **)(ctx + 4), 0x35, (void *)text);
        TOUCHBAR_PrintAligned(p, (void *)(*(u32 *)(ctx + 0x34)), 4, 0, text, *(u32 *)(ctx + 0x17c), 0x440, 0);
        WF2DMAP_TOUCH_TransferScreen(*(char **)p);
        pal = *(u32 *)(ctx + 0x17c);
        gfx = *(u32 *)(ctx + 0x34);
        t = gWf2dmapCursorTileTable;
        x = 0;
        n = BMP_WIN_GetWidth(*(void **)(p + 8));
        w1 = Wf2dmapTouchSecondWindow(p);
        for (i = 1; i <= 12; i++) {
            STRBUF_Clear((void *)text);
            STRBUF_AppendChar((void *)text, t.v[key % 10]);
            TOUCHBAR_PrintAligned(w1, (void *)gfx, (n - i) * 8 - x + 1, 0, text, pal, 0x3c40, 0);
            if (i % 4 == 0)
                x += 8;
            key = key / 10;
        }
        WF2DMAP_TOUCH_TransferScreen(*(char **)(p + 8));
    } else {
        MSGDATA_ReadString(*(void **)(ctx + 4), 0x36, (void *)text);
        TOUCHBAR_PrintAligned(p, (void *)(*(u32 *)(ctx + 0x34)), 4, 0, text, *(u32 *)(ctx + 0x17c), 0x440, 0);
        WF2DMAP_TOUCH_TransferScreen(*(char **)p);
    }
    STRBUF_Delete((void *)text);
    STRBUF_Delete(buf2);
    *(void **)(p + 0x10) = ARC_UTIL_LoadPaletteDataFromHandle(*(void **)(ctx + 8), 6, 0, (void **)(p + 0x14), heap);
}

void WF2DMAP_TOUCH_DeleteScreens(char *p,int unused,char *q) { WF2DMAP_TOUCH_ClearSlotArray(q);WF2DMAP_TOUCH_AddSlot(q,q+12);BMP_WIN_Delete(((Wf2dmapTouchWindowSet *)p)->windowA);BMP_WIN_Delete(((Wf2dmapTouchWindowSet *)p)->windowB);GFL_HEAP_Free(((Wf2dmapTouchWindowSet *)p)->archive);}

void WF2DMAP_TOUCH_InitGfx(char *p,char *q,char *r) {
 char *s;
 WORDSET_SetSlotMyStatus(((Wf2dmapTouchGfx *)r)->wordSet,0,GAME_DATA_GetMyStatus(((Wf2dmapTouchFriendData *)q)->saveData));
 Wf2dmapFriend_DrawText((u8 *)r,(u8 *)(r+12),50);
 s=*(char * *)&((Wf2dmapTouchWindowSet *)p)->bitmap;
 BG_SYS_DrawTile(2,(void *)(s+12),0,0,(((Wf2dmapBitmapHeader *)s)->width>>3)&255,(((Wf2dmapBitmapHeader *)s)->height>>3)&255);
 BG_SYS_MarkTileDirty(2);
}

void WF2DMAP_TOUCH_ClearScreens(char *p,void *q) {
 void *v;
 Wf2dmapFriend_ClearWindow(q);
 BG_SYS_SetTileEntry(2,0,0,0,32,24,0);BG_SYS_MarkTileDirty(2);
 v=((Wf2dmapTouchWindowSet *)p)->windowA;BMP_WIN_ClearScreen(v);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(v));
 v=((Wf2dmapTouchWindowSet *)p)->windowB;BMP_WIN_ClearScreen(v);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(v));
 BG_SYS_SetTileEntry(3,0,0,0,32,24,0);BG_SYS_MarkTileDirty(3);
}

void WF2DMAP_TOUCH_StartFriendEdit(u8 *p,u8 *b,u8 *c,u16 d) { ((Wf2dmapTouchEdit *)p)->direction=1; WF2DMAP_TOUCH_CreateEditWidgets(p,b,c,d); }

int WF2DMAP_TOUCH_FriendEditScreen(u8 *p,u8 *q,u8 *r,u16 heap)
{
    switch(q[8]) {
    case 0:
        ((Wf2dmapTouchEdit *)p)->flagE=0; ((Wf2dmapTouchEdit *)p)->value=0;
    case 1:
        WF2DMAP_TOUCH_StartFriendEdit(p,q,r,heap);
        WF2DMAP_TOUCH_InitEditScreen(p,q,r,heap);
        q[8]=2;
        break;
    case 2: q[8]=WF2DMAP_TOUCH_GetMenuInput(p,(int *)q,(char *)r); break;
    case 3:
        WF2DMAP_TOUCH_StartEditAnim((char *)p,q,r,heap);
        WF2DMAP_TOUCH_StepSlideIn(p,q,r,heap);
        q[8]=4; break;
    case 4: if(WF2DMAP_TOUCH_StepSlideIn(p,q,r,heap)==1)q[8]=5; break;
    case 5:
        if(PRINTSYS_QUE_IsFinished(((Wf2dmapTouchGfx *)r)->printWin)==1) {
            BG_SYS_ChangeScroll(2,0,0);BG_SYS_ChangeScroll(3,0,0);q[8]=2;
        } break;
    case 6:
        if(((Wf2dmapTouchEdit *)p)->flagE) {
            --((Wf2dmapTouchEdit *)p)->timer;
            if(((Wf2dmapTouchEdit *)p)->timer)break;
        }
        if(WF2DMAP_TOUCH_FindPrevEntry(q,((Wf2dmapTouchEdit *)p)->variant)) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            WF2DMAP_TOUCH_ReleaseEditWidgets((char *)p,r);
            Wf2dmapFriend_SetState(q,4,1);
            ((Wf2dmapTouchEdit *)p)->flagE=1;
            WF2DMAP_TOUCH_DeleteEditWidgets(p,q,r);
            return 1;
        } else q[8]=2;
        break;
    case 7:
        if(CLACT_IsActorAnimActive(((Wf2dmapTouchGfx *)r)->actorA)!=1) {
            WF2DMAP_TOUCH_CloseEditScreen(p,r);
            Wf2dmapFriend_SetState(q,1,11);
            WF2DMAP_TOUCH_DeleteEditWidgets(p,q,r);
            return 1;
        } break;
    case 8: if(CLACT_IsActorAnimActive(((Wf2dmapTouchGfx *)r)->actorB)!=1)q[8]=9; break;
    case 9: WIPE_SYS_Start(0,0,0,0,6,1,heap);q[8]=10;break;
    case 10: if(WIPE_SYS_EndCheck()) {
        Wf2dmapFriend_SetState(q,6,0);WF2DMAP_TOUCH_DeleteEditWidgets(p,q,r);return 1;
        }break;
    }
    return 0;
}

int WF2DMAP_TOUCH_SelectMenu(char *p,void *q,void *r,int n) {
 switch(n) {
 case 0:GFL_USE_PlaySeDefaultVolume(0x551);WF2DMAP_TOUCH_PlayActorAnimA(r);return 7;
 case 1:GFL_USE_PlaySeDefaultVolume(0x556);WF2DMAP_TOUCH_PlayActorAnimB(r);return 8;
 case 2:if(WF2DMAP_TOUCH_FindNextEntry(q,0)==1) {((Wf2dmapTouchEdit *)p)->timer=4;((Wf2dmapTouchEdit *)p)->variant=0;Wf2dmapFriend_RestartActorAnim(r,1,11);return 6;}break;
 case 3:if(WF2DMAP_TOUCH_FindNextEntry(q,1)==1) {((Wf2dmapTouchEdit *)p)->timer=4;((Wf2dmapTouchEdit *)p)->variant=1;Wf2dmapFriend_RestartActorAnim(r,0,10);return 6;}break;
 }
 return 2;
}

int WF2DMAP_TOUCH_GetMenuKeyInput(void *p,int *q,void *r) {
 if(*q==1 && (KEY_GetTrg()&0xcf3)) {UI_SetInputMode(0);*q=0;}
 if(KEY_GetTrg()&2)return WF2DMAP_TOUCH_SelectMenu(p,q,r,0);
 if(KEY_GetTrg()&1024)return WF2DMAP_TOUCH_SelectMenu(p,q,r,1);
 if(KEY_GetCont()&64)return WF2DMAP_TOUCH_SelectMenu(p,q,r,2);
 if(KEY_GetCont()&128)return WF2DMAP_TOUCH_SelectMenu(p,q,r,3);
 return 2;
}

int WF2DMAP_TOUCH_GetMenuTouchInput(void *p,void *q,void *r,int *flag) {
 int v=TOUCHPANEL_HitTrg(gWf2dmapEditHitRects);
 if(v==-1)return 2;
 *flag=1;
 if(v==0)return WF2DMAP_TOUCH_SelectMenu(p,q,r,3);
 if(v==1)return WF2DMAP_TOUCH_SelectMenu(p,q,r,2);
 if(v==2)return WF2DMAP_TOUCH_SelectMenu(p,q,r,0);
 return WF2DMAP_TOUCH_SelectMenu(p,q,r,1);
}

int WF2DMAP_TOUCH_GetMenuInput(void *p,int *q,char *r) {
 int flag=0; int ret;
 if(!PRINTSYS_QUE_IsFinished(((Wf2dmapTouchGfx *)r)->printWin)) return 2;
 ret=WF2DMAP_TOUCH_GetMenuTouchInput(p,q,r,&flag);
 if(flag) {UI_SetInputMode(1); *q=1; return ret;}
 return WF2DMAP_TOUCH_GetMenuKeyInput(p,q,r);
}

void WF2DMAP_TOUCH_StartEditAnim(char *p, void *q, void *r, int s) {
 int mode;
 ((Wf2dmapTouchEdit *)p)->slideStep=0;
 Wf2dmapFriend_SetActorAutoAnim(r,0);
 mode=(((Wf2dmapTouchEdit *)p)->variant==2)?2:1;
 WF2DMAP_TOUCH_SetValue((u16 *)p,q,r,mode,((Wf2dmapTouchEdit *)p)->value,s);
 GFL_USE_PlaySeDefaultVolume(0x548);
}

/*
 * extent: two-byte zero padding at 021C9626 before next label 021C9628.
 */
int WF2DMAP_TOUCH_StepSlideIn(u8 *p,void *a,void *b,int c)
{
    int value=((Wf2dmapTouchEdit *)p)->slideStep;
    int offset;
    if(value>8) {
        WF2DMAP_TOUCH_SetValue((u16 *)p,a,b,0,((Wf2dmapTouchEdit *)p)->value,c);
        Wf2dmapFriend_SetActorAutoAnim(b,1);
        WF2DMAP_TOUCH_DrawSlider(p,b,255);
        return 1;
    }
    offset=(value*256)/8;
    if(((Wf2dmapTouchEdit *)p)->variant==2) offset=-offset;
    BG_SYS_ChangeScrollImmediate(3,0,offset);
    ((Wf2dmapTouchEdit *)p)->slideStep=((Wf2dmapTouchEdit *)p)->slideStep+1;
    return 0;
}

static inline int Wf2dmapTouchAbsolute(s16 value) { if (value < 0) return -value; return value; }

/*
 * note 2026-10-05: the matched callees WF2DMAP_TOUCH_InitTileRecord and WF2DMAP_TOUCH_SetTileRecordField declare 4 parameters,
 *   but this caller passes the heap id as a stack argument (5th for 9ED0, 6th for 9EF4); the
 *   prototypes below carry the real arity. The heap id is u16 here and in all callee prototypes
 *   (narrow param puts its home store first); the inner counter is long.
 */
void WF2DMAP_TOUCH_CreateEditWidgets(u8 *p, void *unused, u8 *q, u16 heap)
{
    int i, k, x, y; long j;
    const s16 *row;
    WF2DMAP_TOUCH_CreateWidgetHandles(p + 0xf8, q, heap);
    WF2DMAP_TOUCH_CreateTileWidgets(p, q);
    for (k = 0; k < 2; k++) {
        row = gWf2dmapEntryPositions[k];
        y = Wf2dmapTouchAbsolute(row[1]);
        x = Wf2dmapTouchAbsolute(row[0]);
        Wf2dmapFriend_CreateWindow(q, (u32 *)(p + 0x118 + k * 8), 3, (u8)(x + 2), y + 1, 26, 18, 10, 0, 0);
    }
    for (i = 0; i < 3; i++) {
        WF2DMAP_TOUCH_InitTileRecord((u32)(p + 20 + i * 0x4c), (int)q, (const u16 *)gWf2dmapEntryPositions[i], gWf2dmapTileValues[i], heap);
        for (j = 0; j < 8; j++) {
            WF2DMAP_TOUCH_SetTileRecordField((u32)(p + 20 + i * 0x4c), (int)q, j, gWf2dmapTileItemIds[j], gWf2dmapTileItemValues[j], heap);
            *(void **)(p + 0x20 + j * 4) = p + 0x118;
            *(void **)(p + 0x6c + j * 4) = p + 0x120;
            *(void **)(p + 0xb8 + j * 4) = p + 0x120;
        }
    }
}

/*
 * extent: two-byte zero padding at 021C979E before next label 021C97A0.
 */
void WF2DMAP_TOUCH_DeleteEditWidgets(u8 *p,void *unused,u8 *q)
{
    u8 *base;
    int j;
    int i;
    WF2DMAP_TOUCH_ClearSlotArray((char *)q);
    WF2DMAP_TOUCH_AddSlot((char *)q,q+12);
    base=p+20;
    for(i=0;i<3;i++) {
        for(j=0;j<8;j++) WF2DMAP_TOUCH_ClearTileRecord((Wf2dmapTouchTileRecord *)(base+i*76), j);
        WF2DMAP_TOUCH_Noop(base+i*76);
    }
    for(i=0;i<2;i++) BMP_WIN_Delete(*(void **)(p+i*8+0x118));
    WF2DMAP_TOUCH_DeleteTileScreens(p,q);
    p+=0xf8;
    WF2DMAP_TOUCH_DeleteWidgetHandles(p);
}

/*
 * lever: u16 heap keeps its word spill before the first indexed load.
 */
void WF2DMAP_TOUCH_InitEditScreen(u8 *p,u8 *q,u8 *r,u16 heap)
{
    u16 *t;
    Wf2dmapFriend_PrintMyStatus(r,(u8 *)q,(q+((Wf2dmapTouchFriendData *)q)->index)[24],heap);
    Wf2dmapFriend_DrawText(r,r+12,13);
    t=*(u16 * *)&((Wf2dmapTouchEdit *)p)->widget[0].bitmap;
    BG_SYS_DrawTile(0,(void *)((u8 *)t+12),0,0,(u32)t[0]>>3,(u32)t[1]>>3);
    BG_SYS_MarkTileDirty(0);
    t=*(u16 * *)&((Wf2dmapTouchEdit *)p)->widget[1].bitmap;
    BG_SYS_DrawTile(2,(void *)((u8 *)t+12),0,0,(u32)t[0]>>3,(u32)t[1]>>3);
    BG_SYS_MarkTileDirty(2);
    WF2DMAP_TOUCH_CreateTrainerWidgets(p,(u8 *)q,r,heap);
    WF2DMAP_TOUCH_SetValue((u16 *)p,(u8 *)q,r,0,((Wf2dmapTouchEdit *)p)->value,heap);
    if(WF2DMAP_TOUCH_FindNextEntry((u8 *)q,0)==1) {
        Wf2dmapFriend_RestartActorAnim(r,1,3);
        Wf2dmapFriend_RestartActorAnim(r,0,2);
    } else {
        Wf2dmapFriend_RestartActorAnim(r,1,17);
        Wf2dmapFriend_RestartActorAnim(r,0,16);
    }
    Wf2dmapFriend_SetActorDrawEnable(r,1);
}

void WF2DMAP_TOUCH_CloseEditScreen(u8 *p,u8 *q)
{
    u16 *t;
    Wf2dmapFriend_SetActorDrawEnable(q,0);
    WF2DMAP_TOUCH_DrawCursorBg(p,q);
    WF2DMAP_TOUCH_ClearTrainerScreens((u32)p);
    BG_SYS_SetTileEntry(2,0,0,0,32,32,0);
    BG_SYS_MarkTileDirty(2);
    t=*(u16 * *)&((Wf2dmapTouchEdit *)p)->widget[2].bitmap;
    BG_SYS_DrawTile(0,(void *)((u8 *)t+12),0,0,(u32)t[0]>>3,(u32)t[1]>>3);
    BG_SYS_MarkTileDirty(0);
    Wf2dmapFriend_ClearWindow(q);
    WF2DMAP_TOUCH_ReleaseActor((int *)p);
}

void WF2DMAP_TOUCH_ReleaseEditWidgets(char *p,u8 *q) {char *base;int i;i=0;base=p+20;for(;i<3;i++) WF2DMAP_TOUCH_ClearAllScreens(base+i*76,q);Wf2dmapFriend_ClearWindow(q);WF2DMAP_TOUCH_ReleaseActor((int *)p);}

/*
 * calls: 0202DA18/48 and 0204B294 leave the consumed handle in r0 despite
 * their void declarations. Heap externs are widened when no truncation
 * occurs. 0202DA04's legacy a1-a3 are neither read nor forwarded.
 * bounds: two unsigned loops cover ten eight-byte records at p+0x128;
 * signed q[11] accesses retain modular address arithmetic.
 */
void WF2DMAP_TOUCH_CreateTrainerWidgets(u8 *p,u8 *q,u8 *ctx,u16 heap)
{
    u32 i,base,id,archive,offset;
    int pos;
    Bounds bounds;
    base=(unsigned int)GAME_DATA_GetWifiList(((Wf2dmapTouchFriendData *)q)->saveData);
    WIFILIST_GetFriendInfoField((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((Wf2dmapTouchFriendData *)q)->index+24),9);
    for(i=0;i<10;i++) BMP_Clear(BMP_WIN_GetBmp(*(void **)(p+i*8+0x128)),0);
    offset=0x128;
    pos=BMP_WIN_GetDispWidth(*(void **)(p+offset));
    TOUCHBAR_PrintYesNoCancelLabels((u32)(p+offset),(void *)(*(u32 *)&((Wf2dmapTouchGfx *)ctx)->printWin),*(u32 *)&((Wf2dmapTouchGfx *)ctx)->palWin,
        (int)((u32)pos*8)/2,0,0x3C40,
        *(u8 *)((u32)q+((Wf2dmapTouchFriendData *)q)->index+0x38)+1,((Wf2dmapTouchFriendData *)q)->nextColor,heap);
    WF2DMAP_TOUCH_PrintItem(p+(offset+8),q,ctx,19,0,0,0x3C40);
    WF2DMAP_TOUCH_PrintItem(p+(offset+16),q,ctx,20,0,0,0x3C40);
    WF2DMAP_TOUCH_PrintItem(p+0x140,q,ctx,21,0,0,0x3C40);
    Wf2dmapFriend_SetWordSlot((char **)ctx,WIFILIST_GetFriendInfoField((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((Wf2dmapTouchFriendData *)q)->index+24),2));
    WF2DMAP_TOUCH_PrintItem(p+(offset+32),q,ctx,22,0,0,0x3C40);
    Wf2dmapFriend_SetWordSlot((char **)ctx,WIFILIST_GetFriendInfoField((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((Wf2dmapTouchFriendData *)q)->index+24),3));
    WF2DMAP_TOUCH_PrintItem(p+0x150,q,ctx,22,0,0,0x3C40);
    WF2DMAP_TOUCH_PrintItem(p+(offset+48),q,ctx,23,0,0,0x3C40);
    Wf2dmapFriend_SetWordSlot((char **)ctx,WIFILIST_GetFriendInfoField((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((Wf2dmapTouchFriendData *)q)->index+24),4));
    WF2DMAP_TOUCH_PrintItem(p+0x160,q,ctx,24,0,0,0x3C40);
    WF2DMAP_TOUCH_PrintItem(p+(offset+=64),q,ctx,27,0,0,0x3C40);
    if(Wf2dmapFriend_PrintTrainerStats(ctx,q,*(u8 *)((u32)q+((Wf2dmapTouchFriendData *)q)->index+24))!=0)
        WF2DMAP_TOUCH_PrintItem(p+0x170,q,ctx,28,0,0,0x3C40);
    else BMP_WIN_TransferChars(((Wf2dmapTouchEdit *)p)->trainerWindow[9].handle);
    for(i=0;i<10;i++) WF2DMAP_TOUCH_TransferScreen(*(char **)(p+i*8+0x128));
    bounds=gWf2dmapTrainerActorBounds;
    id=CURSOR_MOVE_GetTableGroup(WIFILIST_GetFriendInfoField((const struct Sub020097BCObj *)base,*(u8 *)((u32)q+((Wf2dmapTouchFriendData *)q)->index+24),8));
    archive=POKEGRA_OpenTrainerHandle(heap);
    ((Wf2dmapTouchEdit *)p)->cgr=POKEGRA_RegisterTrainerCgr(archive,id,0,heap);
    ((Wf2dmapTouchEdit *)p)->palette=POKEGRA_RegisterTrainerPalette(archive,id,0,192,heap);
    ((Wf2dmapTouchEdit *)p)->cellAnim=POKEGRA_RegisterTrainerCellAnim(id,2,0,heap);
    ARC_TOOL_DeleteHandle((void *)archive);
    ((Wf2dmapTouchEdit *)p)->cursorBmp=(u32)CLACT_CreateActor((void *)((Wf2dmapTouchGfx *)ctx)->actorBank,((Wf2dmapTouchEdit *)p)->cgr,
        ((Wf2dmapTouchEdit *)p)->palette,((Wf2dmapTouchEdit *)p)->cellAnim,&bounds,0,heap);
}

void WF2DMAP_TOUCH_ClearTrainerScreens(u32 p) { int i;void *q;for(i=0;i<10;i++) {q=*(void **)(p+296+i*8);BMP_WIN_ClearScreen(q);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(q));}}

void WF2DMAP_TOUCH_SetValue(u16 *p, void *b, void *c, int flag, int value, int unused) { if(flag==0) *p=value; }

/*
 * lever: the table value in r1 supplies both destination x and clip x;
 * raw u32 address arithmetic preserves base-plus-row accesses without
 * imposing unproven row or index bounds; all shifts/adds wrap at 32 bits.
 */
void WF2DMAP_TOUCH_DrawSlider(u8 *p,u8 *q,int idx)
{
    u16 *t;
    if (((Wf2dmapTouchEdit *)p)->direction==1) {
        t=*(u16 * *)&((Wf2dmapTouchGfx *)q)->bmpDesc[1];
        BG_SYS_DrawTileEx(2,0,20,32,4,(void *)((u8 *)t+12),0,12,(u32)t[0]>>3,(u32)t[1]>>3);
    } else {
        t=*(u16 * *)&((Wf2dmapTouchGfx *)q)->bmpDesc[1];
        BG_SYS_DrawTileEx(2,0,20,32,4,(void *)((u8 *)t+12),0,20,(u32)t[0]>>3,(u32)t[1]>>3);
    }
    if (idx==255) {
        BG_SYS_MarkTileDirty(2);
        return;
    }
    t=*(u16 * *)&((Wf2dmapTouchGfx *)q)->bmpDesc[1];
    BG_SYS_DrawTileEx(2,*(const u8 *)((u32)gWf2dmapSliderTileX+((u32)((Wf2dmapTouchEdit *)p)->direction<<3)+(u32)idx),20,
        *(const u8 *)((u32)gWf2dmapSliderTileY+((u32)((Wf2dmapTouchEdit *)p)->direction<<3)+(u32)idx),4,(void *)((u8 *)t+12),
        *(const u8 *)((u32)gWf2dmapSliderTileX+((u32)((Wf2dmapTouchEdit *)p)->direction<<3)+(u32)idx),
        *(const u8 *)((u32)gWf2dmapSliderFlags+(u32)((Wf2dmapTouchEdit *)p)->direction),(u32)t[0]>>3,(u32)t[1]>>3);
    BG_SYS_MarkTileDirty(2);
}

void WF2DMAP_TOUCH_DrawCursorBg(void *unused,u8 *p)
{
    u16 *q = *(u16 * *)&((Wf2dmapTouchEdit *)p)->cursorBmp;
    BG_SYS_DrawTileEx(2,0,20,32,4,(void *)((u8 *)q+12),0,28,(u32)q[0]>>3,(u32)q[1]>>3);
    BG_SYS_MarkTileDirty(2);
}

/*
 * extent: two-byte zero padding at 021C9D86 before next label 021C9D88.
 */
int WF2DMAP_TOUCH_FindPrevEntry(u8 *p,int direction)
{
    int index;
    u32 data;
    u32 count;
    data=(unsigned int)GAME_DATA_GetWifiList(((Wf2dmapTouchFriendData *)p)->saveData);
    index=((Wf2dmapTouchFriendData *)p)->index;
    if(direction==0) {
        for(count=0;count<((Wf2dmapTouchFriendData *)p)->count-1;count++) {
            index--;
            if(index<0) index+=((Wf2dmapTouchFriendData *)p)->count;
            if(WIFILIST_GetFriendInfoField((const struct Sub020097BCObj *)data,p[index+24],9)!=2) {
                p[11]=index;
                return 1;
            }
        }
    } else {
        for(count=0;count<((Wf2dmapTouchFriendData *)p)->count-1;count++) {
            index=(u32)(index+1)%((Wf2dmapTouchFriendData *)p)->count;
            if(WIFILIST_GetFriendInfoField((const struct Sub020097BCObj *)data,p[index+24],9)!=2) {
                p[11]=index;
                return 1;
            }
        }
    }
    return 0;
}

/*
 * extent: two-byte zero padding at 021C9E0E before next label 021C9E10.
 * lever: writing the reloaded signed byte on the left of == fixes both cmp operands.
 */
int WF2DMAP_TOUCH_FindNextEntry(u8 *p,int direction)
{
    int index;
    u32 data;
    u32 count;
    data=(unsigned int)GAME_DATA_GetWifiList(((Wf2dmapTouchFriendData *)p)->saveData);
    index=((Wf2dmapTouchFriendData *)p)->index;
    if(direction==0) {
        for(count=0;count<((Wf2dmapTouchFriendData *)p)->count-1;count++) {
            index--;
            if(index<0) index+=((Wf2dmapTouchFriendData *)p)->count;
            if(((Wf2dmapTouchFriendData *)p)->index==index) goto fail;
            if(WIFILIST_GetFriendInfoField((const struct Sub020097BCObj *)data,p[index+24],9)!=2) return 1;
        }
    } else {
        for(count=0;count<((Wf2dmapTouchFriendData *)p)->count-1;count++) {
            index=(u32)(index+1)%((Wf2dmapTouchFriendData *)p)->count;
            if(((Wf2dmapTouchFriendData *)p)->index==index) goto fail;
            if(WIFILIST_GetFriendInfoField((const struct Sub020097BCObj *)data,p[index+24],9)!=2) return 1;
        }
    }
fail:
    return 0;
}

void WF2DMAP_TOUCH_CreateWidgetHandles(u8 *p,u8 *q,u16 heap)
{
    u16 ids[4];
    int i;
    ids[0]=gWf2dmapWidgetFileIds[0]; ids[1]=gWf2dmapWidgetFileIds[1];
    ids[2]=gWf2dmapWidgetFileIds[2]; ids[3]=gWf2dmapWidgetFileIds[3];
    for(i=0;i<4;i++) {
        ((Wf2dmapTouchWidget *)p)->handle=ARC_UTIL_LoadPaletteDataFromHandle(((Wf2dmapTouchGfx *)q)->archive,ids[i],0,(void **)&((Wf2dmapTouchWidget *)p)->bitmap,heap);
        p+=8;
    }
}

/*
 * Addresses are Black-image addresses.
 */
void WF2DMAP_TOUCH_DeleteWidgetHandles(u8 *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        GFL_HEAP_Free(((Wf2dmapTouchWidget *)p)->handle);
        p += 8;
    }
}

void WF2DMAP_TOUCH_CreateTileWidgets(u8 *p,void *q)
{
    int i;
    p+=0x128;
    for(i=0;i<10;i++)
        Wf2dmapFriend_CreateWindow(q,(u32 *)(p+i*8),1,gWf2dmapTileWindowParams[i][0],gWf2dmapTileWindowParams[i][1],gWf2dmapTileWindowParams[i][2],gWf2dmapTileWindowParams[i][3],10,0,0);
}

void WF2DMAP_TOUCH_DeleteTileScreens(u8 *p, void *unused)
{
    int i;
    for (i = 0; i < 10; i++)
        BMP_WIN_Delete(*(void **)(p + 0x128 + i * 8));
}

void WF2DMAP_TOUCH_InitTileRecord(u32 p,int unused,const u16 *q,u32 value,u16 heap) { int i; ((Wf2dmapTouchTileRecord *)p)->value=value; ((Wf2dmapTouchTileRecord *)p)->x=q[0]; ((Wf2dmapTouchTileRecord *)p)->y=q[1]; ((Wf2dmapTouchTileRecord *)p)->z=q[2]; for(i=0;i<8;i++) *(u32 *)(p+44+i*4)=0; }

void WF2DMAP_TOUCH_Noop(void *unused) {}

void WF2DMAP_TOUCH_SetTileRecordField(u32 p,int unused,u32 index,u32 value,u32 unused5,u16 heap) { *(u32 *)(p+44+index*4)=value; }

/*
 * volatile: 021C9F1E rereads loop bound field, also entry021C9F0E.
 */
void WF2DMAP_TOUCH_ClearTileRecord(Wf2dmapTouchTileRecord *p,u32 index) {u8 i;if(p->items[index]){for(i=0;i<p->count[index];i++) {} p->items[index]=0;p->count[index]=0;}}

void WF2DMAP_TOUCH_ClearScreenAt(char *p,u32 index) {u32 i;void *q;char *base;base=p+index*4;for(i=0;i<((Wf2dmapTouchTileRecord *)base)->count[0];i++){BMP_Clear(BMP_WIN_GetBmp(**(void ** *)&((Wf2dmapTouchTileRecord *)base)->items[0]),0);q=**(void ** *)&((Wf2dmapTouchTileRecord *)base)->items[0];BMP_WIN_ClearScreen(q);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(q));}}

void WF2DMAP_TOUCH_ClearAllScreens(char *p,void *q) { int i; for(i=0;i<8;i++)WF2DMAP_TOUCH_ClearScreenAt(p,i);WF2DMAP_TOUCH_SetBgScroll(q,p); }

static inline int Wf2dmapTouchAbs(int x) { return x<0?-x:x; }

void WF2DMAP_TOUCH_SetBgScroll(void *q,char *p) { BG_SYS_SetTileEntry(3,0,Wf2dmapTouchAbs(((Wf2dmapTouchTileRecord *)p)->x),Wf2dmapTouchAbs(((Wf2dmapTouchTileRecord *)p)->y),32,24,0);BG_SYS_MarkTileDirty(3); }

void WF2DMAP_TOUCH_PrintItem(u8 *p,void *unused,u8 *q,u32 item,int x,int y,int color)
{
    MSGDATA_ReadString(((Wf2dmapTouchGfx *)q)->msgBank,item,((Wf2dmapTouchGfx *)q)->formatArg);
    WORDSET_CopyTaggedText(((Wf2dmapTouchGfx *)q)->wordSet,(void *)((Wf2dmapTouchGfx *)q)->textHandle,((Wf2dmapTouchGfx *)q)->formatArg);
    TOUCHBAR_PrintAligned(p,(void *)(*(u32 *)&((Wf2dmapTouchGfx *)q)->printWin),x,y,((Wf2dmapTouchGfx *)q)->textHandle,*(u32 *)&((Wf2dmapTouchGfx *)q)->palWin,color,0);
}

/*
 * lever: initialize value before *ok; multiply and add the u64 digit separately;
 *        cast the u16 counter to int for its bound, and share failure via done.
 */
u64 WF2DMAP_TOUCH_ParseKey(void *p,int *ok)
{
    u16 end=STRBUF_GetEosChar();
    u16 *text=STRBUF_GetChars(p);
    u64 value;
    u16 i;
    u16 digit;
    value=0;
    *ok=0;
    i=0;
    while(text[i]!=end) {
        if((int)i>=18) goto done;
        digit=(u16)(text[i]-0x30);
        if(digit>=10) {
            digit=(u16)(text[i]-0xff10);
            if(digit>=10) goto done;
        }
        value*=10;
        value+=(u64)digit;
        i++;
    }
    *ok=1;
done:
    return value;
}

/*
 * extent: two trailing bytes of zero alignment padding.
 */
int WF2DMAP_TOUCH_GetConfirmInput(int *p) { if(TOUCHPANEL_GetTrg()==1) {UI_SetInputMode(1);*p=1;return 1;} if(KEY_GetTrg()&3) {UI_SetInputMode(0);*p=0;return 1;} return 0; }

void WF2DMAP_TOUCH_CreatePalAnims(u8 *p,u16 heap)
{
    ((Wf2dmapTouchGfx *)p)->palAnimA=BLINK_PALANM_Create(48,16,0,heap);
    BLINK_PALANM_LoadPalettes(((Wf2dmapTouchGfx *)p)->palAnimA,*(u8 * *)&((Wf2dmapTouchGfx *)p)->archive,0,32,48);
    ((Wf2dmapTouchGfx *)p)->palAnimB=BLINK_PALANM_Create(16,16,0xfffe,heap);
    BLINK_PALANM_LoadPalettes(((Wf2dmapTouchGfx *)p)->palAnimB,*(u8 * *)&((Wf2dmapTouchGfx *)p)->archive,2,0,16);
}

void WF2DMAP_TOUCH_DeletePalAnims(u8 *p)
{
    BLINK_PALANM_Delete(((Wf2dmapTouchGfx *)p)->palAnimB);
    BLINK_PALANM_Delete(((Wf2dmapTouchGfx *)p)->palAnimA);
}

void WF2DMAP_TOUCH_DrawTopHighlight(u32 a,u32 b) {BG_SYS_FillTileMap(2,2,(a+1)*5,28,4,b);BG_SYS_MarkTileDirty(2);}

void WF2DMAP_TOUCH_SetTopHighlight1(u8 *p, int a)
{
    WF2DMAP_TOUCH_DrawTopHighlight(a, 1);
    BLINK_PALANM_ResetPhase(((Wf2dmapTouchGfx *)p)->palAnimA);
}

void WF2DMAP_TOUCH_SetTopHighlight3(u8 *p, int a)
{
    WF2DMAP_TOUCH_DrawTopHighlight(a, 3);
    BLINK_PALANM_ResetPhase(((Wf2dmapTouchGfx *)p)->palAnimA);
}

void WF2DMAP_TOUCH_SetTopHighlight(u8 *p, int a, int b)
{
    WF2DMAP_TOUCH_SetTopHighlight1(p, b);
    WF2DMAP_TOUCH_SetTopHighlight3(p, a);
}

/*
 * extent: two-byte zero padding at 021CA1DE; next labelled function 021CA1E0.
 */
void WF2DMAP_TOUCH_UpdateTopBar(unsigned *p)
{
    unsigned i;
    if(UI_GetInputMode()==1) {
        for(i=0;i<3;i++) WF2DMAP_TOUCH_DrawTopHighlight(i,1);
        return;
    }
    for(i=0;i<3;i++) {
        if(i==*p) WF2DMAP_TOUCH_DrawTopHighlight(i,3);
        else WF2DMAP_TOUCH_DrawTopHighlight(i,1);
    }
}

/*
 * Extent ends with two bytes of zero alignment padding.
 */
int WF2DMAP_TOUCH_StepTopBarBlink(char *p)  {
    switch(((Wf2dmapFriendListScreen *)p)->blinkState)  {
        case 0: WF2DMAP_TOUCH_DrawTopHighlight((u32)(((Wf2dmapFriendListScreen *)p)->highlight),1);
        ((Wf2dmapFriendListScreen *)p)->blinkTimer=0;
        (((Wf2dmapFriendListScreen *)p)->blinkState)++;
        break;
        case 1: (((Wf2dmapFriendListScreen *)p)->blinkTimer)++;
        if(((Wf2dmapFriendListScreen *)p)->blinkTimer==4)  {
            WF2DMAP_TOUCH_DrawTopHighlight((u32)(((Wf2dmapFriendListScreen *)p)->highlight),2);
            ((Wf2dmapFriendListScreen *)p)->blinkTimer=0;
            (((Wf2dmapFriendListScreen *)p)->blinkState)++;
        }
        break;
        case 2: (((Wf2dmapFriendListScreen *)p)->blinkTimer)++;
        if(((Wf2dmapFriendListScreen *)p)->blinkTimer==4)  {
            WF2DMAP_TOUCH_DrawTopHighlight((u32)(((Wf2dmapFriendListScreen *)p)->highlight),1);
            ((Wf2dmapFriendListScreen *)p)->blinkTimer=0;
            (((Wf2dmapFriendListScreen *)p)->blinkState)++;
        }
        break;
        case 3: (((Wf2dmapFriendListScreen *)p)->blinkTimer)++;
        if(((Wf2dmapFriendListScreen *)p)->blinkTimer==4)  {
            WF2DMAP_TOUCH_DrawTopHighlight((u32)(((Wf2dmapFriendListScreen *)p)->highlight),2);
            ((Wf2dmapFriendListScreen *)p)->blinkTimer=0;
            (((Wf2dmapFriendListScreen *)p)->blinkState)++;
        }
        break;
        case 4: (((Wf2dmapFriendListScreen *)p)->blinkTimer)++;
        if(((Wf2dmapFriendListScreen *)p)->blinkTimer==4)  {
            ((Wf2dmapFriendListScreen *)p)->blinkState=0;
            ((Wf2dmapFriendListScreen *)p)->blinkTimer=0;
            return 0;
        }
        break;
    }
    return 1;
}

void WF2DMAP_TOUCH_DrawItemHighlight(u32 a,u32 b) {BG_SYS_FillTileMap(2,(a>>2)*14+2,(a&3)*4+4,14,4,b);BG_SYS_MarkTileDirty(2);}

void WF2DMAP_TOUCH_SetItemHighlight1(u8 *p, int a)
{
    WF2DMAP_TOUCH_DrawItemHighlight(a, 1);
    BLINK_PALANM_ResetPhase(((Wf2dmapTouchGfx *)p)->palAnimA);
}

void WF2DMAP_TOUCH_SetItemHighlight3(u8 *p, int a)
{
    WF2DMAP_TOUCH_DrawItemHighlight(a, 3);
    BLINK_PALANM_ResetPhase(((Wf2dmapTouchGfx *)p)->palAnimA);
}

void WF2DMAP_TOUCH_SetItemHighlight(u8 *p, int a, int b)
{
    WF2DMAP_TOUCH_SetItemHighlight1(p, b);
    WF2DMAP_TOUCH_SetItemHighlight3(p, a);
}

void WF2DMAP_TOUCH_UpdateItemBar(char *p)  {
    unsigned i;
    if(UI_GetInputMode()==1)  {
        for(i=0;i<8;i++) WF2DMAP_TOUCH_DrawItemHighlight(i,1);
    }
    else  {
        for(i=0;i<8;i++)  {
            if(i==((Wf2dmapFriendItemScreen *)p)->cursor) WF2DMAP_TOUCH_DrawItemHighlight(i,3);
            else WF2DMAP_TOUCH_DrawItemHighlight(i,1);
        }
    }
}

int WF2DMAP_TOUCH_StepItemBarBlink(char *p)  {
    switch(((Wf2dmapFriendItemScreen *)p)->blinkState)  {
        case 0: WF2DMAP_TOUCH_DrawItemHighlight(((Wf2dmapFriendItemScreen *)p)->cursor,1);
        ((Wf2dmapFriendItemScreen *)p)->blinkTimer=0;
        (((Wf2dmapFriendItemScreen *)p)->blinkState)++;
        break;
        case 1: (((Wf2dmapFriendItemScreen *)p)->blinkTimer)++;
        if(((Wf2dmapFriendItemScreen *)p)->blinkTimer==4)  {
            WF2DMAP_TOUCH_DrawItemHighlight(((Wf2dmapFriendItemScreen *)p)->cursor,2);
            ((Wf2dmapFriendItemScreen *)p)->blinkTimer=0;
            (((Wf2dmapFriendItemScreen *)p)->blinkState)++;
        }
        break;
        case 2: (((Wf2dmapFriendItemScreen *)p)->blinkTimer)++;
        if(((Wf2dmapFriendItemScreen *)p)->blinkTimer==4)  {
            WF2DMAP_TOUCH_DrawItemHighlight(((Wf2dmapFriendItemScreen *)p)->cursor,1);
            ((Wf2dmapFriendItemScreen *)p)->blinkTimer=0;
            (((Wf2dmapFriendItemScreen *)p)->blinkState)++;
        }
        break;
        case 3: (((Wf2dmapFriendItemScreen *)p)->blinkTimer)++;
        if(((Wf2dmapFriendItemScreen *)p)->blinkTimer==4)  {
            WF2DMAP_TOUCH_DrawItemHighlight(((Wf2dmapFriendItemScreen *)p)->cursor,2);
            ((Wf2dmapFriendItemScreen *)p)->blinkTimer=0;
            (((Wf2dmapFriendItemScreen *)p)->blinkState)++;
        }
        break;
        case 4: (((Wf2dmapFriendItemScreen *)p)->blinkTimer)++;
        if(((Wf2dmapFriendItemScreen *)p)->blinkTimer==4)  {
            ((Wf2dmapFriendItemScreen *)p)->blinkState=0;
            ((Wf2dmapFriendItemScreen *)p)->blinkTimer=0;
            return 0;
        }
        break;
    }
    return 1;
}

void WF2DMAP_TOUCH_PlayActorAnimA(char *p) {CLACT_SetActorAnimFrame(((Wf2dmapTouchGfx *)p)->actorA,0);CLACT_SetActorAnimSeq(((Wf2dmapTouchGfx *)p)->actorA,9);CLACT_SetActorAutoAnim(((Wf2dmapTouchGfx *)p)->actorA,1);}

void WF2DMAP_TOUCH_PlayActorAnimB(char *p) {CLACT_SetActorAnimFrame(((Wf2dmapTouchGfx *)p)->actorB,0);CLACT_SetActorAnimSeq(((Wf2dmapTouchGfx *)p)->actorB,8);CLACT_SetActorAutoAnim(((Wf2dmapTouchGfx *)p)->actorB,1);}

void WF2DMAP_TOUCH_SetScreenBrightness(int a) {if(a==1)G2x_SetBlendBrightness_(0x04000050,28,0);else G2x_SetBlendBrightness_(0x04000050,28,-8);}

void WF2DMAP_TOUCH_SetActorAnimSeq(char *p, int n) {CLACT_SetActorAnimFrame(((Wf2dmapFriendItemScreen *)p)->actor2,0);CLACT_SetActorAnimSeq(((Wf2dmapFriendItemScreen *)p)->actor2,n+2);}

void WF2DMAP_TOUCH_MakeScreen(char *p)
{
    BMP_WIN_MakeScreen(((Wf2dmapTouchGfx *)p)->window);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(((Wf2dmapTouchGfx *)p)->window));
}

void WF2DMAP_TOUCH_ClearSlotArray(char *p)
{
    unsigned int i;

    for (i = 0; i < 0x40; i++)
        *(unsigned int *)(p + i * 4 + 0x38) = 0;
}

void WF2DMAP_TOUCH_AddSlot(char *p,void *q) {u32 i;for(i=0;i<64;i++) {if(!*(void **)(p+i*4+56)) {*(void **)(p+i*4+56)=q;return;}}}

void WF2DMAP_TOUCH_UpdateSlots(char *p) {u32 i;char *q;void *v;for(i=0;i<64;i++){q=*(char **)(p+i*4+56);if(!q)break;v=((Wf2dmapTouchGfx *)p)->printWin;if(((Wf2dmapTouchSlot *)q)->dirty) {if(!PRINTSYS_QUE_IsExistTarget(v,BMP_WIN_GetBmp(((Wf2dmapTouchSlot *)q)->window))) {BMP_WIN_TransferChars(((Wf2dmapTouchSlot *)q)->window);((Wf2dmapTouchSlot *)q)->dirty=0;}}}}

void WF2DMAP_TOUCH_TransferScreen(char *p)
{
    BMP_WIN_MakeScreen((struct BmpWin *)p);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)p));
}

void WF2DMAP_TOUCH_ReleaseActor(int *p)
{
    CLACT_ReleaseCharacter(p[95]);
    CLACT_ReleasePalette(p[96]);
    CLACT_ReleaseCellAnim(p[97]);
    CLACT_DeleteActor((struct Actor *)p[94]);
}

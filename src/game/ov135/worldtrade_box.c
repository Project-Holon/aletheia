/*
 * file:     worldtrade_box.c
 * unit:     yes
 * function: WORLDTRADE_BOX_Init, WORLDTRADE_BOX_Main, WORLDTRADE_BOX_Exit, WORLDTRADE_BOX_SetupBgPlanes, WORLDTRADE_BOX_ExitBgPlanes, WORLDTRADE_BOX_LoadBgGraphics, WORLDTRADE_BOX_CreateActors, WORLDTRADE_BOX_DeleteActors, WORLDTRADE_BOX_CreateWindows, WORLDTRADE_BOX_DeleteWindows, WORLDTRADE_BOX_CreateStrings, WORLDTRADE_BOX_DeleteStrings, WORLDTRADE_BOX_StateWaitWipeIn, WORLDTRADE_BOX_SelectMonForOffer, WORLDTRADE_BOX_SelectMonForRequest, WORLDTRADE_BOX_CheckArrowTouch, WORLDTRADE_BOX_FinishByKind, WORLDTRADE_BOX_StateMainInput, WORLDTRADE_BOX_UpdateKeyCursor, WORLDTRADE_BOX_MoveCursorToSlot, WORLDTRADE_BOX_GetColumnIndex, WORLDTRADE_BOX_StateCreateOfferMenu, WORLDTRADE_BOX_StateOfferMenuInput, WORLDTRADE_BOX_StateCreateRequestMenu, WORLDTRADE_BOX_StateRequestMenuInput, WORLDTRADE_BOX_StateStartWipeOut, WORLDTRADE_BOX_StateOpenCancelConfirm, WORLDTRADE_BOX_StateCancelConfirmInput, WORLDTRADE_BOX_StatePrintDepositPrompt, WORLDTRADE_BOX_StateOpenDepositConfirm, WORLDTRADE_BOX_StateDepositConfirmInput, WORLDTRADE_BOX_TryConfirmDeposit, WORLDTRADE_BOX_StatePrintSelectPrompt, WORLDTRADE_BOX_StateOpenSelectConfirm, WORLDTRADE_BOX_StateSelectConfirmInput, WORLDTRADE_BOX_StateWaitCursorAnim, WORLDTRADE_BOX_StateWaitMessage, WORLDTRADE_BOX_StateWaitMessageOrKey, WORLDTRADE_BOX_PrintMessage, WORLDTRADE_BOX_LoadPokeIconChar, WORLDTRADE_BOX_LoadPokeIcon, WORLDTRADE_BOX_CalcLevel, WORLDTRADE_BOX_TransferIconPalette, WORLDTRADE_BOX_SetupIconActor, WORLDTRADE_BOX_LoadBoxIcons, WORLDTRADE_BOX_ClampSlot, WORLDTRADE_BOX_GetPartyMon, WORLDTRADE_BOX_GetMonCount, WORLDTRADE_BOX_CanRemoveMon, WORLDTRADE_BOX_GetBoxCount, WORLDTRADE_BOX_CheckMonRestrictionA, WORLDTRADE_BOX_CheckMonRestrictionB, WORLDTRADE_BOX_GetMonTradeState, WORLDTRADE_BOX_TagMatchesRequest, WORLDTRADE_BOX_MonMatchesRequest, WORLDTRADE_BOX_BuildDepositFromWork, WORLDTRADE_BOX_ScoreMatchingRecords, WORLDTRADE_BOX_IsSpeciesFlagged, WORLDTRADE_BOX_RestoreCursorSave
 * address:  0x021F5154
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from worldtrade_box.c, worldtrade_enter.c, worldtrade_adapter.c, WORLDTRADE_ADAPTER_QueueMessagePrint.c by tools/splitfile.py.
 *
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   DC_FlushRange  0x020862F0  arm
 *   func_02034714 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   WORLDTRADE_TITLE_ScrollBg 0x021FFFE8 thumb ov135
 *   WORLDTRADE_SUBLCD_SetSlotActorPositions 0x021FFD44 thumb ov135
 *   GXx_GetMasterBrightness_ 0x0207D55C arm
 *   WORLDTRADE_ENTER_RestartNetTimeout 0x021F9254 thumb ov135
 *   g_02203B0C  0x02203B0C  data  ov135
 *   WORLDTRADE_SUBLCD_SetSlotActorPositionsLower 0x021FFD74 thumb ov135
 *   WORLDTRADE_TITLE_ExitBgPlanes 0x022000E4 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BG_SYS_GetSubVisiblePlanes  0x02043668  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   func_02040588  0x02040588  arm
 *   BG_SYS_InitRun  0x02040B94  arm
 *   g_02202C94  0x02202C94  data  ov135
 *   g_02202CE4  0x02202CE4  data  ov135
 *   g_02202D04  0x02202D04  data  ov135
 *   g_02202CA4  0x02202CA4  data  ov135
 *   g_02202CC4  0x02202CC4  data  ov135
 *   BG_SYS_Delete_03F4  0x020403F4  arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   WORLDTRADE_TITLE_LoadMainBgSwap 0x02200AB4 thumb ov135
 *   WORLDTRADE_TITLE_LoadSubBgSwap 0x02200B34 thumb ov135
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   func_020355C4  0x020355C4  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_StopActorAnim  0x0204B974  arm
 *   tbl_02202D24   0x02202D24  data  a2
 *   tbl_02202C50   0x02202C50  data  a2
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   WORLDTRADE_INPUT_PrintStringAlignedLine  0x021F91A0  thumb
 *   WORLDTRADE_TITLE_CreateMenuWindow  0x02200BAC  thumb
 *   WORLDTRADE_ADAPTER_DeletePrintStream 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02030734 0x02030734 arm
 *   str_02203B54 0x02203B54 data a1
 *   WORLDTRADE_ADAPTER_CreateMonFromBox  0x022025E4  thumb
 *   tbl_02202E24  0x02202E24  data  a1
 *   tbl_02202DA4  0x02202DA4  data  a1
 *   d_02203B68 0x02203B68 data a4
 *   WORLDTRADE_ADAPTER_IsStreamDone  0x02202840  thumb  ov135
 *   MSGDATA_AllocString   0x02045EC0  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   unit_02045730  0x02045730  arm
 *   BG_SYS_PushTile   0x020409B4  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   WORLDTRADE_ADAPTER_QueuePrintDefaultColor  0x02202858  thumb  ov135
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   POKE_TOOL_CalcIconPalette  0x0201BB5C  thumb
 *   GX_LoadOBJ     0x0207E780  arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   FILE_UTIL_Check136C  0x0202136C  thumb
 *   func_02007A18  0x02007A18  thumb
 *   func_0200785C  0x0200785C  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   tbl_02202C58  0x02202C58  data  a4
 *   func_02017E1C  0x02017E1C  thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   POKE_TOOL_ChangeBoxForm  0x020179B8  thumb  arm9
 *   POKE_TOOL_CalcBoxLevel  0x02018438  thumb  arm9
 *   BMP_MENUWORK_Create  0x0201F81C  thumb  arm9
 *   BMP_MENUWORK_Delete  0x0201F868  thumb  arm9
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9
 *   TOUCHPANEL_HitTrg  0x02035C08  arm  arm9
 *   TOUCHPANEL_GetTrg  0x02035C60  arm  arm9
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm  arm9
 *   CLACT_IsActorAnimActive  0x0204B98C  arm  arm9
 *   CLACT_RestartActorAnim  0x0204B9A0  arm  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   WORLDTRADE_ClearBusyFlag  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   WORLDTRADE_SetActorPos  0x021F4FF4  thumb
 *   func_020355D8  0x020355D8  arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   WORLDTRADE_OpenTaskMenuList 0x021F4D50 thumb ov135
 *   WORLDTRADE_UpdateTaskMenuList 0x021F4E30 thumb ov135
 *   WORLDTRADE_CloseTaskMenuList 0x021F4E64 thumb ov135
 *   WORLDTRADE_BOX_IsSpeciesFlagged 0x021F6DE8 thumb ov135
 *   WORLDTRADE_SetActorSurfacePos 0x021F4EA0 thumb ov135
 *   WORLDTRADE_OpenTaskMenuYesNoDefault  0x021F4BE0  thumb  ov135
 *   WORLDTRADE_BOX_ClampSlot 0x021F6B34 thumb ov135
 *   WORLDTRADE_BOX_GetMonCount 0x021F6B80 thumb ov135
 *   WORLDTRADE_BOX_GetPartyMon 0x021F6B40 thumb ov135
 *   WORLDTRADE_DEPOSIT_BuildOffer 0x021F8554 thumb ov135
 *   NNS_G2dGetUnpackedCharacterDataEx  0x02062A4C  arm  arm9
 */
#include "worldtrade_types.h"

struct ArcFile;

struct NitroFileHeader;

struct Sav;

typedef struct {
    u16 x;
    u16 y;
} Pos_021F4580;

typedef struct {
    u8 pad0[0x14];
    void *pixels;
} CharData_p02;

typedef struct {
    s16 a;
    s16 b;
} Rec_p03;

typedef struct {
    u32 f0;
    int f4;
    u8 pad8[0x20C - 8];
} Entry_021F6DB4;

extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 WIPE_SYS_EndCheck(void);

extern u32 func_020307B0(void *p);

extern void func_02034714(const char *expr, u32 line, const char *file);

extern void *func_020490F4(u32 id, u32 heap);

extern void ARC_TOOL_DeleteHandle(void *h);

extern void DC_FlushRange(void *p, u32 size);

extern void *func_02045EC0(struct MsgBank *bank, u32 index);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void func_020409B4(u32 v);

extern void BG_SYS_SetSubVisiblePlanes(u32 a);

extern void BG_SYS_SetGraphicsMode(struct DispConfig_021F4580 *cfg);

extern void WORLDTRADE_TITLE_ScrollBg(Work *, u32, u32);

extern void WORLDTRADE_SUBLCD_SetSlotActorPositions(char *p);

extern int GXx_GetMasterBrightness_(volatile u16 *reg);

extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);

extern void WORLDTRADE_ENTER_RestartNetTimeout(u8 *);

extern void WORLDTRADE_SUBLCD_SetSlotActorPositionsLower(char *p);

extern void WORLDTRADE_TITLE_ExitBgPlanes(char *p);

extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

extern u32 BG_SYS_GetSubVisiblePlanes(void);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate_021F4580 *tmpl, u32 type);

extern void BG_SYS_ClearSlot(u32 i);

extern void func_02040588(unsigned char which, unsigned char enable);

extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);

extern void BG_SYS_Delete_03F4(u32 i);

extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);

extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void WORLDTRADE_TITLE_LoadMainBgSwap(Work *);

extern void WORLDTRADE_TITLE_LoadSubBgSwap(Work *);

extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);

extern void CLACT_SetActorAutoAnim(struct Obj *, u32);

extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

extern u8 func_020355C4(void);

extern void CLACT_SetActorBgPriority(u32, int);

extern void CLACT_StopActorAnim(struct Actor *a);

extern void CLACT_DeleteActor(struct Obj *p);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern int WORLDTRADE_INPUT_PrintStringAlignedLine(void *win, void *str, u32 c, u32 d, u32 e, u16 f, void *g);

extern void WORLDTRADE_TITLE_CreateMenuWindow(Work *p, u32 k);

extern void WORLDTRADE_ADAPTER_DeletePrintStream(struct Obj *p);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern void CLACT_RestartActorAnim(struct Actor *a);

extern void GFL_USE_PlaySeDefaultVolume(u32 se);

extern void WORLDTRADE_ADAPTER_CreateMonFromBox(u32 a, u32 b, u32 c);

extern int TOUCHPANEL_HitTrg(const void *key);

extern void func_020355D8(u8 v);

extern u32 KEY_GetTrg(void);

extern void *BMP_MENUWORK_Create(u32 a, u32 b);

extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);

extern u32 BMP_MENUWORK_Delete(void *p);

extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);

extern void *POKEPARTY_GetMember(void *p, u32 idx);

extern u32 func_02017E88(void *p, u32 id, u32 v);

extern int POKE_TOOL_ChangeBoxForm(int a0, int a1);

extern u32 POKEPARTY_GetCount(void *p);

extern u32 CLACT_IsActorAnimActive(struct Actor *a);

extern u32 WORLDTRADE_ADAPTER_IsStreamDone(PrintStreamCtx *p);

extern int TOUCHPANEL_GetTrg(void);

extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);





extern u8 unit_02045730(u32 a);

extern void BG_SYS_PushTile(u32 index);

extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);


extern u32 WORLDTRADE_ADAPTER_QueuePrintDefaultColor(void *p, u8 b, void *s, u32 x, u32 y, void *out);

extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);

extern s32 NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *file, void **out);

extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);

extern void MIi_CpuCopyFast(const void *src, void *dst, u32 n);

extern u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 half, u32 isEgg);

extern u32 POKE_TOOL_CalcBoxLevel(void *p);

extern void GX_LoadOBJ(const void *src, u32 offset, u32 size);

extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

extern u32 func_02017DBC(struct Sav *p);

extern u32 func_02017DE4(struct Sav *p, u32 f);

extern u32 FILE_UTIL_Check136C(u16 v);

extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);

extern void func_0200785C(void *save, u32 box, void *dest);

extern void *POKE_TOOL_GetBoxParam(void *a);

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);

extern int func_020078C4(void *save, u32 box);

extern u32 func_02017E1C(void *a, u32 b, u32 c);

extern u8 func_020076A4(void *save);

extern u8 func_020076B4(void *save);

void WORLDTRADE_OpenTaskMenuYesNoDefault(u32 a, u32 b, u32 c, u32 d, u8 e);

void WORLDTRADE_CloseTaskMenu(Work *p);

int WORLDTRADE_UpdateTaskMenuYesNo(Work *p);

void WORLDTRADE_OpenTaskMenuList(Work *p, u16 a, int count, int b);

u32 WORLDTRADE_UpdateTaskMenuList(Work *p);

void WORLDTRADE_CloseTaskMenuList(Work *p);

void WORLDTRADE_SetNextState(Work *p, u32 a, u32 b);

void WORLDTRADE_SetActorSurfacePos(u32 a, u16 b, u16 c);

void WORLDTRADE_SetStateAndReturn(Work *p, u32 a, u32 b);

void WORLDTRADE_ClearBusyFlag(Work *p);

void WORLDTRADE_SetActorPos(u32 a, u32 b, u32 c);

int WORLDTRADE_BOX_Init(Work *p);

void WORLDTRADE_BOX_Main(u8 *p);

int WORLDTRADE_BOX_Exit(Work *p);

void WORLDTRADE_BOX_SetupBgPlanes(void);

void WORLDTRADE_BOX_ExitBgPlanes(void);

void WORLDTRADE_BOX_LoadBgGraphics(Work *p);

void WORLDTRADE_BOX_CreateActors(Work *p);

void WORLDTRADE_BOX_DeleteActors(Work *p);

void WORLDTRADE_BOX_CreateWindows(Work *p);

void WORLDTRADE_BOX_DeleteWindows(Work *p);

void WORLDTRADE_BOX_CreateStrings(Work *p);

void WORLDTRADE_BOX_DeleteStrings(Work *p);

int WORLDTRADE_BOX_StateWaitWipeIn(Work *p);

void WORLDTRADE_BOX_SelectMonForOffer(Work *p);

void WORLDTRADE_BOX_SelectMonForRequest(Work *p);

int WORLDTRADE_BOX_CheckArrowTouch(Work *p);

void WORLDTRADE_BOX_FinishByKind(Work *p, u32 k);

int WORLDTRADE_BOX_StateMainInput(Work *p);

void WORLDTRADE_BOX_UpdateKeyCursor(Work *p);

void WORLDTRADE_BOX_MoveCursorToSlot(u32 cursor, int i);

int WORLDTRADE_BOX_GetColumnIndex(int a, int b, int c);

int WORLDTRADE_BOX_StateCreateOfferMenu(Work *p);

int WORLDTRADE_BOX_StateOfferMenuInput(Work *p);

int WORLDTRADE_BOX_StateCreateRequestMenu(Work *p);

int WORLDTRADE_BOX_StateRequestMenuInput(Work *p);

int WORLDTRADE_BOX_StateStartWipeOut(Work *p);

int WORLDTRADE_BOX_StateOpenCancelConfirm(Work *p);

int WORLDTRADE_BOX_StateCancelConfirmInput(Work *p);

int WORLDTRADE_BOX_StatePrintDepositPrompt(Work *p);

int WORLDTRADE_BOX_StateOpenDepositConfirm(Work *p);

int WORLDTRADE_BOX_StateDepositConfirmInput(Work *p);

int WORLDTRADE_BOX_TryConfirmDeposit(Work *p);

int WORLDTRADE_BOX_StatePrintSelectPrompt(Work *p);

int WORLDTRADE_BOX_StateOpenSelectConfirm(Work *p);

int WORLDTRADE_BOX_StateSelectConfirmInput(Work *p);

int WORLDTRADE_BOX_StateWaitCursorAnim(Work *p);

int WORLDTRADE_BOX_StateWaitMessage(Work *p);

int WORLDTRADE_BOX_StateWaitMessageOrKey(Work *p);

void WORLDTRADE_BOX_PrintMessage(Work *p, u32 b, u32 c, u32 d, u32 e, u32 sel);

u32 WORLDTRADE_BOX_LoadPokeIconChar(u32 a, u32 b, u32 c, u32 d);

void WORLDTRADE_BOX_LoadPokeIcon(u32 species, u32 form, u32 gender, u32 isEgg, u32 slot, u32 f8, u32 arc, IconRec *rec);

void WORLDTRADE_BOX_CalcLevel(u32 a, u8 *q);

void WORLDTRADE_BOX_TransferIconPalette(Work *p);

void WORLDTRADE_BOX_SetupIconActor(void *mon, u32 icon, u32 item_spr, u16 *species, u32 slot, void *arc, Info *info, IconRec *rec);

void WORLDTRADE_BOX_LoadBoxIcons(Work *p, int box);

int WORLDTRADE_BOX_ClampSlot(int v);

void *WORLDTRADE_BOX_GetPartyMon(void *party, void *save, int box, int slot);

u32 WORLDTRADE_BOX_GetMonCount(u8 *p, u32 b, u32 c);

int WORLDTRADE_BOX_CanRemoveMon(void *party, void *save, int box, int slot);

u32 WORLDTRADE_BOX_GetBoxCount(void *sav);

int WORLDTRADE_BOX_CheckMonRestrictionA(u32 handle);

int WORLDTRADE_BOX_CheckMonRestrictionB(u32 handle);

int WORLDTRADE_BOX_GetMonTradeState(void *party, void *save, int box, int slot);

int WORLDTRADE_BOX_TagMatchesRequest(MonTag *pa, WantTag *pb);

int WORLDTRADE_BOX_MonMatchesRequest(void *mon, WantTag *want);

void WORLDTRADE_BOX_BuildDepositFromWork(Deposit *dst, Work *p);

void WORLDTRADE_BOX_ScoreMatchingRecords(Rec_p03 *recs, u32 unused, WantTag *key, Entry_021F6DB4 *ent);

int WORLDTRADE_BOX_IsSpeciesFlagged(u32 handle);

void WORLDTRADE_BOX_RestoreCursorSave(Work *p);

void WORLDTRADE_DEPOSIT_BuildOffer(Entry *dst, Work *p);

extern void (*g_02203B0C[])(u8 *);

extern struct DispConfig_021F4580 g_02202C94;

extern struct BgTemplate_021F4580 g_02202CE4;

extern struct BgTemplate_021F4580 g_02202D04;

extern struct BgTemplate_021F4580 g_02202CA4;

extern struct BgTemplate_021F4580 g_02202CC4;

extern const Pos_021F4580 tbl_02202D24[];

extern const Pos_021F4580 tbl_02202C50[];

extern const char str_02203B54[];

extern const u8 tbl_02202E24[];

extern const u8 tbl_02202DA4[][4];

extern const char d_02203B68[];

extern const u32 tbl_02202C58[];

/*
 * volatile: hardware halfword 04000304 read at 021F5162 before masked write.
 */
int WORLDTRADE_BOX_Init(Work *p)
{
    WORLDTRADE_BOX_CreateStrings(p);
    *(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);
    WORLDTRADE_BOX_SetupBgPlanes();
    WORLDTRADE_TITLE_ScrollBg(p, 0, 0);
    WORLDTRADE_BOX_LoadBgGraphics(p);
    WORLDTRADE_BOX_CreateWindows((Work *)p);
    WORLDTRADE_BOX_CreateActors((Work *)p);
    WORLDTRADE_SUBLCD_SetSlotActorPositions((char *)p);
    if (GXx_GetMasterBrightness_((u16 *)0x0400106c) == 0) {
        WIPE_SYS_Start((void *)3, 1, 1, 0, 6, 1, 0x48);
    } else {
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x48);
    }
    WORLDTRADE_BOX_LoadBoxIcons((Work *)p, p->box);
    WORLDTRADE_ENTER_RestartNetTimeout((u8 *)p);
    p->state = 0;
    p->f12E4 = 0;
    return 1;
}

/*
 * State-table dispatch through the table at 0x02203B0C.
 */
void WORLDTRADE_BOX_Main(u8 *p)
{
    g_02203B0C[*(u32 *)(p + 0x28)](p);
}

int WORLDTRADE_BOX_Exit(Work *p)
{
    if (GXx_GetMasterBrightness_((u16 *)0x0400106c)) {
        WORLDTRADE_SUBLCD_SetSlotActorPositionsLower((char *)p);
    }
    WORLDTRADE_BOX_DeleteActors((Work *)(void *)p);
    WORLDTRADE_BOX_DeleteStrings((Work *)p);
    WORLDTRADE_BOX_DeleteWindows((Work *)(void *)p);
    WORLDTRADE_BOX_ExitBgPlanes();
    WORLDTRADE_TITLE_ExitBgPlanes((char *)p);
    CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)&p->fD38, 0);
    WORLDTRADE_ClearBusyFlag((Work *)(void *)p);
    return 0;
}

/*
 * Five-layer bring-up: the saved display config, then layers 0, 2 and 3
 * through 020414EC and layers 0 and 3 cleared through 02040B94.
 */
void WORLDTRADE_BOX_SetupBgPlanes(void)
{
    struct DispConfig_021F4580 c = g_02202C94;
    u32 v = BG_SYS_GetSubVisiblePlanes();

    BG_SYS_SetGraphicsMode(&c);
    BG_SYS_SetSubVisiblePlanes(v);
    {
        struct BgTemplate_021F4580 t = g_02202CE4;
        BG_SYS_InitBgLayer(0, &t, 0);
    }
    BG_SYS_ClearSlot(0);
    func_02040588(0, 1);
    {
        struct BgTemplate_021F4580 t = g_02202D04;
        BG_SYS_InitBgLayer(1, &t, 0);
    }
    func_02040588(1, 1);
    {
        struct BgTemplate_021F4580 t = g_02202CA4;
        BG_SYS_InitBgLayer(2, &t, 0);
    }
    BG_SYS_ClearSlot(2);
    func_02040588(2, 1);
    {
        struct BgTemplate_021F4580 t = g_02202CC4;
        BG_SYS_InitBgLayer(3, &t, 0);
    }
    BG_SYS_ClearSlot(3);
    func_02040588(3, 1);
    BG_SYS_InitRun(0, 0x20, 0, 0x48);
    BG_SYS_InitRun(3, 0x20, 0, 0x48);
}

/*
 * Poke the channel-selection helper with 2, 1, 0, 3 in turn.
 */
void WORLDTRADE_BOX_ExitBgPlanes(void)
{
    BG_SYS_Delete_03F4(2);
    BG_SYS_Delete_03F4(1);
    BG_SYS_Delete_03F4(0);
    BG_SYS_Delete_03F4(3);
}

void WORLDTRADE_BOX_LoadBgGraphics(Work *p)
{
    void *h;
    h = func_020490F4(0x60, 0x48);
    func_02049B68(h, 1, 0, 0, 0x60, 0x48);
    func_02049B40(0x17, 5, 0, 0x1a0, 0x20, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 0xe, 0, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(0, 0x1f, 0xb, 0, 0x48);
    func_02049658(h, 0xa, 1, 0, 0xa00, 1, 0x48);
    func_020498F4(h, 0x15, 1, 0, 0x600, 1, 0x48);
    func_020498F4(h, 0x1f, 2, 0, 0x600, 1, 0x48);
    ARC_TOOL_DeleteHandle(h);
    WORLDTRADE_TITLE_LoadMainBgSwap(p);
    WORLDTRADE_TITLE_LoadSubBgSwap(p);
}

void WORLDTRADE_BOX_CreateActors(Work *p)
{
    Local s;
    int i;

    MI_CpuFill8(&s, 0, 8);
    s.a = tbl_02202D24[p->slot].x;
    s.b = tbl_02202D24[p->slot].y;
    p->sub.f34 = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
    CLACT_SetActorAutoAnim((struct Obj *)p->sub.f34, 1);
    CLACT_SetActorAnimSeq((struct Obj *)p->sub.f34, 4);
    if (func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)p->sub.f34, 0);
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)p->sub.f34, 1);
    }
    if (p->slot == 0x1f || p->slot <= 5) {
        CLACT_SetActorBgPriority(p->sub.f34, 0);
    } else {
        CLACT_SetActorBgPriority(p->sub.f34, 1);
    }

    for (i = 0; i < 30; i++) {
        s.a = tbl_02202D24[i].x;
        s.b = tbl_02202D24[i].y;
        s.d = 30 - i % 6;
        p->sub.arrA[i] = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        CLACT_SetActorAnimSeq((struct Obj *)p->sub.arrA[i], i + 6);
        CLACT_SetActorBgPriority(p->sub.arrA[i], 1);
    }

    for (i = 0; i < 30; i++) {
        s.a = tbl_02202D24[i].x;
        s.b = tbl_02202D24[i].y + 6;
        s.d = 10;
        p->sub.arrB[i] = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        CLACT_SetActorAnimSeq((struct Obj *)p->sub.arrB[i], 0x28);
        CLACT_SetActorBgPriority(p->sub.arrB[i], 1);
    }

    for (i = 0; i < 6; i++) {
        s.a = tbl_02202D24[i].x + 8;
        s.b = tbl_02202D24[i].y + 6;
        s.d = 10;
        p->arrC[i] = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        CLACT_SetActorAnimSeq((struct Obj *)p->arrC[i], 0x2a);
        CLACT_SetActorBgPriority(p->arrC[i], 1);
    }

    for (i = 0; i < 2; i++) {
        s.a = tbl_02202C50[i].x;
        s.b = tbl_02202C50[i].y;
        p->arrows[i] = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f4, p->sub.f8, p->sub.fC, &s, 0, 0x48);
        CLACT_SetActorAnimSeq((struct Obj *)p->arrows[i], i + 0x26);
        CLACT_SetActorBgPriority(p->arrows[i], 1);
    }

    s.a = 0xef;
    s.b = 0x88;
    s.d = 100;
    s.e = 1;
    p->sub.f3C = (u32)CLACT_CreateActor((void *)p->sub.f0, p->sub.f28, p->sub.f8, p->sub.f30, &s, 0, 0x48);
    CLACT_SetActorAnimSeq((struct Obj *)p->sub.f3C, 0xc);
    CLACT_SetActorAutoAnim((struct Obj *)p->sub.f3C, 1);
    CLACT_StopActorAnim((struct Actor *)p->sub.f3C);
    CLACT_SetActorDrawEnable((struct Obj *)p->sub.f3C, 0);
    CLACT_SetActorDrawEnable((struct Obj *)p->fD38, 1);
    WORLDTRADE_SetActorSurfacePos(p->fD38, 0x37, 0xa8);
}

void WORLDTRADE_BOX_DeleteActors(Work *p)
{
    int i;
    CLACT_DeleteActor((struct Obj *)(p->cursor_u));
    for (i = 0; i < 2; i++) {
        CLACT_DeleteActor((struct Obj *)(*(u32 *)((u8 *)p + 0xd2c + i * 4)));
    }
    CLACT_DeleteActor((struct Obj *)(p->cursor));
    for (i = 0; i < 30; i++) {
        CLACT_DeleteActor((struct Obj *)(p->icon[i]));
        CLACT_DeleteActor((struct Obj *)(p->item[i]));
    }
    for (i = 0; i < 6; i++) {
        CLACT_DeleteActor((struct Obj *)(*(u32 *)((u8 *)p + 0xcf0 + i * 4)));
    }
}

void WORLDTRADE_BOX_CreateWindows(Work *p)
{
    void *w;

    p->fD4C = (void *)BMP_WIN_Create(3, 4, 0, 0xD, 3, 0xD, 1);
    BMP_Clear(BMP_WIN_GetBmp(p->fD4C), 0);
    w = p->fD4C;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_020409B4(BMP_WIN_GetBgLayer(w));

    p->d40 = (void *)BMP_WIN_Create(0, 2, 0x15, 0x1B, 2, 0xD, 1);
    BMP_Clear(BMP_WIN_GetBmp(p->d40), 0);
    w = p->d40;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_020409B4(BMP_WIN_GetBgLayer(w));

    p->dd0 = (void *)BMP_WIN_Create(0, 2, 0x13, 0x1B, 4, 0xD, 1);
    BMP_Clear(BMP_WIN_GetBmp(p->dd0), 0);
    w = p->d40;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_020409B4(BMP_WIN_GetBgLayer(w));

    p->win3 = (void *)BMP_WIN_Create(1, 0x18, 0x10, 6, 2, 0, 1);
    BMP_Clear(BMP_WIN_GetBmp(p->win3), 4);
    w = p->win3;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_020409B4(BMP_WIN_GetBgLayer(w));

    WORLDTRADE_INPUT_PrintStringAlignedLine(p->win3, p->strs, 0, 1, 1, 0x3DC4, p->fFA0);
    if (p->kind == 5) {
        WORLDTRADE_TITLE_CreateMenuWindow(p, 3);
    } else {
        WORLDTRADE_TITLE_CreateMenuWindow(p, 1);
    }
}

void WORLDTRADE_BOX_DeleteWindows(Work *p)
{
    WORLDTRADE_ADAPTER_DeletePrintStream((struct Obj *)((u8 *)p + 0xfa0));
    BMP_WIN_Delete(p->fDE0);
    BMP_WIN_Delete(p->dd0);
    BMP_WIN_Delete(p->win3);
    BMP_WIN_Delete(p->d40);
    BMP_WIN_Delete(p->fD4C);
}

void WORLDTRADE_BOX_CreateStrings(Work *p)
{
    WORLDTRADE_BOX_RestoreCursorSave((Work *)p);
    p->fB80 = STRBUF_Create(0x12, 0x48);
    p->str = STRBUF_Create(0xb4, 0x48);
    p->strs = func_02045EC0(p->bank, 0x73);
    if (p->slot == 0x1e) {
        p->slot = 0;
    }
    (*(void **)&p->info_p) = func_02030734(0x48, 0x78, 0, str_02203B54, 0x344);
}

void WORLDTRADE_BOX_DeleteStrings(Work *p) { func_020307B0((void *)p->info_p); STRBUF_Delete(p->fB80); STRBUF_Delete(p->str); STRBUF_Delete(p->strs); }

/*
 * precondition: entry mode at offset 0x20 must be 5 or 6; original
 *   leaves r4 unchanged for other modes at 021F5A32..021F5A38.
 */
int WORLDTRADE_BOX_StateWaitWipeIn(Work *p)
{
    int index;
    if (WIPE_SYS_EndCheck()) {
        if (p->kind == 5) {
            index = 0x15;
        } else if (p->kind == 6) {
            index = 0x11;
        }
        WORLDTRADE_BOX_PrintMessage(p, index, 1, 0, 0xf0f, 0);
        WORLDTRADE_SetNextState(p, 3, 1);
        if (func_020355C4() == 1) {
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 0);
        } else {
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        }
    }
    return 2;
}

void WORLDTRADE_BOX_SelectMonForOffer(Work *p)
{
    if (p->slot == 0x1E) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor_u, 1);
        CLACT_RestartActorAnim((struct Actor *)p->cursor_u);
        p->state = 0x11;
        GFL_USE_PlaySeDefaultVolume(0x551);
        return;
    }
    if (p->slot == 0x1F) {
        return;
    }
    switch (WORLDTRADE_BOX_GetMonTradeState(p->ctx->party, p->ctx->save, p->box, p->slot)) {
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (WORLDTRADE_BOX_CanRemoveMon(p->ctx->party, p->ctx->save, p->box, p->slot) != 0) {
            WORLDTRADE_ADAPTER_CreateMonFromBox((u32)p->words, 0, (u32)WORLDTRADE_BOX_GetPartyMon(p->ctx->party, p->ctx->save, p->box, p->slot));
            WORLDTRADE_BOX_PrintMessage(p, 0x16, 1, 0, 0xF0F, 0);
            WORLDTRADE_SetNextState(p, 3, 7);
        } else {
            WORLDTRADE_BOX_PrintMessage(p, 0x1A, 1, 0, 0xF0F, 1);
            WORLDTRADE_SetNextState(p, 4, 1);
        }
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        WORLDTRADE_BOX_PrintMessage(p, 0x21, 1, 0, 0xF0F, 1);
        WORLDTRADE_SetNextState(p, 4, 1);
        break;
    }
}

void WORLDTRADE_BOX_SelectMonForRequest(Work *p)
{
    void *mon;

    if (p->slot == 0x1E) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor_u, 1);
        CLACT_RestartActorAnim((struct Actor *)p->cursor_u);
        p->state = 0x11;
        return;
    }
    if (p->slot == 0x1F) {
        return;
    }
    switch (WORLDTRADE_BOX_GetMonTradeState(p->ctx->party, p->ctx->save, p->box, p->slot)) {
    case 1:
        mon = WORLDTRADE_BOX_GetPartyMon(p->ctx->party, p->ctx->save, p->box, p->slot);
        if (WORLDTRADE_BOX_MonMatchesRequest(mon, (WantTag *)(p->arr_entry1[p->cur].key)) != 0) {
            if (WORLDTRADE_BOX_CanRemoveMon(p->ctx->party, p->ctx->save, p->box, p->slot) != 0) {
                WORLDTRADE_ADAPTER_CreateMonFromBox((u32)p->words, 0, (u32)mon);
                WORLDTRADE_BOX_PrintMessage(p, 0x12, 1, 0, 0xF0F, 0);
                WORLDTRADE_SetNextState(p, 3, 9);
                GFL_USE_PlaySeDefaultVolume(0x54C);
            } else {
                WORLDTRADE_BOX_PrintMessage(p, 0x1A, 1, 0, 0xF0F, 1);
                WORLDTRADE_SetNextState(p, 4, 1);
            }
        } else {
            GFL_USE_PlaySeDefaultVolume(0x551);
        }
        break;
    case 0:
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        break;
    }
}

int WORLDTRADE_BOX_CheckArrowTouch(Work *p)
{
    int r = TOUCHPANEL_HitTrg(tbl_02202E24);

    if (r != -1) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 0);
        func_020355D8(1);
    }
    return r;
}

/*
 * Two-way mode dispatch on the second argument, each arm latching state 2.
 */
void WORLDTRADE_BOX_FinishByKind(Work *p, u32 k)
{
    if (k == 5) {
        WORLDTRADE_SetStateAndReturn(p, 1, 0);
        p->state = 2;
    } else if (k == 6) {
        WORLDTRADE_SetStateAndReturn(p, 3, 0x11);
        p->state = 2;
    }
}

int WORLDTRADE_BOX_StateMainInput(Work *p)
{
    int r = WORLDTRADE_BOX_CheckArrowTouch((Work *)p);

    if (r != -1) {
        switch (r) {
        case 0x1F:
            CLACT_SetActorAutoAnim((struct Obj *)p->arrows[0], 1);
            CLACT_SetActorAnimSeq((struct Obj *)p->arrows[0], 0x26);
            p->box = WORLDTRADE_BOX_GetColumnIndex(p->box, p->boxes, 1);
            WORLDTRADE_BOX_LoadBoxIcons(p, p->box);
            GFL_USE_PlaySeDefaultVolume(0x548);
            break;
        case 0x20:
            CLACT_SetActorAutoAnim((struct Obj *)p->arrows[1], 1);
            CLACT_SetActorAnimSeq((struct Obj *)p->arrows[1], 0x27);
            p->box = WORLDTRADE_BOX_GetColumnIndex(p->box, p->boxes, -1);
            WORLDTRADE_BOX_LoadBoxIcons(p, p->box);
            GFL_USE_PlaySeDefaultVolume(0x548);
            break;
        case 0x1E:
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor_u, 1);
            CLACT_RestartActorAnim((struct Actor *)p->cursor_u);
            p->state = 0x11;
            p->slot = r;
            GFL_USE_PlaySeDefaultVolume(0x551);
            WORLDTRADE_BOX_MoveCursorToSlot(p->cursor, p->slot);
            break;
        default:
            p->slot = r;
            WORLDTRADE_BOX_MoveCursorToSlot(p->cursor, p->slot);
            if (p->kind == 5) {
                WORLDTRADE_BOX_SelectMonForOffer((Work *)p);
            } else if (p->kind == 6) {
                WORLDTRADE_BOX_SelectMonForRequest((Work *)p);
            }
            break;
        }
    } else {
        WORLDTRADE_BOX_UpdateKeyCursor((Work *)((Work *)p));
        if (p->kind == 5) {
            if (KEY_GetTrg() & 2) {
                CLACT_SetActorDrawEnable((struct Obj *)p->cursor_u, 1);
                CLACT_RestartActorAnim((struct Actor *)p->cursor_u);
                p->state = 0x11;
                GFL_USE_PlaySeDefaultVolume(0x551);
            } else if (KEY_GetTrg() & 1) {
                WORLDTRADE_BOX_SelectMonForOffer((Work *)p);
            }
        } else if (p->kind == 6) {
            if (KEY_GetTrg() & 2) {
                CLACT_SetActorDrawEnable((struct Obj *)p->cursor_u, 1);
                CLACT_RestartActorAnim((struct Actor *)p->cursor_u);
                p->state = 0x11;
                GFL_USE_PlaySeDefaultVolume(0x551);
            } else if (KEY_GetTrg() & 1) {
                WORLDTRADE_BOX_SelectMonForRequest((Work *)p);
            }
        }
    }
    return 2;
}

void WORLDTRADE_BOX_UpdateKeyCursor(Work *p)
{
    int moved = 0;
    int dir = 0;
    u8 k;

    if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        func_020355D8(moved);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return;
    }
    if (KEY_GetTrg() & 0x40) {
        dir = 1;
    } else if (KEY_GetTrg() & 0x80) {
        dir = 2;
    } else if (KEY_GetTrg() & 0x20) {
        dir = 3;
    } else if (KEY_GetTrg() & 0x10) {
        dir = 4;
    }
    if (dir != 0) {
        dir = tbl_02202DA4[p->slot][dir - 1];
        if (dir != p->slot) {
            if (dir == 0x63 || dir == 0x65) {
                k = dir == 0x65 ? 0 : 1;
                CLACT_SetActorAutoAnim((struct Obj *)p->arrows[k], 1);
                CLACT_SetActorAnimSeq((struct Obj *)p->arrows[k], k + 0x26);
                p->box = WORLDTRADE_BOX_GetColumnIndex(p->box, p->boxes, dir - 0x64);
                WORLDTRADE_BOX_LoadBoxIcons((Work *)p, p->box);
                GFL_USE_PlaySeDefaultVolume(0x548);
            } else {
                moved = 1;
                p->slot = dir;
            }
        }
    }
    if (moved) {
        GFL_USE_PlaySeDefaultVolume(0x548);
    }
    WORLDTRADE_BOX_MoveCursorToSlot(p->cursor, p->slot);
}

void WORLDTRADE_BOX_MoveCursorToSlot(u32 cursor, int i)
{
    WORLDTRADE_SetActorPos(cursor, tbl_02202D24[i].x, tbl_02202D24[i].y);
    if (i == 0x1F || (i >= 0 && i <= 5)) {
        CLACT_SetActorBgPriority(cursor, 0);
    } else {
        CLACT_SetActorBgPriority(cursor, 1);
    }
}

/*
 * Byte-index arithmetic with 0xff as the out-of-range marker.
 */
int WORLDTRADE_BOX_GetColumnIndex(int a, int b, int c)
{
    if (a == 0xff) {
        if (c > 0) {
            return 0;
        }
        if (c < 0) {
            return b - 1;
        }
        return a;
    }
    a += c;
    if (a < 0) {
        return 0xff;
    }
    if (a == b) {
        return 0xff;
    }
    return a;
}

/*
 * Create the resource, register the three 68/69/6a entries and latch state 0x8.
 */
int WORLDTRADE_BOX_StateCreateOfferMenu(Work *p)
{
    *(u32 *)&p->de8 = (u32)BMP_MENUWORK_Create(3, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&p->de8), p->bank_u, 0x68, 1, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&p->de8), p->bank_u, 0x69, 2, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&p->de8), p->bank_u, 0x6a, 3, 0x48);
    WORLDTRADE_OpenTaskMenuList(p, 0, 3, 0x14);
    p->state = 8;
    return 2;
}

int WORLDTRADE_BOX_StateOfferMenuInput(Work *p)
{
    void *mon;

    switch (WORLDTRADE_UpdateTaskMenuList(p)) {
    case 1:
        WORLDTRADE_CloseTaskMenuList(p);
        BMP_MENUWORK_Delete(p->de8);
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        p->state = 2;
        WORLDTRADE_SetStateAndReturn(p, 8, 5);
        break;
    case 2:
        WORLDTRADE_CloseTaskMenuList(p);
        BMP_MENUWORK_Delete(p->de8);
        mon = WORLDTRADE_BOX_GetPartyMon(p->ctx->party, p->ctx->save, p->box, p->slot);
        if (WORLDTRADE_BOX_GetBoxCount(mon) != 0) {
            WORLDTRADE_BOX_PrintMessage(p, 0x2B, 1, 0, 0xF0F, 1);
            WORLDTRADE_SetNextState(p, 4, 1);
        } else if (WORLDTRADE_BOX_CheckMonRestrictionA((u32)mon) != 0) {
            if (WORLDTRADE_BOX_CheckMonRestrictionA((u32)mon) == 1) {
                WORLDTRADE_BOX_PrintMessage(p, 0xBF, 1, 0, 0xF0F, 1);
            } else {
                WORLDTRADE_BOX_PrintMessage(p, 0xC0, 1, 0, 0xF0F, 1);
            }
            WORLDTRADE_SetNextState(p, 4, 1);
        } else if (WORLDTRADE_BOX_CheckMonRestrictionB((u32)mon) != 0) {
            WORLDTRADE_BOX_PrintMessage(p, 0xC1, 1, 0, 0xF0F, 1);
            WORLDTRADE_SetNextState(p, 4, 1);
        } else {
            if (WORLDTRADE_BOX_ClampSlot(p->box) != 0) {
                POKEPARTY_GetMember(p->ctx->party, p->slot);
            }
            p->mon = WORLDTRADE_BOX_GetPartyMon(p->ctx->party, p->ctx->save, p->box, p->slot);
            p->state = 2;
            WORLDTRADE_SetStateAndReturn(p, 6, 0);
        }
        break;
    case 3:
    case (u32)-2:
        WORLDTRADE_CloseTaskMenuList(p);
        BMP_MENUWORK_Delete(p->de8);
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        p->state = 0;
        break;
    }
    return 2;
}

/*
 * Create the resource, register the three 5d/5e/5f entries and latch state 0xa.
 */
int WORLDTRADE_BOX_StateCreateRequestMenu(Work *p)
{
    *(u32 *)&p->de8 = (u32)BMP_MENUWORK_Create(3, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&p->de8), p->bank_u, 0x5d, 1, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&p->de8), p->bank_u, 0x5e, 2, 0x48);
    BMP_MENUWORK_AddMsgItem((struct Slot *)(*(u32 *)&p->de8), p->bank_u, 0x5f, 3, 0x48);
    WORLDTRADE_OpenTaskMenuList(p, 0, 3, 0x14);
    p->state = 10;
    return 2;
}

int WORLDTRADE_BOX_StateRequestMenuInput(Work *p)
{
    void *mon;

    switch (WORLDTRADE_UpdateTaskMenuList(p)) {
    case 1:
        WORLDTRADE_CloseTaskMenuList(p);
        BMP_MENUWORK_Delete(p->de8);
        p->state = 2;
        WORLDTRADE_SetStateAndReturn(p, 8, 6);
        break;
    case 2:
        WORLDTRADE_CloseTaskMenuList(p);
        BMP_MENUWORK_Delete(p->de8);
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        mon = WORLDTRADE_BOX_GetPartyMon(p->ctx->party, p->ctx->save, p->box, p->slot);
        if (WORLDTRADE_BOX_GetBoxCount(mon) != 0) {
            WORLDTRADE_BOX_PrintMessage(p, 0x2B, 1, 0, 0xF0F, 1);
            WORLDTRADE_SetNextState(p, 4, 1);
        } else if (WORLDTRADE_BOX_CheckMonRestrictionA((u32)mon) != 0) {
            if (WORLDTRADE_BOX_CheckMonRestrictionA((u32)mon) == 1) {
                WORLDTRADE_BOX_PrintMessage(p, 0xBF, 1, 0, 0xF0F, 1);
            } else {
                WORLDTRADE_BOX_PrintMessage(p, 0xC0, 1, 0, 0xF0F, 1);
            }
            WORLDTRADE_SetNextState(p, 4, 1);
        } else if (WORLDTRADE_BOX_CheckMonRestrictionB((u32)mon) != 0) {
            WORLDTRADE_BOX_PrintMessage(p, 0xC1, 1, 0, 0xF0F, 1);
            WORLDTRADE_SetNextState(p, 4, 1);
        } else {
            if (WORLDTRADE_BOX_ClampSlot(p->box) != 0) {
                POKEPARTY_GetMember(p->ctx->party, p->slot);
            }
            if (func_02017E88(mon, 5, 0) == 0x1EC) {
                POKE_TOOL_ChangeBoxForm((int)mon, 0);
            }
            WORLDTRADE_BOX_TryConfirmDeposit((Work *)((Work *)p));
        }
        break;
    case 3:
    case (u32)-2:
        WORLDTRADE_CloseTaskMenuList(p);
        BMP_MENUWORK_Delete(p->de8);
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        p->state = 0;
        break;
    }
    return 2;
}

int WORLDTRADE_BOX_StateStartWipeOut(Work *p)
{
    if (p->x14 == 0 || p->x14 == 8 || p->x14 == 3) {
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x48);
        p->eb4 = 1;
    } else {
        WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    p->state = 0;
    return 3;
}

/*
 * State setter: build with the fixed 0x14/0x1ad/0x8/0x1 argument pair and latch state 0x6.
 */
int WORLDTRADE_BOX_StateOpenCancelConfirm(Work *p)
{
    WORLDTRADE_OpenTaskMenuYesNoDefault((u32)p, 0x14, 0x1ad, 0x8, 0x1);
    p->state = 0x6;
    return 2;
}

int WORLDTRADE_BOX_StateCancelConfirmInput(Work *p)
{
    unsigned result = WORLDTRADE_UpdateTaskMenuYesNo(p);
    func_02034714(d_02203B68, 0, d_02203B68);
    if (result == 1) {
        WORLDTRADE_CloseTaskMenu(p);
        p->state = 2;
        WORLDTRADE_SetStateAndReturn(p, 0, 0);
    } else if (result == 2) {
        WORLDTRADE_CloseTaskMenu(p);
        p->state = 0;
    }
    return 2;
}

/*
 * Build through WORLDTRADE_BOX_PrintMessage and publish the 3/0xc pair.
 */
int WORLDTRADE_BOX_StatePrintDepositPrompt(Work *p)
{
    WORLDTRADE_BOX_PrintMessage(p, 0x19, 1, 0, 0xf0f, 1);
    WORLDTRADE_SetNextState(p, 3, 0xc);
    return 2;
}

/*
 * State setter: build with the fixed 0x12/0x1ad/0x8/0x1 argument pair and latch state 0xd.
 */
int WORLDTRADE_BOX_StateOpenDepositConfirm(Work *p)
{
    WORLDTRADE_OpenTaskMenuYesNoDefault((u32)p, 0x12, 0x1ad, 0x8, 0x1);
    p->state = 0xd;
    return 2;
}

/*
 * Two-way mode dispatch: mode 1 clears and runs the sub-step, mode 2 clears, releases the +0xdd0 word and latches state 1.
 */
int WORLDTRADE_BOX_StateDepositConfirmInput(Work *p)
{
    u32 k = WORLDTRADE_UpdateTaskMenuYesNo(p);

    if (k == 1) {
        WORLDTRADE_CloseTaskMenu(p);
        WORLDTRADE_BOX_TryConfirmDeposit((Work *)((Work *)p));
    } else if (k == 2) {
        WORLDTRADE_CloseTaskMenu(p);
        BMP_MENUWORK_DrawWindowBorder((void *)(*(u32 *)&p->dd0), 0);
        p->state = 1;
    }
    return 2;
}

int WORLDTRADE_BOX_TryConfirmDeposit(Work *p)
{
    if (WORLDTRADE_BOX_IsSpeciesFlagged((u32)p->list[p->cur]) != 0 && p->box != 0xFF
        && POKEPARTY_GetCount(p->ctx->party) == 6) {
        WORLDTRADE_BOX_PrintMessage(p, 0x29, 1, 0, 0xF0F, 1);
        WORLDTRADE_SetNextState(p, 4, 1);
        return 0;
    }
    p->mon = WORLDTRADE_BOX_GetPartyMon(p->ctx->party, p->ctx->save, p->box, p->slot);
    p->state = 2;
    p->eb4 = 1;
    WORLDTRADE_SetStateAndReturn(p, 7, 9);
    WORLDTRADE_BOX_BuildDepositFromWork((Deposit *)p->ent, p);
    p->d0 = 0;
    return 1;
}

int WORLDTRADE_BOX_StatePrintSelectPrompt(Work *p)
{
    WORLDTRADE_BOX_PrintMessage(p, 0x19, 1, 0, 0xf0f, 1);
    WORLDTRADE_SetNextState(p, 3, 0xf);
    return 2;
}

/*
 * State setter: build with the fixed 0x12/0x1ad/0x8/0x1 argument pair and latch state 0x10.
 */
int WORLDTRADE_BOX_StateOpenSelectConfirm(Work *p)
{
    WORLDTRADE_OpenTaskMenuYesNoDefault((u32)p, 0x12, 0x1ad, 0x8, 0x1);
    p->state = 0x10;
    return 2;
}

int WORLDTRADE_BOX_StateSelectConfirmInput(Work *p)
{
    unsigned result = WORLDTRADE_UpdateTaskMenuYesNo(p);
    if (result == 1) {
        WORLDTRADE_CloseTaskMenu(p);
        p->mon = WORLDTRADE_BOX_GetPartyMon(p->ctx->party, p->ctx->save, p->box, p->slot);
        p->state_un = 2;
        WORLDTRADE_SetStateAndReturn(p, 6, 0);
    } else if (result == 2) {
        WORLDTRADE_CloseTaskMenu(p);
        BMP_MENUWORK_DrawWindowBorder(p->dd0, 0);
        p->state_un = 1;
    }
    return 2;
}

/*
 * While the +0xbfc buffer is free, feed the mode word at +0x20 to the dispatch.
 */
int WORLDTRADE_BOX_StateWaitCursorAnim(Work *p)
{
    if (CLACT_IsActorAnimActive((struct Actor *)(p->cursor_u)) == 0) {
        WORLDTRADE_BOX_FinishByKind((Work *)(void *)p, p->kind);
    }
    return 2;
}

/*
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */
int WORLDTRADE_BOX_StateWaitMessage(Work *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamDone(&p->printCtx) == 0) {
        p->state = p->returnState;
    }
    return 2;
}

/*
 * When the build query answers 0 and either probe is set, release the +0xdd0 word and roll the state.
 */
int WORLDTRADE_BOX_StateWaitMessageOrKey(Work *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamDone(&p->printCtx) == 0) {
        if (KEY_GetTrg() != 0 || TOUCHPANEL_GetTrg() != 0) {
            BMP_MENUWORK_DrawWindowBorder((void *)((*(unsigned int *)&p->dd0)), 0);
            p->state = p->returnState;
        }
    }
    return 2;
}

/*
 * Window teardown: the handle is the 0xd40 or 0xdd0 window selected by the
 * sixth argument, and that one handle is used by every call in the body.
 */
void WORLDTRADE_BOX_PrintMessage(Work *p, u32 b, u32 c, u32 d, u32 e, u32 sel)
{
    u32 v = (u32)MSGDATA_AllocString((struct MsgBank *)(*(u32 *)&p->bank), b);
    u32 h;

    WORDSET_CopyTaggedText((struct WordSet *)(*(u32 *)&p->words), (void *)((*(unsigned int *)&p->str)), (void *)v);
    h = *(u32 *)((u8 *)p + (sel == 0 ? 0xd40 : 0xdd0));
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)h)), 0xf);
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    BG_SYS_PushTile(unit_02045730(h));
    BMP_MENUWORK_DrawWindow((void *)h, 0, 1, 0xe);
    WORLDTRADE_ADAPTER_QueuePrintDefaultColor((void *)h, 0, (void *)((*(unsigned int *)&p->str)), 0, 0, (u8 *)p + 0xfa0);
    STRBUF_Delete((struct U16Vec *)v);
}

u32 WORLDTRADE_BOX_LoadPokeIconChar(u32 a, u32 b, u32 c, u32 d)
{
    u32 blk = (u32)ARC_TOOL_LoadHandleMember((struct ArcFile *)a, b, (u16)d);

    if (blk != 0 && NNS_G2dGetUnpackedCharacterDataEx((struct NitroFileHeader *)blk, (void **)c) == 0) {
        func_020307B0((void *)blk);
        return 0;
    }
    return blk;
}

/*
 * Load the icon graphics of a Pokemon (species, form, gender/half, egg)
 * from the archive handle and copy its 0x200 bytes into the sprite
 * record: +0 gets the VRAM offset of slot `slot`, +4 the icon palette
 * (POKE_TOOL_CalcIconPalette + 5), +8 `pal`, the pixels go to +0xC.
 */
void WORLDTRADE_BOX_LoadPokeIcon(u32 species, u32 form, u32 gender, u32 isEgg, u32 slot, u32 f8, u32 arc, IconRec *rec)
{
    CharData_p02 *cd;
    void *buf = (void *)WORLDTRADE_BOX_LoadPokeIconChar(arc, POKE_TOOL_CalcGraphicIndex(species, form, gender, isEgg), (u32)(&cd), 0x48);

    MIi_CpuCopyFast(cd->pixels, rec->pixels, 0x200);
    rec->vram = (slot * 16 + 0x1c) * 32;
    rec->spr = f8;
    rec->pal = POKE_TOOL_CalcIconPalette(species, form, gender, isEgg) + 5;
    func_020307B0(buf);
}

/*
 * Store the query byte at +3 of the second argument.
 */
void WORLDTRADE_BOX_CalcLevel(u32 a, u8 *q)
{
    q[3] = POKE_TOOL_CalcBoxLevel((void *)a);
}

/*
 * Deferred icon upload (installed at +0xEBC by WORLDTRADE_BOX_LoadBoxIcons): for each
 * of the 30 icon records at +0xEB8 that has a sprite (+8), flush and
 * load its 0x200 pixel bytes to its OBJ VRAM offset and set the sprite's
 * palette; then free the record block.
 */
void WORLDTRADE_BOX_TransferIconPalette(Work *p)
{
    int i;
    IconRec *e;

    e = p->icons;
    for (i = 0; i < 30; i++, e++) {
        if (e->spr != 0) {
            DC_FlushRange(e->pixels, 0x200);
            GX_LoadOBJ(e->pixels, e->vram, 0x200);
            CLACT_SetActorPaletteOffset((struct Obj *)e->spr, (u8)e->pal, 1);
        }
    }
    func_020307B0(p->icons);
}

/*
 * Read one Pokemon's display parameters (presence 0xA9, species 5, form
 * 0x6F, egg 0x4C, held item 6, parameter 0x6E + 1) into the info record,
 * clearing its +3 byte for an egg. A present Pokemon gets its icon loaded
 * (WORLDTRADE_BOX_LoadPokeIcon) and shown; the item sprite is shown with animation 0x29
 * or 0x28 by FILE_UTIL_Check136C, or hidden when there is no item. An empty
 * slot hides both sprites and clears the icon record's +8 word.
 */
void WORLDTRADE_BOX_SetupIconActor(void *mon, u32 icon, u32 item_spr, u16 *species, u32 slot, void *arc, Info *info, IconRec *rec)
{
    u32 present;
    u32 item;
    u32 egg;
    u32 form;

    func_02017DBC(mon);
    present = func_02017E88(mon, 0xa9, 0);
    *species = func_02017E88(mon, 5, 0);
    form = func_02017E88(mon, 0x6f, 0);
    egg = func_02017E88(mon, 0x4c, 0);
    item = func_02017E88(mon, 6, 0);
    info->species = *species;
    info->f2 = func_02017E88(mon, 0x6e, 0) + 1;
    if (egg != 0) {
        info->f3 = 0;
    }
    func_02017DE4(mon, 1);
    if (present != 0) {
        WORLDTRADE_BOX_LoadPokeIcon(*species, form, info->f2 - 1, egg, slot, icon, (u32)arc, (IconRec *)rec);
        CLACT_SetActorDrawEnable((struct Obj *)icon, 1);
        if (item != 0) {
            CLACT_SetActorDrawEnable((struct Obj *)item_spr, 1);
            if (FILE_UTIL_Check136C(item) != 0) {
                CLACT_SetActorAnimSeq((struct Obj *)item_spr, 0x29);
            } else {
                CLACT_SetActorAnimSeq((struct Obj *)item_spr, 0x28);
            }
        } else {
            CLACT_SetActorDrawEnable((struct Obj *)item_spr, 0);
        }
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)icon, 0);
        CLACT_SetActorDrawEnable((struct Obj *)item_spr, 0);
        rec->spr = 0;
    }
}

/*
 * Build the 30 Pokemon icon slots of the screen from box `box` of the
 * storage (+0xC of the context) or, for box 0xFF, from the party (+8),
 * blanking the slots past the party size. Icon records (0x3D68 bytes,
 * +0xEB8) are uploaded later by WORLDTRADE_BOX_TransferIconPalette, installed at +0xEBC.
 * Any other box reports through func_02034714 (raw 0x02203B68). Kind 6
 * then runs WORLDTRADE_BOX_ScoreMatchingRecords against the current entry's key.
 */
void WORLDTRADE_BOX_LoadBoxIcons(Work *p, int box)
{
    void *storage = p->ctx->save;
    u16 species[30];
    void *arc;
    IconRec *icons;
    u16 i;

    icons = func_02030734(0x8001, 0x3D68, 0, str_02203B54, 0x892);
    p->icons = icons;
    arc = func_020490F4(7, 0x48);
    if (box >= 0 && box < p->nbox) {
        for (i = 0; i < 30; i++) {
            WORLDTRADE_BOX_CalcLevel((u32)func_02007A18(storage, box, i), (u8 *)(&p->info_p[i]));
        }
        for (i = 0; i < 30; i++) {
            p->info_p[i].species = 0;
            WORLDTRADE_BOX_SetupIconActor(func_02007A18(storage, box, i), p->icon[i], p->item[i], &species[i], i, arc, (Info *)(&p->info_p[i]), &icons[i]);
            if (i < 6) {
                CLACT_SetActorDrawEnable((struct Obj *)p->arrC[i], 0);
            }
        }
        func_0200785C(storage, box, p->fB80);
    } else if (box == 0xff) {
        int n = POKEPARTY_GetCount(p->ctx->party);

        for (i = 0; i < n; i++) {
            void *mon = POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(p->ctx->party, i));

            WORLDTRADE_BOX_CalcLevel((u32)mon, (u8 *)(&p->info_p[i]));
            WORLDTRADE_BOX_SetupIconActor(mon, p->icon[i], p->item[i], &species[i], i, arc, (Info *)(&p->info_p[i]), &icons[i]);
            CLACT_SetActorDrawEnable((struct Obj *)p->arrC[i], 0);
        }
        for (; i < 30; i++) {
            p->info_p[i].species = 0;
            CLACT_SetActorDrawEnable((struct Obj *)p->icon[i], 0);
            CLACT_SetActorDrawEnable((struct Obj *)p->item[i], 0);
            icons[i].spr = 0;
            if (i < 6) {
                CLACT_SetActorDrawEnable((struct Obj *)p->arrC[i], 0);
            }
        }
        func_02045CAC(p->bank, 0x62, p->fB80);
    } else {
        func_02034714((void *)0x02203B68, 0, (void *)0x02203B68);
    }
    ARC_TOOL_DeleteHandle(arc);
    BMP_Clear(BMP_WIN_GetBmp(p->fD4C), 0);
    WORLDTRADE_INPUT_PrintStringAlignedLine(p->fD4C, p->fB80, 0, 5, 1, 0x440, p->fFA0);
    if (p->kind == 6) {
        WORLDTRADE_BOX_ScoreMatchingRecords((Rec_p03 *)p->info_p, (u32)p->icon, (WantTag *)(p->arr[p->cur].key), (Entry_021F6DB4 *)icons);
    }
    p->vblank_fn = WORLDTRADE_BOX_TransferIconPalette;
}

/*
 * True only for the 0xff sentinel.
 */
int WORLDTRADE_BOX_ClampSlot(int v)
{
    if (v == 0xff) {
        return 1;
    }
    return 0;
}

void *WORLDTRADE_BOX_GetPartyMon(void *party, void *save, int box, int slot)
{
    if (WORLDTRADE_BOX_ClampSlot(box) != 0) {
        if (slot > (int)POKEPARTY_GetCount(party) - 1) {
            return 0;
        }
        return POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(party, slot));
    }
    return func_02007A18(save, box, slot);
}

u32 WORLDTRADE_BOX_GetMonCount(u8 *p, u32 b, u32 c)
{
    if (WORLDTRADE_BOX_ClampSlot(c) != 0) {
        return POKEPARTY_GetCount(p);
    }
    return func_020078C4((void *)b, c);
}

int WORLDTRADE_BOX_CanRemoveMon(void *party, void *save, int box, int slot)
{
    if (WORLDTRADE_BOX_ClampSlot(box) != 0 && (int)POKEPARTY_GetCount(party) < 2) {
        return 0;
    }
    return 1;
}

u32 WORLDTRADE_BOX_GetBoxCount(void *sav)
{
    u32 f = func_02017DBC(sav);
    u32 i;
    u32 r;

    for (i = 0; i < 15; i++) {
        r = func_02017E88(sav, tbl_02202C58[i], 0);
        if (r == 1) {
            break;
        }
    }
    func_02017DE4(sav, f);
    return r;
}

/*
 * Restart the channel: stamp, force ports 5 and 0x6f to zero, hand the stamp over.
 */
int WORLDTRADE_BOX_CheckMonRestrictionA(u32 handle)
{
    u32 stamp = func_02017DBC((struct Sav *)handle);

    func_02017E88((void *)handle, 5, 0);
    func_02017E88((void *)handle, 0x6f, 0);
    func_02017DE4((struct Sav *)handle, stamp);
    return 0;
}

/*
 * Restart the channel: take a stamp, force port 6 to zero and hand the handle over.
 */
int WORLDTRADE_BOX_CheckMonRestrictionB(u32 handle)
{
    u32 stamp = func_02017DBC((struct Sav *)handle);

    func_02017E88((void *)handle, 6, 0);
    func_02017DE4((struct Sav *)handle, stamp);
    return 0;
}

int WORLDTRADE_BOX_GetMonTradeState(void *party, void *save, int box, int slot)
{
    void *mon = WORLDTRADE_BOX_GetPartyMon(party, save, box, slot);

    if (mon == 0) {
        return 0;
    }
    if (func_02017E88(mon, 0xA9, 0) == 0) {
        return 0;
    }
    if (func_02017E88(mon, 0xAA, 0) != 0) {
        return 2;
    }
    return 1;
}

int WORLDTRADE_BOX_TagMatchesRequest(MonTag *pa, WantTag *pb)
{
    signed char a3;
    signed char b3;
    signed char b4;
    signed char b2;

    if (pa->species != pb->species)
        return 0;
    b2 = pb->form;
    if (b2 != 3 && b2 != pa->form)
        return 0;
    a3 = pa->gender;
    if (a3 == 0)
        return 0;
    b3 = pb->b3;
    if (b3 != 0 && b3 > a3)
        return 0;
    b4 = pb->b4;
    if (b4 != 0 && b4 < a3)
        return 0;
    return 1;
}

int WORLDTRADE_BOX_MonMatchesRequest(void *mon, WantTag *want)
{
    MonTag t;

    t.species = func_02017E88(mon, 5, 0);
    t.form = func_02017E88(mon, 0x6E, 0) + 1;
    t.gender = POKE_TOOL_CalcBoxLevel(mon);
    return WORLDTRADE_BOX_TagMatchesRequest(&t, want);
}

void WORLDTRADE_BOX_BuildDepositFromWork(Deposit *dst, Work *p)
{
    MonTag m;
    WantTag w;
    void *e;

    m.species = func_02017E88(p->mon, 5, 0);
    m.form = func_02017E88(p->mon, 0x6E, 0) + 1;
    m.gender = POKE_TOOL_CalcBoxLevel(p->mon);
    dst->have = m;
    WORLDTRADE_DEPOSIT_BuildOffer((Entry *)dst, p);
    e = POKE_TOOL_GetBoxParam(p->list[p->cur]);
    w.species = func_02017E88(e, 5, 0);
    w.form = func_02017E88(e, 0x6E, 0) + 1;
    w.b3 = 0;
    w.b4 = 0;
    dst->want = w;
}

void WORLDTRADE_BOX_ScoreMatchingRecords(Rec_p03 *recs, u32 unused, WantTag *key, Entry_021F6DB4 *ent)
{
    int i;

    for (i = 0; i < 30; i++) {
        if (recs[i].a != 0 && WORLDTRADE_BOX_TagMatchesRequest((MonTag *)(&recs[i]), key) == 0) {
            ent[i].f4 += 3;
        }
    }
}

/*
 * Read port 6 and report whether the follow-up check accepted it.
 */
int WORLDTRADE_BOX_IsSpeciesFlagged(u32 handle)
{
    int ok = 0;
    u16 v = (u16)func_02017E1C((void *)handle, 6, 0);

    if (FILE_UTIL_Check136C(v) != 0) {
        ok = 1;
    }
    return ok;
}

void WORLDTRADE_BOX_RestoreCursorSave(Work *p)
{
    unsigned i;
    p->count = func_020076A4(p->ctx->save);
    if (p->count < 24) {
        for (i = 0; i < p->count; i++) {
            if (func_020078C4(p->ctx->save, i) == 0) break;
        }
        if (i == p->count) p->count = func_020076B4(p->ctx->save);
    }
}

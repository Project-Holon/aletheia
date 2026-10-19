/*
 * file:     worldtrade_deposit.c
 * unit:     yes
 * function: WORLDTRADE_DEPOSIT_Init, WORLDTRADE_DEPOSIT_Main, WORLDTRADE_DEPOSIT_Exit, WORLDTRADE_DEPOSIT_PrintMessage, WORLDTRADE_DEPOSIT_SetupBgPlanes, WORLDTRADE_DEPOSIT_ExitBgPlanes, WORLDTRADE_DEPOSIT_LoadBgGraphics, WORLDTRADE_DEPOSIT_CreateWindows, WORLDTRADE_DEPOSIT_DeleteWindows, WORLDTRADE_DEPOSIT_CreateActors, WORLDTRADE_DEPOSIT_DeleteActors, WORLDTRADE_DEPOSIT_CreateStrings, WORLDTRADE_DEPOSIT_DeleteStrings, WORLDTRADE_DEPOSIT_WaitWipeIn, WORLDTRADE_DEPOSIT_StateWaitCancel, WORLDTRADE_DEPOSIT_StateOpenCategoryMenu, WORLDTRADE_DEPOSIT_StateCategoryMenuInput, WORLDTRADE_DEPOSIT_StateCreateSpeciesMenu, WORLDTRADE_DEPOSIT_CheckGenderEvent, WORLDTRADE_DEPOSIT_StateSpeciesMenuInput, WORLDTRADE_DEPOSIT_StatePrintGenderPrompt, WORLDTRADE_DEPOSIT_StateOpenGenderMenu, WORLDTRADE_DEPOSIT_StateGenderMenuInput, WORLDTRADE_DEPOSIT_StatePrintLevelPrompt, WORLDTRADE_DEPOSIT_StateOpenLevelMenu, WORLDTRADE_DEPOSIT_StateLevelMenuInput, WORLDTRADE_DEPOSIT_StatePrintConfirmPrompt, WORLDTRADE_DEPOSIT_StateOpenConfirmYesNo, WORLDTRADE_DEPOSIT_StateConfirmYesNoInput, WORLDTRADE_DEPOSIT_StateStartWipeOut, WORLDTRADE_DEPOSIT_StateWaitMessage, WORLDTRADE_DEPOSIT_GetModeColor, WORLDTRADE_DEPOSIT_PrintName, WORLDTRADE_DEPOSIT_PrintBankString, WORLDTRADE_DEPOSIT_PrintMessageLine, WORLDTRADE_DEPOSIT_GetModeFontColor, WORLDTRADE_DEPOSIT_PrintModeLabelAligned, WORLDTRADE_DEPOSIT_PrintModeLabel, WORLDTRADE_DEPOSIT_PrintLevelRange, WORLDTRADE_DEPOSIT_PrintConditionLabel, WORLDTRADE_DEPOSIT_DrawRequestWindow, WORLDTRADE_DEPOSIT_DrawRequestWindowAlt, WORLDTRADE_DEPOSIT_PrintMonSummary, WORLDTRADE_DEPOSIT_LoadSpeciesList, WORLDTRADE_DEPOSIT_GetSpeciesRange, WORLDTRADE_DEPOSIT_GetSpeciesFlag, WORLDTRADE_DEPOSIT_BuildOffer, WORLDTRADE_DEPOSIT_StoreOfferInWork, WORLDTRADE_DEPOSIT_CreateSpeciesMenu, WORLDTRADE_DEPOSIT_CreateSpeciesMenuList, WORLDTRADE_DEPOSIT_CreateGenderMenu, WORLDTRADE_DEPOSIT_GetLevelBracket, WORLDTRADE_DEPOSIT_GetConditionIndex
 * address:  0x021F73DC
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
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MYSTATUS_GetOutfitVariant  0x02008550  thumb
 *   SAVEDATA_PanicFail 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   WORLDTRADE_TITLE_ScrollBg 0x021FFFE8 thumb ov135
 *   WORLDTRADE_ENTER_RestartNetTimeout 0x021F9254 thumb ov135
 *   WORLDTRADE_TITLE_ExitBgPlanes 0x022000E4 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   BG_SYS_InitRun  0x02040B94  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   WORLDTRADE_TITLE_LoadSubBgSwap 0x02200B34 thumb ov135
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_StopActorAnim  0x0204B974  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   WORLDTRADE_INPUT_PrintStringAlignedLine  0x021F91A0  thumb
 *   WORLDTRADE_TITLE_CreateMenuWindow  0x02200BAC  thumb
 *   WORLDTRADE_ADAPTER_DeletePrintStream 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Create 0x020457B0 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
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
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WORLDTRADE_INPUT_MenuCreate 0x021F9890 thumb ov135
 *   g_02203BBC  0x02203BBC  data  ov135
 *   WORLDTRADE_INPUT_MenuDelete 0x021F99D0 thumb ov135
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   g_02202F64  0x02202F64  data  ov135
 *   g_02202F84  0x02202F84  data  ov135
 *   g_02202F44  0x02202F44  data  ov135
 *   g_02202FA4  0x02202FA4  data  ov135
 *   ARC_UTIL_UploadBgCharFromArchive 0x02049624 arm
 *   ARC_UTIL_UploadBgPaletteFromArchive 0x0204989C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   tbl_02202EC0 0x02202EC0 data a2
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   WORLDTRADE_ENTER_ClearListRange 0x021F8990 thumb ov135
 *   g_02203C00 0x02203C00 data a4
 *   WORLDTRADE_INPUT_MenuSetMode  0x021F9968  thumb  ov135
 *   WORLDTRADE_ENTER_UpdateListMenu 0x021F8950 thumb ov135
 *   WORLDTRADE_ADAPTER_ClearWindowScreen 0x02202644 thumb ov135
 *   WORLDTRADE_INPUT_MenuUpdate 0x021F99F0 thumb ov135
 *   WORLDTRADE_ENTER_SetListRangeEntry 0x021F89A8 thumb ov135
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   WORLDTRADE_ADAPTER_PrintQueColor  0x022028C8  thumb
 *   tbl_02202EB0   0x02202EB0  data
 *   WORLDTRADE_ADAPTER_CreateString  0x02202670  thumb
 *   ARC_UTIL_LoadMemberWithSize  0x0204A298  arm
 *   tbl_0220307C   0x0220307C  data
 *   WORLDTRADE_ADAPTER_CopyBoxMon  0x022026A0  thumb
 *   tbl_02203B84 0x02203B84 data a2
 *   d_02202ED8 0x02202ED8 data a4
 *   tbl_0220301C 0x0220301C data a4
 *   tbl_02202FC4 0x02202FC4 data a4
 *   str_02203C18 0x02203C18 data a1
 *   POKE_TOOL_ChangeBoxForm  0x020179B8  thumb  arm9
 *   POKE_TOOL_CalcBoxLevel  0x02018438  thumb  arm9
 *   POKE_TOOL_ChangeForm  0x02017988  thumb  arm9
 *   BMP_MENUWORK_Create  0x0201F81C  thumb  arm9
 *   BMP_MENUWORK_Delete  0x0201F868  thumb  arm9
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9
 *   BMP_MENULIST_Create  0x0201FF30  thumb  arm9
 *   BMP_MENULIST_Delete  0x0202020C  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   ZUKAN_SAVE_IsSeen  0x0200D064  thumb  arm9
 *   WORLDTRADE_ClearBusyFlag  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   WORLDTRADE_DEPOSIT_CreateGenderMenu 0x021F87E0 thumb ov135
 *   WORLDTRADE_DEPOSIT_LoadSpeciesList  0x021F8498  thumb
 *   WORLDTRADE_DEPOSIT_GetSpeciesRange  0x021F84BC  thumb
 *   MYSTATUS_GetName 0x020084F4 thumb
 *   WORLDTRADE_DEPOSIT_GetConditionIndex 0x021F886C thumb ov135
 *   WORLDTRADE_DEPOSIT_DrawRequestWindowAlt 0x021F8290 thumb ov135
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_UpdateTaskMenuYesNo 0x021F4D14 thumb ov135
 *   WORLDTRADE_CloseTaskMenu 0x021F4CE4 thumb ov135
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORLDTRADE_DEPOSIT_PrintBankString  0x021F7FD4  thumb
 *   WORLDTRADE_DEPOSIT_PrintModeLabel  0x021F8104  thumb
 *   WORLDTRADE_DEPOSIT_PrintConditionLabel  0x021F8178  thumb
 *   WORLDTRADE_DEPOSIT_PrintName  0x021F7F9C  thumb
 *   WORLDTRADE_DEPOSIT_PrintModeLabelAligned  0x021F8098  thumb
 *   WORLDTRADE_DEPOSIT_PrintLevelRange  0x021F8154  thumb
 *   WORLDTRADE_DEPOSIT_PrintMessageLine  0x021F8010  thumb
 *   WORLDTRADE_DEPOSIT_GetSpeciesFlag  0x021F84EC  thumb
 *   WORLDTRADE_DEPOSIT_CheckGenderEvent 0x021F7B9C thumb ov135
 *   WORLDTRADE_DEPOSIT_GetLevelBracket 0x021F882C thumb ov135
 *   WORLDTRADE_OpenTaskMenuYesNoDefault  0x021F4BE0  thumb  ov135
 *   WORLDTRADE_BOX_ClampSlot 0x021F6B34 thumb ov135
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   WIFI_HISTORY_GetVisitedCountryCount  0x02009584  thumb  arm9
 *   WORDSET_CopyString  0x0201F41C  thumb  arm9
 *   MYSTATUS_GetId  0x02008530  thumb  arm9
 *   MYSTATUS_GetOutfit  0x02008554  thumb  arm9
 *   MYSTATUS_GetLanguage  0x0200856C  thumb  arm9
 *   MYSTATUS_GetVersion  0x02008570  thumb  arm9
 *   WIFI_HISTORY_GetRatingLevel  0x0200960C  thumb  arm9
 *   WIFI_HISTORY_GetGreetingSet  0x02009628  thumb  arm9
 */
#include "worldtrade_types.h"

struct Src;

typedef struct { void *a,*b,*obj,*d,*e,*f,*g,*h,*i; u32 j,k,l; } Init;

typedef struct {
    u32 id;
    union {
        struct { s16 x; s16 y; };
        struct { s16 key; s16 val; };
    };
} TableRow;

/* Menu-list source descriptor handed to BMP_MENULIST_Create as `struct Src`. */
typedef struct { u32 ptrs[4]; u16 count, rows; u32 extra[8]; } MenuSrc;

extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 WIPE_SYS_EndCheck(void);

extern u32 GFL_HEAP_Free(void *p);

extern void SAVEDATA_PanicFail(const char *expr, u32 line, const char *file);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern void ARC_TOOL_DeleteHandle(void *h);

extern u8 MYSTATUS_GetOutfitVariant(const struct Sub0200852CObj *obj);

extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void BG_SYS_PushTile(u32 v);

extern void WORLDTRADE_TITLE_ScrollBg(Work *, u32, u32);

extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);

extern void WORLDTRADE_ENTER_RestartNetTimeout(u8 *);

extern void WORLDTRADE_TITLE_ExitBgPlanes(char *p);

extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void BG_SYS_ClearSlot(u32 i);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);

extern void BG_SYS_SetTileEntry(u32 layer, int value, int x0, int y0, u8 w, u8 h, u8 mode);

extern void BG_SYS_FreeLayerBuf(u32 i);

extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);

extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void WORLDTRADE_TITLE_LoadSubBgSwap(Work *);

extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);

extern void CLACT_SetActorAutoAnim(struct Obj *, u32);

extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

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

extern void GFL_USE_PlaySeDefaultVolume(u32 se);

extern u32 KEY_GetTrg(void);

extern void *BMP_MENUWORK_Create(u32 a, u32 b);

extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);

extern u32 BMP_MENUWORK_Delete(void *p);

extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);

extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);

extern int POKE_TOOL_ChangeBoxForm(int box, int newForm);

extern u32 WORLDTRADE_ADAPTER_IsStreamDone(PrintStreamCtx *p);

extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);





extern u8 unit_02045730(u32 a);


extern void BMP_MENUWORK_DrawWindow(void *win, int commitMode, int tileBase, int palette);


extern u32 WORLDTRADE_ADAPTER_QueuePrintDefaultColor(void *p, u8 b, void *s, u32 x, u32 y, void *out);

extern void MIi_CpuCopyFast(const void *src, void *dst, u32 n);

extern u32 POKE_TOOL_CalcBoxLevel(void *p);

extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);

extern void *WORLDTRADE_INPUT_MenuCreate(Init *,u32,u32);

extern void WORLDTRADE_INPUT_MenuDelete(u8 *p);

extern u32 ARC_UTIL_UploadBgCharFromArchive(void *archiveID, void *memberIdx, void *bgId, void *tileOffset, u32 size, u32 heapID, u16 allocFlags);

extern void ARC_UTIL_UploadBgPaletteFromArchive(u32 archiveID, u32 memberIdx, u32 channel, u32 offset, u32 size, u32 heapID, u16 flags);

extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);

extern void WORLDTRADE_ENTER_ClearListRange(u8 *p);

extern void WORLDTRADE_INPUT_MenuSetMode(u8 *p, int mode);

extern int WORLDTRADE_ENTER_UpdateListMenu(void *p, u16 *old);

extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);

extern void WORLDTRADE_ADAPTER_ClearWindowScreen(u32 a, int kind);

extern int WORLDTRADE_INPUT_MenuUpdate(void *);

extern void *POKE_PERSONAL_Create(u32,int,u32);

extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);

extern void POKE_PERSONAL_Delete(void *p);

extern void WORLDTRADE_ENTER_SetListRangeEntry(u8 *p, int i, u16 a, u16 b);

extern u32 WORLDTRADE_ADAPTER_PrintQueColor(void *win, u32 z, void *str, u32 x, u32 y, u32 z2, u16 color, void *g);

extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

extern u32 WORLDTRADE_ADAPTER_CreateString(u32 a, u32 b, u32 c, u32 d);

extern int ARC_UTIL_LoadMemberWithSize(int archiveID, int memberIdx, int decompress, int heapID, u32 *out);

extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);

extern u32 POKE_TOOL_GetPartyParamSize(void);

extern void WORLDTRADE_ADAPTER_CopyBoxMon(u8 *p, u32 k);

extern const void *MYSTATUS_GetName(const void *p);

extern void WORDSET_CopyString(const u16 *src, u16 *dst, u32 n);

extern u32 MYSTATUS_GetId(const struct Sub0200852CObj *obj);

extern u8 MYSTATUS_GetLanguage(const struct Sub0200852CObj *obj);

extern u8 MYSTATUS_GetVersion(const struct Sub0200852CObj *obj);

extern u8 MYSTATUS_GetOutfit(const struct Sub0200852CObj *obj);

extern u8 WIFI_HISTORY_GetGreetingSet(const struct Sub02009470Obj *obj);

extern u8 WIFI_HISTORY_GetVisitedCountryCount(const struct Sub02009470Obj *obj);

extern u8 WIFI_HISTORY_GetRatingLevel(const struct Sub02009470Obj *obj);

extern u32 ZUKAN_SAVE_IsSeen(struct Blk37 *p, u16 id);

extern struct Obj *BMP_MENULIST_Create(struct Src *src, u16 a, u16 b, u32 heap);

void WORLDTRADE_OpenTaskMenuYesNoDefault(u32 a, u32 b, u32 c, u32 d, u8 e);

void WORLDTRADE_CloseTaskMenu(Work *p);

int WORLDTRADE_UpdateTaskMenuYesNo(Work *p);

void WORLDTRADE_SetNextState(Work *p, u32 a, u32 b);

void WORLDTRADE_SetStateAndReturn(Work *p, u32 a, u32 b);

void WORLDTRADE_ClearBusyFlag(Work *p);

int WORLDTRADE_BOX_ClampSlot(int v);

int WORLDTRADE_DEPOSIT_Init(Work *p);

void WORLDTRADE_DEPOSIT_Main(u8 *p);

int WORLDTRADE_DEPOSIT_Exit(Work *p);

void WORLDTRADE_DEPOSIT_PrintMessage(Work *p, u32 b, u32 c, u32 d, u32 e);

void WORLDTRADE_DEPOSIT_SetupBgPlanes(void);

void WORLDTRADE_DEPOSIT_ExitBgPlanes(void);

void WORLDTRADE_DEPOSIT_LoadBgGraphics(Work *p);

void WORLDTRADE_DEPOSIT_CreateWindows(Work *p);

void WORLDTRADE_DEPOSIT_DeleteWindows(Work *p);

void WORLDTRADE_DEPOSIT_CreateActors(Work *p);

void WORLDTRADE_DEPOSIT_DeleteActors(Work *p);

void WORLDTRADE_DEPOSIT_CreateStrings(Work *p);

void WORLDTRADE_DEPOSIT_DeleteStrings(Work *p);

int WORLDTRADE_DEPOSIT_WaitWipeIn(Work *p);

int WORLDTRADE_DEPOSIT_StateWaitCancel(Work *p);

int WORLDTRADE_DEPOSIT_StateOpenCategoryMenu(Work *p);

int WORLDTRADE_DEPOSIT_StateCategoryMenuInput(Work *p);

int WORLDTRADE_DEPOSIT_StateCreateSpeciesMenu(Work *p);

int WORLDTRADE_DEPOSIT_CheckGenderEvent(u8 *p, int event);

int WORLDTRADE_DEPOSIT_StateSpeciesMenuInput(Work *p);

int WORLDTRADE_DEPOSIT_StatePrintGenderPrompt(Work *p);

int WORLDTRADE_DEPOSIT_StateOpenGenderMenu(Work *p);

int WORLDTRADE_DEPOSIT_StateGenderMenuInput(Work *p);

int WORLDTRADE_DEPOSIT_StatePrintLevelPrompt(Work *p);

int WORLDTRADE_DEPOSIT_StateOpenLevelMenu(Work *p);

int WORLDTRADE_DEPOSIT_StateLevelMenuInput(Work *p);

int WORLDTRADE_DEPOSIT_StatePrintConfirmPrompt(Work *p);

int WORLDTRADE_DEPOSIT_StateOpenConfirmYesNo(Work *p);

int WORLDTRADE_DEPOSIT_StateConfirmYesNoInput(Work *p);

int WORLDTRADE_DEPOSIT_StateStartWipeOut(Work *p);

int WORLDTRADE_DEPOSIT_StateWaitMessage(Work *p);

u16 WORLDTRADE_DEPOSIT_GetModeColor(int mode);

void WORLDTRADE_DEPOSIT_PrintName(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *g);

void WORLDTRADE_DEPOSIT_PrintBankString(void *win, void *bank, u32 index, u32 y, u16 color, void *g);

void WORLDTRADE_DEPOSIT_PrintMessageLine(void *win, void *bank, void *bank2, u32 index, u32 y, u32 x, u16 color, void *g);

u16 WORLDTRADE_DEPOSIT_GetModeFontColor(int mode, u16 color);

void WORLDTRADE_DEPOSIT_PrintModeLabelAligned(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *g);

void WORLDTRADE_DEPOSIT_PrintModeLabel(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *g);

void WORLDTRADE_DEPOSIT_PrintLevelRange(void *win, void *bank, int idx, u32 e, u32 y, u16 color, int alt, void *g);

void WORLDTRADE_DEPOSIT_PrintConditionLabel(void *win, void *bank, int idx, u32 e, u32 x, u32 y, u16 color, int alt, u32 g);

void WORLDTRADE_DEPOSIT_DrawRequestWindow(void *bank, void *names, int unused, void **win, u32 index, int mode, int place, void *g);

void WORLDTRADE_DEPOSIT_DrawRequestWindowAlt(void *bank, void *names, int unused, void **win, u32 index, int mode, int place, void *g);

void WORLDTRADE_DEPOSIT_PrintMonSummary(void *bank, void *ws, void **win, void *mon, MonTag *out, void *g);

u16 *WORLDTRADE_DEPOSIT_LoadSpeciesList(u32 heap, u32 unused, u32 *count);

void WORLDTRADE_DEPOSIT_GetSpeciesRange(u32 i, int *start, int *end);

u8 *WORLDTRADE_DEPOSIT_GetSpeciesFlag(u32 id);

void WORLDTRADE_DEPOSIT_BuildOffer(Entry *dst, Work *p);

void WORLDTRADE_DEPOSIT_StoreOfferInWork(Deposit *dst, Work *p);

int WORLDTRADE_DEPOSIT_CreateSpeciesMenu(void **menu, void *msg, void *endmsg, u16 *list, u32 unused4, u32 unused5, u32 kind, void *bag);

void *WORLDTRADE_DEPOSIT_CreateSpeciesMenuList(Work *p, void **menu, void *win, void *endmsg, void *msg, DepositState *cfg, void *bag);

int WORLDTRADE_DEPOSIT_CreateGenderMenu(void **menu, void *msg, int kind);

void WORLDTRADE_DEPOSIT_GetLevelBracket(u8 *dst, int i, int kind);

int WORLDTRADE_DEPOSIT_GetConditionIndex(int key, int val, int which);

extern void (*g_02203BBC[])(u8 *);

extern struct BgTemplate g_02202F64;

extern struct BgTemplate g_02202F84;

extern struct BgTemplate g_02202F44;

extern struct BgTemplate g_02202FA4;

extern const u16 tbl_02202EC0[][2];

extern const char g_02203C00[];

extern const u32 tbl_02202EB0[];

extern const int tbl_0220307C[];

extern const u16 tbl_02203B84[];

extern const MenuSrc d_02202ED8;

extern const TableRow tbl_0220301C[12];

extern const TableRow tbl_02202FC4[11];

extern const char str_02203C18[];

int WORLDTRADE_DEPOSIT_Init(Work *p)
{
    Init init;
    WORLDTRADE_DEPOSIT_CreateStrings(p);
    WORLDTRADE_DEPOSIT_SetupBgPlanes();
    WORLDTRADE_TITLE_ScrollBg(p,0,0);
    WORLDTRADE_DEPOSIT_LoadBgGraphics(p);
    WORLDTRADE_DEPOSIT_CreateWindows((Work *)p);
    WORLDTRADE_DEPOSIT_CreateActors(p);
    WIPE_SYS_Start((void *)3,1,1,0,6,1,0x48);
    WORLDTRADE_ENTER_RestartNetTimeout((u8 *)p);
    WORLDTRADE_DEPOSIT_DrawRequestWindow(p->bank,p->names,(int)(p->words),(void **)((u8 *)p+0xD90),0,3,-1,(u8 *)p+0xFA0);
    WORLDTRADE_DEPOSIT_PrintMonSummary(p->bank,p->words,(void **)((u8 *)p+0xD9C),p->mon,(MonTag *)((u8 *)p+0xB4C),(u8 *)p+0xFA0);
    init.a=(u8 *)p+0xD50;
    init.b=(u8 *)p+0xDD4;
    init.obj=p->mark;
    init.d=p->btn[0];
    init.e=p->btn[1];
    init.f=0;
    init.g=p->bank;
    init.h=p->names;
    init.i=p->msg_p;
    init.j=(u32)p->ctx->dex;
    init.k=(u32)((DepositState *)p->st)->speciesFlags;
    init.l=(u32)p->ctx->statusConfig;
    p->menu=WORLDTRADE_INPUT_MenuCreate(&init,2,0);
    p->state=0;
    p->keepBgLayers=0;
    return 1;
}

/*
 * State-table dispatch through the table at 0x02203BBC.
 */
void WORLDTRADE_DEPOSIT_Main(u8 *p)
{
    g_02203BBC[*(u32 *)(p + 0x28)](p);
}

int WORLDTRADE_DEPOSIT_Exit(Work *p)
{
    WORLDTRADE_DEPOSIT_DeleteActors((Work *)(void *)p);
    WORLDTRADE_INPUT_MenuDelete(p->menu);
    WORLDTRADE_DEPOSIT_DeleteStrings((Work *)p);
    WORLDTRADE_DEPOSIT_DeleteWindows((Work *)p);
    WORLDTRADE_DEPOSIT_ExitBgPlanes();
    WORLDTRADE_TITLE_ExitBgPlanes((char *)p);
    CLACT_SetActorDrawEnable((struct Obj *)*(unsigned *)&p->scrollBarObj, 0);
    WORLDTRADE_ClearBusyFlag((Work *)(void *)p);
    return 0;
}

/*
 * Handle walk: 02045EC0 over the 0xb6c field, the 0xb68/0xb88 pair through
 * 0201F250, then the p+0xd40 window through the 02045334/02045374/
 * 02045730/020409B4 group and a 02202858 redraw with the p+0xfa0 block.
 */
void WORLDTRADE_DEPOSIT_PrintMessage(Work *p, u32 msgId, u32 unused1, u32 unused2, u32 unused3)
{
    u32 v = (u32)MSGDATA_AllocString((struct MsgBank *)(*(u32 *)&p->bank), msgId);
    u32 h;

    WORDSET_CopyTaggedText((struct WordSet *)(*(u32 *)&p->words), (void *)((*(unsigned int *)&p->str)), (void *)v);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->frame)), 0xf);
    h = p->frame;
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    BG_SYS_PushTile(unit_02045730(h));
    BMP_MENUWORK_DrawWindow((void *)(p->frame), 0, 1, 0xe);
    WORLDTRADE_ADAPTER_QueuePrintDefaultColor((void *)(p->frame), 0, (void *)((*(unsigned int *)&p->str)), 0, 0, (u8 *)p + 0xfa0);
    STRBUF_Delete((struct U16Vec *)v);
}

/*
 * Four-layer bring-up with no display restore: layer 2 is seeded by the
 * 02041300 tile dump and its 020409B4 redraw before the enable.
 */
void WORLDTRADE_DEPOSIT_SetupBgPlanes(void)
{
    {
        struct BgTemplate t = g_02202F64;
        BG_SYS_InitBgLayer(0, &t, 0);
    }
    BG_SYS_ClearSlot(0);
    BG_SYS_SetPlaneVisible(0, 1);
    {
        struct BgTemplate t = g_02202F84;
        BG_SYS_InitBgLayer(1, &t, 0);
    }
    BG_SYS_SetPlaneVisible(1, 1);
    {
        struct BgTemplate t = g_02202F44;
        BG_SYS_InitBgLayer(2, &t, 0);
    }
    BG_SYS_SetTileEntry(2, 0, 0, 0, 0x20, 0x18, 0);
    BG_SYS_PushTile(2);
    BG_SYS_SetPlaneVisible(2, 1);
    {
        struct BgTemplate t = g_02202FA4;
        BG_SYS_InitBgLayer(3, &t, 0);
    }
    BG_SYS_ClearSlot(3);
    BG_SYS_SetPlaneVisible(3, 1);
    BG_SYS_InitRun(0, 0x20, 0, 0x48);
    BG_SYS_InitRun(3, 0x20, 0, 0x48);
}

/*
 * Poke the channel-selection helper with 2, 1, 0, 3 in turn.
 */
void WORLDTRADE_DEPOSIT_ExitBgPlanes(void)
{
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_FreeLayerBuf(3);
}

void WORLDTRADE_DEPOSIT_LoadBgGraphics(Work *p)
{
    void *h = ARC_TOOL_CreateHandle(0x60, 0x48);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x60, 0, 0, 0, 0x40, 0x48);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1A0, 0x20, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 14, 0, 0x48);
    BMP_MENUWORK_LoadCharAndPltt(0, 31, 11, 0, 0x48);
    ARC_UTIL_UploadBgCharFromArchive((void *)0x60, (void *)9, (void *)1, 0, 0, 1, 0x48);
    ARC_UTIL_UploadBgPaletteFromArchive(0x60, 20, 1, 0, 0x600, 1, 0x48);
    ARC_UTIL_UploadBgCharFromHandle(h, 12, 2, 0, 0, 1, 0x48);
    WORLDTRADE_TITLE_LoadSubBgSwap(p);
    ARC_TOOL_DeleteHandle(h);
}

void WORLDTRADE_DEPOSIT_CreateWindows(Work *p)
{
    void *w;
    int i;
    p->d40 = (void *)BMP_WIN_Create(0, (u8)2, (u8)21, (u8)27, 2, 13, (u16)1);
    BMP_Clear(BMP_WIN_GetBmp(p->d40), 0);
    w = p->d40;
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(w));
    for (i = 0; i < 6; i++) {
        p->wins[i] = (void *)BMP_WIN_Create(3, (u8)tbl_02202EC0[i][0], (u8)tbl_02202EC0[i][1], (u8)12, 2, 13, (u16)1);
        BMP_Clear(BMP_WIN_GetBmp(p->wins[i]), 0);
        w = p->wins[i];
        BMP_WIN_TransferChars(w);
        BMP_WIN_MakeScreen(w);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(w));
    }
    WORLDTRADE_TITLE_CreateMenuWindow(p, 3);
}

void WORLDTRADE_DEPOSIT_DeleteWindows(Work *p) { int i; WORLDTRADE_ADAPTER_DeletePrintStream((struct Obj *)((char *)p+0xfa0)); BMP_WIN_Delete(p->msgWin); for(i=0;i<6;i++) BMP_WIN_Delete(*(void **)((u32)(char *)p+(u32)i*4+0xd90)); BMP_WIN_Delete(p->d40); }

/*
 * CLACT_CreateActor returns the object consumed by the subsequent calls and stores.
 * Matched ov135 neighbours prove its pointer request in the fifth slot.
 */
void WORLDTRADE_DEPOSIT_CreateActors(Work *p)
{
    ObjPos pos;
    MI_CpuFill8(&pos,0,8);
    pos.x=0xA0;
    pos.y=0x20;
    p->mark=CLACT_CreateActor(p->res,(unsigned int)p->set2,(unsigned int)p->set[1],(unsigned int)p->set3,&pos,0,0x48);
    CLACT_SetActorAnimSeq(p->mark,12);
    CLACT_SetActorAutoAnim(p->mark,1);
    CLACT_StopActorAnim(p->mark);
    CLACT_SetActorDrawEnable(p->mark,0);
    pos.x=0xE4;
    pos.y=0x75;
    p->btn[0]=CLACT_CreateActor(p->res,(unsigned int)p->set[0],(unsigned int)p->set[1],(unsigned int)p->set[2],&pos,0,0x48);
    CLACT_SetActorAnimSeq(p->btn[0],0x26);
    CLACT_SetActorDrawEnable(p->btn[0],0);
    pos.x=0x8C;
    p->btn[1]=CLACT_CreateActor(p->res,(unsigned int)p->set[0],(unsigned int)p->set[1],(unsigned int)p->set[2],&pos,0,0x48);
    CLACT_SetActorAnimSeq(p->btn[1],0x27);
    CLACT_SetActorDrawEnable(p->btn[1],0);
}

/*
 * Release the +0xbf8, +0xd2c and +0xd30 handles.
 */
void WORLDTRADE_DEPOSIT_DeleteActors(Work *p)
{
    CLACT_DeleteActor((struct Obj *)(p->sub.depositMarkObj));
    CLACT_DeleteActor((struct Obj *)((*(unsigned int *)&p->btn[0])));
    CLACT_DeleteActor((struct Obj *)((*(unsigned int *)&p->btn[1])));
}

void WORLDTRADE_DEPOSIT_CreateStrings(Work *p)
{
    p->str = STRBUF_Create(0xB4, 0x48);
    (*(void **)&p->st) = GFL_HEAP_Alloc(0x48, 0x30, 0, g_02203C00, 0x2B4);
    MIi_CpuClearFast(0, (void *)p->st, 0x30);
    ((DepositState *)p->st)->speciesList = WORLDTRADE_DEPOSIT_LoadSpeciesList(0x48, 0, &((DepositState *)p->st)->speciesCount);
    ((DepositState *)p->st)->speciesFlags = WORLDTRADE_DEPOSIT_GetSpeciesFlag(0x48);
    WORLDTRADE_ENTER_ClearListRange((u8 *)p + 0xEEC);
}

void WORLDTRADE_DEPOSIT_DeleteStrings(Work *p) { GFL_HEAP_Free(((DepositState *)p->st)->speciesFlags); GFL_HEAP_Free(((DepositState *)p->st)->speciesList); GFL_HEAP_Free((void *)p->st); STRBUF_Delete(p->str); }

int WORLDTRADE_DEPOSIT_WaitWipeIn(Work *p) { if(WIPE_SYS_EndCheck()){WORLDTRADE_DEPOSIT_PrintMessage(p,9,1,0,0xf0f);WORLDTRADE_SetNextState(p,16,1);}return 2; }

/*
 * Test bit 1 of the callee result; the odd branch re-latches state 2 before state 3.
 */
int WORLDTRADE_DEPOSIT_StateWaitCancel(Work *p)
{
    u32 v = KEY_GetTrg();

    if (v & 2) {
        WORLDTRADE_SetStateAndReturn(p, 5, 5);
        p->state = 2;
    }
    p->state = 3;
    return 2;
}

/*
 * Hand the buffer at +0xde4 to the writer and stamp state 6.
 */
int WORLDTRADE_DEPOSIT_StateOpenCategoryMenu(Work *p)
{
    WORLDTRADE_INPUT_MenuSetMode((u8 *)((*(unsigned int *)&p->menu)), 0);
    p->state = 6;
    return 2;
}

int WORLDTRADE_DEPOSIT_StateCategoryMenuInput(Work *p)
{
    switch ((unsigned)WORLDTRADE_ENTER_UpdateListMenu(p->speciesMenuList, (u16 *)((u8 *)p + 0xBC))) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        BMP_MENULIST_Delete(p->speciesMenuList, &((DepositState *)p->st)->menuScroll, &((DepositState *)p->st)->menuRow);
        BMP_MENUWORK_Delete(p->de8);
        p->state = 5;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        break;
    case (unsigned)-2:
        BMP_MENULIST_Delete(p->speciesMenuList, &((DepositState *)p->st)->menuScroll, &((DepositState *)p->st)->menuRow);
        BMP_MENUWORK_Delete(p->de8);
        WORLDTRADE_ADAPTER_ClearWindowScreen((u32)(p->side_p2[0]), 0);
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        BMP_WIN_Delete(p->side_p2[0]);
        BMP_WIN_Delete(p->win3);
        WORLDTRADE_SetStateAndReturn(p, 5, 5);
        p->state = 2;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        break;
    case 0:
        break;
    }
    return 2;
}

int WORLDTRADE_DEPOSIT_StateCreateSpeciesMenu(Work *p)
{
    p->speciesMenuList = WORLDTRADE_DEPOSIT_CreateSpeciesMenuList((Work *)p, (void **)((u8 *)p + 0xDE8), p->win3, p->bank, p->names, (DepositState *)((void *)p->st), p->ctx->dex);
    p->menuChoice = 0xFFFF;
    p->state = 6;
    return 2;
}

/*
 * Map the event code to its state byte: 0, 0xfe and 0xff are accepted.
 */
int WORLDTRADE_DEPOSIT_CheckGenderEvent(u8 *p, int event)
{
    switch (event) {
    case 0:
        p[2] = 1;
        return 1;
    case 0xfe:
        p[2] = 2;
        return 1;
    case 0xff:
        p[2] = 3;
        return 1;
    }
    return 0;
}

/*
 * lever: signed halfword selection store keeps the unsigned argument truncation after it.
 */
int WORLDTRADE_DEPOSIT_StateSpeciesMenuInput(Work *p)
{
    int result=WORLDTRADE_INPUT_MenuUpdate(p->menu);
    u32 h,v;
    int mode;
    DepositState *target;
    switch(result) {
    case (u32)-2:
        BMP_MENUWORK_DrawWindowBorder(p->d40,0);
        WORLDTRADE_SetStateAndReturn(p,5,5);
        p->state=2;
        target=(DepositState *)p->st;
        WORLDTRADE_ENTER_SetListRangeEntry((u8 *)p+0xEEC,target->menuScroll+target->menuRow,target->restoreScroll,target->restoreRow);
        break;
    case (u32)-1:
        break;
    default:
        p->wantSpecies=result;
        h=(u32)POKE_PERSONAL_Create((u16)result,0,0x48);
        v=POKE_PERSONAL_GetParam((const struct Personal *)h,20);
        POKE_PERSONAL_Delete((void *)h);
        ((DepositState *)p->st)->genderEvent=v;
        if(WORLDTRADE_DEPOSIT_CheckGenderEvent((u8 *)p+0xB50,((DepositState *)p->st)->genderEvent)) {
            p->state=10;
            mode=p->wantGender;
        } else {
            p->state=7;
            mode=3;
        }
        WORLDTRADE_DEPOSIT_DrawRequestWindow(p->bank,p->names,(int)(p->words),(void **)((u8 *)p+0xD90),p->wantSpecies,mode,-1,(u8 *)p+0xFA0);
        target=(DepositState *)p->st;
        WORLDTRADE_ENTER_SetListRangeEntry((u8 *)p+0xEEC,target->menuScroll+target->menuRow,target->restoreScroll,target->restoreRow);
        break;
    }
    return 2;
}

/*
 * Build through WORLDTRADE_DEPOSIT_PrintMessage and publish the 0x10/0x8 pair.
 */
int WORLDTRADE_DEPOSIT_StatePrintGenderPrompt(Work *p)
{
    WORLDTRADE_DEPOSIT_PrintMessage(p, 0xa, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState(p, 0x10, 0x8);
    return 2;
}

/*
 * Publish the 0xffff sentinel at +0xbc and the u32 at +0xde4, then latch state 9.
 */
int WORLDTRADE_DEPOSIT_StateOpenGenderMenu(Work *p)
{
    p->menuChoice = 0xffff;
    WORLDTRADE_INPUT_MenuSetMode((u8 *)((*(unsigned int *)&p->menu)), 1);
    p->state = 9;
    return 2;
}

int WORLDTRADE_DEPOSIT_StateGenderMenuInput(Work *p)
{
    unsigned result = WORLDTRADE_INPUT_MenuUpdate(p->menu);
    switch (result) {
    case (unsigned)-2:
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        p->state = 0;
        break;
    case 0: case 1: case 2:
        p->wantGender = result + 1;
        p->state = 10;
        WORLDTRADE_DEPOSIT_DrawRequestWindow(p->bank, p->names, (int)(p->words), (void **)((u8 *)p + 0xD90), p->wantSpecies, p->wantGender, -1, (u8 *)p + 0xFA0);
        break;
    }
    return 2;
}

int WORLDTRADE_DEPOSIT_StatePrintLevelPrompt(Work *p)
{
    WORLDTRADE_DEPOSIT_PrintMessage(p, 0xb, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState(p, 0x10, 0xb);
    return 2;
}

/*
 * Publish the u32 at +0xde4, the 0xffff sentinel at +0xbc and latch state 0xc.
 */
int WORLDTRADE_DEPOSIT_StateOpenLevelMenu(Work *p)
{
    WORLDTRADE_INPUT_MenuSetMode((u8 *)((*(unsigned int *)&p->menu)), 2);
    p->menuChoice = 0xffff;
    p->state = 0xc;
    return 2;
}

int WORLDTRADE_DEPOSIT_StateLevelMenuInput(Work *p)
{
    unsigned result = WORLDTRADE_INPUT_MenuUpdate(p->menu);
    switch (result) {
    case 12: case (unsigned)-2:
        BMP_MENUWORK_DrawWindowBorder(p->d40, 0);
        if (WORLDTRADE_DEPOSIT_CheckGenderEvent((u8 *)p + 0xB50, ((DepositState *)p->st)->genderEvent)) {
            p->state = 0;
        } else {
            p->state = 7;
        }
        break;
    case (unsigned)-1:
        break;
    default:
        WORLDTRADE_DEPOSIT_GetLevelBracket((u8 *)p + 0xB50, result, 0);
        p->state = 13;
        result = WORLDTRADE_DEPOSIT_GetConditionIndex(p->wantLevelMin, p->wantLevelMax, 0);
        WORLDTRADE_DEPOSIT_DrawRequestWindow(p->bank, p->names, (int)(p->words), (void **)((u8 *)p + 0xD90), p->wantSpecies, p->wantGender, result, (u8 *)p + 0xFA0);
        break;
    }
    return 2;
}

int WORLDTRADE_DEPOSIT_StatePrintConfirmPrompt(Work *p)
{
    WORLDTRADE_DEPOSIT_PrintMessage(p, 0x17, 1, 0, 0xf0f);
    WORLDTRADE_SetNextState(p, 0x10, 0xe);
    return 2;
}

/*
 * State setter: build with the fixed 0x14/0x126/0x3/0x0 argument pair and latch state 0xf.
 */
int WORLDTRADE_DEPOSIT_StateOpenConfirmYesNo(Work *p)
{
    WORLDTRADE_OpenTaskMenuYesNoDefault((u32)p, 0x14, 0x126, 0x3, 0x0);
    p->state = 0xf;
    return 2;
}

int WORLDTRADE_DEPOSIT_StateConfirmYesNoInput(Work *p)
{
    int result;
    result = WORLDTRADE_UpdateTaskMenuYesNo(p);
    if (result == 1) {
        WORLDTRADE_CloseTaskMenu(p);
        WORLDTRADE_SetStateAndReturn(p, 7, 7);
        p->state = 2;
        p->eb4 = 1;
        WORLDTRADE_DEPOSIT_StoreOfferInWork((Deposit *)&p->single, p);
    } else if (result == 2) {
        WORLDTRADE_CloseTaskMenu(p);
        WORLDTRADE_SetStateAndReturn(p, 5, 5);
        p->state = 2;
    }
    return 2;
}

int WORLDTRADE_DEPOSIT_StateStartWipeOut(Work *p)
{
    if (p->nextScreenId == 0) {
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x48);
        p->eb4 = 1;
    } else {
        WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    p->state = 0;
    return 3;
}

/*
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */
int WORLDTRADE_DEPOSIT_StateWaitMessage(Work *p)
{
    if (WORLDTRADE_ADAPTER_IsStreamDone(&p->printCtx) == 0) {
        p->state = p->returnState;
    }
    return 2;
}

/*
 * Mode table: 0 -> 0x14c0, 1 -> 0xc80, anything else 0.
 */
u16 WORLDTRADE_DEPOSIT_GetModeColor(int mode)
{
    switch (mode) {
    case 0:
        return 0x53 << 6;
    case 1:
        return 0x32 << 6;
    default:
        return 0;
    }
}

void WORLDTRADE_DEPOSIT_PrintName(void *win, void *bank, u32 index, u32 y, u32 x, u16 color, void *printer)
{
    void *str;

    if (index != 0) {
        str = MSGDATA_AllocString(bank, index);
        WORLDTRADE_INPUT_PrintStringAlignedLine(win, str, 0, x, y, color, printer);
        STRBUF_Delete(str);
    }
}

void WORLDTRADE_DEPOSIT_PrintBankString(void *win, void *bank, u32 index, u32 y, u16 color, void *printer)
{
    void *str;

    if (index != 0) {
        str = MSGDATA_AllocString(bank, index);
        WORLDTRADE_ADAPTER_PrintQueColor(win, 0, str, 0, y, 0, color, printer);
        STRBUF_Delete(str);
    }
}

void WORLDTRADE_DEPOSIT_PrintMessageLine(void *win, void *bank, void *bank2, u32 index, u32 y, u32 x, u16 color, void *printer)
{
    void *str;

    if (index != 0) {
        str = MSGDATA_AllocString(bank, index);
        WORLDTRADE_INPUT_PrintStringAlignedLine(win, str, 0, x, y, color, printer);
        STRBUF_Delete(str);
    } else {
        str = MSGDATA_AllocString(bank2, 0xBB);
        WORLDTRADE_INPUT_PrintStringAlignedLine(win, str, 0, x, y, color, printer);
        STRBUF_Delete(str);
    }
}

u16 WORLDTRADE_DEPOSIT_GetModeFontColor(int mode, u16 color)
{
    if (mode == 1) {
        return WORLDTRADE_DEPOSIT_GetModeColor(0);
    }
    if (mode == 2) {
        color = WORLDTRADE_DEPOSIT_GetModeColor(1);
    }
    return color;
}

void WORLDTRADE_DEPOSIT_PrintModeLabelAligned(void *win, void *bank, int mode, int force, u32 x, int y, u16 color, void *printer)
{
    void *str;

    if (force != 0 || mode != 3) {
        str = MSGDATA_AllocString(bank, tbl_02202EB0[mode]);
        if (y > 3) {
            WORLDTRADE_INPUT_PrintStringAlignedLine(win, str, y, x, 0, WORLDTRADE_DEPOSIT_GetModeFontColor(mode, color), printer);
        } else {
            WORLDTRADE_INPUT_PrintStringAlignedLine(win, str, 0, x, y, WORLDTRADE_DEPOSIT_GetModeFontColor(mode, color), printer);
        }
        STRBUF_Delete(str);
    }
}

void WORLDTRADE_DEPOSIT_PrintModeLabel(void *win, void *bank, int mode, int force, u32 x, u32 y, u16 color, void *printer)
{
    void *str;

    if (force != 0 || mode != 3) {
        str = MSGDATA_AllocString(bank, tbl_02202EB0[mode]);
        WORLDTRADE_ADAPTER_PrintQueColor(win, 0, str, x, y, 0, WORLDTRADE_DEPOSIT_GetModeFontColor(mode, color), printer);
        STRBUF_Delete(str);
    }
}

void WORLDTRADE_DEPOSIT_PrintLevelRange(void *win, void *bank, int idx, u32 align, u32 y, u16 color, int alt, void *printer)
{
    WORLDTRADE_DEPOSIT_PrintConditionLabel(win, bank, idx, align, 0, y, color, alt, (u32)printer);
}

void WORLDTRADE_DEPOSIT_PrintConditionLabel(void *win, void *bank, int idx, u32 align, u32 x, u32 y, u16 color, int alt, u32 printer)
{
    const TableRow *tab;
    void *str;

    if (idx != -1) {
        tab = tbl_0220301C;
        if (alt != 0) {
            tab = tbl_02202FC4;
        }
        str = MSGDATA_AllocString(bank, tab[idx].id);
        WORLDTRADE_INPUT_PrintStringAlignedLine(win, str, x, y, align, color, (void *)printer);
        STRBUF_Delete(str);
    }
}

void WORLDTRADE_DEPOSIT_DrawRequestWindow(void *bank, void *names, int unused, void **win, u32 index, int mode, int place, void *printer)
{
    int i;
    void *str;
    int show = 1;
    str = MSGDATA_AllocString(bank, 0x6b);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[0], str, 1, 0, 0, 0x440, printer);
    for (i = 1; i < 3; i++)
        BMP_Clear(BMP_WIN_GetBmp(win[i]), 0);
    WORLDTRADE_DEPOSIT_PrintName(win[1], names, index, 0, 0, 0x440, printer);
    if (index == 29 && mode == 2)
        show = 0;
    else if (index == 32 && mode == 1)
        show = 0;
    if (show) {
        if (mode == 1 || mode == 2)
            WORLDTRADE_DEPOSIT_PrintModeLabelAligned(win[1], bank, mode, 0, 0, 70, 0x440, printer);
    }
    WORLDTRADE_DEPOSIT_PrintLevelRange(win[2], bank, place, 2, 0, 0x440, 0, printer);
    STRBUF_Delete(str);
}

void WORLDTRADE_DEPOSIT_DrawRequestWindowAlt(void *bank, void *names, int unused, void **win, u32 index, int mode, int place, void *printer)
{
    int i;
    void *str;
    int show = 1;
    str = MSGDATA_AllocString(bank, 0x6b);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[0], str, 0, 0, 0, 0x440, printer);
    for (i = 1; i < 3; i++)
        BMP_Clear(BMP_WIN_GetBmp(win[i]), 0);
    WORLDTRADE_DEPOSIT_PrintName(win[1], names, index, 0, 0, 0x440, printer);
    if (index == 29 && mode == 2)
        show = 0;
    else if (index == 32 && mode == 1)
        show = 0;
    if (show) {
        if (mode == 1 || mode == 2)
            WORLDTRADE_DEPOSIT_PrintModeLabelAligned(win[1], bank, mode, 0, 0, 70, 0x440, printer);
    }
    WORLDTRADE_DEPOSIT_PrintLevelRange(win[2], bank, place, 0, 0, 0x440, 0, printer);
    STRBUF_Delete(str);
}

void WORLDTRADE_DEPOSIT_PrintMonSummary(void *bank, void *ws, void **win, void *mon, MonTag *out, void *printer)
{
    int i;
    int form;
    void *title;
    void *place;
    void *name;
    void *tmp;
    u32 has;
    u32 gender;

    name = STRBUF_Create(0xB, 0x48);
    tmp = STRBUF_Create(0xB, 0x48);
    POKE_TOOL_GetBoxValue(mon, 0x73, (u32)name);
    form = POKE_TOOL_GetBoxValue(mon, 0x6E, 0) + 1;
    gender = POKE_TOOL_CalcBoxLevel(mon);
    has = POKE_TOOL_GetBoxValue(mon, 0xAD, 0);
    title = MSGDATA_AllocString(bank, 0x6E);
    WORDSET_SetSlotNumber(ws, 3, gender, 3, 0, 1);
    place = (void *)WORLDTRADE_ADAPTER_CreateString((u32)ws, (u32)bank, 0x72, 0x48);
    if (form != 3) {
        MSGDATA_ReadString(bank, tbl_02202EB0[form], tmp);
    }
    for (i = 0; i < 3; i++) {
        BMP_Clear(BMP_WIN_GetBmp(win[i]), 0);
    }
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[0], title, 1, 0, 0, 0x3C40, printer);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[1], name, 0, 0, 0, 0x3C40, printer);
    WORLDTRADE_INPUT_PrintStringAlignedLine(win[2], place, 0, 0, 2, 0x3C40, printer);
    if (form != 3 && has != 0) {
        WORLDTRADE_INPUT_PrintStringAlignedLine(win[1], tmp, 0x46, 0, 0, WORLDTRADE_DEPOSIT_GetModeColor(form - 1), printer);
    }
    out->species = POKE_TOOL_GetBoxValue(mon, 5, 0);
    out->form = form;
    out->gender = gender;
    STRBUF_Delete(place);
    STRBUF_Delete(tmp);
    STRBUF_Delete(name);
    STRBUF_Delete(title);
}

u16 *WORLDTRADE_DEPOSIT_LoadSpeciesList(u32 heap, u32 unused, u32 *count)
{
    u32 size;
    u16 *list;

    list = (u16 *)ARC_UTIL_LoadMemberWithSize(0x62, 5, 0, (u16)heap, &size);
    *count = size / 2;
    return list;
}

void WORLDTRADE_DEPOSIT_GetSpeciesRange(u32 kind, int *start, int *end)
{
    if (kind >= 0x1B) {
        SAVEDATA_PanicFail((void *)0x02203C18, 0, (void *)0x02203C18);
    }
    *start = tbl_0220307C[kind];
    *end = tbl_0220307C[kind + 1];
}

u8 *WORLDTRADE_DEPOSIT_GetSpeciesFlag(u32 id)
{
    u32 size;
    u32 i;
    u8 *buf;
    u16 *tbl;
    u32 n;

    buf = GFL_HEAP_Alloc(0x48, 0x28A, 0, (const char *)g_02203C00, 0x796);
    MIi_CpuClearFast(0, buf, 0x28A);
    tbl = (u16 *)ARC_UTIL_LoadMemberWithSize(0x62, 4, 0, (u16)id, &size);
    n = size / 2;
    for (i = 0; i < n; i++) {
        if (tbl[i] < 0x28A) {
            buf[tbl[i]] = 1;
        }
    }
    GFL_HEAP_Free(tbl);
    return buf;
}

void WORLDTRADE_DEPOSIT_BuildOffer(Entry *dst, Work *p)
{
    u32 species;

    if (WORLDTRADE_BOX_ClampSlot(p->box) != 0) {
        species = POKE_TOOL_GetBoxValue(p->mon, 5, 0);
        if (species == 0x1EC || species == 0x286) {
            POKE_TOOL_ChangeForm(p->mon, 0);
        }
        MIi_CpuCopyFast(p->mon, dst, POKE_TOOL_GetPartyParamSize());
    } else {
        species = POKE_TOOL_GetBoxValue(p->mon, 5, 0);
        if (species == 0x1EC || species == 0x286) {
            POKE_TOOL_ChangeBoxForm((int)p->mon, 0);
        }
        WORLDTRADE_ADAPTER_CopyBoxMon(p->mon, (u32)dst);
    }
    WORDSET_CopyString(MYSTATUS_GetName(p->ctx->myStatus), (u16 *)dst->name, 8);
    dst->trainerId = MYSTATUS_GetId(p->ctx->myStatus);
    dst->lang = MYSTATUS_GetLanguage(p->ctx->myStatus);
    dst->ver = MYSTATUS_GetVersion(p->ctx->myStatus);
    dst->country = MYSTATUS_GetOutfit(p->ctx->myStatus);
    dst->gender = MYSTATUS_GetOutfitVariant(p->ctx->myStatus);
    dst->region = 0x15;
    dst->city = 2;
    dst->profileFlagB = WIFI_HISTORY_GetGreetingSet(p->ctx->status);
    dst->profileFlagC = WIFI_HISTORY_GetVisitedCountryCount(p->ctx->status);
    dst->profileFlagA = WIFI_HISTORY_GetRatingLevel(p->ctx->status);
}

void WORLDTRADE_DEPOSIT_StoreOfferInWork(Deposit *dst, Work *p)
{
    WORLDTRADE_DEPOSIT_BuildOffer((Entry *)dst, (Work *)p);
    dst->have.species = p->haveSpecies;
    *(u16 *)&dst->have.form = p->haveFormGender;
    dst->want.species = (*(unsigned short *)&p->wantSpecies);
    *(u16 *)&dst->want.form = p->wantGenderLevelMin;
    *(u16 *)&dst->want.b4 = p->wantLevelMaxPair;
}

int WORLDTRADE_DEPOSIT_CreateSpeciesMenu(void **menu, void *msg, void *endmsg, u16 *list, u32 unused4, u32 unused5, u32 kind, void *bag)
{
    int i;
    int size;
    int count;
    int start;
    count = 0;
    start = tbl_02203B84[kind];
    size = tbl_02203B84[kind + 1] - start;
    for (i = 0; i < size; i++) {
        if (ZUKAN_SAVE_IsSeen(bag, list[start + i]) != 0) count++;
    }
    *menu = BMP_MENUWORK_Create(count + 1, 0x48);
    for (i = 0; i < size; i++) {
        if (ZUKAN_SAVE_IsSeen(bag, list[start + i]) != 0) {
            BMP_MENUWORK_AddMsgItem(*menu, (u32)msg, list[start + i], list[start + i], 0x48);
        }
    }
    BMP_MENUWORK_AddMsgItem(*menu, (u32)endmsg, 0x85, -2, 0x48);
    return count + 1;
}

/*
 * lever: u16 arrays at 0xEF0 and 0xF04 preserve base/index load scheduling; raw offset casts differ by 8 bytes.
 */
void *WORLDTRADE_DEPOSIT_CreateSpeciesMenuList(Work *p, void **menu, void *win, void *endmsg, void *msg, DepositState *cfg, void *bag)
{
    int kind;
    int count;
    MenuSrc src;
    BMP_Clear(BMP_WIN_GetBmp(win), 15);
    kind = cfg->menuScroll + cfg->menuRow;
    count = WORLDTRADE_DEPOSIT_CreateSpeciesMenu(menu, msg, endmsg, cfg->speciesList, (u32)cfg->speciesFlags, cfg->speciesCount, kind, bag);
    src = d_02202ED8;
    src.count = count;
    src.ptrs[0] = (u32)*menu;
    src.ptrs[3] = (u32)win;
    BMP_MENUWORK_DrawWindow(win, 0, 31, 11);
    return BMP_MENULIST_Create((struct Src *)(&src), p->a[kind], p->b[kind], 0x48);
}

int WORLDTRADE_DEPOSIT_CreateGenderMenu(void **menu, void *msg, int kind)
{
    const TableRow *table;
    int i;
    int count;
    if (kind == 0) { table = tbl_0220301C; count = 12; }
    else { table = tbl_02202FC4; count = 11; }
    *menu = BMP_MENUWORK_Create(count, 0x48);
    for (i = 0; i < count; i++) {
        BMP_MENUWORK_AddMsgItem(*menu, (u32)msg, table[i].id, i, 0x48);
    }
    return count;
}

void WORLDTRADE_DEPOSIT_GetLevelBracket(u8 *dst, int index, int kind)
{
    const TableRow *table;
    if (kind == 0) {
        table = tbl_0220301C;
        if (index >= 12) SAVEDATA_PanicFail(str_02203C18, 0, str_02203C18);
    } else {
        table = tbl_02202FC4;
        if (index >= 11) SAVEDATA_PanicFail(str_02203C18, 0, str_02203C18);
    }
    dst[3] = table[index].x;
    dst[4] = table[index].y;
}

/*
 * Index of a key/value pair in one of two s16 tables.
 */
int WORLDTRADE_DEPOSIT_GetConditionIndex(int key, int val, int which)
{
    int i;
    int n;
    const TableRow *tab;

    if (which == 0) {
        tab = tbl_0220301C;
        n = 0xc;
    } else {
        tab = tbl_02202FC4;
        n = 0xb;
    }
    for (i = 0; i < n; i++) {
        if (tab[i].key == key && tab[i].val == val) {
            return i;
        }
    }
    return 0;
}

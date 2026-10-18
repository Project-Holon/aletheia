/*
 * file:     intrude_comm_view.c
 * unit:     yes
 * function: INTRUDE_COMM_VIEW_StoreCallback, INTRUDE_COMM_VIEW_SetCallback, INTRUDE_COMM_VIEW_SetupBackgrounds, INTRUDE_COMM_VIEW_BuildRowList, INTRUDE_COMM_VIEW_RebuildRow, INTRUDE_COMM_VIEW_DeleteRowSlot, INTRUDE_COMM_VIEW_ResetRowSlot, INTRUDE_COMM_VIEW_DeleteRows, INTRUDE_COMM_VIEW_InvokeCallback, INTRUDE_COMM_VIEW_BrightenPalette, INTRUDE_COMM_VIEW_CreateActors, INTRUDE_COMM_VIEW_CreateResources, INTRUDE_COMM_VIEW_InitMenu, INTRUDE_COMM_VIEW_DeleteResources, INTRUDE_COMM_VIEW_CheckExitRequest, INTRUDE_COMM_VIEW_BeginExit, INTRUDE_COMM_VIEW_StartExit, INTRUDE_COMM_VIEW_Noop, INTRUDE_COMM_VIEW_AnimateSelectedRow, INTRUDE_COMM_VIEW_SelectRow, INTRUDE_COMM_VIEW_DrawRowText, INTRUDE_COMM_VIEW_UpdatePeerList, INTRUDE_COMM_VIEW_Update, INTRUDE_COMM_VIEW_InitStatusText, INTRUDE_COMM_VIEW_UpdateActorAnim, INTRUDE_COMM_VIEW_SetFoundPeerMac, INTRUDE_COMM_VIEW_ClearFoundPeerMac, INTRUDE_COMM_VIEW_OnScanResult, INTRUDE_COMM_VIEW_StorePeerRecord, INTRUDE_COMM_VIEW_TickPeerTimers, INTRUDE_COMM_VIEW_SumPeerTimers, INTRUDE_COMM_VIEW_VBlankHandler, INTRUDE_COMM_VIEW_Create, INTRUDE_COMM_VIEW_Main, INTRUDE_COMM_VIEW_Exit
 * address:  0x021D4240
 * region:   ov122
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021D5780 0x021D5780 data a4
 *   d_021D57A0 0x021D57A0 data a4
 *   d_021D57C0 0x021D57C0 data a4
 *   d_021D57E0 0x021D57E0 data a4
 *   d_021D5800 0x021D5800 data a4
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   GF_FONT_MeasureWidestLine 0x0201D304 thumb
 *   GF_FONT_CountLines 0x0201D42C thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 *   data_021D5708 0x021D5708 data a1
 *   data_021D5704 0x021D5704 data a1
 *   data_021D570C 0x021D570C data a1
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   data_021D5870 0x021D5870 data a2
 *   d_021D575C 0x021D575C data a4
 *   d_021D5890 0x021D5890 data a4
 *   d_021D5720 0x021D5720 data a4
 *   d_021D5718 0x021D5718 data a4
 *   d_021D5728 0x021D5728 data a4
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   NET_WHPIPE_SetNotifyCallback 0x02178118 thumb ov014
 *   CLACT_ApplyActorAnimCommand 0x0204BA00 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   INTRUDE_COMM_GetRequestState 0x02158630 thumb ov010
 *   data_021D58E0 0x021D58E0 data a4
 *   INTRUDE_COMM_CountEventPeers 0x02158678 thumb ov010
 *   INTRUDE_COMM_GetRequesterStatus 0x021586C8 thumb ov010
 *   data_021D5714 0x021D5714 data ov122 a4
 *   data_021D5840 0x021D5840 data a4
 *   data_021D5850 0x021D5850 data a4
 *   data_021D5860 0x021D5860 data a4
 *   data_021D5710 0x021D5710 data a4
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   GFL_NET_GetScanResultMac 0x0203CF3C arm
 *   GFL_NET_GetScanResult 0x0203CF10 arm
 *   STRBUF_SetStringN 0x02045994 arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   GF_STANDARD_CompareBytes 0x0203EFC8 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   GX_DispOn 0x0207D46C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   TCBL_Create 0x0203101C arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   data_021D58B0 0x021D58B0 data a4
 *   data_021D5770 0x021D5770 data a4
 *   data_021D5740 0x021D5740 data a4
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   CLACT_DrawSystem 0x0204A600 arm
 *   GAME_DATA_GetField1A0 0x0201283C thumb
 *   WIH_DWC_PollStatus 0x0201058C thumb
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   GAMESYSTEM_TryStartAutoComm 0x020121CC thumb
 *   ICA_ANIME_GetUnk330 0x02012204 thumb
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   GAME_BEACON_GetNextNewLogIndex  0x02026CA0  thumb  arm9
 *   FIELD_SOUND_SYSTEM_StartRingtone  0x02028A64  thumb  arm9
 *   COMM_PLAYER_SUPPORT_GetRecordFieldPtr  0x0202E930  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   GAME_COMM_GetKind  0x02026454  thumb  arm9
 *   ICA_ANIME_GetField24  0x02012138  thumb  arm9
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb  arm9
 *   WORDSET_Create  0x0201EC74  thumb  arm9
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb  arm9
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
 *   GF_FONT_InitTextColor  0x0201DD60  thumb  arm9
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 *   BMP_MENUWORK_LoadFrameGfx  0x0201F5DC  thumb  arm9
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm  arm9
 *   GFL_USE_AddMainTask  0x020056A0  thumb  arm9
 *   TCB_DeleteTask  0x02030EAC  arm  arm9
 *   PROCSYS_FreeProcWork  0x020315D4  arm  arm9
 *   WIH_DWC_FindSlotByKey  0x020107FC  thumb  arm9
 *   FIELD_SOUND_SYSTEM_StopRingtone  0x02028A70  thumb  arm9
 */

struct BgTemplate;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct Obj;
struct Actor;
struct GfFont;
struct U16Vec;
struct Rec;
struct Ctx;
struct Comm;
struct Cmd;
struct WordSet;
struct BigObj;
struct SoundSys;
struct Strbuf;
struct Proc;
struct DispConfig;
struct DispVram;
struct Bank;
struct TaskMenuRes;
struct Tcbl;
struct IcaAnime;
struct PrintSys;
struct Node;
struct Rec3;
struct S02031140;
struct Proc;
struct TaskMenu;
struct TaskMenuState;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Config { u32 w[8]; } Config;

typedef signed short s16;

typedef struct { int x, y, w, h; } Row;

typedef struct { u8 addr[8]; u16 timer; u16 tag; } IntrudeCommViewPeer;

typedef struct IntrudeCommViewArgs {
    void *icaAnime;
    void *gameData;
    u32 field08;
    void *owner;
    int active;
    u8 foundMac[6];
    u8 pad1A[2];
    u32 field1C;
    u32 field20;
    u32 field24;
    int requestState;
} IntrudeCommViewArgs;

typedef struct IntrudeCommView {
    void (*step)(char *p);
    int (*invokeCallback)(int, char *);
    int state;
    u16 heapId;
    u16 pad00E;
    void *rows[11];
    void *rowWin;
    void *buttonMan;
    void *msgBank;
    void *wordSet;
    void *font;
    void *textBufAlt;
    void *textBuf;
    void *textBuf3;
    void *frameGfx;
    u32 frameParam;
    IntrudeCommViewPeer peers[16];
    int peerCacheMode;
    int peerCount;
    u16 paletteMain[112];
    u16 paletteBright[112];
    u8 pad2EC[0x20];
    void *clactUnit;
    void *vblankTask;
    void *bmpWin;
    void *printStream;
    void *tcbl;
    void *printQueue;
    void *taskMenu;
    void *statusText;
    u16 statusColor;
    u16 pad32E;
    u32 statusFlags;
    u8 pad334[0xC];
    void *taskMenuRes;
    IntrudeCommViewArgs *args;
    int rowCount;
    u8 pad34C[4];
    void *gameData;
    void *icaAnime;
    u32 wipeDelay;
    int selectedRow;
    u8 pad360[4];
    u32 peerTimer;
    u32 peerTimerPrev;
    u32 peerSum;
    u32 peerSumPrev;
    int newLogSeen;
    u32 paletteId;
    u32 charId;
    u32 cellId;
    u8 pad384[8];
    int exitStarted;
    void *actors[6];
} IntrudeCommView;

typedef char IntrudeCommView_size_check[(sizeof(IntrudeCommView) == 0x3A8) ? 1 : -1];

typedef struct { u8 reserved[32]; int state; } IntrudeCommViewExitState;

typedef struct { u8 reserved[12]; void *data; } IntrudeCommViewPalette;

typedef int (*Fn)(int,u32 *);

typedef struct { u8 v[3]; } Triple;

typedef struct { u16 x, y, z; u8 mode, layer; } Request;

typedef signed int     s32;

typedef struct { int v[2]; } Pair;

typedef struct { u16 opcode; char *ctx; void (*fn)(void); } Params;

typedef struct { u32 v[4]; } Display;

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u32);
extern void BG_SYS_PushTile(u32);
extern void BG_SYS_SetVisibleLayer(int, u16);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void BG_SYS_Init(u32, u32, u32, u32);
extern void BG_SYS_SetTileEntry(u32, int, int, int, u8, u8, u8);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32, u32, u32, u32, u32, u16);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void BMP_MENUWORK_DrawWindowBorder(void *, unsigned);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u32 GF_FONT_MeasureWidestLine(struct StrObj *s, u32 a, u32 b);
extern u32 GF_FONT_CountLines(struct StrObj *s, void *font);
extern void PRINTSYS_PrintColor(void *, s16, s16, void *, void *, u16);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BUTTON_MAN_Delete(void *);
extern void BG_SYS_SetFlagField06(u32);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 space, u16 heap);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 GFL_HEAP_Free(void *p);
extern u32 ARC_UTIL_RegisterObjCharFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(u32);
extern void *BMP_MENUWORK_LoadFrameGfx(void *a0, u32 a1, u32 a2, u32 a3);
extern void *BUTTON_MAN_Create(u8 *a0, int a1, int a2, int a3);
extern void GF_FONT_SetDefaultTextColor(void);
extern void BG_SYS_SetTileUnit(u32 idx, u32 count, u32 tile);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern unsigned int WIPE_SYS_EndCheck(void);
extern unsigned int ICA_ANIME_GetField24(const struct Ctx *p);
extern u32 GAME_COMM_GetKind(void *obj);
extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);
extern void NET_WHPIPE_SetNotifyCallback(u32 callback, u32 value);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const struct Cmd *cmd);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern int INTRUDE_COMM_GetRequestState(int a);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern int GAME_BEACON_GetNextNewLogIndex(int *);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int INTRUDE_COMM_CountEventPeers(void *p);
extern int INTRUDE_COMM_GetRequesterStatus(int, int);
extern int BUTTON_MAN_UpdateSlots(void *);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void *GFL_NET_GetInitParam(void);
extern void *GFL_NET_GetScanResultMac(u32);
extern u32 GAME_DATA_GetField1A0(const struct BigObj *p);
extern int WIH_DWC_FindSlotByKey(void *);
extern u32 GFL_NET_GetScanResult(u32 a);
extern u16 *COMM_PLAYER_SUPPORT_GetRecordFieldPtr(void *);
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern unsigned int GAME_DATA_GetBgmInfo(const struct BigObj *);
extern void FIELD_SOUND_SYSTEM_StartRingtone(struct SoundSys *sys);
extern void FIELD_SOUND_SYSTEM_StopRingtone(struct SoundSys *sys);
extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);
extern void CLACT_VBlankSystem(void);
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, u32);
extern void BMP_SetDisplaySwap(u32);
extern void GX_DispOn(void);
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
extern void GF_FONT_InitTextColor(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *GFL_USE_AddMainTask(u32, void *, u32);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct TaskMenuRes *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void G2x_SetBlendAlpha_(void *, u32, u32, u32, u32);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
extern int GFL_NET_GetRunState(void);
extern void UI_SetInputMode(u8);
extern void APP_TASKMENU_UpdateMenu(void *);
extern void CLACT_DrawSystem(void);
extern u32 WIH_DWC_PollStatus(void *);
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void BG_SYS_FillScrollArea(u32, u32, u32);
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);
extern u32 ICA_ANIME_GetUnk330(const struct Ctx *p);
extern void WIPE_SetBrightnessFadeOut(u32, u32);
extern void TCBL_Destroy(struct S02031140 *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void TCB_DeleteTask(struct Node *n);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
void INTRUDE_COMM_VIEW_StoreCallback(u32 *slot, u32 value);
void INTRUDE_COMM_VIEW_SetCallback(void *p, u32 callback, int id);
void INTRUDE_COMM_VIEW_SetupBackgrounds(void *unused);
void INTRUDE_COMM_VIEW_BuildRowList(int count, int *values, IntrudeCommView *p, Row *rows, const int *xs, const int *ys);
void INTRUDE_COMM_VIEW_RebuildRow(int i, IntrudeCommView *p, Row *row, const int *xs, const int *ys);
void INTRUDE_COMM_VIEW_DeleteRowSlot(u32 i,u32 p);
void INTRUDE_COMM_VIEW_ResetRowSlot(u32 i,u32 p);
void INTRUDE_COMM_VIEW_DeleteRows(char *p);
void INTRUDE_COMM_VIEW_InvokeCallback(int value, int index, u32 *p);
void INTRUDE_COMM_VIEW_BrightenPalette(u16 *p, const u16 *add, int count);
void INTRUDE_COMM_VIEW_CreateActors(char *p);
void INTRUDE_COMM_VIEW_CreateResources(char *p);
void INTRUDE_COMM_VIEW_InitMenu(char *p);
void INTRUDE_COMM_VIEW_DeleteResources(char *p);
void INTRUDE_COMM_VIEW_CheckExitRequest(char *p);
void INTRUDE_COMM_VIEW_BeginExit(char *p);
void INTRUDE_COMM_VIEW_StartExit(char *p);
void INTRUDE_COMM_VIEW_Noop(void);
void INTRUDE_COMM_VIEW_AnimateSelectedRow(char *p);
int INTRUDE_COMM_VIEW_SelectRow(int value, char *p);
void INTRUDE_COMM_VIEW_DrawRowText(int i, int value, int force, int mode, IntrudeCommView *p);
void INTRUDE_COMM_VIEW_UpdatePeerList(char *p);
void INTRUDE_COMM_VIEW_Update(char *p);
void INTRUDE_COMM_VIEW_InitStatusText(char *p);
void INTRUDE_COMM_VIEW_UpdateActorAnim(char *p);
void INTRUDE_COMM_VIEW_SetFoundPeerMac(char *p, u32 peerIndex);
void INTRUDE_COMM_VIEW_ClearFoundPeerMac(char *p);
void INTRUDE_COMM_VIEW_OnScanResult(char *p);
void INTRUDE_COMM_VIEW_StorePeerRecord(IntrudeCommView *p, const char *data, int value, int tag);
void INTRUDE_COMM_VIEW_TickPeerTimers(u8 *p);
u32 INTRUDE_COMM_VIEW_SumPeerTimers(u8 *p);
void INTRUDE_COMM_VIEW_VBlankHandler(void);
int INTRUDE_COMM_VIEW_Create(void *owner, void *unused, char *args);
int INTRUDE_COMM_VIEW_Main(void *owner, void *unused1, void *unused2, char *p);
extern const Config d_021D5780, d_021D57A0, d_021D57C0, d_021D57E0, d_021D5800;
extern const Triple data_021D5708, data_021D5704, data_021D570C;
extern u16 data_021D5870[];
extern const Pair d_021D575C;
extern int d_021D5890[], d_021D5720[], d_021D5718[], d_021D5728[];
extern Row data_021D58E0[];
extern int data_021D5714[], data_021D5710[];
extern Row data_021D5840, data_021D5850, data_021D5860;
extern u32 data_021D58B0[], data_021D5740[];
extern const Display data_021D5770;







void INTRUDE_COMM_VIEW_StoreCallback(u32 *slot, u32 value) {*slot=value;}







void INTRUDE_COMM_VIEW_SetCallback(void *p, u32 callback, int id) {INTRUDE_COMM_VIEW_StoreCallback(p,callback);}







void INTRUDE_COMM_VIEW_SetupBackgrounds(void *unused)
{
    Config bg0, bg4, bg5, bg6, bg7;
    bg0 = d_021D5780;
    BG_SYS_InitBgLayer(0, (const struct BgTemplate *)(&bg0), 0);
    BG_SYS_FreeSlot(0);
    BG_SYS_PushTile(0);
    BG_SYS_SetVisibleLayer(0, 0);
    BG_SYS_SetPlaneVisible(0, 1);
    bg4 = d_021D57A0;
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)(&bg4), 0);
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_PushTile(4);
    bg5 = d_021D57C0;
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)(&bg5), 0);
    BG_SYS_Init(5, 0, 1, 0);
    BG_SYS_SetTileEntry(5, 0, 0, 0, 32, 32, 17);
    BG_SYS_PushTile(5);
    BG_SYS_SetPlaneVisible(5, 1);
    bg6 = d_021D57E0;
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)(&bg6), 0);
    BG_SYS_SetPlaneVisible(6, 1);
    BG_SYS_PushTile(6);
    bg7 = d_021D5800;
    BG_SYS_InitBgLayer(7, (const struct BgTemplate *)(&bg7), 0);
    BG_SYS_SetPlaneVisible(7, 1);
    BG_SYS_PushTile(7);
}







void INTRUDE_COMM_VIEW_BuildRowList(int count, int *values, IntrudeCommView *p, Row *rows, const int *xs, const int *ys)
{
    int i, x, y;
    p->rowCount = count;
    ARC_UTIL_UploadPaletteFromArchiveWhole(23, 5, 4, 384, 32, p->heapId);
    for (i = 0; i < 11; i++) {
        if (p->rows[i]) {
            BMP_WIN_ClearScreen(p->rows[i]);
            BMP_MENUWORK_DrawWindowBorder(p->rows[i], 2);
            BMP_WIN_Delete(p->rows[i]);
        }
        p->rows[i] = 0;
    }
    for (i = 0; i < count; i++) {
        p->rows[i] = (void *)BMP_WIN_Create(7, (u8)rows[i].x, (u8)rows[i].y, (u8)rows[i].w, rows[i].h, 13, 0);
        BMP_Clear(BMP_WIN_GetBmp(p->rows[i]), 0);
        MSGDATA_ReadString(p->msgBank, (int)values[i], p->textBuf);
        if (xs) x = xs[i] - (GF_FONT_MeasureWidestLine(p->textBuf, (u32)p->font, 0) >> 1);
        else x = 0;
        if (ys) y = ys[i] - (GF_FONT_CountLines(p->textBuf, p->font) >> 1);
        else y = 0;
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(p->rows[i]), x, y, p->textBuf, p->font, 0x39e3);
        BMP_WIN_TransferChars(p->rows[i]);
        BMP_WIN_MakeScreen(p->rows[i]);
    }
    if (p->buttonMan) BUTTON_MAN_Delete(p->buttonMan);
    p->buttonMan = 0;
    BG_SYS_SetFlagField06(7);
}







/*
 * lever: x initialized after construction lets its zero share the outgoing stack argument.
 */
void INTRUDE_COMM_VIEW_RebuildRow(int i, IntrudeCommView *p, Row *row, const int *xs, const int *ys)
{
    int x, y;
    if (p->rows[i]) {
        BMP_WIN_ClearScreen(p->rows[i]);
        BMP_MENUWORK_DrawWindowBorder(p->rows[i], 2);
        BMP_WIN_Delete(p->rows[i]);
        p->rows[i] = 0;
    }
    p->rows[i] = (void *)BMP_WIN_Create(7, (u8)row->x, (u8)row->y, (u8)row->w, row->h, 13, 0);
    x = 0;
    BMP_Clear(BMP_WIN_GetBmp(p->rows[i]), 0);
    if (xs) x = xs[i] - (GF_FONT_MeasureWidestLine(((IntrudeCommView *)p)->textBuf, *(u32 *)&((IntrudeCommView *)p)->font, 0) >> 1);
    if (ys) y = ys[i] - (GF_FONT_CountLines(((IntrudeCommView *)p)->textBuf, ((IntrudeCommView *)p)->font) >> 1);
    else y = 0;
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(p->rows[i]), x, y, ((IntrudeCommView *)p)->textBuf, ((IntrudeCommView *)p)->font, 0x39e3);
    BMP_WIN_TransferChars(p->rows[i]);
    BMP_WIN_MakeScreen(p->rows[i]);
    BG_SYS_SetFlagField06(7);
}







void INTRUDE_COMM_VIEW_DeleteRowSlot(u32 i,u32 p) {if(*(void **)(p+0x10+i*4)) {BMP_WIN_ClearScreen(*(void **)(p+0x10+i*4));BMP_MENUWORK_DrawWindowBorder(*(void **)(p+0x10+i*4),2);BMP_WIN_Delete(*(void **)(p+0x10+i*4));}*(void **)(p+0x10+i*4)=0;BG_SYS_SetFlagField06(5);}







void INTRUDE_COMM_VIEW_ResetRowSlot(u32 i,u32 p) {if(*(void **)(p+0x10+i*4)) {BMP_WIN_ClearScreen(*(void **)(p+0x10+i*4));BMP_MENUWORK_DrawWindowBorder(*(void **)(p+0x10+i*4),2);BMP_WIN_Delete(*(void **)(p+0x10+i*4));}*(void **)(p+0x10+i*4)=0;BG_SYS_SetFlagField06(7);}







/*
 * extent: Two zero padding bytes after the return, next function 021D4630.
 */
void INTRUDE_COMM_VIEW_DeleteRows(char *p)
{
    int i;
    char *q;
    if (((IntrudeCommView *)p)->buttonMan) BUTTON_MAN_Delete(((IntrudeCommView *)p)->buttonMan);
    *(int *)&((IntrudeCommView *)p)->buttonMan = 0;
    for (i = 0; i < 11; i++) {
        q = p + i * 4;
        if (((IntrudeCommView *)q)->rows[0]) {
            BMP_WIN_ClearScreen(((IntrudeCommView *)q)->rows[0]);
            BG_SYS_SetFlagField06(5);
            BMP_MENUWORK_DrawWindowBorder(((IntrudeCommView *)q)->rows[0], 2);
            BMP_WIN_Delete(((IntrudeCommView *)q)->rows[0]);
        }
        *(int *)&((IntrudeCommView *)q)->rows[0] = 0;
    }
    ((IntrudeCommView *)p)->rowCount = 0;
}







void INTRUDE_COMM_VIEW_InvokeCallback(int value, int index, u32 *p) {if(index==0 && p[1]!=0) {if(((Fn)p[1])(value,p)==0)return;}}







void INTRUDE_COMM_VIEW_BrightenPalette(u16 *p, const u16 *add, int count)
{
    int i, j;
    for (i = 0; i < count; i++) {
        u16 *q = p + i * 16;
        for (j = 0; j < 16; j++) {
            u16 color = q[j];
            u16 r = color & 31;
            u16 g = (color & 0x3e0) >> 5;
            u16 b = (color & 0x7c00) >> 10;
            r += add[j];
            g += add[j];
            b += add[j];
            if (r > 31) r = 31;
            if (g > 31) g = 31;
            if (b > 31) b = 31;
            q[j] = r + (g << 5) + (b << 10);
        }
    }
}







void INTRUDE_COMM_VIEW_CreateActors(char *p)
{
    Triple x = data_021D5708;
    Triple y = data_021D5704;
    Triple z = data_021D570C;
    Request req;
    int i, charIdOfs, palIdOfs, cellIdOfs, actorOfs0, actorOfs1, actorOfs2, actorOfs3;
    i = 0;
    charIdOfs = 0x37c;
    palIdOfs = 0x378;
    cellIdOfs = 0x380;
    actorOfs0 = 0x390;
    actorOfs1 = 0x390;
    actorOfs2 = 0x390;
    actorOfs3 = 0x390;
    for (; i < 3; i++) {
        char *q;
        req.x = x.v[i]; req.y = y.v[i]; req.z = z.v[i];
        req.mode = 1; req.layer = 2;
        q = p + 4 * i;
        *(void **)(q + actorOfs0) = CLACT_CreateActor((void *)*(u32 *)&((IntrudeCommView *)p)->clactUnit, *(u32 *)(p + charIdOfs), *(u32 *)(p + palIdOfs), *(u32 *)(p + cellIdOfs), &req, 1, ((IntrudeCommView *)p)->heapId);
        CLACT_SetActorAutoAnim(*(void **)(q + actorOfs1), 0);
        CLACT_SetActorDrawEnable(*(void **)(q + actorOfs2), 1);
        CLACT_SetActorObjMode(*(void **)(q + actorOfs3), 1);
    }
    req.x = 128; req.y = 96; req.z = 15; req.mode = 0; req.layer = 2;
    ((IntrudeCommView *)p)->actors[3] = CLACT_CreateActor((void *)*(u32 *)&((IntrudeCommView *)p)->clactUnit, ((IntrudeCommView *)p)->charId, ((IntrudeCommView *)p)->paletteId, ((IntrudeCommView *)p)->cellId, &req, 1, ((IntrudeCommView *)p)->heapId);
    CLACT_SetActorAutoAnim(((IntrudeCommView *)p)->actors[3], 1);
    CLACT_SetActorDrawEnable(((IntrudeCommView *)p)->actors[3], 1);
    CLACT_SetActorObjMode(((IntrudeCommView *)p)->actors[3], 1);
    req.x = 128; req.y = 96; req.z = 18; req.mode = 0; req.layer = 2;
    ((IntrudeCommView *)p)->actors[4] = CLACT_CreateActor((void *)*(u32 *)&((IntrudeCommView *)p)->clactUnit, ((IntrudeCommView *)p)->charId, ((IntrudeCommView *)p)->paletteId, ((IntrudeCommView *)p)->cellId, &req, 1, ((IntrudeCommView *)p)->heapId);
    CLACT_SetActorAutoAnim(((IntrudeCommView *)p)->actors[4], 1);
    CLACT_SetActorDrawEnable(((IntrudeCommView *)p)->actors[4], 0);
    CLACT_SetActorObjMode(((IntrudeCommView *)p)->actors[4], 1);
    req.x = 128; req.y = 96; req.z = 25; req.mode = 0; req.layer = 2;
    ((IntrudeCommView *)p)->actors[5] = CLACT_CreateActor((void *)*(u32 *)&((IntrudeCommView *)p)->clactUnit, ((IntrudeCommView *)p)->charId, ((IntrudeCommView *)p)->paletteId, ((IntrudeCommView *)p)->cellId, &req, 1, ((IntrudeCommView *)p)->heapId);
    CLACT_SetActorAutoAnim(((IntrudeCommView *)p)->actors[5], 1);
    CLACT_SetActorDrawEnable(((IntrudeCommView *)p)->actors[5], 0);
    CLACT_SetActorObjMode(((IntrudeCommView *)p)->actors[5], 1);
}







/*
 * ABI: 02049990 argument 5 is u16: original truncates the value at 021D49B4/49D2.
 */
void INTRUDE_COMM_VIEW_CreateResources(char *p)
{
    u32 arc;
    void *resource;
    char *palette;
    ((IntrudeCommView *)p)->textBuf = STRBUF_Create(200, ((IntrudeCommView *)p)->heapId);
    ((IntrudeCommView *)p)->textBuf3 = STRBUF_Create(200, ((IntrudeCommView *)p)->heapId);
    ((IntrudeCommView *)p)->textBufAlt = STRBUF_Create(200, ((IntrudeCommView *)p)->heapId);
    ((IntrudeCommView *)p)->rowWin = (void *)BMP_WIN_Create(5, 16, 10, 10, 2, 13, 0);
    ((IntrudeCommView *)p)->font = GF_FONT_Create(23, 0, 0, 0, ((IntrudeCommView *)p)->heapId);
    ((IntrudeCommView *)p)->msgBank = MSGDATA_CreateFromArchive(0, 2, 23, ((IntrudeCommView *)p)->heapId);
    arc = (u32)ARC_TOOL_CreateHandle(29, ((IntrudeCommView *)p)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole((void *)arc, 0, 0, 0, 0, ((IntrudeCommView *)p)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole((void *)arc, 1, 4, 0, 0, ((IntrudeCommView *)p)->heapId);
    resource = ARC_UTIL_LoadPaletteBlockFromHandle((void *)arc, 1, (u32)&palette, ((IntrudeCommView *)p)->heapId);
    MI_CpuCopy8(((IntrudeCommViewPalette *)palette)->data, ((IntrudeCommView *)p)->paletteMain, 0xe0);
    MI_CpuCopy8(((IntrudeCommViewPalette *)palette)->data, ((IntrudeCommView *)p)->paletteBright, 0xe0);
    INTRUDE_COMM_VIEW_BrightenPalette(((IntrudeCommView *)p)->paletteBright, data_021D5870, 7);
    GFL_HEAP_Free(resource);
    ((IntrudeCommView *)p)->frameParam = ARC_UTIL_RegisterObjCharFromHandle((void *)arc, 4, 4, 0, 0, ((IntrudeCommView *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)arc, 9, 4, 0, (u16)(((IntrudeCommView *)p)->frameParam), 0, 0, ((IntrudeCommView *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle((void *)arc, 15, 6, 0, (u16)(((IntrudeCommView *)p)->frameParam), 0, 0, ((IntrudeCommView *)p)->heapId);
    *(int *)&((IntrudeCommView *)p)->charId = CLACT_RegisterCharacter((void *)arc, 5, 0, 1, ((IntrudeCommView *)p)->heapId);
    *(int *)&((IntrudeCommView *)p)->paletteId = CLACT_RegisterPaletteEx((void *)arc, 3, 1, 0, 0, 10, ((IntrudeCommView *)p)->heapId);
    *(int *)&((IntrudeCommView *)p)->cellId = CLACT_RegisterCellAnim((void *)arc, 7, 16, ((IntrudeCommView *)p)->heapId);
    ARC_TOOL_DeleteHandle(arc);
    ((IntrudeCommView *)p)->frameGfx = BMP_MENUWORK_LoadFrameGfx((void *)5, 11, 0, ((IntrudeCommView *)p)->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23, 5, 4, 384, 32, ((IntrudeCommView *)p)->heapId);
    INTRUDE_COMM_VIEW_CreateActors(p);
}







void INTRUDE_COMM_VIEW_InitMenu(char *p)
{
    Pair pair = d_021D575C;
    INTRUDE_COMM_VIEW_BuildRowList(2, (int *)&pair, (IntrudeCommView *)p, (Row *)d_021D5890, (const int *)d_021D5720, (const int *)d_021D5718);
    ((IntrudeCommView *)p)->buttonMan = BUTTON_MAN_Create((u8 *)d_021D5728, (int)INTRUDE_COMM_VIEW_InvokeCallback, (int)p, ((IntrudeCommView *)p)->heapId);
    ((IntrudeCommView *)p)->invokeCallback = INTRUDE_COMM_VIEW_SelectRow;
    INTRUDE_COMM_VIEW_InitStatusText(p);
    INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_Update, 0x31b);
}







void INTRUDE_COMM_VIEW_DeleteResources(char *p)
{
    unsigned ranges;
    GF_FONT_SetDefaultTextColor();
    INTRUDE_COMM_VIEW_DeleteRows(p);
    BG_SYS_SetTileUnit(5, 1, 0);
    ranges = (u32)((IntrudeCommView *)p)->frameGfx;
    BG_SYS_DeleteHalf(5, (u16)ranges, (u16)(ranges >> 16));
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    MSGDATA_Delete(((IntrudeCommView *)p)->msgBank);
    GF_FONT_Delete(((IntrudeCommView *)p)->font);
    STRBUF_Delete(((IntrudeCommView *)p)->textBuf);
    STRBUF_Delete(((IntrudeCommView *)p)->textBufAlt);
    STRBUF_Delete(((IntrudeCommView *)p)->textBuf3);
    BMP_WIN_Delete(((IntrudeCommView *)p)->rowWin);
}







void INTRUDE_COMM_VIEW_CheckExitRequest(char *p)
{
    if (WIPE_SYS_EndCheck()) {
        if (((IntrudeCommView *)p)->state == 1) {
            if (!GAME_COMM_GetKind((void *)ICA_ANIME_GetField24(((IntrudeCommView *)p)->icaAnime)))
                INTRUDE_COMM_VIEW_SetCallback(p, 0, 0x341);
        } else {
            INTRUDE_COMM_VIEW_SetCallback(p, 0, 0x345);
        }
    }
}







/*
 * evidence: unlabelled ov014 Thumb setter 0x02178118 is filed separately.
 * extent: unit includes tail-call stub 0x021D4BDC and return stub 0x021D4BF0;
 *   two zero padding bytes at 0x021D4BF2 follow the intended code.
 */
void INTRUDE_COMM_VIEW_BeginExit(char *p)
{
    ((IntrudeCommView *)p)->exitStarted = 1;
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, ((IntrudeCommView *)p)->heapId);
    NET_WHPIPE_SetNotifyCallback(0, 0);
    if (((IntrudeCommView *)p)->state == 1 && GAME_COMM_GetKind((void *)ICA_ANIME_GetField24(((IntrudeCommView *)p)->icaAnime)))
        GAME_COMM_RequestExitNoCallback((struct Comm *)ICA_ANIME_GetField24(((IntrudeCommView *)p)->icaAnime));
    INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_CheckExitRequest, 0x35e);
}







void INTRUDE_COMM_VIEW_StartExit(char *p)
{
    INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_BeginExit, 0x36f);
}







void INTRUDE_COMM_VIEW_Noop(void)
{
}






void INTRUDE_COMM_VIEW_AnimateSelectedRow(char *p)
{
    int i;
    Params args;
    void **base;
    i = ((IntrudeCommView *)p)->selectedRow;
    args.opcode = 0;
    args.ctx = p;
    args.fn = (void (*)(void))INTRUDE_COMM_VIEW_StartExit;
    if (i == 3) i = 0;
    else if (i == 4) i = 1;
    base = ((IntrudeCommView *)p)->actors;
    CLACT_SetActorAutoAnim(base[i], 1);
    CLACT_ApplyActorAnimCommand(base[i], (const struct Cmd *)(&args));
    CLACT_RestartActorAnim(base[i]);
    INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_Noop, 0x390);
}






int INTRUDE_COMM_VIEW_SelectRow(int value, char *p)
{
    void *obj;
    obj = (void *)ICA_ANIME_GetField24(((IntrudeCommView *)p)->icaAnime);
    ((IntrudeCommView *)p)->selectedRow = value;
    switch (value) {
    case 0:
    case 3:
        ((IntrudeCommView *)p)->args->requestState = INTRUDE_COMM_GetRequestState((int)obj);
        ((IntrudeCommView *)p)->state = 0;
        GFL_USE_PlaySeDefaultVolume(0x73b);
        INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_AnimateSelectedRow, 0x3c4);
        break;
    case 1:
    case 4:
        ((IntrudeCommView *)p)->state = 1;
        GFL_USE_PlaySeDefaultVolume(0x73b);
        INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_AnimateSelectedRow, 0x3cd);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x73c);
        ((IntrudeCommView *)p)->state = 2;
        INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_AnimateSelectedRow, 0x3d3);
        break;
    }
    return 1;
}




void INTRUDE_COMM_VIEW_DrawRowText(int i, int value, int force, int mode, IntrudeCommView *p)
{
    if (p->rows[i] && !force) return;
    if (!p->rows[i])
        p->rows[i] = (void *)BMP_WIN_Create((int)7, (u8)data_021D58E0[i].x, (u8)data_021D58E0[i].y,
            (u8)data_021D58E0[i].w, data_021D58E0[i].h, (int)13, (int)0);
    BMP_Clear(BMP_WIN_GetBmp(p->rows[i]), 0);
    if (mode) {
        MSGDATA_ReadString(((IntrudeCommView *)p)->msgBank, value, ((IntrudeCommView *)p)->textBufAlt);
        WORDSET_CopyTaggedText(((IntrudeCommView *)p)->wordSet, ((IntrudeCommView *)p)->textBuf, ((IntrudeCommView *)p)->textBufAlt);
    } else {
        MSGDATA_ReadString(((IntrudeCommView *)p)->msgBank, value, ((IntrudeCommView *)p)->textBuf);
    }
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(p->rows[i]), 0, 0, ((IntrudeCommView *)p)->textBuf, ((IntrudeCommView *)p)->font, 0x39e3);
    BMP_WIN_TransferChars(p->rows[i]);
    BMP_WIN_MakeScreen(p->rows[i]);
}



/*
 * lever: explicit if/else calls preserve the shared stack home and call ordering.
 * tables: original pool maps y=5714, x=5710, rows=5840/5860, extra=5850.
 */
void INTRUDE_COMM_VIEW_UpdatePeerList(char *p)
{
    int force = 0;
    int scratch = 0;
    int object, mode, count;
    object = ICA_ANIME_GetField24(((IntrudeCommView *)p)->icaAnime);
    mode = INTRUDE_COMM_GetRequestState(object);
    if (!((IntrudeCommView *)p)->newLogSeen) {
        scratch = 0;
        if (GAME_BEACON_GetNextNewLogIndex(&scratch) != 30) ((IntrudeCommView *)p)->newLogSeen = 1;
    }
    if (((IntrudeCommView *)p)->peerSum != ((IntrudeCommView *)p)->peerSumPrev) force = 1;
    if (((IntrudeCommView *)p)->peerTimerPrev != ((IntrudeCommView *)p)->peerTimer) force = 1;
    INTRUDE_COMM_VIEW_DrawRowText(4, 2, 0, 0, (IntrudeCommView *)p);
    INTRUDE_COMM_VIEW_DrawRowText(6, 4, 0, 0, (IntrudeCommView *)p);
    INTRUDE_COMM_VIEW_DrawRowText(8, 12, 0, 0, (IntrudeCommView *)p);
    if (mode == 0) {
        WORDSET_SetSlotNumber(((IntrudeCommView *)p)->wordSet, 0, ((IntrudeCommView *)p)->peerSum, 2, 0, 1);
        INTRUDE_COMM_VIEW_DrawRowText(5, 3, force, 1, (IntrudeCommView *)p);
        if (((IntrudeCommView *)p)->peerTimer & 32) INTRUDE_COMM_VIEW_DrawRowText(7, 5, force, 1, (IntrudeCommView *)p);
        else INTRUDE_COMM_VIEW_DrawRowText(7, 6, force, 1, (IntrudeCommView *)p);
        if (((IntrudeCommView *)p)->newLogSeen) INTRUDE_COMM_VIEW_DrawRowText(9, 5, force, 1, (IntrudeCommView *)p);
        else INTRUDE_COMM_VIEW_DrawRowText(9, 6, force, 1, (IntrudeCommView *)p);
    } else {
        INTRUDE_COMM_VIEW_DeleteRowSlot(5, (u32)p); INTRUDE_COMM_VIEW_DeleteRowSlot(7, (u32)p); INTRUDE_COMM_VIEW_DeleteRowSlot(9, (u32)p);
    }
    if (mode == 2 && ((IntrudeCommView *)p)->peerCount != INTRUDE_COMM_CountEventPeers((void *)object)) ((IntrudeCommView *)p)->peerCacheMode = 0;
    if (((IntrudeCommView *)p)->peerCacheMode != mode) {
        switch (mode) {
        case 0:
            CLACT_SetActorDrawEnable(((IntrudeCommView *)p)->actors[5], 0);
            INTRUDE_COMM_VIEW_ResetRowSlot(10, (u32)p);
            MSGDATA_ReadString(((IntrudeCommView *)p)->msgBank, 0, ((IntrudeCommView *)p)->textBuf);
            INTRUDE_COMM_VIEW_RebuildRow(0, (IntrudeCommView *)p, &data_021D5840, data_021D5710, data_021D5714);
            break;
        case 1:
            CLACT_SetActorDrawEnable(((IntrudeCommView *)p)->actors[5], 0);
            INTRUDE_COMM_VIEW_ResetRowSlot(10, (u32)p);
            MSGDATA_ReadString(((IntrudeCommView *)p)->msgBank, 15, ((IntrudeCommView *)p)->textBuf);
            INTRUDE_COMM_VIEW_RebuildRow(0, (IntrudeCommView *)p, &data_021D5860, data_021D5710, data_021D5714);
            break;
        case 2:
            count = INTRUDE_COMM_CountEventPeers((void *)object);
            ((IntrudeCommView *)p)->peerCount = count;
            CLACT_SetActorDrawEnable(((IntrudeCommView *)p)->actors[5], 0);
            INTRUDE_COMM_VIEW_ResetRowSlot(10, (u32)p);
            WORDSET_SetSlotNumber(((IntrudeCommView *)p)->wordSet, 0, count, 1, 0, 1);
            MSGDATA_ReadString(((IntrudeCommView *)p)->msgBank, 16, ((IntrudeCommView *)p)->textBufAlt);
            WORDSET_CopyTaggedText(((IntrudeCommView *)p)->wordSet, ((IntrudeCommView *)p)->textBuf, ((IntrudeCommView *)p)->textBufAlt);
            INTRUDE_COMM_VIEW_RebuildRow(0, (IntrudeCommView *)p, &data_021D5860, data_021D5710, data_021D5714);
            break;
        case 3:
            MSGDATA_ReadString(((IntrudeCommView *)p)->msgBank, 17, ((IntrudeCommView *)p)->textBuf);
            INTRUDE_COMM_VIEW_RebuildRow(0, (IntrudeCommView *)p, &data_021D5860, data_021D5710, data_021D5714);
            if (INTRUDE_COMM_GetRequesterStatus(object, *(int *)&((IntrudeCommView *)p)->textBuf)) {
                INTRUDE_COMM_VIEW_RebuildRow(10, (IntrudeCommView *)p, &data_021D5850, 0, 0);
                CLACT_SetActorDrawEnable(((IntrudeCommView *)p)->actors[5], 1);
            }
            break;
        }
        ((IntrudeCommView *)p)->peerCacheMode = mode;
    }
    BG_SYS_SetFlagField06(7);
}



void INTRUDE_COMM_VIEW_Update(char *p) {if(WIPE_SYS_EndCheck())BUTTON_MAN_UpdateSlots(((IntrudeCommView *)p)->buttonMan);INTRUDE_COMM_VIEW_UpdateActorAnim(p);INTRUDE_COMM_VIEW_UpdatePeerList(p);}



/*
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char MSGDATA_AllocSite[];
 * extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
 * extern void GFL_HEAP_Free(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void ARC_TOOL_SeekHandle(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void MSGDATA_DecryptStrbuf(void *,u32);
 * extern void MSGDATA_RefreshLanguage(struct MsgBank *);
 * void MSGDATA_ReadString(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     MSGDATA_RefreshLanguage(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         ARC_TOOL_SeekHandle(bank->stream,pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,MSGDATA_AllocSite,0xd6);
 *         if (buf != 0) {
 *             ARC_TOOL_SeekHandle(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             GFL_HEAP_Free(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     MSGDATA_DecryptStrbuf(dest,index);
 * }
 */
void INTRUDE_COMM_VIEW_InitStatusText(char *p) {void *t;t=STRBUF_Create(100,((IntrudeCommView *)p)->heapId);((IntrudeCommView *)p)->statusText=t;MSGDATA_ReadString(((IntrudeCommView *)p)->msgBank,9,t);((IntrudeCommView *)p)->statusColor=0x39e3;((IntrudeCommView *)p)->statusFlags=1;STRBUF_Delete(((IntrudeCommView *)p)->statusText);}



/*
 * extent: zero padding at 0x021D50B2; next function at 0x021D50B4.
 */
void INTRUDE_COMM_VIEW_UpdateActorAnim(char *p)
{
    switch (INTRUDE_COMM_GetRequestState(ICA_ANIME_GetField24(((IntrudeCommView *)p)->icaAnime))) {
    case 0:
    case 1:
        if (CLACT_GetActorAnimSeq(((IntrudeCommView *)p)->actors[0]) == 20) {
            CLACT_SetActorAutoAnim(((IntrudeCommView *)p)->actors[0], 0);
            CLACT_SetActorAnimSeq(((IntrudeCommView *)p)->actors[0], 12);
        }
        break;
    case 2:
    case 3:
        if (CLACT_GetActorAnimSeq(((IntrudeCommView *)p)->actors[0]) == 12) {
            CLACT_SetActorAutoAnim(((IntrudeCommView *)p)->actors[0], 1);
            CLACT_SetActorAnimSeq(((IntrudeCommView *)p)->actors[0], 20);
        }
        break;
    }
}



void INTRUDE_COMM_VIEW_SetFoundPeerMac(char *p, u32 peerIndex) {void *q;GFL_NET_GetInitParam();q=GFL_NET_GetScanResultMac(peerIndex);((IntrudeCommView *)p)->args->active=2;MI_CpuCopy8(q,((IntrudeCommView *)p)->args->foundMac,6);}


void INTRUDE_COMM_VIEW_ClearFoundPeerMac(char *p) {u8 buf[6]={0};GFL_NET_GetInitParam();((IntrudeCommView *)p)->args->active=1;MI_CpuCopy8(buf,((IntrudeCommView *)p)->args->foundMac,6);}


void INTRUDE_COMM_VIEW_OnScanResult(char *p)
{
    int index;
    void *record, *text;
    index = WIH_DWC_FindSlotByKey((void *)GAME_DATA_GetField1A0(((IntrudeCommView *)p)->gameData));
    if (index != -1) {
        record = (void *)GFL_NET_GetScanResult(index);
        text = STRBUF_Create(200, ((IntrudeCommView *)p)->heapId);
        STRBUF_SetStringN(text, COMM_PLAYER_SUPPORT_GetRecordFieldPtr(record), 8);
        if (!CLACT_GetActorDrawEnable(((IntrudeCommView *)p)->actors[4])) {
            STRBUF_SetStringN(((IntrudeCommView *)p)->textBuf3, COMM_PLAYER_SUPPORT_GetRecordFieldPtr(record), 8);
            BMP_Clear(BMP_WIN_GetBmp(((IntrudeCommView *)p)->rowWin), 0);
            PRINTSYS_PrintColor(BMP_WIN_GetBmp(((IntrudeCommView *)p)->rowWin), 0, 0, ((IntrudeCommView *)p)->textBuf3, ((IntrudeCommView *)p)->font, 0x39e3);
            BMP_WIN_TransferChars(((IntrudeCommView *)p)->rowWin);
            BMP_WIN_MakeScreen(((IntrudeCommView *)p)->rowWin);
            CLACT_SetActorDrawEnable(((IntrudeCommView *)p)->actors[4], 1);
            BG_SYS_SetFlagField06(5);
            INTRUDE_COMM_VIEW_SetFoundPeerMac(p, index);
        }
        STRBUF_Delete(text);
        FIELD_SOUND_SYSTEM_StartRingtone((struct SoundSys *)GAME_DATA_GetBgmInfo(((IntrudeCommView *)p)->gameData));
        if (CLACT_GetActorAnimSeq(((IntrudeCommView *)p)->actors[3]) == 15)
            CLACT_SetActorAnimSeq(((IntrudeCommView *)p)->actors[3], 16);
        if (CLACT_GetActorAnimSeq(((IntrudeCommView *)p)->actors[1]) == 11) {
            CLACT_SetActorAutoAnim(((IntrudeCommView *)p)->actors[1], 1);
            CLACT_SetActorAnimSeq(((IntrudeCommView *)p)->actors[1], 19);
        }
    } else {
        FIELD_SOUND_SYSTEM_StopRingtone((struct SoundSys *)GAME_DATA_GetBgmInfo(((IntrudeCommView *)p)->gameData));
        CLACT_SetActorDrawEnable(((IntrudeCommView *)p)->actors[4], 0);
        BMP_Clear(BMP_WIN_GetBmp(((IntrudeCommView *)p)->rowWin), 0);
        BMP_WIN_TransferChars(((IntrudeCommView *)p)->rowWin);
        INTRUDE_COMM_VIEW_ClearFoundPeerMac(p);
        if (CLACT_GetActorAnimSeq(((IntrudeCommView *)p)->actors[1]) == 19) {
            CLACT_SetActorAutoAnim(((IntrudeCommView *)p)->actors[1], 0);
            CLACT_SetActorAnimSeq(((IntrudeCommView *)p)->actors[1], 11);
        }
        if (CLACT_GetActorAnimSeq(((IntrudeCommView *)p)->actors[3]) == 16)
            CLACT_SetActorAnimSeq(((IntrudeCommView *)p)->actors[3], 15);
    }
}


/*
 * extent: zero padding at 0x021D530E; next function at 0x021D5310.
 */
void INTRUDE_COMM_VIEW_StorePeerRecord(IntrudeCommView *p, const char *data, int value, int tag)
{
    int i;
    if (value >= 20 && value <= 27) {
        for (i = 0; i < 16; i++) {
            if (p->peers[i].timer && !GF_STANDARD_CompareBytes((const u8 *)p->peers[i].addr, (const u8 *)(data + 4), 6)) {
                p->peers[i].timer = 600;
                p->peers[i].tag = tag;
                return;
            }
        }
        for (i = 0; i < 16; i++) {
            if (!p->peers[i].timer) {
                MI_CpuCopy8(data + 4, p->peers[i].addr, 6);
                p->peers[i].timer = 600;
                p->peers[i].tag = tag;
                return;
            }
        }
    }
}


void INTRUDE_COMM_VIEW_TickPeerTimers(u8 *p) { int i; for(i=0;i<16;i++) if(((IntrudeCommView *)p)->peers[i].timer) --((IntrudeCommView *)p)->peers[i].timer; }


u32 INTRUDE_COMM_VIEW_SumPeerTimers(u8 *p) { int i; int sum; sum=0; for(i=0;i<16;i++) if(((IntrudeCommView *)p)->peers[i].timer) sum+=((IntrudeCommView *)p)->peers[i].tag; return sum; }


/*
 * leaf: root-claimed sole callback witness for INTRUDE_COMM_VIEW_Create.
 */
void INTRUDE_COMM_VIEW_VBlankHandler(void)
{
    CLACT_VBlankSystem();
}


/*
 * volatile: 021D53BA reads hardware DISPCNT, 021D53C0 writes the update.
 * ABI: 0203159C leaves the allocator result in r0 (020315BC/15C0); caller uses it.
 */
int INTRUDE_COMM_VIEW_Create(void *owner, void *unused, char *args)
{
    char *p;
    Display display;
    GFL_HEAP_CreateChildHeap(1, 31, 0x18000);
    p = PROCSYS_AllocProcWork(owner, 0x3a8, 31);
    MI_CpuFill8(p, 0, 0x3a8);
    ((IntrudeCommView *)p)->heapId = 31;
    ((IntrudeCommView *)p)->gameData = ((IntrudeCommViewArgs *)args)->gameData;
    ((IntrudeCommView *)p)->icaAnime = ((IntrudeCommViewArgs *)args)->icaAnime;
    BMP_SetDisplaySwap(1);
    *(volatile u32 *)0x04001000 |= 0x10000;
    GX_DispOn();
    BG_SYS_Create(((IntrudeCommView *)p)->heapId);
    BMP_WIN_Init(((IntrudeCommView *)p)->heapId);
    GF_FONT_InitTextColor();
    BG_SYS_SetVramBanks((const struct DispVram *)data_021D58B0);
    display = data_021D5770;
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&display));
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    CLACT_InitSystem((const struct Cfg *)data_021D5740, (u32)data_021D58B0, ((IntrudeCommView *)p)->heapId);
    ((IntrudeCommView *)p)->clactUnit = CLACT_CreateUnit(40, 0, ((IntrudeCommView *)p)->heapId);
    ((IntrudeCommView *)p)->vblankTask = GFL_USE_AddMainTask((u32)INTRUDE_COMM_VIEW_VBlankHandler, p, 0);
    INTRUDE_COMM_VIEW_SetupBackgrounds(p);
    INTRUDE_COMM_VIEW_CreateResources(p);
    ((IntrudeCommView *)p)->wordSet = WORDSET_Create(11, 200, ((IntrudeCommView *)p)->heapId);
    ((IntrudeCommView *)p)->tcbl = TCBL_Create(((IntrudeCommView *)p)->heapId, ((IntrudeCommView *)p)->heapId, 1, 0);
    ((IntrudeCommView *)p)->printQueue = (void *)PRINTSYS_QUE_Create((void *)(((IntrudeCommView *)p)->heapId));
    ((IntrudeCommView *)p)->taskMenuRes = APP_TASKMENU_RES_Create(5, 13, *(u32 *)&((IntrudeCommView *)p)->font, (u32)((IntrudeCommView *)p)->printQueue, ((IntrudeCommView *)p)->heapId);
    G2x_SetBlendAlpha_((void *)0x04001050, 4, 1, 15, 4);
    WIPE_SYS_Start((void *)4, 1, 1, 0, 6, 1, ((IntrudeCommView *)p)->heapId);
    BG_SYS_SetSubVisiblePlanes(31);
    INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_InitMenu, 0x6cb);
    ((IntrudeCommView *)p)->args = (IntrudeCommViewArgs *)args;
    GFL_NET_GetInitParam();
    ((IntrudeCommView *)p)->args->active = 1;
    ((IntrudeCommView *)p)->args->owner = ((IntrudeCommView *)p)->gameData;
    GFL_NET_RestartWithDefaultTimeout(0, ((IntrudeCommView *)p)->heapId);
    if (GFL_NET_GetRunState()) NET_WHPIPE_SetNotifyCallback((u32)INTRUDE_COMM_VIEW_StorePeerRecord, (u32)p);
    UI_SetInputMode(1);
    return 1;
}


/*
 * extent: two-byte zero alignment at 021D55FA, then next labelled function.
 */
int INTRUDE_COMM_VIEW_Main(void *owner, void *unused1, void *unused2, char *p)
{
    int result = 1;
    if (((IntrudeCommView *)p)->step) {
        ((IntrudeCommView *)p)->step(p);
        result = 0;
    }
    if (((IntrudeCommView *)p)->taskMenu) APP_TASKMENU_UpdateMenu(((IntrudeCommView *)p)->taskMenu);
    if (((IntrudeCommView *)p)->state != 1) INTRUDE_COMM_VIEW_OnScanResult(p);
    INTRUDE_COMM_VIEW_TickPeerTimers((unsigned char *)p);
    CLACT_DrawSystem();
    if (GFL_NET_GetRunState()) {
        ((IntrudeCommView *)p)->peerTimerPrev = ((IntrudeCommView *)p)->peerTimer;
        ((IntrudeCommView *)p)->peerTimer = WIH_DWC_PollStatus((void *)GAME_DATA_GetField1A0(((IntrudeCommView *)p)->gameData));
        ((IntrudeCommView *)p)->peerSumPrev = ((IntrudeCommView *)p)->peerSum;
        ((IntrudeCommView *)p)->peerSum = INTRUDE_COMM_VIEW_SumPeerTimers((u8 *)p);
    }
    TCBL_Main(((IntrudeCommView *)p)->tcbl);
    PRINTSYS_QUE_Main(((IntrudeCommView *)p)->printQueue);
    BG_SYS_FillScrollArea(4, 3, ((IntrudeCommView *)p)->wipeDelay);
    ((IntrudeCommView *)p)->wipeDelay = ((IntrudeCommView *)p)->wipeDelay - 1;
    if (WIPE_SYS_EndCheck() && ((IntrudeCommView *)p)->exitStarted == 0) GAMESYSTEM_TryStartAutoComm(((IntrudeCommView *)p)->icaAnime);
    if (WIPE_SYS_EndCheck() && ICA_ANIME_GetUnk330(((IntrudeCommView *)p)->icaAnime)) {
        ((IntrudeCommView *)p)->state = 2;
        result = 1;
        WIPE_SetBrightnessFadeOut(0, 0);
        WIPE_SetBrightnessFadeOut(1, 0);
    }
    return result;
}


/*
 * function: INTRUDE_COMM_VIEW_Exit
 * address: 0x021D55FC
 * extent: intended code ends 021D5704; remaining handed extent is rodata.
 * leaf: callback blocker of INTRUDE_COMM_VIEW_Main.
 */
int INTRUDE_COMM_VIEW_Exit(void *owner, void *unused, char *out, char *p)
{
    int i;
    if (!WIPE_SYS_EndCheck()) return 0;
    if (GFL_NET_GetRunState()) NET_WHPIPE_SetNotifyCallback(0, 0);
    INTRUDE_COMM_VIEW_DeleteResources(p);
    ((IntrudeCommViewExitState *)out)->state = ((IntrudeCommView *)p)->state;
    TCBL_Destroy(((IntrudeCommView *)p)->tcbl);
    BG_SYS_FreeLayerBuf(5);
    PRINTSYS_QUE_Clear(((IntrudeCommView *)p)->printQueue);
    PRINTSYS_QUE_Delete(((IntrudeCommView *)p)->printQueue);
    for (i = 0; i < 3; i++) CLACT_DeleteActor(((IntrudeCommView *)p)->actors[i]);
    CLACT_DeleteActor(((IntrudeCommView *)p)->actors[3]);
    CLACT_DeleteActor(((IntrudeCommView *)p)->actors[4]);
    CLACT_DeleteActor(((IntrudeCommView *)p)->actors[5]);
    CLACT_ReleasePalette((u32)(((IntrudeCommView *)p)->paletteId));
    CLACT_ReleaseCharacter((u32)(((IntrudeCommView *)p)->charId));
    CLACT_ReleaseCellAnim((u32)(((IntrudeCommView *)p)->cellId));
    TCB_DeleteTask(((IntrudeCommView *)p)->vblankTask);
    CLACT_DeleteUnit(((IntrudeCommView *)p)->clactUnit);
    CLACT_ExitSystem();
    if (((IntrudeCommView *)p)->printStream) PRINTSYS_PrintStreamDelete(((IntrudeCommView *)p)->printStream);
    WORDSET_DeleteStrbufED04(((IntrudeCommView *)p)->wordSet);
    if (((IntrudeCommView *)p)->taskMenu) {
        APP_TASKMENU_CloseMenu(((IntrudeCommView *)p)->taskMenu);
        ((IntrudeCommView *)p)->taskMenu = 0;
    }
    if (((IntrudeCommView *)p)->bmpWin) BMP_WIN_Delete(((IntrudeCommView *)p)->bmpWin);
    APP_TASKMENU_RES_Delete(((IntrudeCommView *)p)->taskMenuRes);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    PROCSYS_FreeProcWork(owner);
    GFL_HEAP_DeleteChecked(31);
    return 1;
}

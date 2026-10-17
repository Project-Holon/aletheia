/*
 * file:     wifi_club_actor.c
 * unit:     yes
 * function: WIFICLUBACTOR_Init, WIFICLUBACTOR_Exit, WIFICLUBACTOR_IsReady, WIFICLUBACTOR_Update, WIFICLUBACTOR_UpdatePickRequest, WIFICLUBACTOR_UpdatePickRequests, WIFICLUBACTOR_GetPickResult, WIFICLUBACTOR_GetCursorTileAttr, WIFICLUBACTOR_GetCursorTileBelowAttr, WIFICLUBACTOR_ShowMarkerAtActor, WIFICLUBACTOR_ResumeActorSprite, WIFICLUBACTOR_HideMarker, WIFICLUBACTOR_SetMode, WIFICLUBACTOR_GetMode, WIFICLUBACTOR_SpawnCursorActor, WIFICLUBACTOR_SpawnSlotActor, WIFICLUBACTOR_StartDespawn, WIFICLUBACTOR_FreeActor, WIFICLUBACTOR_GetActorId, WIFICLUBACTOR_GetActorFacing, WIFICLUBACTOR_StartTurn, WIFICLUBACTOR_RestoreActorUpdate, WIFICLUBACTOR_SetActorMode, WIFICLUBACTOR_StartBlinkOnTile, WIFICLUBACTOR_RestartBlink, WIFICLUBACTOR_TickBlink, WIFICLUBACTOR_FreeAllActors, WIFICLUBACTOR_IsCursorFree, WIFICLUBACTOR_IsFacingEntrance, WIFICLUBACTOR_ProcessSpawnCommands, WIFICLUBACTOR_UpdateActors, WIFICLUBACTOR_AnimateActors, WIFICLUBACTOR_FindActorFacing, WIFICLUBACTOR_InitSpriteManager, WIFICLUBACTOR_ExitSpriteManager, WIFICLUBACTOR_InitLayer, WIFICLUBACTOR_ExitLayer, WIFICLUBACTOR_InitSprites, WIFICLUBACTOR_ExitSprites, WIFICLUBACTOR_RegisterResources, WIFICLUBACTOR_ReleaseResources, WIFICLUBACTOR_CreateCursorActors, WIFICLUBACTOR_DeleteCursorActors, WIFICLUBACTOR_NoOpInit, WIFICLUBACTOR_NoOpExit, WIFICLUBACTOR_LoadPalette, WIFICLUBACTOR_RegisterClactResources, WIFICLUBACTOR_ReleaseClactResources, WIFICLUBACTOR_CreateClactActors, WIFICLUBACTOR_DeleteClactActors, WIFICLUBACTOR_ShowCursor, WIFICLUBACTOR_HideCursor, WIFICLUBACTOR_ShowMarker, WIFICLUBACTOR_HideMarkerActor, WIFICLUBACTOR_IsCursorOnExit, WIFICLUBACTOR_FindSlotTile, WIFICLUBACTOR_FindCursorStartTile, WIFICLUBACTOR_FindFreeActor, WIFICLUBACTOR_AttachSprite, WIFICLUBACTOR_SpawnEntity, WIFICLUBACTOR_IsPickable, WIFICLUBACTOR_SetPlayerState, WIFICLUBACTOR_SetWaitState, WIFICLUBACTOR_SetIdleState, WIFICLUBACTOR_SetBounceState, WIFICLUBACTOR_NoOpAnim, WIFICLUBACTOR_AnimateWalkBob, WIFICLUBACTOR_AnimateBounce, WIFICLUBACTOR_UpdatePlayer, WIFICLUBACTOR_UpdateWait, WIFICLUBACTOR_UpdateIdleWander, WIFICLUBACTOR_QueueMoveCommand, WIFICLUBACTOR_QueueActorMove, WIFICLUBACTOR_IsNotWalkBobbing, WIFICLUBACTOR_ApplyActorMode, WIFICLUBACTOR_InitBlink, WIFICLUBACTOR_ExitBlink, WIFICLUBACTOR_TickBlinkAll, WIFICLUBACTOR_TickBlinkFrame, WIFICLUBACTOR_TickBlinkScript, WIFICLUBACTOR_GetBlinkColors, WIFICLUBACTOR_EndBlinkScript, WIFICLUBACTOR_RequestBlinkRestart, WIFICLUBACTOR_StartBlinkScript, WIFICLUBACTOR_RestartBlinkScript, WIFICLUBACTOR_GetCommandTable, WIFICLUBACTOR_GetCommandCount, WIFICLUBACTOR_AddNetCommands, WIFICLUBACTOR_RemoveNetCommands, WIFICLUBACTOR_NetCallbackA, WIFICLUBACTOR_NetCallbackB, WIFICLUBACTOR_NetCallbackC, WIFICLUBACTOR_GetMapSize
 * address:  0x021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   WIFICLUB_GetMessageIdByIndex  0x021BA81C  thumb  ov099
 *   WF2DMAP_MAP_CreateGrid  0x021C47A0  thumb  ov127
 *   WF2DMAP_MAP_CopyEntries  0x021C4800  thumb  ov127
 *   WF2DMAP_OBJ_CreateList  0x021C4880  thumb  ov127
 *   WF2DMAP_OBJDRAW_ClearPos  0x021C59D0  thumb  ov127
 *   WF2DMAP_CMDQ_CreateStore  0x021C5EEC  thumb  ov127
 *   WF2DMAP_CMDQ_DeleteStore  0x021C5F30  thumb  ov127
 *   WF2DMAP_OBJ_DeleteList  0x021C48C0  thumb  ov127
 *   WF2DMAP_MAP_DeleteGrid  0x021C47E4  thumb  ov127
 *   WF2DMAP_OBJ_UpdateList  0x021C48E8  thumb  ov127
 *   WF2DMAP_OBJDRAW_SetPosFromOwner  0x021C5994  thumb  ov127
 *   WF2DMAP_SCRDRAW_UpdatePosition  0x021C5A60  thumb  ov127
 *   WF2DMAP_OBJDRAW_UpdateAllActors  0x021C571C  thumb  ov127
 *   KEY_GetCont  0x0203630C  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   WF2DMAP_OBJ_GetSlot  0x021C49A4  thumb  ov127
 *   WF2DMAP_OBJ_GetPos  0x021C4AC4  thumb  ov127
 *   WF2DMAP_MAP_GetCellValue  0x021C4864  thumb  ov127
 *   WF2DMAP_OBJDRAW_GetActorValue2  0x021C5858  thumb  ov127
 *   WF2DMAP_OBJDRAW_SetActorValue2  0x021C584C  thumb  ov127
 *   WF2DMAP_OBJDRAW_SetActive  0x021C57D8  thumb  ov127
 *   WF2DMAP_OBJDRAW_SetFrameDefault  0x021C57DC  thumb  ov127
 *   WF2DMAP_OBJ_Clear  0x021C4948  thumb  ov127
 *   WF2DMAP_OBJDRAW_RemoveActor  0x021C5704  thumb  ov127
 *   WF2DMAP_OBJ_GetTableByte  0x021C4A8C  thumb  ov127
 *   WF2DMAP_OBJDRAW_SetFrameZero  0x021C5864  thumb  ov127
 *   WF2DMAP_OBJDRAW_SetActorPos  0x021C5814  thumb  ov127
 *   WF2DMAP_OBJ_OffsetPos  0x021C4A54  thumb  ov127
 *   WF2DMAP_OBJ_DispatchById  0x021C48D4  thumb  ov127
 *   WF2DMAP_OBJCMD_Dispatch  0x021C5370  thumb  ov127
 *   WF2DMAP_CMDQ_Pop  0x021C5F80  thumb  ov127
 *   WF2DMAP_OBJ_FindAtPos  0x021C4BA4  thumb  ov127
 *   WF2DMAP_OBJDRAW_CreateAnimSeq 0x021C5590 thumb ov127
 *   WF2DMAP_OBJDRAW_ConfigureSprite 0x021C5664 thumb ov127
 *   WF2DMAP_OBJDRAW_DeleteAnimSeq  0x021C5608  thumb  ov127
 *   d_021C289C     0x021C289C  data  a1
 *   WF2DMAP_SCRDRAW_CreateBitmapDesc  0x021C59F4  thumb  ov127
 *   WF2DMAP_SCRDRAW_DeleteBitmapDesc  0x021C5A4C  thumb  ov127
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   BG_SYS_LoadPlttEntry  0x02040EBC  arm
 *   func_02049624  0x02049624  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_SetActorPos 0x0204B528 arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   WF2DMAP_MAP_GetWidth  0x021C47F8  thumb  ov127
 *   WF2DMAP_MAP_GetHeight  0x021C47FC  thumb  ov127
 *   WF2DMAP_OBJDRAW_AddActor 0x021C5680 thumb ov127
 *   WF2DMAP_OBJDRAW_SetActorValue 0x021C5840 thumb ov127
 *   WF2DMAP_OBJ_Create 0x021C4918 thumb ov127
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   WF2DMAP_OBJDRAW_RefreshActor  0x021C57E8  thumb  ov127
 *   WF2DMAP_OBJDRAW_GetActorValue  0x021C5834  thumb  ov127
 *   GF_STANDARD_Get_F5FC  0x0203F5FC  arm
 *   _ll_mul        0x0209C054  arm
 *   WF2DMAP_OBJDRAW_SetActorPos2  0x021C5898  thumb  ov127
 *   WF2DMAP_OBJDRAW_RestoreFrame  0x021C57F4  thumb  ov127
 *   WF2DMAP_CMDQ_Push  0x021C5F44  thumb  ov127
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   d_021C2878 0x021C2878 data ov099 a2
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   NNS_GfdRegisterNewVramTransferTask  0x02061CA4  arm
 *   d_021C287C     0x021C287C  data  ov099  a1
 *   data_021C28A8  0x021C28A8  data
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   data_021C28F0  0x021C28F0  data  a4
 */
#include "wifi_club_actor_types.h"

/* Placement request for the entity manager. */
typedef struct {
    short x, y;
    u16 id, kind, flag, graphic;
} EntitySpawnParams;

/* Actor creation parameters of CLACT_CreateActor. */
typedef struct {
    u16 vramType, drawArea, animSeq;
    u8 bgPriority, drawPriority;
} ClactActorParams;

typedef struct {
    u8 b[11];
} LayerParams;

/* One step of the colour blink script. */
typedef struct {
    u8 waitForTimer;    /* 1: step ends when the timer runs out, 0: when a restart is requested */
    u8 duration;
    u8 apply;           /* 1: write a palette entry at the start of the step */
    u8 frame;           /* palette frame to write */
} PaletteStep;

extern u32 WIFICLUB_GetMessageIdByIndex(int mapIndex);
extern void *WF2DMAP_MAP_CreateGrid(u32 width, u32 height, u32 heapId);
extern void WF2DMAP_MAP_CopyEntries(u8 *tileMap, void *mapData);
extern void *WF2DMAP_OBJ_CreateList(u32 count, u32 heapId);
extern void WF2DMAP_OBJDRAW_ClearPos(void *layerState);
extern void *WF2DMAP_CMDQ_CreateStore(int count, int heapId);
extern void WF2DMAP_CMDQ_DeleteStore(u8 *cmdQueue);
extern void WF2DMAP_OBJ_DeleteList(u8 *entityMgr);
extern void WF2DMAP_MAP_DeleteGrid(u8 *tileMap);
extern void WF2DMAP_OBJ_UpdateList(u8 *entityMgr);
extern void WF2DMAP_OBJDRAW_SetPosFromOwner(void *layerState, void *entity);
extern void WF2DMAP_SCRDRAW_UpdatePosition(void *layer, void *layerState);
extern void WF2DMAP_OBJDRAW_UpdateAllActors(u8 *spriteMgr);
extern int WF2DMAP_OBJ_GetSlot(u8 *entity, unsigned int index);
extern TilePos WF2DMAP_OBJ_GetPos(void *entity);
extern u32 WF2DMAP_MAP_GetCellValue(u8 *tileMap, u16 x, u16 y);
extern int WF2DMAP_OBJDRAW_GetActorValue2(u8 *sprite);
extern void WF2DMAP_OBJDRAW_SetActorValue2(u8 *sprite, int value);
extern void WF2DMAP_OBJDRAW_SetActive(u8 *sprite, int value);
extern void WF2DMAP_OBJDRAW_SetFrameDefault(u8 *sprite);
extern void WF2DMAP_OBJDRAW_RemoveActor(u8 *sprite);
extern void WF2DMAP_OBJ_Clear(void *entity);
extern unsigned char WF2DMAP_OBJ_GetTableByte(int direction);
extern void WF2DMAP_OBJDRAW_SetFrameZero(u8 *sprite, int value);
extern void WF2DMAP_OBJDRAW_SetActorPos(void *sprite, TilePos pos);
extern TilePos WF2DMAP_OBJ_OffsetPos(TilePos pos, int direction);
extern int WF2DMAP_CMDQ_Pop(void *cmdQueue, int *out);
extern int WF2DMAP_OBJCMD_Dispatch(void *tileMap, void *entityMgr, const u8 *desc, int *out);
extern void WF2DMAP_OBJ_DispatchById(void *entityMgr, u8 *entry);
extern u8 *WF2DMAP_OBJ_FindAtPos(u8 *key, void *entityMgr, int direction);
extern void *WF2DMAP_OBJDRAW_CreateAnimSeq(void *, void *, u32, void *, int, u32, u32);
extern void WF2DMAP_OBJDRAW_ConfigureSprite(char *, int, int);
extern void WF2DMAP_OBJDRAW_DeleteAnimSeq(u8 *spriteMgr);
extern void *WF2DMAP_SCRDRAW_CreateBitmapDesc(void *a, void *b, LayerParams *params, int x);
extern void WF2DMAP_SCRDRAW_DeleteBitmapDesc(u8 *layer);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void BG_SYS_LoadPlttEntry(u32 a, u32 b);
extern u32 func_02049624(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern u16 WF2DMAP_MAP_GetWidth(u16 *tileMap);
extern u16 WF2DMAP_MAP_GetHeight(u16 *tileMap);
extern u8 *WF2DMAP_OBJDRAW_AddActor(u8 *, void *, int, u32);
extern void WF2DMAP_OBJDRAW_SetActorValue(char *, int);
extern void *WF2DMAP_OBJ_Create(void *, EntitySpawnParams *);
extern u32 GFL_USE_GetRandom(u32 range);
extern void WF2DMAP_OBJDRAW_RefreshActor(char *sprite);
extern int WF2DMAP_OBJDRAW_GetActorValue(char *sprite);
extern int GF_STANDARD_Get_F5FC(u32 angle);
extern void WF2DMAP_OBJDRAW_SetActorPos2(void *sprite, TilePos pos);
extern void WF2DMAP_OBJDRAW_RestoreFrame(u8 *sprite);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 d, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void *CLACT_CreateActor(void *a, unsigned int b, unsigned int c, unsigned int d, const void *e, u16 f, u16 g);
extern void CLACT_SetActorDrawEnable(void *actor, unsigned int enable);
extern void CLACT_SetActorAutoAnim(void *actor, u32 enable);
extern void CLACT_DeleteActor(void *actor);
extern void CLACT_SetActorPos(void *actor, TilePos *pos);
extern void CLACT_SetActorDrawPriority(void *actor, u32 priority);
extern u32 KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern void WF2DMAP_CMDQ_Push(void *cmdQueue, void *command);
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 archive, u32 fileIndex, u32 outData, u32 heapId);
extern u32 GFL_HEAP_Free(void *handle);
extern s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32 size);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
void WIFICLUBACTOR_Init(WifiClubActorSys *sys, int heapId, u32 clactResArc, u32 spriteArc, u32 mapIndexPlusOne, u32 paletteArc, u32 clactSys, u32 gfxArchive);
void WIFICLUBACTOR_Exit(WifiClubActorSys *sys);
int WIFICLUBACTOR_IsReady(WifiClubActorSys *sys);
u32 WIFICLUBACTOR_Update(WifiClubActorSys *sys);
int WIFICLUBACTOR_UpdatePickRequest(WifiClubActorSys *sys, WifiClubActor *actor);
void WIFICLUBACTOR_UpdatePickRequests(WifiClubActorSys *sys);
u8 WIFICLUBACTOR_GetPickResult(WifiClubActorSys *sys);
int WIFICLUBACTOR_GetCursorTileAttr(WifiClubActorSys *sys);
int WIFICLUBACTOR_GetCursorTileBelowAttr(WifiClubActorSys *sys);
void WIFICLUBACTOR_ShowMarkerAtActor(void *sys, WifiClubActor *actor);
void WIFICLUBACTOR_ResumeActorSprite(int unused, WifiClubActor *actor);
void WIFICLUBACTOR_HideMarker(WifiClubActorSys *sys);
void WIFICLUBACTOR_SetMode(WifiClubActorSys *sys, u32 mode);
u32 WIFICLUBACTOR_GetMode(WifiClubActorSys *sys);
WifiClubActor *WIFICLUBACTOR_SpawnCursorActor(WifiClubActorSys *sys, int graphic);
void *WIFICLUBACTOR_SpawnSlotActor(WifiClubActorSys *sys, int graphic, int slotPlusOne);
void WIFICLUBACTOR_StartDespawn(void *sys, WifiClubActor *actor);
void WIFICLUBACTOR_FreeActor(WifiClubActor *actor);
u8 WIFICLUBACTOR_GetActorId(WifiClubActor *actor);
unsigned char WIFICLUBACTOR_GetActorFacing(WifiClubActor *actor);
void WIFICLUBACTOR_StartTurn(void *sys, WifiClubActor *actor, int direction);
void WIFICLUBACTOR_RestoreActorUpdate(void *sys, WifiClubActor *actor);
void WIFICLUBACTOR_SetActorMode(void *sys, WifiClubActor *actor, u8 mode);
void WIFICLUBACTOR_StartBlinkOnTile(WifiClubActorSys *sys);
void WIFICLUBACTOR_RestartBlink(WifiClubActorSys *sys);
void WIFICLUBACTOR_TickBlink(WifiClubActorSys *sys);
void WIFICLUBACTOR_FreeAllActors(WifiClubActorSys *sys);
BOOL WIFICLUBACTOR_IsCursorFree(WifiClubActorSys *sys);
int WIFICLUBACTOR_IsFacingEntrance(WifiClubActorSys *sys);
void WIFICLUBACTOR_ProcessSpawnCommands(WifiClubActorSys *sys);
void WIFICLUBACTOR_UpdateActors(WifiClubActorSys *sys);
void WIFICLUBACTOR_AnimateActors(WifiClubActorSys *sys);
void *WIFICLUBACTOR_FindActorFacing(WifiClubActorSys *sys, WifiClubActor *actor, int direction);
void WIFICLUBACTOR_InitSpriteManager(WifiClubActorSys *sys, void *spriteArc, u32 heapId);
void WIFICLUBACTOR_ExitSpriteManager(WifiClubActorSys *sys);
void WIFICLUBACTOR_InitLayer(WifiClubActorSys *sys, int heapId, int unused, int mapIndex);
void WIFICLUBACTOR_ExitLayer(WifiClubActorSys *sys);
void WIFICLUBACTOR_InitSprites(WifiClubSpriteSet *sprites, u32 heapId, u32 clactResArc);
void WIFICLUBACTOR_ExitSprites(WifiClubSpriteSet *sprites);
void WIFICLUBACTOR_RegisterResources(WifiClubSpriteSet *sprites, int heapId, u32 clactResArc);
void WIFICLUBACTOR_ReleaseResources(WifiClubSpriteSet *sprites);
void WIFICLUBACTOR_CreateCursorActors(WifiClubSpriteSet *sprites, int heapId);
void WIFICLUBACTOR_DeleteCursorActors(WifiClubSpriteSet *sprites);
void WIFICLUBACTOR_NoOpInit(void *unused, int heapId);
void WIFICLUBACTOR_NoOpExit(int unused);
void WIFICLUBACTOR_LoadPalette(void *unused, u32 heapId, u32 clactResArc, u32 paletteArc);
void WIFICLUBACTOR_RegisterClactResources(WifiClubSpriteSet *sprites, int heapId, u32 clactResArc);
void WIFICLUBACTOR_ReleaseClactResources(WifiClubSpriteSet *sprites);
void WIFICLUBACTOR_CreateClactActors(WifiClubSpriteSet *sprites, int heapId);
void WIFICLUBACTOR_DeleteClactActors(WifiClubSpriteSet *sprites);
void WIFICLUBACTOR_ShowCursor(WifiClubActorSys *sys);
void WIFICLUBACTOR_HideCursor(WifiClubActorSys *sys);
void WIFICLUBACTOR_ShowMarker(WifiClubActorSys *sys, TilePos pos, int priority);
void WIFICLUBACTOR_HideMarkerActor(WifiClubActorSys *sys);
int WIFICLUBACTOR_IsCursorOnExit(WifiClubActorSys *sys);
void WIFICLUBACTOR_FindSlotTile(WifiClubActorSys *sys, u16 *out, u32 slot);
void WIFICLUBACTOR_FindCursorStartTile(WifiClubActorSys *sys, u16 *out);
WifiClubActor *WIFICLUBACTOR_FindFreeActor(WifiClubActorSys *sys);
void WIFICLUBACTOR_AttachSprite(WifiClubActorSys *sys, WifiClubActor *actor, int visible);
void WIFICLUBACTOR_SpawnEntity(WifiClubActorSys *sys, void **out, short *xy, int id, u16 graphic, u8 flag, int kind);
BOOL WIFICLUBACTOR_IsPickable(WifiClubActor *actor);
void WIFICLUBACTOR_SetPlayerState(void *sys, WifiClubActor *actor);
void WIFICLUBACTOR_SetWaitState(int unused, WifiClubActor *actor);
void WIFICLUBACTOR_SetIdleState(void *sys, WifiClubActor *actor);
void WIFICLUBACTOR_SetBounceState(void *sys, WifiClubActor *actor);
void WIFICLUBACTOR_NoOpAnim(void);
void WIFICLUBACTOR_AnimateWalkBob(void *sys, WifiClubActor *actor);
void WIFICLUBACTOR_AnimateBounce(void *sys, WifiClubActor *actor);
int WIFICLUBACTOR_UpdatePlayer(WifiClubActorSys *sys, WifiClubActor *actor);
int WIFICLUBACTOR_UpdateWait(WifiClubActorSys *sys, WifiClubActor *actor);
int WIFICLUBACTOR_UpdateDespawn(WifiClubActorSys *sys, WifiClubActor *actor);
int WIFICLUBACTOR_UpdateIdleWander(void *sys, WifiClubActor *actor);
int WIFICLUBACTOR_UpdateBounce(void *sys, WifiClubActor *actor);
int WIFICLUBACTOR_UpdateNone(void);
void WIFICLUBACTOR_QueueMoveCommand(WifiClubActorSys *sys, int action, int direction, int actorId);
void WIFICLUBACTOR_QueueActorMove(void *sys, int action, WifiClubActor *actor);
BOOL WIFICLUBACTOR_IsNotWalkBobbing(WifiClubActor *actor);
void WIFICLUBACTOR_ApplyActorMode(void *sys, WifiClubActor *actor, u8 mode);
void WIFICLUBACTOR_InitBlink(WifiClubActorSys *sys, WifiClubPaletteBlink *blink, u32 unused, u32 archive);
void WIFICLUBACTOR_ExitBlink(int unused, WifiClubPaletteBlink *blink);
void WIFICLUBACTOR_TickBlinkAll(int unused, WifiClubPaletteBlink *blink);
void WIFICLUBACTOR_TickBlinkFrame(WifiClubPaletteBlink *blink);
void WIFICLUBACTOR_TickBlinkScript(WifiClubPaletteBlink *blink);
u16 *WIFICLUBACTOR_GetBlinkColors(WifiClubPaletteBlink *blink, int i);
void WIFICLUBACTOR_EndBlinkScript(WifiClubPaletteBlink *blink);
void WIFICLUBACTOR_RequestBlinkRestart(WifiClubPaletteBlink *blink);
void WIFICLUBACTOR_StartBlinkScript(WifiClubPaletteBlink *blink, u8 colorIndex);
void WIFICLUBACTOR_RestartBlinkScript(WifiClubPaletteBlink *blink);
u8 *WIFICLUBACTOR_GetCommandTable(void);
int WIFICLUBACTOR_GetCommandCount(void);
void WIFICLUBACTOR_AddNetCommands(void *work);
void WIFICLUBACTOR_RemoveNetCommands(void *unused);
void WIFICLUBACTOR_NetCallbackA(int a, int b, int c, int d);
void WIFICLUBACTOR_NetCallbackB(int a, int b, int c, int d);
void WIFICLUBACTOR_NetCallbackC(int a, int b, int c, int d);
MapSize WIFICLUBACTOR_GetMapSize(int mapIndex);
extern LayerParams d_021C289C;
extern const u16 d_021C2878[];
extern const PaletteStep d_021C287C[];
extern u8 data_021C28A8[];
extern const MapSize data_021C28F0[];


/* Frame counter in the shared system area; bit 0 selects the frames that run
 * the full per-actor update. */
#define OS_VBLANK_COUNT (*(u32 *)0x02FFFC3C)


void WIFICLUBACTOR_Init(WifiClubActorSys *sys, int heapId, u32 clactResArc, u32 spriteArc, u32 mapIndexPlusOne, u32 paletteArc, u32 clactSys, u32 gfxArchive)
{
    MapSize size;
    u32 mapIndex = 0;

    MI_CpuFill8(sys, 0, 0x5A0);
    if (mapIndexPlusOne != 0) mapIndex = (mapIndexPlusOne - 1) >> 3;
    sys->sprites.clactSys = (void *)clactSys;
    sys->heapId = heapId;
    sys->sprites.gfxArchive = (void *)gfxArchive;
    WIFICLUBACTOR_InitSprites(&sys->sprites, heapId, clactResArc);
    WIFICLUBACTOR_NoOpInit(sys->reserved10, heapId);
    size = WIFICLUBACTOR_GetMapSize(mapIndex);
    sys->tileMap = WF2DMAP_MAP_CreateGrid(size.w, size.h, heapId);
    WF2DMAP_MAP_CopyEntries(sys->tileMap, (void *)WIFICLUB_GetMessageIdByIndex(mapIndex));
    sys->entityMgr = WF2DMAP_OBJ_CreateList(0x30, heapId);
    WIFICLUBACTOR_InitSpriteManager(sys, (void *)spriteArc, heapId);
    WF2DMAP_OBJDRAW_ClearPos(&sys->layerState);
    WIFICLUBACTOR_InitLayer(sys, heapId, clactResArc, mapIndex);
    WIFICLUBACTOR_LoadPalette(sys->reserved10, heapId, clactResArc, paletteArc);
    WIFICLUBACTOR_InitBlink(sys, &sys->blink, clactResArc, paletteArc);
    sys->cmdQueue = WF2DMAP_CMDQ_CreateStore(0x80, heapId);
    sys->ready = 1;
}


void WIFICLUBACTOR_Exit(WifiClubActorSys *sys)
{
    WF2DMAP_CMDQ_DeleteStore(sys->cmdQueue);
    WIFICLUBACTOR_ExitLayer(sys);
    WIFICLUBACTOR_ExitBlink((int)sys, &sys->blink);
    WIFICLUBACTOR_FreeAllActors(sys);
    WIFICLUBACTOR_ExitSpriteManager(sys);
    WF2DMAP_OBJ_DeleteList(sys->entityMgr);
    WF2DMAP_MAP_DeleteGrid(sys->tileMap);
    WIFICLUBACTOR_ExitSprites(&sys->sprites);
    WIFICLUBACTOR_NoOpExit((int)sys->reserved10);
    MI_CpuFill8(sys, 0, 0x5a0);
}


int WIFICLUBACTOR_IsReady(WifiClubActorSys *sys)
{
    return sys->ready;
}


u32 WIFICLUBACTOR_Update(WifiClubActorSys *sys)
{
    if (OS_VBLANK_COUNT & 1) {
        WF2DMAP_OBJ_UpdateList(sys->entityMgr);
        WIFICLUBACTOR_UpdateActors(sys);
        WIFICLUBACTOR_ProcessSpawnCommands(sys);
        WF2DMAP_OBJDRAW_SetPosFromOwner(&sys->layerState, sys->selected->entity);
        WF2DMAP_SCRDRAW_UpdatePosition(sys->layer, &sys->layerState);
        WF2DMAP_OBJDRAW_UpdateAllActors(sys->spriteMgr);
        WIFICLUBACTOR_AnimateActors(sys);
        WIFICLUBACTOR_HideCursor(sys);
    }
    if (WIFICLUBACTOR_IsCursorFree(sys) == 1) {
        WIFICLUBACTOR_UpdatePickRequests(sys);
        if (WIFICLUBACTOR_IsCursorOnExit(sys) == 1) {
            WIFICLUBACTOR_ShowCursor(sys);
            if (KEY_GetCont() & 0x80)
                return 1;
        }
        if (KEY_GetTrg() & 1) {
            if (WIFICLUBACTOR_GetPickResult(sys) != 0)
                return 2;
            if (WIFICLUBACTOR_IsFacingEntrance(sys) == 1)
                return 3;
        }
    }
    return 0;
}


int WIFICLUBACTOR_UpdatePickRequest(WifiClubActorSys *sys, WifiClubActor *actor)
{
    int pickResult;
    int direction;
    WifiClubActor *target;

    direction = WF2DMAP_OBJ_GetSlot(actor->entity, 6);
    if (KEY_GetTrg() & 1) {
        target = WIFICLUBACTOR_FindActorFacing(sys, actor, direction);
        if (target != 0) {
            if (WIFICLUBACTOR_IsPickable(target) == 1)
                pickResult = WF2DMAP_OBJ_GetSlot(target->entity, 4);
            else
                pickResult = 0;
        } else
            pickResult = 0;
        actor->pickResult = pickResult;
    }
    return 1;
}


void WIFICLUBACTOR_UpdatePickRequests(WifiClubActorSys *sys)
{
    int i;
    for (i = 0; i < 0x30; i++) {
        if (sys->actors[i].entity != 0) {
            WIFICLUBACTOR_UpdatePickRequest(sys, &sys->actors[i]);
        }
    }
}


u8 WIFICLUBACTOR_GetPickResult(WifiClubActorSys *sys)
{
    return sys->selected->pickResult;
}


int WIFICLUBACTOR_GetCursorTileAttr(WifiClubActorSys *sys)
{
    TilePos pos = WF2DMAP_OBJ_GetPos(sys->selected->entity);
    return WF2DMAP_MAP_GetCellValue(sys->tileMap, pos.x / 16, pos.y / 16);
}


int WIFICLUBACTOR_GetCursorTileBelowAttr(WifiClubActorSys *sys)
{
    TilePos pos = WF2DMAP_OBJ_GetPos(sys->selected->entity);
    return WF2DMAP_MAP_GetCellValue(sys->tileMap, pos.x / 16, pos.y / 16 + 1);
}


void WIFICLUBACTOR_ShowMarkerAtActor(void *sys, WifiClubActor *actor)
{
    TilePos pos = WF2DMAP_OBJ_GetPos(actor->entity);
    WIFICLUBACTOR_ShowMarker(sys, pos, WF2DMAP_OBJDRAW_GetActorValue2(actor->sprite) - 2);
    WF2DMAP_OBJDRAW_SetActorValue2(actor->sprite, 0);
}


void WIFICLUBACTOR_ResumeActorSprite(int unused, WifiClubActor *actor)
{
    WF2DMAP_OBJDRAW_SetActorValue2(actor->sprite, 1);
}


void WIFICLUBACTOR_HideMarker(WifiClubActorSys *sys)
{
    WIFICLUBACTOR_HideMarkerActor(sys);
}


void WIFICLUBACTOR_SetMode(WifiClubActorSys *sys, u32 mode)
{
    sys->mode = mode;
}


u32 WIFICLUBACTOR_GetMode(WifiClubActorSys *sys)
{
    return sys->mode;
}


WifiClubActor *WIFICLUBACTOR_SpawnCursorActor(WifiClubActorSys *sys, int graphic)
{
    WifiClubActor *actor;
    u16 xy[2];

    actor = WIFICLUBACTOR_FindFreeActor(sys);
    sys->selected = actor;
    WIFICLUBACTOR_FindCursorStartTile(sys, xy);
    WIFICLUBACTOR_SpawnEntity(sys, &actor->entity, (short *)xy, 0, graphic, 0, 0);
    WIFICLUBACTOR_SetPlayerState(sys, actor);
    WIFICLUBACTOR_AttachSprite(sys, actor, 1);
    WF2DMAP_OBJDRAW_SetPosFromOwner(&sys->layerState, sys->selected->entity);
    WF2DMAP_SCRDRAW_UpdatePosition(sys->layer, &sys->layerState);
    return actor;
}


void *WIFICLUBACTOR_SpawnSlotActor(WifiClubActorSys *sys, int graphic, int slotPlusOne)
{
    WifiClubActor *actor;
    TilePos spawn;
    TilePos cursor;

    actor = WIFICLUBACTOR_FindFreeActor(sys);
    WIFICLUBACTOR_FindSlotTile(sys, (u16 *)&spawn, slotPlusOne - 1);
    if (sys->selected != 0) {
        cursor = WF2DMAP_OBJ_GetPos(sys->selected->entity);
        if (cursor.x == spawn.x && cursor.y == spawn.y)
            return 0;
    }
    WIFICLUBACTOR_SpawnEntity(sys, &actor->entity, (short *)&spawn, slotPlusOne, graphic, 1, 4);
    WIFICLUBACTOR_SetWaitState((int)sys, actor);
    WIFICLUBACTOR_AttachSprite(sys, actor, 0);
    return actor;
}


void WIFICLUBACTOR_StartDespawn(void *sys, WifiClubActor *actor)
{
    WF2DMAP_OBJ_GetSlot(actor->entity, 6);
    actor->updateFn = WIFICLUBACTOR_UpdateDespawn;
    actor->counter.timer = 0;
    actor->animFn = WIFICLUBACTOR_AnimateWalkBob;
    actor->state = 2;
    WF2DMAP_OBJDRAW_SetActive(actor->sprite, 0);
    WF2DMAP_OBJDRAW_SetFrameDefault(actor->sprite);
    WIFICLUBACTOR_QueueActorMove(sys, 4, actor);
}


void WIFICLUBACTOR_FreeActor(WifiClubActor *actor)
{
    WF2DMAP_OBJDRAW_RemoveActor(actor->sprite);
    WF2DMAP_OBJ_Clear(actor->entity);
    MI_CpuFill8(actor, 0, sizeof(WifiClubActor));
}


u8 WIFICLUBACTOR_GetActorId(WifiClubActor *actor)
{
    return (u8)WF2DMAP_OBJ_GetSlot(actor->entity, 4);
}


unsigned char WIFICLUBACTOR_GetActorFacing(WifiClubActor *actor)
{
    return WF2DMAP_OBJ_GetTableByte(WF2DMAP_OBJ_GetSlot(actor->entity, 6));
}


void WIFICLUBACTOR_StartTurn(void *sys, WifiClubActor *actor, int direction)
{
    TilePos pos;

    actor->prevUpdateFn = actor->updateFn;
    actor->updateFn = WIFICLUBACTOR_UpdateNone;
    actor->prevState = actor->state;
    actor->state = 5;
    WIFICLUBACTOR_QueueMoveCommand(sys, 0, direction, WF2DMAP_OBJ_GetSlot(actor->entity, 4));
    WF2DMAP_OBJDRAW_SetActive(actor->sprite, 0);
    WF2DMAP_OBJDRAW_SetFrameZero(actor->sprite, direction);
    pos.x = WF2DMAP_OBJ_GetSlot(actor->entity, 0);
    pos.y = WF2DMAP_OBJ_GetSlot(actor->entity, 1);
    WF2DMAP_OBJDRAW_SetActorPos(actor->sprite, pos);
}


void WIFICLUBACTOR_RestoreActorUpdate(void *sys, WifiClubActor *actor)
{
    if (actor) {
        if (actor->prevUpdateFn) {
            actor->updateFn = actor->prevUpdateFn;
            actor->prevUpdateFn = 0;
            actor->state = actor->prevState;
            WF2DMAP_OBJDRAW_SetActive(actor->sprite, 1);
        }
    }
}


void WIFICLUBACTOR_SetActorMode(void *sys, WifiClubActor *actor, u8 mode)
{
    if (WIFICLUBACTOR_IsNotWalkBobbing(actor) == 0) {
        actor->savedMode = mode;
    } else {
        WIFICLUBACTOR_ApplyActorMode(sys, actor, mode);
    }
}


void WIFICLUBACTOR_StartBlinkOnTile(WifiClubActorSys *sys)
{
    if (WIFICLUBACTOR_IsFacingEntrance(sys) == 1) {
        s8 tileAttr = (s8)WIFICLUBACTOR_GetCursorTileBelowAttr(sys);
        s8 colorIndex = tileAttr - 3;
        WIFICLUBACTOR_StartBlinkScript(&sys->blink, colorIndex);
    }
}


void WIFICLUBACTOR_RestartBlink(WifiClubActorSys *sys)
{
    WIFICLUBACTOR_RestartBlinkScript(&sys->blink);
}


void WIFICLUBACTOR_TickBlink(WifiClubActorSys *sys)
{
    if (OS_VBLANK_COUNT & 1) {
        WIFICLUBACTOR_TickBlinkAll((int)sys, &sys->blink);
    }
}


void WIFICLUBACTOR_FreeAllActors(WifiClubActorSys *sys)
{
    int i;
    for (i = 0; i < 0x30; i++) {
        if (sys->actors[i].entity != 0) {
            WIFICLUBACTOR_FreeActor(&sys->actors[i]);
        }
    }
}


BOOL WIFICLUBACTOR_IsCursorFree(WifiClubActorSys *sys)
{
    if (WF2DMAP_OBJ_GetSlot(sys->selected->entity, 5) == 0) {
        return 1;
    }
    return 0;
}


int WIFICLUBACTOR_IsFacingEntrance(WifiClubActorSys *sys)
{
    TilePos pos;
    TilePos front;
    int direction;
    int attr;

    pos = WF2DMAP_OBJ_GetPos(sys->selected->entity);
    direction = WF2DMAP_OBJ_GetSlot(sys->selected->entity, 6);
    front = WF2DMAP_OBJ_OffsetPos(pos, direction);
    attr = WF2DMAP_MAP_GetCellValue(sys->tileMap, front.x / 16, front.y / 16);
    if (direction == 0 && attr == 2)
        return 1;
    return 0;
}


void WIFICLUBACTOR_ProcessSpawnCommands(WifiClubActorSys *sys)
{
    int command;
    int spawned[2];

    while (WF2DMAP_CMDQ_Pop(sys->cmdQueue, &command) == 1) {
        if (WF2DMAP_OBJCMD_Dispatch(sys->tileMap, sys->entityMgr, (const u8 *)&command, spawned) == 1)
            WF2DMAP_OBJ_DispatchById(sys->entityMgr, (u8 *)spawned);
    }
}


void WIFICLUBACTOR_UpdateActors(WifiClubActorSys *sys)
{
    int i;
    for (i = 0; i < 0x30; i++) {
        if (sys->actors[i].entity) {
            if (sys->actors[i].updateFn(sys, &sys->actors[i]) == 1)
                WIFICLUBACTOR_FreeActor(&sys->actors[i]);
        }
    }
}


void WIFICLUBACTOR_AnimateActors(WifiClubActorSys *sys)
{
    int i;
    for (i = 0; i < 0x30; i++) {
        if (sys->actors[i].entity != 0) {
            sys->actors[i].animFn(sys, &sys->actors[i]);
        }
    }
}


void *WIFICLUBACTOR_FindActorFacing(WifiClubActorSys *sys, WifiClubActor *actor, int direction)
{
    void *found = WF2DMAP_OBJ_FindAtPos((u8 *)actor->entity, sys->entityMgr, direction);
    int i;
    if (found != 0) {
        for (i = 0; i < 0x30; i++) {
            if (sys->actors[i].entity == found) {
                return &sys->actors[i];
            }
        }
    }
    return 0;
}


void WIFICLUBACTOR_InitSpriteManager(WifiClubActorSys *sys, void *spriteArc, u32 heapId)
{
    void *spriteMgr;
    spriteMgr = WF2DMAP_OBJDRAW_CreateAnimSeq(sys->sprites.clactSys, 0, 48, spriteArc, 0, 0, heapId);
    sys->spriteMgr = spriteMgr;
    WF2DMAP_OBJDRAW_ConfigureSprite(spriteMgr, 2, heapId);
}


void WIFICLUBACTOR_ExitSpriteManager(WifiClubActorSys *sys)
{
    WF2DMAP_OBJDRAW_DeleteAnimSeq(sys->spriteMgr);
}


void WIFICLUBACTOR_InitLayer(WifiClubActorSys *sys, int heapId, int unused, int mapIndex)
{
    LayerParams params = d_021C289C;
    params.b[9] += (u8)mapIndex;
    sys->layer = WF2DMAP_SCRDRAW_CreateBitmapDesc(sys->sprites.gfxArchive, sys->reserved10, &params, heapId);
}


void WIFICLUBACTOR_ExitLayer(WifiClubActorSys *sys)
{
    WF2DMAP_SCRDRAW_DeleteBitmapDesc(sys->layer);
}


void WIFICLUBACTOR_InitSprites(WifiClubSpriteSet *sprites, u32 heapId, u32 clactResArc)
{
    WIFICLUBACTOR_RegisterResources(sprites, heapId, clactResArc);
    WIFICLUBACTOR_CreateCursorActors(sprites, heapId);
}


void WIFICLUBACTOR_ExitSprites(WifiClubSpriteSet *sprites)
{
    WIFICLUBACTOR_DeleteCursorActors(sprites);
    WIFICLUBACTOR_ReleaseResources(sprites);
}


void WIFICLUBACTOR_RegisterResources(WifiClubSpriteSet *sprites, int heapId, u32 clactResArc)
{
    WIFICLUBACTOR_RegisterClactResources(sprites, heapId, clactResArc);
}


void WIFICLUBACTOR_ReleaseResources(WifiClubSpriteSet *sprites)
{
    WIFICLUBACTOR_ReleaseClactResources(sprites);
}


void WIFICLUBACTOR_CreateCursorActors(WifiClubSpriteSet *sprites, int heapId)
{
    WIFICLUBACTOR_CreateClactActors(sprites, heapId);
}


void WIFICLUBACTOR_DeleteCursorActors(WifiClubSpriteSet *sprites)
{
    WIFICLUBACTOR_DeleteClactActors(sprites);
}


void WIFICLUBACTOR_NoOpInit(void *unused, int heapId)
{
}


void WIFICLUBACTOR_NoOpExit(int unused)
{
}


void WIFICLUBACTOR_LoadPalette(void *unused, u32 heapId, u32 clactResArc, u32 paletteArc)
{
    u32 zero = 0;
    ARC_UTIL_UploadPaletteFromArchiveWhole(paletteArc, 7, 0, 0, 0x100, heapId);
    BG_SYS_LoadPlttEntry(0, 0);
    func_02049624((void *)paletteArc, (void *)0x10, 0, 0, zero, zero, heapId);
}


void WIFICLUBACTOR_RegisterClactResources(WifiClubSpriteSet *sprites, int heapId, u32 clactResArc)
{
    sprites->charRes = CLACT_RegisterCharacter((void *)clactResArc, 0x11, 0, 0, heapId);
    sprites->palRes = CLACT_RegisterPaletteEx((void *)clactResArc, 8, 0, 0x160, 0, 2, heapId);
    sprites->cellRes = CLACT_RegisterCellAnim((void *)clactResArc, 0x14, 0x20, (u16)heapId);
}


void WIFICLUBACTOR_ReleaseClactResources(WifiClubSpriteSet *sprites)
{
    CLACT_ReleaseCharacter((u32)sprites->charRes);
    CLACT_ReleasePalette((u32)sprites->palRes);
    CLACT_ReleaseCellAnim((u32)sprites->cellRes);
}


void WIFICLUBACTOR_CreateClactActors(WifiClubSpriteSet *sprites, int heapId)
{
    ClactActorParams params;

    params.vramType = 1;
    params.drawArea = 1;
    params.animSeq = 0;
    params.bgPriority = 0;
    params.drawPriority = 0;
    sprites->cursorActor = CLACT_CreateActor(sprites->clactSys, sprites->charRes, sprites->palRes, sprites->cellRes, &params, 0, heapId);
    params.animSeq = 2;
    params.bgPriority = 0xfe;
    params.drawPriority = 3;
    sprites->markerActor = CLACT_CreateActor(sprites->clactSys, sprites->charRes, sprites->palRes, sprites->cellRes, &params, 0, heapId);
    CLACT_SetActorDrawEnable(sprites->cursorActor, 0);
    CLACT_SetActorDrawEnable(sprites->markerActor, 0);
    CLACT_SetActorAutoAnim(sprites->cursorActor, 1);
    CLACT_SetActorAutoAnim(sprites->markerActor, 1);
}


void WIFICLUBACTOR_DeleteClactActors(WifiClubSpriteSet *sprites)
{
    CLACT_DeleteActor(sprites->cursorActor);
    CLACT_DeleteActor(sprites->markerActor);
}


void WIFICLUBACTOR_ShowCursor(WifiClubActorSys *sys)
{
    TilePos cursorTile;
    TilePos spritePos;

    WIFICLUBACTOR_FindCursorStartTile(sys, (u16 *)&cursorTile);
    cursorTile.x += 8;
    cursorTile.y += 32;
    spritePos.x = cursorTile.x;
    spritePos.y = cursorTile.y;
    CLACT_SetActorPos(sys->sprites.cursorActor, &spritePos);
    CLACT_SetActorDrawEnable(sys->sprites.cursorActor, 1);
}


void WIFICLUBACTOR_HideCursor(WifiClubActorSys *sys)
{
    CLACT_SetActorDrawEnable(sys->sprites.cursorActor, 0);
}


void WIFICLUBACTOR_ShowMarker(WifiClubActorSys *sys, TilePos pos, int priority)
{
    TilePos markerPos;
    markerPos.x = pos.x + 8;
    markerPos.y = pos.y;
    CLACT_SetActorPos(sys->sprites.markerActor, &markerPos);
    CLACT_SetActorDrawPriority(sys->sprites.markerActor, (unsigned char)priority);
    CLACT_SetActorDrawEnable(sys->sprites.markerActor, 1);
}


void WIFICLUBACTOR_HideMarkerActor(WifiClubActorSys *sys)
{
    CLACT_SetActorDrawEnable(sys->sprites.markerActor, 0);
}


int WIFICLUBACTOR_IsCursorOnExit(WifiClubActorSys *sys)
{
    TilePos pos;
    int direction;
    if (sys->selected == 0)
        return 0;
    pos = WF2DMAP_OBJ_GetPos(sys->selected->entity);
    direction = WF2DMAP_OBJ_GetSlot(sys->selected->entity, 6);
    if (WF2DMAP_MAP_GetCellValue(sys->tileMap, pos.x / 16, pos.y / 16) == 15 && direction == 1)
        return 1;
    return 0;
}


void WIFICLUBACTOR_FindSlotTile(WifiClubActorSys *sys, u16 *out, u32 slot)
{
    u32 y, height, x, width;
    u32 row = slot >> 3;
    u32 column = slot & 7;
    width = WF2DMAP_MAP_GetWidth(sys->tileMap);
    height = WF2DMAP_MAP_GetHeight(sys->tileMap);
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            /* pointer-typed compares: only this form orders the cmp operands as the image does */
            if ((void *)WF2DMAP_MAP_GetCellValue(sys->tileMap, x, y) == (void *)(column + 7)
                && (void *)WF2DMAP_MAP_GetCellValue(sys->tileMap, x, y + 1) == (void *)(row + 3)) {
                out[0] = x << 4;
                out[1] = y << 4;
                return;
            }
        }
    }
}


void WIFICLUBACTOR_FindCursorStartTile(WifiClubActorSys *sys, u16 *out)
{
    u32 y;
    u32 height;
    u32 x;
    u32 width;
    width = WF2DMAP_MAP_GetWidth(sys->tileMap);
    height = WF2DMAP_MAP_GetHeight(sys->tileMap);
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (WF2DMAP_MAP_GetCellValue(sys->tileMap, x, y) == 0xf) {
                out[0] = x * 16;
                out[1] = y * 16;
                return;
            }
        }
    }
}


/* Returns the first free slot (entity zero), else 0.  The two address
 * spellings differ on purpose: the test is `p + i * 0x1C + 0x30`, the return
 * `(p + 0x30) + i * 0x1C`; the image has that register split. */
WifiClubActor *WIFICLUBACTOR_FindFreeActor(WifiClubActorSys *sys)
{
    int i;
    for (i = 0; i < 0x30; i++) {
        if (sys->actors[i].entity == 0) {
            return &sys->actors[i];
        }
    }
    return 0;
}


void WIFICLUBACTOR_AttachSprite(WifiClubActorSys *sys, WifiClubActor *actor, int visible)
{
    actor->sprite = WF2DMAP_OBJDRAW_AddActor(sys->spriteMgr, actor->entity, visible, (u32)sys->heapId);
    if (visible == 0) {
        WF2DMAP_OBJDRAW_SetActive(actor->sprite, 0);
        WF2DMAP_OBJDRAW_SetFrameDefault(actor->sprite);
        WF2DMAP_OBJDRAW_SetActorValue(actor->sprite, 0);
    }
}


void WIFICLUBACTOR_SpawnEntity(WifiClubActorSys *sys, void **out, short *xy, int id, u16 graphic, u8 flag, int kind)
{
    EntitySpawnParams params;
    params.x = xy[0];
    params.y = xy[1];
    params.id = id;
    params.kind = kind;
    params.flag = flag;
    params.graphic = graphic;
    *out = WF2DMAP_OBJ_Create(sys->entityMgr, &params);
}


BOOL WIFICLUBACTOR_IsPickable(WifiClubActor *actor)
{
    switch (actor->state) {
    case 0:
    case 3:
    case 4:
        return 1;
    case 1:
    case 2:
    case 5:
        return 0;
    }
    return 0;
}


void WIFICLUBACTOR_SetPlayerState(void *sys, WifiClubActor *actor)
{
    actor->updateFn = WIFICLUBACTOR_UpdatePlayer;
    actor->animFn = WIFICLUBACTOR_NoOpAnim;
    actor->state = 0;
    WIFICLUBACTOR_QueueActorMove(sys, 0, actor);
}


void WIFICLUBACTOR_SetWaitState(int unused, WifiClubActor *actor)
{
    actor->updateFn = WIFICLUBACTOR_UpdateWait;
    actor->animFn = WIFICLUBACTOR_AnimateWalkBob;
    actor->counter.timer = 0x2D;
    actor->state = 1;
}


/* n stays a runtime shift: the range is a u32 local, 0x400 >> 2 is not folded. */
void WIFICLUBACTOR_SetIdleState(void *sys, WifiClubActor *actor)
{
    u32 n;
    actor->updateFn = WIFICLUBACTOR_UpdateIdleWander;
    actor->animFn = WIFICLUBACTOR_NoOpAnim;
    n = 0x400;
    actor->counter.timer = GFL_USE_GetRandom(n) + (n >> 2);
    actor->state = 3;
    WIFICLUBACTOR_QueueActorMove(sys, 0, actor);
    WF2DMAP_OBJDRAW_SetActive(actor->sprite, 1);
}


void WIFICLUBACTOR_SetBounceState(void *sys, WifiClubActor *actor)
{
    actor->updateFn = WIFICLUBACTOR_UpdateBounce;
    actor->animFn = WIFICLUBACTOR_AnimateBounce;
    actor->counter.timer = 28;
    actor->state = 4;
    WIFICLUBACTOR_QueueActorMove(sys, 4, actor);
    WF2DMAP_OBJDRAW_SetActive(actor->sprite, 0);
}


void WIFICLUBACTOR_NoOpAnim(void)
{
}


void WIFICLUBACTOR_AnimateWalkBob(void *sys, WifiClubActor *actor)
{
    TilePos pos;
    TilePos base;
    WF2DMAP_OBJDRAW_RefreshActor(actor->sprite);
    if (WF2DMAP_OBJDRAW_GetActorValue(actor->sprite) == 0) {
        WF2DMAP_OBJDRAW_SetActorValue(actor->sprite, 1);
    }
    pos.x = WF2DMAP_OBJ_GetSlot(actor->entity, 0);
    pos.y = WF2DMAP_OBJ_GetSlot(actor->entity, 1);
    base = pos;
    pos.y = pos.y + (s16)((int)(((long long)GF_STANDARD_Get_F5FC(actor->counter.phase) * -786432 + 0x800) >> 12) >> 12);
    WF2DMAP_OBJDRAW_SetActorPos(actor->sprite, pos);
    WF2DMAP_OBJDRAW_SetActorPos2(actor->sprite, base);
}


void WIFICLUBACTOR_AnimateBounce(void *sys, WifiClubActor *actor)
{
    TilePos pos;
    TilePos base;
    int t;
    pos.x = WF2DMAP_OBJ_GetSlot(actor->entity, 0);
    pos.y = WF2DMAP_OBJ_GetSlot(actor->entity, 1);
    base = pos;
    t = (s16)(actor->counter.timer - 16);
    if (t > 0) {
        pos.y = pos.y - (s16)((int)(((long long)GF_STANDARD_Get_F5FC((u16)(180 * (s16)(t % 6) / 6)) * 16384 + 0x800) >> 12) >> 12);
    }
    WF2DMAP_OBJDRAW_SetActorPos(actor->sprite, pos);
    WF2DMAP_OBJDRAW_SetActorPos2(actor->sprite, base);
    WF2DMAP_OBJDRAW_SetFrameZero(actor->sprite, 1);
}


int WIFICLUBACTOR_UpdatePlayer(WifiClubActorSys *sys, WifiClubActor *actor)
{
    int direction;
    int actorId;
    int speed;
    int keys;

    direction = WF2DMAP_OBJ_GetSlot(actor->entity, 6);
    actorId = WF2DMAP_OBJ_GetSlot(actor->entity, 4);
    if (WF2DMAP_OBJ_GetSlot(actor->entity, 5) != 0) {
        return 0;
    }
    if (sys->mode == 1) {
        return 0;
    }
    keys = KEY_GetCont();
    speed = 2;
    if (keys & 2) {
        speed = 3;
    }
    if (KEY_GetCont() & 0x40) {
        if (direction == 0) {
            WIFICLUBACTOR_QueueMoveCommand(sys, speed, direction, actorId);
        } else {
            WIFICLUBACTOR_QueueMoveCommand(sys, 1, 0, actorId);
        }
    } else if (KEY_GetCont() & 0x80) {
        if (direction == 1) {
            WIFICLUBACTOR_QueueMoveCommand(sys, speed, direction, actorId);
        } else {
            WIFICLUBACTOR_QueueMoveCommand(sys, 1, 1, actorId);
        }
    } else if (KEY_GetCont() & 0x20) {
        if (direction == 2) {
            WIFICLUBACTOR_QueueMoveCommand(sys, speed, direction, actorId);
        } else {
            WIFICLUBACTOR_QueueMoveCommand(sys, 1, 2, actorId);
        }
    } else if (KEY_GetCont() & 0x10) {
        if (direction == 3) {
            WIFICLUBACTOR_QueueMoveCommand(sys, speed, direction, actorId);
        } else {
            WIFICLUBACTOR_QueueMoveCommand(sys, 1, 3, actorId);
        }
    }
    return 0;
}


int WIFICLUBACTOR_UpdateWait(WifiClubActorSys *sys, WifiClubActor *actor)
{
    int selectedId;
    int actorId;
    actor->counter.timer = actor->counter.timer - 1;
    if (actor->counter.timer <= 0) {
        WF2DMAP_OBJDRAW_RestoreFrame(actor->sprite);
        WF2DMAP_OBJDRAW_SetActive(actor->sprite, 1);
        selectedId = WF2DMAP_OBJ_GetSlot(sys->selected->entity, 4);
        actorId = WF2DMAP_OBJ_GetSlot(actor->entity, 4);
        if (actorId == selectedId) {
            WIFICLUBACTOR_SetPlayerState(sys, actor);
        } else {
            WIFICLUBACTOR_ApplyActorMode(sys, actor, actor->savedMode);
        }
    }
    return 0;
}


int WIFICLUBACTOR_UpdateDespawn(WifiClubActorSys *sys, WifiClubActor *actor)
{
    actor->counter.timer = actor->counter.timer + 1;
    if (actor->counter.timer > 0x2d) {
        return 1;
    }
    return 0;
}


int WIFICLUBACTOR_UpdateIdleWander(void *sys, WifiClubActor *actor)
{
    int direction;
    actor->counter.timer = actor->counter.timer - 1;
    if (actor->counter.timer <= 0) {
        actor->counter.timer = GFL_USE_GetRandom(0x400) + 0x100;
        direction = GFL_USE_GetRandom(4);
        WIFICLUBACTOR_QueueMoveCommand(sys, 0, direction, WF2DMAP_OBJ_GetSlot(actor->entity, 4));
    }
    return 0;
}


int WIFICLUBACTOR_UpdateBounce(void *sys, WifiClubActor *actor)
{
    actor->counter.timer = actor->counter.timer - 1;
    if (actor->counter.timer < 0) {
        actor->counter.timer = 0x1c;
    }
    return 0;
}


int WIFICLUBACTOR_UpdateNone(void)
{
    return 0;
}


/* Queues a movement command for an actor. */
void WIFICLUBACTOR_QueueMoveCommand(WifiClubActorSys *sys, int action, int direction, int actorId)
{
    struct {
        u16 action;
        u8 direction;
        u8 actorId;
    } command;

    command.action = action;
    command.direction = direction;
    command.actorId = actorId;
    WF2DMAP_CMDQ_Push(sys->cmdQueue, &command);
}


void WIFICLUBACTOR_QueueActorMove(void *sys, int action, WifiClubActor *actor)
{
    int direction = WF2DMAP_OBJ_GetSlot(actor->entity, 6);
    int actorId = WF2DMAP_OBJ_GetSlot(actor->entity, 4);
    WIFICLUBACTOR_QueueMoveCommand(sys, action, direction, actorId);
}


/* True unless the actor's animation callback is the walk-bob one. */
BOOL WIFICLUBACTOR_IsNotWalkBobbing(WifiClubActor *actor)
{
    if (actor->animFn != WIFICLUBACTOR_AnimateWalkBob) {
        return 1;
    }
    return 0;
}


/* The pair is a switch, not an if/else-if chain: only the switch form lays the
 * case bodies out of line the way the image does. */
void WIFICLUBACTOR_ApplyActorMode(void *sys, WifiClubActor *actor, u8 mode)
{
    switch (mode) {
    case 0:
        WIFICLUBACTOR_SetIdleState(sys, actor);
        break;
    case 1:
        WIFICLUBACTOR_SetBounceState(sys, actor);
        break;
    }
    actor->savedMode = mode;
}


void WIFICLUBACTOR_InitBlink(WifiClubActorSys *sys, WifiClubPaletteBlink *blink, u32 unused, u32 archive)
{
    MI_CpuFill8(blink, 0, 20);
    blink->paletteHandle = ARC_UTIL_LoadPaletteBlockFromArchive(archive, 9, (u32)&blink->paletteData, (u16)sys->heapId);
    blink->frame = 0;
    blink->colorMask = 15;
    blink->frameTimer = d_021C2878[(u8)blink->frame];
}


void WIFICLUBACTOR_ExitBlink(int unused, WifiClubPaletteBlink *blink)
{
    GFL_HEAP_Free(blink->paletteHandle);
    MI_CpuFill8(blink, 0, 0x14);
}


void WIFICLUBACTOR_TickBlinkAll(int unused, WifiClubPaletteBlink *blink)
{
    WIFICLUBACTOR_TickBlinkFrame(blink);
    WIFICLUBACTOR_TickBlinkScript(blink);
}


void WIFICLUBACTOR_TickBlinkFrame(WifiClubPaletteBlink *blink)
{
    int i;
    int frame;

    blink->frameTimer = blink->frameTimer - 1;
    if (blink->frameTimer <= 0) {
        frame = 2;
        blink->frame = (blink->frame + 1) % 2;
        blink->frameTimer = d_021C2878[blink->frame];
        if (blink->frame != 1) {
            frame = 1;
        }
        for (i = 0; i < 4; i++) {
            if (blink->colorMask & (1 << i)) {
                NNS_GfdRegisterNewVramTransferTask((void *)0xf, (i + 1) * 2 + 0xe0, (u32)WIFICLUBACTOR_GetBlinkColors(blink, frame), 2);
            }
        }
    }
}


/* Source order of the table reads (timer, then apply, then frame) decides how
 * the pool loads and the ldrb group come out. */
void WIFICLUBACTOR_TickBlinkScript(WifiClubPaletteBlink *blink)
{
    int apply = 0;
    int frame = 0;
    int stepEnded = 0;

    if (d_021C287C[blink->stepIndex].waitForTimer == 1) {
        blink->stepTimer = blink->stepTimer - 1;
        if (blink->stepTimer <= 0) {
            stepEnded = 1;
        }
    } else if (blink->stepRestart != 0) {
        blink->stepRestart = 0;
        stepEnded = 1;
    }
    if (stepEnded != 0) {
        blink->stepIndex = blink->stepIndex + 1;
        if (blink->stepIndex >= 8) {
            WIFICLUBACTOR_EndBlinkScript(blink);
            return;
        }
        blink->stepTimer = d_021C287C[blink->stepIndex].duration;
        apply = d_021C287C[blink->stepIndex].apply;
        frame = d_021C287C[blink->stepIndex].frame;
    }
    if (apply != 0) {
        NNS_GfdRegisterNewVramTransferTask((void *)0xf, (blink->stepColor + 1) * 2 + 0xe0, (u32)WIFICLUBACTOR_GetBlinkColors(blink, frame), 2);
    }
}


/* Halfword pointer one past index i in the colour table of the palette file.
 * The index is scaled after the +1, which is why the listing is
 * `adds r0, r1, #1; lsls r0, r0, #1`. */
u16 *WIFICLUBACTOR_GetBlinkColors(WifiClubPaletteBlink *blink, int i)
{
    return (u16 *)((u8 *)blink->paletteData->colors + (i + 1) * 2);
}


/* Ends the step script: the colour's mask bit comes back and the script resets. */
void WIFICLUBACTOR_EndBlinkScript(WifiClubPaletteBlink *blink)
{
    blink->colorMask = (u8)(blink->colorMask | (u8)(1 << blink->stepColor));
    blink->stepColor = 0;
    blink->stepIndex = 0;
    blink->stepTimer = 0;
    blink->stepRestart = 0;
}


void WIFICLUBACTOR_RequestBlinkRestart(WifiClubPaletteBlink *blink)
{
    blink->stepRestart = 1;
}


/* Starts the step script on one colour, cutting short a script in progress. */
void WIFICLUBACTOR_StartBlinkScript(WifiClubPaletteBlink *blink, u8 colorIndex)
{
    if (blink->stepIndex != 0) {
        WIFICLUBACTOR_EndBlinkScript(blink);
    }
    blink->stepColor = colorIndex;
    blink->colorMask ^= (u8)(1 << colorIndex);
    WIFICLUBACTOR_RequestBlinkRestart(blink);
}


void WIFICLUBACTOR_RestartBlinkScript(WifiClubPaletteBlink *blink)
{
    if (blink->stepIndex != 0) {
        WIFICLUBACTOR_RequestBlinkRestart(blink);
    }
}


u8 *WIFICLUBACTOR_GetCommandTable(void)
{
    return data_021C28A8;
}


int WIFICLUBACTOR_GetCommandCount(void)
{
    return 9;
}


void WIFICLUBACTOR_AddNetCommands(void *work)
{
    GFL_NET_COMMAND_AddCommandTable(0x0A00, (u32)WIFICLUBACTOR_GetCommandTable(), WIFICLUBACTOR_GetCommandCount(), (u32)work);
}


void WIFICLUBACTOR_RemoveNetCommands(void *unused)
{
    GFL_NET_COMMAND_DeleteCommandTable(0xA00);
}


void WIFICLUBACTOR_NetCallbackA(int a, int b, int c, int d)
{
    if (d != 0) {
        return;
    }
}


void WIFICLUBACTOR_NetCallbackB(int a, int b, int c, int d)
{
    if (d != 0) {
        return;
    }
}


void WIFICLUBACTOR_NetCallbackC(int a, int b, int c, int d)
{
    if (d != 0) {
        return;
    }
}


MapSize WIFICLUBACTOR_GetMapSize(int mapIndex)
{
    return data_021C28F0[mapIndex];
}

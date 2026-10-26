#ifndef GAME_OV099_WIFI_CLUB_ACTOR_H
#define GAME_OV099_WIFI_CLUB_ACTOR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifi_club_actor.c, prototypes copied from their definitions. */

#include "../ov099/wifi_club_actor_types.h"
#include "../types.h"
#include "../arm9/net_types.h"

void WIFICLUBACTOR_Init(WifiClubActorSys *sys, int heapId, void *clactResArc, u32 spriteKind, u32 mapIndexPlusOne, u32 paletteArc, void *clactSys, void *gfxArchive);
void WIFICLUBACTOR_Exit(WifiClubActorSys *sys);
int WIFICLUBACTOR_IsReady(WifiClubActorSys *sys);
u32 WIFICLUBACTOR_Update(WifiClubActorSys *sys);
int WIFICLUBACTOR_UpdatePickRequest(WifiClubActorSys *sys, WifiClubActor *actor);
void WIFICLUBACTOR_UpdatePickRequests(WifiClubActorSys *sys);
u8 WIFICLUBACTOR_GetPickResult(WifiClubActorSys *sys);
int WIFICLUBACTOR_GetCursorTileAttr(WifiClubActorSys *sys);
int WIFICLUBACTOR_GetCursorTileBelowAttr(WifiClubActorSys *sys);
void WIFICLUBACTOR_ShowMarkerAtActor(void *sys, WifiClubActor *actor);
void WIFICLUBACTOR_ResumeActorSprite(void *unused, WifiClubActor *actor);
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
void WIFICLUBACTOR_InitSpriteManager(WifiClubActorSys *sys, u32 spriteKind, u32 heapId);
void WIFICLUBACTOR_ExitSpriteManager(WifiClubActorSys *sys);
void WIFICLUBACTOR_InitLayer(WifiClubActorSys *sys, int heapId, void *unused, int mapIndex);
void WIFICLUBACTOR_ExitLayer(WifiClubActorSys *sys);
void WIFICLUBACTOR_InitSprites(WifiClubSpriteSet *sprites, u32 heapId, void *clactResArc);
void WIFICLUBACTOR_ExitSprites(WifiClubSpriteSet *sprites);
void WIFICLUBACTOR_RegisterResources(WifiClubSpriteSet *sprites, int heapId, void *clactResArc);
void WIFICLUBACTOR_ReleaseResources(WifiClubSpriteSet *sprites);
void WIFICLUBACTOR_CreateCursorActors(WifiClubSpriteSet *sprites, int heapId);
void WIFICLUBACTOR_DeleteCursorActors(WifiClubSpriteSet *sprites);
void WIFICLUBACTOR_NoOpInit(void *unused, int heapId);
void WIFICLUBACTOR_NoOpExit(void *unused);
void WIFICLUBACTOR_LoadPalette(void *unused, u32 heapId, void *clactResArc, u32 paletteArc);
void WIFICLUBACTOR_RegisterClactResources(WifiClubSpriteSet *sprites, int heapId, void *clactResArc);
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
void WIFICLUBACTOR_SetWaitState(void *unused, WifiClubActor *actor);
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
void WIFICLUBACTOR_InitBlink(WifiClubActorSys *sys, WifiClubPaletteBlink *blink, void *unused, u32 archive);
void WIFICLUBACTOR_ExitBlink(void *unused, WifiClubPaletteBlink *blink);
void WIFICLUBACTOR_TickBlinkAll(void *unused, WifiClubPaletteBlink *blink);
void WIFICLUBACTOR_TickBlinkFrame(WifiClubPaletteBlink *blink);
void WIFICLUBACTOR_TickBlinkScript(WifiClubPaletteBlink *blink);
u16 *WIFICLUBACTOR_GetBlinkColors(WifiClubPaletteBlink *blink, int i);
void WIFICLUBACTOR_EndBlinkScript(WifiClubPaletteBlink *blink);
void WIFICLUBACTOR_RequestBlinkRestart(WifiClubPaletteBlink *blink);
void WIFICLUBACTOR_StartBlinkScript(WifiClubPaletteBlink *blink, u8 colorIndex);
void WIFICLUBACTOR_RestartBlinkScript(WifiClubPaletteBlink *blink);
NetCommandEntry *WIFICLUBACTOR_GetCommandTable(void);
int WIFICLUBACTOR_GetCommandCount(void);
void WIFICLUBACTOR_AddNetCommands(void *work);
void WIFICLUBACTOR_RemoveNetCommands(void *unused);
void WIFICLUBACTOR_NetCallbackA(int a, int b, int c, int d);
void WIFICLUBACTOR_NetCallbackB(int a, int b, int c, int d);
void WIFICLUBACTOR_NetCallbackC(int a, int b, int c, int d);
MapSize WIFICLUBACTOR_GetMapSize(int mapIndex);
/* END mkheaders: generated region */

#endif

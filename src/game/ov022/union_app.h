#ifndef GAME_OV022_UNION_APP_H
#define GAME_OV022_UNION_APP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of union_app.c, prototypes copied from their definitions. */

struct GFLNetHandle;

#include "../ov022/union_app_types.h"
#include "../ov012/union_comm_types.h"
#include "../ov022/union_app_types.h"
#include "../types.h"

UnionAppWork *UNION_APP_Create(UnionRoomWork *work, int heapId, int maxMembers, UnionAppStatusCopy *myStatus);
void UNION_APP_Delete(UnionAppWork *app);
int UNION_APP_TryAcceptMember(UnionAppWork *app, int netId);
void UNION_APP_Update(UnionAppWork *app, UnionRoomWork *work);
void UNION_APP_DropDisconnectedMembers(UnionAppWork *app);
void UNION_APP_SendSetting(UnionAppWork *app);
void UNION_APP_SelectQuitRequester(UnionAppWork *app);
void UNION_APP_SendQuitAccept(UnionAppWork *app);
void UNION_APP_SendOwnEntry(UnionAppWork *app);
void UNION_APP_ConfirmJoins(UnionAppWork *app);
void UNION_APP_UpdateLeaves(UnionAppWork *app, UnionRoomWork *work);
void UNION_APP_ClearDisconnectedPending(UnionAppWork *app, UnionRoomWork *work);
void UNION_APP_AddQuitRequest(UnionAppWork *app, u8 netId);
void UNION_APP_SetQuitAccepted(UnionAppWork *app);
u8 UNION_APP_IsQuitAccepted(UnionAppWork *app);
void UNION_APP_AddSettingTarget(UnionAppWork *app, u8 netId);
void UNION_APP_SetSetting(UnionAppWork *app, const void *setting);
void UNION_APP_AddEntryTarget(UnionAppWork *app, u8 netId);
void UNION_APP_SetMemberEntry(UnionAppWork *app, UnionRoomWork *work, u32 netId, const UnionAppEntry *src);
int UNION_APP_HasMembers(UnionAppWork *app);
int UNION_APP_IsAllEntriesReceived(UnionAppWork *app);
void UNION_APP_QueueJoinConfirm(UnionAppWork *app, int netId);
void UNION_APP_OnMemberDropped(UnionAppWork *app, int netId);
unsigned int UNION_APP_GetSettingSize(struct GFLNetHandle *entry);
void UNION_APP_AddSelfToJoined(UnionAppWork *app);
int UNION_APP_IsClosed(UnionAppWork *app);
void UNION_APP_SetCallbacks(UnionAppWork *app, UnionAppMemberCallback joinCallback, UnionAppMemberCallback leaveCallback, void *callbackArg);
int UNION_APP_Close(UnionAppWork *app);
void UNION_APP_Open(UnionAppWork *app);
void UNION_APP_OpenLimited(UnionAppWork *app, int maxCount);
void UNION_APP_SetReady(UnionAppWork *app);
void UNION_APP_RequestReset(UnionAppWork *app);
u32 UNION_APP_IsResetDone(UnionAppWork *app);
UnionAppEntry *UNION_APP_GetMemberEntry(UnionAppWork *app, int netId);
unsigned char UNION_APP_GetJoinedBits(UnionAppWork *app);
int UNION_APP_GetMemberCount(UnionAppWork *app);
/* END mkheaders: generated region */

#endif

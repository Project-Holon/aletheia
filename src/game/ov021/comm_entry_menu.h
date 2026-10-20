#ifndef GAME_OV021_COMM_ENTRY_MENU_H
#define GAME_OV021_COMM_ENTRY_MENU_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of comm_entry_menu.c, prototypes copied from their definitions. */

struct CommEntryMenu;
struct MyStatus;
struct FieldMap;
struct CommEntryMember;
struct CommEntryRoster;
struct CommEntryBeaconData;
struct CommEntryJoinRequest;
typedef struct CommEntryMenu CommEntryMenu;
typedef struct CommEntryMember CommEntryMember;
typedef struct CommEntryRoster CommEntryRoster;
typedef struct CommEntryBeaconData CommEntryBeaconData;
typedef struct CommEntryJoinRequest CommEntryJoinRequest;

#include "../types.h"
#include "../ov021/comm_entry_menu_types.h"
#include "../ov021/comm_entry_menu_types.h"

CommEntryMenu *COMM_ENTRY_MENU_Create(struct MyStatus *myStatus, struct FieldMap *fieldMap, u32 minMembers, u32 maxMembers, u32 heapId, u32 menuMode, u32 isChild, const u8 *mac);
u32 COMM_ENTRY_MENU_Delete(CommEntryMenu *menu);
void COMM_ENTRY_MENU_SetCallbacks(CommEntryMenu *menu, void *work, CommEntryMemberFunc onAdd, CommEntryMemberFunc onRemove);
void COMM_ENTRY_MENU_AddMember(CommEntryMenu *menu, int netId, const void *myStatus, u32 autoAccept, const u8 *mac);
u32 COMM_ENTRY_MENU_Main(CommEntryMenu *menu);
int COMM_ENTRY_MENU_MainRecruit(CommEntryMenu *menu);
int COMM_ENTRY_MENU_MainMode1(CommEntryMenu *menu);
int COMM_ENTRY_MENU_MainMode2(CommEntryMenu *menu);
int COMM_ENTRY_MENU_MainMode3(CommEntryMenu *menu);
void COMM_ENTRY_MENU_ProcessMemberQueues(CommEntryMenu *menu);
u8 COMM_ENTRY_MENU_CollectMemberNames(CommEntryMenu *menu);
void COMM_ENTRY_MENU_CheckDisconnects(CommEntryMenu *menu);
void COMM_ENTRY_MENU_UpdateMemberList(CommEntryMenu *menu);
void COMM_ENTRY_MENU_AdvanceMemberStates(CommEntryMenu *menu);
void COMM_ENTRY_MENU_ClearMember(CommEntryMenu *menu, int index);
int COMM_ENTRY_MENU_LatchRequest(CommEntryMenu *menu, CommEntryMember *member);
void COMM_ENTRY_MENU_ProcessRequest(CommEntryMenu *menu);
int COMM_ENTRY_MENU_ProcessCancel(CommEntryMenu *menu);
u32 COMM_ENTRY_MENU_ProcessStartConfirm(CommEntryMenu *menu);
void COMM_ENTRY_MENU_MarkMemberReady(CommEntryMenu *menu, int netId);
void COMM_ENTRY_MENU_SetAcceptFlag(CommEntryMenu *menu);
void COMM_ENTRY_MENU_SetCancelFlag(CommEntryMenu *menu);
void COMM_ENTRY_MENU_SetBusyFlags(CommEntryMenu *menu);
int COMM_ENTRY_MENU_CountAcceptedMembers(CommEntryMenu *menu);
u32 COMM_ENTRY_MENU_GetAcceptedMask(CommEntryMenu *menu);
int COMM_ENTRY_MENU_IsIdle(CommEntryMenu *menu);
void COMM_ENTRY_MENU_OpenWindows(CommEntryMenu *menu);
void COMM_ENTRY_MENU_CloseWindows(CommEntryMenu *menu);
int COMM_ENTRY_MENU_PrintRemaining(CommEntryMenu *menu, int count);
void COMM_ENTRY_MENU_UpdateMemberName(CommEntryMenu *menu, CommEntryMember *member, int index);
void COMM_ENTRY_MENU_ClearMemberName(CommEntryMenu *menu, CommEntryMember *member, int index);
void COMM_ENTRY_MENU_PrintMemberName(CommEntryMenu *menu, const void *myStatus, u32 row);
void COMM_ENTRY_MENU_EraseMemberName(CommEntryMenu *menu, u32 row);
void COMM_ENTRY_MENU_RefreshNames(CommEntryMenu *menu);
void COMM_ENTRY_MENU_PrintMessage(CommEntryMenu *menu, u32 msgId);
void COMM_ENTRY_MENU_SnapshotStates(CommEntryMenu *menu);
int COMM_ENTRY_MENU_StatesUnchanged(CommEntryMenu *menu);
void COMM_ENTRY_MENU_ClearPendingBits(CommEntryMenu *menu, int index);
void COMM_ENTRY_MENU_QueueSend(CommEntryMenu *menu);
CommEntryMenu *COMM_ENTRY_MENU_AckSend(CommEntryMenu *menu);
CommEntryRoster *COMM_ENTRY_MENU_GetNameBuffer(CommEntryMenu *menu);
void COMM_ENTRY_MENU_SetNameBuffer(CommEntryMenu *menu, const CommEntryRoster *roster);
void COMM_ENTRY_MENU_StartYesNo(CommEntryMenu *menu);
void COMM_ENTRY_MENU_EndYesNo(CommEntryMenu *menu);
u32 COMM_ENTRY_MENU_MainYesNo(CommEntryMenu *menu);
int COMM_ENTRY_PollParentList(CommEntryMenu *menu);
void COMM_ENTRY_TickParentTimeouts(CommEntryMenu *menu);
void COMM_ENTRY_ScanParents(CommEntryMenu *menu);
void COMM_ENTRY_AddParent(CommEntryMenu *menu, u8 *mac, CommEntryBeaconData *beacon);
void COMM_ENTRY_ClearParentSlot(CommEntryMenu *menu, int slotIndex);
void COMM_ENTRY_BuildParentItems(CommEntryMenu *menu);
int COMM_ENTRY_RunLeaveConfirm(CommEntryMenu *menu);
void COMM_ENTRY_ResetLeaveConfirm(CommEntryMenu *menu);
void COMM_ENTRY_StoreJoinReply(CommEntryMenu *menu, u32 reply, const void *parentMyStatus);
u32 COMM_ENTRY_GetRosterSize(void);
int COMM_ENTRY_IsOtherMemberConnected(int mask);
void COMM_ENTRY_StartNetCommands(CommEntryMenu *menu);
void COMM_ENTRY_EndNetCommands(void);
CommEntryRoster *COMM_ENTRY_GetRosterBuffer(u32 netId, CommEntryMenu *menu);
void COMM_ENTRY_RecvJoinRequest(u32 netId, u32 size, CommEntryJoinRequest *request, CommEntryMenu *menu);
u32 COMM_ENTRY_SendJoinRequest(const void *myStatus, u32 isChild, u32 netMode);
void COMM_ENTRY_RecvJoinAccept(u32 netId, u32 size, const void *parentMyStatus, CommEntryMenu *menu);
u32 COMM_ENTRY_SendJoinAccept(u32 index, u32 netMode, const void *myStatus);
void COMM_ENTRY_RecvJoinRedirect(u32 netId, u32 size, const void *parentMyStatus, CommEntryMenu *menu);
u32 COMM_ENTRY_SendJoinRedirect(u32 index, u32 netMode, const void *myStatus);
void COMM_ENTRY_RecvSessionLock(u32 netId, u32 size, const void *data, CommEntryMenu *menu);
int COMM_ENTRY_SendSessionLock(int netMode);
void COMM_ENTRY_RecvReady(u32 netId, u32 size, const void *data, CommEntryMenu *menu);
u32 COMM_ENTRY_SendReady(u32 netMode);
void COMM_ENTRY_RecvAccept(u32 netId, u32 size, const void *data, CommEntryMenu *menu);
int COMM_ENTRY_SendAccept(int netMode);
void COMM_ENTRY_RecvCancel(u32 netId, u32 size, const void *data, CommEntryMenu *menu);
int COMM_ENTRY_SendCancel(int netMode);
void COMM_ENTRY_RecvRoster(u32 netId, u32 size, const CommEntryRoster *roster, CommEntryMenu *menu);
u32 COMM_ENTRY_SendRoster(const CommEntryRoster *roster, u32 recipients, int netMode);
/* END mkheaders: generated region */

#endif

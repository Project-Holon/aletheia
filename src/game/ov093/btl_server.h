#ifndef GAME_OV093_BTL_SERVER_H
#define GAME_OV093_BTL_SERVER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_server.c, prototypes copied from their definitions. */

struct BtlMain;
struct BtlClientSet;

#include "../ov093/btl_server_types.h"
#include "../ov093/btl_calc_types.h"
#include "../types.h"

BtlServer *BTL_SERVER_Create(struct BtlMain *main, BtlRngState *rngState, void *partyTable, int flowParam, u16 heapId);
void BTL_SERVER_SetClientAdapter(BtlServer *server, void *adapter, u8 clientId, u8 battleSlots);
void BTL_SERVER_CreateClientAdapter(BtlServer *server, int unused, struct GFLNetHandle *netId, int clientId, u8 battleSlots);
void BTL_SERVER_SetClientWithoutAdapter(BtlServer *server, u8 clientId, u8 battleSlots);
void BTL_SERVER_Restart(BtlServer *server);
void BTL_SERVER_Delete(BtlServer *server);
int BTL_SERVER_Update(BtlServer *server);
void BTL_SERVER_GetFinalData(BtlServer *server, struct BtlClientSet *out);
void BTL_SERVER_SetHandler(BtlServer *server, BtlServerHandler handler);
void BTL_SERVER_GotoSelectCommands(BtlServer *server);
int BTL_SERVER_StepStart(BtlServer *server, int *step);
int BTL_SERVER_StepSelectCommands(BtlServer *server, int *step);
int BTL_SERVER_GetRecordInitArg(BtlServer *server);
int BTL_SERVER_StepShiftPrompt(BtlServer *server, int *step);
int BTL_SERVER_StepRequestPokeChange(BtlServer *server, int *step);
int BTL_SERVER_CheckShiftPromptNeeded(BtlServer *server);
u32 BTL_SERVER_GetShiftPromptMon(BtlServer *server);
int BTL_SERVER_StepRequestPokeReplace(BtlServer *server, int *step);
int BTL_SERVER_StepSendRecording(BtlServer *server, int *step);
int BTL_SERVER_StepSelectEnding(BtlServer *server, int *step);
int BTL_SERVER_StepWaitEnd(BtlServer *server, int *step);
int BTL_SERVER_StepSendWildWin(BtlServer *server, int *step);
int BTL_SERVER_StepSendWildLoseOrDraw(BtlServer *server, int *step);
int BTL_SERVER_StepSendCommResult(BtlServer *server, int *step);
int BTL_SERVER_StepSendTrainerResult(BtlServer *server, int *step);
int BTL_SERVER_StepSendSubwayResult(BtlServer *server, int *step);
void BTL_SERVER_LoadRecorderReplies(BtlServer *server, void *src, int size);
void BTL_SERVER_NoOp(void *reply);
int BTL_SERVER_CompareFlowOutput(BtlServer *server, int stage, void *expected, u32 size);
int BTL_SERVER_SendSkipPacket(BtlServer *server, int skipFlags);
int BTL_SERVER_SendActionPacket(BtlServer *server, int stage, int initArg);
void *BTL_SERVER_BuildActionPacket(BtlServer *server, int stage, int initArg, unsigned int *outSize);
void BTL_SERVER_CollectReplies(BtlServer *server);
void BTL_SERVER_SendCommand(BtlServer *server, int command);
void BTL_SERVER_SendCommandData(BtlServer *server, int command, const void *data, int size);
void BTL_SERVER_SendCommandDataToClient(BtlServer *server, int command, u32 clientIndex, const void *data, int size);
int BTL_SERVER_AreRepliesReady(BtlServer *server);
void BTL_SERVER_ClearReplies(const BtlServer *server);
void BTL_SERVER_ResetClientCommands(const BtlServer *server);
void BTL_SERVER_ClearClient(BtlServerClient *client);
int BTL_SERVER_IsClientSlotUsed(const BtlServerClient *client);
void BTL_SERVER_SetClientAdapterSlot(BtlServerClient *client, int clientId, void *adapter, int adapterBorrowed);
void BTL_SERVER_SetClientParty(BtlServerClient *client, void *party, u8 battleSlots);
BtlServerClient *BTL_SERVER_GetClientChecked(BtlServer *server, unsigned int index);
BtlServerClient *BTL_SERVER_GetClientIfUsed(BtlServer *server, u32 index);
int BTL_SERVER_IsClientUsed(BtlServer *server, u8 index);
u8 BTL_SERVER_GetActionTableValue(BtlServerActionTable *table, u8 index);
union BtlAction BTL_SERVER_GetActionTableEntry(BtlServerActionTable *table, u8 row, u8 column);
void BTL_SERVER_NotifyLevelUp(BtlServer *server, u32 *pokeParam);
void BTL_SERVER_NotifyCapture(BtlServer *server, u32 *pokeParam);
void BTL_SERVER_AddMainCounter(BtlServer *server, int amount);
void BTL_SERVER_FinishMainCounter(BtlServer *server);
void BTL_SERVER_ClearPokeChangeRequests(BtlServer *server);
void BTL_SERVER_AddPokeChangeRequest(BtlServer *server, u32 clientId);
void *BTL_SERVER_GetFlow(BtlServer *server);
/* END mkheaders: generated region */

#endif

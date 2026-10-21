/*
 * file:     btl_server.c
 * unit:     yes
 * function: BTL_SERVER_Create, BTL_SERVER_SetClientAdapter, BTL_SERVER_CreateClientAdapter, BTL_SERVER_SetClientWithoutAdapter, BTL_SERVER_Restart, BTL_SERVER_Delete, BTL_SERVER_Update, BTL_SERVER_GetFinalData, BTL_SERVER_SetHandler, BTL_SERVER_GotoSelectCommands, BTL_SERVER_StepStart, BTL_SERVER_StepSelectCommands, BTL_SERVER_GetRecordInitArg, BTL_SERVER_StepShiftPrompt, BTL_SERVER_StepRequestPokeChange, BTL_SERVER_CheckShiftPromptNeeded, BTL_SERVER_GetShiftPromptMon, BTL_SERVER_StepRequestPokeReplace, BTL_SERVER_StepSendRecording, BTL_SERVER_StepSelectEnding, BTL_SERVER_StepWaitEnd, BTL_SERVER_StepSendWildWin, BTL_SERVER_StepSendWildLoseOrDraw, BTL_SERVER_StepSendCommResult, BTL_SERVER_StepSendTrainerResult, BTL_SERVER_StepSendSubwayResult, BTL_SERVER_LoadRecorderReplies, BTL_SERVER_NoOp, BTL_SERVER_CompareFlowOutput, BTL_SERVER_SendSkipPacket, BTL_SERVER_SendActionPacket, BTL_SERVER_BuildActionPacket, BTL_SERVER_CollectReplies, BTL_SERVER_SendCommand, BTL_SERVER_SendCommandData, BTL_SERVER_SendCommandDataToClient, BTL_SERVER_AreRepliesReady, BTL_SERVER_ClearReplies, BTL_SERVER_ResetClientCommands, BTL_SERVER_ClearClient, BTL_SERVER_IsClientSlotUsed, BTL_SERVER_SetClientAdapterSlot, BTL_SERVER_SetClientParty, BTL_SERVER_GetClientChecked, BTL_SERVER_GetClientIfUsed, BTL_SERVER_IsClientUsed, BTL_SERVER_GetActionTableValue, BTL_SERVER_GetActionTableEntry, BTL_SERVER_NotifyLevelUp, BTL_SERVER_NotifyCapture, BTL_SERVER_AddMainCounter, BTL_SERVER_FinishMainCounter, BTL_SERVER_ClearPokeChangeRequests, BTL_SERVER_AddPokeChangeRequest, BTL_SERVER_GetFlow
 * address:  0x021BA9C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from btl_server.c (lane L189): __FILE__ anchor 021BAA8C (gBtlServerFileName "btl_server.c") used by the 0xcc4-byte BtlServer constructor 021BA9C8, which is the first function of the file.
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   GFL_HEAP_Free  0x020307B0  arm
 *   STRBUF_Create  0x020457B0  arm
 *   BTL_CALC_SetRngState  0x021D787C  thumb  ov093
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   gBtlServerFileName 0x021F3A60 data a4
 *   BTL_ADAPTER_Create  0x021EEA58  thumb  ov093
 *   STRBUF_Delete  0x02045808  arm
 *   BTL_ADAPTER_Delete  0x021EEAE0  thumb  ov093
 *   BTL_MAIN_GetCommPos 0x021B86C0 thumb ov093
 *   BTL_ADAPTER_GetSendBuffer  0x021EEB64  thumb  ov093
 *   BTL_MAIN_CheckShiftModePrompt  0x021B85A8  thumb  ov093
 *   BTL_ACTION_GetKind  0x021D8454  thumb  ov093
 *   BTL_REC_MakeResetPacket  0x021EE9A4  thumb  ov093
 *   BTL_MAIN_GetWinBgm  0x021B86DC  thumb  ov093
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   BTL_REC_LoadPacket  0x021EE9B4  thumb  ov093
 *   BTL_REC_NextRecord  0x021EE9E4  thumb  ov093
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   BTL_REC_InitPacket 0x021EE8B4 thumb ov093
 *   BTL_REC_MakeSkipPacket 0x021EE8D8 thumb ov093
 *   BTL_REC_AddRecord  0x021EE8F4  thumb  ov093
 *   BTL_REC_FinishPacket  0x021EE96C  thumb  ov093
 *   BTL_ADAPTER_NotifyNet  0x021EEAE8  thumb  ov093
 *   BTL_ADAPTER_SetSendData  0x021EEB00  thumb  ov093
 *   BTL_ADAPTER_Idle  0x021EEAFC  thumb  ov093
 *   BTL_ADAPTER_Cancel 0x021EEB70 thumb ov093
 *   BTL_ADAPTER_Update 0x021EEB2C thumb ov093
 *   BTL_ADAPTER_ResetCommand 0x021EEAD0 thumb ov093
 *   GAME_BEACON_SetPokeLevelUp 0x02027268 thumb
 *   GAME_BEACON_SetPokeCapture 0x020271DC thumb
 *   BTL_MAIN_GetSlotClientIdThunk  0x021B8DE4  thumb  ov093
 *   BTL_MAIN_GetOwnClientId  0x021B8FF4  thumb  ov093
 *   BTL_MAIN_GetOwnsSlots  0x021B9114  thumb  ov093
 *   BTL_MAIN_StoreSlotNthResult  0x021B9120  thumb  ov093
 *   BTL_MAIN_SetOutcomeIfUnset  0x021B916C  thumb  ov093
 *   BTL_MAIN_JudgeResultThunk  0x021B917C  thumb  ov093
 *   BTL_MAIN_AddBonusMoney  0x021B91E4  thumb  ov093
 *   BTL_MAIN_SetDoubleMoney  0x021B9234  thumb  ov093
 *   BTL_SIDE_GetClientPoke  0x021B9920  thumb  ov093
 *   BTL_SIDE_GetSlotOfClient  0x021B9AEC  thumb  ov093
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_SLOT_CountLiving  0x021B9B98  thumb  ov093
 *   BTL_MAIN_TrainerRecordAdd  0x021BA1B4  thumb  ov093
 *   BTL_MAIN_IsOwnWindowWaiting  0x021BA5D8  thumb  ov093
 *   BTL_MAIN_CheckOwnWindowDone  0x021BA618  thumb  ov093
 *   BTL_SERVER_FLOW_Create  0x021BB968  thumb  ov093
 *   BTL_SERVER_FLOW_Reset  0x021BB9D0  thumb  ov093
 *   BTL_SERVER_FLOW_Destroy  0x021BBB48  thumb  ov093
 *   BTL_SERVER_FLOW_RunBattleStart  0x021BBB60  thumb  ov093
 *   BTL_SERVER_FLOW_ResetInitState  0x021BBC34  thumb  ov093
 *   BTL_SERVER_FLOW_StartTurn  0x021BBC44  thumb  ov093
 *   BTL_SERVER_FLOW_ResetInitStateAfterSelect  0x021BBD20  thumb  ov093
 *   BTL_SERVER_FLOW_StartAfterPokeSelect  0x021BBD2C  thumb  ov093
 *   BTL_SERVER_FLOW_ResetInitStateAfterChange  0x021BBD80  thumb  ov093
 *   BTL_SERVER_FLOW_StartAfterPokeChange  0x021BBD8C  thumb  ov093
 *   BTL_SERVER_FLOW_RunEscapeFromLead  0x021BC360  thumb  ov093
 *   BTL_SERVER_FLOW_RunBagModeSetup  0x021BC390  thumb  ov093
 *   BTL_SERVER_FLOW_GetSlotTable  0x021BC550  thumb  ov093
 *   BTL_SERVER_FLOW_GetChosenSlot  0x021BC55C  thumb  ov093
 *   BTL_SERVER_FLOW_GetBattleResult  0x021C84D8  thumb  ov093
 */
#include "btl_server_types.h"

struct BtlMain;
#include "btl_main.h"
struct BtlPokeParam;
struct PokemonParam;
#include "../arm9/poke_tool.h"
/* The callers pass a 16 bit heap id; the shared header takes 32 bits and adds a conversion. */
struct Strbuf;
#include "../arm9/strbuf.h"
#include "btl_calc.h"
struct BtlAdapter;
union BtlAction;
#include "btl_action_word.h"
#include "../arm9/gfl_use.h"
#include "../arm9/key.h"
#include "../arm9/touchpanel.h"
#include "../arm9/gf_standard.h"
#include "../arm9/game_beacon.h"
#include "btl_pokeparam.h"
/* The original declares GFL_HEAP_Alloc with a 16-bit heap id; the definition takes a u32. */
#ifdef __MWERKS__
#define GFL_HEAP_Alloc GFL_HEAP_AllocHeader
#endif
#include "../arm9/gfl_heap_wrap.h"
#ifdef __MWERKS__
#undef GFL_HEAP_Alloc
extern void *GFL_HEAP_Alloc(u16, unsigned int, int, const char *, u16);
#endif
#ifdef __MWERKS__
/* The original callers pass the stage and the command as plain ints; the headers declare u8 and u16. */
#define BTL_REC_FinishPacket BTL_REC_FinishPacketHeader
#define BTL_ADAPTER_SetSendData BTL_ADAPTER_SetSendDataHeader
#endif
#include "btl_adapter.h"
#include "btl_rec.h"
#include "btl_server_flow.h"
#ifdef __MWERKS__
#undef BTL_REC_FinishPacket
#undef BTL_ADAPTER_SetSendData
extern void *BTL_REC_FinishPacket(BtlRecPacket *recorder, int stage, unsigned int *outSize);
extern void BTL_ADAPTER_SetSendData(BtlAdapter *adapter, int command, const void *data, int size);
#endif
#include "btl_server.h"
struct BtlSide;
struct BtlSideSlot;
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
void BTL_SERVER_ClearClient(BtlServerClient *client);
void BTL_SERVER_SetClientAdapterSlot(BtlServerClient *client, int clientId, void *adapter, int adapterBorrowed);
union BtlAction BTL_SERVER_GetActionTableEntry(BtlServerActionTable *table, u8 row, u8 column);
void BTL_SERVER_AddMainCounter(BtlServer *server, int amount);
void BTL_SERVER_FinishMainCounter(BtlServer *server);
void BTL_SERVER_AddPokeChangeRequest(BtlServer *server, u32 clientId);
struct BtlServerFlow;
extern u8 gBtlServerFileName[];


BtlServer *BTL_SERVER_Create(struct BtlMain *main, BtlRngState *rngState, void *partyTable, int flowParam, u16 heapId)
{
    BtlServer *server;
    int i;
    server = GFL_HEAP_Alloc(heapId, 0xcc4, 1, (const char *)gBtlServerFileName, 0xad);
    server->main = main;
    server->partyTable = partyTable;
    server->heapId = heapId;
    server->sendBuf = server->sendBufStorage;
    server->quitState = 0;
    server->flow = 0;
    server->changeCount = 0;
    server->changeLock = 0;
    server->flowParam = flowParam;
    server->rngState = *rngState;
    server->nameBuf = STRBUF_Create(0x20, heapId);
    BTL_CALC_SetRngState(rngState);
    for (i = 0; i < 4; i++)
        BTL_SERVER_ClearClient(&server->clients[i]);
    server->flow = BTL_SERVER_FLOW_Create(server, server->main, server->partyTable, server->sendBufStorage, server->flowParam, server->heapId);
    server->finalData = BTL_SERVER_FLOW_GetSlotTable(server->flow);
    BTL_SERVER_SetHandler(server, BTL_SERVER_StepStart);
    return server;
}

void BTL_SERVER_SetClientAdapter(BtlServer *server, void *adapter, u8 clientId, u8 battleSlots)
{
    void *party;
    BtlServerClient *client;
    party = BTL_SIDE_GetSlotOfClient(server->partyTable, clientId);
    client = &server->clients[clientId];
    BTL_SERVER_SetClientAdapterSlot(client, clientId, adapter, 1);
    BTL_SERVER_SetClientParty(client, party, battleSlots);
}

void BTL_SERVER_CreateClientAdapter(BtlServer *server, int unused, struct GFLNetHandle *netId, int clientId, u8 battleSlots)
{
    void *party;
    void *adapter;
    BtlServerClient *client;

    party = BTL_SIDE_GetSlotOfClient(server->partyTable, clientId);
    adapter = BTL_ADAPTER_Create(netId, clientId, 1, server->heapId);
    client = &server->clients[clientId];
    BTL_SERVER_SetClientAdapterSlot(client, clientId, adapter, 0);
    BTL_SERVER_SetClientParty(client, party, battleSlots);
}

void BTL_SERVER_SetClientWithoutAdapter(BtlServer *server, u8 clientId, u8 battleSlots)
{
    void *party;
    BtlServerClient *client;
    party = BTL_SIDE_GetSlotOfClient(server->partyTable, clientId);
    client = &server->clients[clientId];
    BTL_SERVER_SetClientAdapterSlot(client, clientId, 0, 0);
    BTL_SERVER_SetClientParty(client, party, battleSlots);
}

void BTL_SERVER_Restart(BtlServer *server)
{
    BTL_SERVER_SetHandler(server, BTL_SERVER_StepStart);
    BTL_SERVER_ResetClientCommands(server);
    BTL_SERVER_FLOW_Reset(server->flow);
}

void BTL_SERVER_Delete(BtlServer *server)
{
    int i;
    STRBUF_Delete(server->nameBuf);
    BTL_SERVER_FLOW_Destroy(server->flow);
    for (i = 0; i < 4; i++) {
        if (server->clients[i].clientId != 0xff && server->clients[i].adapter != 0 && server->clients[i].adapterBorrowed == 0)
            BTL_ADAPTER_Delete(server->clients[i].adapter);
    }
    GFL_HEAP_Free(server);
}

int BTL_SERVER_Update(BtlServer *server)
{
    if (server->quitState != 2) {
        BtlServerHandler handler = server->handler;
        if (handler(server, &server->step) != 0) {
            BTL_SERVER_SendCommandData(server, 9, server->finalData, 8);
            server->quitState = 2;
        }
    } else {
        if (BTL_SERVER_AreRepliesReady(server) != 0)
            return 1;
    }
    return 0;
}

void BTL_SERVER_GetFinalData(BtlServer *server, struct BtlClientSet *out)
{
    *out = *server->finalData;
}

void BTL_SERVER_SetHandler(BtlServer *server, BtlServerHandler handler)
{
    server->handler = handler;
    server->step = 0;
}

void BTL_SERVER_GotoSelectCommands(BtlServer *server)
{
    BTL_SERVER_SetHandler(server, BTL_SERVER_StepSelectCommands);
}

int BTL_SERVER_StepStart(BtlServer *server, int *step)
{
    int *buf;

    switch (*step) {
    case 0:
        BTL_SERVER_SendCommand(server, 1);
        (*step)++;
    case 1:
        if (BTL_SERVER_AreRepliesReady(server)) {
            BTL_SERVER_ClearReplies(server);
            if (BTL_MAIN_GetCompetitor(server->main) != 4) {
                BTL_SERVER_SendSkipPacket(server, BTL_SERVER_FLOW_RunBattleStart(server->flow));
                (*step)++;
            } else {
                BTL_SERVER_SetHandler(server, BTL_SERVER_StepSelectEnding);
            }
        }
        break;
    case 2:
        if (BTL_SERVER_AreRepliesReady(server)) {
            BTL_SERVER_ClearReplies(server);
            (*step)++;
        }
        break;
    case 3:
        buf = server->sendBuf;
        BTL_SERVER_SendCommandData(server, 8, buf + 2, *buf);
        (*step)++;
        break;
    case 4:
        if (BTL_SERVER_AreRepliesReady(server)) {
            BTL_SERVER_ClearReplies(server);
            BTL_SERVER_GotoSelectCommands(server);
        }
        break;
    }
    return 0;
}

/*
 * Contains the lead callback and its trailing return-one stub.
 * The fifth pool word is BTL_SERVER_StepRequestPokeReplace, the distinct case-1 callback;
 * reusing BTL_SERVER_StepRequestPokeChange there shortens the pool and cross-jumps the calls.
 */
int BTL_SERVER_StepSelectCommands(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        if (BTL_SERVER_FLOW_RunBagModeSetup(server->flow)) {
            int *buf = server->sendBuf;
            BTL_SERVER_SendCommandData(server, 8, buf + 2, *buf);
            (*step)++;
        } else
            *step += 2;
        break;
    case 1:
        if (BTL_SERVER_AreRepliesReady(server)) {
            BTL_SERVER_ClearReplies(server);
            (*step)++;
        }
        break;
    case 2:
        BTL_SERVER_SendCommand(server, 3);
        (*step)++;
        break;
    case 3:
        if (BTL_SERVER_AreRepliesReady(server)) {
            BTL_SERVER_ClearReplies(server);
            if (BTL_MAIN_IsOwnWindowWaiting(server->main)) {
                BTL_SERVER_SetHandler(server, BTL_SERVER_StepSendRecording);
                break;
            }
            if (BTL_MAIN_CheckOwnWindowDone(server->main)) {
                BTL_SERVER_SetHandler(server, BTL_SERVER_StepSelectEnding);
                break;
            }
            BTL_SERVER_CollectReplies(server);
            if (BTL_SERVER_SendActionPacket(server, 1, BTL_SERVER_GetRecordInitArg(server)))
                (*step)++;
            else
                *step += 2;
        }
        break;
    case 4:
        if (BTL_SERVER_AreRepliesReady(server)) {
            BTL_SERVER_ClearReplies(server);
            (*step)++;
        }
        break;
    case 5:
        BTL_SERVER_FLOW_ResetInitState(server->flow);
        BTL_SERVER_ClearReplies(server);
        (*step)++;
    case 6:
        server->flowResult = BTL_SERVER_FLOW_StartTurn(server->flow, &server->replies);
        if (BTL_MAIN_GetCommPos(server->main))
            BTL_SERVER_NoOp(&server->replies);
        {
            int *buf = server->sendBuf;
            BTL_SERVER_SendCommandData(server, 8, buf + 2, *buf);
        }
        (*step)++;
        break;
    case 7:
        if (BTL_SERVER_AreRepliesReady(server)) {
            BTL_SERVER_ClearReplies(server);
            switch (server->flowResult) {
            case 0:
                BTL_SERVER_GotoSelectCommands(server);
                break;
            case 3:
                *step = 6;
                break;
            case 2:
                {
                    int competitor = BTL_MAIN_GetCompetitor(server->main);
                    u32 rule = BTL_MAIN_GetRule(server->main);
                    if (!competitor && !rule)
                        BTL_SERVER_SetHandler(server, BTL_SERVER_StepShiftPrompt);
                    else
                        BTL_SERVER_SetHandler(server, BTL_SERVER_StepRequestPokeChange);
                }
                break;
            case 1:
                BTL_SERVER_SetHandler(server, BTL_SERVER_StepRequestPokeReplace);
                break;
            case 6:
                BTL_MAIN_StoreSlotNthResult(server->main, BTL_SERVER_FLOW_GetChosenSlot(server->flow));
                BTL_SERVER_SetHandler(server, BTL_SERVER_StepSelectEnding);
                return 0;
            case 4:
                BTL_MAIN_SetOutcomeIfUnset(server->main, BTL_SERVER_FLOW_GetBattleResult(server->flow));
                BTL_SERVER_SetHandler(server, BTL_SERVER_StepSelectEnding);
                return 0;
            case 5:
            default:
                return 1;
            }
        }
        break;
    }
    return 0;
}

int BTL_SERVER_GetRecordInitArg(BtlServer *server)
{
    return 1;
}

int BTL_SERVER_StepShiftPrompt(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        BTL_SERVER_SendCommand(server, 7);
        (*step)++;
        break;
    case 1:
        if (BTL_SERVER_AreRepliesReady(server) != 0) {
            u8 clientId = BTL_MAIN_GetOwnClientId(server->main);
            int *buf;
            BTL_SERVER_ClearReplies(server);
            if (*(u8 *)BTL_ADAPTER_GetSendBuffer(server->clients[clientId].adapter, 0) == 0) {
                BTL_SERVER_SetHandler(server, BTL_SERVER_StepRequestPokeChange);
            } else {
                server->flowResult = BTL_SERVER_FLOW_RunEscapeFromLead(server->flow);
                buf = server->sendBuf;
                BTL_SERVER_SendCommandData(server, 8, buf + 2, *buf);
                (*step)++;
            }
        }
        break;
    case 2:
        if (BTL_SERVER_AreRepliesReady(server) != 0) {
            BTL_SERVER_ClearReplies(server);
            if (server->flowResult != 0)
                return 1;
            BTL_SERVER_SetHandler(server, BTL_SERVER_StepRequestPokeChange);
        }
        break;
    }
    return 0;
}

/*
 * Case 4 falls through into case 5; the two entry points prevent the
 * field-address setup from moving above the state increment.
 */
int BTL_SERVER_StepRequestPokeChange(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        BTL_SERVER_SendCommandData(server, 5, server->changeClients, server->changeCount);
        (*step)++;
        break;
    case 1:
        if (BTL_SERVER_AreRepliesReady(server)) {
            if (BTL_SERVER_CheckShiftPromptNeeded(server)) {
                server->shiftPromptMon = BTL_SERVER_GetShiftPromptMon(server);
                BTL_SERVER_SendCommandDataToClient(server, 4, 0, &server->shiftPromptMon, 1);
            }
            (*step)++;
        }
        break;
    case 2:
        if (BTL_SERVER_AreRepliesReady(server)) {
            BTL_SERVER_ClearReplies(server);
            if (BTL_MAIN_CheckOwnWindowDone(server->main)) {
                BTL_SERVER_SetHandler(server, BTL_SERVER_StepSelectEnding);
                break;
            }
            BTL_SERVER_CollectReplies(server);
            if (BTL_SERVER_SendActionPacket(server, 2, 0))
                (*step)++;
            else
                *step += 2;
        }
        break;
    case 3:
        if (BTL_SERVER_AreRepliesReady(server)) {
            BTL_SERVER_ClearReplies(server);
            (*step)++;
        }
        break;
    case 4:
        BTL_SERVER_ClearReplies(server);
        BTL_SERVER_FLOW_ResetInitStateAfterChange(server->flow);
        (*step)++;
    case 5:
        server->flowResult = BTL_SERVER_FLOW_StartAfterPokeChange(server->flow, &server->replies);
        {
            int *buf = server->sendBuf;
            BTL_SERVER_SendCommandData(server, 8, buf + 2, *buf);
        }
        (*step)++;
        break;
    case 6:
        if (BTL_SERVER_AreRepliesReady(server)) {
            BTL_SERVER_ClearReplies(server);
            switch (server->flowResult) {
            case 2:
                *step = 0;
                break;
            case 3:
                *step = 5;
                break;
            case 4:
                BTL_MAIN_SetOutcomeIfUnset(server->main, BTL_SERVER_FLOW_GetBattleResult(server->flow));
                BTL_SERVER_SetHandler(server, BTL_SERVER_StepSelectEnding);
                break;
            case 5:
                return 1;
            default:
                BTL_SERVER_GotoSelectCommands(server);
                break;
            }
        }
        break;
    }
    return 0;
}

int BTL_SERVER_CheckShiftPromptNeeded(BtlServer *server)
{
    unsigned i;
    if (BTL_MAIN_CheckShiftModePrompt(server->main) != 0 && server->changeCount != 0) {
        for (i = 0; i < server->changeCount; i++) {
            if (BTL_MAIN_GetSlotClientIdThunk(server->main, server->changeClients[i]) == 0)
                return 0;
        }
        if (BTL_SLOT_CountLiving(BTL_SIDE_GetSlotOfClient(server->partyTable, BTL_MAIN_GetOwnClientId(server->main))) < 2)
            return 0;
        return 1;
    }
    return 0;
}

u32 BTL_SERVER_GetShiftPromptMon(BtlServer *server)
{
    BtlServerClient *client = &server->clients[1];
    const union BtlAction *action;
    if (BTL_SERVER_IsClientSlotUsed(client) != 0) {
        action = BTL_ADAPTER_GetSendBuffer(client->adapter, 0);
        if (BTL_ACTION_GetKind(action) == 3) {
            struct BtlPokeParam *party = BTL_SIDE_GetClientPoke(server->partyTable, 1, action->change.memberIndex);
            return BTL_POKEPARAM_GetPokeId(party);
        }
    }
    return 0x1f;
}

int BTL_SERVER_StepRequestPokeReplace(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        BTL_SERVER_SendCommandData(server, 6, server->changeClients, server->changeCount);
        (*step)++;
        break;
    case 1:
        if (BTL_SERVER_AreRepliesReady(server)) {
            BTL_SERVER_ClearReplies(server);
            if (BTL_MAIN_CheckOwnWindowDone(server->main)) {
                BTL_SERVER_SetHandler(server, BTL_SERVER_StepSelectEnding);
            } else {
                BTL_SERVER_CollectReplies(server);
                if (BTL_SERVER_SendActionPacket(server, 3, 0)) (*step)++;
                else *step += 2;
            }
        }
        break;
    case 2:
        if (BTL_SERVER_AreRepliesReady(server)) {
            BTL_SERVER_ClearReplies(server);
            (*step)++;
        }
        break;
    case 3:
        BTL_SERVER_ClearReplies(server);
        BTL_SERVER_FLOW_ResetInitStateAfterSelect(server->flow);
        (*step)++;
    case 4: {
        int *buf;
        buf = server->sendBuf;
        buf[0] = 0;
        buf[1] = 0;
        server->flowResult = BTL_SERVER_FLOW_StartAfterPokeSelect(server->flow, &server->replies);
        buf = server->sendBuf;
        BTL_SERVER_SendCommandData(server, 8, buf + 2, buf[0]);
        (*step)++;
        break;
    }
    case 5:
        if (BTL_SERVER_AreRepliesReady(server)) {
            BTL_SERVER_ClearReplies(server);
            switch (server->flowResult) {
            case 1: *step = 0; break;
            case 3: *step = 4; break;
            case 2: BTL_SERVER_SetHandler(server, BTL_SERVER_StepRequestPokeChange); break;
            case 4:
                BTL_MAIN_SetOutcomeIfUnset(server->main, BTL_SERVER_FLOW_GetBattleResult(server->flow));
                BTL_SERVER_SetHandler(server, BTL_SERVER_StepSelectEnding);
                break;
            case 5: return 1;
            case 0:
            default: BTL_SERVER_GotoSelectCommands(server); break;
            }
        }
        break;
    }
    return 0;
}

int BTL_SERVER_StepSendRecording(BtlServer *server, int *step)
{
    unsigned int size;
    switch (*step) {
    case 0: {
        u8 *packet = BTL_REC_MakeResetPacket(&server->recorder, &size);
        BTL_SERVER_SendCommandData(server, 0xa, packet, size);
        (*step)++;
        break;
    }
    case 1:
        if (BTL_SERVER_AreRepliesReady(server) != 0) {
            BTL_SERVER_ClearReplies(server);
            BTL_SERVER_SendCommand(server, 0x10);
            (*step)++;
        }
        break;
    case 2:
        if (BTL_SERVER_AreRepliesReady(server) != 0) {
            BTL_SERVER_ClearReplies(server);
            BTL_MAIN_SetOutcomeIfUnset(server->main, BTL_SERVER_FLOW_GetBattleResult(server->flow));
            BTL_SERVER_SetHandler(server, BTL_SERVER_StepSelectEnding);
        }
        break;
    }
    return 0;
}

int BTL_SERVER_StepSelectEnding(BtlServer *server, int *step)
{
    int result = BTL_MAIN_JudgeResultThunk(server->main);
    server->result.result = result;
    server->result.playerClientId = BTL_MAIN_GetOwnClientId(server->main);
    switch (BTL_MAIN_GetCompetitor(server->main)) {
    case 1:
        BTL_SERVER_SetHandler(server, BTL_SERVER_StepSendTrainerResult);
        break;
    case 2:
        BTL_SERVER_SetHandler(server, BTL_SERVER_StepSendSubwayResult);
        break;
    case 3:
        BTL_SERVER_SetHandler(server, BTL_SERVER_StepSendCommResult);
        break;
    case 0:
        if (result == 1) {
            BTL_SERVER_SetHandler(server, BTL_SERVER_StepSendWildWin);
        } else if (result == 0 || result == 2) {
            BTL_SERVER_SetHandler(server, BTL_SERVER_StepSendWildLoseOrDraw);
        } else {
            BTL_SERVER_SetHandler(server, BTL_SERVER_StepWaitEnd);
        }
        break;
    default:
        if (result == 1) {
            GFL_USE_CancelChangeAndPlayBgm(BTL_MAIN_GetWinBgm(server->main), 0xffff);
        }
        BTL_SERVER_SetHandler(server, BTL_SERVER_StepWaitEnd);
        break;
    }
    return 0;
}

int BTL_SERVER_StepWaitEnd(BtlServer *server, int *step)
{
    switch (*step) {
    case 0: {
        int finished = 0;
        if (BTL_MAIN_GetOwnsSlots(server->main) == 0) {
            if ((KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() != 0) finished = 1;
        } else {
            finished = 1;
        }
        if (finished != 0) {
            (*step)++;
            return 1;
        }
        break;
    }
    case 1:
        return 1;
    }
    return 0;
}

int BTL_SERVER_StepSendWildWin(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        BTL_SERVER_SendCommandData(server, 0xe, &server->result, 4);
        (*step)++;
        break;
    case 1:
        if (BTL_SERVER_AreRepliesReady(server) != 0) {
            BTL_SERVER_ClearReplies(server);
            (*step)++;
        }
        break;
    case 2:
        BTL_SERVER_SetHandler(server, BTL_SERVER_StepWaitEnd);
        break;
    }
    return 0;
}

int BTL_SERVER_StepSendWildLoseOrDraw(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        BTL_SERVER_SendCommandData(server, 0xf, &server->result, 4);
        (*step)++;
        break;
    case 1:
        if (BTL_SERVER_AreRepliesReady(server) != 0) {
            BTL_SERVER_ClearReplies(server);
            (*step)++;
        }
        break;
    case 2:
        BTL_SERVER_SetHandler(server, BTL_SERVER_StepWaitEnd);
        break;
    }
    return 0;
}

int BTL_SERVER_StepSendCommResult(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        BTL_SERVER_SendCommandData(server, 0xd, &server->result, 4);
        (*step)++;
        break;
    case 1:
        if (BTL_SERVER_AreRepliesReady(server) != 0) {
            BTL_SERVER_ClearReplies(server);
            (*step)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}

int BTL_SERVER_StepSendTrainerResult(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        BTL_SERVER_SendCommandData(server, 0xb, &server->result, 4);
        (*step)++;
        break;
    case 1:
        if (BTL_SERVER_AreRepliesReady(server) != 0) {
            BTL_SERVER_ClearReplies(server);
            (*step)++;
        }
        break;
    case 2:
        BTL_SERVER_SetHandler(server, BTL_SERVER_StepWaitEnd);
        break;
    }
    return 0;
}

int BTL_SERVER_StepSendSubwayResult(BtlServer *server, int *step)
{
    switch (*step) {
    case 0:
        BTL_SERVER_SendCommandData(server, 0xc, &server->result, 4);
        (*step)++;
        break;
    case 1:
        if (BTL_SERVER_AreRepliesReady(server) != 0) {
            BTL_SERVER_ClearReplies(server);
            (*step)++;
        }
        break;
    case 2:
        if (BTL_MAIN_GetCommPos(server->main) == 0) {
            BTL_SERVER_SetHandler(server, BTL_SERVER_StepWaitEnd);
        } else {
            return 1;
        }
        break;
    }
    return 0;
}

void BTL_SERVER_LoadRecorderReplies(BtlServer *server, void *src, int size)
{
    u8 i;
    u8 clientId;
    u8 count;
    u32 index;
    u32 words[3];
    index = 0;
    for (i = 0; i < 4; i++)
        server->replies.count[i] = 0;
    BTL_REC_LoadPacket(&server->recorder, src, size);
    while (BTL_REC_NextRecord(&server->recorder, &index, &clientId, &count, words) != 0) {
        for (i = 0; i < count; i++)
            server->replies.action[clientId][i].raw = words[i];
        server->replies.count[clientId] = count;
    }
}

void BTL_SERVER_NoOp(void *reply)
{
}

int BTL_SERVER_CompareFlowOutput(BtlServer *server, int stage, void *expected, u32 size)
{
    u32 *buf = server->sendBuf;
    buf[0] = 0;
    buf[1] = 0;
    switch (stage) {
    case 4:
        BTL_SERVER_FLOW_RunBattleStart(server->flow);
        break;
    case 1:
        BTL_SERVER_FLOW_ResetInitState(server->flow);
        BTL_SERVER_FLOW_StartTurn(server->flow, &server->replies);
        break;
    case 2:
        BTL_SERVER_FLOW_ResetInitStateAfterChange(server->flow);
        BTL_SERVER_FLOW_StartAfterPokeChange(server->flow, &server->replies);
        break;
    case 3:
        BTL_SERVER_FLOW_ResetInitStateAfterSelect(server->flow);
        BTL_SERVER_FLOW_StartAfterPokeSelect(server->flow, &server->replies);
        break;
    }
    buf = server->sendBuf;
    if (buf[0] == size && GF_STANDARD_CompareBytes((const u8 *)(buf + 2), expected, size) == 0)
        return 0;
    return 1;
}

int BTL_SERVER_SendSkipPacket(BtlServer *server, int skipFlags)
{
    unsigned int size;
    u8 *packet;
    BTL_REC_InitPacket(&server->recorder, 1);
    packet = BTL_REC_MakeSkipPacket(&server->recorder, &size, skipFlags);
    BTL_SERVER_SendCommandData(server, 10, packet, size);
    return 1;
}

/*
 * interface: BTL_SERVER_BuildActionPacket's matched source declares void and an integer
 * fourth payload. Its original forwards that full word into EE96C r2;
 * EE96C stores the output count through r2 only on its nonzero return path
 * (021EE998), returns base+4 or zero, and BB650 leaves that r0 live.
 * This caller passes &size in r3 and reads r0, so its extern preserves both.
 */
int BTL_SERVER_SendActionPacket(BtlServer *server, int stage, int initArg)
{
    unsigned int size;
    void *packet;
    packet = BTL_SERVER_BuildActionPacket(server, stage, initArg, &size);
    if (packet != 0) {
        BTL_SERVER_SendCommandData(server, 10, packet, size);
        return 1;
    }
    return 0;
}

void *BTL_SERVER_BuildActionPacket(BtlServer *server, int stage, int initArg, unsigned int *outSize)
{
    u32 i;
    u32 header;
    BTL_REC_InitPacket(&server->recorder, initArg);
    for (i = 0; i < 4; i++) {
        if (server->clients[i].clientId != 0xff) {
            const void *data = BTL_ADAPTER_GetSendBuffer(server->clients[i].adapter, &header);
            BTL_REC_AddRecord(&server->recorder, i, data, (header << 22) >> 24);
        }
    }
    return BTL_REC_FinishPacket(&server->recorder, stage, outSize);
}

/*
 * note 2026-10-05 (final push G6L5): closed by copying each word through a one-word struct
 *   (BtlServerWord, source cursor `BtlServerWord *src`, destination element type BtlServerWord, so
 *   `server->replies.action[i][j] = *src++;` is a struct assignment). The word-copy path creates the load before
 *   the destination address, which gives the walking source in r2 with j in r0, cnt in r1 and
 *   the load in r6. Plain `u32 *s` with `*s++` (every spelling) gave j=r1, cnt=r2, s=r3, load r0
 *   (51 bytes); indexed `s[j]` gave `ldr r6,[r2,r4]` (1 byte). Same shape in both lang c99 and c.
 */
void BTL_SERVER_CollectReplies(BtlServer *server)
{
    u32 i;
    u32 j;
    u32 size;
    u32 count;
    const union BtlAction *src;
    BtlServerClient *client;
    for (i = 0; i < 4; i++) {
        client = &server->clients[i];
        server->replies.count[i] = 0;
        if (BTL_SERVER_IsClientSlotUsed(client) != 0) {
            src = BTL_ADAPTER_GetSendBuffer(client->adapter, &size);
            count = size >> 2;
            for (j = 0; j < count; j++) {
                server->replies.action[i][j] = *src++;
                server->replies.count[i]++;
            }
        }
    }
}

void BTL_SERVER_SendCommand(BtlServer *server, int command)
{
    BTL_SERVER_SendCommandData(server, command, 0, 0);
}

void BTL_SERVER_SendCommandData(BtlServer *server, int command, const void *data, int size)
{
    int i;
    BtlServerClient *clients;
    BTL_ADAPTER_NotifyNet();
    i = 0;
    clients = server->clients;
    for (; i < 4; i++) {
        if (BTL_SERVER_IsClientSlotUsed(clients + i) != 0)
            BTL_ADAPTER_SetSendData(server->clients[i].adapter, command, data, size);
    }
    BTL_ADAPTER_Idle();
}

void BTL_SERVER_SendCommandDataToClient(BtlServer *server, int command, u32 clientIndex, const void *data, int size) {
    BtlServerClient *client;
    client = &server->clients[clientIndex];
    if (BTL_SERVER_IsClientSlotUsed(client)) {
        BTL_ADAPTER_Cancel(client->adapter);
        BTL_ADAPTER_SetSendData(client->adapter, command, data, size);
    }
}

int BTL_SERVER_AreRepliesReady(BtlServer *server) {
    int allReceived;
    int i;
    BtlServerClient *clients;
    allReceived = 1; i = 0; clients = server->clients;
    for (; i < 4; i++) {
        if (BTL_SERVER_IsClientSlotUsed(clients + i)) {
            if (!BTL_ADAPTER_Update(server->clients[i].adapter)) allReceived = 0;
        }
    }
    return allReceived;
}

void BTL_SERVER_ClearReplies(const BtlServer *server) {
    int i;
    i = 0;
    for (; i < 4; i++) {
        if (BTL_SERVER_IsClientSlotUsed(&server->clients[i])) BTL_ADAPTER_Cancel(server->clients[i].adapter);
    }
}

void BTL_SERVER_ResetClientCommands(const BtlServer *server) {
    int i;
    i = 0;
    for (; i < 4; i++) {
        if (BTL_SERVER_IsClientSlotUsed(&server->clients[i])) BTL_ADAPTER_ResetCommand(server->clients[i].adapter);
    }
}

/*
 * store constant 0xff at #0xb
 */
void BTL_SERVER_ClearClient(BtlServerClient *client)
{
    client->clientId = 0xff;
}

int BTL_SERVER_IsClientSlotUsed(const BtlServerClient *client) { if (client->clientId != 255) return 1; return 0; }

void BTL_SERVER_SetClientAdapterSlot(BtlServerClient *client, int clientId, void *adapter, int adapterBorrowed)
{
    client->clientId = clientId;
    client->adapter = adapter;
    client->adapterBorrowed = adapterBorrowed;
}

void BTL_SERVER_SetClientParty(BtlServerClient *client, void *party, u8 battleSlots) { client->party = party; client->partyCount = BTL_SLOT_GetCount(party); client->battleSlots = battleSlots; }

BtlServerClient *BTL_SERVER_GetClientChecked(BtlServer *server, unsigned int index) { if (index < 4 && server->clients[index].clientId != 255) return &server->clients[index]; return 0; }

BtlServerClient *BTL_SERVER_GetClientIfUsed(BtlServer *server, u32 index) { if (server->clients[index].clientId != 255) return &server->clients[index]; return 0; }

int BTL_SERVER_IsClientUsed(BtlServer *server, u8 index) { if (index < 4) return BTL_SERVER_IsClientSlotUsed(&server->clients[index]); return 0; }

/* 021BB8A8  adds r0,r0,r1; adds r0,#0x30; ldrb r0,[r0] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: adds r0, r0, r1; adds r0, #0x30; ldrb r0, [r0]; bx lr.
 */
u8 BTL_SERVER_GetActionTableValue(BtlServerActionTable *table, u8 index) { return table->count[index]; }

/* 021BB8B0  movs r3,#0xc; muls r3,r1,r3; lsls r1,r2,#2; adds r0,r0,r3;
 *           ldr r0,[r1,r0] */
/*
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: movs r3, #0xc; muls r3, r1, r3; lsls r1, r2, #2; adds r0, r0, r3; ldr r0, [r1, r0]; bx lr.
 */
union BtlAction BTL_SERVER_GetActionTableEntry(BtlServerActionTable *table, u8 row, u8 column)
{
    return table->action[row][column];
}

void BTL_SERVER_NotifyLevelUp(BtlServer *server, u32 *pokeParam) {
    POKE_TOOL_GetPartyValue(BTL_POKEPARAM_GetMon((struct BtlPokeParam *)pokeParam),(u32)0x73,(uptr)server->nameBuf);
    GAME_BEACON_SetPokeLevelUp(server->nameBuf);
}

/*
 * evidence: caller narrows POKE_TOOL_GetPartyValue result to u16 before 020271DC.
 */
void BTL_SERVER_NotifyCapture(BtlServer *server, u32 *pokeParam) {
    GAME_BEACON_SetPokeCapture(POKE_TOOL_GetPartyValue(BTL_POKEPARAM_GetMon((struct BtlPokeParam *)pokeParam),5,0));
    BTL_MAIN_TrainerRecordAdd(server->main,7);
    BTL_MAIN_TrainerRecordAdd(server->main,0x54);
}

void BTL_SERVER_AddMainCounter(BtlServer *server, int amount)
{
    BTL_MAIN_AddBonusMoney(server->main, amount);
}

/*
 * overlays, with no outside branch; the pool relocation has no witness.
 * All bytes correct.
 *
 * UNBLOCKED: BTL_MAIN_SetDoubleMoney is now an EXACT entry in layout/matched/ov093;
 * the call site resolves as matched, verdict promoted to EXACT.
 */
void BTL_SERVER_FinishMainCounter(BtlServer *server)
{
    BTL_MAIN_SetDoubleMoney(server->main);
}

void BTL_SERVER_ClearPokeChangeRequests(BtlServer *server) { server->changeCount = 0; server->changeLock = 0; }

/*
 * Lever: left-associated pointer addition p + count + 0xcb4 preserves
 * the base-plus-count computation before the incrementing byte store.
 */
void BTL_SERVER_AddPokeChangeRequest(BtlServer *server, u32 clientId)
{
    u32 i;
    u32 count = server->changeCount;
    for (i = 0; i < count; i++) {
        if (clientId == server->changeClients[i]) return;
    }
    server->changeCount++;
    server->changeClients[count] = clientId;
}

void *BTL_SERVER_GetFlow(BtlServer *server) { return server->flow; }

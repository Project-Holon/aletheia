/*
 * file:     plist_comm.c
 * unit:     yes
 * function: PLIST_COMM_Start, PLIST_COMM_End, PLIST_COMM_Update, PLIST_COMM_SendStatus, PLIST_COMM_OnStatusReceived, PLIST_COMM_StartSync, PLIST_COMM_IsSyncDoneOrFinished
 * address:  0x021B6100
 * region:   ov090
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   gPartyListCommandTable     0x021B6228  data  a4
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 */
struct NetHandle;
#include "../types.h"

/*
 * The fields of the party list parameter block (PartyListParam, defined by
 * the caller in ov012) that this overlay reads and writes. Offsets 0x62,
 * 0x63 and 0x94 lie in the unnamed gap of that struct.
 */
typedef struct PartyListCommWork {
    u8 unusedHead[0x62];
    u8 syncStep;          /* 0: request sync 1, 1: wait for it and register the command table, 2: running */
    u8 commFinished;      /* set on a network error, read by PLIST_COMM_IsSyncDoneOrFinished as "stop waiting" */
    u8 unusedMid[0x30];
    u8 receivedCount;     /* incremented by every status message with status 0 */
} PartyListCommWork;

/* Payload of the status command (4 bytes on the wire). */
typedef struct PartyListStatusMsg {
    u16 selection;
    u8 status;
} PartyListStatusMsg;

extern void GFL_NET_COMMAND_DeleteCommandTable(u32 commandBase);
struct GFLNetHandle;
extern struct GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct GFLNetHandle *handle, u32 timingLow, u32 timingHigh);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct GFLNetHandle *handle, u32 timingLow, u32 timingHigh);
extern void GFL_NET_COMMAND_AddCommandTable(u32 groupKey, u32 commandList, u32 listNum, u32 userData);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern u32 GFL_NET_SendData(struct GFLNetHandle *handle, u32 sendId, u32 command, u32 size, void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode);
extern u32 GFL_NET_GetHandleNetID(struct GFLNetHandle *handle);
void PLIST_COMM_Start(PartyListCommWork *work);
void PLIST_COMM_End(void *unused);
void PLIST_COMM_Update(PartyListCommWork *work);
u32 PLIST_COMM_SendStatus(PartyListCommWork *work, u8 status, u16 selection);
void PLIST_COMM_OnStatusReceived(int netId, int size, u8 *data, PartyListCommWork *work);
void PLIST_COMM_StartSync(void *work, int syncNo);
int PLIST_COMM_IsSyncDoneOrFinished(PartyListCommWork *work, int syncNo);
extern u8 gPartyListCommandTable[];

void PLIST_COMM_Start(PartyListCommWork *work)
{
    work->syncStep = 0;
}

/*
 * Leaf of ov178 021E54CC; caller unloads overlay 90 immediately after call.
 */
void PLIST_COMM_End(void *unused)
{
    GFL_NET_COMMAND_DeleteCommandTable(0x2D00);
}

void PLIST_COMM_Update(PartyListCommWork *work)
{
    switch (work->syncStep) {
    case 0:
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x2d);
        work->syncStep = 1;
        break;
    case 1:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x2d) == 1) {
            GFL_NET_COMMAND_AddCommandTable((u32)0x2d00, (u32)gPartyListCommandTable, (u32)1, (u32)work);
            work->syncStep = 2;
        }
        break;
    case 2:
        break;
    }
    if (GFL_NET_ERR_GetErrorLevel() != 0 && work->commFinished == 0)
        work->commFinished = 1;
}

u32 PLIST_COMM_SendStatus(PartyListCommWork *work, u8 status, u16 selection)
{
    PartyListStatusMsg msg;
    struct NetHandle *handle;

    handle = (struct NetHandle *)GFL_NET_HANDLE_GetCurrentHandle();
    msg.status = status;
    msg.selection = selection;
    if (work->syncStep != 2)
        return 0;
    return GFL_NET_SendData((struct GFLNetHandle *)handle, 0xff, 0x2d00, 4, &msg, 1, 0, 0);
}

/* Command callback for 0x2d00: counts the status messages whose status is 0. */
void PLIST_COMM_OnStatusReceived(int netId, int size, u8 *data, PartyListCommWork *work)
{
    GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle());
    if (data[2] == 0)
        work->receivedCount++;
}

void PLIST_COMM_StartSync(void *work, int syncNo)
{
    GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), syncNo, 45);
}

int PLIST_COMM_IsSyncDoneOrFinished(PartyListCommWork *work, int syncNo)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), syncNo, 0x2d) == 1)
        return 1;
    if (work->commFinished == 1)
        return 1;
    return 0;
}

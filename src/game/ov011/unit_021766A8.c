/*
 * file:     unit_021766A8.c
 * unit:     yes
 * function: INTRUDE_LINK_ProcExit, INTRUDE_LINK_CreateEvent, INTRUDE_LINK_EventMain, INTRUDE_COMM_GetPartnerSlot, INTRUDE_COMM_GetMarkerPosForPartner, INTRUDE_COMM_SendValueNow, INTRUDE_COMM_IsRecordReceived, INTRUDE_COMM_GetPartnerRecord, INTRUDE_COMM_SetPendingValue
 * address:  0x021766A8
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203133C 0x0203133C arm
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_Start  0x021CF498  thumb  ov021
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   sIntrudeLinkProcTable     0x02176FCC  data  ov011  a4
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   GAME_DATA_GetIntrudeId  0x02012B80  thumb
 *   sLinkMarkerPosTemplate     0x02176FD8  data  ov011  a4
 *   INTRUDE_COMM_SendPageRequest 0x02174854 thumb ov011
 */
#include "../../matched/include/Obj12441.h"

struct S020314B8;
struct S020315D4;
struct Desc;
struct Obj;
struct Ctx;
struct Evt;
struct BigObj;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

#include "intrude_comm_types.h"

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} LinkMarkerPos;

typedef struct { u8 value; u8 enabled; } LinkValueMessage;

extern void func_0203133C(struct S020314B8 *p);
extern u32 func_020307B0(void *p);
extern void func_020315D4(struct S020315D4 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(void *a, u32 b);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int  FIELDMAP_GetEncEff(unsigned char *p);
extern void ENCEFF_Start(struct Ctx *c, u32 x, int idx);
extern int  FIELD_STATUS_CreateFieldCloseEvent(int a, int b);
extern void GAME_EVENT_CallProc(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern void *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(void *a);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a0);
extern void *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(void *a);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern u32 func_0200FB24(void);
extern u8 GAME_DATA_GetIntrudeId(const struct BigObj *p);
extern int INTRUDE_COMM_SendPageRequest(IntrudeCommSys *p, int key, int data);
int INTRUDE_LINK_ProcExit(void *procWork, int unused1, int unused2, u8 *linkProc);
void *INTRUDE_LINK_CreateEvent(void *partySelectArg, void *eventArg);
int INTRUDE_LINK_EventMain(void *event, u32 *state, int *eventWork);
u8 INTRUDE_COMM_GetPartnerSlot(void *comm, void *gameData);
void INTRUDE_COMM_GetMarkerPosForPartner(void *comm, void *gameData, LinkMarkerPos *outPos);
int INTRUDE_COMM_SendValueNow(IntrudeCommSys *linkState, u8 value);
u32 INTRUDE_COMM_IsRecordReceived(IntrudeCommSys *linkState);
u8 *INTRUDE_COMM_GetPartnerRecord(IntrudeCommSys *linkState);
void INTRUDE_COMM_SetPendingValue(IntrudeCommSys *linkState, u8 value);
extern char sIntrudeLinkProcTable[];
extern LinkMarkerPos sLinkMarkerPosTemplate;

/*
 * extent: two alignment bytes at 021766CA.
 * Exit callback of the link proc (init 02176454, main 02176504, table 02176FCC):
 * deletes the sub proc system, frees the party list and the proc work.
 */
int INTRUDE_LINK_ProcExit(void *procWork, int unused1, int unused2, u8 *linkProc)
{
    func_0203133C(((struct Obj12441 *)linkProc)->fF4);
    func_020307B0(((struct Obj12441 *)linkProc)->fF8);
    func_020315D4(procWork);
    return 1;
}

/* Creates the game event step that runs the link proc and stores its two arguments. */
void *INTRUDE_LINK_CreateEvent(void *partySelectArg, void *eventArg)
{
    void *event;
    void **eventWork;
    event = func_020122C0(partySelectArg, 0, INTRUDE_LINK_EventMain, 8);
    eventWork = func_020124E8(event);
    eventWork[1] = eventArg;
    eventWork[0] = partySelectArg;
    return event;
}


/*
 * Lever: case 1 forwards GAMESYSTEM_GetFieldMap's live r0 result into
 * FIELDMAP_GetEncEff(unsigned char *); the matched body reads p + 0x13C.
 * Steps: 0 fade BGM out, 1 field transition, 2 close field, 3 run the link proc,
 * 4 pop BGM fade, 5 open field, 6 wait for sound request, 7 return to field menu.
 */
int INTRUDE_LINK_EventMain(void *event, u32 *state, int *eventWork)
{
    int fieldMap;

    fieldMap = (int)GAMESYSTEM_GetFieldMap((const struct Ctx *)eventWork[0]);
    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask((void *)eventWork[0], 0x490));
        (*state)++;
        break;
    case 1:
        ENCEFF_Start((struct Ctx *)FIELDMAP_GetEncEff((unsigned char *)fieldMap), (u32)event, 5);
        (*state)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent(eventWork[0], fieldMap));
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallProc(event, -1, (u32)sIntrudeLinkProcTable, eventWork[1]);
        (*state)++;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask((void *)eventWork[0]));
        (*state)++;
        break;
    case 5:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent((void *)eventWork[0]));
        (*state)++;
        break;
    case 6:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask((void *)eventWork[0]));
        (*state)++;
        break;
    case 7:
        GAME_EVENT_CallEvent(event, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)eventWork[0], fieldMap, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    default:
        return 1;
    }
    return 0;
}


/* Returns the link slot of the partner record, or 4 when the record is the local player's. */
u8 INTRUDE_COMM_GetPartnerSlot(void *comm, void *gameData)
{
    u8 localSlot;
    u8 remoteSlot;
    IntrudeCommSys *link;

    localSlot = (int)GAME_DATA_GetExitMode(gameData);
    link = (IntrudeCommSys *)INTRUDE_COMM_GetWorkIfRunning((int)comm);
    if (func_0200FB24()) {
        remoteSlot = (int)GAME_DATA_GetIntrudeId(gameData);
        if (remoteSlot == localSlot) {
            return 4;
        }
        return remoteSlot;
    }
    if (link != 0) {
        if (link->localPeer.intrudeId == localSlot) {
            return 4;
        }
        return link->localPeer.intrudeId;
    }
    return 4;
}


/* Writes the marker position template, shifted by the slot distance to the partner (wrapped by player count). */
void INTRUDE_COMM_GetMarkerPosForPartner(void *comm, void *gameData, LinkMarkerPos *outPos)
{
    IntrudeCommSys *link;
    int slotDistance;

    link = (IntrudeCommSys *)INTRUDE_COMM_GetWorkIfRunning((int)comm);
    if (link == 0 || link->localPeer.intrudeId == GAME_DATA_GetExitMode(gameData)) {
        slotDistance = 0;
    } else {
        slotDistance = link->localPeer.intrudeId - GAME_DATA_GetExitMode(gameData);
        if (slotDistance < 0) {
            slotDistance += link->memberCount;
        }
    }
    *outPos = sLinkMarkerPosTemplate;
    outPos->x += slotDistance << 22;
}

/*
 * extent: followers 02176870 and 02176880 already filed separately.
 * Sends the value to the partner (network command 0x228) tagged as enabled.
 */
int INTRUDE_COMM_SendValueNow(IntrudeCommSys *linkState, u8 value)
{
    LinkValueMessage message;
    message.value = value;
    message.enabled = 1;
    return INTRUDE_COMM_SendPageRequest(linkState, (u8)linkState->localPeer.intrudeId, (int)&message);
}


/* Returns the pageReceived flag. */
u32 INTRUDE_COMM_IsRecordReceived(IntrudeCommSys *linkState)
{
    return linkState->pageReceived;
}


/*
 * Returns the received partner record (+0x82C).
 * Filed as the sole blocker of SYMBOL_MAP_GetSelection (ov010).
 */
u8 *INTRUDE_COMM_GetPartnerRecord(IntrudeCommSys *linkState)
{
    return (u8 *)&linkState->peerSymbolPage;
}


/*
 * Stores the value to send and arms the retry flag (areaNoticeValue/areaNoticePending).
 * Recursive MATCH unblocker: callee of SCRCMD_SYMBOL_SendEntryFlag (ov010) at +0032. The
 * address is Thumb code in ov011 (ARM/data in the overlapping ov009), so the
 * matched shard makes that site attest as `matched`.
 */
void INTRUDE_COMM_SetPendingValue(IntrudeCommSys *linkState, u8 value)
{
    linkState->areaNoticeValue = value;
    linkState->areaNoticePending = 1;
}

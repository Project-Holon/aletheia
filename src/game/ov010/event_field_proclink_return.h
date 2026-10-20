#ifndef GAME_OV010_EVENT_FIELD_PROCLINK_RETURN_H
#define GAME_OV010_EVENT_FIELD_PROCLINK_RETURN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_field_proclink_return.c, prototypes copied from their definitions. */

struct ProcLinkSys;
struct ProcLinkEntry;
struct ProcLinkRequest;
struct EventSlots;
struct EventSlot;
typedef struct ProcLinkSys ProcLinkSys;
typedef struct ProcLinkEntry ProcLinkEntry;
typedef struct ProcLinkRequest ProcLinkRequest;
typedef struct EventSlots EventSlots;
typedef struct EventSlot EventSlot;

#include "../types.h"

void EVENT_FIELD_PROCLINK_CompactReturnList(ProcLinkSys *procLink, int listIndex);
void EVENT_FIELD_PROCLINK_ClearReturnEntry(ProcLinkEntry *entry);
int EVENT_FIELD_PROCLINK_IsReturnEntryAllowed(ProcLinkEntry *entry);
int EVENT_FIELD_PROCLINK_IsReturnEntryValid(ProcLinkEntry *entry);
void EVENT_FIELD_PROCLINK_InitIdList(u16 *buf);
void EVENT_FIELD_PROCLINK_InitReturnHeader(ProcLinkRequest *request);
void EVENT_FIELD_PROCLINK_GetReturnInfo(u16 *result, ProcLinkRequest *request, int variant);
void EVENT_FIELD_PROCLINK_InitReturnSlotsWithAid(EventSlots *slots);
void EVENT_FIELD_PROCLINK_ClearReturnSlots(EventSlots *slots);
void EVENT_FIELD_PROCLINK_RunReturnSlotsIfOffline(EventSlots *slots, ProcLinkSys *procLink, int slotMask);
void EVENT_FIELD_PROCLINK_ApplyReturnEntry(int unused, ProcLinkRequest *request, ProcLinkSys *procLink, int arg, u16 linkId, u16 variant);
void EVENT_FIELD_PROCLINK_SetReturnLinkId(EventSlots *slots, u16 pendingKey);
void EVENT_FIELD_PROCLINK_SetReturnSlotDefaultIfOffline(EventSlots *slots, EventSlot *slot);
void EVENT_FIELD_PROCLINK_SetReturnSlotIfOffline(EventSlots *slots, int index, EventSlot *slot);
int EVENT_FIELD_PROCLINK_GetReturnResultSlot(EventSlots *slots, int index, EventSlot *result);
int EVENT_FIELD_PROCLINK_GetReturnPendingSlot(EventSlots *slots, EventSlot *result, u8 *pendingKey);
void EVENT_FIELD_PROCLINK_ClearReturnResultSlot(EventSlots *slots, int index);
void EVENT_FIELD_PROCLINK_ClearReturnPendingSlotThunk(EventSlots *slots);
void EVENT_FIELD_PROCLINK_RequestReturn(EventSlots *slots, int entryId, int handlerIndex);
int EVENT_FIELD_PROCLINK_HasReturnDefaultSlot(EventSlots *slots, int unused);
u16 EVENT_FIELD_PROCLINK_GetReturnDefaultSlotType(EventSlots *slots);
void EVENT_FIELD_PROCLINK_ClearReturnDefaultAndPending(EventSlots *slots);
void EVENT_FIELD_PROCLINK_CompactEntryList(char *entries);
int EVENT_FIELD_PROCLINK_IsNetConnected(int unused);
void EVENT_FIELD_PROCLINK_RunReturnSlots(EventSlots *slots, ProcLinkSys *procLink, int slotMask);
int EVENT_FIELD_PROCLINK_HandlerCheckEntryGrid(EventSlots *slots, ProcLinkSys *procLink, const EventSlot *slot, EventSlot *result);
int EVENT_FIELD_PROCLINK_HandlerCheckEntryRail(EventSlots *slots, ProcLinkSys *procLink, const EventSlot *slot, EventSlot *result);
int EVENT_FIELD_PROCLINK_HandlerRemoveEntry(EventSlots *slots, ProcLinkSys *procLink, const EventSlot *slot);
void EVENT_FIELD_PROCLINK_SetReturnSlotDefault(EventSlots *slots, EventSlot *slot);
void EVENT_FIELD_PROCLINK_SetReturnSlot(EventSlots *slots, int index, EventSlot *slot);
int EVENT_FIELD_PROCLINK_GetReturnSlot(EventSlots *slots, u16 index, EventSlot *out);
void EVENT_FIELD_PROCLINK_SetReturnResultSlot(EventSlots *slots, int index, u16 entryId, u16 handlerType);
void EVENT_FIELD_PROCLINK_SetReturnPendingSlot(EventSlots *slots, int entryId, int handlerType);
int EVENT_FIELD_PROCLINK_GetReturnResultSlotSub(EventSlots *slots, int index, EventSlot *out);
int EVENT_FIELD_PROCLINK_GetReturnPendingSlotSub(EventSlots *slots, EventSlot *out);
void EVENT_FIELD_PROCLINK_ClearReturnDefaultSlot(EventSlots *slots);
void EVENT_FIELD_PROCLINK_ClearReturnSlot(EventSlots *slots, unsigned index);
void EVENT_FIELD_PROCLINK_ClearReturnResultSlotSub(EventSlots *slots, unsigned index);
void EVENT_FIELD_PROCLINK_ClearReturnPendingSlot(EventSlots *slots);
int EVENT_FIELD_PROCLINK_IsSlotIndexOutOfRange(int value);
/* END mkheaders: generated region */

#endif

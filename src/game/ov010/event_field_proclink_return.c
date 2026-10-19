/*
 * file:     event_field_proclink_return.c
 * unit:     yes
 * function: EVENT_FIELD_PROCLINK_CompactReturnList, EVENT_FIELD_PROCLINK_ClearReturnEntry, EVENT_FIELD_PROCLINK_IsReturnEntryAllowed, EVENT_FIELD_PROCLINK_IsReturnEntryValid, EVENT_FIELD_PROCLINK_InitIdList, EVENT_FIELD_PROCLINK_InitReturnHeader, EVENT_FIELD_PROCLINK_GetReturnInfo, EVENT_FIELD_PROCLINK_InitReturnSlotsWithAid, EVENT_FIELD_PROCLINK_ClearReturnSlots, EVENT_FIELD_PROCLINK_RunReturnSlotsIfOffline, EVENT_FIELD_PROCLINK_ApplyReturnEntry, EVENT_FIELD_PROCLINK_SetReturnLinkId, EVENT_FIELD_PROCLINK_SetReturnSlotDefaultIfOffline, EVENT_FIELD_PROCLINK_SetReturnSlotIfOffline, EVENT_FIELD_PROCLINK_GetReturnResultSlot, EVENT_FIELD_PROCLINK_GetReturnPendingSlot, EVENT_FIELD_PROCLINK_ClearReturnResultSlot, EVENT_FIELD_PROCLINK_ClearReturnPendingSlotThunk, EVENT_FIELD_PROCLINK_RequestReturn, EVENT_FIELD_PROCLINK_HasReturnDefaultSlot, EVENT_FIELD_PROCLINK_GetReturnDefaultSlotType, EVENT_FIELD_PROCLINK_ClearReturnDefaultAndPending, EVENT_FIELD_PROCLINK_CompactEntryList, EVENT_FIELD_PROCLINK_IsNetConnected, EVENT_FIELD_PROCLINK_RunReturnSlots, EVENT_FIELD_PROCLINK_HandlerCheckEntryGrid, EVENT_FIELD_PROCLINK_HandlerCheckEntryRail, EVENT_FIELD_PROCLINK_HandlerRemoveEntry, EVENT_FIELD_PROCLINK_SetReturnSlotDefault, EVENT_FIELD_PROCLINK_SetReturnSlot, EVENT_FIELD_PROCLINK_GetReturnSlot, EVENT_FIELD_PROCLINK_SetReturnResultSlot, EVENT_FIELD_PROCLINK_SetReturnPendingSlot, EVENT_FIELD_PROCLINK_GetReturnResultSlotSub, EVENT_FIELD_PROCLINK_GetReturnPendingSlotSub, EVENT_FIELD_PROCLINK_ClearReturnDefaultSlot, EVENT_FIELD_PROCLINK_ClearReturnSlot, EVENT_FIELD_PROCLINK_ClearReturnResultSlotSub, EVENT_FIELD_PROCLINK_ClearReturnPendingSlot, EVENT_FIELD_PROCLINK_IsSlotIndexOutOfRange
 * address:  0x02161E60
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Return-slot and proclink table code; continues the ov010 event_field_proclink.c unit (the functions before the eventdata_system.c anchor at 0x0216237C).
 *
 * symbols:
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   FIELD_WFBC_DATA_LOCAL_OpenNpcData  0x021867C4  thumb ov020
 *   FIELD_WFBC_DATA_LOCAL_GetNpcRecord  0x0218682C  thumb
 *   FIELD_WFBC_DATA_LOCAL_CloseNpcData  0x02186804  thumb
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   EVENT_FIELD_PROCLINK_GetEventdataEntry  0x02161DC4  thumb
 *   FIELD_WFBC_DATA_LOCAL_InsertPersonForCity  0x02186520  thumb
 *   d_0217144C     0x0217144C  data  ov010  a4
 *   MI_CpuCopy8    0x02082D44  arm
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   d_02172990     0x02172990  data  ov010  a4
 *   MI_CpuFill8    0x02082BCC  arm
 */

#include "../ov021/fldmmdl_rail_types.h"
#include "fldmmdl_types.h"

typedef unsigned int u32;

/* One return request: the record key it belongs to, the proclink entry it
 * names, and the handler type (index into d_02172990). */
typedef struct EventSlot {
    u32 key;            /* 0x00 */
    u16 entryId;        /* 0x04 */
    u16 handlerType;    /* 0x06 */
} EventSlot;

/* A proclink entry (0x18 bytes). */
typedef struct ProcLinkEntry {
    u8 active : 4;      /* 0x00: 0 = empty */
    u8 idFilter : 4;    /*       nonzero: only the ids below may use it */
    u8 age;             /* 0x01: usable while below 30 */
    u8 value;           /* 0x02: usable while at most 100 */
    u8 kind;            /* 0x03: 7 when set by EVENT_FIELD_PROCLINK_ApplyReturnEntry */
    u16 allowedIds[8];  /* 0x04 */
} ProcLinkEntry;

/* The proclink table: two lists of 10 entries after an 8-byte head. */
typedef struct ProcLinkSys {
    u8 head[8];                     /* 0x00 */
    ProcLinkEntry entries[2][10];   /* 0x08 and 0xF8 */
} ProcLinkSys;

/* A proclink request (9 + 1 bytes read here): mode at +2 (10 = none), link id at +9. */
typedef struct ProcLinkRequest {
    u16 reserved;       /* 0x00 */
    u16 mode;           /* 0x02 */
    u8 pad4[5];         /* 0x04 */
    u8 linkId;          /* 0x09 */
} ProcLinkRequest;

typedef struct EventSlots EventSlots;

/* One return handler (index = EventSlot.handlerType), table d_02172990. */
typedef int (*ReturnHandlerFn)(EventSlots *slots, ProcLinkSys *procLink, void *slot, void *result);

/* The return-slot record (0x48 bytes). */
struct EventSlots {
    u16 key;                /* 0x00 */
    u16 flags;              /* 0x02: bits 0-2 slot, 3 default, 4 pending, 5-7 result */
    u16 pendingKey;         /* 0x04 */
    u8 pad6[2];
    EventSlot slot[3];      /* 0x08 */
    EventSlot defaultSlot;  /* 0x20 */
    EventSlot pendingSlot;  /* 0x28 */
    EventSlot resultSlot[3]; /* 0x30 */
};

extern u16 STRBUF_GetEosChar(void);
extern int FIELD_WFBC_DATA_LOCAL_OpenNpcData(int, int);
extern u16 *FIELD_WFBC_DATA_LOCAL_GetNpcRecord(int h);
extern void FIELD_WFBC_DATA_LOCAL_CloseNpcData(int);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern ProcLinkEntry *EVENT_FIELD_PROCLINK_GetEventdataEntry(ProcLinkSys *procLink, int linkId, unsigned mode);
extern void FIELD_WFBC_DATA_LOCAL_InsertPersonForCity(ProcLinkRequest *request, int arg, ProcLinkEntry *entry);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
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
extern int d_0217144C[];
extern ReturnHandlerFn d_02172990[];

void EVENT_FIELD_PROCLINK_CompactReturnList(ProcLinkSys *procLink, int listIndex)
{
    if (listIndex == 0)
        EVENT_FIELD_PROCLINK_CompactEntryList((char *)procLink + 8);
    else
        EVENT_FIELD_PROCLINK_CompactEntryList((char *)procLink + 0xf8);
}

/*
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into MI_CpuFill8, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/EVENT_FIELD_PROCLINK_ClearReturnEntry.c \
 *       --func EVENT_FIELD_PROCLINK_ClearReturnEntry --addr 0x02161E78 --region ov010 --cc dsi/1.1p1 --thumb
 */
void EVENT_FIELD_PROCLINK_ClearReturnEntry(ProcLinkEntry *entry)
{

    MI_CpuFill8(entry, 0, 24);
}

int EVENT_FIELD_PROCLINK_IsReturnEntryAllowed(ProcLinkEntry *entry)
{
    int curId = STRBUF_GetEosChar();
    int i;
    int found;
    if (entry->age >= 30) return 0;
    if (entry->value > 100) return 0;
    if (entry->idFilter != 0) {
        found = 0;
        for (i = 0; i < 8; i++) {
            if (curId == entry->allowedIds[i]) found = 1;
        }
        if (found == 0) return 0;
    }
    return 1;
}

int EVENT_FIELD_PROCLINK_IsReturnEntryValid(ProcLinkEntry *entry)
{
    if (entry->active == 0) return 0;
    if (EVENT_FIELD_PROCLINK_IsReturnEntryAllowed(entry) != 0) return 1;
    return 0;
}

/*
 * Fills ten halfwords with 0xFFFF.  A leaf with no lr-saving prologue,
 * called only from arm9 (MUSICAL_SHOT_Init), so the listing emits it as data.
 */
void EVENT_FIELD_PROCLINK_InitIdList(u16 *buf)
{
    int i;
    for (i = 0; i < 10; i++)
        buf[i] = 0xffff;
}

void EVENT_FIELD_PROCLINK_InitReturnHeader(ProcLinkRequest *request)
{
    MI_CpuFill8(request, 0, 4);
    request->mode = 10;
}

void EVENT_FIELD_PROCLINK_GetReturnInfo(u16 *result, ProcLinkRequest *request, int variant)
{
    int handle;
    u16 *record;
    if (request->mode == 1) {
        handle = FIELD_WFBC_DATA_LOCAL_OpenNpcData(request->linkId, (u16)((variant & 0x7FFF) | 0x8000));
        record = FIELD_WFBC_DATA_LOCAL_GetNpcRecord(handle);
        result[0] = record[0x24 / 2];
        result[1] = record[8 / 2];
        FIELD_WFBC_DATA_LOCAL_CloseNpcData(handle);
    } else {
        result[0] = 0;
        result[1] = 10;
    }
}

void EVENT_FIELD_PROCLINK_InitReturnSlotsWithAid(EventSlots *slots)
{
    MI_CpuFill8(slots, 0, 0x48);
    slots->key = GFL_NET_SYSTEM_GetCurrentAid();
}

void EVENT_FIELD_PROCLINK_ClearReturnSlots(EventSlots *slots)
{
    MI_CpuFill8(slots, 0, 0x48);
}

void EVENT_FIELD_PROCLINK_RunReturnSlotsIfOffline(EventSlots *slots, ProcLinkSys *procLink, int slotMask)
{
    if (EVENT_FIELD_PROCLINK_IsNetConnected((int)slots) == 0)
        EVENT_FIELD_PROCLINK_RunReturnSlots(slots, procLink, slotMask);
}

void EVENT_FIELD_PROCLINK_ApplyReturnEntry(int unused, ProcLinkRequest *request, ProcLinkSys *procLink, int arg, u16 linkId, u16 variant)
{
    ProcLinkEntry *entry;
    int handle;
    u16 *record;

    entry = EVENT_FIELD_PROCLINK_GetEventdataEntry(procLink, linkId, 1);
    handle = (int)FIELD_WFBC_DATA_LOCAL_OpenNpcData(linkId, variant);
    record = FIELD_WFBC_DATA_LOCAL_GetNpcRecord(handle);
    if (request->mode == 0)
        entry->value = record[3];
    else
        entry->value = record[2];
    entry->kind = 7;
    FIELD_WFBC_DATA_LOCAL_CloseNpcData(handle);
    FIELD_WFBC_DATA_LOCAL_InsertPersonForCity(request, arg, entry);
    EVENT_FIELD_PROCLINK_ClearReturnEntry(entry);
    EVENT_FIELD_PROCLINK_CompactReturnList(procLink, 1);
}

/*
 * Unlabelled leaf, four bytes: strh r1, [r0, 4]; bx lr.
 */
/*
 * Unlabelled leaf, four bytes: strh r1, [r0, #4]; bx lr.
 */
void EVENT_FIELD_PROCLINK_SetReturnLinkId(EventSlots *slots, u16 pendingKey)
{
    slots->pendingKey = pendingKey;
}

void EVENT_FIELD_PROCLINK_SetReturnSlotDefaultIfOffline(EventSlots *slots, EventSlot *slot)
{
    if (EVENT_FIELD_PROCLINK_IsNetConnected((int)slots) == 0)
        EVENT_FIELD_PROCLINK_SetReturnSlotDefault(slots, slot);
}

void EVENT_FIELD_PROCLINK_SetReturnSlotIfOffline(EventSlots *slots, int index, EventSlot *slot)
{
    if (EVENT_FIELD_PROCLINK_IsNetConnected((int)slots) == 0)
        EVENT_FIELD_PROCLINK_SetReturnSlot(slots, index, slot);
}

int EVENT_FIELD_PROCLINK_GetReturnResultSlot(EventSlots *slots, int index, EventSlot *result)
{
    return EVENT_FIELD_PROCLINK_GetReturnResultSlotSub(slots, index, result);
}

int EVENT_FIELD_PROCLINK_GetReturnPendingSlot(EventSlots *slots, EventSlot *result, u8 *pendingKey)
{
    *pendingKey = slots->pendingKey;
    return EVENT_FIELD_PROCLINK_GetReturnPendingSlotSub(slots, result);
}

void EVENT_FIELD_PROCLINK_ClearReturnResultSlot(EventSlots *slots, int index)
{
    EVENT_FIELD_PROCLINK_ClearReturnResultSlotSub(slots, index);
}

/*
 * The full target body overwrites r1/r2 with 0/8 before use; neither
 * caller nor thunk supplies those legacy trailing parameters.
 */
void EVENT_FIELD_PROCLINK_ClearReturnPendingSlotThunk(EventSlots *slots)
{
    EVENT_FIELD_PROCLINK_ClearReturnPendingSlot(slots);
}

void EVENT_FIELD_PROCLINK_RequestReturn(EventSlots *slots, int entryId, int handlerIndex)
{
    EventSlot slot;
    int handlerType;

    if (EVENT_FIELD_PROCLINK_IsNetConnected((int)slots) == 0) {
        EVENT_FIELD_PROCLINK_SetReturnPendingSlot(slots, entryId, handlerIndex);
        return;
    }
    handlerType = d_0217144C[handlerIndex];
    if (handlerType != 4) {
        slot.key = slots->key;
        slot.entryId = entryId;
        slot.handlerType = handlerType;
        EVENT_FIELD_PROCLINK_SetReturnSlotDefault(slots, &slot);
    }
}

/*
 * Unlabelled Thumb leaf (no lr save, prints as .word data in the listing),
 * called from ov020 FIELD_WFBC_DATA_LOCAL_PersonTalkEventMain.
 */
int EVENT_FIELD_PROCLINK_HasReturnDefaultSlot(EventSlots *slots, int unused)
{
    if (slots->flags & 8)
        return 1;
    return 0;
}

u16 EVENT_FIELD_PROCLINK_GetReturnDefaultSlotType(EventSlots *slots)
{
    return slots->defaultSlot.handlerType;
}

void EVENT_FIELD_PROCLINK_ClearReturnDefaultAndPending(EventSlots *slots)
{
    EVENT_FIELD_PROCLINK_ClearReturnPendingSlot(slots);
    EVENT_FIELD_PROCLINK_ClearReturnDefaultSlot(slots);
}

#pragma opt_propagation off

/*
 * The list is compacted: each empty 0x18-byte entry takes the next
 * used entry after it. The copy destination is written through a second base name dst (= p) under
 * pragma opt_propagation off, so `i * 0x18` is a common subexpression of two different bases. The
 * front end then makes the offset its own temporary local, which takes the stack slot below the
 * named counter i (sp+0 under sp+4), as in the image. With one base name the offset was a back-end
 * spill temporary above i (7 B, 92/92); without the pragma dst folds into p (7 B).
 */
void EVENT_FIELD_PROCLINK_CompactEntryList(char *entries)
{
    int i;
    int j;
    char *dst;

    dst = entries;
    i = 0;
    do {
        if (EVENT_FIELD_PROCLINK_IsReturnEntryValid((ProcLinkEntry *)(entries + i * 0x18)) == 0) {
            for (j = i + 1; j < 10; j++) {
                if (EVENT_FIELD_PROCLINK_IsReturnEntryValid((ProcLinkEntry *)(entries + j * 0x18)) != 0) {
                    MI_CpuCopy8(entries + j * 0x18, dst + i * 0x18, 0x18);
                    EVENT_FIELD_PROCLINK_ClearReturnEntry((ProcLinkEntry *)(entries + j * 0x18));
                    break;
                }
            }
        }
        i++;
    } while (i < 10);
}

#pragma opt_propagation reset

int EVENT_FIELD_PROCLINK_IsNetConnected(int unused)
{
    if (GFL_NET_ERR_GetErrorLevel() == 0)
        return 0;
    return 1;
}

void EVENT_FIELD_PROCLINK_RunReturnSlots(EventSlots *slots, ProcLinkSys *procLink, int slotMask)
{
    EventSlot result;
    EventSlot slot;
    int i;
    int handled;

    for (i = 0; i < 3; i++) {
        if ((slotMask & (1 << i)) == 0) {
            EVENT_FIELD_PROCLINK_ClearReturnSlot(slots, (u16)i);
        } else if (EVENT_FIELD_PROCLINK_GetReturnSlot(slots, i, &slot) != 0) {
            handled = d_02172990[slot.handlerType](slots, procLink, &slot, &result);
            EVENT_FIELD_PROCLINK_ClearReturnSlot(slots, (u16)i);
            if (handled != 0)
                EVENT_FIELD_PROCLINK_SetReturnResultSlot(slots, (u16)i, result.entryId, result.handlerType);
        }
    }
}

int EVENT_FIELD_PROCLINK_HandlerCheckEntryGrid(EventSlots *slots, ProcLinkSys *procLink, const EventSlot *slot, EventSlot *result)
{
    result->key = slot->key;
    result->entryId = slot->entryId;
    if (EVENT_FIELD_PROCLINK_GetEventdataEntry(procLink, slot->entryId, 1) != 0) result->handlerType = 0;
    else result->handlerType = 1;
    return 1;
}

int EVENT_FIELD_PROCLINK_HandlerCheckEntryRail(EventSlots *slots, ProcLinkSys *procLink, const EventSlot *slot, EventSlot *result)
{
    result->key = slot->key;
    result->entryId = slot->entryId;
    if (EVENT_FIELD_PROCLINK_GetEventdataEntry(procLink, slot->entryId, 1) != 0) result->handlerType = 2;
    else result->handlerType = 3;
    return 1;
}

int EVENT_FIELD_PROCLINK_HandlerRemoveEntry(EventSlots *slots, ProcLinkSys *procLink, const EventSlot *slot)
{
    ProcLinkEntry *entry;

    entry = EVENT_FIELD_PROCLINK_GetEventdataEntry(procLink, slot->entryId, 1);
    if (entry != 0) {
        EVENT_FIELD_PROCLINK_ClearReturnEntry(entry);
        EVENT_FIELD_PROCLINK_CompactReturnList(procLink, 1);
    }
    return 0;
}

void EVENT_FIELD_PROCLINK_SetReturnSlotDefault(EventSlots *slots, EventSlot *slot)
{
    if (slot->key == slots->key) {
        MI_CpuCopy8(slot, &slots->defaultSlot, 8);
        slots->flags |= 8;
    }
}

/*
 * note:     caller 0x02162008 forwards all three of its arguments unchanged
 *           (r0-r2); the copy is MI_CpuCopy8-shaped (src, dst, 8) into the
 *           index-th eight-byte slot after an 8-byte head, then bit index of
 *           the u16 at +2 is set.
 */
void EVENT_FIELD_PROCLINK_SetReturnSlot(EventSlots *slots, int index, EventSlot *slot)
{
    MI_CpuCopy8(slot, &slots->slot[index], 8);
    slots->flags = (u16)(slots->flags | (1 << index));
}

int EVENT_FIELD_PROCLINK_GetReturnSlot(EventSlots *slots, u16 index, EventSlot *out)
{
    int result = 0;
    if (slots->flags & (1 << index)) {
        MI_CpuCopy8(&slots->slot[index], out, 8);
        result = 1;
    }
    return result;
}

void EVENT_FIELD_PROCLINK_SetReturnResultSlot(EventSlots *slots, int index, u16 entryId, u16 handlerType)
{
    slots->resultSlot[index].key = index;
    slots->resultSlot[index].entryId = entryId;
    slots->resultSlot[index].handlerType = handlerType;
    slots->flags = (u16)(slots->flags | (1 << (index + 5)));
}

void EVENT_FIELD_PROCLINK_SetReturnPendingSlot(EventSlots *slots, int entryId, int handlerType)
{
    int pendingKey;
    int flags;

    slots->pendingSlot.handlerType = handlerType;
    pendingKey = slots->pendingKey;
    slots->pendingSlot.entryId = entryId;
    flags = slots->flags;
    slots->pendingSlot.key = pendingKey;
    slots->flags = flags | 0x10;
}

int EVENT_FIELD_PROCLINK_GetReturnResultSlotSub(EventSlots *slots, int index, EventSlot *out)
{
    int result = 0;
    if (slots->flags & (1 << (index + 5))) {
        MI_CpuCopy8(&slots->resultSlot[index], out, 8);
        result = 1;
    }
    return result;
}

int EVENT_FIELD_PROCLINK_GetReturnPendingSlotSub(EventSlots *slots, EventSlot *out)
{
    int result = 0;
    if (slots->flags & 16) {
        MI_CpuCopy8(&slots->pendingSlot, out, 8);
        result = 1;
    }
    return result;
}

void EVENT_FIELD_PROCLINK_ClearReturnDefaultSlot(EventSlots *slots)
{
    MI_CpuFill8(&slots->defaultSlot, 0, 8);
    slots->flags = slots->flags & ~8;
}

/*
 * domain: Primary calls at 0216213C/0216216E receive loop index 0..2
 *   from 02162120 (zero at 0216212A; increment/test at 02162188..18C).
 *   ov011 02172D70 passes Work+0x35C through 02161F74 to 02162120.
 *   02172BC0 allocates 0x94C bytes and initializes that 0x48-byte record
 *   with 02161F54. The clear spans offsets 8..31; the mask reads offset 2.
 *   Thus primary shift counts 0..2 are defined; no arbitrary-u32 domain claim.
 */
void EVENT_FIELD_PROCLINK_ClearReturnSlot(EventSlots *slots, unsigned index) { MI_CpuFill8(&slots->slot[index],0,8); slots->flags = slots->flags & ~(1<<index); }

/*
 * domain: Primary ov011 call 02174C8C reaches this through thunk 02162038.
 *   Its byte counter is zeroed at 02174C64..68, loaded at 02174C88, and
 *   increments/tests against 3 at 02174C90..9A: index 0..2, shifts 5..7.
 *   The record is Work+0x35C (02174C62/6A/8A); 02172BC0 allocates
 *   0x94C bytes and 02161F54 initializes this 0x48-byte record.
 *   Clears cover offsets 0x30..0x47; mask halfword offset 2 is initialized.
 *   No arbitrary-u32 domain claim: all primary arithmetic stays in range.
 */
void EVENT_FIELD_PROCLINK_ClearReturnResultSlotSub(EventSlots *slots, unsigned index) { MI_CpuFill8(&slots->resultSlot[index],0,8); slots->flags = slots->flags & ~(1<<(index+5)); }

void EVENT_FIELD_PROCLINK_ClearReturnPendingSlot(EventSlots *slots)
{
    MI_CpuFill8(&slots->pendingSlot, 0, 8);
    slots->flags = slots->flags & ~0x10;
}

/*
 * Predicate: is the argument >= 7.
 *
 * Addresses are Black-image addresses.
 */
int EVENT_FIELD_PROCLINK_IsSlotIndexOutOfRange(int value)
{
    return value >= 7;
}

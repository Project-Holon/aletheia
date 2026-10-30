/*
 * file:     beacon_status.c
 * unit:     yes
 * function: BEACON_STATUS_Create, BEACON_STATUS_Delete, BEACON_STATUS_GetLog, BEACON_STATUS_GetViewTop, BEACON_STATUS_SetViewTop, BEACON_STATUS_GetMessage, BEACON_STATUS_GetViewFlags, BEACON_STATUS_IsLocked, BEACON_STATUS_DoNothing
 * address:  0x0202751C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from app_taskmenu.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   STRBUF_Create       0x020457B0  arm
 *   MSGDATA_CreateFromArchive       0x02045B38  arm
 *   MSGDATA_AllocString       0x02045EC0  arm
 *   STRBUF_ToChars       0x02045A38  arm
 *   STRBUF_SetString       0x02045924  arm
 *   STRBUF_Delete       0x02045808  arm
 *   MSGDATA_Delete       0x02045C04  arm
 *   beacon_status_File  0x020A74D0  data
 *   GFL_HEAP_Free  0x020307B0  arm
 */
#include "beacon_status_shared_types.h"
#include "../version.h"

struct MsgData;         /* opened message bank */

/* ------------------------------------------------------------------ */
/* beacon_status.c                                                     */
/* ------------------------------------------------------------------ */

/* 0xB10 bytes, allocated with the beacon_status.c __FILE__ string. */
typedef struct BeaconStatus {
    u8 log[0xB08];              /* +0x000 beacon log area (handed out whole) */
    struct Strbuf *message;     /* +0xB08 9-character string from message 0x11 */
    u16 viewFlags;              /* +0xB0C handed out by address */
    u8 viewTop;                 /* +0xB0E top row of the beacon log view */
    u8 pad_B0F;
} BeaconStatus;

#include "mi_memory.h"

#include "gfl_heap_wrap.h"
struct Strbuf;

#include "strbuf.h"
struct MsgBank;

#include "msgdata.h"







BeaconStatus *BEACON_STATUS_Create(u32 heapId, u32 msgHeapId);

void BEACON_STATUS_Delete(BeaconStatus *bs);

u8 *BEACON_STATUS_GetLog(BeaconStatus *bs);

u8 BEACON_STATUS_GetViewTop(BeaconStatus *bs);

void BEACON_STATUS_SetViewTop(BeaconStatus *bs, int top);

struct Strbuf *BEACON_STATUS_GetMessage(BeaconStatus *bs);

u16 *BEACON_STATUS_GetViewFlags(BeaconStatus *bs);

int BEACON_STATUS_IsLocked(void);

void BEACON_STATUS_DoNothing(void);

extern const char beacon_status_File[];

/* ================================================================== */
/* beacon_status.c                                                     */
/* ================================================================== */

/*
 * Allocate the cleared beacon status work and fill its 9-character string
 * with message 0x11 of bank 8.
 */
/* Message archive member of the beacon status texts. */
#if LANGUAGE == LANGUAGE_JAPANESE
#define BEACON_STATUS_MSG_MEMBER 11
#else
#define BEACON_STATUS_MSG_MEMBER 8
#endif

BeaconStatus *BEACON_STATUS_Create(u32 heapId, u32 msgHeapId)
{
    BeaconStatus *bs;
    struct MsgData *msgData;
    struct Strbuf *str;
    u16 code[10];

    bs = GFL_HEAP_Alloc(heapId, sizeof(BeaconStatus), 1, beacon_status_File, 42);
    bs->message = (struct Strbuf *)STRBUF_Create(9, heapId);
    msgData = (struct MsgData *)MSGDATA_CreateFromArchive(0, 2, BEACON_STATUS_MSG_MEMBER, msgHeapId);
    str = (struct Strbuf *)MSGDATA_AllocString((struct MsgBank *)msgData, 0x11);
    STRBUF_ToChars((struct Strbuf *)str, code, 9);
    STRBUF_SetString((struct Strbuf *)bs->message, code);
    STRBUF_Delete((struct Strbuf *)str);
    MSGDATA_Delete((struct MsgBank *)msgData);
    return bs;
}

void BEACON_STATUS_Delete(BeaconStatus *bs)
{
    STRBUF_Delete((struct Strbuf *)bs->message);
    MI_CpuFill8(bs, 0, sizeof(BeaconStatus));
    GFL_HEAP_Free(bs);
}

u8 *BEACON_STATUS_GetLog(BeaconStatus *bs)
{
    return bs->log;
}

u8 BEACON_STATUS_GetViewTop(BeaconStatus *bs)
{
    return bs->viewTop;
}

void BEACON_STATUS_SetViewTop(BeaconStatus *bs, int top)
{
    bs->viewTop = top;
}

struct Strbuf *BEACON_STATUS_GetMessage(BeaconStatus *bs)
{
    return bs->message;
}

u16 *BEACON_STATUS_GetViewFlags(BeaconStatus *bs)
{
    return &bs->viewFlags;
}

int BEACON_STATUS_IsLocked(void)
{
    return 0;
}

void BEACON_STATUS_DoNothing(void)
{
}

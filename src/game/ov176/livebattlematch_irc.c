/*
 * file:     livebattlematch_irc.c
 * unit:     yes
 * function: LIVEBATTLEMATCH_IRC_ShowMenu, LIVEBATTLEMATCH_IRC_CreateWindow, LIVEBATTLEMATCH_IRC_DeleteWindow, LIVEBATTLEMATCH_IRC_PollWindowResult, LIVEBATTLEMATCH_IRC_SetMenuValue, LIVEBATTLEMATCH_IRC_GetMenuValue, LIVEBATTLEMATCH_IRC_ToggleSe, LIVEBATTLEMATCH_IRC_DeleteMenuRecord, LIVEBATTLEMATCH_IRC_Create, LIVEBATTLEMATCH_IRC_Delete, LIVEBATTLEMATCH_IRC_NoOp, LIVEBATTLEMATCH_IRC_CheckError, LIVEBATTLEMATCH_IRC_InitState, LIVEBATTLEMATCH_IRC_StartSession, LIVEBATTLEMATCH_IRC_Exit, LIVEBATTLEMATCH_IRC_WaitExit, LIVEBATTLEMATCH_IRC_ResetState, LIVEBATTLEMATCH_IRC_EndSession, LIVEBATTLEMATCH_IRC_SendRegulation, LIVEBATTLEMATCH_IRC_TakeRegulation, LIVEBATTLEMATCH_IRC_SendSaveData, LIVEBATTLEMATCH_IRC_RecvSaveData, LIVEBATTLEMATCH_IRC_SendSyncValue, LIVEBATTLEMATCH_IRC_RecvSyncValue, LIVEBATTLEMATCH_IRC_CreateDelivery, LIVEBATTLEMATCH_IRC_DeliveryMain, LIVEBATTLEMATCH_IRC_ClearState, LIVEBATTLEMATCH_IRC_DeliveryEnd, LIVEBATTLEMATCH_IRC_RecvHandler0, LIVEBATTLEMATCH_IRC_RecvHandler1, LIVEBATTLEMATCH_IRC_RecvHandler2, LIVEBATTLEMATCH_IRC_RecvHandler3, LIVEBATTLEMATCH_IRC_RecvHandler4, LIVEBATTLEMATCH_IRC_OnFilter
 * address:  0x0217DEA4
 * region:   ov176
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * leaf: callback blocker of LIVEBATTLEMATCH_IRC_StartSession
 *
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_DrawStatusWindow 0x021E5F24 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_DrawDateWindow 0x021E62CC thumb ov177
 *   MI_CpuFill8 0x02082BCC arm
 *   WIFIBATTLEMATCH_UTIL_CreateMenu 0x021E88B0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_DeleteMenu  0x021E89D0  thumb  ov177
 *   WIFIBATTLEMATCH_UTIL_UpdateMenu  0x021E8A00  thumb  ov177
 *   WIFIBATTLEMATCH_UTIL_PrintMessage  0x021E8738  thumb  ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   WIFIBATTLEMATCH_UTIL_ClearBmp 0x021E8870 thumb ov177
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_0217E634 0x0217E634 data a1
 *   d_0217E544 0x0217E544 data a4
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   DELIVERY_IRC_Delete 0x02157E8C thumb ov010
 *   GFL_NET_ERR_WaitLinkClosed 0x0200FBB0 thumb
 *   GFL_NET_ERR_ShowSimpleScreen 0x0200F83C thumb
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   IRCNET_SetFilter 0x021799C0 thumb ov015
 *   GFL_NET_StartChangeoverChild 0x0203D0DC arm
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   d_0217E564 0x0217E564 data a4
 *   d_0217E630 0x0217E630 data a4
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   GAME_LANGUAGE_Code 0x0209DF0C data a1
 *   GF_PANIC_Fail 0x02034714 arm
 *   d_0217E64C 0x0217E64C data a1
 *   DELIVERY_IRC_Create 0x02157DD8 thumb ov010
 *   DELIVERY_IRC_Main 0x02157E78 thumb ov010
 *   DELIVERY_IRC_Start 0x02157E34 thumb ov010
 *   DELIVERY_IRC_GetResult 0x02157E6C thumb ov010
 *   GFL_NET_IsIdle 0x0203D210 arm
 */
#include "../ov015/ircnet.h"
#include "../version.h"
#include "livebattlematch_shared_types.h"
struct WifibattlematchUtilWork;
struct GFLNetInitializeStruct;
struct GFLNetHandle;
struct GFLNetHandle;

typedef struct {
    u32 size;               /* 00 */
    void *data;             /* 04 */
    u32 id;                 /* 08 */
    u32 mask;               /* 0C */
} IrcDeliveryEntry;

typedef struct {
    u32 netCommandBase;         /* 00 */
    u16 reserved;               /* 04 */
    u16 heapId;                 /* 06 */
    IrcDeliveryEntry entries[7];/* 08 */
    u32 entryCount;             /* 78 */
} IrcDeliveryParam;

#include "../ov177/wifibattlematch_view.h"
#include "../arm9/mi_memory.h"
/* The DS code passes the menu height as a byte (the original prototype); the definition keeps a word parameter. The host build uses the header. */
#ifdef __MWERKS__
#define WIFIBATTLEMATCH_UTIL_CreateMenu WIFIBATTLEMATCH_UTIL_CreateMenu_header
#endif
#include "../ov177/wifibattlematch_util.h"
#ifdef __MWERKS__
#undef WIFIBATTLEMATCH_UTIL_CreateMenu
extern WifibattlematchMenu *WIFIBATTLEMATCH_UTIL_CreateMenu(const WifibattlematchMenuDesc *p, u8 x, u8 y, u8 width, u8 height, u16 heap);
#endif
struct WifibattlematchMenu;
#include "../arm9/bg_sys.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/net.h"
struct DeliveryIrcWork;
#include "../arm9/net_command.h"
#include "../types.h"
#include "../arm9/net_err.h"
#include "../ov010/delivery_irc.h"
struct GFLNetInitializeStruct;
                            
#include "../arm9/net_handle.h"
#include "../arm9/poke_regulation.h"
struct GFLNetHandle;
struct DeliveryIrcParam;
#include "../arm9/gf_panic.h"
struct DeliveryIrcWork;
struct DeliveryIrcWork;
struct DeliveryIrcWork;
#include "livebattlematch_irc.h"
extern const char d_0217E634[];
extern NetCommandEntry d_0217E544[];
extern const unsigned d_0217E564[];
extern int d_0217E630;
extern unsigned char GAME_LANGUAGE_Code;
extern const char d_0217E64C[];

void LIVEBATTLEMATCH_IRC_ShowMenu(LivebattlematchRequest *p, int a) {if(p->config.slot==0)WIFIBATTLEMATCH_VIEW_DrawStatusWindow(p->record,a,p->msgBank,p->config.printQue,p->config.font,p->heap);else WIFIBATTLEMATCH_VIEW_DrawDateWindow(p->record,a,p->msgBank,p->config.printQue,p->config.font,p->heap);}

/*
 * E88B0 returns its allocated record; original call truncates four coordinates to bytes.
 */
void LIVEBATTLEMATCH_IRC_CreateWindow(LivebattlematchRequest *p, int mode)
{
    WifibattlematchMenuDesc rec;
    int layout, x, y, width, height;
    if (p->window == 0) {
        MI_CpuFill8(&rec, 0, sizeof(rec));
        rec.msgBank = p->msgBank;
        rec.font = p->config.font;
        rec.printQue = p->config.printQue;
        rec.a = 0; rec.b = 15; rec.c = 13; rec.d = 1;
        switch (mode) {
        case 0:
            rec.items[0] = 0x76; rec.items[1] = 0x77; rec.count = 2;
            rec.enabled = 1; rec.kind = 1; layout = 0; rec.row = 1; break;
        case 1:
            rec.items[0] = 0x74; rec.count = 1; rec.enabled = 1; rec.kind = 0;
            layout = 0; break;
        case 2:
            rec.items[0] = 0x75; rec.items[1] = 0x74; rec.count = 2;
            rec.enabled = 1; rec.kind = 1; layout = 1; rec.row = 1; break;
        }
        switch (layout) {
        case 0: height = rec.count * 2; width = 12; x = 19; y = 17 - height; break;
        case 1: height = rec.count * 2; width = 15; x = 16; y = 17 - height; break;
        }
        p->window = WIFIBATTLEMATCH_UTIL_CreateMenu(&rec, x, y, width, height, p->heap);
    }
}

void LIVEBATTLEMATCH_IRC_DeleteWindow(LivebattlematchRequest *p)
{
    if (p->window) {
        WIFIBATTLEMATCH_UTIL_DeleteMenu(p->window);
        p->window = 0;
    }
}

int LIVEBATTLEMATCH_IRC_PollWindowResult(LivebattlematchRequest *p)
{
    if (p->window)
        return WIFIBATTLEMATCH_UTIL_UpdateMenu(p->window);
    return -1;
}

void LIVEBATTLEMATCH_IRC_SetMenuValue(LivebattlematchRequest *p, int a, int b)
{
    WIFIBATTLEMATCH_UTIL_PrintMessage(p->config.printSys, p->msgBank, a, b);
}

int LIVEBATTLEMATCH_IRC_GetMenuValue(LivebattlematchRequest *p) {return WIFIBATTLEMATCH_UTIL_GetBusy(p->config.printSys);}

/*
 * Extent runs long: 0x0217E000 is an unlabelled follower leaf, so EXACT*.
 */
void LIVEBATTLEMATCH_IRC_ToggleSe(int unused, int visible)
{
    BG_SYS_SetPlaneVisible(0, (unsigned char)visible);
}

/*
 * Unlabelled blocker leaf for DA38 and DB0C; parent confirmed unowned.
 */
void LIVEBATTLEMATCH_IRC_DeleteMenuRecord(LivebattlematchRequest *p)
{
    WIFIBATTLEMATCH_UTIL_ClearBmp(p->config.printSys);
}

struct LiveBattleMatchIrcWork *LIVEBATTLEMATCH_IRC_Create(struct GameData *unused, u16 heap)
{
    struct LiveBattleMatchIrcWork *p = GFL_HEAP_Alloc(heap, sizeof(*p), 0, d_0217E634, 0x8E);
    MI_CpuFill8(p, 0, sizeof(*p));
    p->heap = heap;
    if (GFL_NET_GetRunState())
        GFL_NET_COMMAND_AddCommandTable(0x1F00, d_0217E544, 4, p);
    return p;
}

void LIVEBATTLEMATCH_IRC_Delete(struct LiveBattleMatchIrcWork *p)
{
    if (GFL_NET_GetRunState())
        GFL_NET_COMMAND_DeleteCommandTable(0x1f00);
    GFL_HEAP_Free(p);
}

void LIVEBATTLEMATCH_IRC_NoOp(void *unused) {}

int LIVEBATTLEMATCH_IRC_CheckError(struct LiveBattleMatchIrcWork *p) {if(GFL_NET_ERR_GetErrorLevel()!=0) {if(p->delivery!=0) {DELIVERY_IRC_Delete(p->delivery);p->delivery=0;}GFL_NET_ERR_WaitLinkClosed();GFL_NET_ERR_ShowSimpleScreen();return 1;}return 0;}

int LIVEBATTLEMATCH_IRC_InitState(struct LiveBattleMatchIrcWork *p){p->state=0;return 1;}

int LIVEBATTLEMATCH_IRC_StartSession(struct LiveBattleMatchIrcWork *p)
{
    switch (p->state) {
    case 0:
        GFL_NET_StartSession((struct GFLNetInitializeStruct *)d_0217E564, 0, 0);
        d_0217E630 = 1;
        p->state = 1;
        break;
    case 1:
        if (GFL_NET_GetRunState())
            p->state = 2;
        break;
    case 2:
        GFL_NET_COMMAND_AddCommandTable(0x1F00, d_0217E544, 4, p);
        IRCNET_SetFilter(LIVEBATTLEMATCH_IRC_OnFilter);
        p->state = 3;
        break;
    case 3:
        GFL_NET_StartChangeoverChild(0);
        p->state = 4;
        break;
    case 4:
        if (GFL_NET_GetNegotiationNum() > 1)
            p->state = 5;
        if (d_0217E630 == 0)
            p->state = 6;
        break;
    case 5:
        IRCNET_SetFilter(0);
        return 1;
    case 6:
        IRCNET_SetFilter(0);
        return 2;
    }
    return 0;
}

void LIVEBATTLEMATCH_IRC_Exit(struct LiveBattleMatchIrcWork *p) {int n;if(p->state>=2)GFL_NET_COMMAND_DeleteCommandTable(0x1f00);n=0;IRCNET_SetFilter(0);p->state=n;}

int LIVEBATTLEMATCH_IRC_WaitExit(struct LiveBattleMatchIrcWork *p)
{
    switch (p->state) {
    case 0:
        if (GFL_NET_GetRunState()) {
            GFL_NET_Exit(0);
            p->state = 1;
        } else {
            p->state = 2;
        }
        break;
    case 1:
        if (GFL_NET_IsSessionNull())
            p->state = 2;
        break;
    case 2:
        return 1;
    }
    return 0;
}

int LIVEBATTLEMATCH_IRC_ResetState(struct LiveBattleMatchIrcWork *p) { p->state = 0; return 1; }

int LIVEBATTLEMATCH_IRC_EndSession(struct LiveBattleMatchIrcWork *p) {switch (p->state) {case 0:GFL_NET_COMMAND_DeleteCommandTable(0x1f00);GFL_NET_Exit(0);p->state=1;break;case 1:if(GFL_NET_IsSessionNull())p->state=2;break;case 2:return 1;}return 0;}

/*
 * extent: remaining code is the separate leaf LIVEBATTLEMATCH_IRC_TakeRegulation
 */
int LIVEBATTLEMATCH_IRC_SendRegulation(struct LiveBattleMatchIrcWork *unused, void *arg)
{
    int flag;
    struct GFLNetHandle *obj;
    unsigned n;
    int r;
    r = GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()));
    flag = 1;
    if (r != 0)
        flag = 0;
    obj = GFL_NET_HANDLE_GetCurrentHandle();
    n = POKE_REGULATION_GetDataSize();
    return GFL_NET_SendData((struct GFLNetHandle *)obj, (unsigned char)flag, (int)0x1F00, n + 0xD4, arg, (int)1, (int)1, (int)1);
}

/*
 * leaf: follower of LIVEBATTLEMATCH_IRC_SendRegulation
 */
int LIVEBATTLEMATCH_IRC_TakeRegulation(struct LiveBattleMatchIrcWork *p, void **out)
{
    int value = p->recvFlag0;
    if (value) {
        p->recvFlag0 = 0;
        *out = p->data;
    }
    return value;
}

int LIVEBATTLEMATCH_IRC_SendSaveData(struct LiveBattleMatchIrcWork *unused, void *arg)
{
    int flag;
    struct GFLNetHandle *obj;
    unsigned n;
    int r;
    r = GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle());
    flag = 1;
    if (r != 0)
        flag = 0;
    obj = GFL_NET_HANDLE_GetCurrentHandle();
    n = POKE_REGULATION_GetDataSize();
    return GFL_NET_SendData(obj, (unsigned char)flag, (int)0x1F01, n, arg, (int)1, (int)1, (int)1);
}

int LIVEBATTLEMATCH_IRC_RecvSaveData(struct LiveBattleMatchIrcWork *p,const void *q) {int v;v=p->recvFlag1;if(v) {p->recvFlag1=0;MI_CpuCopy8(p->data,(void *)q,POKE_REGULATION_GetDataSize());}return v;}

u32 LIVEBATTLEMATCH_IRC_SendSyncValue(struct LiveBattleMatchIrcWork *unused,void *a) {int flag;int v;v=GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()));flag=1;if(v!=0)flag=0;return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(),(u8)flag,0x1f03,4,a,(int)1,(int)1,(int)1);}

int LIVEBATTLEMATCH_IRC_RecvSyncValue(struct LiveBattleMatchIrcWork *p,const void *q) {int v;v=p->recvFlag3;if(v) {p->recvFlag3=0;MI_CpuCopy8(p->data,(void *)q,4);}return v;}

void LIVEBATTLEMATCH_IRC_CreateDelivery(struct LiveBattleMatchIrcWork *p, void *value)
{
    IrcDeliveryParam config;
    MI_CpuFill8(&config, 0, sizeof(config));
    config.netCommandBase = 0x30;
    config.entries[0].size = 0x160;
    config.entries[0].data = value;
    config.reserved = 0;
    config.heapId = p->heap;
    config.entries[0].id = GAME_LANGUAGE_Code;
    config.entries[0].mask = PM_VERSION_MASK;
    config.entryCount = 1;
    if (p->delivery)
        GF_PANIC_Fail(d_0217E64C, 0, d_0217E64C);
    p->delivery = DELIVERY_IRC_Create((struct DeliveryIrcParam *)(&config));
    p->state = 0;
}

/*
 * extent: two alignment bytes follow LIVEBATTLEMATCH_IRC_ClearState
 */
int LIVEBATTLEMATCH_IRC_DeliveryMain(struct LiveBattleMatchIrcWork *p)
{
    if (p->delivery)
        DELIVERY_IRC_Main(p->delivery);
    switch (p->state) {
    case 0:
        DELIVERY_IRC_Start(p->delivery);
        (p->state)++;
        break;
    case 1:
        p->deliveryResult = DELIVERY_IRC_GetResult(p->delivery);
        if (p->deliveryResult)
            (p->state)++;
        break;
    case 2:
        DELIVERY_IRC_Delete(p->delivery);
        p->delivery = 0;
        (p->state)++;
        break;
    case 3:
        if (GFL_NET_IsIdle()) {
            switch (p->deliveryResult) {
            case 1: return 1;
            case 3: return 3;
            case 2: break;
            }
            return 2;
        }
        break;
    }
    return 0;
}

void LIVEBATTLEMATCH_IRC_ClearState(struct LiveBattleMatchIrcWork *p) { p->state = 0; }

int LIVEBATTLEMATCH_IRC_DeliveryEnd(struct LiveBattleMatchIrcWork *p)
{
    if (p->delivery)
        DELIVERY_IRC_Main(p->delivery);
    switch (p->state) {
    case 0:
        if (p->delivery) {
            DELIVERY_IRC_Delete(p->delivery);
            p->delivery = 0;
        }
        (p->state)++;
        break;
    case 1:
        if (GFL_NET_IsIdle())
            return 1;
        break;
    }
    return 0;
}

void LIVEBATTLEMATCH_IRC_RecvHandler0(u32 a, void *b, void *c, struct LiveBattleMatchIrcWork *p, struct GFLNetHandle *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
            p->recvFlag0 = 1;
    }
}

void LIVEBATTLEMATCH_IRC_RecvHandler1(u32 a, void *b, void *c, struct LiveBattleMatchIrcWork *p, struct GFLNetHandle *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
            p->recvFlag1 = 1;
    }
}

void LIVEBATTLEMATCH_IRC_RecvHandler2(u32 a, void *b, void *c, struct LiveBattleMatchIrcWork *p, struct GFLNetHandle *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
            p->recvFlag2 = 1;
    }
}

void LIVEBATTLEMATCH_IRC_RecvHandler3(u32 a, void *b, void *c, struct LiveBattleMatchIrcWork *p, struct GFLNetHandle *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
            p->recvFlag3 = 1;
    }
}

int LIVEBATTLEMATCH_IRC_RecvHandler4(int a, int b)
{
    if (a == GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle())) {
        GF_PANIC_Fail(d_0217E64C, 0, d_0217E64C);
        return 0;
    }
    return b + 6;
}

int LIVEBATTLEMATCH_IRC_OnFilter(int a, int b) { int value = a == b; d_0217E630 = value; return value; }

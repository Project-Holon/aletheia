/*
 * file:     sta_net.c
 * unit:     yes
 * function: STA_NET_FindRecValueByKey, STA_NET_BeginTransfer, STA_NET_UpdateTransferState, STA_NET_SendChunk, STA_NET_AdvanceChunk, STA_NET_GetChunkPtr, STA_NET_IsTransferDone, STA_NET_NotifyHostKind4, STA_NET_NotifyHostKind5, STA_NET_NotifyHostKind6, STA_NET_SendSlot1Command, STA_NET_SetSlot1Done, STA_NET_GetSlot1Value, STA_NET_SendSlot2Command, STA_NET_SetSlot2Done, STA_NET_GetSlot2Value, STA_NET_SendSlot3Command, STA_NET_SetSlot3Done, STA_NET_GetSlot3Value, STA_NET_GetSlot1Done, STA_NET_GetSlot3Done, STA_NET_SendRandomOrder, STA_NET_SendKindA, STA_NET_GetCurrentSlotValue, STA_NET_GetSlotValueByIndex, STA_NET_GetSlotWordByIndex, STA_NET_GetRole, STA_NET_GetBoxesReceived, STA_NET_GetRecordsReceived, STA_NET_SetState6Pair, STA_NET_BeginKind5Phase, STA_NET_SetState18Value, STA_NET_GetPairA, STA_NET_GetPairB
 * address:  0x021FD4F8
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MUS_COMM_FUNC_SendCommandWait 0x021FCEA8 thumb ov132
 *   _u32_div_f 0x0209C2B0 arm
 *   GFL_NET_HANDLE_GetNetHandle 0x0203996C arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   STA_SLOT_Noop 0x021FDA74 thumb ov132
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   MUS_COMM_FUNC_SendCommand  0x021FCE74  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   MUS_COMM_FUNC_SetTimingSync 0x021FCDEC thumb ov132
 */
#include "ov132_types.h"

struct Entry;
struct Link;
#include "../types.h"

struct StaNetRec {
    u8 pad00[4];
    int state;
    u8 pad08[0x0A];
    u8 id;
    u8 pad13[9];
    u32 partyBuffer;
    u8 pad20[0x10];
};

struct StaNetCtx {
    u8 pad00[0x60];
    struct StaNetRec rec[4];
};

typedef struct StaNetWork {
    u8 pad00[0x14C];
    u8 chunkIndex;
    int transferActive;
    int chunkSending;
    u8 pad158[0x24];
    int transferState;
} StaNetWork;

#include "mus_comm_func.h"
struct GFLNetHandle;
#include "../arm9/net_handle.h"
#include "../arm9/net.h"
#include "sta_slot.h"
#include "../arm9/gf_standard.h"
u32 STA_NET_FindRecValueByKey(struct StaNetCtx *p, u8 key);
void STA_NET_BeginTransfer(StaNetWork *s);
void STA_NET_UpdateTransferState(char *p);
int STA_NET_SendChunk(char *p,u32 i);
void STA_NET_AdvanceChunk(int a,int b,int c,char *p);
void *STA_NET_GetChunkPtr(int a,char *p);
int STA_NET_IsTransferDone(char *p);
int STA_NET_NotifyHostKind4(u8 *p);
int STA_NET_NotifyHostKind5(char *p);
int STA_NET_NotifyHostKind6(char *p);
int STA_NET_SendSlot1Command(u8 *p);
void STA_NET_SetSlot1Done(void *a, void *b, void *c, u8 *p);
u32 STA_NET_GetSlot1Value(void *a, u8 *p);
int STA_NET_SendSlot2Command(u8 *p);
void STA_NET_SetSlot2Done(void *a, void *b, void *c, u8 *p);
u32 STA_NET_GetSlot2Value(void *a, u8 *p);
int STA_NET_SendSlot3Command(u8 *p);
void STA_NET_SetSlot3Done(void *a, void *b, void *c, u8 *p);
u32 STA_NET_GetSlot3Value(void *a, u8 *p);
u32 STA_NET_GetSlot1Done(char *p);
int STA_NET_GetSlot3Done(int *p);
int STA_NET_SendRandomOrder(u8 *p);
u32 STA_NET_SendKindA(char *p, int a);
u32 STA_NET_GetCurrentSlotValue(char *p);
u8 STA_NET_GetSlotValueByIndex(char *p, int index);
u32 STA_NET_GetSlotWordByIndex(char *p,u32 index);
int STA_NET_GetRole(int *p);
u32 STA_NET_GetBoxesReceived(u8 *p);
int STA_NET_GetRecordsReceived(int *p);
void STA_NET_SetState6Pair(char *p, u32 a, int b);
void STA_NET_BeginKind5Phase(char *p);
void STA_NET_SetState18Value(char *p,u32 value);
u32 STA_NET_GetPairA(char *p);
u32 STA_NET_GetPairB(char *p);

/*
 * 2026-10-05 (wave D9): witness leaf for ov010 MUSICAL_EVENT_RollProgramRewards. Searches the
 * four 48-byte records at +0x60 for one whose id byte (+0x12) equals the key
 * and whose state word (+4) is 1; returns its word at +0x1C, else 0.
 */
u32 STA_NET_FindRecValueByKey(struct StaNetCtx *p, u8 key)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        if (key == p->rec[i].id && p->rec[i].state == 1)
            return p->rec[i].partyBuffer;
    }
    return 0;
}

/*
 * Unlabelled leaf hidden in a .word run; helper whose address is the
 * witness for the call in ov010 MUSICAL_DRESSUP_SYS_Main.
 */
void STA_NET_BeginTransfer(StaNetWork *work)
{
    if (work->transferActive == 0) {
        work->transferActive = 1;
        work->chunkIndex = 0;
        work->transferState = 1;
        work->chunkSending = 0;
    }
}

void STA_NET_UpdateTransferState(char *p)
{
    if(((struct ActingHost *)p)->transferActive==1) {
        switch(*(u32 *)&((struct ActingHost *)p)->transferState) {
        case 0: break;
        case 1:
            if(MUS_COMM_FUNC_SendCommandWait((sptr)p,7,((struct HostEntry *)(*(char * *)&((struct ActingHost *)p)->hostEntry))->chunkSize,0xff)==1) ((struct ActingHost *)p)->transferState=2;
            break;
        case 2: break;
        case 3:
            if(STA_NET_SendChunk(p,((struct ActingHost *)p)->chunkIndex)==1) {
                ((struct ActingHost *)p)->chunkSending=1;
                ((struct ActingHost *)p)->transferState=4;
            }
            break;
        case 4:
            if(((struct ActingHost *)p)->chunkSending==0) {
                if((u32)(((struct ActingHost *)p)->chunkIndex*0x3800)>=((struct HostEntry *)(*(char * *)&((struct ActingHost *)p)->hostEntry))->chunkSize) ((struct ActingHost *)p)->transferActive=0;
                else ((struct ActingHost *)p)->transferState=3;
            }
            break;
        }
    }
}

/*
 * followers: own leaf files 021FD634 and 021FD68C.
 */
int STA_NET_SendChunk(char *p,u32 chunk)
{
    char *q;
    char *s;
    u16 n;
    q=*(char * *)&((struct ActingHost *)p)->hostEntry;
    n=0x3800;
    s=*(char * *)&((struct HostEntry *)q)->chunkBuffer+chunk*0x3800;
    if((chunk+1)*0x3800>((struct HostEntry *)q)->chunkSize) n=((struct HostEntry *)q)->chunkSize%0x3800U;
    return GFL_NET_SendData(GFL_NET_HANDLE_GetNetHandle(0xff),0xff,0x1105,n,s,0,1,1);
}

void STA_NET_AdvanceChunk(int unused,int unused1,int unused2,char *p)
{
    char *q;
    char *s;
    u32 v;
    (((struct ActingHost *)p)->chunkIndex)++;
    ((struct ActingHost *)p)->chunkSending=0;
    q=*(char * *)&((struct ActingHost *)p)->hostEntry;
    if((u32)(((struct ActingHost *)p)->chunkIndex*0x3800)>=((struct HostEntry *)q)->chunkSize) {
        s=*(char * *)&((struct HostEntry *)q)->chunkBuffer;
        ((struct HostEntry *)q)->body=s+0xc;
        q=*(char * *)&((struct ActingHost *)p)->hostEntry;
        ((struct HostEntry *)q)->section2=*(char * *)&((struct HostEntry *)q)->chunkBuffer+0xc+((struct StaNetChunkHeader *)s)->size;
        q=*(char * *)&((struct ActingHost *)p)->hostEntry;
        v=((struct StaNetChunkHeader *)s)->offset;
        ((struct HostEntry *)q)->section3=v+(*(u32 *)&((struct HostEntry *)q)->chunkBuffer+0xc+((struct StaNetChunkHeader *)s)->size);
    }
}

void *STA_NET_GetChunkPtr(int unused,char *p)
{
    char *q;
    q=*(char * *)&((struct ActingHost *)p)->hostEntry;
    return *(char * *)&((struct HostEntry *)q)->chunkBuffer+((struct ActingHost *)p)->chunkIndex*0x3800;
}

int STA_NET_IsTransferDone(char *p) {if(((struct HostEntry *)(*(char * *)&((struct ActingHost *)p)->hostEntry))->chunkSize/0x3800u<((struct ActingHost *)p)->chunkIndex)return 1;return 0;}

/*
 * Addresses are Black-image addresses.
 */
int STA_NET_NotifyHostKind4(u8 *p)
{
    void *q = ((struct ActingHost *)p)->hostEntry.p;
    return MUS_COMM_FUNC_SendCommandWait((sptr)p, 4, (uptr)(((struct HostEntry *)q)->slot1Size), 0xff);
}

int STA_NET_NotifyHostKind5(char *p)
{
    return MUS_COMM_FUNC_SendCommandWait((sptr)p, 5, *(int *)(((struct ActingHost *)p)->hostEntry.s + 0x24), 0xff);
}

int STA_NET_NotifyHostKind6(char *p)
{
    return MUS_COMM_FUNC_SendCommandWait((sptr)p, 6, *(int *)(((struct ActingHost *)p)->hostEntry.s + 0x28), 0xff);
}

int STA_NET_SendSlot1Command(u8 *p)
{
    u32 *q = *(u32 * *)&((struct ActingHost *)p)->hostEntry;
    uptr id;
    STA_SLOT_Noop(q[1], q[8], 2);
    id = (uptr)GFL_NET_HANDLE_GetNetHandle(255);
    return GFL_NET_SendData((struct GFLNetHandle *)id, 255, 0x1106, (*(u32 **)(p + 0x140))[8], (void *)((*(u32 **)(p + 0x140))[1]), 1, 0, 1);
}

void STA_NET_SetSlot1Done(void *unused, void *unused1, void *unused2, u8 *p)
{
    u32 *q;
    ((struct ActingHost *)p)->slot1Done = 1;
    q = *(u32 * *)&((struct ActingHost *)p)->hostEntry;
    STA_SLOT_Noop(q[1], q[8], 12);
}

u32 STA_NET_GetSlot1Value(void *unused, u8 *p)
{
    return (*(u32 **)(p + 0x140))[1];
}

int STA_NET_SendSlot2Command(u8 *p)
{
    u32 *q = *(u32 * *)&((struct ActingHost *)p)->hostEntry;
    uptr id;
    STA_SLOT_Noop(q[2], q[9], 1);
    id = (uptr)GFL_NET_HANDLE_GetNetHandle(255);
    return GFL_NET_SendData((struct GFLNetHandle *)id, 255, 0x1107, (*(u32 **)(p + 0x140))[9], (void *)((*(u32 **)(p + 0x140))[2]), 1, 0, 1);
}

void STA_NET_SetSlot2Done(void *unused, void *unused1, void *unused2, u8 *p)
{
    u32 *q;
    ((struct ActingHost *)p)->slot2Done = 1;
    q = *(u32 * *)&((struct ActingHost *)p)->hostEntry;
    STA_SLOT_Noop(q[2], q[9], 11);
}

u32 STA_NET_GetSlot2Value(void *unused, u8 *p)
{
    return (*(u32 **)(p + 0x140))[2];
}

int STA_NET_SendSlot3Command(u8 *p)
{
    u32 *q = *(u32 * *)&((struct ActingHost *)p)->hostEntry;
    uptr id;
    STA_SLOT_Noop(q[3], q[10], 0);
    id = (uptr)GFL_NET_HANDLE_GetNetHandle(255);
    return GFL_NET_SendData((struct GFLNetHandle *)id, 255, 0x1108, (*(u32 **)(p + 0x140))[10], (void *)((*(u32 **)(p + 0x140))[3]), 1, 0, 1);
}

void STA_NET_SetSlot3Done(void *unused, void *unused1, void *unused2, u8 *p)
{
    u32 *q;
    ((struct ActingHost *)p)->slot3Done = 1;
    q = *(u32 * *)&((struct ActingHost *)p)->hostEntry;
    STA_SLOT_Noop(q[3], q[10], 10);
}

u32 STA_NET_GetSlot3Value(void *unused, u8 *p)
{
    return (*(u32 **)(p + 0x140))[3];
}

u32 STA_NET_GetSlot1Done(char *p) {return ((struct ActingHost *)p)->slot1Done;}

/*
 * Unlabelled ov132 leaf hidden in a .word run: returns element 0x5e of the
 * argument viewed as an int array.  Matched to supply the `matched` witness
 * for the pending ov010 caller SCRCMD_MUSICAL_WaitSessionReady.
 */
int STA_NET_GetSlot3Done(int *p)
{
    return p[0x5e];
}

static inline u8 random4(void)
{
    u32 draw;
    draw = GF_STANDARD_Rand();
    return ((u64)draw * 4) >> 32;
}

/*
 * padding: two zero bytes at 021FD8C2 before next labelled function.
 * lever: bind the inline random draw to u32 before the multiply-high.
 */
int STA_NET_SendRandomOrder(u8 *p)
{
    u8 slots[4];
    u8 i, j, n;
    int result = 0;
    for (i = 0; i < 4; i++) slots[i] = i;
    for (n = 0; n < 10; n++) {
        for (i = 0; i < 4; i++) {
            int t;
            j = random4();
            t = slots[i];
            slots[i] = slots[j];
            slots[j] = t;
        }
    }
    for (i = 0; i < 4; i++) result += slots[i] << (i * 4);
    return MUS_COMM_FUNC_SendCommandWait((sptr)p, 1, result, 255);
}

u32 STA_NET_SendKindA(char *p, int value)
{
    return MUS_COMM_FUNC_SendCommand(p, 0xa, value, 0xff);
}

u32 STA_NET_GetCurrentSlotValue(char *p) {return *(u8 *)((uptr)p+GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle())*0x30+0x72);}

u8 STA_NET_GetSlotValueByIndex(char *p, int index) {return *(u8 *)((uptr)p+index*0x30+0x72);}

u32 STA_NET_GetSlotWordByIndex(char *p,u32 index){return *(u32 *)((uptr)p+index*0x30+0x80);}

/*
 * Unlabelled ov132 leaf hidden in a .word run: returns the word at +0x48.
 * Matched to supply the `matched` witness for the pending ov010 caller
 * MUSICAL_EVENT_CreateLocalPerformer.
 */
int STA_NET_GetRole(int *p)
{
    return ((struct ActingHost *)p)->role;
}

/*
 * Getter: returns the word at offset 0x158.
 */
u32 STA_NET_GetBoxesReceived(u8 *p)
{
 return *(u32 *)(p+0x158);
}

/*
 * Unlabelled ov132 leaf hidden in a .word run: returns element 0x57 of the
 * argument viewed as an int array.  Matched to supply the `matched` witness
 * for the pending ov010 caller SCRCMD_MUSICAL_WaitSessionFinish.
 */
int STA_NET_GetRecordsReceived(int *p)
{
    return p[0x57];
}

void STA_NET_SetState6Pair(char *p, u32 pairA, int pairB) {MUS_COMM_FUNC_SetTimingSync((sptr)p,0x40);((struct ActingHost *)p)->state=6;((struct ActingHost *)p)->pairValueA.s=pairA;((struct ActingHost *)p)->pairValueB.s=pairB;}

void STA_NET_BeginKind5Phase(char *p) {MUS_COMM_FUNC_SetTimingSync((sptr)p,0x42);((struct ActingHost *)p)->state=12;}

/*
 * The larger indexed follower at 021FD964 is parked separately at DIFF.
 */
void STA_NET_SetState18Value(char *p,u32 value){((struct ActingHost *)p)->state=18;((struct ActingHost *)p)->statusSource=value;}

u32 STA_NET_GetPairA(char *p){return ((struct ActingHost *)p)->pairValueA.u;}

u32 STA_NET_GetPairB(char *p){return ((struct ActingHost *)p)->pairValueB.u;}

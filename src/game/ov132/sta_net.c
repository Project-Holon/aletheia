/*
 * file:     sta_net.c
 * unit:     yes
 * function: STA_NET_FindRecValueByKey, STA_NET_BeginTransfer, STA_NET_UpdateTransferState, STA_NET_SendChunk, STA_NET_AdvanceChunk, STA_NET_GetChunkPtr, STA_NET_IsTransferDone, STA_NET_NotifyHostKind4, STA_NET_NotifyHostKind5, STA_NET_NotifyHostKind6, STA_NET_SendSlot1Command, STA_NET_SendSlot2Command, STA_NET_SendSlot3Command, STA_NET_GetSlot1Done, STA_NET_GetIndexedWord5E, STA_NET_SendRandomOrder, STA_NET_SendKindA, STA_NET_GetCurrentSlotValue, STA_NET_GetSlotValueByIndex, STA_NET_GetField48, STA_NET_GetField158, STA_NET_GetIndexedWord57, STA_NET_SetState6Pair, STA_NET_SetState12
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
 *   func_021FCEA8 0x021FCEA8 thumb ov132
 *   _u32_div_f 0x0209C2B0 arm
 *   GFL_NET_HANDLE_GetNetHandle 0x0203996C arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   STA_SLOT_Noop 0x021FDA74 thumb ov132
 *   func_0203F0A8 0x0203F0A8 arm
 *   func_021FCE74  0x021FCE74  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   func_021FCDEC 0x021FCDEC thumb ov132
 */
#include "ov132_types.h"

struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned int u32;

struct Rec {
    u8 pad00[4];
    int state;
    u8 pad08[0x0A];
    u8 id;
    u8 pad13[9];
    u32 f1c;
    u8 pad20[0x10];
};

struct Ctx {
    u8 pad00[0x60];
    struct Rec rec[4];
};

typedef struct S {
    u8 pad00[0x14C];
    u8 f14c;
    int f150;
    int f154;
    u8 pad158[0x24];
    int f17c;
} S;

typedef unsigned short u16;

typedef signed int     s32;

typedef unsigned long long u64;

extern u32 func_021FCEA8(int unused, int kind, u32 value, u32 id);
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void STA_SLOT_Noop(int a0, int a1, int a2);
extern u32 func_0203F0A8(void);
extern void func_021FCE74(int unused, int kind, u32 value, u32 id);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *);
extern void func_021FCDEC(int,int);
u32 STA_NET_FindRecValueByKey(struct Ctx *p, u8 key);
void STA_NET_BeginTransfer(S *s);
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
int STA_NET_GetIndexedWord5E(int *p);
int STA_NET_SendRandomOrder(u8 *p);
void STA_NET_SendKindA(char *p, int a);
u32 STA_NET_GetCurrentSlotValue(char *p);
u8 STA_NET_GetSlotValueByIndex(char *p, int index);
u32 STA_NET_GetSlotWordByIndex(char *p,u32 index);
int STA_NET_GetField48(int *p);
u32 STA_NET_GetField158(u8 *p);
int STA_NET_GetIndexedWord57(int *p);
void STA_NET_SetState6Pair(char *p, u32 a, int b);
void STA_NET_SetState12(char *p);
void STA_NET_SetState18Value(char *p,u32 value);
u32 STA_NET_GetPairA(char *p);
u32 STA_NET_GetPairB(char *p);


/*
 * 2026-10-05 (wave D9): witness leaf for ov010 MUSICAL_EVENT_RollProgramRewards. Searches the
 * four 48-byte records at +0x60 for one whose id byte (+0x12) equals the key
 * and whose state word (+4) is 1; returns its word at +0x1C, else 0.
 */
u32 STA_NET_FindRecValueByKey(struct Ctx *p, u8 key)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        if (key == p->rec[i].id && p->rec[i].state == 1)
            return p->rec[i].f1c;
    }
    return 0;
}


/*
 * Unlabelled leaf hidden in a .word run; helper whose address is the
 * witness for the call in ov010 MUSICAL_DRESSUP_SYS_Main.
 */
void STA_NET_BeginTransfer(S *s)
{
    if (s->f150 == 0) {
        s->f150 = 1;
        s->f14c = 0;
        s->f17c = 1;
        s->f154 = 0;
    }
}

void STA_NET_UpdateTransferState(char *p)
{
    if(((struct ActingHost *)p)->f150==1) {
        switch(*(u32 *)&((struct ActingHost *)p)->f17C) {
        case 0: break;
        case 1:
            if(func_021FCEA8((int)p,7,((struct HostEntry *)(*(char * *)&((struct ActingHost *)p)->f140))->f2C,0xff)==1) ((struct ActingHost *)p)->f17C=2;
            break;
        case 2: break;
        case 3:
            if(STA_NET_SendChunk(p,((struct ActingHost *)p)->f14C)==1) {
                ((struct ActingHost *)p)->f154=1;
                ((struct ActingHost *)p)->f17C=4;
            }
            break;
        case 4:
            if(((struct ActingHost *)p)->f154==0) {
                if((u32)(((struct ActingHost *)p)->f14C*0x3800)>=((struct HostEntry *)(*(char * *)&((struct ActingHost *)p)->f140))->f2C) ((struct ActingHost *)p)->f150=0;
                else ((struct ActingHost *)p)->f17C=3;
            }
            break;
        }
    }
}

/*
 * followers: own leaf files 021FD634 and 021FD68C.
 */
int STA_NET_SendChunk(char *p,u32 i)
{
    char *q;
    char *s;
    u16 n;
    q=*(char * *)&((struct ActingHost *)p)->f140;
    n=0x3800;
    s=*(char * *)&((struct HostEntry *)q)->f10+i*0x3800;
    if((i+1)*0x3800>((struct HostEntry *)q)->f2C) n=((struct HostEntry *)q)->f2C%0x3800U;
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetNetHandle(0xff),0xff,0x1105,n,(u32)s,0,1,1);
}

void STA_NET_AdvanceChunk(int a,int b,int c,char *p)
{
    char *q;
    char *s;
    u32 v;
    (((struct ActingHost *)p)->f14C)++;
    ((struct ActingHost *)p)->f154=0;
    q=*(char * *)&((struct ActingHost *)p)->f140;
    if((u32)(((struct ActingHost *)p)->f14C*0x3800)>=((struct HostEntry *)q)->f2C) {
        s=*(char * *)&((struct HostEntry *)q)->f10;
        ((struct HostEntry *)q)->f14=s+0xc;
        q=*(char * *)&((struct ActingHost *)p)->f140;
        ((struct HostEntry *)q)->f18=*(char * *)&((struct HostEntry *)q)->f10+0xc+((struct Obj10567 *)s)->f0;
        q=*(char * *)&((struct ActingHost *)p)->f140;
        v=((struct Obj10567 *)s)->f4;
        ((struct HostEntry *)q)->f1C=v+(*(u32 *)&((struct HostEntry *)q)->f10+0xc+((struct Obj10567 *)s)->f0);
    }
}

void *STA_NET_GetChunkPtr(int a,char *p)
{
    char *q;
    q=*(char * *)&((struct ActingHost *)p)->f140;
    return *(char * *)&((struct HostEntry *)q)->f10+((struct ActingHost *)p)->f14C*0x3800;
}

int STA_NET_IsTransferDone(char *p) {if(((struct HostEntry *)(*(char * *)&((struct ActingHost *)p)->f140))->f2C/0x3800u<((struct ActingHost *)p)->f14C)return 1;return 0;}


/*
 * Addresses are Black-image addresses.
 */
int STA_NET_NotifyHostKind4(u8 *p)
{
    void *q = ((struct ActingHost *)p)->f140.p;
    return func_021FCEA8((int)p, 4, (u32)(((struct HostEntry *)q)->f20), 0xff);
}


int STA_NET_NotifyHostKind5(char *p)
{
    return func_021FCEA8((int)p, 5, *(int *)(((struct ActingHost *)p)->f140.s + 0x24), 0xff);
}


int STA_NET_NotifyHostKind6(char *p)
{
    return func_021FCEA8((int)p, 6, *(int *)(((struct ActingHost *)p)->f140.s + 0x28), 0xff);
}

int STA_NET_SendSlot1Command(u8 *p)
{
    u32 *q = *(u32 * *)&((struct ActingHost *)p)->f140;
    u32 id;
    STA_SLOT_Noop(q[1], q[8], 2);
    id = (u32)GFL_NET_HANDLE_GetNetHandle(255);
    return GFL_NET_SendData(id, 255, 0x1106, (*(u32 **)(p + 0x140))[8], (*(u32 **)(p + 0x140))[1], 1, 0, 1);
}

void STA_NET_SetSlot1Done(void *a, void *b, void *c, u8 *p)
{
    u32 *q;
    ((struct ActingHost *)p)->f170 = 1;
    q = *(u32 * *)&((struct ActingHost *)p)->f140;
    STA_SLOT_Noop(q[1], q[8], 12);
}

u32 STA_NET_GetSlot1Value(void *a, u8 *p)
{
    return (*(u32 **)(p + 0x140))[1];
}

int STA_NET_SendSlot2Command(u8 *p)
{
    u32 *q = *(u32 * *)&((struct ActingHost *)p)->f140;
    u32 id;
    STA_SLOT_Noop(q[2], q[9], 1);
    id = (u32)GFL_NET_HANDLE_GetNetHandle(255);
    return GFL_NET_SendData(id, 255, 0x1107, (*(u32 **)(p + 0x140))[9], (*(u32 **)(p + 0x140))[2], 1, 0, 1);
}

void STA_NET_SetSlot2Done(void *a, void *b, void *c, u8 *p)
{
    u32 *q;
    ((struct ActingHost *)p)->f174 = 1;
    q = *(u32 * *)&((struct ActingHost *)p)->f140;
    STA_SLOT_Noop(q[2], q[9], 11);
}

u32 STA_NET_GetSlot2Value(void *a, u8 *p)
{
    return (*(u32 **)(p + 0x140))[2];
}

int STA_NET_SendSlot3Command(u8 *p)
{
    u32 *q = *(u32 * *)&((struct ActingHost *)p)->f140;
    u32 id;
    STA_SLOT_Noop(q[3], q[10], 0);
    id = (u32)GFL_NET_HANDLE_GetNetHandle(255);
    return GFL_NET_SendData(id, 255, 0x1108, (*(u32 **)(p + 0x140))[10], (*(u32 **)(p + 0x140))[3], 1, 0, 1);
}

void STA_NET_SetSlot3Done(void *a, void *b, void *c, u8 *p)
{
    u32 *q;
    ((struct ActingHost *)p)->f178 = 1;
    q = *(u32 * *)&((struct ActingHost *)p)->f140;
    STA_SLOT_Noop(q[3], q[10], 10);
}

u32 STA_NET_GetSlot3Value(void *a, u8 *p)
{
    return (*(u32 **)(p + 0x140))[3];
}

u32 STA_NET_GetSlot1Done(char *p) {return ((struct ActingHost *)p)->f170;}

/*
 * Unlabelled ov132 leaf hidden in a .word run: returns element 0x5e of the
 * argument viewed as an int array.  Matched to supply the `matched` witness
 * for the pending ov010 caller SCRCMD_MUSICAL_WaitSessionReady.
 */
int STA_NET_GetIndexedWord5E(int *p)
{
    return p[0x5e];
}

static inline u8 random4(void)
{
    u32 draw;
    draw = func_0203F0A8();
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
    return func_021FCEA8((int)p, 1, result, 255);
}


void STA_NET_SendKindA(char *p, int a)
{
    func_021FCE74((int)p, 0xa, a, 0xff);
}

u32 STA_NET_GetCurrentSlotValue(char *p) {return *(u8 *)((u32)p+GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())*0x30+0x72);}

u8 STA_NET_GetSlotValueByIndex(char *p, int index) {return *(u8 *)((u32)p+index*0x30+0x72);}

u32 STA_NET_GetSlotWordByIndex(char *p,u32 index){return *(u32 *)((u32)p+index*0x30+0x80);}


/*
 * Unlabelled ov132 leaf hidden in a .word run: returns the word at +0x48.
 * Matched to supply the `matched` witness for the pending ov010 caller
 * MUSICAL_EVENT_CreateLocalPerformer.
 */
int STA_NET_GetField48(int *p)
{
    return ((struct ActingHost *)p)->f48;
}

/*
 * Getter: returns the word at offset 0x158.
 */
u32 STA_NET_GetField158(u8 *p)
{
 return *(u32 *)(p+0x158);
}

/*
 * Unlabelled ov132 leaf hidden in a .word run: returns element 0x57 of the
 * argument viewed as an int array.  Matched to supply the `matched` witness
 * for the pending ov010 caller SCRCMD_MUSICAL_WaitSessionFinish.
 */
int STA_NET_GetIndexedWord57(int *p)
{
    return p[0x57];
}

void STA_NET_SetState6Pair(char *p, u32 a, int b) {func_021FCDEC((int)p,0x40);((struct ActingHost *)p)->f4C=6;((struct ActingHost *)p)->f144.s=a;((struct ActingHost *)p)->f148.s=b;}

void STA_NET_SetState12(char *p) {func_021FCDEC((int)p,0x42);((struct ActingHost *)p)->f4C=12;}

/*
 * The larger indexed follower at 021FD964 is parked separately at DIFF.
 */
void STA_NET_SetState18Value(char *p,u32 value){((struct ActingHost *)p)->f4C=18;((struct ActingHost *)p)->f120=value;}

u32 STA_NET_GetPairA(char *p){return ((struct ActingHost *)p)->f144.u;}

u32 STA_NET_GetPairB(char *p){return ((struct ActingHost *)p)->f148.u;}

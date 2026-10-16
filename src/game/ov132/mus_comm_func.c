/*
 * file:     mus_comm_func.c
 * unit:     yes
 * function: MUS_COMM_FUNC_Create, MUS_COMM_FUNC_Delete, MUS_COMM_FUNC_StartSession, MUS_COMM_FUNC_UpdateNetState, MUS_COMM_FUNC_WaitSessionNull, MUS_COMM_FUNC_Task, MUS_COMM_FUNC_SetHostFlag, MUS_COMM_FUNC_InitCommandTable, MUS_COMM_FUNC_InitWork, MUS_COMM_FUNC_DeleteBuffers, MUS_COMM_FUNC_SetReady, MUS_COMM_FUNC_Update, MUS_COMM_FUNC_SetTimingSync, MUS_COMM_FUNC_CheckTimingSync, MUS_COMM_FUNC_GetSlotValueA, MUS_COMM_FUNC_GetSlotValueB, MUS_COMM_FUNC_GetRecordPtr, MUS_COMM_FUNC_GetRecordSize, MUS_COMM_FUNC_Equals, MUS_COMM_FUNC_SendCommand, MUS_COMM_FUNC_SendCommandWait, MUS_COMM_FUNC_HandlePacket, MUS_COMM_FUNC_SendMyStatus, MUS_COMM_FUNC_SetEntryFlag, MUS_COMM_FUNC_ClearEntryFlag, MUS_COMM_FUNC_SendBoxData, MUS_COMM_FUNC_ReceiveBoxData, MUS_COMM_FUNC_ResetBoxFlags, MUS_COMM_FUNC_SendStatusBlock, MUS_COMM_FUNC_SetRecordData, MUS_COMM_FUNC_ClearRecordData, MUS_COMM_FUNC_SendRecordBlock, MUS_COMM_FUNC_ReceiveRecordBlock, MUS_COMM_FUNC_ClearRecords
 * address:  0x021FC644
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from sta_acting.c, script_command.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   MUS_COMM_FUNC_SetTimingSync 0x021FCDEC thumb ov132
 *   MUS_COMM_FUNC_CheckTimingSync 0x021FCE00 thumb ov132
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   d_021FDE5C 0x021FDE5C data a4
 *   GAME_COMM_RequestExitNoCallback 0x02026400 thumb
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   OS_GetMacAddress 0x02087C6C arm
 *   d_021FDE4C 0x021FDE4C data a4
 *   d_021FDDEC 0x021FDDEC data a4
 *   GFL_NET_GetNegotiationNum 0x0203D1B4 arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   ICA_ANIME_SetField30 0x02012124 thumb
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_021FDC38 0x021FDC38 data a4
 *   GAME_DATA_GetSaveBlock2A 0x02012F44 thumb
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   POKE_TOOL_GetBoxParamSize 0x020173E8 thumb
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   MUSICAL_SAVE_GetFanPoints 0x0200A81C thumb
 *   STA_NET_SendRandomOrder 0x021FD84C thumb ov132
 *   STA_NET_NotifyHostKind4 0x021FD6C8 thumb ov132
 *   STA_NET_SendSlot1Command 0x021FD704 thumb ov132
 *   STA_NET_NotifyHostKind5 0x021FD6DC thumb ov132
 *   STA_NET_NotifyHostKind6 0x021FD6F0 thumb ov132
 *   STA_NET_SendSlot2Command 0x021FD76C thumb ov132
 *   STA_NET_SendSlot3Command 0x021FD7D4 thumb ov132
 *   STA_NET_IsTransferDone 0x021FD6A4 thumb ov132
 *   STA_NET_UpdateTransferState 0x021FD550 thumb ov132
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   GFL_NET_HANDLE_GetNetHandle 0x0203996C arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020084BC 0x020084BC thumb
 *   MYSTATUS_Copy  0x02008494  thumb  arm9
 *   GAME_COMM_Start  0x020263D8  thumb  arm9
 *   ICA_ANIME_GetField1C  0x020120F4  thumb  arm9
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 */
#include "ov132_types.h"
#include "sta_acting_shared_types.h"
#include "sta_act_script_shared_types.h"
#include "script_command_shared_types.h"

extern u32 GFL_NET_IsParentAid(void);

extern u32 GF_STANDARD_Rand(void);

#define W(q,k) (*(u32 *)((q)+(k)))

#define P(q,k) (*(u8 **)((q)+(k)))

struct Comm;

struct Req;

struct Big;

struct Link;

struct Pl {
    u32 a;
    u32 b;
    u32 c;
    u8 d;
    u8 pad[3];
    u32 x;
    u32 e;
    u8 rest[0x18];
};

struct MusCommPlayerTable {
    u8 pad[0x64];
    struct Pl pl[4];
};

struct Request {u8 kind;u32 value;};

typedef struct 
{
  u8 tag;
  u32 data;
} Packet;

typedef struct { u32 w[12]; } E;

typedef struct { u8 pad[0x60]; E e[4]; } T;

struct Context { char pad0[0x60]; struct Record rec[4]; };

/* The callback owner is the 0x1ac-byte allocation in 021FC644, viewed as
   struct ActingHost. */

extern void *func_02030734(unsigned, unsigned, int, const char *, u16);

extern u32 func_020307B0(void *p);

extern void *ICA_ANIME_GetField1C(const struct Ctx *p);

extern void GAME_COMM_Start(struct Comm *p, u32 a1, u32 a2);

extern void GAME_COMM_RequestExitNoCallback(struct Comm *);

extern u8 *GAME_DATA_GetMyStatus(void *p);

extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);

extern void MYSTATUS_Copy(void *, void *);

extern void OS_GetMacAddress(void *);

extern int GFL_NET_GetNegotiationNum(void);

extern int GFL_NET_Exit(int);

extern void GFL_NET_COMMAND_DeleteCommandTable(u32);

extern void GFL_NET_SetLoginOption(u8 a0);

extern u32 func_0200FB24(void);

extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);

extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);

extern void ICA_ANIME_SetField30(struct Ctx *p, u32 v);

extern int GFL_NET_IsSessionNull(void);

extern void GFL_NET_COMMAND_AddCommandTable(u32,u32,u32,u32);

extern void *GAME_DATA_GetSaveBlock2A(void *);

extern u32 POKE_TOOL_GetPartyParamSize(void);

extern u32 POKE_TOOL_GetBoxParamSize(void);

extern int MYSTATUS_GetSize(void);

extern void MI_CpuFill8(void *,u8,u32);

extern u16 MUSICAL_SAVE_GetFanPoints(struct Big *p);

extern int STA_NET_SendRandomOrder(u8 *p);

extern int STA_NET_NotifyHostKind4(u8 *p);

extern int STA_NET_SendSlot1Command(u8 *p);

extern int STA_NET_NotifyHostKind5(char *);

extern int STA_NET_NotifyHostKind6(char *);

extern int STA_NET_SendSlot2Command(u8 *p);

extern int STA_NET_SendSlot3Command(u8 *p);

extern int STA_NET_IsTransferDone(char *);

extern void STA_NET_UpdateTransferState(char *);

extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, unsigned int, unsigned int);

extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);

extern u32 GFL_NET_SendData(u32,u32,u32,u32,u32,u32,u32,u32);

extern struct Entry *GFL_NET_HANDLE_GetNetHandle(int);

extern void GFL_USE_PlaySeDefaultVolume(u32);

extern void MI_CpuCopy8(void *,void *,u32);

extern int func_020084BC(const u16 *values);

void MUS_COMM_FUNC_Create(int a, void *b, void *c, int d);

void MUS_COMM_FUNC_Delete(char *p);

void *MUS_COMM_FUNC_StartSession(int a,char *p);

int MUS_COMM_FUNC_UpdateNetState(int *state,u8 *p);

int MUS_COMM_FUNC_WaitSessionNull(int unused,int unused1,void *p);

void MUS_COMM_FUNC_Task(int unused,int unused1,char *p);

void MUS_COMM_FUNC_SetHostFlag(char *p);

void MUS_COMM_FUNC_InitCommandTable(char *p);

void MUS_COMM_FUNC_InitWork(u8 *p,void *a,void *b,int unused,void *d,u16 heap);

void MUS_COMM_FUNC_DeleteBuffers(char *p);

void MUS_COMM_FUNC_SetReady(char *p);

void MUS_COMM_FUNC_Update(char *p);

void MUS_COMM_FUNC_SetTimingSync(int a, int b);

int MUS_COMM_FUNC_CheckTimingSync(char *p,int id);

int MUS_COMM_FUNC_GetSlotValueA(char *p,u32 index);

int MUS_COMM_FUNC_GetSlotValueB(char *p,u32 index);

char *MUS_COMM_FUNC_GetRecordPtr(char *p);

u32 MUS_COMM_FUNC_GetRecordSize(void);

int MUS_COMM_FUNC_Equals(int a,int b);

void MUS_COMM_FUNC_SendCommand(int unused,int kind,u32 value,u32 id);

u32 MUS_COMM_FUNC_SendCommandWait(int unused,int kind,u32 value,u32 id);

void MUS_COMM_FUNC_HandlePacket(unsigned long slot, int unused, const Packet *q, char *p);

u32 MUS_COMM_FUNC_SendMyStatus(struct ActingHost *p);

void MUS_COMM_FUNC_SetEntryFlag(int i, int b, int c, T *p);

u32 MUS_COMM_FUNC_ClearEntryFlag(int i, T *p);

int MUS_COMM_FUNC_SendBoxData(char *p);

void MUS_COMM_FUNC_ReceiveBoxData(int a,int b,int c,char *p);

void *MUS_COMM_FUNC_ResetBoxFlags(int a,char *p);

int MUS_COMM_FUNC_SendStatusBlock(char *p, char *src);

void MUS_COMM_FUNC_SetRecordData(long i,int b,int c,struct Context *p);

void *MUS_COMM_FUNC_ClearRecordData(long i,struct Context *p);

int MUS_COMM_FUNC_SendRecordBlock(const char *p);

void MUS_COMM_FUNC_ReceiveRecordBlock(int a,int b,int c,const struct ActingHost *p);

extern const char d_021FDE5C[];

extern char d_021FDE4C[];

extern char d_021FDDEC[];

extern char d_021FDC38[];

void MUS_COMM_FUNC_Create(int a, void *b, void *c, int d)
{
    char *p;
    p = func_02030734(4, 0x1ac, 1, d_021FDE5C, 0x14c);
    ((struct ActingHost *)p)->fC = d;
    ((struct ActingHost *)p)->f54 = b;
    ((struct ActingHost *)p)->f58 = ICA_ANIME_GetField1C(b);
    ((struct ActingHost *)p)->f50 = c;
    ((struct ActingHost *)p)->f4 = 0;
    ((struct ActingHost *)p)->f8 = 0;
    GAME_COMM_Start(c, 4, (u32)p);
}

void MUS_COMM_FUNC_Delete(char *p) { MUS_COMM_FUNC_DeleteBuffers(p); GAME_COMM_RequestExitNoCallback(*(struct Comm * *)&((struct ActingHost *)p)->f50); }

void *MUS_COMM_FUNC_StartSession(int a,char *p)
{
    ((struct ScriptCtx *)p)->f5C=GAME_DATA_GetMyStatus(((struct ScriptCtx *)p)->f58);
    if(((struct ScriptCtx *)p)->fC==1) d_021FDE4C[5]=4;
    else {
        d_021FDE4C[5]=0;
        GFL_NET_StartSession((struct Req *)d_021FDDEC,(u32)MUS_COMM_FUNC_SetReady,(u32)p);
    }
    MYSTATUS_Copy(((struct ScriptCtx *)p)->f5C,p+0x20);
    OS_GetMacAddress(p+0x40);
    ((struct ScriptCtx *)p)->f46=0x3a0b;
    return p;
}

/*
 * 0203D1B4's forwarding matched void declaration loses its live result.
 * 0203D7BC retains the original caller's unused zero argument.
 */
int MUS_COMM_FUNC_UpdateNetState(int *state,u8 *p)
{
 switch(*state) {
 case 0:
  if(GFL_NET_GetNegotiationNum()<=1) {GFL_NET_Exit(0);return 1;}
  if(((struct ActingHost *)p)->fC==1) GFL_NET_COMMAND_DeleteCommandTable(0x1100);
  if(((struct ActingHost *)p)->f8==1) {GFL_NET_SetLoginOption(0);MUS_COMM_FUNC_SetTimingSync((int)p,0x41);*state=1;}
  else *state=2;
  break;
 case 1:
  if(MUS_COMM_FUNC_CheckTimingSync((char *)p,0x41)==1) *state=2;
  if(GFL_NET_GetNegotiationNum()<=1 || func_0200FB24()!=0) *state=10;
  break;
 case 2:
  if(((struct ActingHost *)p)->f8==0) {GFL_NET_Exit(0);return 1;}
  if(GFL_NET_IsParentAid()==0) {
   if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),1,0,0)==1) return 1;
  } else if(GFL_NET_GetNegotiationNum()<=1) {GFL_NET_Exit(0);return 1;}
  if(func_0200FB24()!=0) *state=10;
  break;
 case 10:
  if(func_0200FB24()!=0) ICA_ANIME_SetField30(*(struct Ctx * *)&((struct ActingHost *)p)->f54,1);
  GFL_NET_Exit(0);return 1;
 }
 return 0;
}

int MUS_COMM_FUNC_WaitSessionNull(int unused,int unused1,void *p) { if(GFL_NET_IsSessionNull()==1) {func_020307B0(p);return 1;} return 0; }

void MUS_COMM_FUNC_Task(int unused,int unused1,char *p) { MUS_COMM_FUNC_Update(p); }

void MUS_COMM_FUNC_SetHostFlag(char *p) { if(GFL_NET_IsParentAid()==1) ((struct ActingHost *)p)->f48=1; else ((struct ActingHost *)p)->f48=2; }

void MUS_COMM_FUNC_InitCommandTable(char *p) { GFL_NET_COMMAND_AddCommandTable(0x1100,(u32)d_021FDC38,9,(u32)p); if(GFL_NET_IsParentAid()==1) ((struct ActingHost *)p)->f48=1; else ((struct ActingHost *)p)->f48=2; }

static inline void clear8(void *dest,u32 size)
{
 MI_CpuFill8(dest,0,size);
}

/*
 * 02012F44 returns the live pointer from its forwarding target 020071CC;
 * its matched void prototype discards that result.
 * Lever: row is block-local; the final fill has a per-entry pointer.
 * The SDK MI_CpuClear8 inline spelling restores both fill-call setup orders
 * (direct MI_CpuFill8 leaves 15 bytes; data/size signedness changes are flat).
 */
void MUS_COMM_FUNC_InitWork(u8 *p,void *a,void *b,int unused,void *d,u16 heap)
{
 void *data;
 u32 size1,size2;
 u8 i,j;
 data=GAME_DATA_GetSaveBlock2A(P(p,0x58));
 ((struct ActingHost *)p)->f0=heap;
 for(i=0;i<4;i++) {
  u8 *row;
  row=p+i*0x30;
  W(row,0x60)=0;
  row[0x72]=i;
  W(row,0x78)=0;
  W(row,0x64)=0;W(row,0x68)=0;W(row,0x6C)=0;
  row[0x70]=10;row[0x71]=10;
  P(row,0x7C)=func_02030734(((struct ActingHost *)p)->f0,POKE_TOOL_GetPartyParamSize()+0x7C,0,d_021FDE5C,0x20E);
  size1=MYSTATUS_GetSize();
  P(row,0x8C)=func_02030734(((struct ActingHost *)p)->f0,(size1+4)+POKE_TOOL_GetBoxParamSize(),0,d_021FDE5C,0x20F);
  clear8(P(row,0x7C),POKE_TOOL_GetPartyParamSize()+0x7C);
  size2=MYSTATUS_GetSize();
  clear8(P(row,0x8C),(size2+4)+POKE_TOOL_GetBoxParamSize());
  P(row,0x80)=P(row,0x8C);
  P(row,0x84)=P(row,0x8C)+4;
  P(row,0x88)=P(row,0x8C)+4+MYSTATUS_GetSize();
  for(j=0;j<2;j++) row[0x73+j]=0xFF;
 }
 ((struct ActingHost *)p)->f12C=MUSICAL_SAVE_GetFanPoints(data);
 ((struct ActingHost *)p)->f130=a;((struct ActingHost *)p)->f134=b;
 W(p,0x138)=0;W(p,0x124)=0;
 P(p,0x128)=func_02030734(((struct ActingHost *)p)->f0,(POKE_TOOL_GetPartyParamSize()+0x7C)*4,0,d_021FDE5C,0x221);
 size1=MYSTATUS_GetSize();
 P(p,0x13C)=func_02030734(((struct ActingHost *)p)->f0,((size1+4)+POKE_TOOL_GetBoxParamSize())*4,0,d_021FDE5C,0x222);
 p[0x1C]=0;W(p,0x14)=0;W(p,0x18)=0;
 p[0x14C]=0;W(p,0x150)=0;
 W(p,0x158)=0;W(p,0x15C)=0;W(p,0x160)=0;W(p,0x164)=0;
 W(p,0x168)=0;W(p,0x170)=0;W(p,0x174)=0;W(p,0x17C)=0;
 W(p,0x184)=0;W(p,0x188)=0;
 p[0x180]=4;
 W(p,8)=1;
 for(j=0;j<8;j++) {
  u8 *entry=p+j*4;
  W(entry,0x18C)=0xFFFF;
 }
 ((struct ActingHost *)p)->f140.p=d;
 W(p,0x4C)=1;
}

void MUS_COMM_FUNC_DeleteBuffers(char *p)
{
    u8 i;
    char *q;
    for(i=0;i<4;i++) {
        q=p+i*0x30;
        if(((struct ActingScene *)q)->f7C) {
            func_020307B0(((struct ActingScene *)q)->f8C);
            func_020307B0(((struct ActingScene *)q)->f7C);
        }
    }
    if(((struct ActingHost *)p)->f124) func_020307B0(((struct ActingHost *)p)->f124);
    if(((struct ActingHost *)p)->f138) func_020307B0(((struct ActingHost *)p)->f138);
    if(((struct ActingHost *)p)->f128) func_020307B0(((struct ActingHost *)p)->f128);
    if(((struct ActingHost *)p)->f13C) func_020307B0(((struct ActingHost *)p)->f13C);
}

void MUS_COMM_FUNC_SetReady(char *p)
{
    ((struct ActingScene *)p)->f10=1;
}

static inline u32 random_below(u32 n)
{
    u32 draw;
    draw = GF_STANDARD_Rand();
    return ((u64)draw * n) >> 32;
}

/*
 * note 2026-10-05: state machine on p+0x4c (22-entry jump table; cases 20 and 21 are explicit
 * so the table keeps its size). Players are a 0x30-byte struct array at p+0x64. The final
 * packed-id draw is a 64-bit multiply high (_ull_mul) through an inline helper; the id is
 * added into sum (sum += list[k] << 16) before the call, which fixed the last 2 bytes.
 * Callees 021FD84C, 021FCEA8 and 021FD350 are void in their matched files but the caller
 * tests r0 == 1: their last call (a u32-returning arm9 function) leaves the result in r0,
 * so the originals return it. They are declared with return values here. Callee 021FD14C
 * and 021FD400 have no source yet (symbols resolve as labels).
 */
void MUS_COMM_FUNC_Update(char *p)
{
    u8 i, j, n;
    u8 cnt;
    u8 list[4];
    u32 v;
    u32 ok;
    if (func_0200FB24()) {
        *(int *)(p + 4) = 1;
        if (GFL_NET_IsSessionNull() == 0) GFL_NET_Exit(0);
    }
    if (*(int *)(p + 4) == 1) return;
    switch (*(u32 *)(p + 0x4c)) {
    case 0:
        return;
    case 1:
        GFL_NET_SetLoginOption(1);
        MUS_COMM_FUNC_SetTimingSync((int)p, 0x46);
        *(int *)(p + 0x4c) = 2;
        break;
    case 2:
        if (MUS_COMM_FUNC_CheckTimingSync(p, 0x46) == 1 && MUS_COMM_FUNC_SendMyStatus((struct ActingHost *)p) == 1) {
            if (*(int *)(p + 0x48) == 1) *(int *)(p + 0x4c) = 3;
            else *(int *)(p + 0x4c) = 5;
        }
        break;
    case 3:
        if (STA_NET_SendRandomOrder((u8 *)p) == 1) *(int *)(p + 0x4c) = 4;
        break;
    case 4:
        cnt = 0;
        for (i = 0; i < 4; i++)
            if (((struct MusCommPlayerTable *)p)->pl[i].b == 1) cnt++;
        if (cnt == GFL_NET_GetNegotiationNum() && MUS_COMM_FUNC_SendBoxData(p) == 1) *(int *)(p + 0x4c) = 5;
        break;
    case 6:
        if (MUS_COMM_FUNC_CheckTimingSync(p, 0x40) == 1) {
            if (*(int *)(p + 0x48) == 1) *(int *)(p + 0x4c) = 7;
            else *(int *)(p + 0x4c) = 0xb;
        }
        break;
    case 7:
        if (MUS_COMM_FUNC_SendCommandWait((int)p, 8, *(u32 *)(p + 0x144), 0xff) == 1) *(int *)(p + 0x4c) = 8;
        break;
    case 8:
        if (MUS_COMM_FUNC_SendCommandWait((int)p, 9, *(u32 *)(p + 0x148), 0xff) == 1) *(int *)(p + 0x4c) = 9;
        break;
    case 9:
        if (STA_NET_NotifyHostKind4((u8 *)p) == 1) *(int *)(p + 0x4c) = 0xa;
        break;
    case 10:
        if (*(int *)(p + 0x164) == 1 && STA_NET_SendSlot1Command((u8 *)p) == 1) *(int *)(p + 0x4c) = 0xb;
        break;
    case 12:
        if (MUS_COMM_FUNC_CheckTimingSync(p, 0x42) == 1) {
            if (*(int *)(p + 0x48) == 1) {
                if (STA_NET_NotifyHostKind5(p) == 1) *(int *)(p + 0x4c) = 0xd;
            } else *(int *)(p + 0x4c) = 0x11;
        }
        break;
    case 13:
        if (*(int *)(p + 0x168) == 1 && STA_NET_NotifyHostKind6(p) == 1) *(int *)(p + 0x4c) = 0xe;
        break;
    case 14:
        if (*(int *)(p + 0x16c) == 1 && STA_NET_SendSlot2Command((u8 *)p) == 1) *(int *)(p + 0x4c) = 0xf;
        break;
    case 15:
        if (*(int *)(p + 0x174) == 1 && STA_NET_SendSlot3Command((u8 *)p) == 1) *(int *)(p + 0x4c) = 0x10;
        break;
    case 16:
        *(int *)(p + 0x4c) = 0x11;
        break;
    case 17:
        if (*(int *)(p + 0x178) == 1) STA_NET_IsTransferDone(p);
        break;
    case 18:
        if (MUS_COMM_FUNC_SendStatusBlock(p, (char *)(*(u32 *)(p + 0x120))) == 1) {
            if (*(int *)(p + 0x48) == 1) *(int *)(p + 0x4c) = 0x13;
            else *(int *)(p + 0x4c) = 0x15;
        }
        break;
    case 19:
        cnt = 0;
        for (i = 0; i < 4; i++)
            if (((struct MusCommPlayerTable *)p)->pl[i].a == 1) cnt++;
        if (cnt == GFL_NET_GetNegotiationNum() && MUS_COMM_FUNC_SendRecordBlock(p) == 1) *(int *)(p + 0x4c) = 0x15;
        break;
    case 20:
    case 21:
        break;
    default:
        break;
    }
    if (*(int *)(p + 0x184) == 1) {
        v = 0;
        v += ((struct MusCommPlayerTable *)p)->pl[0].e;
        v += ((struct MusCommPlayerTable *)p)->pl[1].e << 4;
        v += ((struct MusCommPlayerTable *)p)->pl[2].e << 8;
        v += ((struct MusCommPlayerTable *)p)->pl[3].e << 12;
        if (MUS_COMM_FUNC_SendCommandWait((int)p, 3, v, 0xff) == 1) *(int *)(p + 0x184) = 0;
    }
    {
        u32 sum = 0;
        n = 0;
        for (i = 0; i < 4; i++) {
            if (((struct MusCommPlayerTable *)p)->pl[i].c == 1) {
                list[n] = i;
                n++;
            }
            sum += ((struct MusCommPlayerTable *)p)->pl[i].d << (i * 4);
        }
        if (n != 0) {
            u32 k = random_below(n);
            sum += list[k] << 16;
            if (MUS_COMM_FUNC_SendCommandWait((int)p, 0xb, sum, 0xff) == 1) {
                for (j = 0; j < n; j++) {
                    ((struct MusCommPlayerTable *)p)->pl[list[j]].c = 0;
                    ((struct MusCommPlayerTable *)p)->pl[list[j]].d = 10;
                }
            }
        }
    }
    if (*(int *)(p + 0x188) == 1) {
        ok = 1;
        for (i = 0; i < 8; i++) {
            if (*(u32 *)(p + i * 4 + 0x18c) != 0xFFFF) {
                if (MUS_COMM_FUNC_SendCommandWait((int)p, 0xc, *(u32 *)(p + i * 4 + 0x18c), 0xff) == 1) *(u32 *)(p + i * 4 + 0x18c) = 0xFFFF;
                ok = 0;
            }
        }
        if (ok == 1) *(int *)(p + 0x188) = 0;
    }
    STA_NET_UpdateTransferState(p);
}

void MUS_COMM_FUNC_SetTimingSync(int a, int b)
{
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), b, 0x11);
}

int MUS_COMM_FUNC_CheckTimingSync(char *p,int id) {if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),id,0x11)==1)return 1;if(((struct ActingHost *)p)->f4==1)return 1;return 0;}

int MUS_COMM_FUNC_GetSlotValueA(char *p,u32 index) {if(((struct ActingHost *)p)->f4C!=0 && *(int *)((u32)p+index*0x30+0x68)==1)return *(int *)((u32)p+index*0x30+0x84);return 0;}

int MUS_COMM_FUNC_GetSlotValueB(char *p,u32 index) {if(((struct ActingHost *)p)->f4C!=0 && *(int *)((u32)p+index*0x30+0x68)==1)return *(int *)((u32)p+index*0x30+0x88);return 0;}

char *MUS_COMM_FUNC_GetRecordPtr(char *p){return p+0x20;}

u32 MUS_COMM_FUNC_GetRecordSize(void){return 40;}

int MUS_COMM_FUNC_Equals(int a,int b){if(a==b)return 1;return 0;}

void MUS_COMM_FUNC_SendCommand(int unused,int kind,u32 value,u32 id) {struct Entry *e;struct Request request;e=GFL_NET_HANDLE_GetCurrentHandle();request.kind=kind;request.value=value;GFL_NET_SendData((u32)e,id,0x1100,8,(u32)&request,1,0,0);}

u32 MUS_COMM_FUNC_SendCommandWait(int unused,int kind,u32 value,u32 id) {struct Entry *e;struct Request request;e=GFL_NET_HANDLE_GetNetHandle(255);request.kind=kind;request.value=value;return GFL_NET_SendData((u32)e,id,0x1100,8,(u32)&request,1,0,0);}

void MUS_COMM_FUNC_HandlePacket(unsigned long slot, int unused, const Packet *q, char *p)
{
  u8 i;
  u8 t;
  u8 code;
  u8 index;
  u8 item;
  u32 mask;
  u32 v;
  u32 tmp;
  u32 tmp1;
  switch (q->tag)
  {
    case 0:
      *((u32 *) (p + 0x18)) = 1;
      break;

    case 1:
      mask = 15;
      for (i = 0; i < 4; i++)
    {
      *((u8 *) ((p + (i * 0x30)) + 0x72)) = (q->data & mask) >> (i * 4);
      mask <<= 4;
    }

      break;

    case 2:
      *((u32 *) ((p + (slot * 0x30)) + 0x78)) = q->data;
      if ((*((u32 *) (p + 0x48))) == 1)
      *((u32 *) (p + 0x184)) = 1;
      break;

    case 3:
      if ((*((u32 *) (p + 0x48))) != 1)
    {
      v = q->data;
      *((u32 *) (p + 0x78)) = v & 15;
      *((u32 *) (p + 0xa8)) = (v & 0xf0) >> 4;
      *((u32 *) (p + 0xd8)) = (v & 0xf00) >> 8;
      *((u32 *) (p + 0x108)) = (v & 0xf000) >> 12;
    }
      break;

    case 4:
      if ((*((u32 *) (p + 0x48))) == 2)
    {
      *((void **) ((*((char **) (p + 0x140))) + 4)) = func_02030734(4, q->data, 0, d_021FDE5C, 0x4c4);
      *((u32 *) ((*((char **) (p + 0x140))) + 0x20)) = q->data;
    }
      *((u32 *) (p + 0x164)) = 1;
      break;

    case 5:
      if ((*((u32 *) (p + 0x48))) == 2)
    {
      *((void **) ((*((char **) (p + 0x140))) + 8)) = func_02030734(44, q->data, 0, d_021FDE5C, 0x4cd);
      *((u32 *) ((*((char **) (p + 0x140))) + 0x24)) = q->data;
    }
      *((u32 *) (p + 0x168)) = 1;
      break;

    case 6:
      if ((*((u32 *) (p + 0x48))) == 2)
    {
      *((void **) ((*((char **) (p + 0x140))) + 12)) = func_02030734(44, q->data, 0, d_021FDE5C, 0x4d6);
      *((u32 *) ((*((char **) (p + 0x140))) + 0x28)) = q->data;
    }
      *((u32 *) (p + 0x16c)) = 1;
      break;

    case 7:
      if ((*((u32 *) (p + 0x48))) == 1)
      *((u32 *) (p + 0x17c)) = 3;
    else
    {
      *((void **) ((*((char **) (0x140 + p))) + 16)) = func_02030734(44, q->data, 0, d_021FDE5C, 0x4e3);
      *((u32 *) ((*((char **) (p + 0x140))) + 0x2c)) = q->data;
    }
      break;

    case 8:
      *((u32 *) (p + 0x144)) = q->data;
      break;

    case 9:
      *((u32 *) (p + 0x148)) = q->data;
      break;

    case 10:
      if ((*((u32 *) (p + 0x48))) == 1)
    {
      *((u32 *) ((((u32) p) + (slot * 0x30)) + 0x6c)) = 1;
      *((u8 *) ((p + (slot * 0x30)) + 0x70)) = q->data;
    }
      break;

    case 11:
    {
      u8 t;
      u8 i;
      u32 mask;
      mask = 15;
      for (i = 0; i < 4; i++)
      {
        t = (q->data & mask) >> (i * 4);
        if (t != 10)
          *((u8 *) ((p + (i * 0x30)) + 0x71)) = t;
        mask <<= 4;
      }

      *((u8 *) (p + 0x180)) = (q->data & 0xf0000) >> 16;
      break;
    }

    case 12:
    {
      u8 i;
      int code;
      int item;
      u16 index;
      u32 v;
      v = q->data;
      code = (u8) ((v & 0xff0000) >> 16);
      index = (u8) ((v & 0xff00) >> 8);
      item = (u8) v;
      for (i = 0; i < 2; i++)
      {
        tmp1 = ((u32) p) + (index * 0x30);
        tmp1 = tmp1 + i;
        if ((*((u8 *) (tmp1 + 0x73))) == 255)
        {
          tmp = (u32) p;
          tmp = tmp + (index * 0x30);
          *((u8 *) ((tmp + i) + 0x73)) = item;
          break;
        }
      }

      if (code == 1)
        GFL_USE_PlaySeDefaultVolume(0x62c);
      else
        if (code == 2)
        GFL_USE_PlaySeDefaultVolume(0x62b);
      break;
    }

  }

}

/*
 * followers: unlabelled leaves begin at 021FD208 and 021FD218 (not part of this function; function body is 188 bytes).
 * note 2026-10-05 (wave P13 lane B5): 6/188 bytes differ, all register colour: the allocation result q is in r6 and q+4 (s) in r4, the original has q r4, s r6 (m2 r7, p r5 match). Callee types checked (02008468 int, 020173E8 u32, 02030734 returns void*, 0203D3F8 u32, caller compares result with 1). Tried, all the same 6 bytes: separate locals for the first size pair; one variable reused for the first size and q; both q and s as u32; q typed as header struct with s = q->data; s declared before q; s set before or after p->buffer store and after m; s = q; s += 4; m+s order; sizes in block locals; all six per-function pragmas (opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments, scheduling, peephole). Without a local s (q+4 written at each use) the 0x4e<<2 offset is hoisted and 121 bytes differ; p->buffer instead of q is worse (123). Idioms read: two-long-lived-values-in-each-others-registers, a-result-computed-in-a-dying-local-takes-that-locals-register, a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off, a-field-read-into-its-own-local-before-a-getter-subtraction-sets-the-colour-order, array-bases-as-pointer-locals-reopen-a-flat-declaration-order.
 * recoup 2026-10-05 P29R10: still 6/188 bytes (q r6/s r4 vs original q r4/s r6). New tries, all the same 6 bytes unless noted: q=p->buffer=alloc chain; s=q+4 before m; m reusing a; int sizes; reversed and regrouped declaration orders (7 layouts, no effect); q as u32* with s=(char*)(q+1); q as header struct with s=q->data; const void* source in MI_CpuCopy8; q and s as u32; a+b+4 order (15 bytes). Worse: s=p->buffer+4 (110), plus copy from p->buffer (123), no s local with q+4 / q+4+m / q+m+4 (121), s after first copy (125), s set at the call (125), s before p->buffer store (25). No twin in src/matched/ov (callees 02030734+02082D44+020173E8 share no file). Idioms re-read: two-long-lived-values-in-each-others-registers, a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off.
 * final push 2026-10-05 G2L10: still 6/188 bytes (q r6/s r4 vs original q r4/s r6). Analysis: q and s interfere, equal cost, so the tie is the simplify order; s (later vreg) is coloured first. With q+4 written at each use q does get r4 but the 0x4e<<2 offset is hoisted (121 bytes), so the named s is right. New tries, all the same 6 bytes unless noted: s=q+4 before m (24 bytes); declaration orders s,q and m,b,a; block-scoped a/b/q and m/s with initialisers; sizes inlined in the alloc call; p->buffer=q=alloc; s=p->buffer then if(s) free (and q likewise); opt_lifetimes+opt_propagation off together; q void* with (char*)q+4; q u32 with s char*; q char* with s u32; static inline halloc wrapper (0x533 as a line argument); static inline fill(p,q,m) for the three copies; u16 heap local (178); first/second pointers as locals (128); inline bufsize() for both size sums (63). Idioms read: two-long-lived-values-in-each-others-registers, a-result-computed-in-a-dying-local-takes-that-locals-register, a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off, a-dying-pointer-loads-scratch-colour-can-be-an-allocator-tie, a-field-read-into-its-own-local-before-a-getter-subtraction-sets-the-colour-order, const-on-a-read-only-source-parameter-settles-a-register-tie. Twins: ov132 021FD350 and 021FC848 (same callees, no matching shape); mwcc ALLOCATOR_CASEBOOK is PPC but says vreg birth order decides ties.
 * pass 2 2026-10-06 P2L12: still 6/188 bytes (q r6/s r4 vs original q r4/s r6), 39 compiles. New tries, all 6 bytes unless noted: local names; s reused for the 020399A8 result with a/b reused for the final sizes (with and without opt_lifetimes off); opt_lifetimes off with declaration orders s,q and m,s,b,q,a; named size locals for the copies and t=s+m; 02082D44(void*,void*,int) with int a/m; s assigned inside the first copy's argument list; s from a static inline Data(q); alloc in a static inline Alloc(p,size); register on q or s; char *const q and s in nested blocks; sibling 021FD350 form (char *p with casts, n reused, h local) with named s. Worse: cursor forms q+=4/q+=m, s=q;s+=4, q++ or q+=4 in the call argument (62 to 67): any second definition frees r7 and hoists the 0x138 offset. Coloring.c (mwcc_ref): select pops the simplify stack, so the order of q vs s comes from vreg numbering or degree; declaration order has no effect here. Assembly hits checked (adds r1,rX,#0 then adds rY,rX,#K before a call): ov010 0216787A, ov093 021C462E, ov116 021D6DF4, ov172 021B7350, all loop copies, no match.
 * pass 3 2026-10-06 P3L06: still 6/188 bytes (q r6/s r4 vs original q r4/s r6), 40 compiles. New tries, all 6 bytes unless noted: zero local (021FD350 style); s=&q[4] and &s[m]; p->buffer=alloc then q=p->buffer (store forwarded); full sibling style (int n, m reused for every size pair, h local); u8 and u16 return for 02008468 with u8/u16 m; long m and long a,b,m; s+=m in the third copy argument; 4+q and m+s; m reusing b; separate old local for the free guard; Owner *const p; opt_loop_invariants off; opt_strength_reduction off; opt_propagation off with t=alloc, s=t+4, q=t (q born after s); inline Header(p,q) returning s; inline Pack(p,q) with m and s inside; inline Copy wrapper; m/s inner block without initialisers (both orders); a/b/q inner block to the first copy; c99 mid-block declarations; local aggregates {head,body} (both orders) and {head,first,second} (021FC848 row style). Worse: first copy from s-4 (120, q and s merge); q+4+m with named s (121); inline Pack(p,q,q+4,m) (121, s propagated). Diagnostics: removing m or s gives q r4 first, so only the q/s/m clique orders s first; dsi 1.1, 1.2, 1.2p2 give the same 6 bytes. Asm scan (adds rLow,rX,#0 plus adds rY,rX,#K before a call): only ov198 02210E20 (matched, base=p+4 from a parameter, not applicable). Idioms read: of-two-equal-temps-the-later-born-one-gets-the-lower-register, a-masked-locals-declared-width-is-invisible-in-the-diff-and-decides-its-register, a-no-code-self-assignment-reorders-the-register-colouring (stand-in, not used), declaration-position-orders-block-scope-colouring, a-width-stored-in-the-handle-temp-it-replaces-keeps-the-original-colours, two-long-lived-values-in-each-others-registers (callees read no hidden arguments).
 * pass 4 2026-10-06 P4L04: EXACT* (--lang c99 and --lang c). The third block pointer is computed up front as t=q+4+MYSTATUS_GetSize() and the second copy writes to q+4 with no named s: CSE turns the shared q+4 into a temp born before the first copy, and t is forward-substituted into the third copy as temp+m, which gives the image colours (q r4, q+4 r6, size r7). Same layout as the row pointers in 021FC848 (P(row,0x88)=buf+4+MYSTATUS_GetSize()).
 */
u32 MUS_COMM_FUNC_SendMyStatus(struct ActingHost *p)
{
    u32 a, b;
    char *q, *t;
    if(p->f138) func_020307B0(p->f138);
    a=MYSTATUS_GetSize();
    b=POKE_TOOL_GetBoxParamSize();
    q=func_02030734(p->f0,a+4+b,0,d_021FDE5C,0x533);
    p->f138=q;
    t=q+4+MYSTATUS_GetSize();
    MI_CpuCopy8(&p->f12C,q,4);
    MI_CpuCopy8(p->f130,q+4,MYSTATUS_GetSize());
    MI_CpuCopy8(p->f134,t,POKE_TOOL_GetBoxParamSize());
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(),0xff,0x1101,MYSTATUS_GetSize()+4+POKE_TOOL_GetBoxParamSize(),(u32)p->f138,1,0,1);
}

void MUS_COMM_FUNC_SetEntryFlag(int i, int b, int c, T *p) { p->e[i].w[2] = 1; p->e[i].w[0] = 1; }

u32 MUS_COMM_FUNC_ClearEntryFlag(int i, T *p) { p->e[i].w[2] = 0; return p->e[i].w[11]; }

int MUS_COMM_FUNC_SendBoxData(char *p)
{
    u8 i;
    u32 n;
    u32 m;
    char *q;
    u32 k;
    void *h;
    for(i=0;i<4;i++) {
        m=MYSTATUS_GetSize();
        n=POKE_TOOL_GetBoxParamSize();
        q=*(char * *)&((struct ActingHost *)p)->f13C;
        k=i*(m+4+n);
        m=MYSTATUS_GetSize();
        n=POKE_TOOL_GetBoxParamSize();
        MI_CpuCopy8(*(void **)(p+i*0x30+0x8c),q+k,m+4+n);
    }
    h=GFL_NET_HANDLE_GetNetHandle(0xff);
    m=MYSTATUS_GetSize();
    n=POKE_TOOL_GetBoxParamSize();
    return GFL_NET_SendData((u32)h,0xff,0x1102,(m+4+n)*4,(u32)(((struct ActingHost *)p)->f13C),1,0,1);
}

/*
 * follower: loop leaf filed as ov132_func_021FD328.c.
 */
void MUS_COMM_FUNC_ReceiveBoxData(int a,int b,int c,char *p)
{
    u8 i;
    int n;
    u32 m,k;
    char *q,*s;
    int flag;
    for(i=0;i<4;i++) {
        m=MYSTATUS_GetSize();
        n=POKE_TOOL_GetBoxParamSize();
        q=*(char * *)&((struct ActingHost *)p)->f13C;
        k=i*(m+4+n);
        m=MYSTATUS_GetSize();
        n=m+4+POKE_TOOL_GetBoxParamSize();
        s=p+i*0x30;
        MI_CpuCopy8(q+k,((struct ActingScene *)s)->f8C,n);
        flag=func_020084BC(((struct ActingScene *)s)->f84)==0 ? 1 : 0;
        ((struct ActingScene *)s)->f60=flag;
        ((struct ActingScene *)s)->f68=flag;
    }
    ((struct ActingHost *)p)->f158=1;
}

void *MUS_COMM_FUNC_ResetBoxFlags(int a,char *p)
{
    u8 i;
    for(i=0;i<4;i++) *(int *)(p+i*0x30+0x68)=0;
    ((struct ActingHost *)p)->f158=0;
    return ((struct ActingHost *)p)->f13C;
}

/*
 * followers: larger leaves 021FD3D8 and 021FD3F0 filed separately.
 */
int MUS_COMM_FUNC_SendStatusBlock(char *p, char *src)
{
    char *q;
    void *h;
    u32 n;
    int zero;
    if(((struct ActingHost *)p)->f124) func_020307B0(((struct ActingHost *)p)->f124);
    n=POKE_TOOL_GetPartyParamSize();
    q=func_02030734(((struct ActingHost *)p)->f0,n+0x7c,0,d_021FDE5C,0x5be);
    zero=0;
    ((struct ActingHost *)p)->f124=q;
    MI_CpuCopy8(src,q,0x7c);
    n=POKE_TOOL_GetPartyParamSize();
    q+=0x7c;
    MI_CpuCopy8(((struct MusCommBlockHeader *)src)->payload,q,n);
    h=GFL_NET_HANDLE_GetCurrentHandle();
    n=POKE_TOOL_GetPartyParamSize();
    return GFL_NET_SendData((u32)h,0xff,0x1103,n+0x7c,(u32)(((struct ActingHost *)p)->f124),1,zero,1);
}

/*
 * layout: 021FC862..021FC93E initializes four 48-byte records at +0x60.
 * padding: two zero bytes at 021FD3EE before 021FD3F0.
 */
void MUS_COMM_FUNC_SetRecordData(long i,int b,int c,struct Context *p)
{
    char *s;
    p->rec[i].flag=1;
    s=p->rec[i].data;
    ((struct MusCommBlockHeader *)s)->payload=s+0x7c;
}

/*
 * layout: 021FC862..021FC93E initializes four 48-byte records at +0x60.
 */
void *MUS_COMM_FUNC_ClearRecordData(long i,struct Context *p)
{
    p->rec[i].flag=0;
    return p->rec[i].data;
}

/*
 * note: 2026-10-05 recoup: the copy length is a plain call result plus 0x7c, written the same way as the
 *   first call's n (n=f()+0x7c) and passed as n. The older draft passed n+0x7c inline and left adds r2/r1 swapped.
 */
int MUS_COMM_FUNC_SendRecordBlock(const char *p)
{
    u8 i;
    u32 n;
    u32 k;
    u32 q;
    void *h;
    for(i=0;i<4;i++) {
        n=POKE_TOOL_GetPartyParamSize()+0x7c;
        q=*(u32 *)(p+0x128);
        k=i*n;
        n=POKE_TOOL_GetPartyParamSize()+0x7c;
        MI_CpuCopy8(*(void **)(p+i*0x30+0x7c),(void *)(q+k),n);
    }
    h=GFL_NET_HANDLE_GetNetHandle(0xff);
    n=POKE_TOOL_GetPartyParamSize();
    return GFL_NET_SendData((u32)h,0xff,0x1104,(n+0x7c)*4,*(u32 *)(p+0x128),1,0,1);
}

/*
 * note: 2026-10-05 length kept in a local before the call (n = f()+0x7c; call(q+k, src, n)); the inline n+0x7c form swapped two adds (4 B). Older DIFF notes superseded.
 */
void MUS_COMM_FUNC_ReceiveRecordBlock(int a,int b,int c,const struct ActingHost *p)
{
    u8 i;
    char *s;
    u32 k;
    char *q;
    u32 n;
    for(i=0;i<4;i++) {
        s=(char *)p+i*0x30;
        if(func_020084BC(*(u16 **)(s+0x84))==0) {
            n=POKE_TOOL_GetPartyParamSize()+0x7c;
            q=p->f128;
            k=i*n;
            n=POKE_TOOL_GetPartyParamSize()+0x7c;
            MI_CpuCopy8(q+k,*(void **)(s+0x7c),n);
            q=*(char **)(s+0x7c);
            *(char **)(q+4)=q+0x7c;
            *(int *)(s+0x64)=1;
        } else *(int *)(s+0x64)=0;
    }
    *(int *)((char *)p+0x15c)=1;
}

/* Clears the flag of the four records, clears the word at +0x15C and returns the buffer pointer. */
char *MUS_COMM_FUNC_ClearRecords(int a, struct ActingHost *p)
{
    u8 i;
    for (i = 0; i < 4; i++)
        p->rec[i].flag = 0;
    p->f15C = 0;
    return p->f128;
}

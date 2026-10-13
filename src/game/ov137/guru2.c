/*
 * file:     guru2.c
 * unit:     yes
 * function: func_021DC860, func_021DC888, func_021DC8BC, func_021DC8D0, func_021DC90C, func_021DC924, func_021DC928, func_021DC950, func_021DC9AC, func_021DC9F4, func_021DCAB4, func_021DCAF0, func_021DCAFC, func_021DCB04, func_021DCB60, func_021DCB78, func_021DCB90, func_021DCB94, func_021DCBC4, func_021DCBCC, func_021DCBFC, func_021DCC24, func_021DCCF0, func_021DCD0C, func_021DCD14,func_021DCD34,func_021DCD44,func_021DCD5C,func_021DCD6C,func_021DCD7C, func_021DCD8C,func_021DCDA0,func_021DCDB0,func_021DCDC0,func_021DCDD8,func_021DCDF0, func_021DCE00, func_021DCE10, func_021DCF50, func_021DCF58, func_021DCF7C, func_021DCF80, func_021DD0B8, func_021DD14C, func_021DD1A4, func_021DD1B4, func_021DD1D0
 * address:  0x021DC860
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Main 0x02031330 arm
 *   d_021E1A50 0x021E1A50 data a4
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_02030734 0x02030734 arm
 *   d_021E2260 0x021E2260 data a4
 *   func_020307B0 0x020307B0 arm
 *   PROCSYS_Push 0x02031348 arm
 *   d_021E1A38 0x021E1A38 data a4
 *   d_0000005B 0x0000005B data a1
 *   gPartyListProcData 0x021BED00 data ov091 a4
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   d_021E1A68 0x021E1A68 data a4
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   func_021DE08C 0x021DE08C thumb ov137
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   UNION_APP_GetJoinedBits 0x021841A0 thumb ov022
 *   func_02080D24 0x02080D24 arm
 *   func_021DE17C 0x021DE17C thumb ov137
 *   func_021E172C 0x021E172C thumb ov137
 *   func_021E1758 0x021E1758 thumb ov137
 *   func_021E168C 0x021E168C thumb ov137
 *   func_021E1694 0x021E1694 thumb ov137
 *   func_021E180C 0x021E180C thumb ov137
 *   func_021E1814 0x021E1814 thumb ov137
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   func_020490F4 0x020490F4 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045B38 0x02045B38 arm
 *   TCBL_Create 0x0203101C arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   func_020056A0 0x020056A0 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_021DD1E0 0x021DD1E0 thumb ov137
 *   func_021DD3D8 0x021DD3D8 thumb ov137
 *   func_021DD2E0 0x021DD2E0 thumb ov137
 *   func_021DD4A8 0x021DD4A8 thumb ov137
 *   func_021DD5AC 0x021DD5AC thumb ov137
 *   func_021DD638 0x021DD638 thumb ov137
 *   UNION_APP_Open 0x02184134 thumb ov022
 *   UNION_APP_SetCallbacks 0x021840FC thumb ov022
 *   UNION_APP_RequestReset 0x02184174 thumb ov022
 *   UNION_APP_IsResetDone 0x0218417C thumb ov022
 *   func_021DE248 0x021DE248 thumb ov137
 *   func_021DE5D0 0x021DE5D0 thumb ov137
 *   func_021DE738 0x021DE738 thumb ov137
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   d_021E1C20 0x021E1C20 data a4
 *   TCBL_DeleteAllTasks 0x0203115C arm
 *   TCBL_Destroy 0x02031140 arm
 *   func_021DD570 0x021DD570 thumb ov137
 *   func_021DD760 0x021DD760 thumb ov137
 *   func_021DD3B0 0x021DD3B0 thumb ov137
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_021DE354 0x021DE354 thumb ov137
 *   func_021DE37C 0x021DE37C thumb ov137
 *   func_021DD380 0x021DD380 thumb ov137
 *   func_020306F0 0x020306F0 arm
 *   GX_LoadOBJPltt 0x0207E51C arm
 *   d_021E1AEE 0x021E1AEE data a1
 *   d_021E1AEF 0x021E1AEF data a1
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   func_020419E4  0x020419E4  arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   TCBL_Main  0x020310C4  arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   d_021E1B40 0x021E1B40 data a4
 *   gPokeStatusProcData 0x021DC800 data a4 ov131
 *   d_00000083 0x00000083 data a1
 *   d_021E1A44 0x021E1A44 data a4
 *   d_021E2268 0x021E2268 data a4
 *   GFL_NET_SetAutoExit  0x0203D7B0  arm  arm9
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 *   POKEPARTY_GetMember  0x0201AB28  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb  arm9
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb  arm9
 */
#include "ov137_types.h"
struct Guru2Ctx;
struct Guru2Ctx_f0;

struct Guru2Ctx {
    void *f0;
    unsigned int f4;
    unsigned char pad_8[4];
    void *fC;
    void *f10;
    unsigned char pad_14[4];
    void *f18;
    unsigned char pad_1C[4];
    void *f20;
    unsigned char pad_24[28];
    unsigned short f40;
    unsigned short f42;
    unsigned char pad_44[4];
    unsigned short f48;
    unsigned short f4A;
    void *f4C;
    void *f50;
};

struct Guru2Ctx_f0 {
    unsigned char pad_0[28];
    void *f1C;
    void *f20;
};

struct Obj0203159C;
struct S020314B8;
struct S020315D4;
struct BigObj;
struct DC950Obj;
struct DC950Src;
struct Blk37;
struct Entry;
struct GfFont;
struct MsgBank;
struct Tcbl;
struct WordSet;
struct Node;
struct PrintSys;
struct Rec;
struct S02031140;
struct DispVram;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct DC950Src {
    u32 pad_00[4];
    void *unk_10;
};

struct DC950Obj {
    void *unk_00;
    void *unk_04;
    u32 pad_08[11];
    int unk_34;
    u32 unk_38;
    int unk_3c;
    u32 pad_40[22];
};

typedef signed short s16;

struct Packet {u8 a,b; volatile u8 c; u8 d;};

typedef signed char s8;

typedef signed int s32;

typedef void (*Cb)(void);

struct State { u32 enable; u32 index; int counter; u32 spare; u8 *object; };

extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,u32);
extern void *PROCSYS_Create(int a0);
extern u32 PROCSYS_Main(void *);
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void *func_02030734(u16,u32,int,const char *,u16);
extern u32 func_020307B0(void *p);
extern void PROCSYS_Push(void *,int,const void *,void *);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201292C(const struct BigObj *p);
extern u32 POKEPARTY_GetCount(void *);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void GFL_NET_SetAutoExit(u8 a0);
extern u8 *func_02012944(void *p);
extern void *ZUKAN_SAVE_GetFromGameData(void *);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);
extern void GFL_NET_COMMAND_AddCommandTable(u32,u32,u32,u32);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void MI_CpuCopy8(const void *,void *,u32);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void func_021DE08C(char *p, int state, int player);
extern int UNION_APP_GetMemberCount(unsigned char *p);
extern unsigned char UNION_APP_GetJoinedBits(unsigned char *p);
extern u32 func_02080D24(int);
extern void func_021DE17C(char *p, int command, int player);
extern void func_021E172C(char *p, unsigned short *q);
extern void func_021E1758(char *p, int a1);
extern void func_021E168C(int *p, int a);
extern void func_021E1694(void *,void *);
extern void func_021E1814(unsigned char *p, u16 *q);
extern void func_021E180C(int *p, int a, int b);
extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0203F8F4(u16);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_021DD1D0(void),func_021DD1E0(void);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void func_021DD3D8(void *,void *);
extern void *func_020056A0(u32,u32,u32);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *);
extern void func_021DD2E0(u8 *,void *),func_021DD4A8(u8 *,void *),func_021DD5AC(u8 *),func_021DD638(u8 *);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 func_0200FB24(void);
extern void UNION_APP_Open(u8 *p);
extern void UNION_APP_RequestReset(u8 *p);
extern u32 UNION_APP_IsResetDone(u8 *);
extern void UNION_APP_SetCallbacks(u8 *,Cb,Cb,void *);
extern int func_021DE248(void *,int,u16,void *);
extern void func_021DE5D0(u8 *p);
extern int func_021DE738(void *,int);
extern void GFL_NET_COMMAND_DeleteCommandTable(unsigned),CLACT_DrawSystem(void);
extern void TCBL_DeleteAllTasks(struct Tcbl *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void func_021DD570(u8 *p);
extern u32 func_021DD760(void *);
extern void func_021DD3B0(u32);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_02030EAC(struct Node *n);
extern int func_021DE354(void *p);
extern u32 func_021DE37C(void *);
extern void func_021DD380(u8 *p);
extern void func_020306F0(unsigned int);
extern void GX_LoadOBJPltt(void *, int, int);
extern void CLACT_VBlankSystem(void);
extern void func_020419E4(void);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void TCBL_Main(struct Tcbl *p);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
int func_021DC860(void *obj,int a,struct Guru2Ctx *ctx);
int func_021DC888(void *obj,int a,int b,u8 *p);
int func_021DC8BC(void *obj,int a,int b,struct Guru2Ctx *p);
void *func_021DC8D0(void *q,int heap);
void func_021DC90C(struct Guru2Ctx *p);
void *func_021DC924(struct Guru2Ctx *p);
int func_021DC928(struct Guru2MainCtx *p);
struct DC950Obj *func_021DC950(struct DC950Src *p,int a,int b);
int func_021DC9AC(u32 *p);
int func_021DC9F4(u32 *p);
int func_021DCAB4(u8 *p);
int func_021DCAE8(u32 *p);
int func_021DCAF0(struct Guru2Ctx *p);
void *func_021DCAFC(struct Guru2MainCtx2 *p);
u32 *func_021DCB04(u32 a,int heap);
void func_021DCB60(struct Guru2Ctx *p);
void func_021DCB78(u32 a);
void func_021DCB90(void *p);
void func_021DCB94(u8 *p,u32 id,const void *data,u32 size);
void func_021DCBC4(void *p,u32 a,const void *b,u32 c);
void func_021DCBCC(int i,int unused,void *q,struct Guru2MainCtx2 *p);
void func_021DCBFC(int a,int b,int c,struct Guru2MainCtx *p);
void func_021DCC24(int a,int b,u8 *c,struct Guru2MainCtx2 *p);
void func_021DCCF0(int a,int b,int c,struct Guru2Ctx *p);
int func_021DCD0C(void);
void func_021DCD14(int a,int b,u8 *c,struct Guru2MainCtx *p);
void func_021DCD34(int a,int b,u16 *c,struct Guru2Ctx *p);
void func_021DCD44(int a,int b,void *c,struct Guru2Ctx *p);
void func_021DCD5C(int a,int b,void *c,struct Guru2Ctx *p);
void func_021DCD6C(int a,int b,int *c,struct Guru2Ctx *p);
void func_021DCD7C(int a,int b,u8 *c,struct Guru2Ctx *p);
void func_021DCD8C(int a,int b,void *c,struct Guru2Ctx *p);
void func_021DCDA0(int a,int b,int *c,struct Guru2Ctx *p);
void func_021DCDB0(int a,int b,void *c,struct Guru2Ctx *p);
void func_021DCDC0(int a,int b,void *c,struct Guru2Ctx *p);
void func_021DCDD8(int a,int b,void *c,struct Guru2Ctx *p);
void *func_021DCDF0(int a,struct Guru2Ctx *p);
int func_021DCE00(struct Guru2MainCtx2 *p, int i);
int func_021DCE10(void *a,u32 *state,u8 *ctx);
void *func_021DCF50(u8 *p);
void func_021DCF58(int a,int b,struct Guru2Ctx *p);
void func_021DCF7C(void);
int func_021DCF80(int a,int b,int c,u8 *p);
int func_021DD0B8(void *a,int b,void *c,u8 *p);
void func_021DD14C(void *unused, u8 *p);
void func_021DD1A4(void *a0, void *work);
void func_021DD1B4(u8 *p);
void func_021DD1D0(void);
extern const u8 d_021E2260[];
extern const u8 d_021E1A38[];
extern const unsigned char gPartyListProcData[];
extern const unsigned char d_0000005B[];
extern const u8 d_021E2260[],gPokeStatusProcData[],d_021E1A44[],d_00000083[];
extern const unsigned char d_021E2268[];
extern const u8 d_021E1A68[];
extern const u8 d_021E1AEE[];
extern const u8 d_021E1AEF[];
extern const u32 d_021E1B40[];



int func_021DC860(void *obj,int a,struct Guru2Ctx *ctx) { u8 *p=PROCSYS_AllocProcWork(obj,36,4); MI_CpuFill8(p,0,36); *(unsigned int *)&((struct Guru2MainCtx *)p)->f10=ctx->f4; ((struct Guru2MainCtx *)p)->f8=ctx; ((struct Guru2MainCtx *)p)->f20=PROCSYS_Create(1); return 1; }



extern int (* const d_021E1A50[])(u8 *);



int func_021DC888(void *obj,int a,int b,u8 *p) { switch(PROCSYS_Main(((struct Guru2Ctx *)p)->f20)) { case 0: if(d_021E1A50[*(u32 *)p](p)==1) return 1; break; case 1: break; case 2: break; } return 0; }



int func_021DC8BC(void *obj,int a,int b,struct Guru2Ctx *p) { func_0203133C(p->f20); func_020315D4(obj); return 1; }



void *func_021DC8D0(void *q,int heap) {u8 *p;p=func_02030734((u16)heap,36,0,(const char *)d_021E2260,171);MI_CpuFill8(p,0,36);*(void * *)&((struct Guru2MainCtx *)p)->f14=q;*(void * *)&((struct Guru2MainCtx *)p)->f18=func_021DCB04((u32)p,heap);return p;}



void func_021DC90C(struct Guru2Ctx *p) {func_021DCB90(p->f18);func_021DCB60(p->f18);func_020307B0(p);}



void *func_021DC924(struct Guru2Ctx *p) { return p->f10; }



int func_021DC928(struct Guru2MainCtx *p) {void *v;v=func_021DC8D0(p->f8,4);*(unsigned int *)&p->f0=1;*(void * *)&p->fC=v;PROCSYS_Push(p->f20,-1,d_021E1A38,v);return 0;}



/*
 * func_02030734 0x02030734 arm
 * d_021E2260 0x021E2260 data a4
 */
struct DC950Obj *func_021DC950(struct DC950Src *p,int a,int b)
{
    struct DC950Obj *v;
    int i;
    v=func_02030734(4,sizeof(struct DC950Obj),1,(const char *)d_021E2260,256);
    v->unk_00=func_02012934(p->unk_10);
    v->unk_04=func_0201292C(p->unk_10);
    v->unk_38=0;
    v->unk_34=a;
    v->unk_3c=b;
    for(i=0;i<(int)POKEPARTY_GetCount(v->unk_00);i++) POKEPARTY_GetMember(v->unk_00,i);
    return v;
}



/*
 * func_021DC924 0x021DC924 thumb ov137
 * func_021DC950 0x021DC950 thumb ov137
 * GFL_NET_SetAutoExit 0x0203D7B0 arm
 * PROCSYS_Push 0x02031348 arm
 * gPartyListProcData 0x021BED00 data ov091 a4
 * d_0000005B 0x0000005B data a1
 */
int func_021DC9AC(u32 *p)
{
    void *v;
    if (!func_021DC924((void *)p[3])) p[0]=5;
    else {
        GFL_NET_SetAutoExit(1);
        v=func_021DC950((struct DC950Src *)p,21,0);
        p[6]=(u32)v;
        PROCSYS_Push((void *)p[8],(int)d_0000005B,gPartyListProcData,v);
        *(u32 *)p[3]=1;
        p[0]=2;
    }
    return 0;
}



/*
 * func_020307B0 0x020307B0 arm
 * func_02030734 0x02030734 arm
 * MI_CpuFill8 0x02082BCC arm
 * PROCSYS_Push 0x02031348 arm
 * d_021E2260 0x021E2260 data a4
 * gPokeStatusProcData 0x021DC800 data a4 ov131
 * d_021E1A44 0x021E1A44 data a4
 * d_00000083 0x00000083 data a1
 */
int func_021DC9F4(u32 *p)
{
    u32 *v=(u32 *)p[6];
    int mode=v[16],sel=v[15];
    void *q;
    void *r;
    func_020307B0(v);
    if(mode==1) {
        func_02012944((void *)p[4]);
        q=ZUKAN_SAVE_GetFromGameData((void *)p[4]);
        p[7]=(u32)func_02030734(4,40,0,(const char *)d_021E2260,328);
        MI_CpuFill8((void *)p[7],0,40);
        r=(void *)func_02012934((void *)p[4]);
        *(void **)p[7]=r;
        *(u32 *)(p[7]+8)=p[4];
        *(u8 *)(p[7]+12)=1;
        *(u8 *)(p[7]+14)=POKEPARTY_GetCount(r);
        *(u8 *)(p[7]+15)=0;
        *(u8 *)(p[7]+13)=1;
        *(u16 *)(p[7]+20)=0;
        *(u8 *)(p[7]+16)=0;
        *(u32 *)(p[7]+24)=ZUKAN_SAVE_IsNationalDexEnabled(q);
        p[1]=sel;
        *(u8 *)(p[7]+15)=sel;
        PROCSYS_Push((void *)p[8],(int)d_00000083,gPokeStatusProcData,(void *)p[7]);
        p[0]=3;
    } else {
        *(u32 *)(p[3]+4)=sel;
        PROCSYS_Push((void *)p[8],-1,d_021E1A44,(void *)p[3]);
        *(u32 *)p[3]=3;
        p[0]=4;
    }
    return 0;
}



int func_021DCAB4(u8 *p) {u8 a;void *v;a=(*(u8 * *)&((struct Guru2MainCtx *)p)->f1C)[15];func_020307B0(*(void * *)&((struct Guru2MainCtx *)p)->f1C);v=func_021DC950((struct DC950Src *)p,21,a);*(void * *)&((struct Guru2MainCtx *)p)->f18=v;PROCSYS_Push(((struct Guru2MainCtx *)p)->f20,(int)d_0000005B,gPartyListProcData,v);*(unsigned int *)&((struct Guru2MainCtx *)p)->f0=2;return 0;}



int func_021DCAE8(u32 *p) {*p=5;return 0;}



int func_021DCAF0(struct Guru2Ctx *p) {func_021DC90C(p->fC);return 1;}



void *func_021DCAFC(struct Guru2MainCtx2 *p) { return **(void ** *)&((struct Guru2MainCtx2_f0 *)p->f0)->f14; }
















/*
 * func_02030734 0x02030734 arm
 * MI_CpuFill8 0x02082BCC arm
 * d_021E2268 0x021E2268 data a4
 */
u32 *func_021DCB04(u32 a,int heap)
{
    u32 *p;
    p=func_02030734(heap,88,0,(const char *)d_021E2268,152);
    MI_CpuFill8(p,0,88);
    p[0]=a;
    p[19]=(u32)func_02030734(heap,0x1be4,0,(const char *)d_021E2268,159);
    p[20]=(u32)func_02030734(heap,0x1be4,0,(const char *)d_021E2268,161);
    return p;
}
















void func_021DCB60(struct Guru2Ctx *p) {func_020307B0(p->f4C);func_020307B0(p->f50);func_020307B0(p);}
















void func_021DCB78(u32 a) {GFL_NET_COMMAND_AddCommandTable(0x2800,(u32)d_021E1A68,16,a);}
















void func_021DCB90(void *p) { }
















/*
 * lever: separate q=(u8 *)((u32)p+4) keeps the updated buffer base;
 *   assigning p+=4 or retaining an integer parameter gave 50 bytes/DIFF.
 */
void func_021DCB94(u8 *p,u32 id,const void *data,u32 size) {u8 *q;void *v;v=GFL_NET_HANDLE_GetCurrentHandle();q=(u8 *)((u32)p+4);MI_CpuCopy8(data,q+4,size);GFL_NET_SendToHandle(v,(u16)id,(u16)(size+4),(u32)q+4);}
















void func_021DCBC4(void *p,u32 a,const void *b,u32 c) {func_021DCB94(p,a,b,c);}
















void func_021DCBCC(int i,int unused,void *q,struct Guru2MainCtx2 *p) {p->f46=p->f46|(s16)(1<<i);MI_CpuCopy8(q, (void *)(func_021DCE00(p,i)), 1428);}














void func_021DCBFC(int a,int b,int c,struct Guru2MainCtx *p) {if(GFL_NET_SYSTEM_GetCurrentAid()!=0) {*(unsigned int *)&p->f20=0;*(unsigned int *)&p->f24=1;func_021DE08C(*(char * *)&((struct Guru2MainCtx_f0 *)p->f0)->f20,27,(u8)a);}}













void func_021DCC24(int a,int b,u8 *c,struct Guru2MainCtx2 *p)
{
    struct Packet s;
    if(a!=0) {
        if(GFL_NET_SYSTEM_GetCurrentAid()!=0) return;
        s=*(struct Packet *)c;
        s.a=a; s.b=p->f2C;
        switch(((struct Packet *)c)->c) {
        case 0:
            if(p->f2C!=UNION_APP_GetMemberCount(func_021DCAFC(p)) ||
               p->f2C!=func_02080D24(UNION_APP_GetJoinedBits(func_021DCAFC(p)))) s.d=0;
            else { p->f30|=1<<a; s.d=1; }
            break;
        case 1: break;
        }
        func_021DCBC4(p,0x2801,&s,4);
    } else {
        switch(c[2]) {
        case 0:
            a=c[0];
            if(a!=GFL_NET_SYSTEM_GetCurrentAid()) return;
            if(c[3]==0) func_021DE08C(*(char * *)&((struct Guru2MainCtx2_f0 *)p->f0)->f20,8,a);
            else { p->f38=c[1]; func_021DE08C(*(char * *)&((struct Guru2MainCtx2_f0 *)p->f0)->f20,7,a); }
            break;
        case 1: func_021DE08C(*(char * *)&((struct Guru2MainCtx2_f0 *)p->f0)->f20,19,c[0]); break;
        }
    }
}












void func_021DCCF0(int a,int b,int c,struct Guru2Ctx *p) {if(GFL_NET_SYSTEM_GetCurrentAid()!=0) func_021DE08C(*(char * *)&((struct Guru2Ctx_f0 *)p->f0)->f20,13,0);}












int func_021DCD0C(void) {return GFL_NET_SYSTEM_GetCurrentAid();}











void func_021DCD14(int a,int b,u8 *c,struct Guru2MainCtx *p)
{
    func_021DE17C(((struct Guru2MainCtx_f0 *)p->f0)->f20,1,*c);
    if(!GFL_NET_SYSTEM_GetCurrentAid()) p->f34=0;
}











/*
 * func_021DE17C 0x021DE17C thumb ov137
 * func_021E172C 0x021E172C thumb ov137
 * func_021E1758 0x021E1758 thumb ov137
 * func_021E168C 0x021E168C thumb ov137
 * GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
void func_021DCD34(int a,int b,u16 *c,struct Guru2Ctx *p) { p->f40|=*c; }











void func_021DCD44(int a,int b,void *c,struct Guru2Ctx *p) { p->f42|=(u16)(1<<a); }











void func_021DCD5C(int a,int b,void *c,struct Guru2Ctx *p) { func_021E172C(((struct Guru2Ctx_f0 *)p->f0)->f1C,c); }











void func_021DCD6C(int a,int b,int *c,struct Guru2Ctx *p) { func_021E1758(((struct Guru2Ctx_f0 *)p->f0)->f1C,*c); }











void func_021DCD7C(int a,int b,u8 *c,struct Guru2Ctx *p) { func_021E168C(((struct Guru2Ctx_f0 *)p->f0)->f1C,*c); }










/*
 * func_021E1694 0x021E1694 thumb ov137
 * func_021E180C 0x021E180C thumb ov137
 * func_021E1814 0x021E1814 thumb ov137
 */
void func_021DCD8C(int a,int b,void *c,struct Guru2Ctx *p) { if(a==0) func_021E1694(((struct Guru2Ctx_f0 *)p->f0)->f1C,c); }










void func_021DCDA0(int a,int b,int *c,struct Guru2Ctx *p) { func_021E180C(((struct Guru2Ctx_f0 *)p->f0)->f1C,a,*c); }










void func_021DCDB0(int a,int b,void *c,struct Guru2Ctx *p) { func_021E1814(((struct Guru2Ctx_f0 *)p->f0)->f1C,c); }










void func_021DCDC0(int a,int b,void *c,struct Guru2Ctx *p) { p->f48|=(u16)(1<<a); }










void func_021DCDD8(int a,int b,void *c,struct Guru2Ctx *p) { p->f4A|=(u16)(1<<a); }










void *func_021DCDF0(int a,struct Guru2Ctx *p) { return *(u8 * *)&p->f4C+a*0x594; }










int func_021DCE00(struct Guru2MainCtx2 *p, int i)
{
    return p->f50 + i * 0x594;
}








/*
 * nested functions. Verified wrapper is MATCH (16 bytes; 020434B4 unresolved).
 * extern void BG_SYS_ClearMainBgPlanes(void),BG_SYS_ClearMainObjPlane(void);
 * void BG_SYS_ClearMainPlanes(void) { BG_SYS_ClearMainBgPlanes(); BG_SYS_ClearMainObjPlane(); }
 * Blocker symbols: BG_SYS_ClearMainBgPlanes 0x0204349C arm; BG_SYS_ClearMainObjPlane 0x020434B4 arm.
 * Verified wrapper is EXACT (16 bytes), fixed compiler/flags ARM.
 * extern void BG_SYS_ClearSubBgPlanes(void),BG_SYS_ClearSubObjPlane(void);
 * void BG_SYS_ClearSubPlanes(void) { BG_SYS_ClearSubBgPlanes(); BG_SYS_ClearSubObjPlane(); }
 * Blocker symbols: BG_SYS_ClearSubBgPlanes 0x02043558 arm; BG_SYS_ClearSubObjPlane 0x02043570 arm.
 * volatile: hardware DISPCNT reads at 021DCE34 and 021DCE3E.
 * lever: PROCSYS_AllocProcWork leaves its allocator result in r0, used by the caller.
 * BG_SYS_ClearMainPlanes 0x020434CC arm
 * BG_SYS_ClearSubPlanes 0x02043588 arm
 * GFL_HEAP_CreateChildHeap 0x0203064C arm
 * func_020490F4 0x020490F4 arm
 * PROCSYS_AllocProcWork 0x0203159C arm
 * MI_CpuFill8 0x02082BCC arm
 * func_0203F8F4 0x0203F8F4 arm
 * func_02045B38 0x02045B38 arm
 * TCBL_Create 0x0203101C arm
 * GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 * ARC_TOOL_DeleteHandle 0x02049238 arm
 * func_0201EC64 0x0201EC64 thumb
 * GF_FONT_Create 0x0201D7EC thumb
 * WIPE_SYS_Start 0x0202208C thumb
 * func_020056A0 0x020056A0 thumb
 * PRINTSYS_QUE_Create 0x0201C440 thumb
 * func_021DD1D0 0x021DD1D0 thumb ov137
 * func_021DD1E0 0x021DD1E0 thumb ov137
 * func_021DD3D8 0x021DD3D8 thumb ov137
 * func_021DD1A4 0x021DD1A4 thumb ov137
 * func_021DD2E0 0x021DD2E0 thumb ov137
 * func_021DD4A8 0x021DD4A8 thumb ov137
 * func_021DD5AC 0x021DD5AC thumb ov137
 * func_021DD638 0x021DD638 thumb ov137
 * func_021DCB78 0x021DCB78 thumb ov137
 */
int func_021DCE10(void *a,u32 *state,u8 *ctx)
{
    u8 *p;
    void *arc;
    switch(*state) {
    case 0:
        BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes();
        *(volatile u32 *)0x04000000&=0xffffe0ff;
        *(volatile u32 *)0x04001000&=0xffffe0ff;
        GFL_HEAP_CreateChildHeap((u32)((void *)1),114,0x80000);
        arc=func_020490F4(184,114);
        p=PROCSYS_AllocProcWork(a,0x4874,114);
        MI_CpuFill8(p,0,0x4874);
        *(u8 **)(ctx+32)=p; *(u8 **)(p+12)=ctx;
        *(void **)(p+16)=*(void **)(ctx+24);
        func_0203F8F4(114);
        *(void **)(p+60)=func_0201EC64(114);
        *(void **)(p+64)=func_02045B38(0,2,42,114);
        *(void **)(p+56)=GF_FONT_Create(23,0,0,0,114);
        func_021DD1D0(); func_021DD1E0();
        WIPE_SYS_Start(0,1,1,0,16,1,114);
        func_021DD3D8(p,arc);
        *(void **)(p+48)=func_020056A0((u32)func_021DD1A4,(u32)p,1);
        *(void **)(p+244)=TCBL_Create(114,114,32,32);
        *(u32 *)(p+236)=PRINTSYS_QUE_Create((void *)114);
        func_021DD2E0(p,arc); func_021DD4A8(p,arc); func_021DD5AC(p); func_021DD638(p);
        func_021DCB78((u32)(*(void **)(ctx+24)));
        GFL_NET_RestartWithDefaultTimeout(1,114); ARC_TOOL_DeleteHandle(arc);
        (*state)++;
        break;
    case 1:
        *state=0;
        return 1;
    }
    return 0;
}









void *func_021DCF50(u8 *p) {return **(void ** *)&((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->fC)->f14;}








void func_021DCF58(int a,int b,struct Guru2Ctx *p) {u8 v;if(GFL_NET_SYSTEM_GetCurrentAid()==0) {v=a;func_021DCBC4(p->f10,10240,&v,1);}}






/*
 * extent: two zero alignment bytes before func_021DCF80.
 */
void func_021DCF7C(void) {}





extern int (*const d_021E1C20[])(u8 *,u32);





/*
 * lever: Table callbacks receive the switch value as their second argument.
 * GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 * func_021DCF50 0x021DCF50 thumb ov137
 * UNION_APP_GetJoinedBits 0x021841A0 thumb ov022
 * UNION_APP_Open 0x02184134 thumb ov022
 * UNION_APP_SetCallbacks 0x021840FC thumb ov022
 * UNION_APP_RequestReset 0x02184174 thumb ov022
 * UNION_APP_IsResetDone 0x0218417C thumb ov022
 * func_021DCF58 0x021DCF58 thumb ov137
 * func_021DCF7C 0x021DCF7C thumb ov137
 * func_021DE248 0x021DE248 thumb ov137
 * func_021DE5D0 0x021DE5D0 thumb ov137
 * func_021DE738 0x021DE738 thumb ov137
 * func_021DD1B4 0x021DD1B4 thumb ov137
 * GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 * CLACT_DrawSystem 0x0204A600 arm
 * WIPE_SYS_EndCheck 0x020221A4 thumb
 * func_0200FB24 0x0200FB24 thumb
 * d_021E1C20 0x021E1C20 data a4
 */
int func_021DCF80(int a,int b,int c,u8 *p)
{
    int v;
    if(GFL_NET_SYSTEM_GetCurrentAid()==0 && ((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f30!=0)
        ((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f30&=UNION_APP_GetJoinedBits(func_021DCF50(p));
    switch(*(unsigned int *)&((struct Guru2MainCtx *)p)->f0) {
    case 0:
        if(WIPE_SYS_EndCheck()) {
            *(unsigned int *)&((struct Guru2MainCtx *)p)->f0=1;
            UNION_APP_Open(func_021DCF50(p));
            UNION_APP_SetCallbacks(func_021DCF50(p),(Cb)func_021DCF58,func_021DCF7C,p);
        }
        break;
    case 1:
        if(d_021E1C20[*(unsigned int *)&((struct Guru2MainCtx *)p)->f118]) *(unsigned int *)&((struct Guru2MainCtx *)p)->f0=d_021E1C20[*(u32 *)&((struct Guru2MainCtx *)p)->f118](p,*(unsigned int *)&((struct Guru2MainCtx *)p)->f0);
        if(((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f24==0) func_021DE248(((struct Guru2MainCtx *)p)->fD0,0,1152,p);
        func_021DE5D0(p);
        if(GFL_NET_SYSTEM_GetCurrentAid()==0) {
            v=func_021DE738(p,1);
            if(*(unsigned int *)&((struct Guru2MainCtx *)p)->f0==1) *(unsigned int *)&((struct Guru2MainCtx *)p)->f0=v;
        }
        break;
    case 2:
        if(d_021E1C20[*(unsigned int *)&((struct Guru2MainCtx *)p)->f118]) *(unsigned int *)&((struct Guru2MainCtx *)p)->f0=d_021E1C20[*(u32 *)&((struct Guru2MainCtx *)p)->f118](p,*(unsigned int *)&((struct Guru2MainCtx *)p)->f0);
        break;
    case 3:
        if(WIPE_SYS_EndCheck()) {
            if(*(unsigned int *)&((struct Guru2MainCtx *)p)->f8) return 1;
            GFL_NET_COMMAND_DeleteCommandTable(10240);
            UNION_APP_RequestReset(func_021DCF50(p));
            *(unsigned int *)&((struct Guru2MainCtx *)p)->f0=4;
        }
        break;
    case 4:
        if(UNION_APP_IsResetDone(func_021DCF50(p))) return 1;
        break;
    }
    if(WIPE_SYS_EndCheck() && func_0200FB24()) return 1;
    CLACT_DrawSystem(); func_021DD1B4(p);
    return 0;
}




/*
 * volatile: 021DD10A reads and 021DD110 writes hardware register 0x04000304
 * TCBL_DeleteAllTasks 0x0203115C arm
 * TCBL_Destroy 0x02031140 arm
 * func_021DD570 0x021DD570 thumb ov137
 * func_021DD760 0x021DD760 thumb ov137
 * func_021DD3B0 0x021DD3B0 thumb ov137
 * MSGDATA_Delete 0x02045C04 arm
 * func_02030EAC 0x02030EAC arm
 * func_021DE354 0x021DE354 thumb ov137
 * func_021DE37C 0x021DE37C thumb ov137
 * func_021DD380 0x021DD380 thumb ov137
 * func_020315D4 0x020315D4 arm
 * func_020306F0 0x020306F0 arm
 */
int func_021DD0B8(void *a,int b,void *c,u8 *p)
{
    TCBL_DeleteAllTasks((struct Tcbl *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->fF4)); TCBL_Destroy((struct S02031140 *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->fF4));
    PRINTSYS_QUE_Clear((struct PrintSys *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->fEC)); PRINTSYS_QUE_Delete((struct PrintSys *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->fEC));
    func_021DD570(p); func_021DD3B0(func_021DD760(p));
    MSGDATA_Delete((struct Rec *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->f40)); func_0201ED04((struct WordSet *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->f3C)); GF_FONT_Delete((void *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->f38));
    *(volatile u16 *)0x04000304 |= 0x8000;
    func_02030EAC((struct Node *)(*(unsigned int *)&((struct Guru2MainCtx *)p)->f30));
    *(unsigned int *)&((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->fC)->f10=*(unsigned int *)&((struct Guru2MainCtx *)p)->f8;
    *(unsigned int *)&((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->fC)->f8=func_021DE354(p);
    *(unsigned int *)&((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->fC)->fC=func_021DE37C(p);
    func_021DD380(p); func_020315D4(a); func_020306F0(114);
    return 1;
}



#pragma opt_propagation off



void func_021DD14C(void *unused, u8 *p)
{
    struct State *v = (struct State *)(p + 24);
    int c;
    u32 i;
    if (v->enable) {
        c = v->counter;
        i = v->index;
        if (c > d_021E1AEE[i * 2]) {
            v->index = i + 1;
            v->counter = 0;
            if (d_021E1AEF[v->index * 2] == 255) v->index = 0;
            GX_LoadOBJPltt(*(u8 **)(v->object + 12) + (d_021E1AEF[v->index * 2] << 5), 0, 32);
            return;
        }
        *(u32 *)(p + 32) += 1;
    }
}



#pragma opt_propagation reset




/*
 * Addresses are Black-image addresses.
 */
void func_021DD1A4(void *a0, void *work)
{
    func_021DD14C(a0, work);
    CLACT_VBlankSystem();
    func_020419E4();
}




void func_021DD1B4(u8 *p)
{
    if (((struct Guru2MainCtx *)p)->fEC)
        PRINTSYS_QUE_Main(((struct Guru2MainCtx *)p)->fEC);
    TCBL_Main(((struct Guru2MainCtx *)p)->fF4);
}



void func_021DD1D0(void) {BG_SYS_SetVramBanks((const struct DispVram *)d_021E1B40);}

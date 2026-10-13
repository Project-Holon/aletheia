/*
 * file:     unit_021E5440.c
 * unit:     yes
 * function: func_021E5440, func_021E54CC, func_021E5524, func_021E56F4, func_021E57E0, func_021E5838, func_021E5888, func_021E58BC, func_021E58F0, func_021E58F4, func_021E5A44, func_021E5A70, func_021E5A90
 * address:  0x021E5440
 * region:   ov178
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   d_02FFFC3C 0x02FFFC3C data a4
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKEPARTY_Add 0x0201A98C thumb
 *   PLIST_COMM_End 0x021B6108 thumb ov090
 *   func_02034A5C 0x02034A5C arm
 *   ov090_id 0x0000005A data
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   ov091_id 0x0000005B data a1
 *   ov131_id 0x00000083 data a1
 *   gPartyListProcData 0x021BED00 data a4 ov091
 *   gPokeStatusProcData 0x021DC800 data a4 ov131
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_ERR_RequestScreen 0x0200FB38 thumb
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb
 *   func_02034AC4 0x02034AC4 arm
 *   PROCSYS_Push 0x02031348 arm
 *   PROCSYS_Main 0x02031330 arm
 *   PLIST_COMM_Update 0x021B6114 thumb ov090
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200873C 0x0200873C thumb
 *   PLIST_COMM_Start 0x021B6100 thumb ov090
 *   ov90_id 0x0000005A data a1
 *   func_02012944   0x02012944  thumb
 *   func_0200CA1C   0x0200CA1C  thumb
 *   POKEPARTY_GetCount   0x0201AA18  thumb
 *   func_0200CA38   0x0200CA38  thumb
 *   func_021E5B1C  0x021E5B1C  thumb  ov178
 *   ov067_id 0x00000043 data a1
 *   ov114_id 0x00000072 data a1
 *   ov175_id 0x000000AF data a1
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   func_021D9DC8 0x021D9DC8 thumb ov175
 *   func_021DC200 0x021DC200 thumb ov175
 *   func_021DC240 0x021DC240 thumb ov175
 *   func_021D9EA0 0x021D9EA0 thumb ov175
 *   func_0217E00C  0x0217E00C  thumb  ov176
 *   ov176_id       0x000000B0  data
 *   func_0217E258 0x0217E258 thumb ov176
 *   func_0217E298 0x0217E298 thumb ov176
 *   func_0217E074 0x0217E074 thumb ov176
 */
#include "../../matched/include/Obj04565.h"
#include "../../matched/include/Obj14378.h"
#include "../../matched/include/Obj14379.h"
#include "../../matched/include/Obj24455.h"
#include "../../matched/include/Obj00349.h"
#include "../../matched/include/Obj10715.h"
#include "../../matched/include/Obj01763.h"
#include "../../matched/include/Obj02890.h"

struct Obj0203159C;
struct Party;
struct PartyMon;
struct S020314B8;
struct S020315D4;
struct Big;
struct Sub02008700Obj;
struct Blk37;
struct Entry;
struct Link;
typedef unsigned int   u32_021E5440;

typedef struct {unsigned words[9];} Copy;

typedef signed int     s32;

typedef unsigned int   u32_021E54CC;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned u32_021E5524;

typedef unsigned int u32;

typedef struct { u8 *a; void *party; u32 f8; u8 fC, padD[3]; u32 f10; void *save; u8 tail[20]; } Args;

typedef struct { u8 pad[4]; void *party; } Other;

typedef struct {
    void *party;
    u32 f4, f8, fC, f10;
    u8 *a;
    u8 pad18[24];
    u16 f30, pad32;
    u32 f34, f38, f3C, f40;
    u16 f44, f46;
    u8 f48, marks[6], pad4F;
    u32 f50;
    u16 f54, pad56;
    u32 f58, pad5C;
    u16 f60, pad62;
    u32 f64;
    u8 pad68[12];
    u32 f74, f78;
    u8 f7C, pad7D[15];
    u32 f8C, f90;
} Output;

typedef unsigned long u32_021E58F4;

typedef unsigned int u32_021E5A44;

typedef unsigned int u32_021E5A70;

typedef unsigned int   u32_021E5A90;

extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32_021E5440 size, u32_021E5440 heap);
extern void MI_CpuFill8(void *,int,int);
extern void *PROCSYS_Create(int a0);
extern void *POKEPARTY_GetMember(void *,unsigned);
extern u32_021E54CC POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern void PLIST_COMM_End(void *);
extern void func_02034A5C(s32 handle);
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned);
extern int GFL_NET_GetRunState(void);
extern void *GFL_NET_GetInitParam(void);
extern u32_021E5524 func_0200FB24(void);
extern void GFL_NET_ERR_RequestScreen(void);
extern int DWC_RAPCOMMON_HandleNetError(void *,void *);
extern int func_02034AC4(int);
extern void PROCSYS_Push(void *,u32_021E5524,void *,void *);
extern u32_021E5524 PROCSYS_Main(void *);
extern void PLIST_COMM_Update(u8 *);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void PLIST_COMM_Start(u8 *);
extern u8 *func_02012944(void *p);
extern void *func_0200CA1C(void *a);
extern unsigned int POKEPARTY_GetCount(void *p);
extern u32 func_0200CA38(struct Blk37 *p);
extern void func_021E5B1C(int *p, void *c);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern char *func_021D9DC8(u32_021E58F4,void *,u32_021E58F4,u16);
extern u32_021E58F4 func_021DC200(char *,u32_021E58F4),func_021DC240(char *,u32_021E58F4);
extern void func_021D9EA0(u8 *p);
extern void *func_0217E00C(int unused, int heap);
extern int func_0217E258(int unused, int arg);
extern int func_0217E298(u8 *p, const void *q);
extern void func_0217E074(void *);
int func_021E5440(void *handle,int unused,char *q);
int func_021E54CC(void *handle,int unused,char *q,char *p);
int func_021E5524(void *unused,int unused2,char *q,char *p);
void func_021E56F4(Args *p, Other *o, Output *out);
void func_021E57E0(int *r5, int *r6, char *r4);
int func_021E5838(struct Obj0203159C *a, int b, int *p);
int func_021E5888(void *a, u32 b, u32 *c, void *d);
int func_021E58BC(u32 a, u32 b, u32 *c, void *d);
void func_021E58F0(int a0, int *a1, int a2);
int func_021E58F4(char **out,u32_021E58F4 *ctx,u32_021E58F4 *state);
void func_021E5A44(void **pp, u32_021E5A44 *c);
void func_021E5A70(u32_021E5A70 *out, u32_021E5A70 **pp, u32_021E5A70 v);
unsigned func_021E5A90(void **d,unsigned *c,unsigned *state);
extern unsigned d_02FFFC3C;
extern unsigned ov090_id[];
extern u8 ov091_id[],ov131_id[],gPartyListProcData[],gPokeStatusProcData[];
extern const char ov90_id[];
extern unsigned char ov067_id[],ov114_id[],ov175_id[];
extern u8 ov114_id[];
extern u8 ov067_id[];
extern u8 ov176_id[];




int func_021E5440(void *handle,int unused,char *q)
{
 char *p;
 GFL_HEAP_CreateChildHeap(1,0x58,0x30000);
 p=PROCSYS_AllocProcWork(handle,0xFC,0x58);
 MI_CpuFill8(p,0,0xFC);
 *(Copy *)(p+0xD4)=*(Copy *)q;
 ((struct Obj04565 *)p)->fF8=0x58;
 ((struct Obj04565 *)p)->fD0=PROCSYS_Create(((struct Obj04565 *)p)->fF8);
 ((struct Obj04565 *)p)->f4=((struct Obj14378 *)q)->f4;
 func_021E56F4((Args *)q, (Other *)p, (Output *)(p+8));func_021E57E0((int *)q,(int *)p,p+0xA0);
 ((struct Obj04565 *)p)->fC8=0;
 ((struct Obj04565 *)p)->fCC=d_02FFFC3C;
 ((struct Obj04565 *)p)->f0=0;((struct Obj14378 *)q)->f20=0;
 return 1;
}




int func_021E54CC(void *handle,int unused,char *q,char *p)
{
 unsigned char i;
 for(i=0;i<6;i++) {
 unsigned n=*(unsigned char *)(p+i+0x51);
 if(n!=0)POKEPARTY_Add(((struct Obj14379 *)q)->f1C,POKEPARTY_GetMember(((struct Obj14379 *)q)->f4,n-1));
 }
 PLIST_COMM_End(p+8);func_02034A5C((unsigned)ov090_id);
 func_0203133C(((struct Obj24455 *)p)->fD0);func_020315D4(handle);func_020306F0(0x58);
 return 1;
}




int func_021E5524(void *unused,int unused2,char *q,char *p)
{
    if(((struct Obj00349 *)p)->f98==1 && ((struct Obj00349 *)p)->f68!=0) {
        u32_021E5524 now;
        now=d_02FFFC3C;
        ((struct Obj00349 *)p)->fC8+=(u8)(now-((struct Obj00349 *)p)->fCC);
        ((struct Obj00349 *)p)->fCC=now;
        if(((struct Obj00349 *)p)->fC8>60) {
            --((struct Obj00349 *)p)->f68;
            ((struct Obj00349 *)p)->fC8-=60;
        }
    }
    if(GFL_NET_GetRunState()) {
        if(*((u8 *)GFL_NET_GetInitParam()+0x65)==3) {
            if(func_0200FB24()) {
                GFL_NET_ERR_RequestScreen();
                ((struct Obj10715 *)q)->f20=2;
                ((struct Obj00349 *)p)->f6B=1;((struct Obj00349 *)p)->fC4=1;
            }
        } else {
            int one;
            one=1;
            switch(DWC_RAPCOMMON_HandleNetError((void *)1,(void *)1)) {
            case 0:case 3:break;
            case 4:((struct Obj10715 *)q)->f20=3;((struct Obj00349 *)p)->f6B=one;((struct Obj00349 *)p)->fC4=one;break;
            case 1:case 2:default:((struct Obj10715 *)q)->f20=1;((struct Obj00349 *)p)->f6B=1;((struct Obj00349 *)p)->fC4=1;break;
            }
        }
    }
    switch(((struct Obj00349 *)p)->f0) {
    case 0:func_02034AC4((int)ov091_id);
        PROCSYS_Push(((struct Obj00349 *)p)->fD0,-1,gPartyListProcData,p+8);((struct Obj00349 *)p)->f0=1;break;
    case 1:if(PROCSYS_Main(((struct Obj00349 *)p)->fD0)==0)((struct Obj00349 *)p)->f0=2;break;
    case 2:func_02034A5C((int)ov091_id);
        if(((struct Obj00349 *)p)->f48==1) {((struct Obj00349 *)p)->fAF=((struct Obj00349 *)p)->f44;((struct Obj00349 *)p)->f0=3;}
        else return 1;
        break;
    case 3:func_02034AC4((int)ov131_id);
        PROCSYS_Push(((struct Obj00349 *)p)->fD0,-1,gPokeStatusProcData,p+0xa0);((struct Obj00349 *)p)->f0=4;break;
    case 4:
        if(((struct Obj00349 *)p)->f98==1 && ((struct Obj00349 *)p)->f68==0)((struct Obj00349 *)p)->fC4=1;
        if(PROCSYS_Main(((struct Obj00349 *)p)->fD0)==0)((struct Obj00349 *)p)->f0=5;break;
    case 5:func_02034A5C((int)ov131_id);
        if(((struct Obj00349 *)p)->f6B==0) {((struct Obj00349 *)p)->f44=((struct Obj00349 *)p)->fAF;((struct Obj00349 *)p)->f0=0;}
        else return 1;
        break;
    }
    if(((struct Obj00349 *)p)->f6B==0) {
        p+=8;
        PLIST_COMM_Update((u8 *)p);
    }
    return 0;
}




/*
 *  * note 2026-10-05 (wave P12 A7): DIFF 12/236 B, one residue: src and the record pointer
 * swap callee-saved registers (original src r6, record r5; build src r5, record r6).
 * Twin: ov134 021DCB48 (same typed Args/Output shape, matched; there src r5, record r6 is correct).
 * Tried, all 12 B: twin struct shape, int* params, typed record struct, const params (28 B),
 * b-before-a (18 B), save in local, declaration orders of a/b/i, block-local i, and each of
 * opt_lifetimes/opt_common_subs/opt_dead_assignments/scheduling/peephole off (12 B),
 * opt_propagation off (113 B). Callee returns: 02012EBC void*, 0200873C pointer, 02034AC4 int.
 * Difference to the twin: here the second parameter stays live across the first call.
 * final push 2026-10-05 G4L3: still DIFF 12/236 B (same swap), 40 compiles, 3 rounds. New tries, all 12 B:
 * initializer decl for a, raw offsets for p, restrict out, party/mode/save locals, a via
 * inline getter or AView struct view, p copy local (arg, block-scope, q), whole body or tail in a
 * static inline, o as Args or const, u8* p with struct casts, a as u32 or const u8*, callee decls
 * u32 (02012EBC/0200873C), do-while marks loop, default: break, -lang c, opt_strength_reduction,
 * opt_loop_invariants, opt_unroll_loops off. Dead ends: no local a (78 B), b-before-a (18 B), int i (111 B).
 * Finding: moving the three p reads (f10,f8,fC) before the switch (p dies earlier) gives the original
 * colours (p r6, a r5) but changes the code (125 B), so the swap is p's live range / degree against
 * the colouring threshold, not source order of p and a. mwcc Coloring.c (inspiredrobot/mwcc): nodes of
 * degree >= K are chosen by spill_cost/degree and p wins the lower register here. The original p
 * has the same live range in the listing, so the lever must change cost or degree without code.
 * pass 2 2026-10-06 P2L25: EXACT. The p/a colour swap was the source order of the stores after the
 * second call: out->f10 then out->a before out->f34 and out->f30 (code order is unchanged; the earlier
 * pcode position of the a store gives a the higher spill score, so a takes r5 and p r6).
 */
void func_021E56F4(Args *p, Other *o, Output *out)
{
    u8 *a;
    void *b;
    u8 i;
    a = p->a;
    b = GAME_DATA_GetSaveControl(p->save);
    out->party = o->party;
    out->f4 = 0;
    out->f8 = 0;
    out->fC = (u32)func_0200873C(b);
    out->f10 = 0;
    out->a = a;
    out->f34 = 26;
    out->f30 = 0;
    switch (a[0xba]) {
    case 0: out->f38 = 0; out->f64 = 1; break;
    case 1: out->f38 = 1; out->f64 = 1; break;
    case 2: out->f38 = 1; out->f64 = 1; break;
    case 3: out->f38 = 1; out->f64 = 1; break;
    case 4: out->f38 = 2; out->f64 = 2; break;
    }
    out->f44 = 0;
    out->f46 = 0;
    out->f48 = 0;
    out->f3C = 0;
    out->f40 = 0;
    for (i = 0; i < 6; i++) out->marks[i] = 0;
    out->f50 = 0;
    out->f58 = 0;
    out->f54 = 0;
    out->f74 = p->f10;
    out->f78 = p->f8;
    out->f7C = p->fC;
    out->f8C = a[184];
    if (a[185] != 0) {
        out->f90 = 1;
        out->f60 = a[185];
    } else {
        out->f90 = 0;
        out->f60 = 0;
    }
    func_02034AC4((int)ov90_id);
    PLIST_COMM_Start((u8 *)out);
}





/*
 * Populate the 0x28-byte record from the two source objects.
 */
void func_021E57E0(int *r5, int *r6, char *r4)
{
    int a;
    int b;
    a = (int)GAME_DATA_GetSaveControl((struct Big *)r5[5]);
    func_02012944((void *)r5[5]);
    b = (int)func_0200CA1C((void *)r5[5]);
    ((struct Obj01763 *)r4)->f0 = r6[1];
    ((struct Obj01763 *)r4)->f8 = r5[5];
    ((struct Obj01763 *)r4)->f4 = (int)func_0200873C((void *)a);
    ((struct Obj01763 *)r4)->fC = 1;
    ((struct Obj01763 *)r4)->fD = 1;
    ((struct Obj01763 *)r4)->fE = POKEPARTY_GetCount((void *)r6[1]);
    ((struct Obj01763 *)r4)->fF = 0;
    ((struct Obj01763 *)r4)->f10 = 0;
    ((struct Obj01763 *)r4)->f11 = 0;
    ((struct Obj01763 *)r4)->f12 = 0;
    ((struct Obj01763 *)r4)->f14 = 0;
    ((struct Obj01763 *)r4)->f18 = func_0200CA38((struct Blk37 *)b);
    ((struct Obj01763 *)r4)->f20 = 0;
    ((struct Obj01763 *)r4)->f24 = 0;
}





/*
 * Allocate the 0x58-byte subobject and dispatch on track[1].
 */
int func_021E5838(struct Obj0203159C *a, int b, int *p)
{
    int h;
    GFL_HEAP_CreateChildHeap(1, 0x58, 0x10000);
    h = (int)PROCSYS_AllocProcWork(a, 4, 0x58);
    MI_CpuFill8((void *)h, 0, 4);
    p[2] = 0;
    switch (p[1]) {
    case 0:
        func_021E58F0(h, p, 0x58);
        break;
    case 1:
        func_021E5A70((u32_021E5A70 *)((u32 *)h), (u32_021E5A70 * *)((u32 **)p), 0x58);
        break;
    }
    return 1;
}




int func_021E5888(void *a, u32 b, u32 *c, void *d)
{
    switch (c[1]) {
    case 0:
        func_021E5A44(d, (u32_021E5A44 *)c);
        break;
    case 1:
        func_021E5B1C(d, c);
        break;
    }
    func_020315D4(a);
    func_020306F0(0x58);
    return 1;
}




int func_021E58BC(u32 a, u32 b, u32 *c, void *d)
{
    u32 r;

    switch (c[1]) {
    case 0:
        r = func_021E58F4(d, (u32_021E58F4 *)c, (u32_021E58F4 *)((u32 *)b));
        break;
    case 1:
        r = func_021E5A90(d, c, (unsigned int *)b);
        break;
    }
    return r != 0;
}



/*
 * extent: bx lr followed by two zero alignment bytes.
 */
void func_021E58F0(int a0, int *a1, int a2) {}


int func_021E58F4(char **out,u32_021E58F4 *ctx,u32_021E58F4 *state)
{
    if(GFL_NET_GetRunState()) {
        switch(DWC_RAPCOMMON_HandleNetError((void *)1,(void *)1)) {
        case 0:break;
        case 1:case 4:ctx[2]=3;return 1;
        case 2:case 3:default:ctx[2]=1;return 1;
        }
    }
    switch(*state) {
    case 0:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),16,36);++*state;break;
    case 1:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),16,36))++*state;break;
    case 2:func_02034AC4((int)ov067_id);func_02034AC4((int)ov114_id);func_02034AC4((int)ov175_id);
        *out=func_021D9DC8(ctx[5],**(void ** *)&((struct Obj02890 *)ctx)->f0,0,88);++*state;break;
    case 3:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),17,36);++*state;break;
    case 4:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),17,36))++*state;break;
    case 5:if(func_021DC200(*out,ctx[3]))++*state;break;
    case 6:if(func_021DC240(*out,ctx[4]))++*state;break;
    case 7:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),18,36);++*state;break;
    case 8:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),18,36))++*state;break;
    case 9:func_021D9EA0((u8 *)((u32_021E58F4)*out));*out=0;
        func_02034A5C((int)ov175_id);func_02034A5C((int)ov114_id);func_02034A5C((int)ov067_id);++*state;break;
    case 10:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),19,36);++*state;break;
    case 11:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),19,36))return 1;break;
    }
    return 0;
}



void func_021E5A44(void **pp, u32_021E5A44 *c)
{
    if (*pp == 0)
        return;
    func_021D9EA0((u8 *)((u32_021E5A44)*pp));
    func_02034A5C((u32_021E5A44)ov175_id);
    func_02034A5C((u32_021E5A44)ov114_id);
    func_02034A5C((u32_021E5A44)ov067_id);
}



void func_021E5A70(u32_021E5A70 *out, u32_021E5A70 **pp, u32_021E5A70 v)
{
    func_02034AC4((u32_021E5A70)ov176_id);
    *out = (u32_021E5A70)func_0217E00C(*(u32_021E5A70 *)*pp, v);
}


unsigned func_021E5A90(void **d,unsigned *c,unsigned *state)
{
 if(func_0200FB24()!=0){GFL_NET_ERR_RequestScreen();c[2]=2;return 1;}
 switch(*state) {
 case 0:++*state;break;
 case 1:GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x11,0x1F);++*state;break;
 case 2:if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x11,0x1F)!=0)++*state;break;
 case 3:if(func_0217E258((int)(*d),c[3])!=0)++*state;break;
 case 4:if(func_0217E298(*d,(const void *)c[4])!=0)++*state;break;
 case 5:return 1;
 }
 func_0217E074(*d);return 0;
}

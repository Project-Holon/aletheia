/*
 * file:     zukan.c
 * unit:     yes
 * function: ZUKAN_Create, ZUKAN_Update, ZUKAN_Delete, ZUKAN_FreeIdList, ZUKAN_SetResumeState, ZUKAN_GetResumeState, ZUKAN_StartProc211, ZUKAN_ResumeProc211, ZUKAN_StartProc209, ZUKAN_ResumeProc209, ZUKAN_StartProc210, ZUKAN_ResumeProc210, ZUKAN_StartProc208, ZUKAN_ResumeProc208, ZUKAN_LoadListAndSelection, ZUKAN_FixLastViewedSpecies, ZUKAN_IsNationalMode, ZUKAN_InitQuery, ZUKAN_StartWipeIn, ZUKAN_StartWipeOut, ZUKAN_TickCounter, ZUKAN_CreateActor
 * address:  0x021C8E80
 * region:   ov212
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zukan.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Main 0x02031330 arm
 *   d_021C9944 0x021C9944 data a4
 *   func_02030734 0x02030734 arm
 *   PROCSYS_Push 0x02031348 arm
 *   d_021C99A0 0x021C99A0 data a1
 *   d_021BC8BC 0x021BC8BC data ov211 a4
 *   ov211_id 0x000000D3 data a1
 *   d_021BE794 0x021BE794 data ov209 a4
 *   ov209_id 0x000000D1 data a1
 *   func_020307B0 0x020307B0 arm
 *   d_021C0714 0x021C0714 data ov210 a4
 *   ov210_id 0x000000D2 data a1
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_GetLastViewedSpecies 0x0200CA8C thumb
 *   d_021C8108 0x021C8108 data ov208 a4
 *   ov208_id 0x000000D0 data a1
 *   ZUKAN_SAVE_SetLastViewedSpecies 0x0200CA78 thumb
 *   ZUKAN_SAVE_GetViewMode 0x0200CA70 thumb
 *   ZUKAN_SAVE_IsCaught 0x0200CED4 thumb
 *   ZUKAN_SAVE_IsSeen 0x0200D064 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 *   BG_SYS_ResetSlot  0x02041EE4  arm  arm9
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm  arm9
 *   ZUKAN_SEARCH_ENGINE_LoadSpeciesIds 0x021C976C thumb ov212
 */
#include "../../matched/include/Obj00635.h"
#include "../../matched/include/Obj25642.h"
#include "../../matched/include/Obj25643.h"
#include "../../matched/include/Obj25644.h"
#include "../../matched/include/Obj25645.h"
#include "../../matched/include/Obj25646.h"
#include "../../matched/include/Obj25647.h"
#include "../../matched/include/Obj25648.h"
#include "../../matched/include/Obj25649.h"
#include "../../matched/include/Obj25650.h"
#include "../../matched/include/Obj08415.h"
#include "../../matched/include/Obj08416.h"
#include "../../matched/include/Obj25651.h"
#include "../../matched/include/Obj06701.h"
#include "../../matched/include/Obj25653.h"
#include "../../matched/include/Obj08417.h"
#include "../../matched/include/Obj25654.h"
#include "../../matched/include/Obj25655.h"
#include "../../matched/include/Obj25656.h"
#include "../../matched/include/Obj02259.h"
#include "../../matched/include/Obj04626.h"
#include "../../matched/include/Obj25658.h"
#include "../../matched/include/Obj25659.h"
#include "../../matched/include/Obj01587.h"
#include "../../matched/include/Obj25660.h"
#include "../../matched/include/Obj25661.h"
#include "../../matched/include/Obj25662.h"
#include "../../matched/include/Obj25663.h"
#include "../../matched/include/Obj25664.h"
#include "../../matched/include/Obj25665.h"
#include "../../matched/include/Obj25666.h"
#include "../../matched/include/Obj06702.h"
#include "../../matched/include/Obj06703.h"
#include "../../matched/include/Obj25668.h"
#include "../../matched/include/Obj04627.h"
#include "../../matched/include/Obj10926.h"
#include "../../matched/include/Obj25669.h"
#include "../../matched/include/Obj04628.h"
#include "../../matched/include/Obj04629.h"
#include "../../matched/include/Obj08418.h"
#include "zukan_shared_types.h"

struct Obj0203159C;

struct Blk37;

struct S020314B8;

struct S020315D4;

struct Obj020314F4;

struct Obj;

/* hidden function: 16 bytes between ZUKAN_SetResumeState and ZUKAN_StartProc211 */
struct Obj021C8F98 {
    u32 f0, f4, f8, fC, f10, f14, f18, f1C, f20;
};

extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);

extern void *PROCSYS_AllocProcWork(struct Obj0203159C *,unsigned,unsigned);

extern void MI_CpuFill8(void *,unsigned char,unsigned);

extern void *PROCSYS_Create(int);

extern unsigned PROCSYS_Main(void *);

extern void func_0203133C(struct S020314B8 *);

extern void func_020315D4(struct S020315D4 *);

extern void GFL_HEAP_DeleteChecked(u32 heap);

extern u32 func_020307B0(void *p);

extern void *func_02030734(unsigned,unsigned,int,const char *,u16);

extern void PROCSYS_Push(struct Obj020314F4 *,unsigned,unsigned,unsigned);

extern void *ZUKAN_SAVE_GetFromGameData(void *);

extern u16 ZUKAN_SAVE_GetLastViewedSpecies(struct Blk37 *);

extern void ZUKAN_SAVE_SetLastViewedSpecies(struct Blk37 *p, u32 v);

extern unsigned ZUKAN_SAVE_GetViewMode(struct Blk37 *);

extern unsigned ZUKAN_SAVE_IsCaught(struct Blk37 *,u16);

extern unsigned ZUKAN_SAVE_IsSeen(struct Blk37 *,u16);

extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);

extern void BG_SYS_ResetSlot(u32,u32,u32);

extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

int ZUKAN_Create(struct Obj0203159C *obj,int unused,char *ctx);

int ZUKAN_Update(int a,int b,int c,unsigned char *p);

int ZUKAN_Delete(struct S020315D4 *obj, void *b, void *c, u8 *p);

void ZUKAN_FreeIdList(u8 *p);

int ZUKAN_SetResumeState(char *p, int v);

u32 ZUKAN_GetResumeState(struct Obj021C8F98 *p);

void ZUKAN_StartProc211(char *p);

int ZUKAN_ResumeProc211(u8 *p);

void ZUKAN_StartProc209(char *p);

int ZUKAN_ResumeProc209(char *p);

void ZUKAN_StartProc210(char *p);

int ZUKAN_ResumeProc210(char *p);

void ZUKAN_StartProc208(char *p);

int ZUKAN_ResumeProc208(char *p);

u16 ZUKAN_LoadListAndSelection(struct Blk37 *save,u16 **out,unsigned heap);

void ZUKAN_FixLastViewedSpecies(void *p,u16 *ids,unsigned count);

int ZUKAN_IsNationalMode(struct Blk37 *p);

void ZUKAN_InitQuery(struct Blk37 *p, u8 *out);

void ZUKAN_StartWipeIn(u32 heap);

void ZUKAN_StartWipeOut(u32 heap);

void ZUKAN_TickCounter(u32 a, u32 b, u32 *counter);

struct Obj *ZUKAN_CreateActor(u32 bank, const u8 *t, u16 heap);

u32 ZUKAN_SEARCH_ENGINE_LoadSpeciesIds(u32 mode,int heap,u16 **out);

extern unsigned char d_021C9944[];

extern const char d_021C99A0[];

extern const unsigned d_021BC8BC[];

extern unsigned char ov211_id[];

extern const unsigned d_021BE794[];

extern unsigned char ov209_id[];

extern const unsigned d_021C0714[];

extern unsigned char ov210_id[];

extern const unsigned d_021C8108[];

extern unsigned char ov208_id[];

/*
 * trailing: two zero alignment bytes at 021C8F2A.
 * prototype: caller consumes r0 from legacy void 0203159C and 02031324;
 * 31324 forwards r0 to matched 31354(int), which returns allocation.
 * 3064C visibly receives three inputs here; retain caller's r2 size.
 */
int ZUKAN_Create(struct Obj0203159C *obj,int unused,char *ctx)
{
    char *p;
    GFL_HEAP_CreateChildHeap(1,105,0x8000);
    p=PROCSYS_AllocProcWork(obj,44,105);
    MI_CpuFill8(p,0,44);
    ((struct Obj00635 *)p)->f0=ctx;
    ((struct Obj00635 *)p)->f4=PROCSYS_Create(105);
    ((struct Obj00635 *)p)->f10=ZUKAN_LoadListAndSelection(*(struct Blk37 * *)&((struct Obj25642 *)(*(char * *)&((struct Obj00635 *)p)->f0))->f4,(u16 **)(p+12),105);
    ((struct Obj00635 *)p)->f12=0;
    ZUKAN_FixLastViewedSpecies(*(struct Blk37 * *)&((struct Obj25643 *)(*(char * *)&((struct Obj00635 *)p)->f0))->f4,*(u16 * *)&((struct Obj00635 *)p)->fC,((struct Obj00635 *)p)->f10);
    ZUKAN_InitQuery(*(struct Blk37 * *)&((struct Obj25644 *)(*(char * *)&((struct Obj00635 *)p)->f0))->f4,(unsigned char *)(p+20));
    if(((struct Obj25645 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==0){((struct Obj00635 *)p)->f1C=1;}
    else if(((struct Obj25646 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==1){((struct Obj00635 *)p)->f1C=3;}
    else if(((struct Obj25647 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==2){((struct Obj00635 *)p)->f1C=5;((struct Obj00635 *)p)->f24=1;}
    else if(((struct Obj25648 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==3){((struct Obj00635 *)p)->f1C=5;((struct Obj00635 *)p)->f24=2;}
    else if(((struct Obj25649 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==4){((struct Obj00635 *)p)->f1C=5;((struct Obj00635 *)p)->f24=3;}
    else if(((struct Obj25650 *)(*(char * *)&((struct Obj00635 *)p)->f0))->fC==5){((struct Obj00635 *)p)->f1C=5;((struct Obj00635 *)p)->f24=4;}
    else {((struct Obj00635 *)p)->f1C=7;}
    return 1;
}

int ZUKAN_Update(int a,int b,int c,unsigned char *p){if(((struct Obj08415 *)p)->f1C==9)return 1;((struct Obj08415 *)p)->f8=PROCSYS_Main(((struct Obj08415 *)p)->f4);((struct Obj08415 *)p)->f1C=(*(unsigned (**)(unsigned char *))(d_021C9944+*(unsigned *)(p+28)*4))(p);return 0;}

int ZUKAN_Delete(struct S020315D4 *obj, void *b, void *c, u8 *p) {
    ZUKAN_FreeIdList(p);
    func_0203133C(*(struct S020314B8 * *)&((struct Obj08416 *)p)->f4);
    func_020315D4(obj);
    GFL_HEAP_DeleteChecked(105);
    return 1;
}

void ZUKAN_FreeIdList(u8 *p)
{
    if (((struct Obj08416 *)p)->fC != 0) {
        func_020307B0(((struct Obj08416 *)p)->fC);
        ((struct Obj08416 *)p)->fC = 0;
    }
}

int ZUKAN_SetResumeState(char *p, int v)
{
    ((struct Obj25651 *)p)->f20 = v;
    return 0;
}

u32 ZUKAN_GetResumeState(struct Obj021C8F98 *p)
{
    if (p->f8 != 1)
        return p->f20;
    return 0;
}

void ZUKAN_StartProc211(char *p)
{
    unsigned *q;
    q=func_02030734(105,12,0,d_021C99A0,297);
    ((struct Obj06701 *)p)->f28=q;
    q[0]=**(unsigned * *)&((struct Obj06701 *)p)->f0;
    q[1]=((struct Obj25653 *)(*(char * *)&((struct Obj06701 *)p)->f0))->f8;
    PROCSYS_Push(*(struct Obj020314F4 * *)&((struct Obj06701 *)p)->f4,(unsigned)ov211_id,(unsigned)d_021BC8BC,*(unsigned *)&((struct Obj06701 *)p)->f28);
    ZUKAN_SetResumeState(p,2);
}

int ZUKAN_ResumeProc211(u8 *p) {
    int result;
    switch (((struct Obj25654 *)(*(u8 * *)&((struct Obj08417 *)p)->f28))->f8) {
    case 0:
        ((struct Obj25655 *)(*(u8 * *)&((struct Obj08417 *)p)->f0))->fE = 0;
        result = 9;
        break;
    case 1:
        ((struct Obj25656 *)(*(u8 * *)&((struct Obj08417 *)p)->f0))->fE = 1;
        result = 9;
        break;
    case 2: result = 3; break;
    }
    func_020307B0(((struct Obj08417 *)p)->f28);
    return result;
}

/*
 * prototype: 02031348 legacy void(void) forwards r0-r3 to 020314F4,
 * whose matched body reads all four; this caller sets all four.
 */
void ZUKAN_StartProc209(char *p)
{
    char *q=func_02030734(105,20,0,d_021C99A0,359);
    ((struct Obj02259 *)p)->f28=q;
    ((struct Obj04626 *)q)->f0=**(unsigned * *)&((struct Obj02259 *)p)->f0;
    ((struct Obj04626 *)q)->f4=((struct Obj25658 *)(*(char * *)&((struct Obj02259 *)p)->f0))->f4;
    ((struct Obj04626 *)q)->f8=((struct Obj02259 *)p)->f12;
    if(((struct Obj02259 *)p)->f12==0&&ZUKAN_IsNationalMode(*(struct Blk37 * *)&((struct Obj25659 *)(*(char * *)&((struct Obj02259 *)p)->f0))->f4)==0){
        *(u16 * *)&((struct Obj04626 *)q)->fC=*(u16 * *)&((struct Obj02259 *)p)->fC+1;
        ((struct Obj04626 *)q)->fA=((struct Obj02259 *)p)->f10-1;
    }else{
        ((struct Obj04626 *)q)->fC=((struct Obj02259 *)p)->fC;
        ((struct Obj04626 *)q)->fA=((struct Obj02259 *)p)->f10;
    }
    PROCSYS_Push(*(struct Obj020314F4 * *)&((struct Obj02259 *)p)->f4,(unsigned)ov209_id,(unsigned)d_021BE794,*(unsigned *)&((struct Obj02259 *)p)->f28);
    ZUKAN_SetResumeState(p,4);
}

/*
 * lever: spell the empty-result arm first in the nested if/else;
 * shared failure exit remains after the switch.
 */
int ZUKAN_ResumeProc209(char *p)
{
    int result;
    switch(((struct Obj25660 *)(*(char * *)&((struct Obj01587 *)p)->f28))->f10){
    case 0:
        if(((struct Obj01587 *)p)->f12==0){
            ((struct Obj25661 *)(*(char * *)&((struct Obj01587 *)p)->f0))->fE=0;result=9;
        }else{
            ZUKAN_FreeIdList((u8 *)p);
            ((struct Obj01587 *)p)->f10=ZUKAN_LoadListAndSelection(*(struct Blk37 * *)&((struct Obj25662 *)(*(char * *)&((struct Obj01587 *)p)->f0))->f4,(u16 **)(p+12),105);
            ((struct Obj01587 *)p)->f12=0;result=3;
        }
        goto done;
    case 1:((struct Obj25663 *)(*(char * *)&((struct Obj01587 *)p)->f0))->fE=1;result=9;goto done;
    case 2:
        ZUKAN_FreeIdList((u8 *)p);
        ((struct Obj01587 *)p)->f10=ZUKAN_LoadListAndSelection(*(struct Blk37 * *)&((struct Obj25664 *)(*(char * *)&((struct Obj01587 *)p)->f0))->f4,(u16 **)(p+12),105);
        result=3;goto done;
    case 3:result=5;((struct Obj01587 *)p)->f24=1;goto done;
    case 4:
        if(((struct Obj01587 *)p)->f12==1){
            ZUKAN_FreeIdList((u8 *)p);
            ((struct Obj01587 *)p)->f10=ZUKAN_LoadListAndSelection(*(struct Blk37 * *)&((struct Obj25665 *)(*(char * *)&((struct Obj01587 *)p)->f0))->f4,(u16 **)(p+12),105);
        }
        result=7;goto done;
    default:break;
    }
    ((struct Obj25666 *)(*(char * *)&((struct Obj01587 *)p)->f0))->fE=0;result=9;
done:
    func_020307B0(((struct Obj01587 *)p)->f28);
    return result;
}

/*
 * prototype: 02031348 legacy void(void) forwards untouched r0-r3 to
 * 020314F4; its matched body reads all four and caller sets all four.
 */
void ZUKAN_StartProc210(char *p)
{
    char *q;
    q=func_02030734(105,24,0,d_021C99A0,455);
    ((struct Obj06702 *)p)->f28=q;
    ((struct Obj06703 *)q)->f0=**(unsigned * *)&((struct Obj06702 *)p)->f0;
    ((struct Obj06703 *)q)->f4=((struct Obj25668 *)(*(char * *)&((struct Obj06702 *)p)->f0))->f4;
    ((struct Obj06703 *)q)->f8=p+20;
    ((struct Obj06703 *)q)->f10=0;
    ((struct Obj06703 *)q)->f14=0;
    PROCSYS_Push(*(struct Obj020314F4 * *)&((struct Obj06702 *)p)->f4,(unsigned)ov210_id,(unsigned)d_021C0714,*(unsigned *)&((struct Obj06702 *)p)->f28);
    ZUKAN_SetResumeState(p,8);
}

/*
 * trailing: two zero alignment bytes at 021C91C2.
 * lever: assign the result in each arm after its stores, keeping r4 reusable.
 */
int ZUKAN_ResumeProc210(char *p)
{
    char *q=*(char * *)&((struct Obj04627 *)p)->f28;
    int result;
    switch(((struct Obj10926 *)q)->fC){
    case 0:
        ZUKAN_FreeIdList((u8 *)p);
        ((struct Obj04627 *)p)->fC=((struct Obj10926 *)q)->f10;
        ((struct Obj04627 *)p)->f10=((struct Obj10926 *)q)->f14;
        ((struct Obj04627 *)p)->f12=1;
        result=3;
        break;
    case 1:
        ((struct Obj04627 *)p)->f12=0;
        result=3;
        break;
    case 2:
    default:
        ((struct Obj25669 *)(*(char * *)&((struct Obj04627 *)p)->f0))->fE=1;
        result=9;
        break;
    }
    func_020307B0(((struct Obj04627 *)p)->f28);
    return result;
}

/*
 * prototype: 02031348 forwards all four original inputs to 020314F4;
 * the matched forwarding target reads each, overriding legacy void(void).
 */
void ZUKAN_StartProc208(char *p)
{
    char *q;
    u16 selected,i;
    selected=ZUKAN_SAVE_GetLastViewedSpecies(ZUKAN_SAVE_GetFromGameData(*(void **)*(char * *)&((struct Obj04628 *)p)->f0));
    q=func_02030734(105,20,0,d_021C99A0,530);
    ((struct Obj04629 *)q)->f0=**(unsigned * *)&((struct Obj04628 *)p)->f0;
    ((struct Obj04629 *)q)->f4=((struct Obj04628 *)p)->f24;
    ((struct Obj04629 *)q)->f8=((struct Obj04628 *)p)->fC;
    ((struct Obj04629 *)q)->fC=((struct Obj04628 *)p)->f10;
    ((struct Obj04629 *)q)->fE=0;
    for(i=0;i<((struct Obj04629 *)q)->fC;i++){
        if((*(u16 **)(q+8))[i]==selected){((struct Obj04629 *)q)->fE=i;break;}
    }
    PROCSYS_Push(*(struct Obj020314F4 * *)&((struct Obj04628 *)p)->f4,(unsigned)ov208_id,(unsigned)d_021C8108,(unsigned)q);
    ((struct Obj04628 *)p)->f28=q;
    ZUKAN_SetResumeState(p,6);
}

int ZUKAN_ResumeProc208(char *p)
{
    struct Blk37 *save;
    char *q;
    int result;
    save = ZUKAN_SAVE_GetFromGameData(*(void **)*(char **)p);
    q = *(char **)(p + 0x28);
    ZUKAN_SAVE_SetLastViewedSpecies(save, (*(u16 **)(q + 8))[*(u16 *)(q + 14)]);
    switch (*(int *)(q + 0x10)) {
    case 0:
        *(u16 *)(*(char **)p + 14) = 1;
        result = 9;
        break;
    case 1:
        *(u16 *)(*(char **)p + 14) = 0;
        result = 3;
        break;
    }
    func_020307B0(*(void **)(p + 0x28));
    return result;
}

/*
 * lever: branch-local calls retain the original boolean polarity and hoist
 * the shared output-address setup; initializing selected follows the call.
 */
u16 ZUKAN_LoadListAndSelection(struct Blk37 *save,u16 **out,unsigned heap)
{
    u16 *list;
    unsigned count,i;
    u16 selected;
    if(ZUKAN_SAVE_GetViewMode(save)==1)count=ZUKAN_SEARCH_ENGINE_LoadSpeciesIds(0,heap,&list);
    else count=ZUKAN_SEARCH_ENGINE_LoadSpeciesIds(1,heap,&list);
    selected=0;
    for(i=0;i<count;i++){
        if(ZUKAN_SAVE_IsCaught(save,list[i])==1||ZUKAN_SAVE_IsSeen(save,list[i])==1)selected=i+1;
    }
    *out=list;
    return selected;
}

void ZUKAN_FixLastViewedSpecies(void *p,u16 *ids,unsigned count)
{
    unsigned current;
    u16 chosen,i;
    chosen=0xFFFF;current=ZUKAN_SAVE_GetLastViewedSpecies(p);
    for(i=0;i<count;i++) {
        if(ZUKAN_SAVE_IsSeen(p,ids[i])==1) {
            if(current==ids[i]) return;
            if(chosen==0xFFFF) chosen=ids[i];
        }
    }
    if(chosen!=0xFFFF) ZUKAN_SAVE_SetLastViewedSpecies(p,chosen);
}

int ZUKAN_IsNationalMode(struct Blk37 *p) {
    if (ZUKAN_SAVE_GetViewMode(p) == 1) return 1;
    if (ZUKAN_SAVE_IsCaught(p,494) == 1 || ZUKAN_SAVE_IsSeen(p,494) == 1) return 1;
    return 0;
}

void ZUKAN_InitQuery(struct Blk37 *p, u8 *out) {
    if(ZUKAN_SAVE_GetViewMode(p)==1) out[0]=0; else out[0]=1;
    out[1]=0; out[2]=255; out[3]=255; out[4]=255; out[5]=255; out[6]=255;
}

void ZUKAN_StartWipeIn(u32 heap) { WIPE_SYS_Start(0,1,1,0,6,1,heap); }

void ZUKAN_StartWipeOut(u32 heap) { WIPE_SYS_Start(0,0,0,0,6,1,heap); }

void ZUKAN_TickCounter(u32 a, u32 b, u32 *counter) {
    ++*counter;
    if(*counter==4) { BG_SYS_ResetSlot(a,1,1); BG_SYS_ResetSlot(b,1,1); *counter=0; }
}

struct Obj *ZUKAN_CreateActor(u32 bank, const u8 *t, u16 heap) {
    return CLACT_CreateActor((void *)bank,*(const u32 *)&((struct Obj08418 *)t)->f8,*(const u32 *)&((struct Obj08418 *)t)->fC,*(const u32 *)&((struct Obj08418 *)t)->f10,t,*(const u16 *)&((struct Obj08418 *)t)->f16,heap);
}

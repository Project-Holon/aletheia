/*
 * file:     battle_championship_flow.c
 * unit:     yes
 * function: func_0217AE20, func_0217AE88, func_0217AECC, func_0217AEF4, func_0217AF04, func_0217AF14, func_0217AF2C, func_0217AF44, func_0217AF50, func_0217AF9C, func_0217AFBC, func_0217AFD0, func_0217B00C, func_0217B014, func_0217B064, func_0217B0C8, func_0217B1BC, func_0217B2E4, func_0217B344, func_0217B35C, func_0217B368, func_0217B380, func_0217B3B8, func_0217B3C0, func_0217B468, func_0217B4A0, func_0217B55C, func_0217B594, func_0217B620, func_0217B6AC, func_0217B768, func_0217B7A0, func_0217B7D8, func_0217B924, func_0217B930, func_0217B93C, func_0217B950, func_0217B964, func_0217B970
 * address:  0x0217AE20
 * region:   ov176
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from battle_championship_flow.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_021E8A3C 0x021E8A3C thumb ov177
 *   BTLV_CORE_IsSlotKind1Index15  0x021E8A78  thumb  ov093
 *   func_02034A5C  0x02034A5C  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   ov177_id       0x000000B1  data
 *   ov67_id        0x00000043  data
 *   func_021E8A80 0x021E8A80 thumb ov177
 *   func_021E8A90 0x021E8A90 thumb ov177
 *   func_021E5440  0x021E5440  thumb  ov177
 *   func_021E54E0  0x021E54E0  thumb  ov177
 *   func_021E5534  0x021E5534  thumb  ov177
 *   func_021E5980  0x021E5980  thumb  ov177
 *   func_021E5548  0x021E5548  thumb  ov177
 *   func_021E567C  0x021E567C  thumb  ov177
 *   func_021E5868 0x021E5868 thumb ov177
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_021E8568 0x021E8568 thumb ov177
 *   func_021E8628  0x021E8628  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   func_021E867C  0x021E867C  thumb  ov177
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8AA8 0x021E8AA8 thumb ov177
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   func_02034714 0x02034714 arm
 *   d_0217E5E0 0x0217E5E0 data a1
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   func_02030734 0x02030734 arm
 *   d_0217E5E4 0x0217E5E4 data a1
 *   func_020307B0 0x020307B0 arm
 *   func_0202EB44 0x0202EB44 thumb
 *   BATTLE_REC_ClearWork 0x0200B480 thumb
 *   func_0217D398 0x0217D398 thumb ov176
 *   func_0217D434 0x0217D434 thumb ov176
 *   func_0217D44C 0x0217D44C thumb ov176
 *   func_0217D410 0x0217D410 thumb ov176
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   func_021E88B0 0x021E88B0 thumb ov177
 *   func_021E89D0 0x021E89D0 thumb ov177
 *   func_021E8A00 0x021E8A00 thumb ov177
 *   func_021E8738  0x021E8738  thumb  ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_0217B984 0x0217B984 thumb ov176
 *   func_0217BA9C 0x0217BA9C thumb ov176
 *   func_0217BAF4 0x0217BAF4 thumb ov176
 *   func_0217BB3C 0x0217BB3C thumb ov176
 */
#include "../../matched/include/Obj10694.h"
#include "../../matched/include/Obj03869.h"
#include "../../matched/include/Obj04561.h"
#include "../../matched/include/Obj14355.h"
#include "../../matched/include/Obj10695.h"
#include "../../matched/include/Obj02888.h"
#include "../../matched/include/Obj24399.h"
#include "../../matched/include/Obj24400.h"
#include "../../matched/include/Obj24401.h"
#include "../../matched/include/Obj24402.h"
#include "../../matched/include/Obj10698.h"
#include "../../matched/include/Obj14356.h"
#include "../../matched/include/Obj14357.h"
#include "../../matched/include/Obj24404.h"
#include "../../matched/include/Obj02221.h"
#include "../../matched/include/Obj02222.h"
#include "../../matched/include/Obj01762.h"
#include "../../matched/include/Obj24405.h"
#include "battle_championship_flow_shared_types.h"

struct Obj0203159C;

struct S020315D4;

struct PrintSys;

typedef unsigned int   u32_0217B064;

typedef struct Data { unsigned words[8]; } Data;

typedef unsigned u32_0217B1BC;

typedef struct {u32_0217B1BC w[10];} Init_0217AE20;

typedef struct { int mode; int a,b,c,d,e,f,g; } Config;

typedef signed char s8;

extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);

extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);

extern void MI_CpuFill8(void *,int,unsigned);

extern int func_02034AC4(signed int);

extern int *func_021E8A3C(int a, int b, int c);

extern void BTLV_CORE_IsSlotKind1Index15(int);

extern void func_02034A5C(int);

extern void func_020315D4(struct S020315D4 *);

extern void func_020306F0(unsigned int);

extern void func_0217AF14(int *),func_0217AFBC(int *),func_021E8A80(CB *);

extern int func_021E8A90(int **);

extern int *func_021E5440(unsigned swap, int heap);

extern void func_021E54E0(char *p);

extern void func_021E5534(u8 *p);

extern void func_021E5980(int);

extern int func_021E5548(int *p);

extern u32 *func_021E567C(int unused, int mode, int heap);

extern void func_021E5868(void *);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern u32 PRINTSYS_QUE_Create(void *p);

extern void *func_021E8568(unsigned,unsigned,unsigned,unsigned,void *,void *,unsigned);

extern void func_021E8628(u32 a);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern u32 GF_FONT_Delete(void *ptr);

extern void func_021E867C(char *p);

extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

extern void func_021E8AA0(int *p, int v);

extern void func_021E8AA8(int a);

extern void FADE_Start(u32_0217B014 a, s32 b, s32 c, s32 d);

extern int FADE_IsActive(void);

extern void func_02034714(const char *expr, u32_0217B014 line, const char *file);

extern void GFL_USE_FadeOutBgm(u32_0217B064 a);

extern void *func_02030734(u32_0217B2E4 heapId, u32_0217B2E4 size, int clear, const char *site, u16 tag);

extern u32_0217B344 func_020307B0(void *p);

extern int func_0202EB44(void);

extern void BATTLE_REC_ClearWork(void);

extern int func_0217D398(Config *,int);

extern void func_0217D434(int *p);

extern int func_0217D44C(int *p);

extern void func_0217D410(int *p);

extern void *GAME_DATA_GetSaveControl(struct Big *p);

extern void *BATTLE_COMPETITION_GetFromSave(void *);

extern struct Rec160 *REGULATION_GetCard(struct Rec160 *arr, u32 index);

extern void *func_021E88B0(Menu_0217AE20 *,u8,u8,u8,u32,int);

extern void func_021E89D0(void *);

extern int func_021E8A00(void *);

extern void func_021E8738(int *p, int a, int b, int c);

extern int func_021E8844(const int *);

int func_0217AE20(void *a,void *b,void *context);

int func_0217AE88(int a, int b, int c, int *p);

int func_0217AECC(u32 a,u32 b,u32 c,int *p);

void func_0217AEF4(int *p);

void func_0217AF04(int *p);

void func_0217AF14(int *p);

void func_0217AF2C(int *p);

void func_0217AF44(int *p);

void func_0217AF50(char *p);

void func_0217AF9C(int *p);

void func_0217AFBC(int *p);

void func_0217AFD0(void *a,int b,char *p);

void func_0217B00C(void *a);

void func_0217B014(void *a,int *state,char *p);

void func_0217B064(void *a,int *state,char *p);

void func_0217B0C8(int *a,int *state,int *p);

void func_0217B1BC(int *a,int *state,int *p);

void *func_0217B2E4(const Data *src,unsigned heap);

void func_0217B344(int *p);

void func_0217B35C(CB **p);

int func_0217B368(int *p);

void func_0217B380(int a, int b, int *p);

void func_0217B3B8(int p);

void func_0217B3C0(int p, unsigned *state, int *q);

void func_0217B468(int *p,int *state,u8 *q);

void func_0217B4A0(int p,unsigned *state,int *q);

void func_0217B55C(int p,int *state,int *q);

void func_0217B594(int p, int *state, char *q);

void func_0217B620(int p, int *state, char *q);

void func_0217B6AC(int p,unsigned *state,int *q);

void func_0217B768(int *p,int *state,u8 *q);

void func_0217B7A0(int *p,int *state,u8 *q);

void func_0217B7D8(int *p, int index);

void func_0217B924(int *p);

unsigned func_0217B930(int *p);

void func_0217B93C(int *p, int b);

void func_0217B950(int *p, int b);

int func_0217B964(int *p);

void func_0217B970(int *p,int a);

u8 *func_0217B984(Init_0217B970 *src,u32_0217B984 heap);

void func_0217BA9C(int *p);

void func_0217BAF4(int *p);

int func_0217BB3C(int *p);

extern char ov67_id[],ov177_id[];

extern char ov67_id[];

extern const char d_0217E5E0[];

extern const char d_0217E5E4[];

int func_0217AE20(void *a,void *b,void *context)
{
    char *p;
    GFL_HEAP_CreateChildHeap(1,0x4e,0x30200);
    p=PROCSYS_AllocProcWork(a,0x34,0x4e);
    MI_CpuFill8(p,0,0x34);
    ((struct Obj10694 *)p)->f28=context;
    ((struct Obj10694 *)p)->f0=0x4e;
    func_02034AC4((int)ov67_id);
    func_02034AC4((int)ov177_id);
    func_0217AEF4((int *)p);
    func_0217AF2C((int *)p);
    func_0217AF50(p);
    ((struct Obj10694 *)p)->f4=func_021E8A3C((int)p,(int)func_0217B014,0x4e);
    return 1;
}

int func_0217AE88(int a, int b, int c, int *p)
{
    BTLV_CORE_IsSlotKind1Index15(((struct Obj03869 *)p)->f4);
    func_0217AF9C(p);
    func_0217AF44(p);
    func_0217AF04(p);
    func_02034A5C((int)ov177_id);
    func_02034A5C((int)ov67_id);
    func_020315D4((struct S020315D4 *)a);
    func_020306F0(0x4e);
    return 1;
}

int func_0217AECC(u32 a,u32 b,u32 c,int *p) {func_0217AF14(p);func_0217AFBC(p);func_021E8A80(*(CB * *)&((struct Obj04561 *)p)->f4);if(func_021E8A90(*(int ** *)&((struct Obj04561 *)p)->f4)) return 1;return 0;}

void func_0217AEF4(int *p)
{
    ((struct Obj14355 *)p)->f24 = (int)func_021E5440(1, ((struct Obj14355 *)p)->f0);
}

void func_0217AF04(int *p)
{
    func_021E54E0((char *)(((struct Obj03869 *)p)->f24));
    ((struct Obj03869 *)p)->f24 = 0;
}

void func_0217AF14(int *p)
{
    if (((struct Obj04561 *)p)->f24) {
        func_021E5534((u8 *)(((struct Obj04561 *)p)->f24));
        func_021E5980(((struct Obj04561 *)p)->f20);
    }
}

/*
 *   func_021E5548 (0x021E5548) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void func_0217AF2C(int *p)
{
    ((struct Obj10695 *)p)->f20 = (int)func_021E567C(func_021E5548((int *)(((struct Obj10695 *)p)->f24)), 1, ((struct Obj10695 *)p)->f0);
}

void func_0217AF44(int *p) {func_021E5868(((struct Obj03869 *)p)->f20);}

/*
 * trailing: two bytes alignment padding at 0x0217AF9A.
 */
void func_0217AF50(char *p)
{
    ((struct Obj02888 *)p)->fC=GF_FONT_Create(0x17,0,0,0,((struct Obj02888 *)p)->f0);
    ((struct Obj02888 *)p)->f10=func_02045B38(0,2,4,((struct Obj02888 *)p)->f0);
    ((struct Obj02888 *)p)->f14=(void *)PRINTSYS_QUE_Create((void *)(((struct Obj02888 *)p)->f0));
    ((struct Obj02888 *)p)->f8=func_021E8568(0,15,14,10,((struct Obj02888 *)p)->f14,((struct Obj02888 *)p)->fC,((struct Obj02888 *)p)->f0);
}

void func_0217AF9C(int *p)
{
    func_021E8628(((struct Obj03869 *)p)->f8);
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj03869 *)p)->f14));
    MSGDATA_Delete((struct Rec *)(((struct Obj03869 *)p)->f10));
    GF_FONT_Delete((void *)(((struct Obj03869 *)p)->fC));
}

void func_0217AFBC(int *p)
{
    func_021E867C((char *)(((struct Obj04561 *)p)->f8));
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj04561 *)p)->f14));
}

void func_0217AFD0(void *a,int b,char *p)
{
    switch(((struct Obj24400 *)(*(char * *)&((struct Obj24399 *)p)->f28))->f4){
    case 0: case 1: case 2:
        func_021E8AA0(a,(int)func_0217B0C8); break;
    case 3: case 4: case 5: case 6:
        func_021E8AA0(a,(int)func_0217B1BC); break;
    }
}

void func_0217B00C(void *a)
{
    func_021E8AA8((int)a);
}

void func_0217B014(void *a,int *state,char *p)
{
    switch(*state){
    case 0: FADE_Start(3,16,0,0); *state=1; break;
    case 1: if(!FADE_IsActive()) *state=2; break;
    case 2: func_021E8AA0(a,(int)func_0217AFD0); break;
    default: func_02034714(d_0217E5E0,0,d_0217E5E0); break;
    }
}

void func_0217B064(void *a,int *state,char *p)
{
    int mode;
    switch(*state){
    case 0:
        if(((struct Obj24402 *)(*(char * *)&((struct Obj24401 *)p)->f28))->f8==0){GFL_USE_FadeOutBgm(6);mode=12;}else mode=3;
        FADE_Start(mode,0,16,0);
        *state=1;
        break;
    case 1: if(!FADE_IsActive()) *state=2; break;
    case 2: func_021E8AA0(a,(int)func_0217B00C); break;
    default: func_02034714(d_0217E5E0,0,d_0217E5E0); break;
    }
}

void func_0217B0C8(int *a,int *state,int *p)
{
    Data config;
    switch(*state) {
    case 0:
        MI_CpuFill8(&config,0,32);
        config.words[1]=p[2];
        config.words[2]=p[3];
        config.words[3]=p[4];
        config.words[4]=p[5];
        config.words[5]=p[8];
        config.words[6]=p[9];
        config.words[7]=*(unsigned *)p[10];
        if(p[12]!=0) {p[12]=0;config.words[0]=2;}
        else {
            switch(((int *)p[10])[1]) {
            case 0: config.words[0]=0;break;
            case 1: config.words[0]=1;break;
            }
        }
        p[11]=(int)func_0217B2E4(&config,78);
        (*state)++;
        break;
    case 1:
        func_0217B35C((CB * *)((int *)p[11]));
        switch(func_0217B368((int *)p[11])) {
        case 1: ((int *)p[10])[2]=0;*state=2;break;
        case 2: ((int *)p[10])[2]=1;*state=2;break;
        case 3: ((int *)p[10])[1]=3;*state=3;break;
        }
        break;
    case 2:
        func_0217B344((int *)p[11]);
        func_021E8AA0(a,(int)func_0217B064);
        break;
    case 3:
        func_0217B344((int *)p[11]);
        func_021E8AA0(a,(int)func_0217B1BC);
        break;
    }
}

void func_0217B1BC(int *a,int *state,int *p)
{
    Init_0217AE20 config;
    switch(*state) {
    case 0:
        MI_CpuFill8(&config,0,40);
        config.w[1]=p[2];
        config.w[2]=p[3];
        config.w[3]=p[5];
        config.w[4]=p[8];
        config.w[5]=p[9];
        config.w[6]=((u32_0217B1BC *)p[10])[0];
        config.w[7]=((u32_0217B1BC *)p[10])[3];
        config.w[8]=((u32_0217B1BC *)p[10])[4];
        config.w[9]=((u32_0217B1BC *)p[10])[5];
        switch(((u32_0217B1BC *)p[10])[1]) {
        case 3: config.w[0]=0;break;
        case 4: config.w[0]=2;break;
        case 5: config.w[0]=3;break;
        case 6: config.w[0]=1;break;
        default: config.w[0]=0;break;
        }
        p[11]=(int)func_0217B984((Init_0217B970 *)&config, 78);
        (*state)++;
        break;
    case 1:
        func_0217BAF4((int *)p[11]);
        switch(func_0217BB3C((int *)p[11])) {
        case 1: *state=3;break;
        case 2: ((int *)p[10])[2]=2;*state=2;break;
        case 3: ((int *)p[10])[2]=3;*state=2;break;
        case 4: ((int *)p[10])[2]=4;*state=2;break;
        }
        break;
    case 2:
        func_0217BA9C((int *)p[11]);
        func_021E8AA0(a,(int)func_0217B064);
        break;
    case 3:
        p[12]=1;
        func_0217BA9C((int *)p[11]);
        func_021E8AA0(a,(int)func_0217B0C8);
        break;
    }
}

void *func_0217B2E4(const Data *src,unsigned heap)
{
    char *p;
    p=func_02030734(heap,0x3c,0,d_0217E5E4,0xaf);
    MI_CpuFill8(p,0,0x3c);
    *(Data *)(p+0x14)=*src;
    ((struct Obj10698 *)p)->f34=heap;
    ((struct Obj10698 *)p)->fC=func_02045B38(0,3,0x9e,heap);
    ((struct Obj10698 *)p)->f0=func_021E8A3C((int)p,(int)func_0217B380,heap);
    return p;
}

void func_0217B344(int *p) {BTLV_CORE_IsSlotKind1Index15((int)(((struct Obj14356 *)p)->f0));MSGDATA_Delete(((struct Obj14356 *)p)->fC);func_020307B0(p);}

/*
 * leaf: sole blocker of owned 0217B0C8 MATCH; no prior source/unit/shard, parent claim accepted.
 */
void func_0217B35C(CB **p)
{
    func_021E8A80(*p);
}

/*
 *   func_021E8A90 (0x021E8A90) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
int func_0217B368(int *p)
{
    if (func_021E8A90((int **)(((struct Obj14357 *)p)->f0)))
        return ((struct Obj14357 *)p)->f10;
    return 0;
}

void func_0217B380(int a, int b, int *p)
{
    switch (((struct Obj24404 *)p)->f14) {
    case 0:
        func_021E8AA0((int *)a, (int)func_0217B3C0);
        break;
    case 1:
        func_021E8AA0((int *)a, (int)func_0217B4A0);
        break;
    case 2:
        func_021E8AA0((int *)a, (int)func_0217B6AC);
        break;
    }
}

void func_0217B3B8(int p) {func_021E8AA8(p);}

void func_0217B3C0(int p, unsigned *state, int *q)
{
    unsigned result;
    switch (*state) {
    case 0: func_0217B93C(q,0); *state = 1; break;
    case 1: if (func_0217B964(q) == 1) *state = 2; break;
    case 2: func_0217B7D8(q,0); *state = 3; break;
    case 3:
        result = func_0217B930(q);
        if (result != -1) {
            switch (result) {
            case 0: func_021E8AA0((int *)p,(int)func_0217B4A0); break;
            case 1: func_021E8AA0((int *)p,(int)func_0217B6AC); break;
            case 2: func_021E8AA0((int *)p,(int)func_0217B468); break;
            case 3: func_0217B970(q,1); break;
            }
            func_0217B924(q);
        }
        break;
    }
}

void func_0217B468(int *p,int *state,u8 *q) {switch(*state) {case 0:func_0217B93C((int *)q,1);*state=1;break;case 1:if(func_0217B964((int *)q)==1) func_021E8AA0(p,(int)func_0217B3C0);break;}}

/*
 * extent: stale 0217B550 data label splits its final twelve pool bytes; real next function is separately filed 0217B55C.
 */
void func_0217B4A0(int p,unsigned *state,int *q)
{
    unsigned result;
    switch (*state) {
    case 0: func_0217B93C(q,9); *state=1; break;
    case 1: if(func_0217B964(q)==1) *state=2; break;
    case 2: func_0217B7D8(q,1); *state=3; break;
    case 3:
        result=func_0217B930(q);
        if(result!=-1) {
            switch(result) {
            case 0:
                if(func_0202EB44()==0) func_021E8AA0((int *)p,(int)func_0217B7A0);
                else {BATTLE_REC_ClearWork(); func_0217B970(q,2);}
                break;
            case 1: func_021E8AA0((int *)p,(int)func_0217B55C); break;
            case 2: func_021E8AA0((int *)p,(int)func_0217B594); break;
            case 3: func_021E8AA0((int *)p,(int)func_0217B3C0); break;
            }
            func_0217B924(q);
        }
        break;
    }
}

void func_0217B55C(int p,int *state,int *q)
{
    switch(*state) {
    case 0: func_0217B93C(q,8); *state=1; break;
    case 1: if(func_0217B964((int *)q)==1) func_021E8AA0((int *)p,(int)func_0217B4A0); break;
    }
}

void func_0217B594(int p, int *state, char *q)
{
    Config config;
    switch (*state) {
    case 0:
        MI_CpuFill8(&config, 0, 32);
        config.mode = 0;
        config.a = ((struct Obj02221 *)q)->f18;
        config.b = ((struct Obj02221 *)q)->f1C;
        config.c = ((struct Obj02221 *)q)->f20;
        config.d = ((struct Obj02221 *)q)->f24;
        config.e = ((struct Obj02221 *)q)->f28;
        config.f = ((struct Obj02221 *)q)->f2C;
        config.g = ((struct Obj02221 *)q)->f30;
        ((struct Obj02221 *)q)->f38 = func_0217D398(&config, ((struct Obj02221 *)q)->f34);
        (*state)++;
        break;
    case 1:
        func_0217D434((int *)(((struct Obj02221 *)q)->f38));
        if (func_0217D44C((int *)(((struct Obj02221 *)q)->f38))) (*state)++;
        break;
    case 2:
        func_0217D410((int *)(((struct Obj02221 *)q)->f38));
        func_021E8AA0((int *)p, (int)func_0217B4A0);
        break;
    }
}

void func_0217B620(int p, int *state, char *q)
{
    Config config;
    switch (*state) {
    case 0:
        MI_CpuFill8(&config, 0, 32);
        config.mode = 1;
        config.a = ((struct Obj02222 *)q)->f18;
        config.b = ((struct Obj02222 *)q)->f1C;
        config.c = ((struct Obj02222 *)q)->f20;
        config.d = ((struct Obj02222 *)q)->f24;
        config.e = ((struct Obj02222 *)q)->f28;
        config.f = ((struct Obj02222 *)q)->f2C;
        config.g = ((struct Obj02222 *)q)->f30;
        ((struct Obj02222 *)q)->f38 = func_0217D398(&config, ((struct Obj02222 *)q)->f34);
        (*state)++;
        break;
    case 1:
        func_0217D434((int *)(((struct Obj02222 *)q)->f38));
        if (func_0217D44C((int *)(((struct Obj02222 *)q)->f38))) (*state)++;
        break;
    case 2:
        func_0217D410((int *)(((struct Obj02222 *)q)->f38));
        func_021E8AA0((int *)p, (int)func_0217B6AC);
        break;
    }
}

void func_0217B6AC(int p,unsigned *state,int *q)
{
    unsigned result;
    switch (*state) {
    case 0: func_0217B93C(q,14); *state=1; break;
    case 1: if(func_0217B964(q)==1) *state=2; break;
    case 2: func_0217B7D8(q,2); *state=3; break;
    case 3:
        result=func_0217B930(q);
        if(result!=-1) {
            switch(result) {
            case 0:
                if(func_0202EB44()==0) func_021E8AA0((int *)p,(int)func_0217B7A0);
                else {BATTLE_REC_ClearWork(); func_0217B970(q,3);}
                break;
            case 1: func_021E8AA0((int *)p,(int)func_0217B768); break;
            case 2: func_021E8AA0((int *)p,(int)func_0217B620); break;
            case 3: func_021E8AA0((int *)p,(int)func_0217B3C0); break;
            }
            func_0217B924(q);
        }
        break;
    }
}

void func_0217B768(int *p,int *state,u8 *q) {switch(*state) {case 0:func_0217B93C((int *)q,15);*state=1;break;case 1:if(func_0217B964((int *)q)==1) func_021E8AA0(p,(int)func_0217B6AC);break;}}

void func_0217B7A0(int *p,int *state,u8 *q) {switch(*state) {case 0:func_0217B950((int *)q,22);*state=1;break;case 1:if(func_0217B964((int *)q)==1) func_021E8AA0(p,(int)func_0217B3C0);break;}}

static inline void selected(Menu_0217AE20 *rec,void *base,int index)
{
    char *mon;
    mon=(char *)REGULATION_GetCard(base,index);
    rec->option0=7;
    rec->option1=5;
    if((u8)(s8)(((struct Obj24405 *)mon)->f15B-1)<=1) rec->f14=13;
    else rec->f14=4;
    rec->f18=6;
    rec->count=4;
    rec->f28=1;
    rec->f2c=3;
}

/*
 * extent: following 0217B924 and 0217B930 tail-call stubs already have separate matched shards; lead only.
 * lever: descriptor assignments in member order fix constant scheduling; coordinates are u8, height u32 with logical shift and no outgoing truncation.
 * abi: E88B0 height widened from its narrow body spelling because original stores the full computed register into the outgoing slot.
 */
void func_0217B7D8(int *p, int index)
{
    Menu_0217AE20 rec;
    void *base;
    int layout;
    u8 x,y,width;
    u32 height;
    base=BATTLE_COMPETITION_GetFromSave((void *)GAME_DATA_GetSaveControl(((struct Obj01762 *)p)->f30));
    MI_CpuFill8(&rec,0,48);
    rec.f00=((struct Obj01762 *)p)->f20;
    rec.f04=((struct Obj01762 *)p)->f1C;
    rec.f08=((struct Obj01762 *)p)->f24;
    switch(index) {
    case 0:
        rec.option0=2;rec.option1=3;rec.f14=5;rec.f18=6;rec.count=4;rec.f28=1;rec.f2c=3;layout=0;break;
    case 1: selected(&rec,base,0);layout=0;break;
    case 2: selected(&rec,base,1);layout=0;break;
    case 3:
        rec.option0=11;rec.option1=12;rec.count=2;layout=1;rec.f28=1;rec.f2c=1;break;
    }
    rec.f20=0;rec.f22=15;rec.f24=13;rec.f26=1;
    switch(layout) {
    case 0: width=28;height=(rec.count&127)*2;x=2;y=9-(height>>1);break;
    case 1: width=12;height=(rec.count&127)*2;x=19;y=17-height;break;
    }
    ((struct Obj01762 *)p)->f4=func_021E88B0((Menu_0217AE20 *)&rec, x, y, width, height, ((struct Obj01762 *)p)->f34);
    ((struct Obj01762 *)p)->f8=index;
}

void func_0217B924(int *p) {func_021E89D0((void *)p[1]);}

unsigned func_0217B930(int *p) {return func_021E8A00((void *)p[1]);}

void func_0217B93C(int *p, int b)
{
    func_021E8738((int *)(*(int *)&((struct Obj01762 *)p)->f18), *(int *)&((struct Obj01762 *)p)->f20, b, 1);
}

void func_0217B950(int *p, int b)
{
    func_021E8738((int *)(*(int *)&((struct Obj01762 *)p)->f18), ((struct Obj01762 *)p)->fC, b, 1);
}

int func_0217B964(int *p) {return func_021E8844(*(int * *)&((struct Obj01762 *)p)->f18);}

void func_0217B970(int *p,int a) {p[4]=a;func_021E8AA0((int *)p[0],(int)func_0217B3B8);}

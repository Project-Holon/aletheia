/*
 * file:     br_main.c
 * unit:     yes
 * function: func_0220AF40, func_0220AF94, func_0220AFD8, func_0220B008, func_0220B02C, func_0220B0CC, func_0220B0F8, func_0220B0FC, func_0220B144, func_0220B164, func_0220B1D8
 * address:  0x0220AF40
 * region:   ov187
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
 *   BATTLE_REC_AllocWork 0x0200B400 thumb
 *   d_0220B2A0 0x0220B2A0 data a4
 *   STRBUF_Delete   0x02045808  arm
 *   func_020315D4   0x020315D4  arm
 *   func_020306F0   0x020306F0  arm
 *   BATTLE_REC_FreeWork   0x0200B424  thumb
 *   PROCSYS_Create  0x02031324  arm
 *   PROCSYS_Push 0x02031348 arm
 *   PROCSYS_Main 0x02031330 arm
 *   func_02034714  0x02034714  arm
 *   func_0203133C  0x0203133C  arm
 *   d_0220B2E0     0x0220B2E0  data  ov187  a4
 *   func_02030734 0x02030734 arm
 *   d_0220B2E4 0x0220B2E4 data a1
 *   func_020307B0  0x020307B0  arm
 *   BTL_SETUP_InitWithSlots 0x020138C4 thumb
 *   BATTLE_REC_LoadToolOverlay 0x0200BA58 thumb
 *   BATTLE_REC_UnloadToolOverlay 0x0200BA68 thumb
 *   func_021EEEA8 0x021EEEA8 thumb ov188
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   func_0220B240 0x0220B240 thumb ov187
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   func_02012A30 0x02012A30 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   func_02028A58 0x02028A58 thumb
 *   BTL_SETUP_ClearWithSlots 0x02013930 thumb
 */
#include "../../matched/include/Obj24881.h"
#include "../../matched/include/Obj24882.h"
#include "../../matched/include/Obj14488.h"
#include "../../matched/include/Obj24883.h"
#include "../../matched/include/Obj24884.h"
#include "../../matched/include/Obj01819.h"
#include "../../matched/include/Obj10802.h"
#include "../../matched/include/Obj24886.h"

struct Obj0203159C;
struct S;
struct U16Vec;
struct S020315D4;
struct State;
struct S020314B8;
struct BigObj;
struct SoundSys;
struct Obj;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

struct S {
    u32 *f0;
    u8 pad[0xc];
    u16 f10;
    u8 pad2[2];
    u32 f14;
    u32 f18;
};

typedef struct Entry { int id; const void *descriptor; void *(*create)(unsigned short, void *, unsigned); void (*destroy)(void *, void *); } Entry;

typedef struct State { void *handle; unsigned state; void *work; unsigned pad; unsigned short heap, pad2; void *payload; Entry *table; unsigned previous, desired, current; } State;

typedef struct { int state, mode; void *data, *owner; } Work;

typedef struct { unsigned char low:1, flag:1, rest:6; } Flag;

extern void GFL_HEAP_CreateChildHeap(unsigned, unsigned, unsigned);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void *MI_CpuFill8(void *, int, unsigned);
extern void BATTLE_REC_AllocWork(unsigned);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void BATTLE_REC_FreeWork(void);
extern void *PROCSYS_Create(int a0);
extern void PROCSYS_Push(void *, int, const void *, void *);
extern unsigned int PROCSYS_Main(void *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0203133C(struct S020314B8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void BTL_SETUP_InitWithSlots(void *,int,void *);
extern void BATTLE_REC_LoadToolOverlay(void);
extern void BATTLE_REC_UnloadToolOverlay(void);
extern void func_021EEEA8(void *,u32);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern void func_0220B240(u16 *,u16 *);
extern void GFL_USE_CancelChangeAndPlayBgm(u32,u32);
extern unsigned int func_02012A30(const struct BigObj *);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_FadeInBgmFull(u32);
extern void func_02028A58(struct SoundSys *sys, u8 level, u16 frames);
extern void BTL_SETUP_ClearWithSlots(struct Obj *p);
int func_0220AF40(struct Obj0203159C *a, unsigned unused, unsigned mode);
int func_0220AF94(int a, int b, int c, char *p);
int func_0220AFD8(void *a,int *state,int b,void *p);
void func_0220B008(struct S *p, u32 a, u32 b, u32 c);
int func_0220B02C(State *p);
void func_0220B0CC(int *p);
void func_0220B0F8(u8 *p,u32 v);
Work *func_0220B0FC(unsigned short heap, char *p, int mode);
void func_0220B144(u32 *p, u32 a);
void *func_0220B164(u32 a,u8 *b);
void func_0220B1D8(u8 *a, u8 *b);
extern const char d_0220B2A0[];
extern const char d_0220B2E4[];

int func_0220AF40(struct Obj0203159C *a, unsigned unused, unsigned mode)
{
    char *p;
    GFL_HEAP_CreateChildHeap(1, 0x59, 0x12000);
    p = PROCSYS_AllocProcWork(a, 0x17f4, 0x59);
    MI_CpuFill8(p, 0, 0x17f4);
    ((struct Obj24881 *)p)->f17F0 = mode;
    BATTLE_REC_AllocWork(0x59);
    func_0220B008((struct S *)p, (unsigned)d_0220B2A0, (unsigned)p, 0x59);
    func_0220B0F8((u8 *)p, 0);
    return 1;
}


/*
 * Tear down the four table slots at p+0x1780 when p+0x17C4 is set, then
 *   release the channel.
 */
int func_0220AF94(int a, int b, int c, char *p)
{
    int i;
    if (((struct Obj24882 *)p)->f17C4 != 0) {
        for (i = 0; i < 4; i++) {
            int v = *(int *)(p + 0x1780 + i * 4);
            if (v != 0)
                STRBUF_Delete((struct U16Vec *)v);
        }
    }
    func_0220B0CC((int *)p);
    BATTLE_REC_FreeWork();
    func_020315D4((struct S020315D4 *)a);
    func_020306F0(0x59);
    return 1;
}

int func_0220AFD8(void *a,int *state,int b,void *p) { switch(*state) { case 0: *state=1; break; case 1: if(func_0220B02C(p)) *state=2; break; case 2: return 1; } return 0; }


void func_0220B008(struct S *p, u32 a, u32 b, u32 c)
{
    MI_CpuFill8(p, 0, 0x28);
    p->f0 = PROCSYS_Create(c);
    p->f14 = b;
    p->f18 = a;
    p->f10 = c;
}

int func_0220B02C(State *p)
{
    switch (p->state) {
    case 0:
        p->previous = p->current;
        p->current = p->desired;
        p->state = 1;
        break;
    case 1:
        if (p->table[p->current].create) p->work = p->table[p->current].create(p->heap, p->payload, p->previous);
        else p->work = 0;
        PROCSYS_Push(p->handle, p->table[p->current].id, p->table[p->current].descriptor, p->work);
        p->state = 2;
        break;
    case 2:
        if (!PROCSYS_Main(p->handle)) p->state = 3;
        break;
    case 3:
        if (p->table[p->current].destroy) {
            p->table[p->current].destroy(p->work, p->payload);
            p->work = 0;
        }
        if (p->current != p->desired) p->state = 0;
        else p->state = 4;
        break;
    case 4: return 1;
    }
    return 0;
}


void func_0220B0CC(int *p)
{
    if (((struct Obj14488 *)p)->f8 != 0)
        func_02034714((void *)0x0220b2e0, 0, (void *)0x0220b2e0);
    func_0203133C(((struct Obj14488 *)p)->f0);
    MI_CpuFill8(p, 0, 0x28);
}

void func_0220B0F8(u8 *p,u32 v) { ((struct Obj24883 *)p)->f20=v; }

Work *func_0220B0FC(unsigned short heap, char *p, int mode)
{
    Work *w;
    w = func_02030734(heap, 16, 0, d_0220B2E4, 0x1e7);
    MI_CpuFill8(w, 0, 16);
    w->owner = ((struct Obj24884 *)p)->f17F0;
    w->data = p + 0x28;
    if (mode == 1) w->mode = 1;
    else w->mode = 0;
    return w;
}


void func_0220B144(u32 *p, u32 a)
{
    switch (p[0]) {
    case 0:
        break;
    case 1:
        func_0220B0F8((u8 *)a, 1);
        break;
    }
    func_020307B0(p);
}

void *func_0220B164(u32 a,u8 *b)
{
    u8 *p = func_02030734(a,240,0,d_0220B2E4,542);
    MI_CpuFill8(p,0,240);
    BTL_SETUP_InitWithSlots(p,*(int *)(*(u8 **)(b+0x17F0)+4),(void *)a);
    BATTLE_REC_LoadToolOverlay();
    func_021EEEA8(p,a);
    BATTLE_REC_UnloadToolOverlay();
    GFL_USE_SetBgmPlayerParam((void *)1);
    GFL_USE_PushBgm();
    func_0220B240((u16 *)(p+24),(u16 *)(p+26));
    GFL_USE_CancelChangeAndPlayBgm(*(u16 *)(p+24),65535);
    return p;
}

void func_0220B1D8(u8 *a, u8 *b)
{
    void *p = (void *)func_02012A30(((struct Obj24886 *)(*(u8 * *)&((struct Obj10802 *)b)->f17F0))->f4);
    GFL_USE_PopBgm();
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_FadeInBgmFull(30);
    if (*(u32 *)*(u8 * *)&((struct Obj10802 *)b)->f17F0 == 0) func_02028A58(p,64,0);
    ((struct Obj10802 *)b)->f17E4 = ((Flag *)(a+0xC1))->flag;
    func_020307B0(((struct Obj01819 *)a)->f34);
    BTL_SETUP_ClearWithSlots((struct Obj *)a);
    func_020307B0(a);
    func_0220B0F8((u8 *)((u32)b),0);
}

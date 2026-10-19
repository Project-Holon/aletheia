/*
 * function: BTL_REC_SEL_Create
 * packet: pkt_ov214_021B95A0
 * checks: 1 callee own bodies/forwarders and original register setup rederived; 2 ov214 neighbours read; 3 const object unchanged in prior run, mutable pointee conversions prohibit const; 4 shared-tail idiom gives MATCH after each incoming arm repeats the call; 5 directory/neighbours refreshed.
 * retry: safe temporaries after the common label stayed DIFF67; repeated branch calls gave MATCH504; callback 021B9F18 separately matched and verified.
 * address: 0x021B95A0
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 0203159C own source returns void, but its ARM body leaves the allocator result in r0 after str r0,[r4,#14]; this caller preserves that live return as its context.
 * symbols:
 * func_02034AC4 0x02034AC4 arm
 * GFL_HEAP_CreateChildHeap 0x0203064C arm
 * PROCSYS_AllocProcWork 0x0203159C arm
 * MI_CpuFill8 0x02082BCC arm
 * func_02040588 0x02040588 arm
 * BTL_REC_SEL_GRAPHIC_Create 0x021BB178 thumb ov214
 * GF_FONT_Create 0x0201D7EC thumb
 * PRINTSYS_QUE_Create 0x0201C440 thumb
 * GAME_DATA_GetMyItem 0x0201292C thumb
 * func_02007F68 0x02007F68 thumb
 * func_020056A0 0x020056A0 thumb
 * BTL_REC_SEL_VBlank 0x021B9F18 thumb ov214
 * func_02045B38 0x02045B38 arm
 * BTL_REC_SEL_InitBgRun 0x021BABF4 thumb ov214
 * BTL_REC_SEL_ClearLayer 0x021BAD08 thumb ov214
 * BTL_REC_SEL_InitSubBg 0x021BAD14 thumb ov214
 * BTL_REC_SEL_InitWindows 0x021B9F24 thumb ov214
 * BTL_REC_SEL_DrawWindow 0x021BA074 thumb ov214
 * BTL_REC_SEL_InitPalette 0x021BA2F4 thumb ov214
 * BTL_REC_SEL_CreateWindows 0x021BA3C4 thumb ov214
 * BG_SYS_SetPriority 0x0204047C arm
 * BG_SYS_LoadPlttEntry 0x02040EBC arm
 * FADE_Start 0x0204E720 arm
 * BTL_REC_SEL_StartFade 0x021B9EB8 thumb ov214
 * BTL_REC_SEL_SetEntryA 0x021B9EF0 thumb ov214
 * BTL_REC_SEL_StartTimer 0x021BA6A0 thumb ov214
 * BTL_REC_SEL_InitBgGfx1 0x021BAC58 thumb ov214
 * BTL_REC_SEL_CreateUiActor 0x021BAE4C thumb ov214
 * BTL_REC_SEL_InitPalanm 0x021BAE9C thumb ov214
 * BTL_REC_SEL_DeleteUiActor 0x021BAE88 thumb ov214
 * GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 * ov67_id 0x00000043 data a1
 */
#include "../include/Obj00182.h"
#include "../include/Obj06705.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u8 ov67_id[];
extern int func_02034AC4(int);
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void*,u32,u32);
struct C;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_SetPriority(int idx, unsigned short val);
extern void BG_SYS_LoadPlttEntry(u32,u32);
extern void FADE_Start(u32,int,int,int);
extern char *BTL_REC_SEL_GRAPHIC_Create(u32,u32);
struct BigObj;
struct GfFont;
struct MsgBank;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void*);
extern void *GAME_DATA_GetMyItem(const struct BigObj *p);
extern u32 func_02007F68(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_020056A0(void(*)(void*),void*,u32);
extern void BTL_REC_SEL_VBlank(void *unused, char *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void BTL_REC_SEL_InitBgRun(int,char*);
extern void BTL_REC_SEL_ClearLayer(void*,char*);
extern void BTL_REC_SEL_InitSubBg(void **a, char *p);
extern void BTL_REC_SEL_InitWindows(void *unused, struct C *p);
extern void BTL_REC_SEL_DrawWindow(int,char*);
extern void BTL_REC_SEL_InitPalette(int,char*);
extern void BTL_REC_SEL_CreateWindows(int,char*);
extern void BTL_REC_SEL_StartFade(char*,int,char*,int,int,int,int,int,int);
extern void BTL_REC_SEL_SetEntryA(void*,char*,u32,u32,u32);
extern void BTL_REC_SEL_StartTimer(void*,char*,u32);
extern void BTL_REC_SEL_InitBgGfx1(int unused, u8 *p);
extern void BTL_REC_SEL_CreateUiActor(int unused, u8 *p);
extern void BTL_REC_SEL_InitPalanm(int,char*);
extern void BTL_REC_SEL_DeleteUiActor(int unused, u8 *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
int BTL_REC_SEL_Create(void *manager,char *state,char * const obj)
{
    char *p;
    u8 i;
    enum {K=3} k;
    func_02034AC4((int)ov67_id);
    GFL_HEAP_CreateChildHeap(1,0x75,0x50000);
    p=PROCSYS_AllocProcWork(manager,0x2f0,0x75);
    MI_CpuFill8(p,0,0x2f0);
    ((struct Obj00182 *)p)->f0=0x75;
    for(i=0;i<=7;i++)func_02040588(i,0);
    *(void* *)&((struct Obj00182 *)p)->f4=BTL_REC_SEL_GRAPHIC_Create(1,((struct Obj00182 *)p)->f0);
    *(void* *)&((struct Obj00182 *)p)->f8=GF_FONT_Create(23,0,0,0,((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->fC=PRINTSYS_QUE_Create((void*)(u32)((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f10=PRINTSYS_QUE_Create((void*)(u32)((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f14=PRINTSYS_QUE_Create((void*)(u32)((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f18=PRINTSYS_QUE_Create((void*)(u32)((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f50=func_02007F68(GAME_DATA_GetMyItem(*(void* *)&((struct Obj06705 *)obj)->f0),0x1d1,1,((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f54=0;
    ((struct Obj00182 *)p)->f4C=func_020056A0((void (*)(void *))BTL_REC_SEL_VBlank,p,1);
    *(void* *)&((struct Obj00182 *)p)->f58=func_02045B38(0,2,19,((struct Obj00182 *)p)->f0);
    BTL_REC_SEL_InitBgRun((int)obj,p);BTL_REC_SEL_ClearLayer(obj,p);BTL_REC_SEL_InitSubBg((void **)obj,p);
    BTL_REC_SEL_InitWindows(obj,(struct C *)p);BTL_REC_SEL_DrawWindow((int)obj,p);BTL_REC_SEL_InitPalette((int)obj,p);BTL_REC_SEL_CreateWindows((int)obj,p);
    BG_SYS_SetPriority(2,2);k=K;BG_SYS_SetPriority(k,1);BG_SYS_SetPriority(1,0);
    func_02040588(2,1);func_02040588(3,1);func_02040588(1,1);
    BG_SYS_LoadPlttEntry(0,0);BG_SYS_LoadPlttEntry(4,0);FADE_Start(3,16,16,0);
    if(((struct Obj00182 *)p)->f50){
        if(((struct Obj06705 *)obj)->fC){
          if(((struct Obj06705 *)obj)->f4){
            BTL_REC_SEL_StartFade(state,(int)obj,p,2,k,16,0,2,0);
            BTL_REC_SEL_SetEntryA(obj,p,5,0,1);BTL_REC_SEL_StartTimer(obj,p,60);
            if(((struct Obj06705 *)obj)->f8)BTL_REC_SEL_InitBgGfx1((int)obj,(u8 *)p);
            ((struct Obj00182 *)p)->fB4=1;
          }else {BTL_REC_SEL_StartFade(state,(int)obj,p,15,k,16,0,2,0);}
        }else {common:BTL_REC_SEL_StartFade(state,(int)obj,p,15,k,16,0,2,0);}
    }else if(((struct Obj06705 *)obj)->f8){BTL_REC_SEL_StartFade(state,(int)obj,p,15,k,16,0,2,0);}
    else ((struct Obj00182 *)p)->f54=1;
    BTL_REC_SEL_CreateUiActor((int)obj,(u8 *)p);BTL_REC_SEL_InitPalanm((int)obj,p);BTL_REC_SEL_DeleteUiActor((int)obj,(u8 *)p);
    GFL_NET_RestartWithDefaultTimeout(1,((struct Obj00182 *)p)->f0);
    return 1;
}

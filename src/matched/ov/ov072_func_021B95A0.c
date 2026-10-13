/*
 * function: TOWNMAP_Create
 * address:  0x021B95A0
 * packet:   pkt_ov072_021B95A0
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   ov067_id       0x00000043  data
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   TOWNMAP_GRH_Create  0x021BB6E8  thumb  ov072
 *   TOWNMAP_GRH_LoadTownInfo  0x021BBB24  thumb  ov072
 *   TOWNMAP_ProcInit  0x021B991C  thumb  ov072
 *   TOWNMAP_StepFadeIn  0x021B996C  thumb  ov072
 *   func_020120F4  0x020120F4  thumb
 *   TOWNMAP_GRH_GetBgId  0x021BB764  thumb  ov072
 *   TOWNMAP_GRH_InitTextBox  0x021BB3E8  thumb  ov072
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   TOWNMAP_GRH_PrintTextBoxMessage  0x021BB448  thumb  ov072
 *   func_0201DD68  0x0201DD68  thumb
 *   TOWNMAP_GRH_GetHandle  0x021BB778  thumb  ov072
 *   TOWNMAP_BackButtonInit  0x021B9E38  thumb  ov072
 *   TOWNMAP_GRH_GetActor  0x021BB784  thumb  ov072
 *   TOWNMAP_GRH_InitLabel  0x021BB4B4  thumb  ov072
 *   func_02040618  0x02040618  arm
 *   TOWNMAP_MapInit  0x021BA490  thumb  ov072
 *   TOWNMAP_CursorInit  0x021BA04C  thumb  ov072
 *   TOWNMAP_MapFindTownById  0x021BA7F8  thumb  ov072
 *   TOWNMAP_TownGetField  0x021BA774  thumb  ov072
 *   TOWNMAP_CursorSetPos  0x021BA3CC  thumb  ov072
 *   TOWNMAP_InitScroll  0x021BAF74  thumb  ov072
 *   TOWNMAP_InitSelection  0x021BB1BC  thumb  ov072
 *   TOWNMAP_GRH_InitTouch  0x021BB5D4  thumb  ov072
 *   TOWNMAP_MapFindTownUnderCursor  0x021BA6C8  thumb  ov072
 *   TOWNMAP_GRH_SetLabelTown  0x021BB5AC  thumb  ov072
 *   TOWNMAP_DrawSelection  0x021BB220  thumb  ov072
 *   TOWNMAP_MapGetScroll  0x021BA69C  thumb  ov072
 *   TOWNMAP_CursorSetHoverTown  0x021BA3F4  thumb  ov072
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   func_020056A0  0x020056A0  thumb
 *   TOWNMAP_GRH_EmptyTask  0x021BB6E4  thumb  ov072
 */
#include "../include/Obj00433.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
} Pos;

typedef struct {
    int f0;
    u8 pad4[4];
    u16 f8;
    u16 fA;
} Arg;

typedef signed int     s32;
struct GfFont;
extern int func_02034AC4(s32 handle);
extern char ov067_id[];
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, int v, int n);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
struct Ctx;
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 *TOWNMAP_GRH_Create(u32 heap);
extern int TOWNMAP_GRH_LoadTownInfo(int a);
extern void TOWNMAP_ProcInit(int *p, int a, int b);
extern void TOWNMAP_StepFadeIn(int a, int *b);
extern void *func_020120F4(const struct Ctx *p);
extern u8 TOWNMAP_GRH_GetBgId(int unused, u32 i);
extern void TOWNMAP_GRH_InitTextBox(void *p, int a, int b, int c, u8 s0, u8 s1, u8 s2, u8 s3, u16 s4);
extern void GF_FONT_SetTextColor(u32 a, u32 b, u32 c);
extern void TOWNMAP_GRH_PrintTextBoxMessage(u32 *p, u32 a, int x, int y);
extern void func_0201DD68(void);
extern unsigned int TOWNMAP_GRH_GetHandle(char *p, int n);
extern void TOWNMAP_BackButtonInit(u32 *o, u32 a1, u32 a2, u8 a3, u8 s0, u8 s1, u32 s2, u16 heap);
extern unsigned int TOWNMAP_GRH_GetActor(char *p, int n);
extern void TOWNMAP_GRH_InitLabel(u32 *p, u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02040618(u32 a, u32 b, u32 c);
extern void TOWNMAP_MapInit(void *p, u16 x, u16 y, int a, u32 b, u32 c, int heap, int flag);
extern void TOWNMAP_CursorInit(void *p, u32 a, u32 b, int heap);
extern void *TOWNMAP_MapFindTownById(char *p, u32 b, int y);
extern int TOWNMAP_TownGetField(char *p, int i);
extern void TOWNMAP_CursorSetPos(char *p, int *q);
extern void TOWNMAP_InitScroll(u8 *p, u32 a, u32 b, int heap);
extern void TOWNMAP_InitSelection(void *p, int a, int b, int c, int d, u16 e);
extern void TOWNMAP_GRH_InitTouch(void *p, int heap);
extern int TOWNMAP_MapFindTownUnderCursor(void *p, void *a);
extern void TOWNMAP_GRH_SetLabelTown(int *p, int x);
extern void TOWNMAP_DrawSelection(void *p, int w);
extern void TOWNMAP_MapGetScroll(char *p, int *o);
extern void TOWNMAP_CursorSetHoverTown(int *p, int a, int *b);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern u32 func_020056A0(void (*cb)(void *, void *), void *arg, int pri);
extern void TOWNMAP_GRH_EmptyTask(void *a, void *b);

int TOWNMAP_Create(void *a, void *b, Arg *c)
{
    Pos pt;
    Pos org;
    u8 *o;
    u32 v;
    int flag;
    int e;

    func_02034AC4((u32)ov067_id);
    GFL_HEAP_CreateChildHeap(1, 0x44, 0x60000);
    o = PROCSYS_AllocProcWork(a, 0x144, 0x44);
    MI_CpuFill8(o, 0, 0x144);
    *(Arg * *)&((struct Obj00433 *)o)->f130 = c;
    flag = (*(Arg * *)&((struct Obj00433 *)o)->f130)->f0 == 2;
    ((struct Obj00433 *)o)->f124 = GF_FONT_Create(0x17, 0, 0, 0, 0x44);
    ((struct Obj00433 *)o)->f128 = (int)func_02045B38(0, 2, 0x59, 0x44);
    ((struct Obj00433 *)o)->f12C = (int)func_02045B38(0, 2, 0xb9, 0x44);
    *(u32 * *)&((struct Obj00433 *)o)->f0 = TOWNMAP_GRH_Create(0x44);
    ((struct Obj00433 *)o)->f34 = TOWNMAP_GRH_LoadTownInfo(0x44);
    TOWNMAP_ProcInit((int *)(o + 4), (int)o, (int)TOWNMAP_StepFadeIn);
    v = (u32)func_020120F4((const struct Ctx *)((*(u32 **)(o + 0x130))[5]));
    if ((*(Arg * *)&((struct Obj00433 *)o)->f130)->f0 != 1) {
        TOWNMAP_GRH_InitTextBox(o + 0xc4, TOWNMAP_GRH_GetBgId(*(u32 *)&((struct Obj00433 *)o)->f0, 1), *(int *)&((struct Obj00433 *)o)->f124, ((struct Obj00433 *)o)->f12C, 0, 0x15, 0x18, 3, 0x44);
        GF_FONT_SetTextColor(0xf, 1, 0);
        TOWNMAP_GRH_PrintTextBoxMessage((u32 *)(o + 0xc4), 0, 0x10, 0);
        func_0201DD68();
    }
    TOWNMAP_BackButtonInit((u32 *)(o + 0x14), (*(Arg * *)&((struct Obj00433 *)o)->f130)->f0, TOWNMAP_GRH_GetHandle((char *)(*(u32 *)&((struct Obj00433 *)o)->f0), 0), TOWNMAP_GRH_GetBgId(*(u32 *)&((struct Obj00433 *)o)->f0, 0), 0xf, 8, v, 0x44);
    TOWNMAP_GRH_InitLabel((u32 *)(o + 0xd4), TOWNMAP_GRH_GetBgId(*(u32 *)&((struct Obj00433 *)o)->f0, 1), *(int *)&((struct Obj00433 *)o)->f124, ((struct Obj00433 *)o)->f128, TOWNMAP_GRH_GetActor((char *)(*(u32 *)&((struct Obj00433 *)o)->f0), 0), 0x44);
    func_02040618(TOWNMAP_GRH_GetBgId(*(u32 *)&((struct Obj00433 *)o)->f0, 1), 3, -4);
    TOWNMAP_MapInit(o + 0x50, c->f8, c->fA, ((struct Obj00433 *)o)->f34, *(u32 *)&((struct Obj00433 *)o)->f0, (u32)func_020120F4((const struct Ctx *)((*(u32 **)(o + 0x130))[5])), 0x44, flag);
    TOWNMAP_CursorInit(o + 0x38, TOWNMAP_GRH_GetActor((char *)(*(u32 *)&((struct Obj00433 *)o)->f0), 1), TOWNMAP_GRH_GetActor((char *)(*(u32 *)&((struct Obj00433 *)o)->f0), 2), 0x44);
    e = (int)TOWNMAP_MapFindTownById((char *)(o + 0x50), c->f8, c->fA);
    if (e != 0) {
        pt.x = TOWNMAP_TownGetField((char *)e, 4);
        pt.y = TOWNMAP_TownGetField((char *)e, 5);
    } else {
        pt.x = 0x80;
        pt.y = 0x60;
    }
    TOWNMAP_CursorSetPos((char *)(o + 0x38), (int *)(&pt));
    TOWNMAP_InitScroll(o + 0x78, TOWNMAP_GRH_GetBgId(*(u32 *)&((struct Obj00433 *)o)->f0, 3), TOWNMAP_GRH_GetBgId(*(u32 *)&((struct Obj00433 *)o)->f0, 2), 0x44);
    TOWNMAP_InitSelection(o + 0xb0, TOWNMAP_GRH_GetBgId(*(u32 *)&((struct Obj00433 *)o)->f0, 5), *(int *)&((struct Obj00433 *)o)->f124, ((struct Obj00433 *)o)->f128, ((struct Obj00433 *)o)->f12C, 0x44);
    TOWNMAP_GRH_InitTouch(o + 0xf4, 0x44);
    e = TOWNMAP_MapFindTownUnderCursor(o + 0x50, o + 0x38);
    if (e != 0) {
        TOWNMAP_GRH_SetLabelTown((int *)(o + 0xd4), e);
        TOWNMAP_DrawSelection(o + 0xb0, e);
        ((struct Obj00433 *)o)->f134 = e;
        TOWNMAP_MapGetScroll((char *)(o + 0x50), (int *)(&org));
        TOWNMAP_CursorSetHoverTown((int *)(o + 0x38), e, (int *)(&org));
    }
    if (GFL_NET_GetRunState()) {
        GFL_NET_RestartWithDefaultTimeout(1, 0x44);
    }
    ((struct Obj00433 *)o)->f13C = func_020056A0(TOWNMAP_GRH_EmptyTask, o, 0);
    return 1;
}

/*
 * function: TOWNMAP_BackButtonInit
 * address:  0x021B9E38
 * packet:   pkt_ov072_021B9E38
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * `u8 a3` puts the request-block stores in source order, and `u16 heap`
 * (with the heap-taking callees declared u16, as ov070's twin does) moves
 * the r3 home store to the front of the prologue; with u32 for both the
 * spill and the stores are scheduled late (22 bytes).  The 64-byte table
 * copy is declared after the request, so it sits below it.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_020490F4  0x020490F4  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_StopActorAnim  0x0204B974  arm
 *   TOUCHBAR_Create  0x021B62E0  thumb  ov067
 *   TOUCHBAR_SetAllButtonsPriority  0x021B6520  thumb  ov067
 *   d_021BBB8C     0x021BBB8C  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Rect;

typedef struct { u32 w[16]; } Tbl;

typedef struct {
    u8 *f0;
    u32 f4;
    int f8;
    u32 fC;
    u32 f10;
    u32 f14;
    int f18;
    int f1c;
} Req;

extern void MI_CpuFill8(void *p, int v, int n);
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, u32, u32, u32, const void *, u16, u16);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
struct Actor;
extern void CLACT_StopActorAnim(struct Actor *a);
extern u32 TOUCHBAR_Create(Req *r, int heap);
extern void TOUCHBAR_SetAllButtonsPriority(u8 *p, u32 v);
extern Tbl d_021BBB8C;

void TOWNMAP_BackButtonInit(u32 *o, u32 a1, u32 a2, u8 a3, u8 s0, u8 s1, u32 s2, u16 heap)
{
    Req r;
    Tbl t;
    Rect s;
    void *h;

    MI_CpuFill8(o, 0, 0x20);
    o[4] = s2;
    h = func_020490F4(0x55, heap);
    o[0] = CLACT_RegisterPaletteEx(h, 2, 0, 0, 0, 4, heap);
    o[1] = CLACT_RegisterCharacter(h, 8, 0, 0, heap);
    o[2] = CLACT_RegisterCellAnim(h, 0xc, 0x13, heap);
    ARC_TOOL_DeleteHandle(h);
    MI_CpuFill8(&s, 0, 8);
    s.a = 0xa8;
    s.b = 0xa8;
    s.c = 7;
    o[5] = (u32)CLACT_CreateActor((void *)a2, o[1], o[0], o[2], &s, 0, heap);
    CLACT_SetActorAutoAnim((struct Obj *)o[5], 1);
    CLACT_StopActorAnim((struct Actor *)o[5]);
    t = d_021BBB8C;
    MI_CpuFill8(&r, 0, 0x20);
    r.f0 = (u8 *)&t;
    r.f4 = 2;
    r.f8 = a2;
    r.fC = a3;
    r.f10 = s0;
    r.f14 = s1 + 4;
    r.f18 = 2;
    o[3] = TOUCHBAR_Create(&r, heap);
    TOUCHBAR_SetAllButtonsPriority((u8 *)o[3], 10);
}

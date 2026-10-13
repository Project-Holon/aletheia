/*
 * function: func_02208DAC
 * address: 0x02208DAC
 * packet: pkt_ov094_02208DAC
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const Arg * lets the side load schedule above the pos zero stores;
 *   pos is initialised in an inner block (a top-level initializer is
 *   emitted at function entry); the stack locals are declared arc, heap,
 *   base so they land at 0x1c, 0x18, 0x14.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   func_0204B92C 0x0204B92C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_02030DA8 0x02030DA8 arm
 *   func_021F896C 0x021F896C thumb ov094
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_022090B4 0x022090B4 thumb ov094
 *   func_02209214 0x02209214 thumb ov094
 *   d_0220AED0 0x0220AED0 data a4
 *   d_0220AB6C 0x0220AB6C data a4
 *   d_0220AB7C 0x0220AB7C data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;
typedef struct { s16 x, y, z, w; } Pos;
typedef struct { s16 x, y; } Vec2;
typedef struct { void *h; int goal, home, step, frame, wait; Vec2 pos; } Entry;
typedef struct {
    u32 h0, h4, h8, hc;
    Entry e[7];
    int state, active, sound;
    u16 heap;
} Work;
typedef struct { int side; int idx[6]; } Arg;
typedef struct { s16 x0, y0, x1, y1; } Origin;
extern const char d_0220AED0[];
extern const Origin d_0220AB6C[];
extern const u32 d_0220AB7C[][5];
extern void *func_02030734(u16, u32, int, const char *, u16);
extern void *func_020490F4(u32 id, u32 heap);
typedef unsigned char  u8;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
typedef signed int     s32;
struct Obj;
struct PalAnmSlot;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern int func_021F86E0(void);
extern int CLACT_GetPaletteVramAddress(u32 idx, u32 alternate);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
struct Actor;
struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void *func_021F86D4(void);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_020061E4(u32 a);
extern void func_022090B4(void *, void *);
extern void func_02209214(void *);
Work *func_02208DAC(const Arg *arg, u32 heapId)
{
    void *arc;
    int heap;
    int base;
    Work *w;
    Work **ctx;
    int i;

    heap = (heapId & 0x7fff) | 0x8000;
    w = func_02030734(heap, 0xe4, 1, d_0220AED0, 0x7a);
    arc = func_020490F4(0xb, (u16)heap);
    w->heap = heap;
    w->h0 = (u32)CLACT_CreateUnit(7, 0, w->heap);
    w->h4 = CLACT_RegisterCharacter(arc, 0xbd, 0, 0, w->heap);
    w->h8 = CLACT_RegisterCellAnim(arc, 0xbf, 0xc0, w->heap);
    w->hc = CLACT_RegisterPalette(arc, 0xbe, 0, 0xc0, w->heap);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)func_021F86E0(), 2, (u16)(CLACT_GetPaletteVramAddress(w->hc, 0) >> 1), 0x20);
    {
    Pos pos = {0, 0, 0, 0};
    int side = arg->side;
    base = d_0220AB6C[side].x0;
    pos.x = base + (side == 0 ? 0x80 : -0x80);
    pos.y = d_0220AB6C[arg->side].y0;
    for (i = 0; i < 6; i++) {
        w->e[i].h = CLACT_CreateActor((void *)w->h0, w->h4, w->hc, w->h8, &pos, 0, w->heap);
        CLACT_GetActorSurfacePos(w->e[i].h, (struct PtS *)&w->e[i].pos, 0);
        func_0204B92C(w->e[i].h, 1);
        CLACT_SetActorAnimSeq(w->e[i].h, d_0220AB7C[arg->side][arg->idx[i]]);
        w->e[i].frame = d_0220AB7C[2][arg->idx[i]];
        w->e[i].wait = (i + 1) * 6;
        w->e[i].home = base;
        w->e[i].goal = base + (i + 1) * (arg->side == 0 ? -2 : 2);
        w->e[i].step = arg->side == 0 ? -12 : 12;
        base += arg->side == 0 ? 15 : -15;
    }
    pos.x = d_0220AB6C[arg->side].x1 + (arg->side == 0 ? 0x80 : -0x80);
    pos.y = d_0220AB6C[arg->side].y1;
    w->e[i].h = CLACT_CreateActor((void *)w->h0, w->h4, w->hc, w->h8, &pos, 0, w->heap);
    CLACT_GetActorSurfacePos(w->e[i].h, (struct PtS *)&w->e[i].pos, 0);
    func_0204B92C(w->e[i].h, 1);
    CLACT_SetActorAnimSeq(w->e[i].h, d_0220AB7C[arg->side][4]);
    w->e[i].frame = d_0220AB7C[arg->side][4];
    w->e[i].wait = 0;
    w->e[i].home = w->e[i].goal = d_0220AB6C[arg->side].x1;
    w->e[i].step = arg->side == 0 ? -0x10 : 0x10;
    ctx = func_02030734(heap, 4, 0, d_0220AED0, 0xec);
    *ctx = w;
    func_021F896C(func_02030DA8(func_021F86D4(), func_022090B4, ctx, 0), func_02209214, 0);
    w->active = 1;
    ARC_TOOL_DeleteHandle(arc);
    func_020061E4(0x570);
    return w;
    }
}

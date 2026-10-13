/*
 * function: WIPE_SUB_CircleInit
 * address:  0x0202368C
 * packet:   pkt_0202368C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WIPE_SUB_FlipLineBuffersTask  0x02022D98  thumb
 *   WIPE_SUB_WindowRectHBlank  0x02022AD0  thumb
 *   WIPE_RequestSetHBlankSlot  0x02022518  thumb
 *   WIPE_SUB_CalcStep  0x0202290C  thumb
 *   WIPE_SUB_CreateLineBuffers  0x02022CEC  thumb
 *   WIPE_SUB_GetLineBuffer  0x02022D88  thumb
 *   WIPE_SUB_SetupWindow  0x02022E20  thumb
 *   WIPE_SUB_SetWindowVisibleMode  0x02022E88  thumb
 *   WIPE_SUB_CalcCircleLines  0x0202384C  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;

typedef struct Par {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    u8  f8;
    u8  f9;
    u8  fa;
    u8  fb;
} Par;

typedef struct Ctx {
    u32 pad0[3];
    u32 c;
    u32 h10;
    u32 h14;
    u32 h18;
    u32 h1c;
    u32 h20;
    u32 h24;
    u32 h28;
    u32 h2c;
    u32 h30;
    u32 h34;
} Ctx;

struct Container;
struct ctl;
extern s32 WIPE_SUB_CalcStep(s32 a, s32 b, s32 c);
struct Obj;
struct Wipe;
extern void WIPE_SUB_CreateLineBuffers(u32 *a0, u32 a1, u32 a2, u32 a3);
extern void WIPE_SUB_CalcCircleLines(struct Wipe *w);
extern void func_020056A0(void *cb, Ctx *ctx, u32 v);
extern void *WIPE_SUB_GetLineBuffer(struct Obj *obj, u32 idx);
extern void WIPE_SUB_FlipLineBuffersTask(void *p, struct Container *c);
extern void WIPE_SUB_SetupWindow(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9);
extern int WIPE_SUB_SetWindowVisibleMode(int a0, int a1, int a2, int a3);
extern void WIPE_SUB_WindowRectHBlank(struct ctl *ctl);
extern void WIPE_RequestSetHBlankSlot(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);

void WIPE_SUB_CircleInit(Ctx *ctx, const Par *par, u32 a2, u32 a3,
                   u32 s5, u32 s6, u32 s7, u32 s8)
{
    u32 t;
    s16 *base;
    u32 off;
    s32 w;
    s32 h;

    t = WIPE_SUB_CalcStep(par->f0, par->f2, a2);
    WIPE_SUB_CreateLineBuffers((u32 *)ctx, par->f8, s5, s8);
    ctx->c = par->f0 << 7;
    ctx->h30 = s6;
    ctx->h10 = par->f4;
    ctx->h14 = par->f6;
    ctx->h18 = t;
    ctx->h1c = a2;
    ctx->h20 = a3;
    ctx->h24 = 0;
    ctx->h34 = s7;
    ctx->h28 = s8;
    ctx->h2c = par->fb;
    WIPE_SUB_CalcCircleLines((struct Wipe *)ctx);
    off = 0x3ff;
    func_020056A0(WIPE_SUB_FlipLineBuffersTask, ctx, off);
    base = WIPE_SUB_GetLineBuffer((struct Obj *)ctx, 0);
    w = *(s16 *)((char *)base + (off - 0xff));
    off += 0x81;
    h = *(s16 *)((char *)base + off);
    WIPE_SUB_SetupWindow(s6, par->f9, par->fa, par->f8,
                  s5, w, 0, h, 0xc0, ctx->h2c);
    if (par->f8 == 0) {
        WIPE_SUB_SetWindowVisibleMode(s6, 1, s5, ctx->h2c);
    } else {
        WIPE_SUB_SetWindowVisibleMode(s6, 2, s5, ctx->h2c);
    }
    WIPE_RequestSetHBlankSlot(ctx->h34, (u32)ctx, (u32)WIPE_SUB_WindowRectHBlank, s5, s8);
}

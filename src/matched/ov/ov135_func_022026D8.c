/*
 * function: WORLDTRADE_ADAPTER_InitPrinter
 * address:  0x022026D8
 * packet:   pkt_022026D8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   TCBL_Create  0x0203101C  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   func_02028590  0x02028590  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void MI_CpuFill8(void *p, u32 v, u32 n);
struct GfFont;
struct Tcbl;
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void *func_02028590(u32 a0, u32 a1, u32 a2, u32 heap);

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Slot;

typedef struct {
    void *font;
    void *buf;
    u32 arg;
    void *msg;
    u8 pad10[8];
    Slot slot[0x18];
    void *res;
} Ctx;

void WORLDTRADE_ADAPTER_InitPrinter(Ctx *ctx, u32 arg)
{
    int i;
    Slot *s;

    MI_CpuFill8(ctx, 0, 0x13C);
    ctx->buf = TCBL_Create(0x48, 0x48, 0x20, 0x20);
    ctx->arg = arg;
    ctx->font = GF_FONT_Create(0x17, 0, 0, 0, 0x48);
    ctx->msg = (void *)PRINTSYS_QUE_Create((void *)0x48);
    ctx->res = func_02028590(0xF, 1, 1, 0x48);
    for (i = 0; i < 0x18; i++) {
        s = &ctx->slot[i];
        MI_CpuFill8(s, 0, 8);
        s->c = 0;
    }
}

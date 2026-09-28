/*
 * function: func_022026D8
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203101C  0x0203101C  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02028590  0x02028590  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *func_0203101C(u32 a, u32 b, u32 c, u32 d);
extern void *func_0201D7EC(u32 a, u32 b, u32 c, u32 d, u32 heap);
extern void *func_0201C440(u32 heap);
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

void func_022026D8(Ctx *ctx, u32 arg)
{
    int i;
    Slot *s;

    func_02082BCC(ctx, 0, 0x13C);
    ctx->buf = func_0203101C(0x48, 0x48, 0x20, 0x20);
    ctx->arg = arg;
    ctx->font = func_0201D7EC(0x17, 0, 0, 0, 0x48);
    ctx->msg = func_0201C440(0x48);
    ctx->res = func_02028590(0xF, 1, 1, 0x48);
    for (i = 0; i < 0x18; i++) {
        s = &ctx->slot[i];
        func_02082BCC(s, 0, 8);
        s->c = 0;
    }
}

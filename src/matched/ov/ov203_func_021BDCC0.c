/*
 * function: DEMO3D_CreateContext
 * address: 0x021BDCC0
 * packet: pkt_ov203_021BDCC0
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C3CC0 0x021C3CC0 data a1
 *   d_021C3BC4 0x021C3BC4 data a4
 */
typedef struct Context Context;
typedef struct Methods { void (*init)(Context *); } Methods;
struct Context { unsigned short heap, pad; void *a, *b; const Methods *methods; void *work; int flag; };
extern const char d_021C3CC0[];
extern const Methods d_021C3BC4;
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
Context *DEMO3D_CreateContext(int mode, void *a, void *b, unsigned heap)
{
    Context *ctx;
    ctx = func_02030734(heap, 24, 1, d_021C3CC0, 0x1e1);
    ctx->a = a;
    ctx->b = b;
    ctx->heap = heap;
    ctx->methods = 0;
    ctx->flag = 0;
    if (mode == 1) {
        ctx->methods = &d_021C3BC4;
        ctx->flag = 1;
    }
    if (ctx->methods) ctx->methods->init(ctx);
    return ctx;
}

/*
 * function: func_02202974
 * address:  0x02202974
 * packet:   pkt_02202974
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   g_02203F5C     0x02203F5C  data  ov135
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 g_02203F5C[];

struct GfFont;
struct MsgBank;
struct WordSet;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);

typedef struct {
    void *font;
    void *msg;
    void *words;
    void *bank;
    u8 pad10[0x60];
    u16 heap;
} Ctx;

Ctx *func_02202974(u32 a, u32 b, u32 c, u32 heap)
{
    Ctx *ctx;

    ctx = func_02030734(heap, 0x74, 0, (const char *)g_02203F5C, 0x1DD);
    func_02082BCC(ctx, 0, 0x74);
    ctx->heap = heap;
    ctx->font = func_0201D7EC(0x17, 3, 0, 0, heap);
    ctx->msg = (void *)func_0201C440((void *)heap);
    ctx->bank = func_02045B38(0, 2, 0xD0, heap);
    ctx->words = func_0201EC64(heap);
    return ctx;
}

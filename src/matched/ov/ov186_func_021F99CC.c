/*
 * function: BR_PROC_SYS_Create
 * address: 0x021F99CC
 * packet: pkt_ov186_021F99CC
 * region: ov186
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   BR_PROC_SYS_ClearEntry 0x021F9CA4 thumb
 *   BR_PROC_SYS_PushEntry 0x021F9BF4 thumb
 *   d_02200D04 0x02200D04 data a1
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, int, unsigned);
extern void *PROCSYS_Create(int a0);
extern void BR_PROC_SYS_ClearEntry(void *);
extern void BR_PROC_SYS_PushEntry(unsigned *ctx, unsigned index);
extern char d_02200D04[];
typedef struct {
    unsigned object;
    void *base;
    unsigned short count, pad;
    unsigned arg;
    unsigned short heap, pad2;
    unsigned words[21];
    unsigned *list;
    unsigned loaded;
} Context;
Context *BR_PROC_SYS_Create(unsigned fallback, void *base, unsigned count, unsigned arg, unsigned *list, unsigned short heap)
{
    Context *ctx;
    unsigned i = 0;
    ctx = func_02030734(heap, 0x70, 0, d_02200D04, 0x77);
    MI_CpuFill8(ctx, 0, 0x70);
    ctx->heap = heap;
    ctx->count = count;
    ctx->arg = arg;
    ctx->base = base;
    ctx->list = list;
    ctx->object = (unsigned int)PROCSYS_Create(heap);
    BR_PROC_SYS_ClearEntry((char *)ctx + 0x2c);
    BR_PROC_SYS_ClearEntry((char *)ctx + 0x3c);
    BR_PROC_SYS_ClearEntry((char *)ctx + 0x1c);
    if (ctx->list[6]) {
        for (i = 0; i < ctx->list[6]; i++) {
            BR_PROC_SYS_PushEntry((unsigned int *)ctx, (unsigned short)ctx->list[i]);
        }
        MI_CpuFill8(ctx->list, 0, 0x1c);
        ctx->loaded = 1;
    } else {
        BR_PROC_SYS_PushEntry((unsigned int *)ctx, fallback);
    }
    return ctx;
}

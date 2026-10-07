/*
 * file:     br_proc_sys_p04.c
 * unit:     yes
 * function: func_021F99CC, func_021F9A6C
 * address:  0x021F99CC
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02031324 0x02031324 arm
 *   func_021F9CA4 0x021F9CA4 thumb
 *   func_021F9BF4 0x021F9BF4 thumb
 *   d_02200D04 0x02200D04 data a1
 *   func_0203133C  0x0203133C  arm
 *   func_020307B0  0x020307B0  arm
 */
struct S020314B8;
typedef unsigned short u16;

typedef unsigned int   u32;

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

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, unsigned);
extern void *func_02031324(int a0);
extern void func_021F9CA4(void *);
extern void func_021F9BF4(unsigned *ctx, unsigned index);
extern void func_0203133C(struct S020314B8 *);
extern u32 func_020307B0(void *p);
Context *func_021F99CC(unsigned fallback, void *base, unsigned count, unsigned arg, unsigned *list, unsigned short heap);
void func_021F9A6C(int *p);
extern char d_02200D04[];

Context *func_021F99CC(unsigned fallback, void *base, unsigned count, unsigned arg, unsigned *list, unsigned short heap)
{
    Context *ctx;
    unsigned i = 0;
    ctx = func_02030734(heap, 0x70, 0, d_02200D04, 0x77);
    func_02082BCC(ctx, 0, 0x70);
    ctx->heap = heap;
    ctx->count = count;
    ctx->arg = arg;
    ctx->base = base;
    ctx->list = list;
    ctx->object = (unsigned int)func_02031324(heap);
    func_021F9CA4((char *)ctx + 0x2c);
    func_021F9CA4((char *)ctx + 0x3c);
    func_021F9CA4((char *)ctx + 0x1c);
    if (ctx->list[6]) {
        for (i = 0; i < ctx->list[6]; i++) {
            func_021F9BF4((unsigned int *)ctx, (unsigned short)ctx->list[i]);
        }
        func_02082BCC(ctx->list, 0, 0x1c);
        ctx->loaded = 1;
    } else {
        func_021F9BF4((unsigned int *)ctx, fallback);
    }
    return ctx;
}


void func_021F9A6C(int *p)
{
    func_0203133C((struct S020314B8 *)p[0]);
    func_020307B0(p);
}

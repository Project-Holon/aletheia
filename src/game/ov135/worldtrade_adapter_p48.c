/*
 * file:     worldtrade_adapter_p48.c
 * unit:     yes
 * function: func_02202940, func_02202974, func_022029D4, func_022029F8, func_02202A50
 * address:  0x02202940
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   g_02203F5C     0x02203F5C  data  ov135
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_02034714  0x02034714  arm
 */
#include "../../matched/include/Obj07259.h"

struct Rec3;
struct GfFont;
struct MsgBank;
struct WordSet;
struct PrintSys;
struct Rec;
struct Descriptor;
struct U16Vec;
typedef unsigned int u32;

struct Ent { u32 a; u32 b; u32 c; };

struct Obj { u32 w0; u32 w1; u32 w2; u32 w3; void *h; u32 n; struct Ent e[24]; };

typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    void *font;
    void *msg;
    void *words;
    void *bank;
    u8 pad10[0x60];
    u16 heap;
} Ctx_02202974;

typedef signed int s32;

typedef struct {
    void *win;
    u8 busy;
} Ent;

typedef struct {
    u8 pad0[4];
    void *queue;
    u8 pad8[0x10 - 8];
    Ent ent[8];
    void *active[8];
} Printer;

typedef struct {
    void *win;
    u8 shown;
    u8 pad5[3];
} Slot;

typedef struct {
    void *font;
    void *print;
    void *words;
    void *bank;
    Slot slot[8];
    u32 used[8];
    u16 heap;
} Ctx_02202A50;

extern void func_0201CE48(struct Rec3 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_020307B0(void *p);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_02034714(const char *expr, u32 line, const char *file);
void func_02202940(struct Obj *p);
Ctx_02202974 *func_02202974(u32 a, u32 b, u32 c, u32 heap);
void func_022029D4(u8 *p);
void func_022029F8(Printer *q);
void func_02202A50(Ctx_02202A50 *ctx, u32 num, u32 digits, u32 mode, void *win, int x, int y);
extern u8 g_02203F5C[];

/*
 * note: 2026-10-05 P22L9: array base reached through a static inline accessor p->e (the bare field, a local pointer and u32 arithmetic all kept the base in r1, DIFF16/13). The zero stored is the counter's initial copy (idiom a-copy-of-the-counter-before-the-loop-label-is-a-stored-zero).
 */
void func_02202940(struct Obj *p) {
    int i;
    for (i = 0; i < 24; i++) {
        struct Ent *e = p->e + i;
        if (e->c != 0) e->c = 0;
    }
    if (p->h != 0) {
        func_0201CE48(p->h);
        p->h = 0;
        p->n = 0;
    }
}


Ctx_02202974 *func_02202974(u32 a, u32 b, u32 c, u32 heap)
{
    Ctx_02202974 *ctx;

    ctx = func_02030734(heap, 0x74, 0, (const char *)g_02203F5C, 0x1DD);
    func_02082BCC(ctx, 0, 0x74);
    ctx->heap = heap;
    ctx->font = func_0201D7EC(0x17, 3, 0, 0, heap);
    ctx->msg = (void *)func_0201C440((void *)heap);
    ctx->bank = func_02045B38(0, 2, 0xD0, heap);
    ctx->words = func_0201EC64(heap);
    return ctx;
}


/*
 * Release every buffer the object owns, then the object itself.
 */
void func_022029D4(u8 *p)
{
    func_0201ED04((struct WordSet *)(((struct Obj07259 *)p)->f8));
    func_02045C04((struct Rec *)(((struct Obj07259 *)p)->fC));
    func_0201C4C0((struct PrintSys *)(((struct Obj07259 *)p)->f4));
    func_0201D83C((void *)(((struct Obj07259 *)p)->f0));
    func_020307B0((void *)((u32)p));
}


void func_022029F8(Printer *q)
{
    int i;
    void *queue;

    for (i = 0; i < 8; i++) {
        if (q->active[i] != 0) {
            queue = q->queue;
            if (q->ent[i].busy != 0 && func_0201C6C4(queue, func_02045770(q->ent[i].win)) == 0) {
                func_02045334(q->ent[i].win);
                q->ent[i].busy = 0;
            }
            if (q->ent[i].busy == 0) {
                q->active[i] = 0;
            }
        }
    }
    func_0201C4E4(q->queue);
}


void func_02202A50(Ctx_02202A50 *ctx, u32 num, u32 digits, u32 mode, void *win, int x, int y)
{
    void *str;
    void *fmt;
    void *print;
    int i;

    str = func_020457B0(0x20, ctx->heap);
    fmt = func_020457B0(0x20, ctx->heap);
    func_02045CAC(ctx->bank, 0xFD, fmt);
    func_0201EFA4(ctx->words, 0, num, digits, mode, 1);
    func_0201F250(ctx->words, str, fmt);
    for (i = 0; i < 8; i++) {
        if (ctx->used[i] == 0) {
            ctx->slot[i].win = win;
            ctx->slot[i].shown = 0;
            print = ctx->print;
            func_0201C724(print, (u32)func_02045770(ctx->slot[i].win), (s16)x, (s16)y, (u32)str, (u32)ctx->font, 0x3DC8);
            ctx->slot[i].shown = 1;
            ctx->used[i] = 1;
            func_02045808(fmt);
            func_02045808(str);
            return;
        }
    }
    func_02034714((void *)0x02203F74, 0, (void *)0x02203F74);
}

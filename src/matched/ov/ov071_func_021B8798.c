/*
 * function: func_021B8798
 * address:  0x021B8798
 * packet:   pkt_ov071_021B8798
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The `src + 0x18` is written in each arm (the compiler tail-merges the
 * adds at the join), the bitfield `y` is read into a local before the
 * first call, and `q->f8` goes through a local reassigned before each
 * draw call so it loads ahead of the nested call.
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   INTRUDE_COMM_IsSessionActive  0x02175B14  thumb  ov011
 *   INTRUDE_COMM_GetActiveSessionRequest  0x02175B34  thumb  ov011
 *   func_02045EC0  0x02045EC0  arm
 *   INTRUDE_COMM_SetWordSetRequest  0x021762D8  thumb  ov011
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   d_021BAA4C     0x021BAA4C  data  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 kind : 4;
    u32 b4 : 14;
    u32 b18 : 11;
    u32 b29 : 3;
    u32 pad8[4];
} Obj;

typedef struct {
    char pad0[8];
    void *f8;
    void *fc;
    void *f10;
    char pad14[8];
    void *f1c;
    char pad20[0x40];
    Obj ent[1];
} Q;

typedef struct {
    void *h[2];
    struct {
        void *h;
        u8 on;
    } e[2];
} P;

extern int d_021BAA4C[];

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PrintSys;
void func_021B8798(u8 **c, Q *q, P *d, u8 *r, unsigned v)
{
    extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
    extern void *BMP_WIN_GetBmp(struct Descriptor *p);
    extern void BMP_Clear(struct CharBuf *buf, u8 value);
    extern int INTRUDE_COMM_IsSessionActive(u8 *);
    extern u8 *INTRUDE_COMM_GetActiveSessionRequest(u8 *p);
    extern void *func_02045EC0(struct MsgBank *bank, u32 index);
    extern void INTRUDE_COMM_SetWordSetRequest(Obj *, void *, void *, int);
    extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
    extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
    extern void STRBUF_Delete(struct U16Vec *vec);
    void *s;
    u8 *src;
    Obj *e;
    u32 y;
    void *t0;
    void *t1;
    void *w;

    s = STRBUF_Create(0x100, 0x61);
    BMP_Clear(BMP_WIN_GetBmp(d->h[0]), 0);
    BMP_Clear(BMP_WIN_GetBmp(d->h[1]), 0);
    if (v == 6 && r != 0 && INTRUDE_COMM_IsSessionActive(r + 0x1AC) == 1) {
        e = (Obj *)INTRUDE_COMM_GetActiveSessionRequest(r + 0x1AC);
        src = (u8 *)e + 0x18;
    } else {
        if (v > 6) {
            v = 0;
        }
        e = &q->ent[d_021BAA4C[v]];
        src = *c + 0x18;
    }
    y = e->b18;
    t0 = func_02045EC0(q->f1c, e->kind);
    t1 = func_02045EC0(q->f1c, y);
    INTRUDE_COMM_SetWordSetRequest(e, src, q->f10, 0x61);
    WORDSET_CopyTaggedText(q->f10, s, t1);
    w = q->f8;
    PRINTSYS_PrintQue(w, (u32)BMP_WIN_GetBmp(d->e[0].h), 0, 4, t0, (u32)q->fc);
    d->e[0].on = 1;
    w = q->f8;
    PRINTSYS_PrintQue(w, (u32)BMP_WIN_GetBmp(d->e[1].h), 0, 0, s, (u32)q->fc);
    d->e[1].on = 1;
    STRBUF_Delete(t0);
    STRBUF_Delete(t1);
    STRBUF_Delete(s);
}

/*
 * function: func_021BA5D4
 * address:  0x021BA5D4
 * packet:   pkt_ov071_021BA5D4
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Extent after 0x021BA756 is alignment and rodata, not a code follower.
 * Lever: a 12-byte Record subscript retains the second-path scale in r0;
 * byte indexing instead adds a copy and shifts the remainder by 2 bytes.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045808 0x02045808 arm
 *   func_02045334 0x02045334 arm
 *   func_021B6F40 0x021B6F40 thumb ov071
 */
#include "../include/Obj03665.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 a, b; u8 pad[10]; } Record;
typedef struct { u8 pad[12]; u16 n, m; } Counts;
typedef struct {
    u8 pad[8];
    void *f8;
    u32 fc;
    void *f10;
    u8 pad14[12];
    void *f20, *f24, *f28;
    u8 pad2c[8];
    Record *f34;
} Q;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct PrintSys;
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *d);
extern Counts *func_021B6F40(u8 *);

static inline void Draw(Q *q, void *h, u32 x, u32 y, void *s)
{
    void *w = q->f8;
    func_0201C6FC(w, (u32)func_02045770(h), x, y, s, q->fc);
}

void func_021BA5D4(u8 *a, Q *q, u8 *p)
{
    u32 k;
    void *s, *t, *u;
    Counts *counts;
    int off;
    u32 index;
    u32 value;

    k = (*(u8 **)(a + 8))[1];
    func_02043B5C(func_02045770(((struct Obj03665 *)p)->f8), 0);
    if (k != 0x30) {
        if ((*(u8 **)(a + 8))[2] == 0) {
            off = k * 12;
            func_0201EFA4(q->f10, 0, *(u16 *)((u8 *)q->f34 + off + 2), 4, 0, 1);
            s = func_02045EC0(q->f24, *(u16 *)((u8 *)q->f34 + off + 6));
            t = func_02045EC0(q->f28, 0x28);
            u = func_020457B0(0x40, 0x61);
            func_0201F250(q->f10, u, t);
            Draw(q, ((struct Obj03665 *)p)->f1C, 0, 4, s);
            p[0x20] = 1;
            Draw(q, ((struct Obj03665 *)p)->f1C, 0x70, 0x34, u);
            p[0x20] = 1;
            func_02045808(s);
            func_02045808(t);
            func_02045808(u);
        } else {
            counts = func_021B6F40(a);
            value = q->f34[k].a;
            if ((int)value > counts->n) {
                index = 0x29;
            } else {
                value = q->f34[k].b;
                index = 0x2a;
            }
            func_0201EFA4(q->f10, 0, value, 3, 0, 1);
            func_0201EFA4(q->f10, 1, counts->n, 3, 0, 1);
            func_0201EFA4(q->f10, 2, counts->m, 3, 0, 1);
            s = func_02045EC0(q->f28, index);
            u = func_020457B0(0x80, 0x61);
            func_0201F250(q->f10, u, s);
            Draw(q, ((struct Obj03665 *)p)->f1C, 0, 4, u);
            p[0x20] = 1;
            func_02045808(u);
            func_02045808(s);
        }
    } else {
        func_02045334(((struct Obj03665 *)p)->f8);
    }
}

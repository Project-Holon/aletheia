/*
 * function: MONOLITH_TOOL_DrawSelectedEntry
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
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   MONOLITH_TOOL_GetSlotIconStates 0x021B6F40 thumb ov071
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
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct PrintSys;
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void *MONOLITH_TOOL_GetSlotIconStates(u8 **p);

static inline void Draw(Q *q, void *h, u32 x, u32 y, void *s)
{
    void *w = q->f8;
    PRINTSYS_PrintQue(w, (u32)BMP_WIN_GetBmp(h), x, y, s, q->fc);
}

void MONOLITH_TOOL_DrawSelectedEntry(u8 *a, Q *q, u8 *p)
{
    u32 k;
    void *s, *t, *u;
    Counts *counts;
    int off;
    u32 index;
    u32 value;

    k = (*(u8 **)(a + 8))[1];
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj03665 *)p)->f8), 0);
    if (k != 0x30) {
        if ((*(u8 **)(a + 8))[2] == 0) {
            off = k * 12;
            func_0201EFA4(q->f10, 0, *(u16 *)((u8 *)q->f34 + off + 2), 4, 0, 1);
            s = func_02045EC0(q->f24, *(u16 *)((u8 *)q->f34 + off + 6));
            t = func_02045EC0(q->f28, 0x28);
            u = STRBUF_Create(0x40, 0x61);
            func_0201F250(q->f10, u, t);
            Draw(q, ((struct Obj03665 *)p)->f1C, 0, 4, s);
            p[0x20] = 1;
            Draw(q, ((struct Obj03665 *)p)->f1C, 0x70, 0x34, u);
            p[0x20] = 1;
            STRBUF_Delete(s);
            STRBUF_Delete(t);
            STRBUF_Delete(u);
        } else {
            counts = MONOLITH_TOOL_GetSlotIconStates((u8 **)a);
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
            u = STRBUF_Create(0x80, 0x61);
            func_0201F250(q->f10, u, s);
            Draw(q, ((struct Obj03665 *)p)->f1C, 0, 4, u);
            p[0x20] = 1;
            STRBUF_Delete(u);
            STRBUF_Delete(s);
        }
    } else {
        BMP_WIN_TransferChars(((struct Obj03665 *)p)->f8);
    }
}

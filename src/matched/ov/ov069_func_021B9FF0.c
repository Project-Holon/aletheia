/*
 * function: func_021B9FF0
 * address:  0x021B9FF0
 * packet:   pkt_ov069_021B9FF0
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note 2026-10-05 (wave P2 Q9b, pengy share): the record is addressed with the
 * struct subscript &tbl[idx] for the fields, while the memcpy source is written
 * as (char *)tbl + off with a separate int off = idx * 0x22. Written that way the
 * compiler keeps tbl in r6 and off in r7 and spills a, b, rec (declaration order
 * a, b, rec, name, off). Two spellings of one address, as a person would write.
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F048  0x0201F048  thumb
 *   func_0201F094  0x0201F094  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045994  0x02045994  arm
 *   func_0202435C  0x0202435C  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WordSet; struct U16Vec; struct Descriptor; struct CharBuf; struct Cfg; struct Strbuf;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EFA4(struct WordSet *, u32, u32, u32, u32, u32);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C724(void *, void *, int, int, void *, void *, int);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern void *func_0202435C(void *slots, unsigned int heap);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);

struct Rec { u8 pad0[0x12]; u8 a; u8 b; u8 pad1[4]; u16 name[5]; };
void func_021B9FF0(char *p, struct Rec *tbl, int idx)
{
    u32 a;
    u32 b;
    struct Rec *rec;
    char *name;
    int off;
    struct U16Vec *vec;
    struct Descriptor *d;
    int n;
    off = idx * 0x22;
    rec = &tbl[idx];
    a = rec->a;
    b = rec->b;
    name = (char *)rec + 0x18;
    vec = func_020457B0(0x10, 0x80);
    func_0201EFA4(*(struct WordSet **)(p + 0xF8), 0, *(u32 *)(*(char **)(p + 0x154) + 4), 2, 0, 1);
    func_0201EFA4(*(struct WordSet **)(p + 0xF8), 1, *(u32 *)(*(char **)(p + 0x154) + 8), 3, 0, 1);
    func_0201F048(*(struct WordSet **)(p + 0xF8), 2, a);
    func_0201F094(*(struct WordSet **)(p + 0xF8), 3, a, b);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x3C)), 0);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x40)), 0);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x44)), 0);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x4C)), 0);
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x54)), 0);
    if (idx < *(int *)(p + 0x164)) {
        void *ws;
        void *str;
        n = 8;
        func_02045994((struct Strbuf *)vec, (const u16 *)((char *)tbl + off), n);
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, func_02045770(*(struct Descriptor **)(p + 0xC0)), 0, 0, vec, *(void **)(p + 0xC), 0x3DC0);
        *(u8 *)(p + 0xC4) = 1;
        func_0201F250(*(struct WordSet **)(p + 0xF8), *(void **)(p + 0xFC), *(void **)(p + n + 0xFC));
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, func_02045770(*(struct Descriptor **)(p + 0xB0)), 0, 0, *(void **)(p + 0xFC), *(void **)(p + 0xC), 0x3DC0);
        *(u8 *)(p + 0xB4) = 1;
        func_0201F250(*(struct WordSet **)(p + 0xF8), *(void **)(p + 0xFC), *(void **)(p + 0x108));
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, func_02045770(*(struct Descriptor **)(p + 0xB8)), 0, 0, *(void **)(p + 0xFC), *(void **)(p + 0xC), 0x3DC0);
        *(u8 *)(p + 0xBC) = 1;
        func_0201F250(*(struct WordSet **)(p + 0xF8), *(void **)(p + 0xFC), *(void **)(p + 0x110));
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, func_02045770(*(struct Descriptor **)(p + 0xD0)), 0, 0, *(void **)(p + 0xFC), *(void **)(p + 0xC), 0x3DC0);
        *(u8 *)(p + 0xD4) = 1;
        func_0201F250(*(struct WordSet **)(p + 0xF8), *(void **)(p + 0xFC), *(void **)(p + 0x114));
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, func_02045770(*(struct Descriptor **)(p + 0xD0)), 0, 0x10, *(void **)(p + 0xFC), *(void **)(p + 0xC), 0x3DC0);
        *(u8 *)(p + 0xD4) = 1;
        str = func_0202435C((void *)name, 0x80);
        ws = *(void **)(p + 0xE8);
        func_0201C724(ws, func_02045770(*(struct Descriptor **)(p + 0xE0)), 0, 0, str, *(void **)(p + 0xC), 0x3DC0);
        *(u8 *)(p + 0xE4) = 1;
        func_02045808((struct U16Vec *)str);
    } else {
        d = *(struct Descriptor **)(p + 0x44);
        func_02045334(d); func_02045374((struct Cfg *)d); func_02041B6C(func_02045730(d));
        d = *(struct Descriptor **)(p + 0x4C);
        func_02045334(d); func_02045374((struct Cfg *)d); func_02041B6C(func_02045730(d));
        d = *(struct Descriptor **)(p + 0x54);
        func_02045334(d); func_02045374((struct Cfg *)d); func_02041B6C(func_02045730(d));
    }
    func_02045808(vec);
}

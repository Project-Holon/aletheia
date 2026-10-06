/*
 * function: func_021B9CBC
 * address: 0x021B9CBC
 * packet: pkt_ov220_021B9CBC
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * note: 2026-10-05 (wD9r Q5b): EXACT. Three source facts closed the 62 B. (1) The pool cap is 9999 (0x270F), not an
 *   overlay id: `if (m > 9999) m = 9999;` with no ov015_id symbol. (2) The d_021BA314 table is declared without const
 *   (a const byte table is hoisted above the stack-argument stores; the original reads it below them). This fixed the
 *   draw-call order of blocks 2 and 4 and the pool-load position of block 4. (3) The second width goes through the
 *   reused temp `h = (u16)f2(); n = w1 + 8 + h;` and w1 is a u32 holding `(u16)f1()`; this puts (w1+8) in r0 after
 *   the second width in r1 and orders the block 2 spill reload. The u16 callee return drops the casts (539 B off).
 *   Earlier notes (Q5): twin shape from ov223 021BB18C (words, msg, width, centre, draw); `idx = 0x26; if (b[1]) idx = 0x27;`
 *   polarity; clamp local m is u32 with a u16 callee parameter; a/b locals declared b first. Pragmas opt_common_subs,
 *   opt_dead_assignments and peephole off: no help. Data hint: `data a1` (the ov220 token is contested).
 *   Real bug candidates: none seen. x/y/off are always set; A (sp+0x24) is read only on the flag path.
 *
 * symbols:
 *   func_02049B90 0x02049B90 arm
 *   func_02045B38 0x02045B38 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045994 0x02045994 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_020437DC 0x020437DC arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021BA068 0x021BA068 thumb ov220
 *   func_021BA01C 0x021BA01C thumb ov220
 *   d_021BA354 0x021BA354 data ov220 a1
 *   d_021BA314 0x021BA314 data a1
 *   d_021BA3A8 0x021BA3A8 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Info { u8 pad0[4]; u8 *base; u32 flag; };
struct Obj {
    u16 heap; u16 pad2; struct Info *info; u32 pad8;
    void *str; void *bmp; u8 pad14[0x5c - 0x14];
    void *bank; void *ptr[4]; u32 done[4]; u32 f80;
};
struct Rec { u32 msg; u16 a; u16 level; u32 b; };
extern const u8 d_021BA354[];
extern u8 d_021BA314[];
extern const struct Rec d_021BA3A8[];
extern void func_02049B90(u32,u32,u32,u32,u32,u32,u16);
struct Bmp;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct Strbuf;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_0201C724(void *, void *, u32, u32, void *, void *, u16);
extern void func_02045808(struct U16Vec *vec);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201ED04(struct WordSet *p);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern u8 func_021BA068(u32);
extern void func_021BA01C(struct Obj *o);
void func_021B9CBC(struct Obj *p)
{
    u8 i;
    u8 *b;
    u8 *a;
    void *x;
    void *y;
    void *g, *t, *z, *q;
    u16 off, n;
    u32 w1;
    u32 h, idx, m;
    u8 k;
    p->bank = 0;
    for (i = 0; i < 4; i++) {
        p->ptr[i] = 0;
        p->done[i] = 0;
    }
    p->done[0] = 1;
    p->f80 = 0;
    if (p->info->flag) {
        b = a = p->info->base;
        b += 0x14;
        a += 0x38;
    } else {
        b = p->info->base;
    }
    if (b[0] == 0) return;
    func_02049B90(0x17, 5, 0, 0, 0x40, 0x20, p->heap);
    p->bank = func_02045B38(0, 3, 0x1CD, p->heap);
    for (i = 0; i < 4; i++) {
        p->ptr[i] = (void *)func_020450F0(d_021BA354[i*7], d_021BA354[i*7+1], d_021BA354[i*7+2], d_021BA354[i*7+3], d_021BA354[i*7+4], d_021BA354[i*7+5], d_021BA354[i*7+6]);
        func_02043B5C(func_02045770(p->ptr[i]), (u32)0);
        func_02045334(p->ptr[i]);
    }
    if (p->info->flag) {
        x = func_020457B0(0x11, (u16)p->heap);
        func_02045994(x, (const u16 *)a, 0x11);
    } else {
        idx = 0x26;
        if (b[1]) idx = 0x27;
        x = func_02045EC0(p->bank, idx);
    }
    y = func_02045EC0(p->bank, 0x28);
    off = 0;
    w1 = (u16)func_0201D304(x, (u32)p->str, 0);
    h = (u16)func_0201D304(y, (u32)p->str, 0);
    n = w1 + 8 + h;
    h = (u32)func_020437DC(func_02045770(p->ptr[1]));
    if (h >= n) off = ((int)(h - n)) / 2;
    k = d_021BA314[1];
    func_0201C724(p->bmp, func_02045770(p->ptr[1]), (s16)off, k, x, p->str, 0x440);
    func_0201C724(p->bmp, func_02045770(p->ptr[1]), (s16)(u16)(off + w1 + 8), k, y, p->str, 0x440);
    func_02045808(y);
    func_02045808(x);
    m = *(u16 *)(b + 2);
    if (m > 9999) m = 9999;
    g = func_0201EC64(p->heap);
    t = func_02045EC0(p->bank, 0x2a);
    z = func_020457B0(5, (u16)p->heap);
    off = 0;
    func_0201EFA4(g, 0, (u16)m, 4, 0, 1);
    func_0201F250(g, z, t);
    q = func_02045EC0(p->bank, 0x29);
    w1 = (u16)func_0201D304(z, (u32)p->str, 0);
    h = (u16)func_0201D304(q, (u32)p->str, 0);
    n = w1 + 8 + h;
    h = (u32)func_020437DC(func_02045770(p->ptr[2]));
    if (h >= n) off = ((int)(h - n)) / 2;
    k = d_021BA314[2];
    func_0201C724(p->bmp, func_02045770(p->ptr[2]), (s16)off, k, z, p->str, 0x440);
    func_0201C724(p->bmp, func_02045770(p->ptr[2]), (s16)(u16)(off + w1 + 8), k, q, p->str, 0x440);
    func_02045808(q);
    func_02045808(z);
    func_02045808(t);
    func_0201ED04(g);
    y = func_02045EC0(p->bank, d_021BA3A8[func_021BA068(*(u16 *)(b + 2))].msg);
    w1 = (u16)func_0201D304(y, (u32)p->str, 0);
    h = (u32)func_020437DC(func_02045770(p->ptr[3]));
    off = ((int)(h - w1)) / 2;
    func_0201C724(p->bmp, func_02045770(p->ptr[3]), (s16)off, d_021BA314[3], y, p->str, 0x440);
    func_02045808(y);
    for (i = 1; i < 4; i++) {
        void *d = p->ptr[i];
        func_02045334(d);
        func_02045374(d);
        func_02041B6C(func_02045730(d));
    }
    func_021BA01C(p);
}

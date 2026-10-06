/*
 * function: func_0220BEB8
 * address: 0x0220BEB8
 * packet: pkt_ov198_0220BEB8
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: rec is passed as `*(void **)rec` (a real variable, not a CSE temp); ex is an s16 local (the callee's
 *   parameter type) set in each head arm; a2 is u16 (the caller passes `(u16)i`); tail colour depends on b0
 * 2026-10-05 (wD9r lane121): 45 -> EXACT. Fixes: (1) the 0201EEF4 argument written `*(void **)rec`, so rec is a
 *   declared variable with its own slot (the `base + off` form made it a CSE temp in the lowest slot); (2) lane 94's
 *   declaration order (w2, w, off, handle, rec, vec, msg, x, k, c90, cn0, c91, cn1, ex, m3, m2, x2) with the four
 *   tail ctx values as function-scope locals; (3) ex as s16 (the 0201C724 parameter type), assigned in each head
 *   arm: a u8 copy coalesced with the stack parameter; (4) logic fix: the tail colour is 0x2960 for b0 == 0 and
 *   0x31A0 for b0 == 1 in both k arms (the draft had it per k); (5) a2 as u16 (the matched caller passes
 *   `(u16)i`), which puts the a2 spill store first at entry.
 * symbols:
 *   func_02045778 0x02045778 arm
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045738 0x02045738 arm
 *   func_0201D304 0x0201D304 thumb
 *   d_02211B68 0x02211B68 data ov198 a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

struct R {
    u8 pad[0x16];
    u8 a0 : 7;
    u8 a1 : 1;
    u8 b0 : 3;
    u8 b1 : 4;
    u8 b2 : 1;
};
struct Ov198Hdr { char pad[0xC]; u32 font; u16 f10; };
struct Ov198P { struct Ov198Hdr *hdr; char pad[0x1E9C]; void *f1EA0; void *f1EA4; void *pad8; u32 f1EAC; };
#define P ((struct Ov198P *)p)

struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern u8 func_02045778(struct Descriptor *p);
extern int func_022110D4(u8 *, int);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(u32, u32, s16, s16, void *, u32, u32);
extern void func_02045808(struct U16Vec *vec);
extern u8 func_02045738(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 d_02211B68[];

void func_0220BEB8(u8 *p, int slot, u16 a2, u8 a3, u8 extra)
{
    u32 w2;
    u32 w;
    u32 off;
    void *handle;
    struct R *rec;
    void *vec;
    void *msg;
    u32 x;
    u32 k;
    u32 c90;
    u32 cn0;
    u32 c91;
    u32 cn1;
    s16 ex;
    void *m3;
    void *m2;
    u32 x2;
    int n;
    u8 *base;
    u8 *tab;

    slot = slot * 8;
    tab = p + 0x1F70;
    handle = *(void **)(tab + slot);
    k = func_02045778(handle);
    n = func_022110D4(p, a2);
    base = p + 4;
    off = n * 0x4C;
    rec = (struct R *)(base + off);
    vec = func_020457B0(12, P->hdr->f10);
    msg = func_02045EC0(P->f1EA0, d_02211B68[a2]);
    func_0201EEF4(P->f1EA4, 0, *(void **)rec);
    func_0201F250(P->f1EA4, vec, msg);
    if (k == 9) {
        u32 h9 = P->f1EAC;
        ex = extra;
        func_0201C724(h9, (u32)func_02045770(*(void **)(tab + slot)), a3, ex, vec, P->hdr->font, 0x3DC0);
        *(p + 0x1F74 + slot) = 1;
    } else {
        u32 hn = P->f1EAC;
        ex = extra;
        func_0201C724(hn, (u32)func_02045770(*(void **)(tab + slot)), a3, ex, vec, P->hdr->font, 0x3DC0);
        *(p + 0x1F74 + slot) = 1;
    }
    func_02045808(msg);
    func_02045808(vec);
    if (rec->a1 || rec->b2)
        return;
    if (rec->b0 == 0) {
        m2 = func_02045EC0(P->f1EA0, 0x16);
        w = func_02045738(handle);
        x = (u16)((w << 3) - func_0201D304(m2, P->hdr->font, 0));
        if (k == 9) {
            c90 = P->f1EAC;
            func_0201C724(c90, (u32)func_02045770(*(void **)(tab + slot)), x, ex, m2, P->hdr->font, 0x2960);
            *(p + 0x1F74 + slot) = 1;
        } else {
            cn0 = P->f1EAC;
            func_0201C724(cn0, (u32)func_02045770(*(void **)(tab + slot)), x, ex, m2, P->hdr->font, 0x2960);
            *(p + 0x1F74 + slot) = 1;
        }
        func_02045808(m2);
    } else if (rec->b0 == 1) {
        m3 = func_02045EC0(P->f1EA0, 0x17);
        w2 = func_02045738(handle);
        x2 = (u16)((w2 << 3) - func_0201D304(m3, P->hdr->font, 0));
        if (k == 9) {
            c91 = P->f1EAC;
            func_0201C724(c91, (u32)func_02045770(*(void **)(tab + slot)), x2, ex, m3, P->hdr->font, 0x31A0);
            *(p + 0x1F74 + slot) = 1;
        } else {
            cn1 = P->f1EAC;
            func_0201C724(cn1, (u32)func_02045770(*(void **)(tab + slot)), x2, ex, m3, P->hdr->font, 0x31A0);
            *(p + 0x1F74 + slot) = 1;
        }
        func_02045808(m3);
    }
}

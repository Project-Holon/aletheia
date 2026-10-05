/*
 * function: func_0220BEB8
 * address: 0x0220BEB8
 * packet: pkt_ov198_0220BEB8
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-05 (wave D4 lane 10): first draft, DIFF, 508 of 536 bytes. Logic follows the listing
 *   (empty `if (k == 9)` around the first draw gives the `bne; b` pair; per-arm ctx locals; a3 is s16 so no
 *   truncation; record bitfields as in 0220DA6C). Residue: (1) the original keeps 0x1EA0 as a real
 *   variable in [sp,#0x58]/[sp,#0x5c] per block and adds 0xC to it at run time (`ldr; adds #0xc; str`);
 *   mwcc propagates our `c = 0x1EA0; c += 0xC` (u32 and u16 tried) and derives it from 0x1F74; (2) colours:
 *   original p r5, slot r4, tab r6, base r7 and reloads 0x1F70 from the pool; ours keeps 0x1F70 in r6 and
 *   spills base; moving the tab declaration and dropping the tab local changed nothing. Frame 0x60 vs 0x50.
 * 2026-10-05 (wD5 lane10): still DIFF, 450 bytes (was 477), compiled 496 of 536. Each 0201C724 call in the two
 *   tail blocks goes through a static inline put(win, sel, x, y, h, fc, color) helper (the sibling 0220C8F0 closed this
 *   way); the c/ctx locals are gone and the frame is now 0x60 as in the original. Residue: the original keeps tab (p+0x1F70)
 *   in r6, slot*8 in r4 and base in r7 and reloads 0x1F70 from the pool; ours keeps the 0x1F70 constant in r4 and spills
 *   base. The original 0x1EA0-in-a-slot `adds #0xc` is compiler constant reuse on a spilled constant, not source.
 *   Also tried: the tail blocks as one inline title(p, tab, fl, slot, handle, k, ex, id) helper (identical output),
 *   0201C724's font read inside put (480 bytes, arms merge), func_02045770 inside put (446 bytes, frame 0x50: the win
 *   load then lands in the freed constant register r4 instead of a slot). Core residue is the allocator keeping the
 *   0x1F70 constant in r4 where the original keeps slot*8 there.
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

extern u32 func_02045778(void *);
extern int func_022110D4(u8 *, int);
extern void *func_020457B0(u32, u32);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_0201EEF4(void *p, u32 i, void *mon);
extern void func_0201F250(void *ws, void *dst, void *src);
extern void *func_02045770(void *p);
extern void func_0201C724(u32, u32, s16, s16, void *, u32, u32);
extern void func_02045808(void *);
extern u32 func_02045738(void *);
extern u32 func_0201D304(void *, u32, u32);
extern u32 d_02211B68[];

static inline void put(u32 win, u32 sel, s16 x, s16 y, void *h, u32 fc, u32 color)
{
    func_0201C724(win, sel, x, y, h, fc, color);
}

void func_0220BEB8(u8 *p, int slot, int a2, s16 a3, u8 extra)
{
    void *handle;
    u32 k;
    int n;
    u8 *base;
    u32 off;
    struct R *rec;
    u8 *tab;
    void *vec;
    void *msg;
    u8 ex;
    u8 *fl;
    void *m2;
    u32 w;
    u32 x;
    void *m3;
    u32 w2;
    u32 x2;

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
    func_0201EEF4(P->f1EA4, 0, *(void **)(base + off));
    func_0201F250(P->f1EA4, vec, msg);
    ex = extra;
    if (k == 9) {
        func_0201C724(P->f1EAC, (u32)func_02045770(*(void **)(tab + slot)), a3, ex, vec, P->hdr->font, 0x3DC0);
    } else {
        func_0201C724(P->f1EAC, (u32)func_02045770(*(void **)(tab + slot)), a3, ex, vec, P->hdr->font, 0x3DC0);
    }
    fl = p + 0x1F74;
    fl[slot] = 1;
    func_02045808(msg);
    func_02045808(vec);
    if (rec->a1 || rec->b2)
        return;
    if (rec->b0 == 0) {
        m2 = func_02045EC0(P->f1EA0, 0x16);
        w = func_02045738(handle);
        x = (u16)((w << 3) - func_0201D304(m2, P->hdr->font, 0));
        if (k == 9) {
            put(P->f1EAC, (u32)func_02045770(*(void **)(tab + slot)), x, ex, m2, P->hdr->font, 0x2960);
        } else {
            put(P->f1EAC, (u32)func_02045770(*(void **)(tab + slot)), x, ex, m2, P->hdr->font, 0x31A0);
        }
        fl[slot] = 1;
        func_02045808(m2);
    } else if (rec->b0 == 1) {
        m3 = func_02045EC0(P->f1EA0, 0x17);
        w2 = func_02045738(handle);
        x2 = (u16)((w2 << 3) - func_0201D304(m3, P->hdr->font, 0));
        if (k == 9) {
            put(P->f1EAC, (u32)func_02045770(*(void **)(tab + slot)), x2, ex, m3, P->hdr->font, 0x2960);
        } else {
            put(P->f1EAC, (u32)func_02045770(*(void **)(tab + slot)), x2, ex, m3, P->hdr->font, 0x31A0);
        }
        fl[slot] = 1;
        func_02045808(m3);
    }
}

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
 * 2026-10-05 (wD6 lane07): new reading, not adopted (464 bytes, worse than 450): the original derives 0x1EA4,
 *   0x1EAC and 0x1F74 from a reloaded 0x1F70 pool word (`subs #0xd0/#0xcc/#0xc4`, `adds #4`), and the tail blocks
 *   add 0xC to a spilled 0x1EA0 and store it back. Wrote `k = 0x1F70` with p + (k - 0xD0) etc. and a block local
 *   `c = 0x1EA0; ... c += 0xC;` in each arm: mwcc still CSEs 0x1F70 into r4 and spills base. Next: find what
 *   raises pressure in the original so the 0x1F70 constant is rematerialised (slot*8 r4, tab r6, base r7).
 * 2026-10-05 (wD7 lane10): still DIFF (450). New reading of the slots: the tail constants live in the HIGHEST
 *   slots (0x58, 0x5c), one per tail block, above handle/off/rec. Tried plain P-> constants in the head with a
 *   tail-only `c = 0x1EA0; m = f(*(void **)(p + c), 0x16); ... c += 0xC; ctx = *(u32 *)(p + c);` in each arm
 *   (ctx read before 02045770 as in the original): 446, c is folded and the tails still derive from the 0x1F70 in r4.
 *   The sibling 0220C0D0 address form `*(void **)(p + slot * 8 + 0x1F70)` / `(p + slot * 8)[0x1F74]` with no
 *   tab/fl locals: 462. The original keeps fl + slot in r7 for the tails (`adds r7,r1,r4` after the head store).
 * 2026-10-05 (wD8 lane09): still DIFF (450). Fresh reading: the image head reloads the 0x1F70 pool word for
 *   every use (BEBE, BEF4, BF06, BF16, BF28, BF5A) and never keeps it; tab = p+0x1F70 in r6; ctx = f1EAC goes
 *   into r7 before the head 02045770 call (empty `bne; b` from `if (k == 9) ctx = f1EAC; else ctx = f1EAC;`);
 *   then r7 = (p+0x1F74)+slot*8 held for the tail flag stores. Tried the sibling 0220C0D0/0220C4DC house shape
 *   (no tab/fl locals, `*(void **)(p + 0x1F70 + slot * 8)`, `*(u8 *)(p + slot * 8 + 0x1F74) = 1`, elem pointer,
 *   ctx in each k arm, calls in each tail arm): 453, the head if/else merges away and 0x1F70 stays in r4.
 * 2026-10-05 (wD9 lane15): 450 -> 441 bytes (compiled 500 of 536). New reading: the image reads P->f1EAC BEFORE
 *   the 02045770 call in every call block (head: into r7 after the empty `bne; b`; tails: into [sp,#0x30],
 *   [sp,#0x2c], [sp,#0x28], [sp,#0x24], one slot per arm), and the font after it. mwcc evaluates a plain load
 *   argument after a call argument, so the load is a local assigned before the call: head
 *   `if (k == 9) ctx = P->f1EAC; else ctx = P->f1EAC;` then one call; tails a block local per arm
 *   (`u32 c9 = P->f1EAC;` / `u32 cn = ...`) and a direct func_0201C724 call per arm (the put helper is gone).
 *   The arm copies, the slots and the late font read now match the image shape. Left: 0x1F70 is still CSE'd into
 *   r4 for the whole function (original: slot*8 r4, tab r6, base r7, 0x1F70 reloaded per head use, and a
 *   separate 0x1EA0 base per tail spilled to [sp,#0x58]/[sp,#0x5c]); frame 0x54 vs 0x60. Also tried on this
 *   shape: `c = 0x1EA0; ... c += 0xC; *(u32 *)(p + c)` in each tail (c folded, same 441); fl + slot as a head
 *   pointer local for the tail flag stores (`fl = p + 0x1F74 + slot; *fl = 1;` 450 on the old shape, 445 here).
 * 2026-10-05 (wD9r lane17): still DIFF (441). New reading: the tail `ldr [sp,#0x58]; adds #0xc; str [sp,#0x58]`
 *   is the 0x1EA0 constant vreg derived in place (two definitions, so spilled to a slot, not reloaded); the head
 *   K=0x1F70 is reloaded from the pool per use, so in the image K has one definition and no register (remat).
 *   Ours derives the tail constants in place from K (`subs r4,#0xc4`), which makes K non-rematerialisable and it
 *   takes r4, so base is spilled. The fix is a source form whose tails do not derive from K. Tried: head fields
 *   tab-relative `*(void **)(tab - 0xD0)` (443, address built from tab), `p + 0x1F70 - 0xD0` (folded, 441),
 *   tails with `volatile u32 c = 0x1EA0; c += 0xC` (390, slot r4 = slot*8 then matches, but volatile rereads and
 *   is a stand-in: not adopted).
 * 2026-10-05 (wD9r lane31): still DIFF (441). Tried: off = n * 0x4C before base = p + 4 (mul-first idiom;
 *   no change, 441); the 0x1EA0..0x1EAC fields as a nested struct (`struct Sub { f0, f4, f8, fC }` at 0x1EA0,
 *   head and tails) so the tail ctx is `(p + 0x1EA0) + 0xC`: offsets fold, same 441, the tails still derive
 *   from the 0x1F70 constant in r4.
 * 2026-10-05 (wD9r lane45): still DIFF (441). Tried the matched sibling 0220C0D0 prototype for 0201C724
 *   (u32,u32,u16,u32,u32,u32,u16) with a u16 a3: 454, worse. The image keeps `lsls #0x10; asrs #0x10` on x
 *   at the tail calls, so the s16 third parameter of this draft is right and the sibling's u16 is not
 *   this call site's shape.
 * 2026-10-05 (wD9r lane74): still DIFF (441). New reading: the tails take 0x1EA0 from their own pool word
 *   (pool: 0x1F70, d_02211B68, 0x1EA0, 0x2960, 0x31A0), so in the image the tail constant pass does not see the
 *   head K = 0x1F70; ours derives the tails from K (`subs r4,#0xc4`), which keeps K in r4. Tried the tails as
 *   `switch (rec->b0) { case 0: ... break; case 1: ... break; }`: 428 bytes differ but the block order changes
 *   (`beq` to case 0, `cmp #1; beq` to case 1, return block first) and the tails still derive from K in r4,
 *   so not adopted. The if/else-if chain stays.
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
    u32 ctx;
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
    if (k == 9) {
        ctx = P->f1EAC;
    } else {
        ctx = P->f1EAC;
    }
    ex = extra;
    func_0201C724(ctx, (u32)func_02045770(*(void **)(tab + slot)), a3, ex, vec, P->hdr->font, 0x3DC0);
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
            u32 c9 = P->f1EAC;
            func_0201C724(c9, (u32)func_02045770(*(void **)(tab + slot)), x, ex, m2, P->hdr->font, 0x2960);
        } else {
            u32 cn = P->f1EAC;
            func_0201C724(cn, (u32)func_02045770(*(void **)(tab + slot)), x, ex, m2, P->hdr->font, 0x31A0);
        }
        fl[slot] = 1;
        func_02045808(m2);
    } else if (rec->b0 == 1) {
        m3 = func_02045EC0(P->f1EA0, 0x17);
        w2 = func_02045738(handle);
        x2 = (u16)((w2 << 3) - func_0201D304(m3, P->hdr->font, 0));
        if (k == 9) {
            u32 c9 = P->f1EAC;
            func_0201C724(c9, (u32)func_02045770(*(void **)(tab + slot)), x2, ex, m3, P->hdr->font, 0x2960);
        } else {
            u32 cn = P->f1EAC;
            func_0201C724(cn, (u32)func_02045770(*(void **)(tab + slot)), x2, ex, m3, P->hdr->font, 0x31A0);
        }
        fl[slot] = 1;
        func_02045808(m3);
    }
}

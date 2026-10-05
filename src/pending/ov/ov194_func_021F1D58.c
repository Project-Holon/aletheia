/*
 * function: func_021F1D58
 * address:  0x021F1D58
 * packet:   pkt_ov194_021F1D58
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note 2026-10-05 (wD5 lane18): channel order a-green, then table, then a/b blue, red, b-green with the lerp order blue, red, green: 208 bytes (original 208), 167 differ (was 185). Residue: original makes the phase pointer r0 and ph r1 (`adds r0,r1,#0; ldrh r1,[r0]`), ours keeps the pointer in r1 and ph in r0.
 * note (2026-10-05, wD4 lane17): still DIFF, 185 bytes. Tried: green channel of a computed before the table lookup, lerp statement order blue/red/green (the original lerps in that order), local copy of the phase pointer (propagated away). Original keeps the phase pointer in r0 and the value in r1 (copy `adds r0,r1,#0` first); ours keeps the pointer in r1. Original also holds a (r5) and b (r3) in registers across the lerps.
 *
 * note (2026-10-04): lane17 wave D2: 204 bytes vs 208, first draft. Logic: phase += step with wrap at 0x10000 (signed int compare), t = (s16)((tbl_020A1B38[(phase >> 4) * 2 + 1] + 0x1000) / 2), per-channel RGB555 lerp (a + ((b - a) * t >> 12)), write u16, call func_02061CA4(0xF, row * 32 + idx * 2, out, 2), return *out == b. Residue: original copies the phase pointer to r0 first (adds r0,r1,#0; ldrh r1,[r0]) and reads the stack colour args a (r5) and b (r3) before the table lookup; ours loads a/b after t. Try computing the channels of a before t and keeping phase in a local pointer.
 *
 * note 2026-10-05 (wD6 lane10): tried the house rgb555 lerp idiom (static inline lerp(u16 *p, int n,
 *   u16 a, u16 b), g, r, blue order): 208 bytes and the whole lerp body has the original shape
 *   (r7 = 0x1F, lsls r7 #0xa / #5), 190 bytes differ only from the register/schedule shift. Original
 *   loads a and computes green BEFORE the table lookup (t in r2, b in r3, g in r4); the inline computes t
 *   first (t r4, b r2, g r3). Also tried t computed inside the helper after g (204 bytes), flat body with g
 *   before t (204), argument order (p, a, b, n) (190), phase update as an inline adv(u16 *), phase as
 *   &s->v of a struct param, everything in one helper: the phase pointer stays in r1 (original copies
 *   it to r0 first). The draft below is still the closest by count (167); the inline form is in the note.
 * note 2026-10-05 (wD7 lane05): still DIFF 167 (draft unchanged). Tried: the ov105 021B8734 body as one
 *   static inline (lerp plus the func_02061CA4 call, n passed in): row lands in ip as in the original, but
 *   190 differ; n computed inside the helper after g (204 bytes); statement order g, r, blue before the
 *   table read (no change: the compiler always schedules the *phase reload and table chain first, the
 *   original loads a first); param `step` reused for the sum and for t (t should be r2, 190); phase
 *   update as a ternary or `ph -= 0x10000; *phase = ph;` (worse); phase as `void *` param copied to a
 *   u16 pointer (no copy). Residue: phase pointer r0/value r1 at entry, and a (r5), g (r4), b (r3), t (r2)
 *   with a loaded before the table chain.
 * symbols:
 *   tbl_020A1B38  0x020A1B38  data
 *   func_02061CA4  0x02061CA4  arm
 */
/*
 * 2026-10-05 (wave D8 lane08): still DIFF 167 (draft unchanged). Tried: second parameter as a struct pointer
 *  with phase at offset 0 (`u16 *phase = &ps->v;` local, and direct `ps->v` uses): both 167, the pointer stays
 *  in r1. Flat ov105 021B8734-style body (u8 r, g, blue; int dr, dg, db; lerp `* t >> 12`): t before g gives
 *  208 bytes with the whole lerp body in the image shape and only the colours different (190: t r4, g r3, b r2;
 *  image g r4, t r2, b r3); g before t gives 204 (the table chain is still scheduled before the a load).
 *  Image reading: r7 = 0x1F with `lsls r7,#0xa` / `lsls r7,#5` masks, but g of a uses an immediate 0x3E0 and is
 *  computed before the table chain, after a reload of *phase.
 */
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
extern s16 tbl_020A1B38[];
extern int func_02061CA4(u32 ch, u32 off, u16 *src, u32 size);
int func_021F1D58(u16 *out, u16 *phase, u32 step, u32 row, u8 idx, u16 a, u16 b)
{
    int ph = *phase + step;
    int t;
    u32 r0, g0, b0, r1, g1, b1;
    if (ph >= 0x10000) *phase = ph - 0x10000;
    else *phase = ph;
    g0 = (u8)((a & 0x3E0) >> 5);
    t = (s16)((tbl_020A1B38[(*phase >> 4) * 2 + 1] + 0x1000) / 2);
    b0 = (u8)((a & 0x7C00) >> 10);
    b1 = (u8)((b & 0x7C00) >> 10);
    r0 = (u8)(a & 0x1F);
    r1 = (u8)(b & 0x1F);
    g1 = (u8)((b & 0x3E0) >> 5);
    b0 = (u8)(b0 + (((int)(b1 - b0) * t) >> 12));
    r0 = (u8)(r0 + (((int)(r1 - r0) * t) >> 12));
    g0 = (u8)(g0 + (((int)(g1 - g0) * t) >> 12));
    *out = (u16)(r0 | (g0 << 5) | (b0 << 10));
    func_02061CA4(0xF, row * 32 + idx * 2, out, 2);
    return *out == b;
}

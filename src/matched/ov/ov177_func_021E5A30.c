/*
 * function: func_021E5A30
 * address: 0x021E5A30
 * packet: pkt_ov177_021E5A30
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 2026-10-02 lane07: DIFF, 172 bytes. Channel unpack/blend scheduling differs (orig reads c0 via add r1,sp,#0x18 before table load, builds 0x1f<<10 mask by reusing the 0x1f register, blend order B,R,G). Tried u8 locals, decl orders, shifted-mask forms.
 * note 2026-10-05: orig packs `(g << 5) | r | (b << 10)` (orrs g5,r then b10); tried that order:
 * the compiler then rebuilds 0x1f from a shifted register and the function shrinks to 156 B (orig 172).
 * The original keeps c0 in r6 and c1 in r1 and builds each mask with its own movs/lsls; no source form
 * found that reproduces this. Still DIFF.
 * 2026-10-05 (wave D9 lane10): DIFF, now 172 bytes (same size as the original), 94 bytes differ
 *   (was 157 with a 164-byte body). New form: c1 channels in u8 locals (b1, r1, g1) as separate
 *   statements, blends written back into the c0 locals in order b, r, g, pack "r | (g << 5) | (b << 10)".
 *   This reproduces every u8 truncation, every mask constant (0x3e<<4, 0x1f, 0x1f<<10, no 0x1f held in
 *   a register), the blend order and out in r7. Residue: register colouring only. Ours keeps c0 in r1
 *   and hoists c1's 0x1f<<10 mask into r6 at the top; the original keeps c0 in r6 (loaded before the
 *   table read) and builds that mask in r6 after c0 dies. Also g0/r0 swap r3/r4 and b0 is r1 (orig r2).
 *   Tried: declaration order of the locals (no change, all propagated), c0 extraction before t (worse,
 *   100), u8 casts inline in the blends (CSE of 0x1f into r7 when all six channels are u8 inline),
 *   a static inline u8 Blend helper (120), U-suffixed masks (no change).
 * 2026-10-05 (wave D9r lane06): DIFF, 172 bytes, 77 bytes differ (was 94). New form: copy c0 into an
 *   `int col` local as the first statement, before t. This puts `add r1,sp,#0x18` at +6 as in the image.
 *   Residue: colouring only. The image loads c0 into r6 at +0x12 (before the table ldrsh) and c1 into r1;
 *   ours loads col into r1 after t, c1 into r2, and hoists c1's 0x1f<<10 mask into r6. g0/r0 also swap
 *   r3/r4. Tried without gain: u16 col (94), u32 col (77), short col (176 B), col reused for c1 (77),
 *   a second int col1 for c1 (137), statement order of the six channel locals (all 94, mwcc rebuilds the
 *   trees per use), g0 or g0+r0 extracted before t with and without col (100/106), static inline Blend
 *   (u16 c0, u16 c1, int t / short t / u16 phase) (94/96), short t (96), pack (g<<5)|r|(b<<10) (109).
 * 2026-10-05 (wave D9r lane33): DIFF, code unchanged (77 bytes differ). Listing reading: the image
 *   colours c0 last (r6, the only free register), so c0 is a short, low-degree value in the image and the
 *   post-RA scheduler then lifts its ldrh to +0x12 and builds c1's 0x7c00 mask in r6 only after c0 dies.
 *   Ours colours c0 (or col) first into r1, leaving r6 free, so the scheduler hoists that mask to the top.
 *   Tried: t through a static inline CalcT(phase) helper (77, same code); blends into three new u8 locals
 *   bb/rr/gg instead of writing back (90); int c0 channel locals with (u8) casts at each assignment (81);
 *   mask-first operand order `0x3e0 & c0` with and without col (94/77, no change).
 *
 * 2026-10-05 (wave D9r lane37): EXACT. Closed with the form of the matched twin ov068 BLINK_PALANM_BlendStep
 *   (arm9 twin BLINK_PALANM_Update, blink_palanm.c): f as an s16 local, all six channels as u8 locals extracted
 *   mask-then-shift, the blends as s32 locals with a u8 cast, and the pack (b << 10) | (r | (g << 5)).
 *
 * symbols:
 *   FX_SinCosTable_  0x020A1B38  data  a2
 *   func_02061CA4    0x02061CA4  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;
extern const short FX_SinCosTable_[];
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
void func_021E5A30(u32 slot, u16 *out, const u16 *phase, u32 unused, u8 a, u8 b, u16 c0, u16 c1)
{
    s16 f;
    u8 r0, g0, b0, r1, g1, b1;
    s32 r, g, bl;

    f = (FX_SinCosTable_[((*phase >> 4) << 1) + 1] + 0x1000) / 2;
    r0 = c0 & 0x1f;
    g0 = (c0 & 0x3e0) >> 5;
    b0 = (c0 & 0x7c00) >> 10;
    r1 = c1 & 0x1f;
    g1 = (c1 & 0x3e0) >> 5;
    b1 = (c1 & 0x7c00) >> 10;
    bl = (u8)(b0 + (((b1 - b0) * f) >> 12));
    r = (u8)(r0 + (((r1 - r0) * f) >> 12));
    g = (u8)(g0 + (((g1 - g0) * f) >> 12));
    *out = (u16)((bl << 10) | (r | (g << 5)));
    func_02061CA4((void *)slot, a * 32 + b * 2, (u32)out, 2);
}

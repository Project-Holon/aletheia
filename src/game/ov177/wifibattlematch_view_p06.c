/*
 * file:     wifibattlematch_view_p06.c
 * unit:     yes
 * function: func_021E5868, func_021E58A4, func_021E5978, func_021E5980, func_021E5A30, func_021E5ADC
 * address:  0x021E5868
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FX_SinCosTable_  0x020A1B38  data  a2
 *   func_02061CA4    0x02061CA4  arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045738 0x02045738 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 */
struct MsgBank;
struct WordSet;
struct U16Vec;
struct Descriptor;
struct PrintSys;
struct Rec;
struct StrObj;
typedef unsigned int   u32;

typedef struct { int a, b, c, d, e, f; } S5868;

typedef unsigned short u16;

typedef struct { char pad[0x18]; unsigned short out[16], original[16], target[16], phase; } State;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed int     s32;

extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern u32 func_020307B0(void *p);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_020498F4(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f, u16 g);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_02049238(int);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u16 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u16 heapId);
extern u8 func_02045738(struct Descriptor *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
void func_021E5868(S5868 *p);
void func_021E58A4(int unused, int mode, unsigned color);
int func_021E5978(int *p, int i);
void func_021E5980(State *p);
void func_021E5A30(u32 slot, u16 *out, const u16 *phase, u32 unused, u8 a, u8 b, u16 c0, u16 c1);
void func_021E5ADC(u32 *p, struct PrintSys *win, u32 str, u32 c2, u32 c1, u16 heap);
extern const short FX_SinCosTable_[];

void func_021E5868(S5868 *p)
{
    func_0204ADA4(p->a);
    func_0204A8D4(p->c);
    func_0204AFD8(p->e);
    func_0204ADA4(p->b);
    func_0204A8D4(p->d);
    func_0204AFD8(p->f);
    func_02040DA8(0, 1, 0);
    func_020307B0(p);
}

void func_021E58A4(int unused, int mode, unsigned color)
{
    int h;
    unsigned c = (color & 0x7fff) | 0x8000;
    h = (int)func_020490F4((int)0x85, (unsigned short)c);
    func_020498F4((void *)h, 5, 3, 0, 0, 0, c);
    func_020498F4((void *)h, 6, 7, 0, 0, 0, c);
    switch (mode) {
    case 2:
        func_020498F4((void *)h, 8, 6, 0, 0, 0, c);
        break;
    case 3:
        func_020498F4((void *)h, 10, 2, 0, 0, 0, c);
        break;
    case 0:
    case 1:
        func_020498F4((void *)h, 10, 6, 0, 0, 0, c);
        break;
    }
    func_02040618(2, 0, -256);
    func_02040618(1, 0, -256);
    func_02040618(6, 0, -256);
    func_02040618(5, 0, -256);
    func_02049238(h);
}

int func_021E5978(int *p, int i)
{
    return p[i];
}

/*
 * lever: observed three color arrays; cached phase on wrap, compound increment reload on no-wrap.
 */
void func_021E5980(State *p)
{
    int i;
    unsigned short phase = p->phase;
    if (phase + 0x200 >= 0x10000)
        p->phase = phase - 0xfe00;
    else
        p->phase += 0x200;
    for (i = 0; i < 16; i++) {
        func_021E5A30(15, &p->out[i], &p->phase, 0, 0, i, p->original[i], p->target[i]);
        func_021E5A30(31, &p->out[i], &p->phase, 0, 0, i, p->original[i], p->target[i]);
        func_021E5A30(14, &p->out[i], &p->phase, 0, 2, i, p->original[i], p->target[i]);
    }
}

/*
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
 * 2026-10-05 (wave D9r lane37): EXACT. Closed with the form of the matched twin ov068 func_021B9D68
 *   (arm9 twin func_0202EA40, blink_palanm.c): f as an s16 local, all six channels as u8 locals extracted
 *   mask-then-shift, the blends as s32 locals with a u8 cast, and the pack (b << 10) | (r | (g << 5)).
 */
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


/*
 * note 2026-10-05 (final push G6L3): EXACT*. The three running x values are separate locals (x, x1 = x - w, x2 = x1 - w, third draw x2 - w), not one x updated in place; the separate values give each its own live range and the original colours (str r4, p r5, heap-base temp and buf r6, x r7). Earlier notes (all pragmas, declaration orders, inline helpers, u8/u16 widths) did not move the colours.
 */
void func_021E5ADC(u32 *p, struct PrintSys *win, u32 str, u32 c2, u32 c1, u16 heap)
{
    struct MsgBank *msg;
    struct WordSet *ws;
    struct U16Vec *buf;
    void *e;
    int x, x1, x2;
    u16 w;

    msg = func_02045B38(0, 2, 0xa3, heap);
    ws = func_0201EC64(heap);
    buf = func_020457B0(0x20, heap);
    x = (u16)(func_02045738((void *)p[0]) << 3);

    e = func_02045EC0(msg, 2);
    func_0201EFA4(ws, 0, c1, 8, 0, 1);
    func_0201F250(ws, buf, e);
    w = func_0201D304((struct StrObj *)buf, str, 0);
    x1 = x - w;
    func_0201C6FC(win, (u32)func_02045770((struct Descriptor *)p[0]), (s16)x1, 0, buf, str);
    ((u8 *)p)[4] = 1;
    func_02045808((struct U16Vec *)e);

    e = func_02045EC0(msg, 0);
    w = func_0201D304(e, str, 0);
    x2 = x1 - w;
    func_0201C6FC(win, (u32)func_02045770((struct Descriptor *)p[0]), (s16)x2, 0, e, str);
    ((u8 *)p)[4] = 1;
    func_02045808((struct U16Vec *)e);

    e = func_02045EC0(msg, 1);
    func_0201EFA4(ws, 0, c2, 8, 0, 1);
    func_0201F250(ws, buf, e);
    w = func_0201D304((struct StrObj *)buf, str, 0);
    func_0201C6FC(win, (u32)func_02045770((struct Descriptor *)p[0]), (s16)(x2 - w), 0, buf, str);
    ((u8 *)p)[4] = 1;
    func_02045808((struct U16Vec *)e);
    func_02045808(buf);
    func_0201ED04(ws);
    func_02045C04((struct Rec *)msg);
}
